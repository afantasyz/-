#pragma once
#include "person.h"
#include"computerRoom.h"
class student :
    public person
{
public:
    int m_id;
    vector<computerRoom> comList;

    student();
    student(int id, string name, string password);
    virtual void openMenu();
    void applyOrder();
    void showMyOrder();
    void showAllOrder();
    void cancelOrder();
    ~student();
    void Menu();
};

