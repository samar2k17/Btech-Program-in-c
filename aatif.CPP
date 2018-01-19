//***************************************************************************
//				HEADER FILES
//***************************************************************************
#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
//***************************************************************************
//				GLOBAL DECLARATIONS
//***************************************************************************
fstream fio;
ifstream fin;ifstream fin2;
ofstream fout;
char pwd[20];
int pos;char ans1;

//***************************************************************************
//				STRUCTURES
//***************************************************************************
struct date
{
	int dd;
	int mm;
	int yy;
}d,d1;

//***************************************************************************
//				FUNCTION DECLARATIONS
//***************************************************************************

//ADMIN FUNCTIONS
void admin();
void admin_edisplay();
void admin_udisplay();
void admin_umodify();
void admin_udelete();
void admin_einsert();
void admin_emodify();
void admin_edelete();
void admin_view_schedule();
void admin_menu();

//USER FUNCTIONS
void signup();
void login();
void user();
void enter_profile();
void display_profile();
void modify_profile();
void delete_profile();
void apply();
void eligible();
void filter();
void view_schedule();
void user_menu();

//OTHER FUNCTIONS
void enter_password();
char *enter_pwd();
int compare_date(date d1,date d2);
int search_exam(char *name);
int search_age(int age1,int age2);
int search_percentage(float percentage);
int search_stream(char stream);
int search_fees(int fees);
int search_date(date d1);
int compare_date(date d1,date d2);

//***************************************************************************
//				CLASSSES
//***************************************************************************

class schedule
{
	char username[20];
	char examname[20];

	public:

	void assign(char *uname,char *ename);
	char *ret_uname()    //function returning character array
	{
		return username;
	}
	char *ret_ename()    //function returning character array
	{
		return examname;
	}
}s;

class user
{
	char userid[20];
	char name[20];
	int age;
	float percentage;
	char stream;
	char password[20];

	public:

	char *ret_userid()   //function returning character array
	{
		return userid;
	}
	char *ret_name()     //function returning character array
	{
		return name;
	}
	char *ret_password() //function returning character array
	{
		return password;
	}
	int ret_age();
	float ret_percentage();
	char ret_stream();
	void display_user();
	void enter_user();
	void enter_password();
	void modify();

}u1,u2,user1;

class exam
{
	char name[20];
	int min_age;
	float percentage;
	date d;
	char stream;
	int max_age;
	int fees;

	public:

	char *ret_name()     //function returning character array
	{
		return name;
	}
	int ret_min_age();
	int ret_max_age();
	float ret_percentage();
	char ret_stream();
	int ret_fees();
	date ret_d();
	void display_exam();
	void enter_exam();
	void modify();

}e1,e2;
//***************************************************************************
//				MEMBER FUNCTIONS
//***************************************************************************
//CLASS SCHEDULE
void schedule::assign(char *uname,char *ename)
{
	strcpy(username,uname);
	strcpy(examname,ename);
}

//***************************************************************************
//CLASS USER

