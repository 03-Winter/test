#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int sum = 0;
//	scanf("%d %d", &a, &b);
//	sum = a + b;
//	printf("sum = %d\n" , sum);
//		
//
//
//
//	return 0;
//}


//int main()
//{
//	int input = 0;
//	printf("要好好学习吗(0/1)?");
//	scanf("%d", &input);
//	if (input == 1)
//		printf("好offer\n");
//	else
//		printf("卖猪\n");
//	return 0;
//}

////int main()
////{
////	int line = 0;
////	while(line<30000)
////	{
////		printf("好男孩:%d\n", line);
////		line++;
////	333///	if (line == 30000)
////	{
////		printf("奖金\n");
////	}
////	return 0;
////}
//int main()
//{
//	int line = 0;
//		while (line < 10000)
//		{
//			printf("GOOD BOY:%d\n", line);
//			line++;
//	    }
//		if (line == 10000)
//		{
//			printf("prrity");
//
//		}
//		return 0;
//}
//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//	
//}
//
//
//
//
//
//
//
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	scanf("%d%d", &num1, &num2);
//	//int sum = num1 + num2;方法1
//	int sum = Add(num1, num2);//方法2
//	printf("%d\n", sum);
//	return 0;
//}
//int main()
//{
//
//	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
// //   //char ch[5] = { 'a','b','c','\0'};
//	//int i = 0;
//	//while (i < 10)
//	//{
//	//	printf("%d\n", arr[i]);
//	//	i++;
//	//}
//
//	double a = 13.000000000000000 / 7.000000000000000;
//	printf("%lf\n", a);
//
//	return 0;
//}
//IN
//int main()
//{
//	int a = 10;
//	//int b = ++a;//先++，后使用
//	//printf("%d\n", a);
//	//printf("%d\n", b);
//	int b = a++;
//	printf("%d\n", a);
//	printf("%d\n", b);
//
//	return 0;
//}
//int main()
//{
//	//int a = (int) 3.24;
//	//printf("%d\n", a);
//	int a = 9;
//	int b = 0;
//	int c = a || b;
//	printf("%d\n", c);
//	//if (a && b)
//	/*{
//
//
//	/
//*/
//
//
//
//	return 0;
//}
//int main()
//{
//	int a = 8;
//	int b = 48;
//	int max = 0;
//	/*if (a > b)
//		max = a;
//	else
//		max = b;*/
//	max = a > b ? a : b;
//	printf("%d\n", max);
//	return 0;
//}
//int main()
//{
//	int a = 4;
//	int b = 3;
//	int c = 7;
//	int d = (a = b + 3, c = a - 4, b = c + 3);//从左至右开始算
//	printf("%d\n", d);
//	return 0;
//}
//typedef unsigned int u_int;
//int mian()
//{
//	unsigned int num = 34;
//	u_int num2 = 34;
//	return 0;
//} 


//void test()
//{
//	static int a = 10;
//	a++;
//	printf("%d\n", a);
//
//}
//int main()
//{
//	int i = 0;
//	while (i < 1000)
//	{
//
//		test();
//		i++;
//	}
//
//
//	return 0;
//}
//int main()
//{
//	int line = 0;
//	while (line < 20000)
//	{
//
//		printf("我能习惯远距离，爱总是身不由己，宁愿换个方式至少还能遥远爱着你：%d\n", line);
//		line++;
//	}
//
//	if (line == 20000)
//	{
//		printf("爱能克服远距离，多远都要在一起\n");
//
//	}
//	return 0;
//}
//extern int g_val;
//int main()
//{
//	printf("%d\n", g_val);
//	return 0;
//}
//extern int Add(int, int);
//
//int main()
//{
//	int a = 4565;
//	int b = 6454;
//	int sum = Add(a, b);
//	printf("sum = %d\n", sum);
//	return 0;
//}

//int main()
//{
//	int a = 34;
//	
//	//int*printf("%p\n,&a");
//
//
//	int* pa = &a;
//	*pa = 20;
//	printf("%d\n", a);
//		
//	return 0;
//
//}

//int main()
//{
//	printf("%d\n", sizeof(char*));
//	printf("%d\n", sizeof(int*));
//	printf("%d\n", sizeof(long*));
//	printf("%d\n", sizeof(long long*));
//	printf("%d\n", sizeof(short*));
//	printf("%d\n", sizeof(float*));
//	printf("%d\n", sizeof(double*));
//	printf("%d\n", sizeof(char*));
//	return 0;
//}
//struct stu
//{
//	char nanme[12];
//	int age;
//	double score;
//};
//struct book
//{
//	char name[23];
//	float price;
//	char id[24];
//};
//int main()
//{
//	struct stu s = { "张三",18,71.34 };
//	printf("1:%s %d %lf\n", s.nanme, s.age, s.score);
//	struct stu * ps = &s;
//	printf("2:%s %d %lf\n", (*ps).nanme, (*ps).age, (*ps).score);
//	printf("3: %s %d %lf\n", ps->nanme, ps->age, ps->score);
//	return 0;
//}
//int MAX(int x, int y)
//{
//	if (x > y)
//	    return x;
//	else
//		return y;
//
//
//}
//int main()
//{
//	int a = 26;
//	int b = 63;
//	scanf("%d %d", &a, &b);
//	int m = MAX(a, b);
//	printf("%d\n", m);
//
//	return 0;
//}
//int sum(int a)
//{
//	int c = 0;
//	static int b = 5;
//	c += 2;
//	b += 3;
//	return (a + b + c);
//}
//int main()
//{
//	int i = 0;
//	int a = 2;
//	for (i = 0; i < 6; i++)
//	{
//
//		printf("%d\n", sum(a));
//	}
//	return 0;
//}
//int main()
//{
//
//
//	printf(".....**.....\n");
//	printf(".....**.....\n");
//	printf("************\n");
//	printf("************\n");
//	printf("...*....*...\n");
//	printf("...*....*...\n");
//}		
//int main()
//{
//	int a = 3, b = 5, c = 7;
//	if (a > b)a = b;
//	c = a;
//	if (c != a)c = b;
//	printf("%d,%d,%d\n", a, b, c);
//	return 0;
//}
//int main()
//{
//	int a = 2, b = 3,s;
//	float x = 3.5, y = 2.5;
//	s= (int)x % (int)y + (float)(a + b) / 2;
//	printf("%f", s);
//	return 0;
//}
//viod main()
//{
//	/*float a = 3.123456789, b = 3.14159;
//	printf("%.9f\n,%-6.3f\n", a,b);*/
//
//	char	 a;
//	a = 'A';
//	printf("$d,%c", a, a);
//	
//}
//int main()
//{
//
//
//	char a;
//	a = 'A';
//	printf("%d,%c", a, a);
//}
//int main()
//{
//	int x, a = 1, b = 2, c = 3, d = 4;
//	x = (a < b) ? a : b;
//	x = (x < c) ? x : c;
//	x = (d > x) ? x : d;
//	printf("%d\n", x);
//
//	return 0;
//}
//int main()
//{
//	int i = 3;
//	printf("%d", -i++);
//	return 0;
//}

