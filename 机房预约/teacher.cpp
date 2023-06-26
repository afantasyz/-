#include "teacher.h"

teacher::teacher()
{
}

//有参构造 (职工编号，姓名，密码)
teacher::teacher(int empId, string name, string password)
{
	this->m_EmpId = empId;
	this->p_name = name;
	this->p_password = password;
}

void teacher::Menu()
{
	cout << "欢迎教师：" << this->m_EmpId << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.审核预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//菜单界面
void teacher::openMenu()
{
	int select;
	while (true)
	{
		this->Menu();
		cin >> select;
		switch (select)
		{
		case 1:
			this->showAllOrder();
			break;
		case 2:
			this->validOrder();
			break;
		case 0:
			cout << "注销登入成功" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			break;
		}
	}
}

//查看所有预约
void teacher::showAllOrder()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	int date;
	int time;
	string name;
	int id;
	int room;
	int state;
	int index = 1;

	while (ifs >> date && ifs >> time && ifs >> name && ifs >> id && ifs >> room && ifs >> state)
	{
		cout << index << ". ";
		string cdate;
		switch (date)
		{
		case 1:
			cdate = "一";
			break;
		case 2:
			cdate = "二";
			break;
		case 3:
			cdate = "三";
			break;
		case 4:
			cdate = "四";
			break;
		case 5:
			cdate = "五";
			break;
		default:
			break;
		}
		cout << "预约日期： 周" << cdate << " ";
		cout << " 时间段： " << (time == 1 ? "上午" : "下午") << " ";
		cout << " 学号： " << id << " ";
		cout << " 申请人： " << name << " ";
		cout << " 机房号： " << room << " ";
		string cstate;
		if (state == 1)
			cstate = "审核中";
		if (state == 0)
			cstate = "已取消";
		if (state == -1)
			cstate = "未通过";
		if (state == 2)
			cstate = "审核成功";
		cout << " 状态： " << cstate << " ";
		cout << endl;
		index++;
	}

	ifs.close();
	system("pause");
	system("cls");
}

//审核预约
void teacher::validOrder()
{
	orderFile odF;
	if (odF.o_num == 0)
	{
		cout << "暂无记录可审核" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "当前共有" << odF.o_num << "条记录" << endl;

	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	int date;
	int time;
	string name;
	int id;
	int room;
	int state;
	int index = 1;

	while (ifs >> date && ifs >> time && ifs >> name && ifs >> id && ifs >> room && ifs >> state)
	{
		cout << index << ". ";
		string cdate;
		switch (date)
		{
		case 1:
			cdate = "一";
			break;
		case 2:
			cdate = "二";
			break;
		case 3:
			cdate = "三";
			break;
		case 4:
			cdate = "四";
			break;
		case 5:
			cdate = "五";
			break;
		default:
			break;
		}
		cout << "预约日期： 周" << cdate << " ";
		cout << " 时间段： " << (time == 1 ? "上午" : "下午") << " ";
		cout << " 学号： " << id << " ";
		cout << " 申请人： " << name << " ";
		cout << " 机房号： " << room << " ";
		string cstate;
		if (state == 1)
			cstate = "审核中";
		if (state == 0)
			cstate = "已取消";
		if (state == -1)
			cstate = "未通过";
		if (state == 2)
			cstate = "审核成功";
		cout << " 状态： " << cstate << " ";
		cout << endl;
		index++;
	}

	cout << "请输入审核的预约" << endl;
	int select;
	while (true)
	{
		cin >> select;
		if (select <= odF.o_num && select > 0)
		{
			break;
		}
		cout << "输入有误，请重新选择" << endl;
	}

	cout << "请输入审核结果" << endl;
	cout << "1、通过" << endl;
	cout << "2、不通过" << endl;
	int status;
	cin >> status;
	if(status==1)
		odF.order[select - 1].a_state = 2;
	else if(status==2)
		odF.order[select - 1].a_state = -1;
	else
	{
		cout << "审核失败" << endl;
		system("pause");
		system("cls");
	}
	odF.updateOrder();
	cout << "审核成功" << endl;
	system("pause");
	system("cls");
}