#define _CRT_SECURE_NO_WARNINGS  1
#include"stuManager.h"




int main()
{
	student stu{ 1,"zr","ÄĞ","one","¼Æ¿Æ"};
	stuManager::getInstance()->_insert(stu);
	//vector<student> ret=stuManager::getInstance()->_insert(stu);


	//for (auto& e : ret)
	//{
	//	cout << e._stu_id << "  " << e._name << "  " << e._class << endl;
	//}
	return 0;
}