//int main()
//{
//	int a = 54;
//	if (a > 34)
//		printf("中年\n");
//	else
//	{
//		printf("少年\n");
//		printf("老不死");
//	}
//	return 0;
//}
//int main()
//{
//	int a = 278;
//	if (a < 18)
//		printf("少年\n");
//	else if (a >= 18 && a < 26)
//		printf("青年\n");
//	else if (a >= 26 && a < 40)
//		printf("中年\n");
//	else if (a >= 40 && a < 60)
//		printf("壮年\n");
//	else if (a >= 60 && a < 100)
//		printf("老年\n");
//	else
//		printf("老不死\n");
//	return 0;
//}
//int main()
//{
//	int a = 9;
//	int b = 4;
//	if (a == 7)
//	{
//		if (b == 4)
//			printf("hehe\n");
//		else
//			printf("haha\n");
//	}
//	else
//		printf("错误障碍\n");
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	for (a =1; a <= 1000382; a++)
//	{
//		if (1 == a % 2)
//		printf(" %d", a);
//
//
//		/////////////////////////////////////////方法一
//	}
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i+= 2)/////////////////////////////方法二
//		printf("%d", i);
//	return 0;
//}
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//		printf("星期一\n");break;
//	case 2:
//		printf("星期二\n"); break;
//	case 3:
//		printf("星期三\n"); break;
//	case 4:
//		printf("星期四\n"); break;
//	case 5:
//		printf("星期五\n"); break;
//	case 6:
//		printf("星期六\n"); break;
//	case 7:
//		printf("星期日\n"); break;
//		default
//	}
//	return 0;
//}
//int main()
//{
//	int day = 0;
//	printf("请输入数字:");
//	scanf("%d", &day);
//	
//	switch (day)
//	{
//	default:
//		printf("输入错误输入错误"); break;
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("工作日\n"); break;
//	case 6:
//	case 7:
//		printf("休息日\n"); break;
//	
//	}
//	return 0;
//}
//int main()
//{
//	int n = 1;
//	int m = 2;
//	switch (n)
//	{
//	case 1:
//		m++;//m=3
//	case 2:
//		n++;//n=2
//	case 3://n不等于3，进不去，但是m等于3，进来case 3：所以m加加；
//		switch (n)//n是几，n就跳到几
//		{
//		case 1://跳过
//			n++;//不赋值
//		case 2://直接来到case 2，
//			m++; n++; break;//赋值，m=4；
//
//
//		}
//	case 4://n已结束，m继续执行，进入case 4，进行赋值；
//		m++; break;//m=5
//	default:
//		break;
//	}
//	printf("m=%d,n=%d", m, n);
//	return 0;
//}
//int main()
//{
//	while (1)
//		printf("循环语句为真");

//	return 0;
//}
//int main()
//{
//	int i = 0;
//	while (i <= 10)
//	{
//		if (i == 5)
//			continue;
//		//在while循环中，break用于永久的终止循环，
//		//在while循环中，continue的作用是跳过本次循环continue后边的代码
//		//直接去判断部分， 看是否进行下一次循环
//
//		printf("%d ", i);
//		i++;
//
//	}
//
// 	return 0;
//}
//int main()
//{
//	int ch = getchar();
//	printf("%c\n", ch);
//	putchar(ch);	
//	printf("%c\n", ch);
//	putchar(ch);
//	printf("%c\n", ch);
//	putchar(ch);
//
//		return 0;
//} 

//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		putchar(ch);
//
//	}
//	return 0;
//} 

//int main()
//{
//	char password[20] = { 0 };
//	printf("请输入密码：>");
//	scanf("%s", password);
//	printf("请确认密码(Y\N)：>");
//	/*getchar();*/
//	int tem = 0;
//	while ((tem = getchar()) !='\n')
//	{
//		;
//
//	}
//	int ch = getchar();
//	/*getchar(); 
//	getchar();
//	getchar();
//	getchar();*/
//	if (ch == 'Y')
//	{
//		printf("确认成功\n");
//	}
//	else
//	{
//		printf("确认失败\n");
//	}
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	while (i < 12)
//	{
//		i++;
//		printf("%d ", i);
//
//
//	}
//
//
//	return 0;
// }

//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 98; i++)
//	{
//		printf("%d ", i);
//
//	}
//	return 0;
//}

