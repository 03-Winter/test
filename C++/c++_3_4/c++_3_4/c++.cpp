#define _CRT_SECURE_NO_WARNINGS  1
#include<iostream>
using namespace std;

//������Ϊ����

//void swap_c(int* a, int* b)
//{
//	int tem = *a;
//	*a = *b;
//	*b = tem;
//}
//
//void swap_cpp(int& w, int& e)
//{
//	int tem=w;
//	w = e;
//	e = tem;
//}

//������Ϊ����ֵ
//�������Ч��
//int& add1(int a, int b)
//{
//	static int c = a + b;		//static�������������ڵģ���֤�˳�����������
//	return c;
//}
//
//
//
//int& add2(int a, int b)
//{
//	int c = a + b;
//	return c;
//}


//��������û�е�ַ--inline

//auto�����Զ��������ͣ����Ǳ����ʼ��
//auto������Ϊ��������
// autoҲ������������
//


//auto k���Լ򻯴��룬����������
//std::map<std::string, std::string> dict;
//auto dict=ti;

//int main()
//{

	//int x = 0, y = 2,z=8;
	////swap_c(&x, &y);
	////swap_cpp(x, y);

	//int& ret = add1(x, y);
	//add1(x, z);       //������ֵ����ʱ����ʱ�����÷����ǲ���ȫ��
	//cout << "add(x,y)=" << ret << endl;

	//int arr[] = { 1,2,4,5,7 };//������ÿ�����������
	//C���԰�
	//for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	//{
	//	arr[i] = arr[i] * 2;
	//}
	//
	//for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
	//	cout << arr[i] << endl;
	//c++
	//for (auto& e: arr)
	//{
	//	e = e * 2;
	//}
	//for (auto e : arr)
	//	cout << e <<" ";





//
//	return 0;
//}

//
//void fun(int n)
//{
//	cout << "asd";
//}
//
//void fun(int* v)
//{
//	cout << "fre";
//}
//
//int mian()
//{
//	fun(0);
//	fun(NULL);			//Ԥ�������fun(0)
//	fun(nullptr);		//fun((void*)0)
//
//	//������c++�н���ʹ��nullptr
//	return 0;
//
//}


class stu
{
	//��� û��������Ĭ��Ϊ˽��private
	// 
	// �෴��struct���ͣ�������Ĭ�Ϲ���
	//��������
public:
	void dun()
	{
		cout << "tr";
	}

	//��������
private:
	char* _name;
	int _age;
	int* _stuid;
};

//c++�ṹ��
class ListNode_cpp {
	int val;
	ListNode_cpp* _next;
	ListNode_cpp* _prev;

	//�����Զ����Ա����
	ListNode_cpp* CreatNode(int val);
};

//c�Ľṹ��
struct ListNode_c {
	int val;
	struct ListNode_c* _next;
	struct ListNode_c* _prev;

};

//û�г�Ա���������С��һ��Ϊʲô��С���ǣ������һ     
//�𣺿�һ���ֽڲ���Ϊ�˴����ݣ����Ǳ�ʾռλ����ʾ�������
int main()
{
	stu s1;
	stu s2;


	return 0;
}