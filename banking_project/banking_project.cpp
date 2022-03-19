#include<iostream>
#include<cstring>
//���� ���� ����ü
typedef struct{
	int num;
	char name[20];
	int mon;
}ACCOUNT;
enum{MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
int index=0;			//����ü�迭�� �ε���
ACCOUNT arr[10];

using std::cin;
using std::cout;
using std::endl;

void make_account(void);	//���°���
void deposit(void);			//�Ա�
void withdraw(void);		//���
void print_account(void);	//�������� ��ü ���
int search(int mum);		//�Ա�,��� ��ġ ã��

int main(void){
	while(1){
	int choice;
	cout<<"\n";
	cout<<"-----Menu-----"<<endl;
	cout<<"1. ���°���"<<endl;
	cout<<"2.�Ա�"<<endl;
	cout<<"3.���"<<endl;
	cout<<"4.�������� ��ü ���"<<endl;
	cout<<"5.���α׷� ����"<<endl;
	cout<<"����:";
	cin>>choice;
		if(choice<5){
			switch(choice){
				case MAKE:
					make_account();
					break;
				case DEPOSIT:
					deposit();
					break;
				case WITHDRAW:
					withdraw();
					break;
				case INQUIRE:
					print_account();
					break;
				case EXIT:
					return 0;
			}
			cout<<"\n";
		}
	}

}

void make_account(void)
{
	ACCOUNT a;
	char name[20];
	cout<<"[���°���]"<<endl;
	cout<<"����ID:";
	cin>>a.num;
	cout<<"�̸�:";
	cin>>name;
	strcpy(a.name,name);
	cout<<"�Աݾ�:";
	cin>>a.mon;

	arr[index]=a;
	index+=1;
}	
void deposit(void){
	int num;
	int mon;
	cout<<"[��   ��]"<<endl;
	cout<<"����ID:";
	cin>>num;
	cout<<"�Աݾ�:";
	cin>>mon;

	int place=search(num);
	if(place>=0){
		arr[place].mon+=mon;
		cout<<"�ԱݿϷ�"<<endl;
	}
}
void withdraw(void){
	int num;
	int mon;
	cout<<"[��   ��]"<<endl;
	cout<<"����ID:";
	cin>>num;
	cout<<"��ݾ�:";
	cin>>mon;

	int place=search(num);
	if(place>=0){
		arr[place].mon-=mon;
		cout<<"��ݿϷ�"<<endl;
	}
}
void print_account(void){
	if(index>0){
		cout<<"**************"<<endl;
		for(int i=0;i<index;i++){
			cout<<"����ID:"<<arr[i].num<<endl;
			cout<<"��  ��:"<<arr[i].name<<endl;
			cout<<"��  ��:"<<arr[i].mon<<endl;
		}
		cout<<"**************"<<endl;
	}
	else
		cout<<"*����� ���°� �����ϴ�.*\n"<<endl;
}

int search(int num){
	for(int i=0;i<index;i++){
		if(arr[i].num==num)
			return i;
	}
	cout<<"*���� ���¹�ȣ �Դϴ�.*";
	return -1;
}
