#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

struct Subject { 			//과목정보.
	char SubName[30];
	int Hackjum;
	char Grade[10];
	float GPA;
};
struct Student {				//학생정보
	char StdName[30];
	int Hakbun;
	Subject Sub[3];
	float AveGPA;
};
struct Student student[2];	//입력된 학생정보 저장할 구조체배열(크기2)
int cnt;					//저장된 학생수를 셀 변수
void ShowMenu(void);		//메뉴를 보여주는 함수
void InputInfo(void);		//성적 입력함수
int CalGPA(int i);			//과목평점 계산하는 함수
void CalAveGPA(void);		//교과목 평균 평점 계산하는 함수
void ShowInfo(void);		//저장된 정보 보여주는 함수

int main(void)
{
	int choice;				//선택한 기능을 저장할 변수
	while (1) {
		ShowMenu();
		cin >> choice;

		switch (choice) {
		case 1:
			InputInfo(); break;
		case 2:
			ShowInfo(); break;
		case 3:
			return 0;
		}
	}
}

void ShowMenu(void)
{
	cout << "=====메뉴=====" << endl;
	cout << "1. 학생 성적 입력" << endl;
	cout << "2. 전체 학생 성적 보기" << endl;
	cout << "3. 프로그램 종료" << endl;
	cout << "원하는 기능을 입력하세요 : ";
}
void InputInfo(void)
{
	char temp[30];				//이름, 과목명, 과목등급을 임시저장할 변수
	for (int i = 1; i < 3; i++) {
		cout << "*" << i << "번째 학생 이름과 학번을 입력하세요." << endl;
		cout << "이름 : "; cin >> temp; strcpy(student[cnt].StdName, temp);
		cout << "학번 : "; cin >> student[cnt].Hakbun;

		cout << "* 수강한 과목3개와 각 교과목명, 과목학점, 과목등급을 입력하세요." << endl;
		for (int i = 0; i < 3; i++) {
			cout << "교과목명 : "; cin >> temp; strcpy(student[cnt].Sub[i].SubName, temp);
			cout << "과목학점수 : "; cin >> student[cnt].Sub[i].Hackjum;
			while (1) { // 정확한 과목등급을 입력할때까지 반복
				cout << "과목등급<A+ ~ F> : "; cin >> temp; strcpy(student[cnt].Sub[i].Grade, temp);
				if (CalGPA(i) == 1)
					break;
				getchar();	//버퍼 비우기
			}
		}
		CalAveGPA();				//교과목 평균 평점을 계산하는 함수를 불러온다.
		cnt++;					//저장된 학생수를 하나 늘려준다.
	}
}
int CalGPA(int i)
{	//정확한 과목등급을 입력했을 시 1반환, 아닐 시 -1반환, 정확한 과목등급을 입력하도록 유도
	if (strcmp(student[cnt].Sub[i].Grade, "A+") == 0) {
		student[cnt].Sub[i].GPA = 4.5 * student[cnt].Sub[i].Hackjum; return 1;
	}
	else if (strcmp(student[cnt].Sub[i].Grade, "A0") == 0) {
		student[cnt].Sub[i].GPA = 4.0 * student[cnt].Sub[i].Hackjum; return 1;
	}
	else if (strcmp(student[cnt].Sub[i].Grade, "B+") == 0) {
		student[cnt].Sub[i].GPA = 3.5 * student[cnt].Sub[i].Hackjum; return 1;
	}
	else if (strcmp(student[cnt].Sub[i].Grade, "B0") == 0) {
		student[cnt].Sub[i].GPA = 3.0 * student[cnt].Sub[i].Hackjum; return 1;
	}
	else if (strcmp(student[cnt].Sub[i].Grade, "C+") == 0) {
		student[cnt].Sub[i].GPA = 2.5 * student[cnt].Sub[i].Hackjum; return 1;
	}
	else if (strcmp(student[cnt].Sub[i].Grade, "C0") == 0) {
		student[cnt].Sub[i].GPA = 2.0 * student[cnt].Sub[i].Hackjum; return 1;
	}
	else if (strcmp(student[cnt].Sub[i].Grade, "D+") == 0) {
		student[cnt].Sub[i].GPA = 1.5 * student[cnt].Sub[i].Hackjum; return 1;
	}
	else if (strcmp(student[cnt].Sub[i].Grade, "D0") == 0) {
		student[cnt].Sub[i].GPA = 1.0 * student[cnt].Sub[i].Hackjum; return 1;
	}
	else if (strcmp(student[cnt].Sub[i].Grade, "F") == 0) {
		student[cnt].Sub[i].GPA = 0.0 * student[cnt].Sub[i].Hackjum; return 1;
	}
	else {
		cout << "A+,A0,B+,B0,C+,C0,D+,D0,F중 하나를 입력해주세요." << endl; return -1;
	}
}
void CalAveGPA(void)
{	//3개의 과목평점을 더해서 3으로 나누어 평균평점을 구한다.
	student[cnt].AveGPA =
		(student[cnt].Sub[0].GPA + student[cnt].Sub[1].GPA + student[cnt].Sub[2].GPA) / 3;
}
void ShowInfo(void)
{
	if (cnt == 0) {
		cout << "\n저장된 학생정보가 없습니다.\n" << endl;
	}
	else {		//학생정보를 저장한 후
		cout.precision(2);
		cout << fixed;

		cout << "\n";
		cout.setf(ios::right);
		cout << setw(35) << "전체 학생 성적 보기" << endl;
		cout << "=======================================================" << endl;

		for (int i = 0; i < 2; i++) {
			cout << "이름 : " << student[i].StdName;
			cout << "  학번 : " << student[i].Hakbun << endl;
			cout << "=======================================================" << endl;
			cout << setw(35) << "과목명\t과목학점\t과목등급\t과목평점" << endl;
			cout << "=======================================================" << endl;
			for (int j = 0; j < 3; j++) {
				cout << setw(6) << student[i].Sub[j].SubName << "\t" << setw(10) << student[i].Sub[j].Hackjum
					<< "\t" << setw(10) << student[i].Sub[j].Grade << "\t" << setw(10) << student[i].Sub[j].GPA << endl;
			}
			cout << "=======================================================" << endl;
			cout << setw(40) << "평균평점" << "\t" << student[i].AveGPA << endl;
			cout << "\n";
		}
	}
}

