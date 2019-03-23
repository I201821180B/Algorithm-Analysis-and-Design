/*Dynamic programming to implement 0-1 knapsack problem*/
#include <iostream>
#include <conio.h>
using namespace std;

int knapsack(int W,int wt[],int price[],int n)
{
	/*No of rows= no. of items
	No of columns=different capacities
	"+1" is because index starts with 0*/
	int k[n+1][W+1];
	for(int i=0;i<=n;i++)
	{
			for(int j=0;j<=W;j++)
			{
					/*1st row,1st column filled with zeroes
					as: no zeroeth item exists.
					Case with capacity=0 is useless*/
					if(i==0 || j==0)
					{
							k[i][j] = 0;
					}
					//i-1 is coz weight of ith item stored in i-1 location
					//as index of wt[] starts with zero
					else if(wt[i-1] <= j)
					{
						 k[i][j] = max(price[i-1]+k[i-1][j-wt[i-1]],k[i-1][j]);
						 //max of two cases:
						 //(1). "i"th item included
						 //(2). item not included
					}
					//i.e. capacity crossed weight of "i"th item
					else
					{
						k[i][j] = k[i-1][j]; //same value continued
					}
			}
	}
	cout<<"Array:\n";
	for(int i=0;i<=n;i++)
	{
			for(int j=0;j<=W;j++)
			{
					cout<<k[i][j]<<"\t";
			}
			cout<<endl;
	}

	return k[n][W];
	
}

int main()
{
	int W = 15;
	int price[] = {3,4,5,8,10};
	int wt[] = { 2,3,4,5,6};
	int n = sizeof(price)/sizeof(price[0]);
	int ans = knapsack(W,wt,price,n);
	cout<<"Maximum possible profit="<<ans<<endl;
	getch();
	return 0;
}
