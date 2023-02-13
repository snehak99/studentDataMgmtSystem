#include"User.h"
#include<fstream>
/////////////////////////////////////////////
class UserMgmt
{
	char emailaddress[35];
	char password[15];
	public:
		UserMgmt();
		void Setemailaddress(char*);
		void Setpassword(char*);
		char* Getemailaddress();
		char* Getpassword();
		//functions
		void FillForm(User &);
		void SearchForm(char*);
		void UpdateForm(char*);
		void DeleteForm(char*);
};