//int main()
//
//{
//	int a, b, tepm;
//	printf("please input a =");
//	scanf("%d", &a);
//	printf("input b =");
//	scanf("%d", &b);
//	if (a > b)
//	{
//		tepm = a;
//		a = b;
//		b = tepm;
//	}
//		printf("a=%d,b=%d", a, b);
//	
//	
//}

//int main()
//{
//	int a, b,c,max;
//	printf("please input 3 integer number:");
//	scanf("%d%d%d", &a, &b, &c);
//	if (a > b)
//	{
//		if (a > c)
//			max = a;
//		else
//			max = b;												////方法一
//	}
//	else
//	{
//	if (b>c)
//	
//		max = b;
//	else
//		max = c;
//
//	}
//	printf("%d", max);
//	return 0;
//}

//int main()
//{
//	int a, b, c, max;
//	printf("please input 3 integer number: ");
//	scanf("%d%d%d", &a, &b, &c);
//	max = a > b ? a : b;										///方法二
//	max = max > c ? max : b;
//	printf("max=%d", max);
//
//
//	return 0;
//}
/*nt main()
{
	int a, b, c, max;
	printf("please input 3 integer number:");
	scanf("%d%d%d", &a, &b, &c);
	max = (a > b ? a : b) > c ? (a > b ? a : b) : c;							////方法三
	printf("%d", max);

	return 0;
}*/
//int main()
//{
//	int year;
//	scanf("%d", &year);
//	if (year % 400 == 0)
//		printf("是闰年");
//	else
//	{
//		if (year % 4 == 0 && year % 100 != 0)
//			printf("是闰年");
//		else
//			printf("非闰年");
//
//	}
//
//	return 0;
//}

//int main()
//{
//	int year, month;
//	int  days =0, flag =0;
//	printf("please input year：");
//	scanf("%d", &year);
//	printf("please input month:");
//	scanf("%d", &month);
//	if (year% 400 == 0)
//		year= 1;
//	else
//	{
//		if (year % 4 && year % 100 != 0)
//			flag = 1;
//		else
//			flag= 0;
//
//	}
//	switch (month)
//	{
//	case 1:
//	case 3:
//	case 5:
//	case 7:
//	case 8:
//	case 10:
//	case 12:days = 31; break;
//	case 4:
//	case 6: 
//	case 9:
//	case 11:days = 30; break;
//	case 2:
//	{
//		if (flag == 1)
//		days = 29;
//		else
//		days = 28;
//	}
//	default:printf("month inptu error\n");
//	}
//	printf("%d年%d月份有%d天\n", year, month, days);
//	return 0;
//}

//int main()
//{
//    float price,k,b;
//    int a,c;
//    scanf("%d%f", &a, &k);
//    c = k;
//    b = k - c;
//    if (b > 0)
//    {
//        b = b + 1;
//    }
//    switch (a)
//    {
//    case 0:
//    {
//        if (k <= 1) price = 10;
//        else price = 10 + ((int)b + c - 1) * 3;
//        printf("Price: %.2f\n", price);
//
//    }   break;
//    case 1:
//    {
//        if (k <= 1) price = 10;
//        else price = 10 + ((int)b + c - 1) * 4;
//        printf("Price: %.2f\n", price);
//
//    } break;
//    case 2:
//    {
//        if (k <= 1) price = 15;
//        else price = 15 + ((int)b + c - 1) * 5;
//        printf("Price: %.2f\n", price);
//    } break;
//    case 3:
//    {
//        if (k <= 1) price = 15;
//        else price = 15 + ((int)b+c-1) * 6.5;
//        printf("Price: %.2f\n", price);
//    }break;
//    case 4:
//    {
//        if (k <= 1) price = 15;
//        else price = 15 + ((int)b + c - 1) * 10;
//        printf("Price: %.2f\n", price);
//    }break;
//    default:printf("Error in Area\n Price:  0.00");
//
//    }
//
//
//	return 0;
//}

//int main()
//{
//	/*int a = -1, b = 4, k;
//	k = (++a <= 0) && !(b-- <= 0);*/
//	printf("%d %d %d", k, a, b);
//	/*int x;
//	scanf("%d",&x);
//	if (x++ > 5)
//		printf("%d", x);
//	else
//		printf("%d", x--);*/
//	/*int x, y = 1;
//	if (y != 0) x = 5;
//	printf("%d\t", x);
//	if (y == 0) x = 3;
//	else x = 5;
//	printf("%d\t\n", x);*/
//	//int c = 0, x = 1, y = 1;
//	//c = x++ || y++;//因为x++为真，所以y++ 不执行， C为真c=1
//	//printf("\n%d%d%d\n", x, y, c);
//	return 0;
//}

//int main()
//
//{
//	double d,m;
//	scanf("%lf", &d);
//	if (d <= 30)
//		m = d * 0.6;
//	else if (d <= 50)
//		m = 30 * 0.6 + (d - 30) * 0.9;
//	else
//		m = 30 * 0.6 + 20 * 0.9 + (d - 50) * 1.5;
//	printf("%lf", m);
//	return 0;
//}

//int main()
//{
//    int a, t, n;
//    float price, z;
//    scanf("%d,%f", &n, &z);
//    t = z;
//    if (t == z) { a = 1; }
//    if (n <= 4 && n >= 0) 
//    {
//        switch (n) 
//        {
//        case 0:if (z <= 1)price = 10; else { if (a == 1)price = (z - 1)3 + 10; else price = 3(t)+10; };   break;
//        case 1:if (z <= 1)price = 10; else { if (a == 1)price = (z - 1)4 + 10; else price = 4(t)+10; }; break;
//        case 2:if (z <= 1)price = 15; else { if (a == 1)price = (z - 1)5 + 15; else price = 5(t)+15; }; break;
//        case 3:if (z <= 1)price = 15; else { if (a == 1)price = (z - 1)6.5 + 15; else price = 6.5(t)+15; }; break;
//        case 4:if (z <= 1)price = 15; else { if (a == 1)price = (z - 1)10 + 15; else price = 10(t)+15; }; break;
//        }
//        printf("Price:%5.2f", price);
//    }
//    else {
//        printf("Error in Area\n");
//        printf("Price: 0.00");
//    }
//
//
//
//
//	return 0;
//}