int user::ret_age()
{
	return age;
}
float user::ret_percentage()
{
	return percentage;
}
char user::ret_stream()
{
	return stream;
}
void user::display_user()
{
	cout<<"USER DETAILS\n";
	cout<<"\nUser ID : ";
	puts(userid);
	cout<<"Name : ";
	puts(name);
	cout<<"Age : "<<age;
	cout<<" || Percentage : "<<percentage;
	cout<<" || Stream : "<<stream;
	cout<<" || Password : ";
	puts(password);
}
void user::enter_user()
{
	cout<<"ENTER USER DETAILS\n\n";
	cout<<"User ID (characters only): ";
	gets(userid);
	cout<<"Name: ";
	gets(name);
	cout<<"Age: ";
	cin>>age;
	cout<<"Percentage: ";
	cin>>percentage;
	cout<<"Stream (s,c,h): ";
	cin>>stream;
}
void user::modify()
{
	display_user();
	char m_name[20]; int m_age; float m_percentage;
	char m_stream; char m_pwd[20];
	cout<<endl;
	cout<<"enter new name (press '.' to  retain old name)\n";
	gets(m_name);
	cout<<"enter new age (press -1 to retain old age)\n";
	cin>>m_age;
	cout<<"enter new percentage (press -1 to retain old percentage)\n";
	cin>>m_percentage;
	cout<<"enter new stream (press '.' to retain old stream)\n";
	cin>>m_stream;
	strcpy(m_pwd,enter_pwd());

	if(strcmpi(m_name,".")!=0)
		strcpy(name,m_name);
	if(m_age!=-1)
		age=m_age;
	if(m_percentage!=-1)
		percentage=m_percentage;
	if(m_stream!='.')
		stream=m_stream;
	if(strcmpi(m_pwd,".")!=0)
		strcpy(password,m_pwd);

}
void user::enter_password()
{
	char ch1;
	int k=0;
	cout<<"enter password ";
	while(1)
	{
		ch1=getch();
		if(ch1==13)
		break;
		else
		{
			cout<<"*";
			password[k++]=ch1;
		}
	}
	password[k]='\0';
}

//***************************************************************************
//CLASS EXAM

int exam::ret_min_age()
{
	return min_age;
}
int exam::ret_max_age()
{
	return max_age;
}
float exam::ret_percentage()
{
	return percentage;
}
char exam::ret_stream()
{
	return stream;
}
int exam::ret_fees()
{
	return fees;
}
date exam::ret_d()
{
	return d;
}
void exam::display_exam()
{
	cout<<"EXAM DETAILS\n";
	cout<<"Exam Name : ";
	puts(name);
	cout<<"Minimum Age : "<<min_age;
	cout<<" || Maximum Age : "<<max_age;
	cout<<" || Minimum Percentage : "<<percentage;
	cout<<" || Stream : "<<stream;
	cout<<" || Date : ";
	cout<<d.dd<<"-"<<d.mm<<"-"<<d.yy;
	cout<<" || Fees : Rs"<<fees;
	cout<<endl<<endl;
}
void exam::enter_exam()
{
	cout<<"ENTER EXAM DETAILS\n";
	cout<<"\nExam Name : ";
	gets(name);
	cout<<"\nMinimum Age : ";
	cin>>min_age;
	cout<<"\nMaximum Age : ";
	cin>>max_age;
	cout<<"\nMinimum Percentage : ";
	cin>>percentage;
	cout<<"\nStream : ";
	cin>>stream;
	cout<<"\nDate : \n";
	cout<<"dd : ";cin>>d.dd;
	cout<<"mm (int) : ";cin>>d.mm;
	cout<<"yy : ";cin>>d.yy;
	cout<<"\nFees : ";
	cin>>fees;
}

void exam::modify()
{
	display_exam();
	char m_name[20]; int m_min_age; int m_max_age; float m_percentage;
	char m_stream; int m_fees; date m_d;
	cout<<endl;
	cout<<"enter new name (press '.' to  retain old name)\n";
	gets(m_name);
	cout<<"enter new minimum age (press -1 to retain old age)\n";
	cin>>m_min_age;
	cout<<"enter new maximum age (press -1 to retain old age)\n";
	cin>>m_max_age;
	cout<<"enter new percentage (press -1 to retain old percentage)\n";
	cin>>m_percentage;
	cout<<"enter new stream (press '.' to retain old stream)\n";
	cin>>m_stream;
	cout<<"enter new fees (press -1 to retain old fees)\n";
	cin>>m_fees;
	cout<<"enter new date (press 0-0-0 to retain old date)\n";
	cout<<"date : "; cin>>m_d.dd;
	cout<<"month (int) : "; cin>>m_d.mm;
	cout<<"year : "; cin>>m_d.yy;

	if(strcmpi(m_name,".")!=0)
		strcpy(name,m_name);
	if(m_min_age!=-1)
		min_age=m_min_age;
	if(m_max_age!=-1)
		max_age=m_max_age;
	if(m_percentage!=-1)
		percentage=m_percentage;
	if(m_stream!='.')
		stream=m_stream;
	if(m_fees!=-1)
		fees=m_fees;
	if(m_d.dd!=0)
		{	d.dd=m_d.dd;
			d.mm=m_d.mm;
			d.yy=m_d.yy;
		}

}

