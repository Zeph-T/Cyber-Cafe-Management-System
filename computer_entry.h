#include<string.h>
using namespace std;

class computer_entry
{
	public:
	char *name,*model,*processor,*purchase_date;
	int ram;
	float *price;
	computer_entry()
	{
	  name=new char[20];
	  model=new char[20];
	  processor=new char[20];
	  purchase_date=new char[10];
	  price=new float;
	}
	void add();
	void show();
	void del();
	void update();
	int search(char n[20]);
	void display(computer_entry com[],int cn);	
};
void computer_entry::display(computer_entry com[],int cn)
{
	cout<<"Computer Name\t\tModel\t\tProcessor\t\tRam\t\tPrice\t\tPurchase date\n";
	for(int i=0;i<cn;i++)
	{
		if(com[i].name!=" ")
		{
		float *t=com[i].price;	
		cout<<"  "<<com[i].name<<"  \t\t "<<com[i].model<<"\t\t  "<<com[i].processor<<"  \t\t  "<<com[i].ram<<"  \t\t  ";
		cout<<*t<<"  \t\t"<<com[i].purchase_date<<endl;
		}
	}
}
void computer_entry::add()
{
  cout<<"Enter computer name: ";
  cin>>name;
  cout<<"Enter model: ";
  cin>>model;
  cout<<"Enter processor type: ";
  cin>>processor;
  cout<<"Ram: ";
  cin>>ram;
  cout<<"Price of computer: ";
  cin>>*price;
  cout<<"Purchase date of computer: ";
  cin>>purchase_date;
}
void computer_entry::show()
{
  cout<<"computer name: "<<name<<endl;
  cout<<"model: "<<model<<endl;
  cout<<"Enter processor type: "<<processor<<endl;
  cout<<"Ram: "<<ram<<endl;
  cout<<"Price of computer: "<<*price<<endl;
  cout<<"Purchase date of computer: "<<purchase_date<<endl;
}
void computer_entry::update()
{
  cout<<"Enter computer name: ";
  cin>>name;
  cout<<"Enter model: ";
  cin>>model;
  cout<<"Enter processor type: ";
  cin>>processor;
  cout<<"Ram: ";
  cin>>ram;
  cout<<"Price of computer: ";
  cin>>*price;
  cout<<"Purchase date of computer: ";
  cin>>purchase_date;
}
int computer_entry::search(char n[20])
{
	if(strcmp(n,name)==0)
	return 1;
	else
	return 0;	
}
void computer_entry::del()
{
	name=" ";
	model=" ";
    processor=" ";
	purchase_date=" ";
    price=NULL ;
	ram=NULL;			
}
