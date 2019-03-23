/* Greedy Algorithm to implement job scheduling */
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

/* Sort tasks in decreasing order according to profit */
void sort(int t[] , int p[] , int d[] , int n)
{
    for(int i = 0; i<n; i++)
	{
			for(int j=0; j<n-i-1; j++)
			{
					if( p[j] < p[j+1] )
					{
						int tempProfit = p[j];
						p[j] = p[j+1];
						p[j+1] = tempProfit;

						int tempTask = t[j];
						t[j] = t[j+1];
						t[j+1] = tempTask;
						
						int tempDeadline = d[j];
						d[j] = d[j+1];
						d[j+1] = tempDeadline;
					}
			}
	}
	
	cout<<"Sorted list\n";
	for(int i=0;i<n;i++)
	{
			cout<<t[i]<<"\t"<<p[i]<<"\t"<<d[i]<<endl;
	}
}

int maxDeadline(int d[],int n)
{
	 int max = 0;
	 for(int i=0;i<n;i++)
	 {
			 if(d[i]>max)
			 {
				  max = d[i];
			 }
	 }
	 return max;
}

void jobScheduler(int t[] , int p[] , int d[] , int n)
{
	 /*find maximum deadline*/
	 int maxd = maxDeadline(d,n);
	 int totProfit = 0;
	 const int m = maxd;
	 int soln[m];
	 
	 /*by default,initialize soln[] to zero to check "if empty" later*/
	 for(int i=0; i<n; i++)
	         soln[i] = 0;
	 
	 for(int i=0 ; i<n ; i++)
	 {
			 if( soln [d[i] -1 ] == 0)
			 {
				 soln [ d[i] - 1] = t[i];   // -1 is coz index starts from zero
				 totProfit += p[i];
			 }
			 else if( soln[ d[i]-2 ] == 0 )
			 {
				  soln [ d[i]-2 ] = t[i];
				  totProfit += p[i];
			 }
			 else if( soln[ d[i]-3 ] == 0)
			 {
				  soln[ d[i]-3 ] = t[i];
				  totProfit += p[i];
			 }
	 }
	 
	 //print
	 cout<<"Tasks scheduled as follows:\n";
	 for(int i=0 ; i<m ; i++)
	 {
			 cout<<soln[i]<<"\t";
	 }
	 cout<<endl;
	 cout<<"Total profit="<<totProfit<<endl;
}

int main()
{
	cout<<"Enter number of tasks\n";
	int n;
	cin>>n;
	
	const int m = n;
	
	int t[m]; //tasks
	int p[m]; //profits
	int d[m]; //deadlines
	
	/*Initialize profit and deadline array*/
	cout<<"Enter profit and deadlines of the tasks\n";
	for(int i = 0; i<n; i++)
	{
			cin>>p[i]>>d[i];
	}
	
	/*Initialize task array*/
	for(int i = 0; i<n ; i++)
	{
			t[i] = i+1;
	}
	
	sort(t,p,d,n);
	jobScheduler(t,p,d,n);

	getch();
	return 0;
}