//***************************************************************************
//				MAIN FUNCTION
//***************************************************************************
void main()
{
	int choice;
	textbackground(RED);
	do
	{
	clrscr();
	cout<<"\nENTRANCE EXAMINATION PORTAL PROGRAM\n";
	cout<<"\n1. User Profile";
	cout<<"\n2. Adminstrator Profile";
	cout<<"\n3. Exit the Program\n";
	cout<<"\nEnter Choice : ";
	cin>>choice;

	switch(choice)
	{
		case 1:
		user();
		break;

		case 2:
		admin();
		break;

		case 3:
		exit(0);
		break;

		default:
		cout<<"\nEnter Valid Choice!!";
	}
	if(ans1!='t')
	{
		cout<<"\nDo you want to continue with Program? (y/n)\n";
		cin>>ans1;
	}
	else
		ans1='y';
	}
	while(ans1=='y');

	getch();
}

//***************************************************************************
//				FUNCTION DEFINITIONS
//***************************************************************************

//***************************************************************************
//                              ADMIN FUNCTIONS
//***************************************************************************

void admin()
{
	textbackground(CYAN);
	textcolor(BLACK);
	do
	{
	clrscr();
	cout<<"ADMINSTRATOR PROFILE\n";
	cout<<"\nAdminstrator Profile ID : Admin_101\n";
	enter_password();
	if(strcmpi(pwd,"dps")==0)
	{
		clrscr();
		cout<<"Adminstrator has been logged in. Welcome!!\n";
		admin_menu();
	}
	else
	cout<<"\nThe password is wrong";
	if(ans1!='t')
	{
		cout<<"\nDo you want to continue with Adminstrator Login? (y/n)\n";
		cin>>ans1;
	}
	}
	while(ans1=='y');
	textcolor(WHITE);
}

void admin_menu()
{
	clrscr();
	textbackground(GREEN);
	textcolor(BLACK);
	int choice;
	do
	{
		clrscr();
		cout<<"\nADMINSTRATOR PROFILE MENU\n\n";
		cout<<"1. Display Entrance Examination Details\n";
		cout<<"2. Display All Users Profiles\n";
		cout<<"3. Modify User Profiles (search by user ID)\n";
		cout<<"4. Delete User Profiles (search by user ID)\n";
		cout<<"5. Insert Entrance Exam Details (sorting by date)\n";
		cout<<"6. Modify Entrance Exam Details (search by exam name)\n";
		cout<<"7. Delete Entrance Exam Details (search by exam name)\n";
		cout<<"8. View Exam Schedule (search by exam name)\n";
		cout<<"9. Exit (Go Back to Main Program Page)\n\n";
		cout<<"Enter choice : ";
		cin>>choice;
		cout<<endl;

		switch(choice)
		{
			case 1:
			admin_edisplay();
			break;

			case 2:
			admin_udisplay();
			break;

			case 3:
			admin_umodify();
			break;

			case 4:
			admin_udelete();
			break;

			case 5:
			admin_einsert();
			break;

			case 6:
			admin_emodify();
			break;

			case 7:
			admin_edelete();
			break;

			case 8:
			admin_view_schedule();
			break;

			case 9:
			ans1='t';
			break;

			default:
			cout<<"\nEnter Valid Choice!!\n";
		}
		if (ans1!='t')
		{
			cout<<"\nDo you want to continue with Admin Menu? (y/n)\n";
			cin>>ans1;
		}
	}
	while(ans1=='y');
	getch();
	textbackground(RED);
}

