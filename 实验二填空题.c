#include<stdio.h>
#include<stdlib.h>
typedef  struct  linknode
{
	int  data;
	struct  linknode* link; //指针域相当于next
}ListNode, * LinkList;

ListNode* Create(int  n)                            /*创建链表*/
{
	ListNode* list = NULL, * pf = NULL, * pb;
	int  i;
	for (i = 0; i < n; i++)
	{
		pb = (ListNode*)malloc(sizeof(ListNode));  /*开辟空间*/
		scanf_s("%d", &pb->data);
		pb->link = NULL;
		if (i == 0)                                /*如果是第一个结点*/
			list = pb;
		else                                        /*否则，插入结点到链表尾部*/
			pf->link = pb;
		pf = pb;                                        /*移动链表的尾指针*/
	}
	return(list);                                /*返回链表的头指针*/
}

void DEL(LinkList  list)
{
	LinkList p = NULL;
	while (list->link != NULL) {
		int flag = 1; //让指针后移
		if (list->data == list->link->data) {
			p = list->link;
			list->link = list->link->link;
			free(p);
			flag =0; //指针不后移
			//return;
		}
		if (flag) {
			list = list->link;

			
		}
	}
}

//void      DEL(LinkList  list)
//{
//	//LinkList p = NULL;
//	while (list->link != NULL) {
//		int flag = 1;
//		if (list->data == list->link->data) {
//			ListNode *p = list->link;
//			list->link = p->link;
//			free;
//			flag = 0;
//		}
//		if (flag) {
//			list = list->link;
//		}
//	}
//}


void  Show(ListNode* h)
{
	ListNode* p = h;
	do
	{
		printf("%d  ", p->data);
		p = p->link;
	} while (p != NULL);
}
int  main(void)
{
	LinkList  list;
	int  n;
	scanf_s("%d", &n);      //输入单链表的结点个数  
	list = Create(n);
	DEL(list);
	Show(list);
	return  0;
}