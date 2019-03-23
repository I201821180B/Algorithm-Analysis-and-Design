/*radix sort*/
#include <bits/stdc++.h>
#include <conio.h>
//#include <cmath>
#include<queue>
using namespace std;

void radix(int a[],int n)
{
     //queue<int> q[10];
	 //Maximum value in array to find number of digits:
	 int max=0,pos;
	 for(int i=0;i<n;i++)
	 {
			 if(a[i]>max)
			 {
						 max=a[i];
						 pos=i;
			 }
	 }
	 cout<<"Max="<<max<<endl;
	 int dig=0;
	 while(max!=0)
	 {
          dig++;
          max/=10;
	 }
	 cout<<"Digits="<<dig<<endl;
	 //dig stores maximum no. of digits.
     int power=10;
	 for(int k=1;k<dig;k++)
	 {
             queue<int> q[10];
			 cout<<"Loop\n";
	  		 for(int i=0;i<n;i++)
	  		 {
					 cout<<"Loop entered\n";
			  		 int rem = a[i]%power;
			  		 cout<<"\npower="<<power;
			  		 cout<<a[i]<<endl;
			 		  q[rem].push(a[i]);
			 		  cout<<"Working\n";
	 		 }
	 		 for(int i=0;i<10;i++)
	 		 {
					 if(!q[i].empty())
					 cout<<"Queue "<<i<<" contains "<<q[i].front()<<endl;
	 		 }
	 		 int k=0;
			 for(int i=0;i<10;i++)
			 {
					  while (!q[i].empty())
  					  {
				   		   a[k]= q[i].front();
				   		   k++;
						   q[i].pop();
 					 }
			 }
			 for(int i=0;i<n;i++)
			         cout<<a[i]<<"\t";
			  cout<<endl;
			  for(int i=0;i<10;i++)
			  {
					 cout<<q[i].front()<<endl;
			  }
			  power*=10;
     }

}

void input()
{
	srand(time(NULL));
	cout<<"Enter number of nos.\n";
	int n;
	cin>>n;
	const int m=n;
	int a[m];
	cout<<"The nos are:\n";
	for(int i=0;i<n;i++)
	{
			a[i]=rand()%1000; //Nos ranging from 0 to 10
			//getch();
			cout<<a[i]<<"\t";
	}
	cout<<endl<<endl;
	radix(a,n);
}
int main()
{
	input();
	return 0;
}
