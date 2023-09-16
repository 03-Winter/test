#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>

//int main()
//{
//	int n; 
//	scanf("%d", &n);
//	int i = 0,a=n;
//	for (i = 31; i >= 1; i -= 2)
//	{
//		a = (n >> i) & 1;
//		printf("%d ", a);
//	}
//
//	printf("\n");
//	for (i = 30; i >= 0; i-=2)
//	{
//		a = (n >> i) & 1;
//		printf("%d ", a);
//	}
//}

//
//int mian()
//{
//
//	return 0;
//}


//方法一
//#include <stdio.h>
//
//double max1(int j, int k, int l)
//{
//    double max = 0;
//    max = (j + k) > k ? (j + k) : k;
//    max = max > l ? max : l;
//    return max;
//}
//double max2(int j, int k, int l)
//{
//    double max = 0;
//    max = (k + l) > j ? (l + k) : j;
//    max = max > l ? max : l;
//    return max;
//}double max3(int j, int k, int l)
//{
//    double max = 0;
//    max = k > j ? k : j;
//    max = max > (k + l) ? max : (k + l);
//    return max;
//}
//int main() {
//    int j, k, l;
//    double a, b, c;
//    scanf("%d%d%d", &j, &k, &l);
//    double m = 0;
//    a = max1(j, k, l);
//    b = max2(j, k, l);
//    c = max3(j, k, l);
//    m = a / (b + c);
//    printf("%.2lf", m);
//    return 0;
//}


//方法二
//int max(int j, int k, int l)
//{
//    int max = 0;
//    max = j > k ? j : k;
//    max = max > l ? max : l;
//    return max;
//}
//int main() {
//    int j, k, l;
//    double a, b, c;
//    scanf("%d%d%d", &j, &k, &l);
//    double m = 0;
//    // a=max1(j,k,l); 
//    // b=max2(j,k,l);
//    // c=max3(j,k,l);  
//    //m= a/(b+c);
//    m = max(j + k, k, l) * 1.00 / (max(j, (k + l), l) + max(j, k, (k + l)));
//    printf("%.2lf", m);
//    return 0;
//}