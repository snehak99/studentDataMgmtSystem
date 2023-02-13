#pragma once
#include<iostream>
#include<string.h>
using namespace std;
/////////////////////////////////////////////
class Student
{
	int roll_no;
	char F_Name[20];
	char L_Name[20];
	char Email[30];
	char Mob[11];
	char Course[20];
	public:
		//constructors
		Student();
		Student(int,char*,char*,char*,char*,char*);
		//Display
		void Display();
		//setters
		void SetRoll_no(int);
		void SetF_Name(char*);
		void SetL_Name(char*);
		void SetEmail(char*);
		void SetMob(char*);
		void SetCourse(char*);
		//getters
		int GetRoll_no();
		char* GetF_Name();
		char* GetL_Name();
		char* GetEmail();
		char* GetMob();
		char* GetCourse();
};
