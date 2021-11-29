#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SNode{
    char data;
	struct SNode *next;
}SNode,*List;

List create() {
    SNode *head = NULL;
    int i=0,size;
    SNode *current,*prev;
    printf("（初始化）输入你想要的结点个数:");
    scanf("%d",&size);
    printf("输入数据\n");
    while(i<size) {
        current = (SNode *)malloc(sizeof(SNode));
        if(current==NULL) exit;
        if(head==NULL) 
        {
            head = current; //头结点不为空
        }
        else
        {
            prev->next = current;
        }
        current->next = NULL;
        printf("第%d个字符：",i+1);
        scanf("\n%c",&current->data);
        while(getchar()!='\n')
            continue;
        prev = current;
        i++;
    }
    return head;
}
char get(List head, int i) {
    // 获取第i个结点的值
    SNode *current;
    current = head;
    int si = 1;
    while(current!=NULL) {
        if(si==i) return current->data;
        current = current->next;
        ++si;
    }
    return 0;
}
int locate(List head, char n) {
    SNode *current;
    current = head;
    int si = 1;
    while(current!=NULL) {
        if(current->data==n)
            return si;
        current = current->next;
        ++si;
    }
    return -1;
}
void insert(List head, char n, int i) {
    //插入data=n， 位于第i-1个结点之后
    SNode *current;
    current = head;
    int j = 0;
    while(current!=NULL && j<i-2) {
        current = current->next;
        ++j;
    }
    if(current == NULL || j>i-2) exit;
    SNode *new;
    new = (SNode *)malloc(sizeof(SNode));
    new->data = n;
    new->next = current->next;
    current->next = new;
}
void delete(List head, int i) {
    //删除第 i 个结点
    SNode *current,*de_current;
    current = head;
    int j = 0;
    while(current!=NULL && j<i-2) {
        current = current->next;
        ++j;
    }
    if(current == NULL || j>i-2) exit;
    de_current = current->next;
    current->next = de_current->next;
    de_current->next = NULL;
    free(de_current);
}
void sort(List head) {
    // 从小到大排序,
    // 交换数据，没有改变指向
    // 选择排序
    SNode *cur, *tail;
    cur = head;
    tail = NULL;
    if(cur==NULL||cur->next==NULL) exit;
    while(cur!=tail) {
        while(cur->next!=tail) {
            if(cur->data > cur->next->data) {
                char temp = cur->data;
                cur->data = cur->next->data;
                cur->next->data = temp;
            }
            cur = cur->next;
        }
        tail = cur; //tail更新为迭代后的（局部）最大值
        cur = head;
    }
}
void display(List head) {
    SNode *current;
    current = head;
    while(current!=NULL) {
        printf("%c ",current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
	printf("hello world\n");
    List head;
    head = create();
    printf("输入的字符是：");
    display(head);
    printf("在第3个结点的字符是：%c\n",get(head,3));
    printf("字符a在第%d个结点\n",locate(head,'a'));
    printf("在第3个结点插入字符a：");
    insert(head,'a',3);
    display(head);
    printf("删除第3个结点：");
    delete(head,3);
    display(head);
    printf("排序后：");
    sort(head);
    display(head);
	return 0;
}
