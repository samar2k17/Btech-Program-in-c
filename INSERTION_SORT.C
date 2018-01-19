#include<stdio.h>
#include<conio.h>
void insertion_sort(int a[]);

void main()
{
int i,n,a[20];
clrscr();
printf("enter the size of the array to be sorted\n");
scanf("%d",&n);
printf("Enter the array to be sorted/n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
insertion_sort(a,n);
printf("the sorted is: ");
for(i=0;i<n;i++)
printf("a[i]");
getch();

}
void insertion_sort(int a[],n)
{
int key,i,j;
for(j=2;j<n;j++)
key=a[j];
i=j-1;
while(i>0 && a[i]>key)
{
a[i+1]=a[i];
i=i-1;
a[i+1]=key;
}
}
