#include "stuManager.h"

stuManager::stuManager()
{
	con = mysql_init(NULL);
	//设置字符编码
	mysql_options(con, MYSQL_SET_CHARSET_NAME, "GBK");

	if (!mysql_real_connect(con, host, user, pw, database, port, NULL, 0))
	{
		fprintf(stderr, "failed to conncect:erroe:%s\n", mysql_error(con));
	}
}

stuManager::~stuManager()
{
	mysql_close(con);
}

bool stuManager::_insert(student& stu)
{
	char sql[1024];
	sprintf(sql, "insert into student (id,name,gender,class,major) values(%d,'%s','%s','%s','%s')",
		stu._stu_id, stu._name.c_str(), stu._gender.c_str(),stu._class.c_str(),stu._major.c_str());
	//sprintf(sql, "insert into student (id,name,class) values(2,1,1)");

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "failed to insert:Error:%s\n", mysql_error(con));
		return false;
	}
	return true;
}

bool stuManager::_updata(student& stu)
{
	char sql[1024];
	sprintf(sql, "update student set gender='%s',name='%s',class='%s',major='%s' where id=%d",
		stu._name.c_str(), stu._gender.c_str(), stu._class.c_str(), stu._major.c_str(),stu._stu_id);

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "failed to updata:Error:%s\n", mysql_error(con));
		return false;
	}
	return true;
}

bool stuManager::_delete(int stu_id)
{
	char sql[1024];
	sprintf(sql, "delete from student where id=%d",stu_id);


	if (mysql_query(con, sql))
	{
		fprintf(stderr, "failed to delete:Error:%s\n", mysql_error(con));
		return false;
	}
	return true;

}

vector<student> stuManager::get(string condition)
{
	vector<student> sublist;

	char sql[1024];
	sprintf(sql, "select * from student %s", condition.c_str());

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "failed to updata:Error:%s\n", mysql_error(con));
		return {};
	}
	MYSQL_RES* res = mysql_store_result(con);
	MYSQL_ROW row;
	while (row = mysql_fetch_row(res))
	{
		student stu;
		//atoi从string转化成int类型
		stu._stu_id = atoi(row[0]);
		stu._name = row[1];
		stu._gender = row[2];
		stu._class = row[3];
		stu._major = row[4];
		sublist.push_back(stu);
	}

	return sublist;
}