void admin_edisplay()
{
	clrscr();
	fin.open("exam.dat",ios::binary);
	while(fin.read((char *)&e1,sizeof(e1)))
	{
		if(fin.eof())
		break;
		e1.display_exam();
		cout<<endl; getch();
	}
	fin.close();
}

void admin_udisplay()
{
	clrscr();
	fin.open("user.dat",ios::in|ios::binary);
	while(fin.read((char *)&u1,sizeof(u1)))
	{
		if(fin.eof())
		break;
		u1.display_user();
		cout<<endl; getch();
	}
	fin.close();
}

void admin_umodify()
{
	clrscr();
	char flag='n';
	fio.open("user.dat",ios::binary|ios::in|ios::out);
	char um_name[20]; int pos;
	cout<<"Enter User ID whose Profile is to modified\n";
	gets(um_name);
	while(!fio.eof())
	{
		pos=fio.tellg();
		fio.read((char *)&u1,sizeof(u1));
		if(strcmpi(um_name,u1.ret_userid())==0)
		{
			flag='f';
			fio.seekg(pos,ios::beg);
			u1.modify();
			fio.write((char *)&u1,sizeof(u1));
			break;
		}
	}
	if(flag=='n')
	cout<<"User Profile Not Found";
	fio.close();

}

void admin_udelete()
{
	clrscr();
	char ans;
	fin.open("user.dat",ios::binary);
	fout.open("temp.dat",ios::binary);
	char um_name[20];char flag='n';
	cout<<"Enter User ID whose Profile is to deleted\n";
	gets(um_name);
	while(fin.read((char *)&u1,sizeof(u1)))
	{
		if(strcmpi(um_name,u1.ret_userid())==0)
		{
			cout<<"\nAre you sure to delete this? (y/n)\n";
			cin>>ans;
			if(ans=='y')
			{
				flag='f';
				cout<<"User Details Deleted\n";
			}
			else
			{	fout.write((char *)&u1,sizeof(u1));
				flag='f';
			}
		}
		else
		fout.write((char *)&u1,sizeof(u1));
	}
	if(flag=='n')
	cout<<"User Profile Not Found";
	fin.close();
	fout.close();
	remove("user.dat");
	rename("temp.dat","user.dat");
}

void admin_einsert()
{
	clrscr();
	fin.open("exam.dat",ios::binary);
	fout.open("temp.dat",ios::binary);
	char last='y';
	cout<<"Enter Details of Exam whose record has to be inserted\n";
	e1.enter_exam();
	while(fin.read((char *)&e2,sizeof(e2)))
	{

		if(compare_date(e2.ret_d(),e1.ret_d()))
		{
			fout.write((char *)&e1,sizeof(e1));
			fout.write((char *)&e2,sizeof(e2));
			last='n';
			break;
		}
		else
			fout.write((char *)&e2,sizeof(e2));
	}
	if(last=='y')
	fout.write((char *)&e1,sizeof(e1));
	else if(!fin.eof())
	{
		while(fin.read((char *)&e1,sizeof(e1)))
		{

			fout.write((char *)&e1,sizeof(e1));
		}
	}
	fin.close();
	fout.close();
	remove("exam.dat");
	rename("temp.dat","exam.dat");
}

void admin_emodify()
{
	clrscr();
	char flag='n';
	fio.open("exam.dat",ios::binary|ios::in|ios::out);
	char em_name[20]; int pos;
	cout<<"Enter Exam Name whose Details are to modified\n";
	gets(em_name);
	cout<<endl;
	while(!fio.eof())
	{
		pos=fio.tellg();
		fio.read((char *)&e1,sizeof(e1));
		if(strcmpi(em_name,e1.ret_name())==0)
		{
			flag='f';
			fio.seekg(pos,ios::beg);
			e1.modify();
			fio.write((char *)&e1,sizeof(e1));
			break;
		}
	}
	if(flag=='n')
	cout<<"Exam Details Not Found";
	fio.close();

}

