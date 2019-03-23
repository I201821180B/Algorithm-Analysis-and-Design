/*euclid algorithm to calculate gcd of two nos*/
#include <iostream>
#include <conio.h>
using namespace std;

int gcd(int a1,int a2)
{
	int q2,a3;
	if(a2 == 0)
	{
		  return a1;
	}
	if(a2>0)
	{
			q2 = a1/a2; //int type to store quotient
			a3 = a1 % a2;
			return gcd(a2,a3);
	}
}
int main()
{
	cout<<"Enter 2 nos"<<endl;
	int a1,a2;
	cin>>a1>>a2;
	if(a1<a2)
	{
			 int temp=a2;
			 a2=a1;
			 a1=temp; //a1 must be the larger number
	}
	int g = gcd(a1,a2);
	cout<<"gcd="<<g<<endl;
	getch();
	return 0;
}
