/*bubble sort*/
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

void bubble(int a[],int n)
{
	 int count=0;
	 for(int i=0;i<n;i++)
	 {
			 for(int j=0;j<n-i-1;j++)
			 {
					 //swap adjacent elements if required
					 if(a[j]>a[j+1])
					 {
						 //cout<<"a[j]="<<a[j]<<" a[j+1]="<<a[j+1]<<endl;
						 int temp=a[j];
						 a[j]=a[j+1];
						 a[j+1]=temp;
						 //cout<<endl<<a[j]<<" and "<<a[j+1]<<" swapped\n";
						 for(int k=0;k<n;k++)
			         	 		 cout<<a[k]<<"\t";
						 cout<<endl;
						 count++;
					 }
			 }
			 cout<<endl<<endl;
			 for(int k=0;k<n;k++)
			         cout<<a[k]<<"\t";
			 cout<<endl;
	 }
     cout<<"\nNo. of swaps="<<count<<"\n";
	 getch();
}
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
	bubble(a,n);
}
int main()
{
	input();
	return 0;
}