//int main()
//	{
//        int bm,za;
//      float zo,zn;
//      scanf("%d,%f",&bm,&zn);
//      switch (bm) {
//          case 0:
//            if (zn <= 1)
//                zo = 10;
//            else
//                {
//                za = zn;
//                if ((za*10) / zn == 10)
//                za -= 1;
//                zo = 10 + za*3;
//             break;
//        case 1:
//      if (zn <= 1)
//      zo = 10;
//  else
//      {
//      za = zn;
//      if ((za*10) / zn == 10)
//      za -= 1;
//      zo = 10 + za*4;
//}break;
//case 2:
//      if (zn <= 1)
//      zo = 15;
//  else
//      {
//      za = zn;
//      if ((za*10) / zn == 10)
//      za -= 1;
//      zo = 15 + za*5;
//}break;
//case 3:
//      if (zn <= 1)
//      zo = 15;
//  else
//      {
//      za = zn;
//      if ((za*10) / zn == 10)
//      za -= 1;
//      zo = 15 + za*6.5;
//}break;
//case 4:
//      if (zn <= 1)
//      zo = 15;
//      else
//      {
//      za = zn;
//      if ((za*10) / zn == 10)
//      za -= 1;
//      zo = 15 + za*10;
//}break;
//default:printf("Error in Area\n"); break;
//}
//printf("Price: %.2f\n",zo);
//		return 0;
//	}

//int main()
//{
//	int arr[10] = { 1,2,3,4};
//	int i = 0; 
//	for (i = 0; i < 10; i++)
//	{
//
//		printf("%d", arr[i]);
//	}
//
//	return 0;
//}

//int main()
//{
//	/*for (;;)
//		printf("hoho\n");*/
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 10; i++)
//	{
//		for (; j < 10; j++)
//			printf("nihao");
//
//	}
//	return 0;
//}
//int main()
//{
//	int x=0,y=0;
//	for (x = 0, y = 0; x < 2 || y>5; ++x, y++)
//	{
//		printf("你好！");
//	}
//	return 0;
//}
//int main()
//{
//	int i = 1;
//	do
//	{
//
//		if (i == 5)
//			continue;
//		printf("%d", i);
//		i++;
//
//	} while (i < 10);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int n = 1;
//	scanf("%d", &i);
//	for (j = 1; j <= i; j++)
//	{
//		n *= j;
//	}
//	printf("%d", n);
//	return 0;
//} 

///**/int main()
//{
//
//
//	return 0;
//}
//
//#include<stdio.h>
//#include<math.h>
//int main(void)
//{
//    /*********Begin*********/
//    double a, b, c;
//    double m;
//    double x1, x2;
//    printf("Please enter the coefficients a,b,c:\n");
//    scanf("%lf,%lf,%lf", &a, &b, &c);
//    m = b * b - 4 * a * c;
//    if (m >= 0)
//    {
//        m = sqrt(m);
//        x1 = (-b + m) / (2.0000 * a);
//        x2 = -b / (2.0000 * a) - m / (2.0000 * a);
//        printf("x1=%.4f, x2=%.4f\n", x1, x2);
//    }
//    else
//    {
//        printf("error!\n");
//
//
//    }
//
//
//
//
//    /*********End**********/
//    return 0;
//}

//void main()
//{
//	int x = -1;
//	do
//		x = x * x;
//	while (!x);
//
//	
//}
//
//int main()
//{
//	/*int x = 0, y = 0;
//	while (x < 15)
//		y++, x += ++y;
//	printf("%d%d", y, x);*/
//	int a = 0, i;
//	for (i = 1; i < 5; i++)
//	{
//		switch (i)
//		{
//		case 0:
//		case 3:a += 2;
//		case 1:
//		case 2:a += 3;
//		default:a += 5;
//		}
//	}
//	printf("%d\n", a);
//	return 0;
//}

