/*Strassen's algorithm for matrix multipication*/
#define MAX 10

#include <iostream>
#include<conio.h>
using namespace std;

void strassen(int a[][MAX],int b[][MAX],int n)
{
	 int c[n][MAX];
	 int s[11];
	 s[0]=0; //ignore it
	 int k=1;
	 s[1] = b[0][1] - b[1][1];
	 s[2] = a[0][0] + a[0][1];
	 s[3] = a[1][0] + a[1][1];
	 s[4] = b[1][0] - b[0][0];
	 s[5] = a[0][0] + a[1][1];
	 s[6] = b[0][0] + b[1][1];
	 s[7] = a[0][1] - a[1][1];
	 s[8] = b[1][0] + b[1][1];
	 s[9] = a[0][0] - a[1][0];
	 s[10] = b[0][0] + b[0][1];
	 
	 int p[8];
	 p[0]=0;//ignore
	 p[1] = a[0][0] * s[1];
	 p[2] = s[2]*b[1][1];
	 p[3] = s[3]*b[0][0];
	 p[4] = a[1][1]*s[4];
	 p[5] = s[5]*s[6];
	 p[6] = s[7]*s[8];
	 p[7] = s[9]*s[10];
	 
	 c[0][0] = p[5]+p[4]-p[2]+p[6];
	 c[0][1] = p[1]+p[2];
	 c[1][0] = p[3] + p[4];
	 c[1][1] = p[5]+p[1]-p[3]-p[7];
	 
	 //print
	 cout<<"Resultant Matrix:\n";
	 for(int i=0;i<n;i++)
	 {
			 for(int j=0;j<n;j++)
			 {
					 cout<<c[i][j]<<"\t";
			 }
			 cout<<"\n";
	 }
}

int main()
{
	//cout<<"Enter value of n\n";
	int n = 2;
	//cin>>n;
	const int len = n;
	int a[len][MAX],b[len][MAX];
	//int c[len][MAX];

	cout<<"Enter elements of matrix A\n";
	for(int i = 0;i<len;i++)
	{
			for(int j=0;j<len;j++)
			{
					cin>>a[i][j];
			}
	}
	cout<<"Enter elements of matrix B\n";
	for(int i = 0;i<len;i++)
	{
			for(int j=0;j<len;j++)
			{
					cin>>b[i][j];
			}
	}

	strassen(a,b,len);
	getch();
	return 0;
}
