#include<stdio.h>
#include<conio.h>
#include<fstream.h>
#include<stdlib.h>
#include<string.h>
void insertion();
void display();
void sorting_marks();
void sorting_roll();
void mergesort(int *,int,int);
void merge(int *,int ,int ,int,int);
void search();
void avmarks();
int rollno[100],i,j,arr[100],n;
int  p_marks,c_marks,m_marks,e_marks,cs_marks;

char name[100];
FILE *fd,*fr,*d;

int  marks()
{ int total;
 total=(p_marks+c_marks+m_marks+e_marks+cs_marks);
return total;
}
void insertion() //INSERTION IN DATABASE
{
long int roll,a;
char name[50],n[50];


clrscr();
fd=fopen("database.txt","r");

    printf("\nPlease Enter The New Details of student \n");
    printf("\nEnter The roll number of student ");
    scanf("%ld",&roll);
    fflush(stdin);
    printf("\n\nEnter The Name of student ");
    gets(name);
    printf("\nEnter The marks in Algorithm out of 100 : ");
    scanf("%d",&p_marks);
    printf("\nEnter eThe marks in Software out of 100 : ");
    scanf("%d",&c_marks);
    printf("\nEnter The marks in Compiler out of 100 : ");
    scanf("%d",&m_marks);
    printf("\nEnter The marks in Network out of 100 : ");
    scanf("%d",&e_marks);
    printf("\nEnter The marks in English out of 100 : ");
    scanf("%d",&cs_marks);
    marks();
strcpy(n,name);
a=roll;
while(!feof(fd))
{
fscanf(fd,"%s %d %d %d %d %d %d\n",&name[i],&rollno[i],&p_marks,&c_marks,&m_marks,&e_marks,&cs_marks);
if(a==rollno[i])
{
printf("\nRecord is already Present\n\t");
printf("\nPress any Key\n");
break;
}
i=i+1;
}
fclose(fd);
}
void display() //VIEWING DATABASE RECORDS
{
clrscr();
fd=fopen("database.txt","r");
i=0;

printf("\n\t\t================================");
printf("\n\t\t LIST OF INSERTED RECORDS");
printf("\n\t\t================================\n\n");
printf("\n------------------------\nNAME ROLL NO MARKS\n------------------------\n");
while(!feof(fd))
{
fscanf(fd,"%s %d %d %d %d %d %d\n",&name[i],&rollno[i],&p_marks,&c_marks,&m_marks,&e_marks,&cs_marks);
printf("%s %d %d %d %d %d %d\n",name[i],rollno[i],p_marks,c_marks,m_marks,e_marks,cs_marks);
i=i+1;
}
fclose(fd);
printf("\n\n*****PRESS ANY KEY*****");

}
void sorting_marks() //SORTING RECORDS(BUBBLE SORT)
{
clrscr();
fd=fopen("database.txt","r");
fr=fopen("record.txt","w");
i=0;
while(!feof(fd))
{

fscanf(fd,"%s %d %d\n",&name[i],&rollno[i],&marks[i]);
arr[i]=marks[i];
i=i+1;
}
n=i;
mergesort(arr,0,n-1);
//printf("\n\n****SORTED RECORDS(MARKS BASIS)****\n\n");
//for(i=0; i<n; i++)
//printf("%s %d %d \n",name[i],rollno[i],arr[i],"\n");
for(i=0; i<n; i++)
{
for(j=0; j<n; j++)
{
if(arr[i]==marks[j])
fprintf(fr,"%s %d %d \n",name[j],rollno[j],marks[j],"\n");
}
}
fclose(fd);
fclose(fr);
fr=fopen("record.txt","r");
i=0;
printf("\n\n****SORTED RECORDS(MARKS BASIS)****\n\n");

while(!feof(fr))
{
fscanf(fd,"%s %d %d\n",&name[i],&rollno[i],&marks[i]);
printf("%s %d %d\n",name[i],rollno[i],marks[i]);
i=i+1;
}
fclose(fr);
printf("\n\n*****PRESS ANY KEY*****");

}
void sorting_roll()
{
clrscr();
fd=fopen("database.txt","r");
fr=fopen("record.txt","w");
i=0;
while(!feof(fd))
{
fscanf(fd,"%s %d %d\n",&name[i],&rollno[i],&marks[i]);
arr[i]=rollno[i];
i=i+1;
}

n=i;
mergesort(arr,0,n-1);
//printf("\n\n****SORTED RECORD(ROLLNO BASIS)****\n\n");
//for(i=0; i<n; i++)
//printf("%s %d %d \n",name[i],arr[i],marks[i],"\n");
for(i=0; i<n; i++)
{
for(j=0; j<n; j++)
{
if(arr[i]==rollno[j])
fprintf(fr,"%s %d %d \n",name[j],rollno[j],marks[j],"\n");
}
}
fclose(fd);
fclose(fr);
fr=fopen("record.txt","r");
i=0;
printf("\n\n****SORTED RECORDS(ROLLNO BASIS)****\n\n");
while(!feof(fr))
{
fscanf(fd,"%s %d %d\n",&name[i],&rollno[i],&marks[i]);
printf("%s %d %d\n",name[i],rollno[i],marks[i]);

i=i+1;
}
fclose(fr);
printf("\n\n*****PRESS ANY KEY*****");

}
void mergesort(int a[],int i,int j)
{
int mid;
if(i<j)
{
mid=(i+j)/2;
mergesort(a,i,mid); //left recursion
mergesort(a,mid+1,j); //right recursion
merge(a,i,mid,mid+1,j); //merging of two sorted subarrays
}
}
void merge(int a[],int i1,int j1,int i2,int j2)
{
int temp[50]; //array used for merging
int i,j,k;
i=i1; //beginning of the first list

j=i2; //beginning of the second list
k=0;
while(i<=j1 && j<=j2) //while elements in both lists
{
if(a[i]<a[j])
temp[k++]=a[i++];
else
temp[k++]=a[j++];
}
while(i<=j1) //copy remaining elements of the first list
temp[k++]=a[i++];
while(j<=j2) //copy remaining elements of the second list
temp[k++]=a[j++];
//Transfer elements from temp[] back to a[]
for(i=i1,j=0;i<=j2;i++,j++)
a[i]=temp[j];
}
void search() //SEARCHING RECORD BY ROLL NO
{
int i,roll,ch,mark,rollno;
char name[50];

clrscr();
fd=fopen("database.txt","r");
printf("\n\t\t=========================");
printf("\n\t\t SEARCHING RECORDS");
printf("\n\t\t=========================\n\n");
printf("\n\n******ENTER ROLL NUMBER:");
scanf("%d",&rollno);
i=0;
while(!feof(fd))
{
fscanf(fd,"%s %d %d\n",&name,&roll,&mark);
if(rollno==roll)
{
printf("\nNAME ROLLNO MARKS\n");
printf("%s %d %d\n",name,roll,mark);
break;
}
else
i=i+1;
}
fclose(fd);
printf("\n\n*****PRESS ANY KEY*****");


}
void avmarks() //CALCULATING AVERAGE MARKS OF ALL STUDENTS
{
int ma=0,n,i,x=0;
float avg;
clrscr();
printf("\n\t\t================================");
printf("\n\t\t AVERAGE MARKS OF STUDENTS");
printf("\n\t\t================================\n\n");
fr=fopen("database.txt","r");
i=0;
while(!feof(fr))
{
fscanf(fr,"%s %d %d\n",&name[i],&rollno[i],&marks[i]);
x=x+marks[i];
arr[i]=marks[i];
i=i+1;
}
n=i;
avg=x/n;
printf("\nAVERAGE MARKS OF %d STUDENTS ARE:%f",n,avg);
for(i=0;i<n;i++)

{
if(ma<arr[i])
{
ma=arr[i];
}
}
printf("\n\tMaximum Marks:-%d",ma);
fclose(fr);
printf("\n\n*****PRESS ANY KEY*****");

void main()
{

int ch;

{
clrscr();
printf("\n\t\t***** STUDENT DATABASE SYSTEM *****");
printf("\n\t\t**********MADE BY:*******\n\t\tMD TARIQULAZAM(14SCSE101224)\n\t\t KUMAR ANAND(14SCSE101249)\n");
printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================");
printf("\n\t\t[1] ADD STUDENT RECORD");
printf("\n\t\t[2] VIEW DATABASE ENTRIES");
printf("\n\t\t[3] SEARCH RECORD BY ROLL NO");
printf("\n\t\t[4] AVERAGE STUDENTS MARKS");
printf("\n\t\t[5] SORT FILE ON MARKS BASIS");
printf("\n\t\t[6] SORT FILE ON ROLL NO BASIS");
printf("\n\t\t[7] Delete Record");
printf("\n\t\t[8] EXIT\n\t\t=================\n\t\t");
printf("PLEASE ENTER YOUR CHOICE:");
scanf("%d",&ch);

switch(ch)
{
case 1: insertion();
break;
case 2: display();
break;
case 3: search();
break;
case 4: avmarks();
break;
case 5: sorting_marks();
break;
case 6: sorting_roll();
break;
case 7: printf("\n\n\t\tARE YOU SURE YOU WANT TO EXIT?");
break;
default: printf("OOPS WRONG CHOICE!!! ENTER CHOICEAGAIN\n");
}while(ch>=7)

}