//int main()
//{
//	int a, b, ret=1, sum=0;
//	
//	for (a = 1; a <= 4; a++)
//	{
//		for (b = 1; b <= a; b++)
//		{
//			ret = ret * b;
//		}
//		sum = sum + ret;
//	}
//	printf("%d", sum);
//
//	return 0;
//}
// int main()
//{
//	/*int i = 0, a = 0;
//	while (i < 20)
//	{
//		for (;;)
//		{
//			if ((i % 10) == 0) break;
//			else i--;
//		}
//		i += 11; a += i;
//	}
//	printf("%d\n", a);*/
//	/*int k = 1;
//	while (!k == 0)
//	{
//		k = k + 1;
//		printf("%d\n", k);
//	}*/
//	/*int x = 0, y = 0;
//	while (x < 15)
//		y++, x += ++y;
//
//	printf("%d,%d", y, x);*/
//	int a, b;
//	for (a = 1, b = 1; a <= 100; a++)
//	{
//		if (b >= 20)break;
//		if (b % 3 == 1)
//		{
//			b += 3;  continue;
//		}
//		b -= 5;
//	}printf("%d%d", a, b);
//	/* int  x, i;
//	 for (i = 1, x = 1; i <= 50; i++)
//	 {
//		 if (x >= 10)break;
//		 if (x % 2 == 1)
//		 {
//			 x += 5; continue;
//		 }
//		 x -= 3;
//	 }
//	 printf("%d\n", i);
//	 return 0;*/
//
//	return 0;
//}
//int gcd(int a, int b)
//{
//    int t;
//    t = a > b ? b : a;
//    do
//    {
//        t--;
//    } while (b % t != 0 && a % t != 0);
//    return t;
//}
//int lcm(int a, int b)
//{
//    int t;
//    t = a > b ? a : b;
//    do
//    {
//        t++;
//    } while ((a * b) % t != 0);
//    return t;
//}
//int main(void)
//{
//    /*********Begin*********/
//    int m, n, a, b;
//    scanf("%d %d", &m, &n);
//    a = gcd(m, n);
//    b = lcm(m, n);
//    printf("最大公约数是:%d", a);
//    printf("最小公倍数是:%d", b);
//    /*********End**********/
//    return 0;
//}
//int main()
//{
//	int n,i=0; float sum=0,m;
//	scanf("%d", &n);
//	if (n <= 0) printf("oooooo");
//	else 
//	{
//		for (i; i <= n; i++)
//		{
//			scanf("%f", &m);
//			sum += m;
//		}
//		printf("%f", sum);
//
//		return 0;
//	}
//
//
//}
//void fun(int p)
//{
//	int d = 2;
//	p = d++;
//	printf("%d", p);
//}
//int main()
//{
//	int a = 1;
//	fun(a);
//	printf("%d", a);
//	return 0;
//}
//int f(int x, int y)
//{
//	if (x != y) return (x + y) / 2;
//	else return x;
//
//}
//int main()
//{
//	int a = 4, b = 5, c = 6;
//	printf("%d", f(2 * a, f(b, c)));
//	return 0;
//}
//int main(void)
//{
//    int n, i, j, sum = 0;
//    scanf("%d", &n);
//    for (i = 1; i <= n; i++)
//    {
//        sum = 0;
//        for (j = 1; j < i; j++)
//        {
//            if (i % j == 0)
//            {
//                sum += j;
//            }
//        }
//        if (sum == i)
//        {
//            printf("%d", i);
//            printf("\n");
//        }

  /*  }
    return 0;
}*/
//#include <string.h>
//#include <windows.h>
//int main()
//{
//	char arr1[] = "welcome to bite";
//	char arr2[] = "###############";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);
//		left++; right--;
//	}
//	return 0;
//
//}
//int main()
//{
//	int i;
//	char password[] = "123456";
//	for (i = 1; i < 4; i++)
//	{
//		printf("请输入密码:");
//		scanf("%s", password);
//		if (strcmp(password, "123456")==0)
//		{
//			printf("输入正确");
//			break;
//		}
//		else
//			printf("密码输入错误\n");
//	}
//	if (i == 4)
//		printf("错误输入三次，退出登入");
//	return 0;
//}return
#include <windows.h>
#include <stdlib.h>

//void menu()
//{
//	printf("***************************\n");
//	printf("********  1.play  *********\n");
//	printf("********  2.exit  *********\n");//间接显示
//	printf("***************************\n");
//}
//void game()
//{
//	
//	int ret = rand()%100+1;//rand范围为0~32829，
//	printf("%d\n", ret);
//	int guess;
//	
//	while (1)
//	{
//		scanf("%d", &guess);
//		if (guess > ret)
//			printf("猜大了\n");
//		else if (guess<ret)
//			printf("猜小了\n");
//		else
//		{
//			printf("恭喜你，答对了\n");
//			break;
//		}
//	}
//}
//int main()
//
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请输入:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 2:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误，重新选择\n"); 
//			break;
//		}
//
//	} while(input);
//	return 0;
//}
//void menu()
//{
//	printf("***************************\n");
//	printf("********  1.play  *********\n");
//	printf("********  2.exit  *********\n");//间接显示
//	printf("***************************\n");
//}
//void game()
//{
//	int ret = rand() % 100 + 1;
//	printf("%d\n",ret);
//	int guess = 0 ;
//	while (1)
//	{
//		scanf("%d", &guess);
//		if(guess < ret)
//			printf("猜小了\n");
//		else if (guess > ret)
//			printf("猜大了\n");
//		else
//		{
//			printf("恭喜你，答对了\n");
//			break;
//		}
//	}
//}
//int main()
//{
//	
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请输入：>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default :
//			printf("输入错误\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
  