void admin_edelete()
{
	clrscr();
	char ans;
	fin.open("exam.dat",ios::binary);
	fout.open("temp.dat",ios::binary);
	char em_name[20];char flag='n';
	cout<<"Enter Exam Name whose Details are to deleted\n";
	gets(em_name);
	while(fin.read((char *)&e1,sizeof(e1)))
	{
		if(strcmpi(em_name,e1.ret_name())==0)
		{
			cout<<"\nAre you sure to delete this? (y/n)\n";
			cin>>ans;
			if(ans=='y')
			{
				flag='f';
				cout<<"Exam Details Deleted\n";
			}
			else
			{	fout.write((char *)&e1,sizeof(e1));
				flag='f';
			}
		}
		else
		fout.write((char *)&e1,sizeof(e1));
	}
	if(flag=='n')
	cout<<"Exam Name Not Found";
	fin.close();
	fout.close();
	remove("exam.dat");
	rename("temp.dat","exam.dat");
}

void admin_view_schedule()
{
	clrscr();
	char vs_user[20];char vs_exam[20];char flag='n';
	cout<<"Enter Exam Name whose Schedule you want to see :\n";
	gets(vs_exam);

	fin.open("schedule.dat",ios::binary);
	while(fin.read((char *)&s,sizeof(s)))
	{
		if(strcmpi(vs_exam,s.ret_ename())==0)
		{
			strcpy(vs_user,s.ret_uname());
			fin2.open("user.dat",ios::binary);
			while(fin2.read((char *)&u1,sizeof(u1)))
			{
				if(strcmpi(vs_user,u1.ret_name())==0)
				{
					cout<<endl;
					u1.display_user();
					flag='f';
				}
			}
			fin2.close();
		}
	}
	fin.close();
	if(flag=='n')
	cout<<"Nothing Availaible in your Schedule\n";

}

//***************************************************************************
//				USER FUNCTIONS
//***************************************************************************

void signup()
{
	char flag='y';
	fin.open("user.dat",ios::binary|ios::in);
	fout.open("user.dat",ios::binary|ios::app);
	do
	{

	cout<<endl;
	flag='y';
	u1.enter_user();
	u1.enter_password();

	while(fin.read((char *)&u2,sizeof(u2)))
	{

		if(strcmpi(u1.ret_userid(),u2.ret_userid())==0)
		{
			cout<<endl;
			cout<<"The user id already exists. Please renter ";
			flag='r';
		}


	}
	}
	while(flag=='r');

	fout.write((char *)&u1,sizeof(u1));
	cout<<"\nSIGN UP SUCESSFULL!! LOGIN NOW\n";
	getch();
	fin.close();
	fout.close();
}

void login()
{
	fin.open("user.dat",ios::binary|ios::in);
	fout.open("user.dat",ios::binary|ios::app);
	char userid101[10];
	char flag='n';char flag2='y';

	cout<<endl;
	cout<<"Enter USER ID : ";
	cin>>userid101;

	while(fin.read((char *)&user1,sizeof(user1)))
	{

		if(strcmpi(userid101,user1.ret_userid())==0)
		{
			flag='f';
			break;
		}
	}
	if(flag=='n')
	{
		cout<<"\nUser Profile Not Found !!";
		flag2='n';
		getch();
	}
	if(flag2=='y')
	{
		enter_password();

		if(strcmpi(pwd,user1.ret_password())==0)
		{
			cout<<"login sucessfull";
			fout.open("user2.dat",ios::binary|ios::out);
			fout.write((char *)&user1,sizeof(user1));
			fout.close();
			user_menu();
		}
		else
		{
			cout<<"\npassword entered is wrong";
			getch();
		}
	}
	fout.close();
	fin.close();
}

