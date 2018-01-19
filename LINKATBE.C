#include<stdio.h>
#include<malloc.h>
#include<conio.h>
struct node
{
int data;
struct node* next;
};

node* insert(node* head,int x)
{
  struct node* temp=(struct node *)malloc(sizeof(struct node));
  temp->data=x;
  temp->next=NULL;
  while(head!=NULL)
  {  temp->data=head;
     head=temp;}
     return head;

}
void print(node* head)
{
printf("List is: ");
while(head!=NULL)
{
 printf("%d",head->data);
 head=head->next;

}
printf("\n");
}


void main()
{

 int n,i,x;
 clrscr();
 node* head=NULL;
 printf("how many number\n");
 scanf("%d",&n);
 for(i=0;i<n;i++)
  {
    printf("enter the number\n");
    scanf("%d",&x);
    head= insert(head,x);
    print(head);
  }
  getch();
 }