/*#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

struct pixel
{
    unsigned char b;
    unsigned char g;
    unsigned char r;
};

#pragma pack(push, 1)
struct head
{
    char type[2];
    unsigned int size;
    unsigned int reserv;
    unsigned int offset;
    unsigned inthead_size;
    unsigned int width;
    unsigned int height;
    unsigned int end[7];
};
#pragma pack(pop)

struct pixel **p_in;
struct pixel **p_out;
struct head h_bmp;
char *infile;
char *outfile;
void check(int &a);
void read_file();
void write_file();



int get_pad(int width)
{
    int i=0;
    while((width + i) % 4 !=0)
        i++;
    return i;
}

int padding(int width)
{
    int i=0;
    while(width % 4 ==0)
        i++;
    return i;
}

void help()
{
    cout <<"usage: \n";
    cout <<"chbmp resizev N in_file out_file \n";
    cout <<"chbmp resizeh N in_file out_file \n";
    cout <<"chbmp rotater in_file out_file \n";
    cout <<"chbmp rotatel in_file out_file \n";
}

int col_b, col_g, col_r;
void setcolor();
void fill_rect(int x, int y, int _x, int _y);

int sharov(int argc, char** argv)
{
    setlocale(LC_ALL, "russian");
    if (!strcmp(argv[1], "fill_rect"))
    {
        if (argc<4)
        {
            help();
            return 1;
        }
        infile = argv[2];
        outfile = argv[3];
        read_file();
        cout << "ширина " <<h_bmp.width <<"px" <<endl;
        cout << "введите координаты точек прямоóгольника: " <<endl;
        int x, y, _x, _y;
        cout << "введите координаты нижней точки: " <<endl;
        do
        {
            cout << "x:";
            check(x);
        } while (x>h_bmp.width || x<0);
        do
        {
            cout << "y:";
            check(y);
        } while (y>h_bmp.width || y<0);
        cout << "введите координаты верхней точки" <<endl;
        do
        {
            cout << "x:";
            check(_x);
        } while (_x>h_bmp.width || _x<0);
        do
        {
            cout << "y:";
            check(_y);
        } while (_y>h_bmp.width || _y<0);
        setcolor();
        fill_rect(x, y, _x, _y);
    }
    return 0;
}
void fill_rect(int x, int y, int _x, int _y)
{
    read_file();
    p_out = new struct pixel*[h_bmp.width];
    for (int i = 0; i < h_bmp.width; i++)
        p_out[i] = new struct pixel[h_bmp.height];
    for (int i = 0; i < h_bmp.height; i++)
        for (int j = 0; j < h_bmp.width; j++)
            p_out[i][j] = p_in[i][j];

    for (int i = y; i < _y; i++)
    {
        for (int j = x; j < _x; j++)
        {
            p_out[i][j].r = col_r;
            p_out[i][j].g = col_g;
            p_out[i][j].b = col_b;

        }
    }
    write_file();
}
void setcolor()
{
    int N;
    cout <<"Выберите цвет:" <<endl;
    cout <<"1.Белый\n2.Черный\n3.Синий\n4.Красный\n5.Зеленый\n6.Желтый\n7.Фиолетовый\n";
    cin >>N;
    switch (N)
    {
        case 1:
        {
            col_r = 255;
            col_g = 255;
            col_b = 255;
            break;
        }
        case 2:
        {
            col_r = 0;
            col_g = 0;
            col_b = 0;
            break;
        }
        case 3:
        {
            col_r = 0;
            col_g = 0;
            col_b = 255;
            break;
        }
        case 4:
        {
            col_r = 255;
            col_g = 0;
            col_b = 0;
            break;
        }
        case 5:
        {
            col_r = 0;
            col_g = 255;
            col_b = 0;
            break;
        }
        case 6:
        {
            col_r = 255;
            col_g = 255;
            col_b = 0;
            break;
        }
        case 7:
        {
            col_r = 139;
            col_g = 0;
            col_b = 255;
            break;
        }

        default:
        {
            cout<< "По-умолчанию выбран черный цвет";
            col_r = 0;
            col_g = 0;
            col_b = 0;
            break;
        }
    }
}
void check(int &a)
{
    while (!(cin >> a))
    {
        cerr << "Error\n";
        cin.clear();
        cin.ignore(256, '\n');
    }
    return;
}

void read_file()
{
    long int count = 0;
    int i, j, n;
    struct pixel buf[4];
    FILE* fd = fopen(infile, "rb");
    if (!fd)
    {
        perror("open file for read");
        exit(1);
    }
    fread(&h_bmp, sizeof(struct head), 1, fd);
    int pad = get_pad(h_bmp.width);
    p_in = new struct pixel* [h_bmp.height];
    for (i = 0; i < h_bmp.height; i++)
    {
        p_in[i] = new struct pixel[h_bmp.width];
        for (j = 0; j < h_bmp.width; j++)
        {
            n = fread(&p_in[i][j], 3, 1, fd);
        }
        if (pad != 0)
            fread(buf, pad, 3, fd);
    }
    fclose(fd);
}

void write_file()
{
    int i, j;
    struct pixel buf[4];
    FILE* fd = fopen(outfile, "wb");
    if (!fd)
    {
        perror("open file for write");
        exit(1);
    }
    fwrite(&h_bmp, sizeof(struct head), 1, fd);
    int pad = get_pad(h_bmp.width);
    for (i = 0; i < h_bmp.height; i++)
    {
        for (j = 0; j < h_bmp.width; j++)
            fwrite(&p_out[i][j], 3, 1, fd);
        if (pad != 0)
            fwrite(buf, pad, 3, fd);
    }
    cout << "\nbyte write= " << ftell(fd) << endl;
    fclose(fd);
}*/

#include <iostream>

using namespace std;

void privet()
{
    printf("Привет");
}
void poka()
{
    printf("Пока");
}
int sharov(int argc, char** argv)
{
    privet();
    poka();
    return 0;
}
