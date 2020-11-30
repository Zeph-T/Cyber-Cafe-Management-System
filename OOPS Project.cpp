#include<bits/stdc++.h>
#include "Master_entry.h"
#include "computer_entry.h"
#include "cyber_cafe.h"
#include<string.h>
using namespace std;

int main()
{
 master_entry me;	
 member_entry mem[20];
 computer_entry com[20];
 cyber_cafe c;
 int p,o,a,i,j,k;
 int mn=2,cn=0,x=0;
 char m_n[20],c_n[20];//member name, computer name
 int m=1,m1=1,m2=1,cc=1,c1=1,c2=1;
 int password=2325;
 mem[1].name="Guest";
 mem[1].password="guest";
 cout<<"Enter the password: ";
 cin>>p;
 while(1)
 {
	if(p==password)
	{
	    break;
	}
	else
	{
	    cout<<"Invalid password!"<<endl;
		cout<<"please enter the correct password: ";
		cin>>p;
	}
 }
//----------------------------------------------------------------------------------------------------- 
 cout<<"Welcome to cyber cafe management"<<endl;
 while(1)
 {
  cout<<"1) Master Entry\n2) Cafe Management\n3) Exit\n";
  cout<<"Please select any one of above options:";
  cin>>o;
  switch(o)
  {
	case 1:
	{
	 while(m!=3)
	 {
	  cout<<"1)Member entry option.\n2)Computer entry option.\n3)Return.\n";
	  cin>>m;
	  switch(m)
      {
       case 1:
	   {
	    while(m1!=6)
		{	
	     cout<<"1)Add new member.\n2)Show member.\n3)Update record.\n4)Delete record.\n5)Search record.\n6)Return.\n";
	     cout<<"select any one of above options:";
	     cin>>m1;
	     switch(m1)
	     {
	 	    case 1:
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
	 	  	mn++;
		    }
		    x=0;
		    break;
			case 2:
		    me.display(mem,mn);	
			break;
		    case 3:
		  	cout<<"Enter the Name of Member:";
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
			break;
		    case 4:
		    cout<<"Enter the Name of Member:";
		  	cin>>m_n;
            for(i=2;i<mn;i++)
			{	
		       if(mem[i].search(m_n))
			   {
			   	cout<<"Member name found.\n ";
			   	x=1;
			   	mem[i].del();
			   	cout<<"Member successfully deleted.\n";
				break;
			   }	
			}
			if(x==0)
			cout<<"Member name not found!\n";
			x=0;
			break;	
			case 5:
		  	cout<<"Enter the name of member:";
		  	cin>>m_n;
		  	for(i=0;i<mn;i++)
		  	{
		  	    if(mem[i].search(m_n))
			   {
				cout<<"Member name found.\n";  	
			    mem[i].show();
			    x=1;
			    break;
			   }	
			}
			if(x==0)
			cout<<"Member name not found!\n";
			x=0;
			break;
		    case 6:break;
	     }
	    
		}
	   m1=0;	
	   break;   
	   }
      //--------------------------------------------------------------------------------------------------
	   case 2:
	   {
	   	string p;
		int cp=0,z=2;
		while(1)
	   	{
	   	 cout<<"Enter the Admin password to access computer details.\n";
		 cin>>p;
		 if(p==mem[0].password)
		 {
		  cp=1;
		  break;
		 }
		 else 
		 {
		  cout<<"Password Incorrect.\n";	
		  cout<<"If u forgot password press 1,if u want to go back press 0: ";
		  cin>>z;
		  if(z==0)
		  {
		  z=2;
		  break;	
		  }
		  else if(z==1)
		  {
		  z==2;
		  mem[0].change_password();	
		  }
		  continue;
		 }	
		}
		if(cp==1)
		{
	   	 while(m2!=6)
	   	 {
	      cout<<"1)Add new computer.\n2)Show computer.\n3)Update record.\n4)Delete record.\n5)Search record.\n6)Return.\n";
	      cout<<"select any one of above options:";
	      cin>>m2;
	      switch(m2)
	      {
 	 	    case 1:
 	 	    com[cn].add();
	 	  	cn++;
	 	  	break;	
		    case 2:
		    com[0].display(com,cn);
			break;	
		    case 3:
		    cout<<"Enter the Name of Computer:";
		  	cin>>c_n;
		  	for(i=0;i<cn;i++)
		  	{
		  		if(com[i].search(c_n))
			   {
			   	cout<<"Computer name found.\n ";
			   	x=1;
			   	com[i].update();
			   	break;
			   }	
			}
			if(x==0)
			cout<<"Computer name not found!\n";
			x=0;
			break;
		    case 4:
		    cout<<"Enter the Name of Computer:";
		  	cin>>c_n;
			for(i=0;i<cn;i++)
			{	
		       if(com[i].search(c_n))
			   {
			   	cout<<"Computer name found.\n ";
			   	x=1;
			   	com[i].del();
			   	cout<<"Computer details successfully deleted.\n";
			   	break;
			   }	
			}
			if(x==0)
			cout<<"Computer name not found!\n";
			x=0;
			break;	
		    case 5:
		    cout<<"Enter the name of computer:";
		  	cin>>c_n;
		  	for(i=0;i<cn;i++)
		  	{
		  	    if(com[i].search(c_n))
			   {
				cout<<"Computer name found.\n";  	
			    com[i].show();
			    x=1;
			    break;
			   }	
			}
			if(x==0)
			cout<<"Computer name not found!\n";
			x=0;
			break;
		    case 6:break;
	      }
		 }
	     m2=0;	 	  
	     }
	     break;
        }
	   case 3:break;
      }
     }
    m=0;
	break; 
	}
//------------------------------------------------------------------------------------------------------- 	
	case 2:
	{
	 while(cc!=4)
	 {
	  cout<<"1)Booking.\n2)Charges.\n3)Renewal(or Taking subscription).\n4)Return.\n";
	  cout<<"select any one of above options:";
	  cin>>cc;
	  switch(cc)
	  {
		case 1:
		{
		 while(c1!=3)
		 {
          cout<<"1)Login.\n2)Log-out.\n3)Return.\n";
	      cout<<"select any one of above options:";
		  cin>>c1;
		  switch(c1)
		  {
			case 1:
			c.booking(mem,mn);	
			break;
            case 2:
			cout<<"Logged-out successfully!"<<endl;
			cout<<" Visit Again!!!"<<endl;
			break;	
			case 3:break; 
		  }
	     } 
		c1=0;
		break;
	    }
		case 2 :
		c.show_charges();
		break; 
		case 3:
		c.renew(mem,mn);
		if(c.added==1)
		{
		c.added=0;
		mn++;	
		}
		break;
		case 4:break;
	  }
     } 
    cc=0; 
	break;  
	}
//------------------------------------------------------------------------------------------------------	
	case 3:exit(0);  
 }
}
 return 0;
}
