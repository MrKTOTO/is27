#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int m,b;
        std::cin>>m;
        b=m%10;
        if (b==1)
        {
           std::cout<<m<" god\n";
        }
        else
        {
            if (b==2 or b==3 or b==4)
            {
               std::cout<<m<<" goda\n";
            }
            else
            {
                std::cout<<m<<" let\n";
            }
         }
     return 0;
}
