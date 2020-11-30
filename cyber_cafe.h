#include<string.h>
//#include "Master_entry.h"
using namespace std;

class cyber_cafe
{
	public:
    char *name,*time;
	long long int phone_no;
	bool ifpremium,added=0;//new_member_added
	int age;
    void booking(member_entry* , int mn);
	void show_charges();
	void pay_charges();
	void renew(member_entry* , int mn);
	
};
void cyber_cafe::show_charges()
{
	cout<<"charges for an hour is 10 INR"<<endl;
	cout<<"Plans:\n";
	cout<<"1)Basic plan(BP)    - for 1 month  - 200  INR \n";
	cout<<"2)Standard plan(SP) - for 3 months - 500  INR \n";
	cout<<"3)Premium(P)        - for 1 year   - 1000 INR \n";
}
void cyber_cafe::booking(member_entry mem[], int mn)
{
	int i=0,x=0,ans;
	while(1)
	{
	cout<<"Are u a member of cyber cafe or Got username for using system one time(through payment):(press 1 if yes else 0) ";
	cin>>ifpremium;
	if(ifpremium)
	{
	 int c=0;	
	 while(c!=2)
	 {
	  int i,x=0;
      string n,p;	 	
	  cout<<"1.LOGIN\n2.Return"<<endl;
	  cin>>c;	
	  switch(c)
	  {
	   case 1:
	   cout<<"Enter your name(user_name): ";
	   cin>>n;
	   cout<<"Enter password: ";
	   cin>>p;
	   for(i=0;i<mn;i++)
	   {
	    if(n==mem[i].name && p==mem[i].password)
	    {
	     cout<<"Successfully logged-in"<<endl;
		 cout<<"Welcome to the cybercafe!!!"<<endl;
	     x=1;
	     break;
	    }
       }
       if(x==0)
       {
        cout<<"Please Enter correct Details:"<<endl;
	    continue;
	   }
	   break;
	   case 2:break;
	  }
	 c=0;
	 break;
	}
    }
	else
	{	
	 show_charges();
	  cout<<"Do u want to use computer?if yes press 1 (charges will apply).\n";
	  cin>>ans;	
	  if(ans==1)
	  {
	   cout<<"charges will be collected according to time of your usage.\n";
	   cout<<"use login credentials as username:Guest,Password:guest\n";
	   continue; 	
	  }
	 }
	break; 
    }
}
void cyber_cafe::renew(member_entry mem[], int mn)
{
	int sp,cp,pm,i=0,x=0;
	char m_n[20];
	show_charges();
	cout<<"Are u previously a member:(if yes press 1) ";
	cin>>pm;
	cout<<"Select a plan from 3 plans: ";
	cin>>sp;
	cout<<"Confirm payment??:(if yes press 1)";
	cin>>cp;
	if(cp==1 && pm==0)
	{
		cout<<"To activate the Plan,Create an account by enter the details asked.";
        for(i=0;i<mn;i++)
		{
		 if(mem[i].name==" ")
		 {
		  mem[i].add();
		  x=1;
		  break;
		 }	
		}	
		if(x==0)
		{
	 	 mem[mn].add();
	 	 added=1;
	 	 mn++;
		}
		x=0;
    }
    else if(cp==1 && pm==1)
    {
    cout<<"To activate the plan update the plan.\n ";	
    cout<<"Enter the Name :";
	cin>>m_n;
	for(i=0;i<mn;i++)
	{
	 if(mem[i].search(m_n))
	 {
	  cout<<"Member name found.\n ";
	  x=1;
	  mem[i].update();
	  break;
     }
	}
	if(x==0)
	cout<<"Member name not found!\n";
	x=0;
	}
}
