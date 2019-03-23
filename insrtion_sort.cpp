/*insertion sort*/
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

void insertion(int a[],int n)
{
	 int count=0;
	 for(int i=1;i<n;i++)
	 {
			 int no=a[i];
			 int j=i-1;
			 count=0;
			 while(a[j]>no && j>=0)
			 {
			     a[j+1]=a[j];
			     j--;
			     count++;
			 }
			 cout<<"No. of shifting="<<count<<endl;
			 a[j+1]=no;
			 for(int k=0;k<n;k++)
			         cout<<a[k]<<"\t";
			 cout<<endl;
	 }
	 cout<<endl;
  	 getch();
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
			a[i]=rand()%10; //Nos ranging from 0 to 10
			//getch();
			cout<<a[i]<<"\t";
	}
	cout<<endl<<endl;
	insertion(a,n);
}
int main()
{
	input();
	return 0;
}
