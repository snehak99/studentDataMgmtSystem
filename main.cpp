#include"TeacherMgmt.h"
#include"UserMgmt.h"
#include<conio.h>
//////////////////////////////////////////////////////////////////////
int choice=0;
//////////////////////////////////////////////////////////////////////
void welcomescreen()
{
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\t\t\t-----------------------------| WELCOME |-----------------------------";
	
	cout<<"\n\n\n\n\t\t\t\t\t    KAVERI JUNIOR COLLEGE, PUNE.";
	
	cout<<"\n\n\t\t\t   Permanently Affiliated to Savitribai Phule Pune University,";
	cout<<"\n\t\t\t     Pune | Recognized Under 3(f) and 12 B of UGC Act, 1956.";
	cout<<"\n\t\t\t\t\t  Minority Status (Linguistic).";
	
	cout<<"\n\n\n\n\n\n\t\t\t\t\t   Press Any Key To Continue...";
	getch();
}
//////////////////////////////////////////////////////////////////////
void LoginScreen()
{
	system("cls");
	cout<<"\n\n\n\n\n\n\t\t\t\t\t\t    You Are...";
	cout<<"\n\n\n\n\t\t\t\t\t  1.Teacher\t\t2.Student";
	cout<<"\n\n\n\t\t\t\t\t  Enter Your Choice [1/2] : ";
	cin>>choice;
}
/////////////////////////////////////////////////////////////////////
void TeacherTitle()
{
	system("cls");
	cout<<"\n\n\t\t\t\t-----------------------------------------------------";
	cout<<"\n\t\t\t\t\t\t   Teacher Section ";
	cout<<"\n\t\t\t\t-----------------------------------------------------";
}
//////////////////////////////////////////////////////////////////////
void StudentTitle()
{
	system("cls");
	cout<<"\n\n\t\t\t\t-----------------------------------------------------";
	cout<<"\n\t\t\t\t\t\t   Student Section ";
	cout<<"\n\t\t\t\t-----------------------------------------------------";
}
//////////////////////////////////////////////////////////////////////
void Page1()
{
	system("cls");
	
	cout<<"\n\n\n\n\t\t\t\t\t\t   * Our VISION * ";
	cout<<"\n\t\t\t\t-----------------------------------------------------";
	cout<<"\n\n\t\t\t     To be a joyful learning community nurturing creativity for";
	cout<<"\n\t\t\t\t\t\ta sustainable future.";
	
	cout<<"\n\n\n\n\n\t\t\t\t\t\t   * Our MISSION * ";
	cout<<"\n\t\t\t\t-----------------------------------------------------";
	cout<<"\n\n\t\t\t     To mentor innovative thinkers through a learner-centric";
	cout<<"\n\t\t\t   educational platforn using experiential pedagogy. to instill";
	cout<<"\n\t\t\t  high ethical standards, accountability and proactive citizenship";
	cout<<"\n\t\t\t    guided by a visionary leadership in our students and staff.";
	
	
	cout<<"\n\n\n\n\t\t\t\t\t\t\t*****";
	
	cout<<"\n\n\n\t\t\t\t\t   Press Any Key To Continue...";
	getch();
}
/////////////////////////////////////////