//int main()
//{
//	int a=0, b=0, c=0;
//	scanf("%d %d %d\n", &a, &b, &c);
//	if (a < b)
//	{
//		int temp = a;
//		a = b;
//		b = temp;
//	}
//	if (a < c)
//	{
//		int temp = a;
//		a = c;
//		c = temp;
//	}
//	if (b < c)
//	{
//		int temp = b;
//		b = c;
//		c = temp;
//	}
//
//
//	printf("%d %d %d\n", a, b, c);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int year, month, day;
//	scanf("%d %d %d", &year, &month, &day);
//
//	return 0;
//}
//int main()
//{
//    /********* Begin *********/
//    char a[100], b[100], c[100]; int i, j = 0, m = 0;
//    gets(a);
//    for (i = 0; a[i]; i++)
//    {
//        if (a[i] >= '0' && a[i] <= '9') b[j++] = a[i];
//        if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z'))
//            c[m++] = a[i];
//    }
//    b[j] = 0;
//    c[m] = 0;
//    printf("the number array: ");
//    puts(b);
//    printf("the letter array: ");
//    puts(c);
//
//    /********* End *********/
//    return 0;
//}
//int main()
//{
//	int i;
//	for (i = 0; i <= 100; i+=3)
//	{
//		//if (i % 3 == 0)
//			printf("%d\n", i);
//	}
//	return 0;
//}
//int main()
//{
//	int m=0, n=0, min=0,i;
//	scanf("%d %d", &m, &n);
//	//min = (m < n) ? m : n;
//	/*for ( min; min > 0; min--)
//	{
//		if (m % min==0 && n % min==0)
//		{
//			printf("最大公约数是%d\n", min);
//			break;
//		}
//	}*/
//	/*while (1)
//	{
//		if (m % min == 0 && n % min == 0)
//		{
//			printf("%d", min);
//			break;
//		}
//		min--;
//	}*/
//	/*int c=0;
//	while (m%n)
//	{
//		c = m % n;
//		m = n ;
//		n = c;
//
//	}
//	printf("%d", n);*/
//	return 0;
//}
//int main()
//{
//	int year;
//	for (year = 1000; year < 2001; year++)
//	/*
//		if (year % 4 == 0)
//			if (year % 100 != 0)
//				printf("%d\n", year);
//		if (year % 400 == 0)
//			printf("%d\n", year);
//	}*/
//	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
//		printf("%d", year);
//	return 0;
//}
//int  main()
//{
//	int i;
//	for (i = 100; i < 201; i++)
//	{
//		int j = 0;
//		for (j = 2; j < i; j++)
//		{
//			if (i % j == 0)
//				break;
//		}
//		if (i == j)
//			printf("%d   ", i);
//	}
//	return 0;
//}
//int main()
//{
//	int i;
//	int count = 0;
//	for (i = 100; i < 201; i++)
//	{
//		int j=0;
//		int flag = 1;
//		for (j = 2; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 1)
//		{
//			printf("%d\n", i);
//			count++;
//		}
//		
//	}
//		printf("%d\n", count);
//	return 0;
//}
//int main()
//{
//	int i;
//		int count = 0;
//		for (i = 101; i < 201; i+=2)//素数绝不可能是偶数
//		{
//			int j=0;
//			int flag = 1;
//			for (j = 2; j < i; j++)
//			{
//				if (i % j == 0)
//				{
//					flag = 0;
//					break;
//				}
//			}
//			if (flag == 1)
//			{
//				printf("%d\n", i);
//				count++;
//			}
//			
//		}
//			printf("%d\n", count);
//	return 0;
//}
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 120");
//again:
//	printf("请输入，我是猪。否则关机\n");
//	scanf("%s", input);
//	if (strcmp(input, "我是猪")==0)
//	{
//		system("shutdown -a");
//	}
//	else
//		goto again;
//	return 0;
//}

//int main()
//{
//	char a[100] = {0};
//	char b[] = "HELLO WORLD !";
//	/*strcpy(a, b);
//	printf("%s\n", a);*/
//	memset(b, 'H', 5);
//	printf("%s", b);
//
//	return 0;
//}

//int get_max(int x, int y)
//{
//	int z;
//	if (x > y)
//		z = x;
//	else
//		z = y;
//	return z;
//}
//
//int main()
//{
//	int a=34, b=63;
//	int max = get_max(a, b);
//	printf("max=%d", max);
//	return 0;
//}

//void Swap(int *x,int *y)
//{
//	int temp=0;
//	temp=*x;
//	*x = *y;
//	*y = temp;
//}
//int main()
//{
//	int a = 12;
//	int b = 45;
//	printf("%d %d\n", a, b);
//	Swap(&a, &b);
//	printf("%d %d", a, b);
//	return  0;
//}



//long fibo(long n)
//{
//	
//	long t;
//	if (n == 1 || n == 2)
//		t = 1;
//	else
//		t = fibo(n - 1) + fibo(n - 2);
//	return t;
//}
//long  main()
//{
//	long n;
//	printf("please input n(n>=1):");
//	scanf("%ld", &n);
//	printf("fibo(%ld)=%ld\n", n, fibo(n));
//	return 0;
//}
//int fac(int n)
//{
//	int i,t=1;
//	for (i = 1; i <= n; i++)
//	{
//		t = t * i;
//	}
//	return t;
//}
//int main()
//{
//	int m, n,C;
//	printf("please input number m,n:");
//	scanf("%d%d", &m, &n);
//	C = fac(m);
//	printf("C(%d %d)=%d", m, n, C);
//	return 0;
//}

//leap_year(int y)
//{
//	if (y % 4 == 0 && y % 100 != 0)
//		return 1;
//	else if (y % 400 == 0)
//		return 1;
//	else
//	return 0;
//}
//
//int main()
//{
//	int y=0;
//	int count = 0;
//	for (y = 1000; y < 2001; y++)
//	{
//		if (leap_year(y) == 1)
//		{
//			printf("%d ", y);
//			count++;
//		}
//		
//	}
//	printf("%d", count);
//	return 0;
//}

//int binary_search(int a[], int k, int s)
//{
//	int left = 0;
//	int right = s - 1;
//	
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (a[mid] > k)
//			right = mid - 1;
//		else if (a[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int key = 5;
//	
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = binary_search(arr, key, sz);
//	if (ret == -1)
//	{
//		printf("找不到");
//	}
//	else
//	{
//		printf("找到了，下标是：%d", ret);
//	}
//	return 0;
//}

//int binary_search(int a[], int k,int s)
//{
//	int left = 0;
//	int right = s - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (a[mid] > k)
//			right = mid - 1;
//		else if (a[mid] < k)
//			left = mid - 1;
//		else
//			return mid;
//		return -1;
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int key = 5;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = binary_search(arr,key,sz);
//	if (ret == -1)
//		printf("找不到");
	/*else
		printf("找到了，下标是:%d",ret);
	return 0;
}*/

//void one()
//{
//	printf("hehe\n");
//}
//void three_printf()
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//		one
//	return 0;
//}
//int main()
//{
//	three_printf();
//	return 0;
//}
////int main()
//{
//	/*char arr1[45] = { 1 };
//	char arr2[] = "hehe";
//	printf("%s", strcpy(arr1, arr2));*/
//	//printf("%d", printf("%d", printf("%d",43)));
//	return 0;
//}

