#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SNode{
    int data;
	struct SNode *next;
}SNode,*List;

List create() {
    SNode *head = NULL;
    int i=0,size;
    SNode *current,*prev;
    printf("（初始化）输入有多少个猴子:");
    scanf("%d",&size);
    while(i<size) {
        current = (SNode *)malloc(sizeof(SNode));
        if(current==NULL) exit(1);
        if(head==NULL) 
        {
            head = current; //头结点不为空
        }
        else
        {
            prev->next = current;
        }
        current->next = NULL;
        current->data = i+1;
        prev = current;
        i++;
    }
    return head;
}
List delete(List head, int i) {
    //头牌为i的猴子出局
    SNode *current,*prev;
    current = head;
    while(current!=NULL) {
        if(current->data == i) {
            if(current == head) {
                head = current->next;
                current->next = NULL;
            }
            else {
                prev->next = current->next;
                current->next = NULL;
            }
            free(current);
            return head;
        }
        prev = current;
        current = current->next;
    }
    return head;
}

void display(List head) {
    SNode *current;
    current = head;
    printf("现在的猴子为：");
    while(current!=NULL) {
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}

void joseph(List head) {
    int i;
    printf("数到多少的猴子出局？");
    scanf("%d",&i);
    SNode *cur,*prev;
    prev = head;
    while(head->next!=NULL){
        cur = prev;
        for(int j=1;j<i;j++) {
            if(cur->next==NULL) cur = head;
            else cur = cur->next;
        }
        if(cur->next==NULL) prev = head;
        else prev = cur->next;
        head = delete(head,cur->data);
        display(head);
    }
    printf("\n");
    printf("猴王是 *-%d-*\n",head->data);
}

int main() {
    List head;
    head = create();
    display(head);
    joseph(head);
	return 0;
}
