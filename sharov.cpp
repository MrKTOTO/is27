
void setcolor();
void fil_rect(int x, int y, int _x, int _y);


int sharov(int argc, char** argv)
{
    setlocale(LC_ALL, "russian");
    if (!strcmp(argv[1], "fill_rect"))
    {
        if (argc < 4)
        {
            help();
            return 1;
        }
        infile = argv[2];
        outfile = argv[3];
        read_file();
        cout << "ширина " << h_bmp.width << "px" << endl;
        cout << "введите координаты точек прямоóгольника: " << endl;
        int x, y, _x, _y;
        cout << "введите координаты нижней точки: " << endl;
        do {
            cout << "x:";
            check(x);
        }
        while (x > h_bmp.width || x < 0);
        do {
            cout << "y:";
            check(y);
        } while (y > h_bmp.width || y < 0);
        cout << "введите координаты верхней точки" << endl;
        do {
            cout << "x:";
            check(_x);
        } while (_x > h_bmp.width || _x < 0);
        do {
            cout << "y:";
            check(_y);
        } while (_y > h_bmp.width || _y < 0);
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
}
