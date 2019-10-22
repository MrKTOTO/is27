/*#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
struct pixel
{
    unsigned char b;
    unsigned char g;
    unsigned char r;
    bool operator==(pixel& pix)
    {
        if (b == pix.b && g == pix.g && r == pix.r)
            return true;
        else
            return false;
    }
};

#pragma pack(push, 1)
struct head
{
    char type[2];
    unsigned int size;
    unsigned int reserv;
    unsigned int offset;
    unsigned int head_size;
    unsigned int width;
    unsigned int height;
    unsigned int end[7];
};
#pragma pack(pop)

struct pixel** p_in;
struct head h_bmp
char* infile;
int get_pad(int);
void read_file();
void help();
void countColors();
int get_pad(int width)
{
    int i = 0;
    while ((width * 3 + i) % 4 != 0)
        i++;
    return i;
}

void help()
{
    cout << "\nusage: \n";
    cout << "  chbmp  in_file \n";
}

int main(int argc, char** argv
{
    infile = argv[1];
    if (argc < 2)
    {
        help();
        return 1;
    }
    read_file();
    countColors();
    return 0;
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
            fread(buf, pad, 1, fd);
    }
    fclose(fd);
}
void countColors()
{
    vector<pixel> colors;
    for (int Y = 0; Y < h_bmp.height; Y++)
    {
        for (int X = 0; X < h_bmp.width; X++)
        {
            bool find = false;
            for (int I = 0; I < colors.size(); I++)
            {
                if (colors[I] == p_in[Y][X])
                    find = true;
            }
            if (find == false)
                colors.push_back(p_in[Y][X]);
        }
    }
    cout << "Kol-vo raznih cvetov: " << colors.size();
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
int peshehonov(int argc, char** argv)
{
    privet();
    poka();
    return 0;
}