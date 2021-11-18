 
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
 
typedef int ElemType;
typedef struct Node{  //创建单向链表的结点 
	int data;
	struct Node *next;
}DLinkList;
 
void InitList(DLinkList *&head,int n)   //方法一 
{
	DLinkList *p,*s;
	head=(DLinkList*)malloc(sizeof(DLinkList));
	head->next=NULL;
	p=head;
	for(int i=1;i<=n;i++)
	{
		s=(DLinkList*)malloc(sizeof(DLinkList));
		scanf("%d",&s->data);
		s->next=NULL;
		p->next=s;
		p=p->next;
	}
} 
 
/*DLinkList *InitList(int n){        方法二 
	DLinkList *head,*p,*s;
	head=(DLinkList*)malloc(sizeof(DLinkList));
	head->next=NULL;
	p=head;
	for(int i=1;i<=n;i++)
	{
		s=(DLinkList*)malloc(sizeof(DLinkList));
		scanf("%d",&s->data);
		s->next=NULL;
		p->next=s;
		p=p->next;
	}
	return head;
}*/

void print(DLinkList *head)     //输出单向链表的所有的元素 
{
	DLinkList *p;
	p=head->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}
 
int main()
{
	DLinkList *head;
 
	InitList(head,5);
	print(head); 
  
/*DLinkList *head;
  head=InitList(5);
	print(head);*/
  
	return 0; 
} 
