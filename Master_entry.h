#include<string.h>
using namespace std;
#ifndef Master_entry_H
#define Master_entry_H

int a=0,npass=0,checkpass=0;
class member_entry;
class master_entry
{
    public:
	master_entry()
	{
//	cout<<"Welcome, You are in constructor of Master_entry class.\n";
	}
	void display(member_entry mem[],int mn);
    ~master_entry()
    {
//  cout<<"You are in destructor of Master_entry class.\n";
	}
};
class member_entry:public master_entry
{
	public:
	string name;
	string password,email_id,plan_type;
	long long int phone_no;
    member_entry()
	{
	name="Admin";
	email_id="cybercafe@gmail.com";
	phone_no=9999999999;
	plan_type="Daily";
	password="cc@1";
	}
	void add();
    void show();
    void update();
    void del();
    void check_password();
    void change_password();
    void set_password();
    void display(member_entry mem[],int mn);
    int search(char n[20]);
};
void member_entry::add()
{
	cout<<"Enter Name: ";
	cin>>name;
	cout<<"Enter Email_id: ";
	cin>>email_id;
	cout<<"Enter Phone Number: ";
	cin>>phone_no;
	cout<<"current plan: ";
	cin>>plan_type;
	cout<<"Create password :";
    cin>>password;
}
void member_entry::show()
{
	cout<<"Name:"<<name<<endl;
	cout<<"Email_id: "<<email_id<<endl;
	cout<<"Phone Number: "<<phone_no<<endl;
	cout<<"current plan: "<<plan_type<<endl;	
}
void master_entry::display(member_entry mem[],int mn)
{
	cout<<"Name\t\tEmail_id\t\tPhone number\t\tCurrent plan\n";
	for(int i=0;i<mn;i++)
	{
		if(mem[i].name!=" ")
		{
			cout<<mem[i].name<<"\t\t"<<mem[i].email_id<<"\t    "<<mem[i].phone_no<<"\t\t"<<mem[i].plan_type<<endl;
		}
	}
}
void member_entry::update()
{ 
   check_password();
   if(checkpass==1)
   {
   checkpass=0;	
   int c;
   cout<<"Choose the option you want to update: \n";
   cout<<"1.Name\n2.Email Id\n3.Phone Number\n4.Current Plan\n5.Change Password\n";
   cin>>c;
    switch(c)
   {
    case 1:
	cout<<"Enter Name:";
	cin>>name;
	break;
	case 2:
	cout<<"Enter Email_id:";
	cin>>email_id;
	break;
	case 3:
	cout<<"Enter Phone Number:";
	cin>>phone_no;
	break; 
	case 4:
	cout<<"current plan:";
	cin>>plan_type;
    break;
    case 5:
    change_password();
	break;	
   }
   }
}
void member_entry::change_password()
{
	int o,b=0;
	string e,p;
	while(1)
	{
	 int c=0;	
	 cout<<"Do u want to change through: \n1)current password.\n2)Forgot password.\n3)Return\n ";
	 cin>>o; 
	 switch(o)
	 {
	  case 1:
	  while(1)
	  {	
	   cout<<"Enter current password: ";
	   cin>>p;
       if(p==password)
       { 
        set_password(); 
	   }
	   else
	   {	
	   cout<<"Please Enter correct password.\n "; 	
	   cout<<"Do u want to go back??(if yes press 1): ";
	   cin>>b;
	   if(b==1)
	   {
	    b=0;
	   	break;
	   }
	   continue;
	   }
	   break;
	  }
	  break;
	  case 2:
	  while(1)
	  {
	   int vc=0;
	   cout<<"Enter the Email id that u linked with the account: ";
	   cin>>e;
	   if(e==email_id)
	   {
	    while(1)
	    {	
	     cout<<"Enter the verification code recieved :(here enter '1111') ";
	     cin>>vc;	
	     if(vc==1111)
	     {
	      set_password();
	      break;
		 }
	     else
	     {
	   	    cout<< "Verification code didn't match.\n";
	   	    cout<<"Do u want to go back??(if yes press 1): ";
	        cin>>b;
	        if(b==1)
	        {
	   	    b=0;
	   	    break;
	        }
		    continue;
	      }
	     }  
	    }   
	   else
	   {
	   cout<<"Email id didn't match,enter correct email id.\n";
	   cout<<"Do u want to go back??(if yes press 1): ";
	   cin>>b;
	   if(b==1)
	   {
	    b=0;
	   	break;
	   }
	   continue;	
	   }
	  break;
	  }
	  break; 	
      case 3:
	  npass=1;
	  break;
     }
     if(npass==1)
     {
     npass=0;
	 break;	
	 }	
	} 
}
void member_entry::set_password()
{
	while(1)
    {
     string pass,c;	
     int d=0;
     cout<<"Enter new password: ";
     cin>>pass;
     cout<<"Confirm new password: ";
     cin>>c;
     if(password!=pass && pass==c)
     {
      password=pass;
	  cout<<"Password Changed Successfully.\n";
	  npass=1;
	  break;
	 }     
	 if(password==pass)
     cout<<"New password shouldn't be same as old password.\n";
	 else
	 cout<<"Both Passwords didn't match.\n";	
	 cout<<"Do u want to go back??(if Yes press 1): ";
	 cin>>d;
	 if(d==1)
	 {
	  d=0;
	  break;
	 }
    }
}
int member_entry::search(char n[20])
{
	if(n==name)
	return 1;
	else
	return 0;
}
void member_entry::check_password()
{
	int z=2;
	string p;
	while(1)
	{
	cout<<"Enter the password: ";
	cin>>p;
	if(p==password)
	{
	checkpass=1;	
    break;
    }
    else
    {
    cout<"Both passwords didn't match.\n";
	cout<<"If u Forgot password and wants to change it, press 1,  if u want to go back, press 0:";
	cin>>z;
	if(z==0)
	break;	
	else if(z==1)
	{
	change_password();
    z=2;
    }
	else
	continue;
	}
    }	
}
void member_entry::del()
{
    check_password();
	if(checkpass==1)
	{
	checkpass=0;	
	name=" ";
	email_id=" ";
    plan_type=" ";
    phone_no=NULL;
    password=" ";
    }
    else
    {
    cout<<"Deletion cancelled."<<endl;	
	}
}
#endif
