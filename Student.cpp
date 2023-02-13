#include"Student.h"
/////////////////////////////////////////////////
Student::Student()
{
	this->roll_no=0;
	strcpy(this->F_Name,"\0");
	strcpy(this->L_Name,"\0");
	strcpy(this->Email,"\0");
	strcpy(this->Mob,"\0");
	strcpy(this->Course,"\0");
}
/////////////////////////////////////////////////
Student::Student(int Rn, char*Fn, char*Ln, char*El, char*Mb, char* Crs)
{
	this->roll_no=Rn;
	strcpy(this->F_Name,Fn);
	strcpy(this->L_Name,Ln);
	strcpy(this->Email,El);
	strcpy(this->Mob,Mb);
	strcpy(this->Course,Crs);
}
/////////////////////////////////////////////////
void Student::Display()
{
	cout<<"\n\t\tRoll No : "<<this->roll_no;
	
	cout<<"\n\t\tFirst Name : "<<this->F_Name;
	cout<<"\n\t\tLast Name : "<<this->L_Name;
	
	cout<<"\n\t\tMobile No. : "<<this->Mob;
	cout<<"\n\t\tEmail : "<<this->Email;
	
	cout<<"\n\t\tCourse : "<<this->Course;
}
/////////////////////////////////////////////////
void Student::SetRoll_no(int Rn)
{
	this->roll_no=Rn;
}
/////////////////////////////////////////////////
void Student::SetF_Name(char* Fn)
{
	strcpy(this->F_Name,Fn);
}
/////////////////////////////////////////////////
void Student::SetL_Name(char* Ln)
{
	strcpy(this->L_Name,Ln);
}
/////////////////////////////////////////////////
void Student::SetEmail(char* El)
{
	strcpy(this->Email,El);
}
/////////////////////////////////////////////////
void Student::SetMob(char* Mb)
{
	strcpy(this->Mob,Mb);
}
/////////////////////////////////////////////////
void Student::SetCourse(char* Cs)
{
	strcpy(this->Course,Cs);
}
/////////////////////////////////////////////////
int Student::GetRoll_no()
{
	return this->roll_no;
}
/////////////////////////////////////////////////
char* Student::GetF_Name()
{
	return this->F_Name;
}
/////////////////////////////////////////////////
char* Student::GetL_Name()
{
	return this->L_Name;
}
/////////////////////////////////////////////////
char* Student::GetEmail()
{
	return this->Email;
}
/////////////////////////////////////////////////
char* Student::GetMob()
{
	return this->Mob;
}
/////////////////////////////////////////////////
char* Student::GetCourse()
{
	return this->Course;
}
////////////////////////////////////////////////
