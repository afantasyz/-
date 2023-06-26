#pragma once
#include "person.h"
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"

class manager :
    public person
{
public:
	vector<student> stuList;
	vector<teacher> teaList;
	vector<computerRoom> comList;

	//默认构造
	manager();

	//有参构造  管理员姓名，密码
	manager(string name, string pwd);

	//选择菜单
	virtual void openMenu();

	void Menu();

	//添加账号  
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约记录
	void cleanFile();

	void initVector();
};

