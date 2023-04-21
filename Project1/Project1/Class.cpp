//#include "Class.h"
//
//#include <iostream>
//using namespace std;
//#include <string.h>
//
//typedef char DataType;
//
//
////��������Ԫ�ؽṹ
//typedef struct node
//{
//    DataType info;
//    struct node* next;
//}QueueData;
//
//typedef struct queueRecord {
//    QueueData* front, * rear;
//}LINKQUEUE;
//
//typedef struct queueRecord* PLinkQueue;
//
//PLinkQueue createEmptyQueue_link()
//{
//    //����һ���ն��У�ʵ�ʣ�����һ��LINKQUEUE���͵Ľ�㣬����front �� rear ��Ա��ֵ
//     //���ڴ˴���д���룬�����Ӧ����
//     /*-------begin----------*/
//
//    PLinkQueue p;
//    p->front = p->rear = 0;
//    return p;
//    /*-------end----------*/
//
//}
//
//int isEmptyQueue_link(PLinkQueue  queue)
//{ //�ж������Ƿ�Ϊ�գ�ʵ�ʣ� �����е�frontָ���Ƿ�Ϊ�գ���Ϊ�գ������Ϊ��
//
//  //���ڴ˴���д���룬�����Ӧ����
//    /*-------begin----------*/
//    if (queue->front = queue->rear = 0)
//        return 1;
//    else
//        return 0;
//
//
//    /*-------end----------*/
//}
//
//void enQueue_link(DataType x, PLinkQueue queue)
//{
//    //������Ԫ��x�����β��ʵ�ʣ�����һ��struct node���͵Ľ�㣬������Ӧ��Ա��ֵ������β
//     //���ڴ˴���д���룬�����Ӧ����
//     /*-------begin----------*/
//    QueueData* p = new QueueData;
//    p->info = x;
//    //queue->front = p;
//
//    p->next = 0;
//    queue->rear->next = 0;
//    queue->rear = p;
//
//
//     /*-------end----------*/
//}
//
//void enQueue_link(QueueData* p, PLinkQueue Q)
//{
//    //�������Ĺ����ǽ� struct node ���͵Ľ������β����enQueue_link(DataType x, PLinkQueue queue)�������ǣ�����Ҫ���ɽ��
//
//       //���ڴ˴���д���룬�����Ӧ����
//      /*-------begin----------*/
//    p->next = 0;
//    Q->rear->next = p;
//    Q->rear = p;
//
//
//      /*-------end----------*/
//
//}
//
//DataType deQueue_link(PLinkQueue Q)
//{
//    //���ӣ�ʵ�ʣ� ȡ��Q���еĶ��׽�㣬���ظý�������Ԫ�أ������ý��ʹ��enQueue_link(QueueData *p,PLinkQueue Q)�����β
//    //������Ϊ��Ա�ʵ��������ƣ���ʵ����Կ��ѭ��ʹ��
//    //���ڴ˴���д���룬�����Ӧ����
//   /*-------begin----------*/
//    QueueData* k = Q->front->next;
//    char l;
//    l = k->info;
//    Q->front->next = k->next;
//    enQueue_link(k, Q);
//    return l;
//
//
//
//   /*-------end----------*/
//
//}
//
//void decrypt(char src[], char key[], char dest[])
//{
//    /*  ������ src �ŵ���Դ�� �� key �ŵ�����Կ �� dest �ż��ܺ������
//       ���ܺ����� ������ʾ
//       1. ��ʼ��һ���ն���Q
//       2. ��key�����Ԫ������������Q
//       3. �������src�����Դ�ģ������ܣ� ʹ��deQueue_link(Q)�����ɵõ�������Կ����ʹ��Կѭ��ʹ��
//    */
//    PLinkQueue p;
//    PLinkQueue createEmptyQueue_link();
//    int i=0;
//    while (key[i++] = '\0')
//    {
//        enQueue_link(key[i], p);
//    }
//    if (isEmptyQueue_link(p))
//        exit(0);
//    i = 0;
//    while (src[i++] = '\0')
//    {
//        deQueue_link(p);
//        dest[i] = src[i] + key[i] - '0';
//
//    }
//    dest[i] = '\0';
//}
//
//int main(void)
//{
//    char src[80], key[20], dest[80];
//
//    cin >> src;
//
//    cin >> key;
//    decrypt(src, key, dest);
//    cout << dest;
//}
//
//
//





