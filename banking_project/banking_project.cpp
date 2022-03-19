#include<iostream>
#include<cstring>
//계좌 정보 구조체
typedef struct{
	int num;
	char name[20];
	int mon;
}ACCOUNT;
enum{MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
int index=0;			//구조체배열의 인덱스
ACCOUNT arr[10];

using std::cin;
using std::cout;
using std::endl;

void make_account(void);	//계좌개설
void deposit(void);			//입금
void withdraw(void);		//출금
void print_account(void);	//계좌정보 전체 출력
int search(int mum);		//입금,출금 위치 찾기

int main(void){
	while(1){
	int choice;
	cout<<"\n";
	cout<<"-----Menu-----"<<endl;
	cout<<"1. 계좌개설"<<endl;
	cout<<"2.입금"<<endl;
	cout<<"3.출금"<<endl;
	cout<<"4.계좌정보 전체 출력"<<endl;
	cout<<"5.프로그램 종료"<<endl;
	cout<<"선택:";
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
	cout<<"[계좌개설]"<<endl;
	cout<<"계좌ID:";
	cin>>a.num;
	cout<<"이름:";
	cin>>name;
	strcpy(a.name,name);
	cout<<"입금액:";
	cin>>a.mon;

	arr[index]=a;
	index+=1;
}	
void deposit(void){
	int num;
	int mon;
	cout<<"[입   금]"<<endl;
	cout<<"계좌ID:";
	cin>>num;
	cout<<"입금액:";
	cin>>mon;

	int place=search(num);
	if(place>=0){
		arr[place].mon+=mon;
		cout<<"입금완료"<<endl;
	}
}
void withdraw(void){
	int num;
	int mon;
	cout<<"[출   금]"<<endl;
	cout<<"계좌ID:";
	cin>>num;
	cout<<"출금액:";
	cin>>mon;

	int place=search(num);
	if(place>=0){
		arr[place].mon-=mon;
		cout<<"출금완료"<<endl;
	}
}
void print_account(void){
	if(index>0){
		cout<<"**************"<<endl;
		for(int i=0;i<index;i++){
			cout<<"계좌ID:"<<arr[i].num<<endl;
			cout<<"이  름:"<<arr[i].name<<endl;
			cout<<"잔  액:"<<arr[i].mon<<endl;
		}
		cout<<"**************"<<endl;
	}
	else
		cout<<"*저장된 계좌가 없습니다.*\n"<<endl;
}

int search(int num){
	for(int i=0;i<index;i++){
		if(arr[i].num==num)
			return i;
	}
	cout<<"*없는 계좌번호 입니다.*";
	return -1;
}
