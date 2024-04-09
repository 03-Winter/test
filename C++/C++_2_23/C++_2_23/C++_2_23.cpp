//
//#include <iostream>
//using namespace std;
////全缺省参数
//void fun1(int a = 10, int b = 20, int c = 30)
//{
//    cout << "a=" << a << endl;
//    cout << "b=" << b << endl;
//    cout << "c=" << c << endl;
//}
//
//
////半缺省参数（缺省部分参数）必须从左往右连续缺省
//void fun2(int a, int b = 10, int c = 20)
//{   
//    cout << "a=" << a << endl;
//    cout << "b=" << b << endl;
//    cout << "c=" << c << endl;
//}
//
//
//
////函数重载，函数名相同，参数不同（个数，类型，顺序）
//int Add(int left,int right)
//{
//    return left + right;
//}
//
//double Add(double left, double right)
//{
//    return left + right;
//}
//
//
//int Add(int left,char right)
//{
//    return left + right;
//}
//
//int Add(int right, int left)
//{
//    return left + right;
//}
//
////为什么c不支持重载
////原因：  函数名修饰原则
//
//int main()
//{
//    fun1();
//    fun1(1, 2, 3);
//    fun2(1);
//    return 0;
//}
//

#include<iostream>
using namespace std;

//int main()
//{
//	//int a = 1;
//	//int& b = a;   //引用必须初始化
//	//int c = 9;
//	//c = b;//这个是赋值而不是引用
//
//	//const int a = 1;
//	////int& b = a;    //编译不通过：a是只读，b是可读可写，所以权限放大
//	//const int& b = a;
//
//
//	//int c = 1;
//	//int& d = c;
//	//const int& e = c;
//	//总结：引用取别名时，变量的访问权限可以缩小，但是不能放大
//
//
//	//int ad = 1;
//	//double da = ad;//赋值时，产生了临时double变量，临时变量具有常性，只读
//	//double& as = da;//隐士类型转化
//	//const double& we = da;
//
//	const int a = 10;
//	int c = 20;
//
//	const int* pa = &a;
//
//	int* pq = &c;
//	const int* pw = pq;
//	return 0;
// }

void swap_c(int* a, int* b)
{
	int tem = *a;
	*a = *b;
	*b = tem;
}
//引用做参数
void swap_cpp(int& a, int& b)
{
	int tem = a;
	a = b;
	b = tem;
}

//引用作为返回值
int count1()
{
	static int c = 0;
	c++;
	return c;//返回时，会赋值给临时变量
}

int& count2()
{
	static int c = 0;//static是作用于周期
	c++;
	return c;
}

int& count2(int a,int b)
{
	int c = a+b;
	c++;
	return c;
}

int& count3(int a,int b)
{
	static int c = a+b;
	//c++;
	return c;
}

//int main()
//{
//	int a = 0, b = 2;
//	int& e1 = count2(a, b);
//	count2(4, 5);
//	cout << "a+b=" << e1 << endl;
//
//	int& e2 = count3(a, b);
//	count3(4, 5);
//	cout << "a+b=" << e2 << endl;
//	//int w = 2, e = 3;
//	//swap_c(&w, &e);
//	//swap_cpp(w, e);
//
//	//const int& r1 = count1();//返回值是常性，所以加const
//	//int& r2 = count2();
//
//	return 0;
//}



int main()
{
	int q = 9;
	auto w = q;
	auto& e = q;

	auto* r = &q;
	auto f = &q;

	cout << typeid(w).name() << endl;
	cout << typeid(e).name() << endl;
	cout << typeid(r).name() << endl;
	cout << typeid(f).name() << endl;
	return 0;
}