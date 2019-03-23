/*Assumption: key is in increasing order*/
#include <iostream>
#include <conio.h>
using namespace std;
#define INF 100000

int sum(int freq[],int i,int j)
{
	int total=0;
	for(int k=i;k<=j;k++)
	    total += freq[k];
	return total;
}

int optimalBST(int keys[],int freq[],int n)
{
	int cost[n][n];
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

	//L: tree level
	// This helps in determining row,col no.
	int L;
	for(L=2;L<=n;L++)
	{
		for(int i=0;i<=n-L+1;i++) //row no.
		{
			int j = i+L-1;
			cost[i][j] = INF;
			
			int sumOfFreq = sum(freq,i,j);
			
			//each node is considered root such that minimum can be found out
			int sum;
			for(int k=i;k<=j;k++)
			{
				sum=((k>i)? cost[i][k-1]:0) +((k<j)? cost[k+1][j]:0) + sumOfFreq;
				if(sum < cost[i][j])
				    cost[i][j] = sum;
			}
		}
	}
	cout<<"Height="<<L-1<<endl;
	return cost[0][n-1];
}

int main()
{
	int keys[] = {1,2,3,4,5,6};
	int freq[] = {10,3,9,2,0,10};
	int n=sizeof(freq)/sizeof(freq[0]);
	cout<<"Optimal value="<<optimalBST(keys,freq,n)<<endl;
	getch();
	return 0;
}