//#include<stdio.h>
//#define N 5
//struct simulate
//{
//    char name[10];          //选手姓名
//    char number[10];        //选手编号
//    char nationality[10];   //选手国籍
//    float score;              //选手得分
//    float grade[7];           //各位评委评分
//} sim[5];           //选手数组
//int main()
//{
//    int i, j, f;
//    float x = 0;
//    float max = 0, min = 11;
//    struct simulate sim[N];
//    for (i = 0; i < 4; i++)
//    {
//        scanf("%s %s %s %f", sim[6].name, sim[6].number, sim[6].nationality, sim[6].grade);
//
//        for (j = 0; j < 7; j++)
//        {
//            if (sim[6].grade[j] > max)
//                max = sim[6].grade[j];
//            if (sim[6].grade[j] < min)
//                min = sim[6].grade[j];
//            sim[6].score += sim[6].grade[j];
//        }
//        sim[6].score = sim[6].score - max - min;
//    }
//    float tem;
//    for (i = 0; i < 4; i++)
//    {
//        for (j = 0; j < 4; j++)
//            if (sim[6].score < sim[6].score)
//            {
//                tem = sim[6].score;
//                sim[6].score = sim[6].score;
//                sim[6].score = tem;
//            }
//    }
//    for (f = 0; f < 3; f++)
//    {
//        printf("%s,%s,%s,%.2f\n", sim[6].name[f], sim[6].number[f], sim[6].nationality[f], sim[6].score);
//    }
//    return 0;
//}


//#include<stdio.h>
//#include<string.h>
//#define N 5
//struct simulate
//{
//    char name[10];          //选手姓名
//    char number[10];        //选手编号
//    char nationality[10];   //选手国籍
//    float score;           //选手得分
//    float grade[7];           //各位评委评分
//} sim[5];           //选手数组
//int main()
//{
//    int i, j, f;
//    float x = 0;
//    float max, min;
//    struct simulate temp1;
//    /*********Begin*********/
//    //录入5位选手信息以及评委评分
//   /* for (i = 0; i < N; i++)
//    {
//        x = 0;
//        scanf("%s%s%s", sim[i].name, sim[i].number, sim[i].nationality);
//        for (j = 0; j < 7; j++)
//        {
//            scanf("%f", &sim[i].grade[j]);
//            x += sim[i].grade[j];
//        }
//        max = sim[i].grade[0];
//        min = sim[i].grade[0];
//        for (f = 0; f < 7; f++)
//        {
//            if (max < sim[i].grade[f])
//                max = sim[i].grade[f];
//            if (min > sim[i].grade[f])
//                min = sim[i].grade[f];
//        }
//        sim[i].score = x - (max + min);
//    }
//    for (i = 0; i < N; i++)
//    {
//        for (j = i + 1; j < N; j++)
//        {
//            if (sim[i].score < sim[j].score)
//            {
//                strcpy(temp1.name, sim[i].name);
//                strcpy(sim[i].name, sim[j].name);
//                strcpy(sim[j].name, temp1.name);
//
//                strcpy(temp1.number, sim[i].number);
//                strcpy(sim[i].number, sim[j].number);
//                strcpy(sim[j].number, temp1.number);
//
//                strcpy(temp1.nationality, sim[i].nationality);
//                strcpy(sim[i].nationality, sim[j].nationality);
//                strcpy(sim[j].nationality, temp1.nationality);
//
//
//                temp1.score = sim[i].score;
//                sim[i].score = sim[j].score;
//                sim[j].score = temp1.score;
//            }
//        }
//    }
//    for (i = 0; i < 3; i++)
//    {
//        printf("%s,%s,%s,%.2f\n", sim[i].name, sim[i].number, sim[i].nationality, sim[i].score);
//    }*/
//    for (i = 0; i < N; i++)
//    {
//        x = 0;
//        scanf("%s%s%s", sim[i].name, sim[i].number, sim[i].nationality);
//
//        for (j = 0; j < 7; j++)
//        {
//            scanf("%f", sim[i].grade[j]);
//        }
//        max = 0; min = 10;
//        for (f = 0; f < 7; f++)
//        {
//            if (max < sim[i].grade[f])
//                max = sim[i].grade[f];
//            if (min > sim[i].grade[f])
//                min = sim[i].grade[f];
//            x += sim[i].grade[f];
//        }
//        sim[i].score = x - max - min;
//
//    }
//    for (i = 0; i < 5; i++)
//    {
//        for (j = i + 1;j < 5; j++)
//        {
//            if (sim[i].score < sim[j].score)
//            {
//                temp1 = sim[i];
//                sim[i] = sim[j];
//                sim[j] = temp1;
//            }
//        }
//    }
//    for (f = 0; f < 3; f++)
//    {
//        printf("%s,%s,%s,%.2f", sim[f].name[f], sim[f].number[f], sim[f].nationality[f], sim[f].score);
//    }
//    return 0;
//}



