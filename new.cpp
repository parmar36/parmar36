#include<iostream>
#include<windows.h>
#include"string.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include <map>
#include<stdlib.h>
using namespace std;
string usn;
int tm;



// this is testing update for github

//                                   this is function of admin  complete
int  update_details_by_admin()
 {
  FILE *fp, *ft;

    char another;
    int choice=0,exit=0;



struct student {

        char first_name[50], last_name[50];

        char course[100];

        int section;
        

    };



    struct student e;
    char xfirst_name[50], xlast_name[50];
    long int recsize;

    fp=fopen("users.txt","rb+");

    if (fp == NULL) {
        fp = fopen("users.txt","wb+");

        if (fp==NULL)
        {
             puts("Cannot open file");
             return 0;
        }
    }


 recsize = sizeof(e);

 while(exit==0) {
     system("cls");
     system("color 17"); 
     cout << "\n\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 STUDENT MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ";
     
	 cout <<"\n\n                                          ";
     cout << "\n\n";
     cout<<" \n\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ";
     cout << "\n \t\t\t\t\t\t\t  Press 1> To Add    Records";
     cout << "\n \t\t\t\t\t\t\t  Press 2> To View   Records";
     cout << "\n \t\t\t\t\t\t\t  Press 3> To Modify Records";     
     cout << "\n \t\t\t\t\t\t\t  Press 4> To Exit   Program";
     cout<<" \n\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ";
     cout << "\n\n";
     cout << "\t\t\t\t\t\t\t Select Your Choice ::";
    
     cin>>choice;
     if(choice==1)
     {
            system("color 71"); 
            fseek(fp,0,SEEK_END);
            another ='Y';
            while(another == 'Y' || another == 'y')
            {
                  system("cls");
                cout << "Enter the First Name : ";
                cin >> e.first_name;
                cout << "Enter the Last Name : ";
                cin >> e.last_name;
                cout << "Enter the Course    : ";
                cin >> e.course;
                cout << "Enter the Section   : ";
                cin >> e.section;
                
                fwrite(&e,recsize,1,fp);
                cout << "\n Add Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
        }
        
    else if(choice==2)
         {
		  system("color 71"); 
            system("cls");
           rewind(fp);
           cout << "\xB2\xB2 View the Records in the Database \xB2\xB2 ";
           cout << "\n";
           while (fread(&e,recsize,1,fp) == 1){
           cout << "\n";
           cout <<"\nName     :: " <<e.first_name <<" "<<e.last_name;
           //cout << "\n";
           cout <<"\nCourse   :: " <<e.course ;
           cout <<"\nSection  :: "<<e.section;
           }
           cout << "\n\n";
           system("pause");
    }

    else if (choice==3)
         {
	                system("color 71"); 
            system("cls");
          another = 'Y';
          while (another == 'Y'|| another == 'y')
          {
              cout << "\n Enter the last name of the student : ";
              cin >> xlast_name;

            rewind(fp);
            while (fread(&e,recsize,1,fp) == 1)
            {
                if (strcmp(e.last_name,xlast_name) == 0)
                {
                cout << "Enter new the Firt Name : ";
                cin >> e.first_name;
                cout << "Enter new the Last Name : ";
                cin >> e.last_name;
                cout << "Enter new the Course    : ";
                cin >> e.course;
                cout << "Enter new the Section   : ";
                cin >> e.section;
                fseek(fp, - recsize, SEEK_CUR);
                fwrite(&e,recsize,1,fp);
                break;
                }
                else
                cout<<"record not found";
            }
            cout << "\n Modify Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
        }else{
        	fclose(fp);
        	cout<<endl;
        	cout<<endl;
        	
        	exit=1;
        	
		}        
         
    
          }
     
 }


 



//                                                                                this login for admin  complete

void login_admin()
{
	system("color 71"); 
 string username = "admin";
    string password = "password";
    string user;
    string pass;
       cout << "ADMINISTRATOR ID: ";
    cin >> user;
    if (user == username){
        cout << "ADMINISTRATOR PASSWORD: ";
        cin >> pass;
        if (pass == password){
            cout << "Successful Login!" << endl;
            update_details_by_admin();
        }
        else {
            cout << "Incorrect Password!" << endl;
        }
    }
    else {
        cout << "Incorrect Username!" << endl;
    }
}









//                                                                                 teacher profile

void teacher_profile()
{
	
update_details_by_admin();
}




//               check valid id for teacher





void valid_teacher(string str)
{
    string dir,user;
    ifstream file;
    dir = str+".txt";
    file.open(dir.c_str());
    if(!file.is_open() && file.fail())
    {
        //file.close();
        return;
    }
    else
    {
        tm++;
        if(tm==3)
        {
            cout<<"\nThis username already exists\nPlease try Again.";
            //file.close();
            return;
        }
        cout<<"\nThis username already exists!\nCreate a username:";
        cin>>usn;
        //file.close();
        valid_teacher(usn);
    }
}





//                                            login page for teacher






void login_teacher()
{
	int choice,i,exit=0;
    string ans,psd,name,fname,bio,usern,pw,line,nusn;
    ofstream fileo;
    ifstream filei;
    cout<<"----------------------------------------------Welcome to our system!------------------------------------------------------\n";
    while(exit==0)
    {
    	system("color 71"); 
        cout<<"\nChoose one option:\n1. SignIn/LogIn(press 1 to select this)\n2. SignUp/Register(press 2 to select this)\n\npress any key and enter to exit\n";
        cin>>choice;
        if(choice==1)
        {
            cout<<"Enter your username:";
            cin>>usn;
            cout<<"\nEnter your password:";
            cin>>psd;
            fname=usn+".txt";
            filei.open(fname.c_str());
            if(!filei.is_open() && filei.fail())
            {
                cout<<"\nYou are not registered, please register before logging in.\n";
                filei.close();
                continue;
            }
            getline(filei,usern);
            getline(filei,line);
            getline(filei,pw);
            if(usn==usern && psd==pw)
            {
                cout<<"\nYou are successfully logged in:)\nYOUR PROFILE SAYS:\n";
                                                                    
                cout<<"User-name:"<<usern<<endl;
                cout<<"Name:"<<line<<endl;
                getline(filei,line);
                cout<<"Bio:"<<line<<endl;	
                filei.close();
                teacher_profile();   
            }
            else{
                cout<<"\nWrong username or password!\nPlease try Again.\n";
            }
            cout<<endl;
        }
        else if(choice==2)
        {
        	system("color 71"); 
            cout<<"\nEnter your name:";
            cin.ignore();
            getline(cin,name);
            cout<<"\nCreate a username:";
            cin>>usn;
            tm=0;
            valid_teacher(usn);
            if(tm>=3)
            {
                continue;
            }
            cout<<"\nCreate a password:";
            cin>>psd;
            fname=usn+".txt";
            cout<<fname;
            fileo.open(fname.c_str());
            fileo<<usn<<endl<<name<<endl<<psd<<endl;
            cout<<"\nYou are successfully registered:)";
            cout<<"\nAdd to your bio and press enter when you are done:";
            cin.ignore();
            getline(cin,bio);
            fileo<<bio<<endl;
            cout<<"\nYour bio is saved as: "<<bio;
          
            fileo.close();
        }
        else
        {
            exit=1;
        }
    }
    cout<<"\n----------------------------------------------Thank you for visiting:)----------------------------------------------------\n";
	
}









//                         check valid details of students




void valid_student(string str)
{
	system("color 71"); 
    string dir,user;
    ifstream file;
    dir = str+".txt";
    file.open(dir.c_str());
    if(!file.is_open() && file.fail())
    {
        //file.close();
        return;
    }
    else
    {
        tm++;
        if(tm==3)
        {
            cout<<"\nThis username already exists\nPlease try Again.";
            //file.close();
            return;
        }
        cout<<"\nThis username already exists!\nCreate a username:";
        cin>>usn;
        //file.close();
        valid_student(usn);
    }
}




//                                 login page for student

void login_student()
{
	system("color 71"); 
int choice,i,exit=0;
    string ans,psd,name,fname,bio,usern,pw,line,nusn;
    ofstream fileo;
    ifstream filei;
    cout<<"----------------------------------------------Welcome to our system!------------------------------------------------------\n";
    while(exit==0)
    {
        cout<<"\nChoose one option:\n1. SignIn/LogIn(press 1 to select this)\n2. SignUp/Register(press 2 to select this)\n\npress any key and enter to exit\n";
        cin>>choice;
        if(choice==1)
        {
            cout<<"Enter your username:";
            cin>>usn;
            cout<<"\nEnter your password:";
            cin>>psd;
            fname=usn+".txt";
            filei.open(fname.c_str());
            if(!filei.is_open() && filei.fail())
            {
                cout<<"\nYou are not registered, please register before logging in.\n";
                filei.close();
                continue;
            }
            getline(filei,usern);
            getline(filei,line);
            getline(filei,pw);
            if(usn==usern && psd==pw)
            {
                cout<<"\nYou are successfully logged in:)\nYOUR PROFILE SAYS:\n";
                cout<<"User-name:"<<usern<<endl;
                cout<<"Name:"<<line<<endl;
                getline(filei,line);
                cout<<"Bio:"<<line<<endl;	
                filei.close();
            }
            else{
                cout<<"\nWrong username or password!\nPlease try Again.\n";
            }
            cout<<endl;
        }
        else if(choice==2)
        {
            cout<<"\nEnter your name:";
            cin.ignore();
            getline(cin,name);
            cout<<"\nCreate a username:";
            cin>>usn;
            tm=0;
            valid_student(usn);
            if(tm>=3)
            {
                continue;
            }
            cout<<"\nCreate a password:";
            cin>>psd;
            fname=usn+".txt";
            //cout<<fname;
            fileo.open(fname.c_str());
            fileo<<usn<<endl<<name<<endl<<psd<<endl;
            cout<<"\nYou are successfully registered:)";
            cout<<"\nAdd to your bio and press enter when you are done:";
            cin.ignore();
            getline(cin,bio);
            fileo<<bio<<endl;
            cout<<"\nYour bio is saved as: "<<bio;
            fileo.close();
        }
        else
        {
            exit=1;
        }
    }
    cout<<"\n----------------------------------------------Thank you for visiting:)----------------------------------------------------\n";
	

}


//                             this function for adminstrator

void admin()
{
	login_admin();
	
}


//                             this function for teachers

void teacher()
{
   login_teacher();	

}




//                              this function for student

void student()
{
	login_student();
	
}





//                             this is frist page


void project()
{
	int ch;

	do
	{
		system("cls");
		system("color 34" );
		 cout<<"\n\n\n\n";
	Sleep(200);
    cout << "\t\t\t||=============================================================================================||"<<endl;
    	Sleep(200);
    cout << "\t\t\t||\t\t\t\t\t\t\t\t\t\t\t\t||"<<endl;
    	Sleep(100);
    cout << "\t\t\t||\t\t\t\t\t\t\t\t\t\t\t\t||"<<endl;
    	Sleep(300);
    cout << "\t\t\t||\t      %%%%   %%%%%%   %%  %%   %%%%%%    %%%%%%  %%  %%  %%%%%%                  \t||" << endl;
		Sleep(500);    
    cout << "\t\t\t||\t     %%        %%     %%  %%    %%  %%   %%      %%% %%    %%                    \t||" << endl;
    	Sleep(500);
    cout << "\t\t\t||\t      %%%%     %%     %%  %%    %%   %%  %%%%    %% %%%    %%                    \t||" << endl;
    	Sleep(500);
    cout << "\t\t\t||\t         %%    %%     %%  %%    %%  %%   %%      %%  %%    %%                    \t||" << endl;
    	Sleep(500);
    cout << "\t\t\t||\t      %%%%     %%      %%%%    %%%%%%    %%%%%%  %%  %%    %%                    \t||" << endl;
    	Sleep(500);
    cout << "\t\t\t||\t\t\t\t\t\t\t\t\t\t\t\t||"<<endl;
    Sleep(500);

    cout << "\t\t\t||\t%%   %%   %%%%   %%  %%   %%%%    %%%%   %%%%%%  %%   %%  %%%%%%  %%  %%  %%%%%%  \t||" << endl;
    Sleep(500);
    cout << "\t\t\t||\t%%% %%%  %%  %%  %%% %%  %%  %%  %%      %%      %%% %%%  %%      %%% %%    %%    \t||" << endl;
    Sleep(500);
    cout << "\t\t\t||\t%% % %%  %%%%%%  %% %%%  %%%%%%  %% %%%  %%%%    %% % %%  %%%%    %%%%%%    %%    \t||" << endl;
    Sleep(500);
    cout << "\t\t\t||\t%%   %%  %%  %%  %%  %%  %%  %%  %%  %%  %%      %%   %%  %%      %%  %%    %%    \t||" << endl;
    Sleep(500);
    cout << "\t\t\t||\t%%   %%  %%  %%  %%  %%  %%  %%   %%%%   %%%%%%  %%   %%  %%%%%%  %%  %%    %%    \t||" << endl;
    Sleep(200);
    cout << "\t\t\t||\t\t\t\t\t\t\t\t\t\t\t\t||"<<endl;
    Sleep(500);

    cout << "\t\t\t||\t\t\t  %%%%   %%  %%   %%%%   %%%%%%  %%%%%%  %%   %%\t\t\t||" << endl;
    Sleep(200);
    cout << "\t\t\t||\t\t\t %%       %%%%   %%        %%    %%      %%% %%%\t\t\t||" << endl;
    Sleep(500);
    cout << "\t\t\t||\t\t\t  %%%%     %%     %%%%     %%    %%%%    %% % %%\t\t\t||" << endl;
    Sleep(200);
    cout << "\t\t\t||\t\t\t     %%    %%        %%    %%    %%      %%   %%\t\t\t||" << endl;
    Sleep(500);
    cout << "\t\t\t||\t\t\t  %%%%     %%     %%%%     %%    %%%%%%  %%   %%\t\t\t||" << endl;
    Sleep(200);
    cout << "\t\t\t||\t\t\t\t\t\t\t\t\t\t\t\t||"<<endl;
    Sleep(500);
    cout << "\t\t\t||\t\t\t\t\t\t\t\t\t\t\t\t||"<<endl;
    Sleep(2000);
    cout << "\t\t\t||=============================================================================================||"<<endl;
    
	cout << "\n\n\n\n";
	
		cout<<"\t\t\t*********************************************************************************************\n";
		cout<<"\t\t\t\t\t\t\t0. Exit from Program\n";
		cout<<"\t\t\t\t\t\t\tif you are admin then press : 1 \n";
		cout<<"\t\t\t\t\t\t\tif you are teacher then press : 2 \n";
		cout<<"\t\t\t\t\t\t\tif you are student then press : 3 \n";
		cout<<"\t\t\t\t\t\t\tEnter your choice  : ";
		cin>>ch;
		system("cls");
		switch(ch)
		{
			case 1: admin(); break;
			case 2: teacher(); break;
			case 3: student(); break;   
		}
		system("pause");
	}while(ch);
}

//                                    this is main function 

int main()
{
	project();
	
}
