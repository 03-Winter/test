#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
//int main()
//{
//    long long n, arr[100001] = { 0 };
//    scanf("%lld", &n);
//    int sum = 0;
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%lld", &arr[i]);
//        sum += arr[i];
//    }
//    int flag = 0, sume = 0, min = 0;
//    for (int j = 0; j < n; j++)
//    {
//        if (arr[j] >= 2)
//        {
//            flag = arr[j];
//        }
//        if (min >= arr[j] && arr[j] >= 2)
//        {
//            min = arr[j];
//        }
//    }
//    for (int j = 0; j < n; j++)
//    {
//        if (flag == 0)
//        {
//            if (sum == 0)
//            {
//                printf("0");
//                break;
//            }
//            else {
//                printf("1");
//                break;
//            }
//        }
//        else
//        {
//            for (int i = 0; i < n; i++)
//            {
//                arr[j] = arr[j + 1] % min;
//                sume += arr[j];
//            }
//            if (sume == 0)
//            {
//                printf("1");
//                break;
//            }
//            else {
//                printf("2");
//                break;
//            }
//        }
//    }
//    return 0;
//}

int Gcd(int a, int b)
{
	return b > 0 ? Gcd(b, a % b) : a;
}
int main()
{
	int n, cnt01 = 0, cnt0 = 0, gcd,a;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		gcd = Gcd(gcd, a);
		if (a == 1)
			cnt01++;
		if (a == 0)
		{
			cnt01++;
			cnt0++;
		}
			
	}
	for(int j = 0; j < n; j++)
	{
		if (cnt0 == n)
		{
			printf("0");
			break;
		}
		else if (cnt01 = n || gcd > 1)
		{
			printf("1");
			break;
		}
		else
		{
			printf("2");
			break;
		}
	}
	return 0;
}

