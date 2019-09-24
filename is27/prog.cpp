#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;
void search(int data[], int tofind);

int main()
{
	int data[600];
	int tofind, finded;
	cout<<"Введите число, для проверки его наличия в массиве:"<<endl;
	cin>>tofind;
	search(data, tofind);
	
	cout<<" "<<endl;
	
}

int search(int data[], int tofind){

}
