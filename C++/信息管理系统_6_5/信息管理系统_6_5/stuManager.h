#pragma once
#define _CRT_SECURE_NO_WARNINGS  1

#include<iostream>
#include<mysql.h>
#include<string>
#include<vector>
using namespace std;

typedef struct student
{
	int _stu_id;
	string _name;
	string _gender;
	string _class;
	string _major;
}student;

class stuManager
{
	stuManager();
	~stuManager();
public:
	//采用单例模式
	static stuManager* getInstance()
	{
		static stuManager stuManager;
		return &stuManager;
	}
	bool _insert(student& t);
	bool _updata(student& t);
	bool _delete(int stu_id);
	vector<student> get(string condition = "");
private:
	MYSQL* con;
	const char* host = "127.0.0.1";
	const char* user = "root";
	const char* pw = "123456";
	const char* database = "ppp";
	const int port = 3306;
};

