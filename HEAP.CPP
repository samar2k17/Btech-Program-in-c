#include<stdio.h>
#include<conio.h>


void heapify(int a[],int i,int heapsize)
{
  int temp,largest;
  int l=(2*i)+1;
  int r=(2*i)+2;
  if( (l<=heapsize) && (a[l] > a[i] ) )
  {
  largest=l;
  }
  else
  largest=i;
  if((r<=heapsize) && (a[r] > a[largest]))
  largest=r;
  if(largest!=i)
  {
	temp=a[i];
	a[i]=a[largest];
	a[largest]=temp;
	heapify(a,largest,heapsize);
	}
  }

void build(int a[],int heapsize)
{
int i;
for(i=heapsize/2;i>=0;i--)
{
   heapify(a,i,heapsize);


}
 }
void heapsort(int a[],int heapsize)
{
  int i,temp;
  build(a,heapsize);
  for(i=heapsize;i>=0;i--)
  {
     temp=a[i];
     a[i]=a[0];
     a[0]=temp;
     heapsize--;
     heapify(a,0,heapsize);
  }
}

void main()
{
  int i,j,n,a[100];


  clrscr();
  printf("Name= M.M.Samar\n");
  printf("Admsn= 15scse101314\n");
  printf("How Many No U Want to Sort\n");
  scanf("%d",&n);
  printf("Enter the no to be sorted\n");
  for(j=0;j<=n;j++)
  scanf("%d",&a[j]);
  heapsort(a,n);
   printf("sorted array is :- ") ;
  for(i=0;i<=n;++i)

    printf("%d  ",a[i]);
    getch();
}