void user()
{
	int choice;
	textbackground(YELLOW);
	textcolor(BLACK);
	do
	{
	clrscr();
	cout<<"\nUSER PROFILE\n\n";
	cout<<"1. Sign Up and Create Profile\n";
	cout<<"2. Log into Existing Profile \n";
	cout<<"3. Exit (Go Back to Main Program Page)\n\n";
	cout<<"Enter choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1:
		signup();
		ans1='t';
		break;

		case 2:
		login();
		break;

		case 3:
		ans1='t';
		break;

		default:
		cout<<"\nEnter Valid Choice!!";

	}
	if(ans1!='t')
	{
		cout<<"\nDo you want to continue with User Login? (y/n)\n";
		cin>>ans1;
	}
	}
	while(ans1=='y');
	getch();
	textbackground(RED);
	textcolor(WHITE);
}

void user_menu()
{
	clrscr();
	textbackground(MAGENTA);
	textcolor(BLACK);
	int choice;
	do
	{
		clrscr();
		cout<<"\nUSER PROFILE MENU\n\n";
		cout<<"1. Display My Profile details\n";
		cout<<"2. Modify My Profile details\n";
		cout<<"3. Delete My Profile\n";
		cout<<"4. Apply for Entrance Exam\n";
		cout<<"5. Check for Eligible Entrance Exams\n";
		cout<<"6. Filter and Search for Exams\n";
		cout<<"7. View my Exam Schedule\n";
		cout<<"8. Exit (Go Back to Main Program Page)\n\n";
		cout<<"Enter choice : ";
		cin>>choice;
		cout<<endl;

		switch(choice)
		{
			case 1:
			display_profile();
			break;

			case 2:
			modify_profile();
			break;

			case 3:
			delete_profile();
			break;

			case 4:
			apply();
			break;

			case 5:
			eligible();
			break;

			case 6:
			filter();
			break;

			case 7:
			view_schedule();
			break;

			case 8:
			ans1='t';
			break;

			default:
			cout<<"\nEnter Valid Choice!!";
		}
		if(ans1!='t')
		{
			cout<<"\nDo you want to continue with User Menu? (y/n)\n";
			cin>>ans1;
		}
	}
	while(ans1=='y');
	getch();
	textbackground(RED);
	textcolor(WHITE);
}

void display_profile()
{
	clrscr();
	fin.open("user2.dat",ios::binary);
	fin.read((char *)&user1,sizeof(user1));
	user1.display_user();
	fin.close();
}

void modify_profile()
{
	clrscr();
	fout.open("user2.dat",ios::binary);
	fin.open("user2.dat",ios::binary);
	fin.read((char *)&user1,sizeof(user1));
	user1.modify();
	fout.write((char *)&user1,sizeof(user1));
	fout.close();
	fin.close();
	fio.open("user.dat",ios::binary);
	fin.open("user2.dat",ios::binary);
	fin.read((char *)&u1,sizeof(u1));

	while(fio.read((char *)&u2,sizeof(u2)))
	{
		if(strcmpi(u1.ret_userid(),u2.ret_userid())==0)
		{
			fio.seekg(-sizeof(u2),ios::cur);
			fio.write((char *)&u1,sizeof(u1));
		}
	}
	fio.close();
	fin.close();
}

void delete_profile()
{
	clrscr();
	char ans;
	fin.open("user2.dat",ios::binary);
	fin.read((char *)&user1,sizeof(user1));
	char um_name[20];
	strcpy(um_name,user1.ret_name());
	fin.close();
	fin.open("user.dat",ios::binary);
	fout.open("temp.dat",ios::binary);

	while(fin.read((char *)&u2,sizeof(u2)))
	{
		if(strcmpi(um_name,u2.ret_name())==0)
		{
			cout<<"\nUser Profile Deleted";
			ans1='t';
		}
		else
		fout.write((char *)&u2,sizeof(u2));
	}
	fin.close();
	fout.close();
	remove("user.dat");
	rename("temp.dat","user.dat");
}

