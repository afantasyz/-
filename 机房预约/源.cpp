#include<iostream>
using namespace std;
#include"defineFILE.h"
#include"manager.h"
#include"person.h"
#include"student.h"
#include"teacher.h"
#include<fstream>

void showMenu()
{
	cout << "======================  欢迎来到传智播客机房预约系统  ====================="
		<< endl;
	cout << endl << "请输入您的身份" << endl;
	cout << "\t\t -------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.学生代表           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.老    师           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.管 理 员           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.退    出           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << "输入您的选择: ";
}

void logIn(string filename,int type)
{
	person* identity = NULL;
	string name;
	string password;
	ifstream ifs;
	ifs.open(filename, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	if (type == 1)
	{
		cout << "请输入登录学生用户名" << endl;
		cin >> name;
		cout << "请输入登录学生密码" << endl;
		cin >> password;
	}
	else if (type == 2)
	{
		cout << "请输入登录教师用户名" << endl;
		cin >> name;
		cout << "请输入登录教师密码" << endl;
		cin >> password;
	}
	else if (type == 3)
	{
		cout << "请输入管理员用户名" << endl;
		cin >> name;
		cout << "请输入管理员密码" << endl;
		cin >> password;
	}
	
	if (type == 1)
	{
		int fid;
		string fname;
		string fpassword;
		while (ifs>>fid&&ifs>>fname&&ifs>>fpassword)
		{
			if (name == fname && password == fpassword)
			{
				identity = new student(fid, fname, fpassword);
				cout << "学生验证登录成功!" << endl;
				system("pause");
				system("cls");
				identity->openMenu();
				return;
			}
		}
	}
	else if (type == 2)
	{
		int fid;
		string fname;
		string fpassword;
		while (ifs >> fid && ifs >> fname && ifs >> fpassword)
		{
			if (name == fname && password == fpassword)
			{
				identity = new teacher(fid, fname, fpassword);
				cout << "教师验证登录成功!" << endl;
				system("pause");
				system("cls");
				identity->openMenu();
				return;
			}
		}
	}
	else if (type == 3)
	{
		int fid;
		string fname;
		string fpassword;
		while (ifs >> fname && ifs >> fpassword)
		{
			if (name == fname && password == fpassword)
			{
				identity = new manager(fname, fpassword);
				cout << "管理员验证登录成功!" << endl;
				system("pause");
				system("cls");
				identity->openMenu();
				return;
			}
		}
	}
	cout << "用户名或密码错误！" << endl;
	identity = NULL;
	delete identity;
	system("pause");
	system("cls");
	return;
}

int main()
{
	int select;
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 0:
			cout << "welcome the next time!" << endl;
			exit(0);
			break;
		case 1:
			logIn(STUDENT_FILE, 1);
			break;
		case 2:
			logIn(TEACHER_FILE, 2);
			break;
		case 3:
			logIn(MANAGER_FILE, 3);
			break;
		default:
			cout << "error input" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}