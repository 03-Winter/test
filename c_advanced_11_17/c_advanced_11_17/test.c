#define _CRT_SECURE_NO_WARNINGS  1
#include"Parking.h"
//ȫ�ֱ��� n��ʾ�û�����ͣ����ͣ�ŵĳ�  cost�γ�ͣ���ѣ�truck������VANС����
int cost = 5, j = 0, k = 0, truck = 15, van = 10;
int main()
{
	int car, time = 1;//  time���ʱ�� 
	char ch = ' ';//����״̬��ʻ���ʻ������  car ���ƺ� 
	char type;
	char eat;
	park sc;//ͣ���� 
	Initpark(&sc);
	sidewalkLink swl;//���
	InitWaitCarLink(&swl);
	//sidewalk* wc;//�����ڵ�ָ�� 
	while (ch != 'E')
	{
		printf("\n�����복��״̬��Aʻ��,Dʻ�������������ͣ����ƺţ�ʻ�����ʻ����ʱ�䣺");
		printf("\n����A t 2 5");
		printf("\ncΪ�γ���tΪ������vΪС��������Сд����\n");
		scanf("%c %c %d %d", &ch, &type, &car, &time);
		if (ch == 'A')
			ArrivalCar(&sc, &swl, ch, type, car, time);
		else if (ch == 'D')
		{
			outcar(&sc, ch, type, car, time);
			WaitTopark(&sc, &swl);//����Ҫ�жϳ�����û�г�����ִ�г����ʱ�򣬳����Ѿ���λ���� 
		}
		else {
			printf("��������ȷ�ı��,A��ʻ�룬D��ʻ����\n");
		}
		printf("\n�����˳�������E 0 0 0\n");
		eat = getchar();//�����̵����з�		
	}
	return 0;
}
