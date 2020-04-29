//
//  main.cpp
//  链表代码
//
//  Created by 何忆源 on 2020/4/29.
//  Copyright © 2020 何忆源. All rights reserved.
//

#include <iostream>
#include<stdio.h>       //用于scanf, printf 标准输入输出
 
#include<stdlib.h>      //用于malloc, free 内存申请及释放
//结构体
typedef struct node          //typedef 用于取struct node 的别名
{
        int data;
        struct node *next;
}*PNODE,NODE;  //别名*PNODE 就是 struct node *   别名NODE就是 struct node
//这部分是函数前置声明
PNODE init();                           //链表初始化
void insert(PNODE head, int newdata);   //插入节点
void print(PNODE head);                 //打印整个链表
void freeAllNode(PNODE head);           //释放整个链表的内存
//链表初始化
PNODE init()
{
    PNODE temp = (PNODE)malloc(sizeof(NODE));  //定义一个节点
    temp->next = NULL;                    //这个节点比较特殊, 它不用于存储数据
    return temp;
}
//插入节点
//1.头插法
void insert(PNODE head,int newdata)
{
 
    PNODE temp=(PNODE)malloc(sizeof(struct node));  //先开辟一块内存用于存放要插入的数据
    temp->data = newdata;
        
        //头插
    temp->next = head->next;    //head->next就是节点A, 将temp连向A
    head ->next= temp;          //将head相向temp
}
//2.尾插法
void insert(PNODE head,int newdata)
{

    PNODE temp=(PNODE)malloc(sizeof(struct node));
    temp->data = newdata;

    //尾插
    PNODE p = (PNODE)malloc(sizeof(NODE));
    p = head;
    while (p->next != NULL) p = p->next;  //先定义一个p, 使它指向最后一个节点
    p->next = temp;                       //将p连向temp
    temp->next = NULL;                    //temp连向NULL
}
//打印整个链表
//链表的打印只能从head开始遍历, 不能像数组可以使用下标那么便利
void print(PNODE head)
{
    PNODE temp=head->next;   //定义temp指向A, 即第一个有内容的节点('空的'的下一个节点)
    while (temp!=NULL)       //在temp不为NULL是, 一直循环, 直到temp==NULL, 即遍历完了
    {
        printf("%d->", temp->data);  //打印节点里面的data
        temp = temp->next;          //指针的移动, 指向下一个节点
    }
    printf("NULL\n");
}
//释放整个链表的内存
void freeAllNode(PNODE head)
{
    PNODE p = head,temp;
    while (p != NULL)
    {
        temp = p->next;
        free(p);
        p = temp;
    }
}
