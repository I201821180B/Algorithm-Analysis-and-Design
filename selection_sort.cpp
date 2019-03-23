/*Selection sort*/
#define MIN 100

#include <bits/stdc++.h>
#include<conio.h>
using namespace std;
void selection(int a[],int n);
void input()
{
     //input:
	srand(time(NULL));
	cout<<"Enter number of nos.\n";
	int n;
	cin>>n;
	const int m=n;
	int a[m];
	cout<<"The nos are:\n";
	for(int i=0;i<n;i++)
	{
			a[i]=rand()%10; //Nos ranging from 0 to 10
			//getch();
			cout<<a[i]<<"\t";
	}
	cout<<endl<<endl;
	selection(a,n);
}
void selection(int a[],int n)
{
	 int small,pos=-1,count=0;
	 for(int i=0;i<n;i++)
	 {
			 small=MIN;
			 for(int j=i;j<n;j++)
			 {
                     if(a[j]<small)
			 		 {
 			            small=a[j];
		                pos=j;
		             }
			 }
			 //swap smallest element with a[i]
			 int temp=a[pos];
			 a[pos]=a[i];
			 a[i]=temp;
			 count++;
			 for(int k=0;k<n;k++)
			         cout<<a[k]<<"\t";
			 cout<<endl;
	 }
	 cout<<"\nNo. of swaps="<<count<<"\n";
	 getch();
}
int main()
{
	input();
	return 0;
}
