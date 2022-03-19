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
			cout<<"이름: "<<name<<endl;
			cout<<"계좌ID: "<<account<<endl;
			cout<<"잔액: "<<money<<endl;
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
		cout<<"1.계좌개설"<<endl;
		cout<<"2.입    금"<<endl;
		cout<<"3.출    금"<<endl;
		cout<<"4.계좌정보 전체 출력"<<endl;
		cout<<"5.프로그램 종료"<<endl;
		cout<<"선택: "; 
}
void MakeAccount()
{
	int account; int money;
	char name[100];
	cout<<"[계좌개설]"<<endl;
	cout<<"계좌ID: "; cin>>account;
	cout<<"이름: "; cin>>name;
	cout<<"입금액: "; cin>>money;

	arr[index++]=new customer(account,money,name);
}
void Deposit()
{
	int account; int money;
	cout<<"[입금]"<<endl;
	cout<<"계좌ID: "; cin>>account;
	cout<<"입금액: "; cin>>money;

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
	cout<<"[출금]"<<endl;
	cout<<"계좌ID: "; cin>>account;
	cout<<"입금액: "; cin>>money;

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