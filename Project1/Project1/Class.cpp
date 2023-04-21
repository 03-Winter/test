//#include "Class.h"
//
//#include <iostream>
//using namespace std;
//#include <string.h>
//
//typedef char DataType;
//
//
////队列数据元素结构
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
//    //创建一个空队列，实质：生成一个LINKQUEUE类型的结点，并给front 和 rear 成员赋值
//     //请在此处填写代码，完成相应功能
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
//{ //判定队列是否为空，实质： 看队列的front指针是否为空，若为空，则队列为空
//
//  //请在此处填写代码，完成相应功能
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
//    //将数据元素x插入队尾。实质：生成一个struct node类型的结点，并给相应成员赋值后插入队尾
//     //请在此处填写代码，完成相应功能
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
//    //本函数的功能是将 struct node 类型的结点插入队尾，与enQueue_link(DataType x, PLinkQueue queue)的区别是，不需要生成结点
//
//       //请在此处填写代码，完成相应功能
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
//    //出队，实质： 取出Q队列的队首结点，返回该结点的数据元素，并将该结点使用enQueue_link(QueueData *p,PLinkQueue Q)插入队尾
//    //本函数为针对本实验特殊设计，可实现秘钥的循环使用
//    //请在此处填写代码，完成相应功能
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
//    /*  参数： src 放的是源文 ； key 放的是秘钥 ； dest 放加密后的密文
//       加密函数： 步骤提示
//       1. 初始化一个空队列Q
//       2. 将key数组的元素逐个插入队列Q
//       3. 逐个访问src数组的源文，并加密， 使用deQueue_link(Q)函数可得到队首秘钥，并使秘钥循环使用
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


//队列数据元素结构
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
    //创建一个空队列，实质：生成一个LINKQUEUE类型的结点，并给front 和 rear 成员赋值
     //请在此处填写代码，完成相应功能
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
{ //判定队列是否为空，实质： 看队列的front指针是否为空，若为空，则队列为空

  //请在此处填写代码，完成相应功能
    /*-------begin----------*/
    if (queue->front->next = 0)
        return 1;
    else
        return 0;


    /*-------end----------*/
}

void enQueue_link(DataType x, PLinkQueue queue)
{
    //将数据元素x插入队尾。实质：生成一个struct node类型的结点，并给相应成员赋值后插入队尾
     //请在此处填写代码，完成相应功能
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
    //本函数的功能是将 struct node 类型的结点插入队尾，与enQueue_link(DataType x, PLinkQueue queue)的区别是，不需要生成结点

       //请在此处填写代码，完成相应功能
      /*-------begin----------*/
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;


    /*-------end----------*/

}

DataType deQueue_link(PLinkQueue Q)
{
    //出队，实质： 取出Q队列的队首结点，返回该结点的数据元素，并将该结点使用enQueue_link(QueueData *p,PLinkQueue Q)插入队尾
    //本函数为针对本实验特殊设计，可实现秘钥的循环使用
    //请在此处填写代码，完成相应功能
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
    /*  参数： src 放的是源文 ； key 放的是秘钥 ； dest 放加密后的密文
       加密函数： 步骤提示
       1. 初始化一个空队列Q
       2. 将key数组的元素逐个插入队列Q
       3. 逐个访问src数组的源文，并加密， 使用deQueue_link(Q)函数可得到队首秘钥，并使秘钥循环使用
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



