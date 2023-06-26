#pragma once
#include "person.h"
class teacher :
    public person
{
public:
	//默认构造
	teacher();

	//有参构造 (职工编号，姓名，密码)
	teacher(int empId, string name, string password);

	//菜单界面
	virtual void openMenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();

	void Menu();

	int m_EmpId; //教师编号
};

