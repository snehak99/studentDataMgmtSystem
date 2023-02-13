#include"Student.h"
#include<fstream>
/////////////////////////////////////////
class TeacherMgmt
{
	char Name[20];
	char Pwd[20];
	public:
		TeacherMgmt();
		void SetName(char*);
		void SetPwd(char*);
		char* GetName();
		char* GetPwd();
		
		void AddStudent(Student &);
		void DisplayAllStud();
		void SearchByRollNo(int);
		void UpdateByRollNo(int);
		void DeleteByRollNo(int);
		void SeeForms();
};
