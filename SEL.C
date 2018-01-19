#include<stdio.h>
#include<string.h>
#include<conio.h>
void main()
{
int n,small,i,j;
char a[20];
for(i=1;i<=strlen(a)-1;i++);
{
small=i;
for(j=i+1;j<n;j++)
{
if (a[i]<a[small])
small=i;}
}
getch();
}