void apply()
{
	clrscr();
	char a_user[20];char a_exam[20];
	fin.open("user2.dat",ios::binary);
	fin.read((char *)&user1,sizeof(user1));
	strcpy(a_user,user1.ret_name());
	fin.close();
	fin.open("exam.dat",ios::binary);
	while(fin.read((char *)&e1,sizeof(e1)))
	{
		if(fin.eof())
		break;
		e1.display_exam();
		getch();
	}
	fin.close();
	cout<<"\nWhich Exam do you want to apply for (exam name)?\n";
	cout<<"Type 'none' if you do not want to apply\n";
	gets(a_exam);
	if(strcmpi(a_exam,"none")!=0)
	{
		fout.open("schedule.dat",ios::binary|ios::app);
		s.assign(a_user,a_exam);
		fout.write((char *)&s,sizeof(s));
		fout.close();
	}

}

void eligible()
{
	clrscr();
	char flag='n';
	fio.open("user2.dat",ios::binary|ios::in);
	fio.read((char *)&user1,sizeof(user1));
	fin.open("exam.dat",ios::in|ios::binary);
	while(fin.read((char *)&e1,sizeof(e1)))
	{

	if( (user1.ret_age()>=e1.ret_min_age()) && (user1.ret_age()<=e1.ret_max_age())
		&& (user1.ret_percentage()>=e1.ret_percentage()) &&
		(user1.ret_stream()==e1.ret_stream()) )
	{
		flag='y';
		e1.display_exam();
		getch();
	}

	if(fin.eof())
	break;
	}
	if(flag=='n')
	cout<<"Sorry You are not eligible for any Exam!!\n";
	fin.close();
	fio.close();
}

//global declarations for filter()
char s_name[20]; int s_age; float s_percentage;
char s_stream; int s_fees; date s_d1;date s_d2;

void filter()
{
	clrscr();
	char flag='n';
	fio.open("user2.dat",ios::binary|ios::in);
	fio.read((char *)&user1,sizeof(user1));
	fin.open("exam.dat",ios::in|ios::binary);

	cout<<"ENTER SEARCH DETAILS\n";
	cout<<endl;
	cout<<"enter exam name (press '.' for no preference) :\n";
	gets(s_name);
	cout<<"enter age (press -1 for no preference) :\n";
	cout<<"[The age entered will be checked if it lies in exam age range]\n";
	cin>>s_age;
	cout<<"enter minimum percentage (press -1 for no preference) :\n";
	cout<<"[for eg. if you enter 70 and min percentage for exam is 80 it will show exam]\n";
	cin>>s_percentage;
	cout<<"enter stream (press '.' for no preference) :\n";
	cin>>s_stream;
	cout<<"enter maximum fees (press -1 for no preference) :\n";
	cout<<"[for eg. if you enter 900 and fees for exam is 800 it will show the exam]\n";
	cin>>s_fees;
	cout<<"enter start date (press '0-0-0' for no preference) :\n";
	cin>>s_d1.dd; cin>>s_d1.mm; cin>>s_d1.yy;
	cout<<"enter end date (press '0-0-0' for no preference) :\n";
	cin>>s_d2.dd; cin>>s_d2.mm; cin>>s_d2.yy;


	while(fin.read((char *)&e1,sizeof(e1)))
	{

	if( (search_exam(e1.ret_name())) && (search_age(e1.ret_min_age(),e1.ret_max_age())) &&
	(search_percentage(e1.ret_percentage())) && (search_stream(e1.ret_stream()))
	&& (search_fees(e1.ret_fees())) && (search_date(e1.ret_d())) )
	{
		flag='y';
		clrscr();
		e1.display_exam();
		getch();
	}

	if(fin.eof())
	break;
	}
	if(flag=='n')
		cout<<"Sorry No Exams match your Preferences!!\n";
	fin.close();
	fio.close();
}

