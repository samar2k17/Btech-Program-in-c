#include<stdio.h>
struct student
{
    char name[20];
    int rn;
    int tm;
}s1;
int a[25];
int no,i,j,k,l,p,q,s,t;
char c;
int f=0;
FILE *fp,*ft,*fr;
main()
{
    int b;
    while(1)
    {
        printf("\n1:Create 2:List 3:Delete 4:Search 5:Sort w.r.t Roll# 6:Sort w.r.t Mark :");
        scanf("%d",&b);
        switch(b)
        {
            case 1:create();
                break;
            case 2:list();
                break;
            case 3:delete();
                break;
            case 4:search();
                break;
            case 5:sort();
                break;
            case 6:marksort();
                break;
            default:
                break;
        }
    }
}
        /*Function to insert a record*/
create()
{
    s=6;
    fp=fopen("stn.dat","a+");
    while(s==6)
    {
        fclose(fp);
        search();
        fp=fopen("stn.dat","a+");
        if(f==0)
        {
            s1.rn=no;
            printf("\nEnter student's name,mark:");
            scanf("%s %d",s1.name,&s1.tm);
            fwrite(&s1,sizeof(s1),1,fp);
        }
        printf("\n Enter 6 to create another:");
        fflush(stdin);
        scanf("%d",&s);
    }
    fclose(fp);
}
        /*Function to display all records*/
list()
{
    fp=fopen("stn.dat","r");
    printf("\n NAME ROLLNO MARK :");
    while(fread(&s1,sizeof(s1),1,fp)==1)
    {
        printf("\n%s\t%4d %4d\n",s1.name,s1.rn,s1.tm);
        
    }fclose(fp);
        }
        /*Function to delete records*/
delete()
{
    fp=fopen("stn.dat","r");
    p=1;
    while(p==1)
    {
        printf("\nEnter student's RollNo to delete:");
        scanf("%d",&no);
        ft=fopen("temp.dat","a+");
        while(fread(&s1,sizeof(s1),1,fp)==1)
        {
            if (s1.rn != no)
            fwrite(&s1,sizeof(s1),1,ft);
            
            remove("stn.dat");
            rename("temp.dat","stn.dat");
            fp=fopen("stn.dat","r+");
            printf("Enter 1 to delete another");
            fflush(stdin);
            scanf("%d",&p);
        }
        fclose(fp);
        fclose(ft);
    }
}
        /*Function to search a record*/
search()
{
    f=0;
    fp=fopen("stn.dat","r");
    printf("\nEnter RollNo:");
    scanf("%d",&no);
    while(fread(&s1,sizeof(s1),1,fp)==1)
    {
        if(s1.rn==no)
        {
            f=1;
            break;
        }
    }
    if (f==1)
    {
        printf("\nRECORD EXISTS DETAILS ARE :");
        printf("%s %d %d\n",s1.name,s1.rn,s1.tm);
    }
    else
    {
        printf("\n RECORD NOT EXISTS\n");
        fclose(fp);
    }
}
        /*Function to sort w.r.t RollNo*/
sort()
{
    fp=fopen("stn.dat","r+");
    fr=fopen("spp.dat","a+");
    i=0;
    while(fread(&s1,sizeof(s1),1,fp)==1)
    {
        a[i]=s1.rn;
        i++;
    }
    l=i;
    isort();
    for(i=l-1;i>=0;i--)
    {
        rewind(fp);
        while(fread(&s1,sizeof(s1),1,fp)==1)
            if(a[i]==s1.rn)
                fwrite(&s1,sizeof(s1),1,fr);

    }
    fclose(fp);
    fclose(fr);
    remove("stn.dat");
    rename("spp.dat","stn.dat");
}
isort()
{
    int t;
    for(j=1;j<1;j++)
    {
        for(k=j;(k>0 || (a[k-1]< a[k]));k--)
        {
            if(a[k]<a[k-1])
            {
                t=a[k];
                a[k]=a[k-1];
                a[k-1]=t;
            }
        }
    }
}
        /*Function to sort w.r.t marks */
marksort()
{
    int i;
    fp=fopen("stn.dat","r+");
    ft=fopen("smm.dat","w+");
    i=0;
    while(fread(&s1,sizeof(s1),1,fp)==1)
    {
        a[i]=s1.tm;
        i++;
    }
        l=i;
    isort();
    for(i=l-1;i>=0;i--)
    {
        rewind(fp);
        while(fread(&s1,sizeof(s1),1,fp)==1)
            if(s1.tm==a[i])
                fwrite(&s1,sizeof(s1),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("stn.dat");
    rename("smm.dat","stn.dat");
}
