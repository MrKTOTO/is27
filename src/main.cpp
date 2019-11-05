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
           "2.peshehonov\n"
           "3.manin\n"
           "4.galanin\n"
           "5.averyanova\n"
           "6.MS\n"
           "7.perevezencev\n"
           "8.Puhov_Create\n"
           "9.svyatov\n"
           "10.zhdanov\n";
    cin >>N;
    switch (N) {
        case 1: {
            sharov(gg, gg2);
            break;
        }
        case 2: {
            peshehonov();
            break;
        }
        case 3: {
            manin();
            break;
        }

        /*case 4: {
            galanin();
            break;
        }
        case 5:
        {
            averyanova();
            break;
        }
        case 6:
        {
            MS();
            break;
        }
        case 4:
        {
            perevezencev();
            break;
        }
        case 5:
        {
            Puhov_Create();
            break;
        }
        case 9:
        {
            svyatov();
            break;
        }
        case 10:
        {
            zhdanov();
            break;
        }*/

        default:
        {
            cout<< "По-умолчанию выбрана функция 1";

            break;
        }
    }


}

