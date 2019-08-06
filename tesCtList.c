#include<stdio.h>
#include<malloc.h>


typedef struct list1
{
    int value;
    struct list1 * next;
} newnode,*pnode;

pnode createLs();
void printLs(pnode ls);
int main()
{
   // newnode ls1;
   // ls1.value=1;
   // printf("%d,%d",ls1.value,ls1.node);
    pnode aa=createLs();
    printLs(aa);
    insertVal(&aa,22);
    printLs(aa);
//    testpq();
    return 0;
}

pnode createLs()
{
    pnode ls;
    ls=(pnode)malloc(sizeof(newnode));
    if(ls==NULL)
    {
        printf("内存分配失败");
        return 1;
    }
    ls->value=10;
    ls->next=NULL;
    pnode p=ls;
    printf("请输入链表长度");
    int len=0,i=0;
    scanf("%d",&len);
    for(i;i<len-1;i++)
    {
        pnode last=(pnode)malloc(sizeof(newnode));
        last->value=i;
        last->next=NULL;
        p->next=last;
        p=last;
    }
    return ls;
}
//将链表打印出来
void printLs(pnode ls)
{
    if(ls->next==NULL)
    {
        printf("链表为空");
    }

    while(ls!=NULL)
    {
        printf("%d\t%d\n",ls->value,ls);
        ls=ls->next;
    }
}

//bool findVal(pnode ls,int a)
//{
//    while(ls->next!=NULL)
//    {
//        if(ls->value==a)
//        {
//            return true;
//        }
//        ls=ls->next;
//    }
//    return false;
//}
//在链表中插入一个值
void insertVal(pnode *ls,int a)
{
    pnode p=*ls;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    pnode nex=(pnode)malloc(sizeof(newnode));
    nex->value=a;
    nex->next=NULL;
    p->next=nex;
}

//同时有p和q两个指针变量指向同一个地址，一个改变其指向地址的内容，另一个内容也会随之改变。
void testpq()
{
    int *p,*q,a=1;
    p=&a;
    q=&a;
    printf("前：*p=%d\t*q=%d\n",*p,*q);
    *p=6;
    printf("后:*p=%d\t*q=%d\n",*p,*q);
//    return 0;
}


