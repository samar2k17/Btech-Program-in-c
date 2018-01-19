#include<stdio.h>
#include<conio.h>
void selection_sort(int a[],int n)
{
int min,temp,i,j;
for(i=0;i<n-1;i++)
{

for(j=i+1;j<n;j++)
{
 if(a[j]<a[i])
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
}
void main()
{
int a[20],i,n ;
clrscr();
printf("selection sort\n");
printf("enter the size of array\n");
scanf("%d",&n);
printf("enter the data to be sorted\n");
for(i=0;i<n;i++)
scanf("%d",a[i]);
selection_sort(a,n);
printf("the sorted array is:- \n");
for(i=0;i<n;i++)
printf("%d",a[i]);
getch();
}
