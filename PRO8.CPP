//***************************************************************
//                   HEADER FILE USED IN PROJECT
//***************************************************************

#include<conio.h>
#include<stdio.h>
#include<process.h>

//***************************************************************
//                   STURUCTURE USED IN PROJECT
//****************************************************************

struct student
{
 int rollno;
 char name[50];
 int p_marks,c_marks,m_marks,e_marks,cs_marks;
 float per;
 char grade;
 int std;
}st;

//***************************************************************
//        global declaration
//****************************************************************

 FILE *fptr;

//***************************************************************
//        function to write in file
//****************************************************************

void write_student()
   {
    fptr=fopen("student.dat","ab");
    printf("\nPlease Enter The New Details of student \n");
    printf("\nEnter The roll number of student ");
    scanf("%d",&st.rollno);
    fflush(stdin);
    printf("\n\nEnter The Name of student ");
    gets(st.name);
    printf("\nEnter The marks in Algorithm out of 100 : ");
    scanf("%d",&st.p_marks);
    printf("\nEnter The marks in Software out of 100 : ");
    scanf("%d",&st.c_marks);
    printf("\nEnter The marks in Compiler out of 100 : ");
    scanf("%d",&st.m_marks);
    printf("\nEnter The marks in Network out of 100 : ");
    scanf("%d",&st.e_marks);
    printf("\nEnter The marks in English out of 100 : ");
    scanf("%d",&st.cs_marks);
    st.per=(st.p_marks+st.c_marks+st.m_marks+st.e_marks+st.cs_marks)/5.0;
    if(st.per>=60)
       st.grade='A';
    else if(st.per>=50 &&st.per<60)
      st.grade='B';
    else if(st.per>=33 &&st.per<50)
      st.grade='C';
    else
     st.grade='F';
    fwrite(&st,sizeof(st),1,fptr);
    fclose(fptr);
    printf("\n\nStudent Record Has Been Created ");
    getch();
}


//***************************************************************
//        function to read all records from file
//****************************************************************


void display_all()
{
    clrscr();
    printf("\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n");
    fptr=fopen("student.dat","rb");
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
      printf("\nRoll Number of Student : %d",st.rollno);
      printf("\nName of student : %s",st.name);
      printf("\nMarks in Algorithm : %d",st.p_marks);
      printf("\nMarks in Software : %d",st.c_marks);
      printf("\nMarks in Compiler : %d",st.m_marks);
      printf("\nMarks in Network : %d",st.e_marks);
      printf("\nMarks in English : %d",st.cs_marks);
      printf("\nPercentage of student is  : %.2f",st.per);
      printf("\nGrade of student is : %c",st.grade);
      printf("\n\n====================================\n");
      getch();
    }
    fclose(fptr);
    getch();
}


//***************************************************************
//        function to read specific record from file
//****************************************************************


void display_sp(int n)
{
    int flag=0;
    fptr=fopen("student.dat","rb");
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
     if(st.rollno==n)
        {
         clrscr();
            printf("\nRoll number of student : %d",st.rollno);
            printf("\nName of student : %s",st.name);
            printf("\nMarks in Algorithm : %d",st.p_marks);
            printf("\nMarks in Software : %d",st.c_marks);
            printf("\nMarks in Compiler : %d",st.m_marks);
            printf("\nMarks in Network : %d",st.e_marks);
            printf("\nMarks in English : %d",st.cs_marks);
            printf("\nPercentage of student is  : %.2f",st.per);
            printf("\nGrade of student is : %c",st.grade);
         flag=1;
        }
    }
    fclose(fptr);
if(flag==0)
 printf("\n\nrecord not exist");
    getch();
}


//***************************************************************
//        function to modify record of file
//****************************************************************


void modify_student()
{
    int no,found=0;
    clrscr();
    printf("\n\n\tTo Modify ");
    printf("\n\n\tPlease Enter The roll number of student");
    scanf("%d",&no);
    fptr=fopen("student.dat","rb+");
    while((fread(&st,sizeof(st),1,fptr))>0 && found==0)
    {
    if(st.rollno==no)
           {
            printf("\nRoll number of student : %d",st.rollno);
            printf("\nName of student : %s",st.name);
            printf("\nMarks in Algorithm : %d",st.p_marks);
            printf("\nMarks in Software : %d",st.c_marks);
            printf("\nMarks in Compiler : %d",st.m_marks);
            printf("\nMarks in Network : %d",st.e_marks);
            printf("\nMarks in English : %d",st.cs_marks);
            printf("\nPercentage of student is  : %.2f",st.per);
            printf("\nGrade of student is : %c",st.grade);
            printf("\nPlease Enter The New Details of student \n");
            printf("\nEnter The roll number of student ");
            scanf("%d",&st.rollno);
            fflush(stdin);
            printf("\n\nEnter The Name of student ");
            gets(st.name);
            printf("\nEnter The marks in Algorithm out of 100 : ");
            scanf("%d",&st.p_marks);
            printf("\nEnter The marks in Software out of 100 : ");
            scanf("%d",&st.c_marks);
            printf("\nEnter The marks in Compiler out of 100 : ");
            scanf("%d",&st.m_marks);
            printf("\nEnter The marks in Network out of 100 : ");
            scanf("%d",&st.e_marks);
            printf("\nEnter The marks in English out of 100 : ");
            scanf("%d",&st.cs_marks);
            st.per=(st.p_marks+st.c_marks+st.m_marks+st.e_marks+st.cs_marks)/5.0;
            if(st.per>=60)
               st.grade='A';
            else if(st.per>=50 && st.per<60)
               st.grade='B';
            else if(st.per>=33 && st.per<50)
               st.grade='C';
            else
               st.grade='F';
            fseek(fptr,-(long)sizeof(st),1);
            fwrite(&st,sizeof(st),1,fptr);
            printf("\n\n\t Record Updated");
            found=1;
           }
         }
    fclose(fptr);
    if(found==0)
    printf("\n\n Record Not Found ");
    getch();
}

