#include<stdio.h>
#include<stdlib.h>
typedef  struct  linknode
{
	int  data;
	struct  linknode* link; //ָ�����൱��next
}ListNode, * LinkList;

ListNode* Create(int  n)                            /*��������*/
{
	ListNode* list = NULL, * pf = NULL, * pb;
	int  i;
	for (i = 0; i < n; i++)
	{
		pb = (ListNode*)malloc(sizeof(ListNode));  /*���ٿռ�*/
		scanf_s("%d", &pb->data);
		pb->link = NULL;
		if (i == 0)                                /*����ǵ�һ�����*/
			list = pb;
		else                                        /*���򣬲����㵽����β��*/
			pf->link = pb;
		pf = pb;                                        /*�ƶ������βָ��*/
	}
	return(list);                                /*���������ͷָ��*/
}

void DEL(LinkList  list)
{
	LinkList p = NULL;
	while (list->link != NULL) {
		int flag = 1; //��ָ�����
		if (list->data == list->link->data) {
			p = list->link;
			list->link = list->link->link;
			free(p);
			flag =0; //ָ�벻����
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
	scanf_s("%d", &n);      //���뵥����Ľ�����  
	list = Create(n);
	DEL(list);
	Show(list);
	return  0;
}