//#include <stdio.h>
//
//int main()
//
//{
//
//	int i, j, k, l, m;
//
//	char c = 3; //ASCII码里面 3 就是一个字符小爱心
//
//	for (i = 1; i <= 5; i++) printf("\n"); //开头空出5行
//
//	for (i = 1; i <= 3; i++) { //前3行中间有空隙分开来写
//
//		for (j = 1; j <= 32 - 2 * i; j++) printf(" "); //左边的空格，每下一行左边的空格比上一行少2个 //8*n-2*i
//
//		for (k = 1; k <= 4 * i + 1; k++) printf("%c", c);//输出左半部分字符小爱心
//
//		for (l = 1; l <= 13 - 4 * i; l++) printf(" "); //中间的空格，每下一行的空格比上一行少4个
//
//		for (m = 1; m <= 4 * i + 1; m++) printf("%c", c);//输出右半部分字符小爱心
//
//		printf("\n"); //每一行输出完毕换行
//
//	}
//
//	for (i = 1; i <= 3; i++) { //下3行中间没有空格
//
//		for (j = 1; j <= 24 + 1; j++) printf(" "); //左边的空格 //8*(n-1)+1
//
//		for (k = 1; k <= 29; k++) printf("%c", c);//输出字符小爱心
//
//		printf("\n"); //每一行输出完毕换行
//
//	}
//
//	for (i = 7; i >= 1; i--) { //下7行
//
//		for (j = 1; j <= 40 - 2 * i; j++) printf(" "); //左边的空格，每下一行左边的空格比上一行少2个//8*(n+1)-2*i
//
//		for (k = 1; k <= 4 * i - 1; k++) printf("%c", c);//每下一行的字符小爱心比上一行少4个（这个循环是i--）
//
//		printf("\n"); //每一行输出完毕换行
//
//	}
//
//	for (i = 1; i <= 39; i++) printf(" "); //最后一行左边的空格
//
//	printf("%c\n", c); //最后一个字符小爱心
//
//	for (i = 1; i <= 5; i++) printf("\n"); //最后空出5行
//
//	return 0;
//
//}

//#include<stdio.h>
//#include<string.h>
//
//typedef struct name {
//    char a[10];
//}B;
//
//
//int main()
//{
//
//    B b[3] = { {"Li"},{"Sun"},{"Zhang"} };
//    int  i,e, j = 0, k = 0, m = 0;
//
//    int n;
//    scanf("%d\n", &n);
//    char name1[20];
//    for (i = 0; i < n; i++)
//    {
//        scanf("%s", name1);
//        for (e = 0; e < 3; e++)
//        {
//            if (strcmp(name1, b[0].a) == 0)
//                j++;
//            if (strcmp(name1, b[1].a) == 0)
//                k++;
//            if (strcmp(name1, b[2].a) == 0)
//                m++;
//        }
//    }
//    printf("Li:%d\n", j);
//    printf("Zhang:%d\n", m);
//    printf("Sun:%d\n", k);
//    return 0;
//}
//union myun { struct { int x, y, z; } u; int k; } a;
//
//int main()
//
//{
//	a.u.x = 4;
//	a.u.y = 5;
//	a.u.z = 6;
//	a.k = 0;
//	printf("%d\n", a.u.x);
//}
//void main()
//
//{
//
//	struct cmplx { int x; int y; }cnum[2] = { 1,3,2,7 };
//
//	printf("%d\n", cnum[0].x );
//	printf("%d\n", cnum[0].y );
//	printf("%d\n",  cnum[1].x);
//	printf("%d\n",  cnum[1].y);
//}
//#include<stdio.h>
//
//struct STU
//
//{
//
//	char name[9], sex; double score[2];
//
//};
//
//void  main()
//
//{
//
//	struct STU a = { "zhao",'m',85.0,90.0}, b = {"Qian",'f',95.0,92.0};
//
//	b = a;
//
//	printf("%s,%c,%2.0f,%2.0f\n", b.name, b.sex, b.score[0], b.score[1]);
//
//}


//void fun(int p)
//{
//	int q = 2;
//	p = q++;
//	printf("%d\n", p);
//}
//
//int main()
//{
//	int a = 1;
//	fun(a);
//	printf("%d\n", a);
//}

//int fun(int n)
//{
//	static int b = 1;
//	n += b++;
//	return n;
//}
//int main()
//{
//	int a = 3, s;
//	s = fun(a);
//	s = s + fun(a);
//	printf("%d\n", s);
//}
//
//# define SIZE 11
//int main()
//{
//	int x, vote[10] = { 0 };
//	printf("please input number；");
//		scanf("%d", &x);
//	while (x != -1)
//	{
//		if (x >= 1 && x < 11)
//			vote[x]++;
//		scanf("%d", &x);
//	}
//	for (x = 1; x < 11; x++)
//		printf("第%d个人票数:%3d\n", x, vote[x]);
//	return 0;
//}
\

//#define SIZE 10
//
//void displayArray(int a[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		if (i != len)	
//			printf("%d\t", a[i]);
//		else	
//			printf("%d\n", a[i]);
//	}
//}
//void selectsort(int a[], int len)
//{
//	int i;
//	int j;
//	int k;
//	for (i = 0; i < len - 1; i++)
//		for (j = i + 1; j < len; j++)
//		
//			if(a[i]>a[j])
//			{ 
//			k = a[i];
//			a[i] = a[j];
//			a[j] = k;
//			}
//}
//void main()
//{
//	int a[SIZE] = { 24,56,8,47,63,82,27,15,90,39 };
//	printf("Before sorting:\n");
//	displayArray(a, SIZE);
//	selectsort(a, SIZE);
//	printf("After sorting:\n");
//	displayArray(a,SIZE);
//
//}

//# include "add.h"
//# include "sub.h"
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = Add(a, b);
//	int d = Sub(a, b);
//	printf("%d\n", d);
//	printf("%d\n", c);
//	return 0;
//}

//#include "sub.h"
//#pragma comment(lib,"sub.lib")
// int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = Sub(a, b);
//	printf("%d", c);
//	return 0;
//}

//int main()
//{
//	printf("hehe");
//	main();//会栈溢出
//	return 0;
//}

void print(unsigned int n)
{
	if (n > 9)
	{
		print(n / 10);
	}
	printf("%d ", n % 10);
}
int main()
{
	unsigned int num = 0;
	scanf("%u", &num);
	print(num);
	return 0;
}