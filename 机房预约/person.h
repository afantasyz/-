#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"defineFILE.h"
#include<fstream>
#include"orderFile.h"
#include<vector>
#include<map>

class person
{
public:
	string p_name;
	string p_password;
	virtual void openMenu() = 0;
};

