//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//#include<stdbool.h>
//
//typedef struct Node {
//	int data; //数据域
//	struct Node* next; //指针域
//}node, * pnode;
//
//pnode create_list(void) {   //因为返回值要赋值给phead，而phead 是结构体指针类型
//	int len;//用来存放有效结点的个数
//	int i;
//	int val;//用来临时存放用户输入结点的值
//	// phead = NULL,pnew=NULL;
//	pnode phead = (pnode)malloc(sizeof(node));//分配了一个不存放有效数据的头结点
//	if (phead == NULL) {
//		printf("内存分配失败");
//		exit(-1);
//	}
//	pnode plast = phead;  //先将你想定义的plast和phead相等，
//	plast->next = NULL;   //再将plast指向NULL，那么plast必定成为了尾结点
//	printf("请输入要生成的结点的个数：len=");
//	scanf_s("%d", &len);
//	for (i = 0; i < len; i++) {
//		printf("请输入第%d个结点的值", i + 1);
//		scanf_s("%d", &val);
//		pnode pnew = (pnode)malloc(sizeof(node));  //每循环一次就用pnew 造出一个新的结点
//		if (pnew == NULL) {
//			printf("内存分配失败");
//			exit(-1);
//		}
//		pnew->data = val;//这句意思是pnew的数据域里存放了所创造出来的每一个新结点的值
//		plast->next = pnew;
//		pnew->next = NULL;
//		plast = pnew;
//	}
//	return phead;   //传头结点
//}
//
////链表为空：链表里只有一个头结点
//void traverse_list(pnode phead) {  //这里来接收
//	pnode p = NULL;
//	p = phead->next;   //p指向头结点后第一个有效的结点，即首结点
//	while (p != NULL) {
//		printf("%d  ", p->data);
//		p = p->next;
//
//		/*if (phead->next  == NULL) {
//			break;
//		}*/
//	}
//	printf("\n");
//	return;// 写return的目的是为了告诉别人程序已经执行完毕了
//}
//
//bool is_empty(pnode phead) {
//	if (phead->next == NULL) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
//int length_list(pnode phead) {
//	pnode p = phead->next;
//	int len = 0;
//	while (p != NULL) {
//		len++;
//		p = p->next;
//	}
//	return len;
//}
//
//void sort_list(pnode phead) {
//	int i, j, len = length_list(phead);
//	pnode p, q;
//	for (i = 0, p = phead->next; i < len - 1; i++, p = p->next) {
//		for (j = 0, q = p->next; j < len - 1 - i; j++, q = q->next) {
//			if (p->data > q->data) {
//				int t = 0;
//				t = p->data;
//				p->data = q->data;
//				q->data = t;
//			}
//		}
//	}
//	return;
//}
//
////在phead所指向链表的第pos个结点的前面插入一个新的结点，该结点的值是val,并且pos的值从1开始
//bool insert_list(pnode phead, int pos, int val) {
//	int i = 0;
//	pnode p = phead;
//	//如果p即头结点不为空，并且 i在你要插入位置的前一个位置
//	while (p != NULL && i < pos - 1) {  //i<pos-1保证了插入位置位于pos的前一个位置
//		p = p->next;
//		i++;
//	}
//
//	//如果i在你要插入的结点的后面并且 p即头指针为空，那么就输出错误
//	if (i > pos - 1 || p == NULL) {  //保证了pos不是负数
//		return false;
//	}
//	pnode pnew = (pnode)malloc(sizeof(node));  //新创一个pnew结点
//	//创建了一个新结点以后先判空
//	if (pnew == NULL) {
//		printf("动态内存分配失败");
//		exit(-1);
//
//	}
//	pnew->data = val;  //这部是将要插入结点的值赋值给pnew的data域
//	pnode q = p->next;  //新建立结点q指向p->next
//	p->next = pnew;
//	pnew->next = q;
//}
//
//bool delete_list(pnode phead, int pos, int* val) {
//	int i = 0;
//	pnode p = phead;
//
//	while (p->next != NULL && i < pos - 1) {
//		p = p->next;
//		i++;
//	}
//	if (i > pos - 1 || p->next == NULL) {
//		return false;
//	}
//	pnode q = p->next;
//	*val = q->data;
//	p->next = p->next->next;
//	free(q);
//	q = NULL;
//
//}
//int main() {
//	pnode phead = NULL;
//	int val;
//	phead = create_list();//create_list()功能：创建一个非循环单链表，并将该链表的头结点的地址赋值给 head
//	traverse_list(phead);
//	//insert_list(phead, 3, 22);
//	if (delete_list(phead, 4, &val))
//	{
//		printf("删除的元素是%d！\n", val);
//
//	}
//	else {
//		printf("删除失败！\n");
//	}
//	traverse_list(phead);//遍历
//
//		//int len = length_list(phead);
//		//printf("链表的长度是%d\n ", len);
//		//sort_list(phead);
//		//traverse_list(phead);
//		/*if (is_empty(phead)) {
//			printf("链表为空！");
//		}
//		else {
//			printf("链表不空");
//		}*/
//
//
//	return 0;
//}