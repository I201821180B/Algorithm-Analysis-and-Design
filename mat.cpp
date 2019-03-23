#include<iostream>
#include<limits.h>
#include <conio.h>
using namespace std;
int s[20][20];

void print_sol(int i,int j)
{
	if(i==j)
	    cout<<"A"<<i;
	else
	{
        cout<<"(";
		print_sol(i,s[i][j]);
		print_sol(s[i][j]+1,j);
		cout<<")";
	}
	    
}

int matrixChainOrder(int p[], int n)
{

    //For simplicity,0th row and 0th column of m[][] are not used
    int m[n][n];

    int i, j, k, L, q;

    //m[i,j] = Minimum number of scalar multiplications
    for (i = 1; i < n; i++) //cost=0 when matrix mult. involves only one matrix
        m[i][i] = 0;

    for (L=2; L<n; L++) // L is chain length
    {
        for (i=1; i<=n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;
            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]; // q = cost/scalar multiplications
                if (q < m[i][j])
                {
					m[i][j] = q;
					s[i][j] = k;
                }
            }
        }
    }
    cout<<"Minimum number of multiplications is "<<m[1][n-1]<<endl;
	print_sol(1,4);
}

int main()
{
	//dimensions:
    int arr[] = {10,30,5,60,8};
    int size = sizeof(arr)/sizeof(arr[0]);

    matrixChainOrder(arr, size);

    getch();
    return 0;
}