//#include "Class.h"

#include <iostream>
using namespace std;
#include <string.h>

typedef char DataType;


//��������Ԫ�ؽṹ
typedef struct node
{
    DataType info;
    struct node* next;
}QueueData;

typedef struct queueRecord {
    QueueData* front, * rear;
}LINKQUEUE;

typedef struct queueRecord* PLinkQueue;

PLinkQueue createEmptyQueue_link()
{
    //����һ���ն��У�ʵ�ʣ�����һ��LINKQUEUE���͵Ľ�㣬����front �� rear ��Ա��ֵ
     //���ڴ˴���д���룬�����Ӧ����
     /*-------begin----------*/

    PLinkQueue p;
    p = new queueRecord;
    p->front = new QueueData;
    //p->front = p->rear = NULL;
    p->front = p->rear;
    p->front->next = NULL;
    return p;
    /*-------end----------*/

}

int isEmptyQueue_link(PLinkQueue  queue)
{ //�ж������Ƿ�Ϊ�գ�ʵ�ʣ� �����е�frontָ���Ƿ�Ϊ�գ���Ϊ�գ������Ϊ��

  //���ڴ˴���д���룬�����Ӧ����
    /*-------begin----------*/
    if (queue->front->next = 0)
        return 1;
    else
        return 0;


    /*-------end----------*/
}

void enQueue_link(DataType x, PLinkQueue queue)
{
    //������Ԫ��x�����β��ʵ�ʣ�����һ��struct node���͵Ľ�㣬������Ӧ��Ա��ֵ������β
     //���ڴ˴���д���룬�����Ӧ����
     /*-------begin----------*/
    QueueData* w = new QueueData;
    w->info = x;
    //queue->front = p;

    w->next = NULL;
    queue->rear->next = w;
    queue->rear = w;


    /*-------end----------*/
}

void enQueue_link(QueueData* p, PLinkQueue Q)
{
    //�������Ĺ����ǽ� struct node ���͵Ľ������β����enQueue_link(DataType x, PLinkQueue queue)�������ǣ�����Ҫ���ɽ��

       //���ڴ˴���д���룬�����Ӧ����
      /*-------begin----------*/
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;


    /*-------end----------*/

}

DataType deQueue_link(PLinkQueue Q)
{
    //���ӣ�ʵ�ʣ� ȡ��Q���еĶ��׽�㣬���ظý�������Ԫ�أ������ý��ʹ��enQueue_link(QueueData *p,PLinkQueue Q)�����β
    //������Ϊ��Ա�ʵ��������ƣ���ʵ����Կ��ѭ��ʹ��
    //���ڴ˴���д���룬�����Ӧ����
   /*-------begin----------*/
    QueueData* k = Q->front->next;
    char l;
    l = k->info;
    Q->front->next = k->next;
    enQueue_link(k, Q);
    return l;



    /*-------end----------*/

}

void decrypt(char src[], char key[], char dest[])
{
    /*  ������ src �ŵ���Դ�� �� key �ŵ�����Կ �� dest �ż��ܺ������
       ���ܺ����� ������ʾ
       1. ��ʼ��һ���ն���Q
       2. ��key�����Ԫ������������Q
       3. �������src�����Դ�ģ������ܣ� ʹ��deQueue_link(Q)�����ɵõ�������Կ����ʹ��Կѭ��ʹ��
    */
    PLinkQueue p;
    PLinkQueue createEmptyQueue_link();
    int i = 0;
    while (key[i] = '\0')
    {
        enQueue_link(key[i], p);
        i++;
    }
    if (isEmptyQueue_link(p))
        exit(0);
    i = 0;
    while (src[i] = '\0')
    {
        deQueue_link(p);
        dest[i] = src[i] + key[i] - '0';
        i++;
    }
    dest[i] = '\0';
}

int main(void)
{
    char src[80], key[20], dest[80];

    cin >> src;

    cin >> key;
    decrypt(src, key, dest);
    cout << dest;
}



