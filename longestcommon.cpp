/*longest common subsequence*/
#include <iostream>
#include <cstring>
#include <string.h>
#include <conio.h>
using namespace std;

void print_lcs(int b[][100],string x,int i,int j)
{
	if(i == 0 || j == 0)
	{
		return;
	}
	if(b[i][j] == 2)
	{
		print_lcs(b,x,i-1,j-1);
		cout<<x[i-1];
	}
	else if(b[i][j] == 3)
		print_lcs(b,x,i-1,j);
	else if(b[i][j] == 1)
	    print_lcs(b,x,i,j-1);
}

void lcs_length(string x,string y)
{
	int m = x.length();
	int n = y.length();
	int b[m+1][100],c[m+1][n+1]; //actually no. of columns in b=n;
	/*for b: 1-left,2-diagonal,3-up*/

	for(int i=0;i<=m;i++)
		c[i][0] = 0;
	for(int j=0;j<=n;j++)
	    c[0][j] = 0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(x[i-1] == y[j-1])
			{
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 2; //diagonal
			}
			else if(c[i-1][j] >= c[i][j-1])
			{
				c[i][j] = c[i-1][j];
				b[i][j] = 3;
			}
			else
			{
				c[i][j] = c[i][j-1];
				b[i][j] = 1;
			}
		}
	}
	cout<<"Length of longest subsequence="<<c[m][n]<<endl;
	cout<<"Matrix:\n";
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cout<<c[i][j]<<"\t";
		}
		cout<<endl;
	}
	print_lcs(b,x,m,n);
}

int main()
{
	cout<<"Enter two strings\n";
	string str1,str2;
	cin>>str1>>str2;
	lcs_length(str1,str2);
	getch();
	return 0;
}
