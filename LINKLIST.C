#include<stdio.h>
#include<malloc.h>
#include<conio.h>
typedef struct node
{
   int data;
   struct node* link;
}node;
  void main()
  {
     int n;
       printf("enter the no of elements\n");
	  scanf("%d",&n);
  }
  node * create (int n)
  {  int i;
  node* head=NULL;
  node* temp=NULL;
  for(i=0;i<n;i++)
  {
     temp=(node*)malloc(size of(node));
     printf("enter value of node no%d",i+1);
     scanf("%d",&temp->data);
     temp->next=NULL;
     if(head==NULL)

