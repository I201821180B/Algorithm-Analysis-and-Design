#include <iostream>
#include <conio.h>
using namespace std;

#define MIN_VAL -1

//func to calc max of 2 digits
int max(int a,int b)
{
	return (a>b)?a:b;
}

//Recursive func. here n=size of rod
int cut_rod(int price[],int n)
{
	if(n <= 0)
	{
			return 0;
	}
	int q = MIN_VAL;
	for(int i=0;i<n;i++)
	{
			q = max(q, price[i]+cut_rod(price,n-i-1));
	}
	return q;
}

int main()
{
	int price[] = {1,5,8,10,13,17,18,22,25,30};
	int len = sizeof(price)/sizeof(price[0]);
	int ans = cut_rod(price,len);
	cout<<"Maximum obtainable price="<<ans<<endl;
	getch();
	return 0;
}
