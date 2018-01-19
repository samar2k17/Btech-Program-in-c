#include<stdio.h>
#include<conio.h>
void mergesort (int,int,int)
void merge (int,int,int,int)

void main()
{      int i,n;
       int arr[20];
       clrscr();
       printf("enter the size of the array\n");
       scanf("%d",&n);
       printf("enter the elemnts\n");
       for(i=0;i<=n;i++)
	    scanf("%d",&arr[i]);

	mergesort(arr,0,n-1);
	printf("soted array:");
	for(i=0;i<n;i++)
	printf("%d",arr[i]);
	getch();
}
void  mergesort(int arr[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}

void  merge(int arr[],int l,int m,int h)
{

	int n1,n2,i,j,k;
	n1=m-l+1;
	n2=h-m;
	int arr1[n1+1],arr2[n2+1];
	for(i=1;i<n1;i++)
		arr1[i]=arr[l+i-1];
	for(j=1;j<n2;j++)
		arr2[j]=arr[m+j];
	arr1[i]=9999;
	arr2[j]=9999;
	i=1;
	j=1;
    for(k=l;k<=h;k++)
		if(arr1[i]<=arr2[j])
		arr[k]=arr1[i];
		i=i+1;
	else
		arr[k]=arr2[j];
		j=j+1;
}





