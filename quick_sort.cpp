/* quick sort */
#include <iostream>
#include <conio.h>
using namespace std;

int partition(int a[],int p,int r)
{
	int pivot = a[r];
	int i = p-1;
	for(int j=p;j<r;j++) //since pivot is at r position
	{
			if(a[j] <= pivot)
			{
					i++;
					//swap a[i] and a[j]
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
			}
	}
	//swap a[i+1],a[r]
	int temp = a[i+1];
	a[i+1] = a[r];
	a[r] = temp;
	return i+1;
}

void quicksort(int a[],int p,int r)
{
	 if(p>=r)
	 {
			 return;
	 }
	 else
	 {
			 int q = partition(a,p,r);
			 quicksort(a,p,q-1);
			 quicksort(a,q+1,r);
	 }
}

int main()
{
     cout<<"Enter no. of elements\n";
	 int n;
	 cin>>n;
	 const int m = n;
	 int a[m];
	 cout<<"Enter array elements\n";
	 for(int i=0;i<m;i++)
	 {
			 cin>>a[i];
	 }
	 quicksort(a,0,m-1);
	 for(int i = 0;i<n;i++)
	 {
			 cout<<a[i]<<"\t";
	 }
	 cout<<endl;
	 getch();
	 return 0;
}
