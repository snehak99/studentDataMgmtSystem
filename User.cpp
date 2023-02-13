#include"User.h"
////////////////////////////////////////////////////////////
User::User()
{
	strcpy(this->First_Name,"\0");
	strcpy(this->Last_Name,"\0");
	strcpy(this->Email_Add,"\0");
	strcpy(this->Mobile,"\0");
	strcpy(this->Courses,"\0");
}
////////////////////////////////////////////////////////////
User::User(char*Fnm,char*Lnm,char*Eml,char*Mbl,char*Crs)
{
	strcpy(this->First_Name,Fnm);
	strcpy(this->Last_Name,Lnm);
	strcpy(this->Email_Add,Eml);
	strcpy(this->Mobile,Mbl);
	strcpy(this->Courses,Crs);
}
////////////////////////////////////////////////////////////
void User::Display()
{
	cout<<"\n\t\tFirst Name : "<<this->First_Name;
	cout<<"\n\t\tLast Name : "<<this->Last_Name;
	
	cout<<"\n\t\tMobile No. : "<<this->Mobile;
	cout<<"\n\t\tEmail : "<<this->Email_Add;
	
	cout<<"\n\t\tCourse : "<<this->Courses;
}
////////////////////////////////////////////////////////////
void User::SetFirst_Name(char* Fnm)
{
	strcpy(this->First_Name,Fnm);
}
////////////////////////////////////////////////////////////
void User::SetLast_Name(char* Lnm)
{
	strcpy(this->Last_Name,Lnm);
}
////////////////////////////////////////////////////////////
void User::SetEmail_Add(char* Eml)
{
	strcpy(this->Email_Add,Eml);
}
////////////////////////////////////////////////////////////
void User::SetMobile(char* Mbl)
{
	strcpy(this->Mobile,Mbl);
}
////////////////////////////////////////////////////////////
void User::SetCourses(char* Crs)
{
	strcpy(this->Courses,Crs);
}
////////////////////////////////////////////////////////////
char* User::GetFirst_Name()
{
	return this->First_Name;
}
////////////////////////////////////////////////////////////
char* User::GetLast_Name()
{
	return this->Last_Name;
}
////////////////////////////////////////////////////////////
char* User::GetEmail_Add()
{
	return this->Email_Add;
}
////////////////////////////////////////////////////////////
char* User::GetMobile()
{
	return this->Mobile;
}
////////////////////////////////////////////////////////////
char* User::GetCourses()
{
	return this->Courses;
}
////////////////////////////////////////////////////////////