//***************************************************************
//        function to sort
//****************************************************************
 void sort(int m, int x[ ])
   {                                                           
       int i, j, t;                                            
                                                               
       for(i = 1; i <= m-1; i++)                               
          for(j = 1; j <= m-i; j++)                             
             if(x[j-1] >= x[j])                                
             {
                t = x[j-1];                                    
                x[j-1] = x[j];                                 
                x[j] = t;                                      
             } 
}




//***************************************************************
//        function to delete record of file
//****************************************************************


void delete_student()
   {
    int no;
    FILE *fptr2;
    clrscr();
    printf("\n\n\n\tDelete Record");
    printf("\n\nPlease Enter The roll number of student You Want To Delete");
    scanf("%d",&no);
    fptr=fopen("student.dat","rb");

    fptr2=fopen("Temp.dat","wb");
    rewind(fptr);
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
       if(st.rollno!=no)
       {
      fwrite(&st,sizeof(st),1,fptr2);
       }
    }
    fclose(fptr2);
    fclose(fptr);
    remove("student.dat");
    rename("Temp.dat","student.dat");
    printf("\n\n\tRecord Deleted ..");
    getch();
}

//***************************************************************
//        function to display all students grade report
//****************************************************************

    void class_result()
    {
     clrscr();
     fptr=fopen("student.dat","rb");
     if(fptr==NULL)
     {
       printf("ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File");
       printf("\n\n\n Program is closing ....");
       getch();
       exit(0);
     }

     printf("\n\n\t\tALL STUDENTS RESULT \n\n");
      printf("====================================================\n");
      printf("R.No.  Name       P   C   M   E   CS  %age   Grade\n");
      printf("====================================================\n");

      while((fread(&st,sizeof(st),1,fptr))>0)
     {
       printf("%-6d %-10s %-3d %-3d %-3d %-3d %-3d %-3.2f  %-1c\n",st.rollno,st.name,st.p_marks,st.c_marks,st.m_marks,st.e_marks,st.cs_marks,st.per,st.grade);
     }
     fclose(fptr);
     getch();
}

//***************************************************************
//        function to display result menu
//****************************************************************

   void result()
   {
    int ans,rno;
    char ch;
    clrscr();
    printf("\n\n\nRESULT MENU");
    printf("\n\n\n1. Class Result\n\n2. Student Report Card\n\n3.Back to Main Menu");
    printf("\n\n\nEnter Choice (1/2)? ");
    scanf("%d",&ans);
    switch(ans)
    {
     case 1 : class_result();break;
     case 2 : {
        do{
        char ans;
        clrscr();
        printf("\n\nEnter Roll Number Of Student : ");
        scanf("%d",&rno);
        display_sp(rno);
        printf("\n\nDo you want to See More Result (y/n)?");
        scanf("%c",&ans);
        }while(ans=='y'||ans=='Y');
        break;
           }
     case 3: break;
     default:  printf("\a");
    }
 }

//***************************************************************
//        INTRODUCTION FUNCTION
//****************************************************************

void intro()
{
 clrscr();
 gotoxy(35,11);
 printf("STUDENT");
 gotoxy(33,14);
 printf("REPORT CARD");
 gotoxy(35,17);
 printf("PROJECT");
 printf("\n\n\n\n\n\nMADE BY : SULABH AGRAWAL");
 printf("\n\nCOLLEGE : ASN ENGINEERING COLLEGE");
 getch();
}
//***************************************************************
//        ENTRY / EDIT MENU FUNCTION
//****************************************************************
void entry_menu()
{
    char ch2;
   clrscr();
  printf("\n\n\n\tENTRY MENU");
  printf("\n\n\t1.CREATE STUDENT RECORD");
  printf("\n\n\t2.DISPLAY ALL STUDENTS RECORDS");
  printf("\n\n\t3.SEARCH STUDENT RECORD ");
  printf("\n\n\t4.MODIFY STUDENT RECORD");
  printf("\n\n\t5.DELETE STUDENT RECORD");
  printf("\n\n\t6.BACK TO MAIN MENU");
  printf("\n\n\tPlease Enter Your Choice (1-6) ");
  ch2=getche();
  switch(ch2)
  {
    case '1': clrscr();
          write_student();
          break;
    case '2': display_all();break;
    case '3':  {
           int num;
           clrscr();
           printf("\n\n\tPlease Enter The roll number ");
           scanf("%d",&num);
           display_sp(num);
           }
           break;
      case '4': modify_student();break;
      case '5': delete_student();break;
      case '6': break;
      default:printf("\a");entry_menu();
   }
}
//***************************************************************
//        THE MAIN FUNCTION OF PROGRAM
//****************************************************************
void main()
{
  char ch;
  intro();
  do
    {
      clrscr();
      printf("\n\n\n\tMAIN MENU");
      printf("\n\n\t01. RESULT MENU");
      printf("\n\n\t02. ENTRY/EDIT MENU");
      printf("\n\n\t03. EXIT");
      printf("\n\n\tPlease Select Your Option (1-3) ");
      ch=getche();
      switch(ch)
      {
         case '1': clrscr();
               result();
               break;
          case '2': entry_menu();
                break;
          case '3':exit(0);
          default :printf("\a");
    }
    }while(ch!='3');
}
//***************************************************************
//                END OF PROJECT
//***************************************************************