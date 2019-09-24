#include <iostream>

using namespace std;

int main()
{
    int n,num,dig,rev=0;
setlocale(LC_ALL,"ru");
cout<<"Введите число для проверки:";
cin>>num;
n=num;

while(num!=0)
{
dig=num%10;
rev=(rev*10)+dig;
num=num/10;
}

if(n==rev)
{
cout<<"Число палиндром"<<endl;
}
else
{
cout<<"Число не палиндром"<<endl;
}

    return 0;
}