void view_schedule()
{
	clrscr();
	char vs_user[20];char vs_exam[20];char flag='n';
	fin.open("user2.dat",ios::binary);
	fin.read((char *)&user1,sizeof(user1));
	strcpy(vs_user,user1.ret_name());
	fin.close();

	fin.open("schedule.dat",ios::binary);
	while(fin.read((char *)&s,sizeof(s)))
	{
		if(strcmpi(vs_user,s.ret_uname())==0)
		{
			strcpy(vs_exam,s.ret_ename());
			fin2.open("exam.dat",ios::binary);
			while(fin2.read((char *)&e1,sizeof(e1)))
			{
				if(strcmpi(vs_exam,e1.ret_name())==0)
				{
					e1.display_exam();
					getch();
					flag='f';
				}
			}
			fin2.close();
		}
	}
	fin.close();
	if(flag=='n')
	cout<<"Nothing Availaible in your Schedule\n";

}

//***************************************************************************
//				OTHER FUNCTIONS
//***************************************************************************

void enter_password()
{
	char ch;int k=0;
	cout<<"enter password: ";
	while(1)
	{
		ch=getch();
		if(ch==13)
		break;
		else
		{
			cout<<"*";
			pwd[k]=ch;
			k++;
		}
	}
	pwd[k]='\0';
}

char *enter_pwd()
{
	char ch;int k=0;char m_pwd[20];
	cout<<"enter new password (press '.' to retain old password): ";

		while(1)
		{
			ch=getch();
			if(ch==13)
			break;
			else
			{
				cout<<"*";
				m_pwd[k]=ch;
				k++;
			}
		}
		m_pwd[k]='\0';

	return m_pwd;
}


//supplementary functions for filter()

	int search_exam(char *name)
	{
		if(strcmpi(s_name,".")==0)
		return 1;
		else if(strcmpi(s_name,name)==0)
		return 1;
		else
		return 0;
	}
	int search_age(int age1,int age2)
	{
		if(s_age==-1)
		return 1;
		else if(s_age>=age1&&s_age<=age2)
		return 1;
		else
		return 0;
	}
	int search_percentage(float percentage)
	{
		if(s_percentage==-1)
		return 1;
		else if(s_percentage>=percentage)
		return 1;
		else
		return 0;
	}
	int search_stream(char stream)
	{
		if(s_stream=='.')
		return 1;
		else if(s_stream==stream)
		return 1;
		else
		return 0;
	}
	int search_fees(int fees)
	{
		if(s_fees==-1)
		return 1;
		else if(s_fees>=fees)
		return 1;
		else
		return 0;
	}
	int search_date(date d)
	{
		if(s_d1.dd==0)
			{	if(compare_date(s_d2,d)==1)
				return 1;
			}
		if(s_d2.dd==0)
			{       if(compare_date(d,s_d1)==1)
				return 1;
			}
		else if(compare_date(d,s_d1)&&compare_date(s_d2,d))
			return 1;

		return 0;
	}

int compare_date(date d1,date d2)
{
	if(d1.yy>d2.yy)
		return 1;
	else if(d1.yy<d2.yy)
		return 0;
	else if(d1.yy==d2.yy)
	{
		if(d1.mm>d2.mm)
		return 1;
		else if(d1.mm<d2.mm)
		return 0;
		else if(d1.mm==d2.mm)
		{
			if(d1.dd>d2.dd)
			return 1;
			else if(d1.dd<d2.dd)
			return 0;
			else if(d1.yy==d2.yy)
			return 1; //as per preference
		}
	}
	return 0;
}
//***************************************************************************
//				END OF PROGRAM CODE
//***************************************************************************