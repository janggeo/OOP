#include<iostream>
#include<cstring>

using namespace std;
#define MAX 10
int index;

enum{MAKE=1,IN,OUT,PRINT,EXIT};

void ShowMenu();
void MakeAccount();
void Deposit();
void Withdraw();
void ShowAllInfo();

class customer
{
	private:
		char * name;
		int account;
		int money;
	public:
		customer(int account,int money,char *name)	:account(account), money(money)
		{
			this->name = new  char[strlen(name)+1];
			strcpy(this->name,name);
		}
		~customer()
		{
			delete []name;
			cout<<"called"<<endl;
		}
		void Drawin(int money)
		{
			this->money+=money;
		}
		void Drawout(int money)
		{
			this->money-=money;
		}
		void PrintCustomer()	const
		{
			cout<<"�̸�: "<<name<<endl;
			cout<<"����ID: "<<account<<endl;
			cout<<"�ܾ�: "<<money<<endl;
		}
		int search()  const
		{
			return account;
		}
};

customer* arr[MAX];


int main(void)
{
	int choice;
	while(1)
	{
		ShowMenu();
		cin>>choice;

		switch(choice)
		{
			case(MAKE):	
				MakeAccount();
				break;
			case(IN):
				Deposit();
				break;
			case(OUT):
				Withdraw();
				break;
			case(PRINT):
				ShowAllInfo();
				break;
			case(EXIT):
				return 0;
		}

	}
}

void ShowMenu()
{
	cout<<"-----MENU-----"<<endl;
		cout<<"1.���°���"<<endl;
		cout<<"2.��    ��"<<endl;
		cout<<"3.��    ��"<<endl;
		cout<<"4.�������� ��ü ���"<<endl;
		cout<<"5.���α׷� ����"<<endl;
		cout<<"����: "; 
}
void MakeAccount()
{
	int account; int money;
	char name[100];
	cout<<"[���°���]"<<endl;
	cout<<"����ID: "; cin>>account;
	cout<<"�̸�: "; cin>>name;
	cout<<"�Աݾ�: "; cin>>money;

	arr[index++]=new customer(account,money,name);
}
void Deposit()
{
	int account; int money;
	cout<<"[�Ա�]"<<endl;
	cout<<"����ID: "; cin>>account;
	cout<<"�Աݾ�: "; cin>>money;

	for(int i=0;i<index;i++)
	{
		if(arr[i]->search()==account)
		{
			arr[i]->Drawin(money);
		}
	}
	
}
void Withdraw()
{
	int account; int money;
	cout<<"[���]"<<endl;
	cout<<"����ID: "; cin>>account;
	cout<<"�Աݾ�: "; cin>>money;

	for(int i=0;i<index;i++)
	{
		if(arr[i]->search()==account)
		{
			arr[i]->Drawout(money);
		}
	}
}
void ShowAllInfo()
{
	for(int i=0;i<index;i++)
	{
		arr[i]->PrintCustomer();
	}
}