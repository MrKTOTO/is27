//
// Created by zhilcov27 on 10/1/19.
//

#include <iostream>
#include <cmath>

#include "header.h"

using namespace std;

int main(){
    setlocale(LC_ALL, "russian");
    string func_name;
    auto *names = new char[8];
    gg = 1;

    int N;
    cout <<"Выберите функцию:" <<endl;
    cout <<"1.sharov\n"
           "2.peshehonov\n";
    cin >>N;
    switch (N)
    {
        case 1:
        {
            sharov(gg, gg2);
            break;
        }
        case 2:
        {
            peshehonov();
            break;
        }

        default:
        {
            cout<< "По-умолчанию выбрана функция 1";

            break;
        }
    }


}

