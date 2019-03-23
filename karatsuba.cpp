/*Karatsuba multiplication*/
#include<iostream>
#include<math.h>
#include <conio.h>
using namespace std;
long multiply(int x,int y)
{
	 //Base case : direcly multiply single digit numbers
	if(x/10 == 0 && y/10 == 0 )
			 return x*y;

	long num=(x>y)?x:y; //as n considered according to larger number
	int n=0;
	while(num!=0)
	{
		num=num/10;
		n++;
	}
	//int fact = (n/2) + (n%2);
	int fact = n/2;
	long temp = pow(10,fact);

	long a = x/temp;
	long b = x%temp;
	long c = y/temp;
	long d = y%temp;
	
	long ac = multiply(a,c);
	long bd = multiply(b,d);
	long abcd = multiply(a+b, c+d);
	return pow(10,2*fact)*ac+temp*(abcd-ac-bd)+bd;
}

int main()
{
	cout<<"Enter two numbers\n";
	int x,y;
	cin>>x>>y;
	cout<<multiply(x,y)+2<<endl;
	cout<<"x*y="<<x*y<<endl;
	getch();
	return 0;
}
