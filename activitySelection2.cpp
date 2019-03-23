/* Greedy algorithm to implement Activity selection */
#include <bits/stdc++.h>
#include<conio.h>
using namespace std;

void ActivitySelector( int s[] , int f[] , int n )
{
	 /* First activity is always selected */
	 int k = 0;
	 cout<<"Activity:"<<k+1<<"is selected\n"<<"Start time="<<s[k]<<"Finish time="<<f[k]<<endl;
	 for( int i = 1; i<n; i++)
	 {
		  if( s[i] >= f[k] )
		  {
			  cout<<"Activity:"<<i+1<<"is selected\n"<<"Start time="<<s[i]<<"Finish time="<<f[i]<<endl;
			  k = i;
		  }
	 }
}

/*Driver program*/
int main()
{
	cout<<"Enter number of activities\n";
	int n;
	cin>>n;

	const int m = n;

	/* Array to store start time and finish time of activities */
	int s[m];
	int f[n];
	
	/*Initialize the arrays*/
	cout<<"Enter start and finish time of the activities\n";
	for(int i=0; i<n; i++)
	{
			cin>>s[i]>>f[i];
	}
	
	
	/*Activities are sorted according to their finish time*/
	for(int i = 0; i<n; i++)
	{
			for(int j=0; j<n-i-1; j++)
			{
					if( f[j] > f[j+1] )
					{
						int tempFinish = f[j];
						f[j] = f[j+1];
						f[j+1] = tempFinish;
						
						int tempStart = s[j];
						s[j] = s[j+1];
						s[j+1] = tempStart;
					}
			}
	}
	
	cout<<"The activities are:\n";
	for( int i=0;i<n;i++ )
	{
		 cout<<s[i]<<"\t"<<f[i]<<endl;
	}
	
	ActivitySelector(s,f,n);
	getch();
	return 0;
}
