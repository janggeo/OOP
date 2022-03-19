#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

struct Subject { 			//��������.
	char SubName[30];
	int Hackjum;
	char Grade[10];
	float GPA;
};
struct Student {				//�л�����
	char StdName[30];
	int Hakbun;
	Subject Sub[3];
	float AveGPA;
};
struct Student student[2];	//�Էµ� �л����� ������ ����ü�迭(ũ��2)
int cnt;					//����� �л����� �� ����
void ShowMenu(void);		//�޴��� �����ִ� �Լ�
void InputInfo(void);		//���� �Է��Լ�
int CalGPA(int i);			//�������� ����ϴ� �Լ�
void CalAveGPA(void);		//������ ��� ���� ����ϴ� �Լ�
void ShowInfo(void);		//����� ���� �����ִ� �Լ�

int main(void)
{
	int choice;				//������ ����� ������ ����
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
	cout << "=====�޴�=====" << endl;
	cout << "1. �л� ���� �Է�" << endl;
	cout << "2. ��ü �л� ���� ����" << endl;
	cout << "3. ���α׷� ����" << endl;
	cout << "���ϴ� ����� �Է��ϼ��� : ";
}
void InputInfo(void)
{
	char temp[30];				//�̸�, �����, �������� �ӽ������� ����
	for (int i = 1; i < 3; i++) {
		cout << "*" << i << "��° �л� �̸��� �й��� �Է��ϼ���." << endl;
		cout << "�̸� : "; cin >> temp; strcpy(student[cnt].StdName, temp);
		cout << "�й� : "; cin >> student[cnt].Hakbun;

		cout << "* ������ ����3���� �� �������, ��������, �������� �Է��ϼ���." << endl;
		for (int i = 0; i < 3; i++) {
			cout << "������� : "; cin >> temp; strcpy(student[cnt].Sub[i].SubName, temp);
			cout << "���������� : "; cin >> student[cnt].Sub[i].Hackjum;
			while (1) { // ��Ȯ�� �������� �Է��Ҷ����� �ݺ�
				cout << "������<A+ ~ F> : "; cin >> temp; strcpy(student[cnt].Sub[i].Grade, temp);
				if (CalGPA(i) == 1)
					break;
				getchar();	//���� ����
			}
		}
		CalAveGPA();				//������ ��� ������ ����ϴ� �Լ��� �ҷ��´�.
		cnt++;					//����� �л����� �ϳ� �÷��ش�.
	}
}
int CalGPA(int i)
{	//��Ȯ�� �������� �Է����� �� 1��ȯ, �ƴ� �� -1��ȯ, ��Ȯ�� �������� �Է��ϵ��� ����
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
		cout << "A+,A0,B+,B0,C+,C0,D+,D0,F�� �ϳ��� �Է����ּ���." << endl; return -1;
	}
}
void CalAveGPA(void)
{	//3���� ���������� ���ؼ� 3���� ������ ��������� ���Ѵ�.
	student[cnt].AveGPA =
		(student[cnt].Sub[0].GPA + student[cnt].Sub[1].GPA + student[cnt].Sub[2].GPA) / 3;
}
void ShowInfo(void)
{
	if (cnt == 0) {
		cout << "\n����� �л������� �����ϴ�.\n" << endl;
	}
	else {		//�л������� ������ ��
		cout.precision(2);
		cout << fixed;

		cout << "\n";
		cout.setf(ios::right);
		cout << setw(35) << "��ü �л� ���� ����" << endl;
		cout << "=======================================================" << endl;

		for (int i = 0; i < 2; i++) {
			cout << "�̸� : " << student[i].StdName;
			cout << "  �й� : " << student[i].Hakbun << endl;
			cout << "=======================================================" << endl;
			cout << setw(35) << "�����\t��������\t������\t��������" << endl;
			cout << "=======================================================" << endl;
			for (int j = 0; j < 3; j++) {
				cout << setw(6) << student[i].Sub[j].SubName << "\t" << setw(10) << student[i].Sub[j].Hackjum
					<< "\t" << setw(10) << student[i].Sub[j].Grade << "\t" << setw(10) << student[i].Sub[j].GPA << endl;
			}
			cout << "=======================================================" << endl;
			cout << setw(40) << "�������" << "\t" << student[i].AveGPA << endl;
			cout << "\n";
		}
	}
}

