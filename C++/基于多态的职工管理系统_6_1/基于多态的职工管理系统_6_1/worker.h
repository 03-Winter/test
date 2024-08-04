#pragma once

#include<iostream>
#include<string>

using namespace std;

class worker
{
public:
	virtual void showinfo() = 0;
	virtual string getDeptName() = 0;

	int _id;
	string _name;
	int _dept_id;

private:

};


class employee :public worker
{
public:
	employee(int id, string name, int dept_id)
	{
		this->_id = id;
		this->_name = name;
		this->_dept_id = dept_id;
	}
	virtual void showinfo() 
	{
		cout << "职工编号: " << this->_id << "\t职工姓名: " << this->_name << "\t岗位: " << this->getDeptName();
		cout << endl;

	}

	virtual string getDeptName()
	{
		return "员工";
	}

};

class manager :public worker
{
public:
	manager(int id, string name, int dept_id)
	{
		this->_id = id;
		this->_name = name;
		this->_dept_id = dept_id;
	}
	virtual void showinfo()
	{
		cout << "职工编号: " << this->_id << "\t职工姓名: " << this->_name << "\t岗位: " << this->getDeptName();
		cout << endl;
	}

	virtual string getDeptName()
	{
		return "经理";
	}
};

class boss :public worker
{
public:
	boss(int id, string name, int dept_id)
	{
		this->_id = id;
		this->_name = name;
		this->_dept_id = dept_id;
	}
	virtual void showinfo()
	{
		cout << "职工编号: " << this->_id << "\t职工姓名: " << this->_name << "\t岗位: " << this->getDeptName();
		cout << endl;

	}

	virtual string getDeptName()
	{
		return "老板";
	}
};


