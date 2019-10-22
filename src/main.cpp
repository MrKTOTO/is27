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

    cout<<"Введите название нужной вам функции"<<endl;
    cin>>func_name;
    cout<<func_name<<endl;

    int N;
    cout <<"Выберите функцию:" <<endl;
    cout <<"1.sharov\n";
    cin >>N;
    switch (N)
    {
        case 1:
        {
            sharov(gg, gg2);
            break;
        }

        default:
        {
            cout<< "По-умолчанию выбрана функция 1";

            break;
        }
    }


}

