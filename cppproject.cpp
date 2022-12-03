#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();
int main()
{
	int c;
	cout<<"\t\t\t______________________________________________________________________________\n\n\n";
	cout<<"\t\t\t                                Welcome to Page                                \n\n\n";
	cout<<"\t\t\t____________________                   Menu      ________________________________\n\n";
	cout<<"                                                                                         \n\n";
	cout<<"\t | Press 1 to Login                       |"<<endl;
	cout<<"\t | Press 2  to Register                   |"<<endl;
	cout<<"\t | Press 3 if you forgot passwd           |"<<endl;
	cout<<"\t | Press 4 to Exit                        |"<<endl;
	cout<<"\n\t\t\tEnter Your Choice :";
	cin>>c;
	switch(c)
	{
		case 1:
			login();
			break;
		case 2:
			registration();
			break;
		case 3:
			forgot();
			break;
		case 4:
			cout<<"\t\t\t Thank You   \n\n";
		default:
			system("cls");
			cout<<"Selct From the given options Please \n";
			main();
		
	}
	
}
void login()
{
	int count;
	string userid,password,id,pass;
	system("cls");
	cout<<"\t\t\tEnter username and password:"<<endl;
	cout<<"\t\t\tUSER NAME:";
	cin>>userid;
	cout<<"\t\t\tPASSWORD:";
	cin>>password;
	
	ifstream input("records.txt");
	
	while(input>>id>>pass)
	{
		if(id==userid&&pass==password)
		{
			count=1;
			system("cls");
		}
	}
	input.close();
	if(count==1)
	{
		cout<<"\nYour Login is Successfull\nTHanks for Logging in";
		main();
	}
	else
	{
		cout<<"\nLogin Error\nPlease check username and password";
		main();
	}
}
void registration()
{
  string ruserId, rpassword, rid, rpass;
  system("cls");
  cout<<"\t\t\t Enter the username : ";
  cin>>ruserId;
  cout<<"\t\t\t Enter the password: ";
  cin>>rpassword;
  ofstream f1("records.txt", ios::app);
  f1<<ruserId<<' '<<rpassword<<endl;
  system("cls");
  cout<<"\n\t\t\t Registration is successfull! \n";
  main();
}
void forgot()
{
  int option;
  system("cls");
  cout<<"\t\tYou forgot the password? No worries \n";
  cout<< "Press 1 to search your id by username "<<endl;
  cout<< "Press 2 to go back to the main menu "<<endl;
  cout<<"\t\tEnter your choice :";
  cin>>option;
 switch(option)
 {
    case 1:
    	{
        int count=0;
        string suserId, sId, spass;
        cout<<"\n\t\tEnter the username which you remembered:";
        cin>>suserId;
        ifstream f2("records.txt");
        while(f2>>sId>>spass)
        {
            if(sId==suserId)
             {
			 count=1;
		}
	}
	f2.close();
	if(count==1)
	{
		cout<<"\n\nYour Account is Found \n";
		cout<<"\n\nYour Password is:"<<spass;
		main();
	}
	else
	{
		cout<<"\n\t Sorry Account not found\n";
		main();
	}
	}
	case 2:
		{
			main();
		}
	default:
		cout<<"\t\t\tWrong Choice!Please try again";
		forgot();
}

}


 


