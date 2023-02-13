#include<iostream>
#include<string.h>
using namespace std;
/////////////////////////////////////////////
class User
{
	char First_Name[20];
	char Last_Name[20];
	char Email_Add[30];
	char Mobile[11];
	char Courses[20];
	public:
		//constructors
		User();
		User(char*,char*,char*,char*,char*);
		//Display
		void Display();
		//setters
		void SetFirst_Name(char*);
		void SetLast_Name(char*);
		void SetEmail_Add(char*);
		void SetMobile(char*);
		void SetCourses(char*);
		//getters
		char* GetFirst_Name();
		char* GetLast_Name();
		char* GetEmail_Add();
		char* GetMobile();
		char* GetCourses();
		
};
