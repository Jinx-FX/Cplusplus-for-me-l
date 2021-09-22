#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    int data;
    int num;
    struct node * next;
}List;

/* 这两个函数用于将链表的数据倒置*/
void invert_1(List *head,int size); //成功
List * invert_2(List *head);        //成功

int main()
{
    List *head =NULL,*tail;         //头节点非空
    List *prev,*curruent;
    int i=0;
    int size;
    puts("enter the node you want:");
    scanf("%d",&size);
    puts("enter the data:");
    while(i<size)
    {
        curruent = (List*)malloc(sizeof(List));
        if(head==NULL)
            head = curruent;
        else
            prev->next = curruent;
        curruent->num = i;
        curruent->next = NULL;      //确保终止尾节点
        scanf("%d",&curruent->data);
        while(getchar() != '\n')
            continue;
        prev = curruent;
        i++;
    }

    tail = curruent;
    puts("Here is the data:");

    curruent = head;
    while(curruent != NULL)
    {
        printf("%d  %d\n",curruent->num,curruent->data);
        curruent=curruent->next;
    }
    
    // invert_1(head,size);
    // invert_2(head);
    invert_3(head);
    printf("\n");

    // curruent = head;  //适用于invert_1
    curruent = tail;      //适用于invert_3
    while(curruent != NULL)
    {
        printf("%d  %d\n",curruent->num,curruent->data);
        curruent=curruent->next;
    }

    curruent = head;
    while(curruent != NULL)
    {
        head = curruent->next;
        free(curruent);
        curruent = head;
    }

    return 0;
}


void invert_1(List *head,int size)
{
    List *tail = head;
    for(int i=0;i<size/2;i++)
    {
        List *curruent=head;
        int temp;
        while(tail->num+head->num != size-1)
        {
            tail = curruent;
            curruent = curruent->next;
        }

        temp = tail->data;
        tail->data = head->data;
        head->data = temp;

        head = head->next;
    }
}

List * invert_2(List *head)
{
		List * h, *u, *tmp;                     
		h = NULL; u = head;
        //先断开相应节点，在重新确定指向
		while (u)                      
		{
			tmp = u->next;
			u->next = h;
			h = u;
			u = tmp;
		}
		// head->next = h;   //h最后是tail，若使用该语句，会使原被断开的链表成为 循环链表。
		return head;
	}
