/*Merge Sort*/
#include <iostream>
#include <conio.h>
using namespace std;

#define INF 100000

void merge(int a[],int p,int q,int r)
{
	 int n1 = q-p+1;
	 int n2 = r-q;
	 const int m1=n1;
	 const int m2=n2;
	 int L[m1],R[m2];
	 int i,j,k;
	 
	 for(i = 0; i < n1; i++)
        L[i] = a[p + i];
    for(j = 0; j < n2; j++)
        R[j] = a[q + j+ 1];
        
	 L[n1] = INF;
	 R[n2] = INF;
	 i = 0; //i=1
	 j = 0; //j=1
	 //k=1;
	 for(k=p;k<r;k++)
	 {
			 if(L[i] <= R[j])
			 {
					 a[k] = L[i];
					 i++;
			 }
			 else
			 {
				 a[k] = R[j];
				 j++;
			 }
	 }
	  

    //copying left over elements of L[] if any
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    //copying left over elements of R[] if any
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
void merge_sort(int a[],int p,int r)
{
	 if(p<r)
	 {
	  int q=(p+r)/2;
	   merge_sort(a,p,q);
	   merge_sort(a,q+1,r);
	   merge(a,p,q,r);
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
	 merge_sort(a,0,n-1);
	 for(int i = 0;i<n;i++)
	 {
			 cout<<a[i]<<"\t";
	 }
	 cout<<endl;
	 getch();
	 return 0;
}
