#include"TeacherMgmt.h"
#include"User.h"
#include<conio.h>
///////////////////////////////////////////
TeacherMgmt::TeacherMgmt()
{
	strcpy(this->Name,"Snehask");
	strcpy(this->Pwd,"100399");	
}
///////////////////////////////////////////
void TeacherMgmt::SetName(char* nm)
{
	strcpy(this->Name,nm);
}
///////////////////////////////////////////
void TeacherMgmt::SetPwd(char* ps)
{
	strcpy(this->Pwd,ps);
}
///////////////////////////////////////////
char* TeacherMgmt::GetName()
{
	return this->Name;
}
///////////////////////////////////////////
char* TeacherMgmt::GetPwd()
{
	return this->Pwd;
}
//////////////////////////////////////////
void TeacherMgmt::AddStudent(Student &S1)
{
	ofstream file1("StudentData.dat",ios_base::binary|ios_base::app);
	file1.write((char*)&S1,sizeof(S1));
	
	file1.close();
	cout<<"\n\n\n\t\t\t\t\t   Information Added Successfully...";
	getch();	
}
///////////////////////////////////////////
void TeacherMgmt::DisplayAllStud()
{
	ifstream file1("StudentData.dat",ios_base::binary);
	if(!file1)
	{
		cout<<"\n\t\t\tFile dosent exist.";
		return;
	}
	else
	{
		Student S1;
		file1.read((char*)&S1,sizeof(S1));
		do
		{
			cout<<"\n--------------------------------------------------------------------------\n";
			S1.Display();
			cout<<"\n--------------------------------------------------------------------------\n";
			file1.read((char*)&S1,sizeof(S1));
		}while(!file1.eof());
		
		file1.close();
	}
}
///////////////////////////////////////////
void TeacherMgmt::SearchByRollNo(int Rn)
{
	ifstream file1("StudentData.dat",ios_base::binary);
	if(!file1)
	{
		cout<<"\n\t\t\tFile dosent exist.";
		return;
	}
	else
	{
		bool Found = false;
		Student S;
		file1.read((char*)&S,sizeof(S));
		do
		{
			if(S.GetRoll_no() == Rn)
			{
				Found = true;
				cout<<"\n\t\t\t\t\t\t   Record Found !!!\n";
				cout<<"\n--------------------------------------------------------------------------\n";
				S.Display();
				cout<<"\n--------------------------------------------------------------------------\n";
				break;
			}
			file1.read((char*)&S,sizeof(S));
		}while(!file1.eof());
		file1.close();
		
		if(!Found)
		{
			cout<<"\n\t\t\t\t\tRecord Not Found !!!";	
		}
	}
}
///////////////////////////////////////////
void TeacherMgmt::UpdateByRollNo(int Rn)
{
	bool found = false;
	Student S;
	fstream file1;
	file1.open("StudentData.dat",ios::in | ios::out | ios::binary);
	if(!file1)
	{
		cout<<"\n\t\t\tFile dosent exist.";
		return;
	}
	while(file1.read((char*)&S,sizeof(S)))
	{
		if(S.GetRoll_no() == Rn)
		{
			cout<<"\n\t\t\t\t\t\t   Record Found !!!\n";
			found=true;
			
			cout<<"\n--------------------------------------------------------------------------\n";
			S.Display();
			cout<<"\n--------------------------------------------------------------------------\n";
				
			char Ans;
			cout<<"\n\n\t\tDo you want to change Roll Number.? [Y/N] : ";
			cin>>Ans;
			
			if(Ans == 'Y' || Ans == 'y')
			{
				int Rn;
				cout<<"\n\t\t\tEnter New Roll Number : ";
				cin>>Rn;
				S.SetRoll_no(Rn);
			}
			/////////////////////////////////////////////////////
			cout<<"\n\t\tDo you want to change First Name? [Y/N] : ";
			cin>>Ans;
			
			if(Ans == 'Y' || Ans == 'y')
			{
				char Fname[20];
				cout<<"\n\t\t\tEnter New First Name : ";
				cin>>Fname;
				S.SetF_Name(Fname);
			}
			////////////////////////////////////////////////////
			cout<<"\n\t\tDo you want to change Last Name? [Y/N] : ";
			cin>>Ans;
			
			if(Ans == 'Y' || Ans == 'y')
			{
				char Lname[20];
				cout<<"\n\t\t\tEnter New Last Name : ";
				cin>>Lname;
				S.SetL_Name(Lname);
			}
			////////////////////////////////////////////////////
			cout<<"\n\t\tDo you want to change Email Address? [Y/N] : ";
			cin>>Ans;
			
			if(Ans == 'Y' || Ans == 'y')
			{
				char Email[30];
				cout<<"\n\t\t\tEnter New Email Address : ";
				cin>>Email;
				S.SetEmail(Email);
			}
			////////////////////////////////////////////////////
			cout<<"\n\t\tDo you want to change Mobile Number? [Y/N] : ";
			cin>>Ans;
			
			if(Ans == 'Y' || Ans == 'y')
			{
				char Mob[11];
				cout<<"\n\t\t\tEnter New Mobile Number : ";
				cin>>Mob;
				S.SetMob(Mob);
			}
			////////////////////////////////////////////////////
			cout<<"\n\t\tDo you want to change Course Name? [Y/N] : ";
			cin>>Ans;
			
			if(Ans == 'Y' || Ans == 'y')
			{
				char Course[20];
				cout<<"\n\t\t\tEnter New Course : ";
				cin>>Course;
				S.SetCourse(Course);
			}
			////////////////////////////////////////////////////
			int pos = sizeof(S);
			file1.seekp(-pos,ios::cur);
			file1.write((char*)&S,sizeof(S));
		}
		
		if(!found)
		{
			cout<<"\n\t\t\t\t\tRecord Not Found !!!";	
		}
	}
	file1.close();
	cout<<"\n\n\n\t\t\t\t\t   Information Updated Successfully...";
	getch();
}
///////////////////////////////////////////
void TeacherMgmt::DeleteByRollNo(int Rn)
{
	bool found=false;
	fstream file1,file2;
	Student S;
	
	file2.open("TempData.dat",ios::out | ios::binary);
	file1.open("StudentData.dat",ios::in | ios::binary);
	
	if(!file1)
	{
		cout<<"\n\t\t\tFile dosent exist.";
		return;
	}
	else
	{
		file1.read((char*)&S,sizeof(S));
		while(!file1.eof())
		{
			if(Rn != S.GetRoll_no())
			{
				file2.write((char*)&S,sizeof(S));
			}
			file1.read((char*)&S,sizeof(S)); 
		}
	
	}
	file2.close();
	file1.close();
	remove("StudentData.dat");
	rename("TempData.dat","StudentData.dat");
	
	cout<<"\n--------------------------------------------------------------------------\n";
	S.Display();
	cout<<"\n--------------------------------------------------------------------------\n";
	
	cout<<"\n\n\t\t\tThis Record Is Getting Deleted...";	
	cout<<"\n\n\n\t\t\t\t\t   Information Deleted Successfully...";
	getch();
}
////////////////////////////////////////////////////////
void TeacherMgmt::SeeForms()
{
	ifstream file1("UserData.dat",ios_base::binary);
	if(!file1)
	{
		cout<<"\n\t\t\tFile dosent exist.";
		return;
	}
	else
	{
		User U1;
		file1.read((char*)&U1,sizeof(U1));
		
		do
		{
			cout<<"\n--------------------------------------------------------------------------\n";
			U1.Display();
			cout<<"\n--------------------------------------------------------------------------\n";
			file1.read((char*)&U1,sizeof(U1));
		}while(!file1.eof());
		file1.close();
	}
}
///////////////////////////////////////////////////////
