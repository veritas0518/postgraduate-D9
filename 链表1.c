//#include<stdio.h>
//#include<malloc.h>
//#include<stdlib.h>
//#include<stdbool.h>
//
//typedef struct Node {
//	int data; //������
//	struct Node* next; //ָ����
//}node, * pnode;
//
//pnode create_list(void) {   //��Ϊ����ֵҪ��ֵ��phead����phead �ǽṹ��ָ������
//	int len;//���������Ч���ĸ���
//	int i;
//	int val;//������ʱ����û��������ֵ
//	// phead = NULL,pnew=NULL;
//	pnode phead = (pnode)malloc(sizeof(node));//������һ���������Ч���ݵ�ͷ���
//	if (phead == NULL) {
//		printf("�ڴ����ʧ��");
//		exit(-1);
//	}
//	pnode plast = phead;  //�Ƚ����붨���plast��phead��ȣ�
//	plast->next = NULL;   //�ٽ�plastָ��NULL����ôplast�ض���Ϊ��β���
//	printf("������Ҫ���ɵĽ��ĸ�����len=");
//	scanf_s("%d", &len);
//	for (i = 0; i < len; i++) {
//		printf("�������%d������ֵ", i + 1);
//		scanf_s("%d", &val);
//		pnode pnew = (pnode)malloc(sizeof(node));  //ÿѭ��һ�ξ���pnew ���һ���µĽ��
//		if (pnew == NULL) {
//			printf("�ڴ����ʧ��");
//			exit(-1);
//		}
//		pnew->data = val;//�����˼��pnew�������������������������ÿһ���½���ֵ
//		plast->next = pnew;
//		pnew->next = NULL;
//		plast = pnew;
//	}
//	return phead;   //��ͷ���
//}
//
////����Ϊ�գ�������ֻ��һ��ͷ���
//void traverse_list(pnode phead) {  //����������
//	pnode p = NULL;
//	p = phead->next;   //pָ��ͷ�����һ����Ч�Ľ�㣬���׽��
//	while (p != NULL) {
//		printf("%d  ", p->data);
//		p = p->next;
//
//		/*if (phead->next  == NULL) {
//			break;
//		}*/
//	}
//	printf("\n");
//	return;// дreturn��Ŀ����Ϊ�˸��߱��˳����Ѿ�ִ�������
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
////��phead��ָ������ĵ�pos������ǰ�����һ���µĽ�㣬�ý���ֵ��val,����pos��ֵ��1��ʼ
//bool insert_list(pnode phead, int pos, int val) {
//	int i = 0;
//	pnode p = phead;
//	//���p��ͷ��㲻Ϊ�գ����� i����Ҫ����λ�õ�ǰһ��λ��
//	while (p != NULL && i < pos - 1) {  //i<pos-1��֤�˲���λ��λ��pos��ǰһ��λ��
//		p = p->next;
//		i++;
//	}
//
//	//���i����Ҫ����Ľ��ĺ��沢�� p��ͷָ��Ϊ�գ���ô���������
//	if (i > pos - 1 || p == NULL) {  //��֤��pos���Ǹ���
//		return false;
//	}
//	pnode pnew = (pnode)malloc(sizeof(node));  //�´�һ��pnew���
//	//������һ���½���Ժ����п�
//	if (pnew == NULL) {
//		printf("��̬�ڴ����ʧ��");
//		exit(-1);
//
//	}
//	pnew->data = val;  //�ⲿ�ǽ�Ҫ�������ֵ��ֵ��pnew��data��
//	pnode q = p->next;  //�½������qָ��p->next
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
//	phead = create_list();//create_list()���ܣ�����һ����ѭ�������������������ͷ���ĵ�ַ��ֵ�� head
//	traverse_list(phead);
//	//insert_list(phead, 3, 22);
//	if (delete_list(phead, 4, &val))
//	{
//		printf("ɾ����Ԫ����%d��\n", val);
//
//	}
//	else {
//		printf("ɾ��ʧ�ܣ�\n");
//	}
//	traverse_list(phead);//����
//
//		//int len = length_list(phead);
//		//printf("����ĳ�����%d\n ", len);
//		//sort_list(phead);
//		//traverse_list(phead);
//		/*if (is_empty(phead)) {
//			printf("����Ϊ�գ�");
//		}
//		else {
//			printf("������");
//		}*/
//
//
//	return 0;
//}