int main()
{
	TeacherMgmt T1;
	UserMgmt UM1;
	welcomescreen();
	Page1();
	LoginScreen();
	B:
	C:
	if(choice == 1)
	{
		char nm[20];
		char ps[20];
		A:
		system("cls");
		TeacherTitle();
		
		cout<<"\n\n\n\n\n\n\n\t\t\t\t\t  Enter Username : ";
		cin>>nm;
		cout<<"\n\t\t\t\t\t  Enter Password : ";
		cin>>ps;
		
		if(strcmp(nm,T1.GetName()) == 0 && strcmp(ps,T1.GetPwd()) == 0)
		{
			cout<<"\n\t\t\t\t\t\tLogin Successfull...";
			cout<<"\n\n\n\n\n\n\t\t\t\t\t   Press Any Key To Continue...";
			getch();
		}
		else
		{
			cout<<"\n\t\t\t\tIncorrect Username & Password... Try Again..";
			getch();
			goto A;
		}	
		
		while(choice != 8)
		{
			system("cls");
			cout<<"\n\n\n\n\n\n\t\t\t\t\t\t1.Add Student.";
			cout<<"\n\t\t\t\t\t\t2.Display All Student.";
			cout<<"\n\t\t\t\t\t\t3.Search Student by Roll No.";
			cout<<"\n\t\t\t\t\t\t4.Update Student Info by Roll No.";
			cout<<"\n\t\t\t\t\t\t5.Delete Student Info.";
			cout<<"\n\t\t\t\t\t\t6.Display All Forms.";
			cout<<"\n\t\t\t\t\t\t7.Login Screen.";
			cout<<"\n\t\t\t\t\t\t8.Exit.";
			
			cout<<"\n\t\t\t\t\t\tEnter Your Choice [1-6] : ";
			cin>>choice;
			
			switch(choice)
			{
				case 1:
					{
						system("cls");
						TeacherTitle();
						int roll;
						char FName[20];
						char LName[20];
						char email[30];
						char Mobl[11];
						char Course[20];
						
						cout<<"\n\n\t\tEnter Roll No. : ";
						cin>>roll;
						cout<<"\n\t\tEnter First Name : ";
						cin>>FName;
						cout<<"\n\t\tEnter Last Name : ";
						cin>>LName;
						cout<<"\n\t\tEnter Email : ";
						cin>>email;
						cout<<"\n\t\tEnter Mobile No. : ";
						cin>>Mobl;
						cout<<"\n\t\tEnter Course Name. : ";
						cin>>Course;
						
						Student S1(roll,FName,LName,email,Mobl,Course);
						T1.AddStudent(S1);
					}
				break;
				
				case 2:
					{
						system("cls");
						TeacherTitle();
						cout<<"\n\n\n\t\t\t\t\t\tAll Student Information \n\n";
						T1.DisplayAllStud();
						getch();
					}
				break;
				
				case 3:
					{
						system("cls");
						TeacherTitle();
						int roll;
						cout<<"\n\n\n\t\t\t\t   Enter Roll Number To Be Searched. : ";
						cin>>roll;
						T1.SearchByRollNo(roll);
						getch();
					}
				break;
				
				case 4:
					{
						system("cls");
						TeacherTitle();
						int roll;
						cout<<"\n\n\n\t\t\t\t   Enter Roll Number To Be Updated. : ";
						cin>>roll;
						T1.UpdateByRollNo(roll);
						getch();
					}
				break;
				
				case 5:
					{
						system("cls");
						TeacherTitle();
						int roll;
						cout<<"\n\n\n\t\t\t\t   Enter Roll Number To Be Deleted. : ";
						cin>>roll;
						T1.DeleteByRollNo(roll);
						getch();
					}
				break;
				
				case 6:
					{
						system("cls");
						TeacherTitle();
						cout<<"\n\n\n\t\t\t\t\t\tAll Students Forms. \n\n";
						T1.SeeForms();
						getch();
					}
				
				case 7:
					{
						LoginScreen();
						goto C;
					}
				break;
				
				case 8:
				break;
				
				default:
					{
						cout<<"\n\n\n\t\t\t\t\t\t\tInvalid Input...";
						getch();
					}
				break;
			}
		}
	}
	if(choice == 2)
	{
		system("cls");
		StudentTitle();
		char nm[35];
		char ps[15];
		
		cout<<"\n\n\n\n\n\n\n\t\t\t\t\t  Enter Email Address : ";
		cin>>nm;
		cout<<"\n\t\t\t\t\t  Enter Password : ";
		cin>>ps;
		
		while(choice != 6)
		{
			system("cls");
			cout<<"\n\n\n\n\n\n\t\t\t\t\t\t1.Fill Form.";
			cout<<"\n\t\t\t\t\t\t2.Display Form,";
			cout<<"\n\t\t\t\t\t\t3.Update Form.";
			cout<<"\n\t\t\t\t\t\t4.Delete Form.";
			cout<<"\n\t\t\t\t\t\t5.Login Screen.";
			cout<<"\n\t\t\t\t\t\t6.Exit";
			
			cout<<"\n\t\t\t\t\t\tEnter Your Choice [1-5] : ";
			cin>>choice;
			
			switch(choice)
			{
				case 1:
					{
						system("cls");
						char FName[20];
						char LName[20];
						char email[30];
						char Mobl[11];
						char Course[20];
						
						cout<<"\n\t\tEnter First Name : ";
						cin>>FName;
						cout<<"\n\t\tEnter Last Name : ";
						cin>>LName;
						cout<<"\n\t\tEnter Email : ";
						cin>>email;
						cout<<"\n\t\tEnter Mobile No. : ";
						cin>>Mobl;
						cout<<"\n\t\tEnter Course Name. : ";
						cin>>Course;
						
						User U(FName,LName,email,Mobl,Course);
						UM1.FillForm(U);
					}
				break;
				
				case 2:
					{
						system("cls");
						TeacherTitle();
						char email[35];
						cout<<"\n\n\n\t\t\t\t   Enter Email Address To See Form. : ";
						cin>>email;
						UM1.SearchForm(email);
						getch();
					}
				break;
				
				case 3:
					{
						system("cls");
						TeacherTitle();
						char email[35];
						cout<<"\n\n\n\t\t\t\t   Enter Email Address To Update Form. : ";
						cin>>email;
						UM1.UpdateForm(email);
						getch();
					}
				break;
				
				case 4:
					{
						system("cls");
						TeacherTitle();
						char email[35];
						cout<<"\n\n\n\t\t\t\t   Enter Email Address To Delete Form. : ";
						cin>>email;
						UM1.DeleteForm(email);
						getch();
					}
				break;
				
				case 5:
					{
						LoginScreen();
						goto B;
					}
				break;
				
				case 6:
				break;
				
				default:
					{
						cout<<"\n\n\n\t\t\t\t\t\t\tInvalid Input...";
						getch();
					}
				break;
			}
		}
	}
	return 0;
}
