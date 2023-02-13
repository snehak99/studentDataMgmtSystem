#include"UserMgmt.h"
#include<conio.h>
////////////////////////////////////////////////////////////
UserMgmt::UserMgmt()
{
	strcpy(this->emailaddress,"\0");
	strcpy(this->password,"\0");	
}
////////////////////////////////////////////////////////////
void UserMgmt::Setemailaddress(char* e)
{
	strcpy(this->emailaddress,e);
}
////////////////////////////////////////////////////////////
void UserMgmt::Setpassword(char* p)
{
	strcpy(this->password,p);
}
////////////////////////////////////////////////////////////
char* UserMgmt::Getemailaddress()
{
	return this->emailaddress;
}
////////////////////////////////////////////////////////////
char* UserMgmt::Getpassword()
{
	return this->password;
}
///////////////////////////////////////////////////////////
void UserMgmt::FillForm(User &U1)
{
	ofstream file1("UserData.dat",ios_base::binary|ios_base::app);
	file1.write((char*)&U1,sizeof(U1));
	
	file1.close();
	cout<<"\n\n\n\t\t\t\t\t   Information Added Successfully...";
	getch();
}
////////////////////////////////////////////////////////////
void UserMgmt::SearchForm(char* em)
{
	ifstream file1("UserData.dat",ios_base::binary);
	if(!file1)
	{
		cout<<"\n\t\t\tFile dosent exist.";
		return;
	}
	else
	{
		bool Found = false;
		User U1;
		file1.read((char*)&U1,sizeof(U1));
		do
		{
			if(strcmp(U1.GetEmail_Add(),em) == 0)
			{
				Found = true;
				cout<<"\n\t\t\t\t\t\t   Record Found !!!\n";
				cout<<"\n--------------------------------------------------------------------------\n";
				U1.Display();
				cout<<"\n--------------------------------------------------------------------------\n";
				break;
			}
			file1.read((char*)&U1,sizeof(U1));
		}while(!file1.eof());
		file1.close();
		
		if(!Found)
		{
			cout<<"\n\t\t\t\t\tRecord Not Found !!!";	
		}
	}
}
////////////////////////////////////////////////////////////
void UserMgmt::UpdateForm(char* em)
{
	User U1;
	fstream file1;
	file1.open("UserData.dat",ios::in | ios::out | ios::binary);
	if(!file1)
	{
		cout<<"\n\t\t\tFile dosent exist.";
		return;
	}
	while(file1.read((char*)&U1,sizeof(U1)))
	{
		if(strcmp(U1.GetEmail_Add(),em) == 0)
		{
			cout<<"\n\t\t\t\t\t\t   Record Found !!!\n";
			
			cout<<"\n--------------------------------------------------------------------------\n";
			U1.Display();
			cout<<"\n--------------------------------------------------------------------------\n";
			char Ans;	
			cout<<"\n\t\tDo you want to change First Name? [Y/N] : ";
			cin>>Ans;
			
			if(Ans == 'Y' || Ans == 'y')
			{
				char Fname[20];
				cout<<"\n\t\t\tEnter New First Name : ";
				cin>>Fname;
				U1.SetFirst_Name(Fname);
			}
			////////////////////////////////////////////////////
			cout<<"\n\t\tDo you want to change Last Name? [Y/N] : ";
			cin>>Ans;
			
			if(Ans == 'Y' || Ans == 'y')
			{
				char Lname[20];
				cout<<"\n\t\t\tEnter New Last Name : ";
				cin>>Lname;
				U1.SetLast_Name(Lname);
			}
			////////////////////////////////////////////////////
			cout<<"\n\t\tDo you want to change Email Address? [Y/N] : ";
			cin>>Ans;
			
			if(Ans == 'Y' || Ans == 'y')
			{
				char Email[30];
				cout<<"\n\t\t\tEnter New Email Address : ";
				cin>>Email;
				U1.SetEmail_Add(Email);
			}
			////////////////////////////////////////////////////
			cout<<"\n\t\tDo you want to change Mobile Number? [Y/N] : ";
			cin>>Ans;
			
			if(Ans == 'Y' || Ans == 'y')
			{
				char Mob[11];
				cout<<"\n\t\t\tEnter New Mobile Number : ";
				cin>>Mob;
				U1.SetMobile(Mob);
			}
			////////////////////////////////////////////////////
			cout<<"\n\t\tDo you want to change Course Name? [Y/N] : ";
			cin>>Ans;
			
			if(Ans == 'Y' || Ans == 'y')
			{
				char Course[20];
				cout<<"\n\t\t\tEnter New Course : ";
				cin>>Course;
				U1.SetCourses(Course);
			}
			////////////////////////////////////////////////////
			int pos = sizeof(U1);
			file1.seekp(-pos,ios::cur);
			file1.write((char*)&U1,sizeof(U1));
		}
	}
	file1.close();
	cout<<"\n\n\n\t\t\t\t\t   Form Updated Successfully...";
	getch();
}
////////////////////////////////////////////////////////////
void UserMgmt::DeleteForm(char* em)
{
	fstream file1,file2;
	User U1;
	
	file2.open("UserTempData.dat",ios::out | ios::binary);
	file1.open("UserData.dat",ios::in | ios::binary);
	
	if(!file1)
	{
		cout<<"\n\t\t\tFile dosent exist.";
		return;
	}
	else
	{
		file1.read((char*)&U1,sizeof(U1));
		while(!file1.eof())
		{
			if(strcmp(U1.GetEmail_Add(),em) != 0)
			{
				file2.write((char*)&U1,sizeof(U1));
			}
			file1.read((char*)&U1,sizeof(U1));
		}
	}
	file2.close();
	file1.close();
	remove("UserData.dat");
	rename("UserTempData.dat","UserData.dat");
	
	cout<<"\n--------------------------------------------------------------------------\n";
	U1.Display();
	cout<<"\n--------------------------------------------------------------------------\n";
	
	cout<<"\n\n\t\t\tThis Form Is Getting Deleted...";	
	cout<<"\n\n\n\t\t\t\t\t   Form Deleted Successfully...";
	getch();
}
////////////////////////////////////////////////////////////
