#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
#define SIZE_M 5

typedef struct {
	char *elem;
	int len;
	int listsize;
}list;

void init(list *L) {
	L->elem = (char *)malloc(SIZE*sizeof(char));
	L->len = 0;
	L->listsize = SIZE;
}

void info(list *L, int l) {
	for(int i=0;i<l;i++) {
		// \n 消除空格给scanf带来的影响
		scanf("\n%c",&L->elem[i]);
		L->len++;
	}
}

int length(list *L) {
	return L->len;
}

char get(list *L, int i) {
	return L->elem[i];
}

int locate(list *L, char n) {
	for(int i=0;i<L->len;i++) {
		if(L->elem[i]==n)
			return i+1;
	}
	return -1; //无
}

void insert(list *L, int i, char n) {
	if(i<1||i>L->len+1) exit; // 不合法
	if(L->len>L->listsize) {
		char * newbase = (char *)realloc(L->elem,(L->listsize+SIZE_M)*sizeof(char));
		if(!newbase) exit;
	L->elem = newbase;
		L->listsize += SIZE_M;
	}
	char *q;
	q = &(L->elem[i-1]);
	for(char *p=&(L->elem[L->len-1]);p>=q;--p) *(p+1) = *p;

	*q = n;
	++L->len;
}

void delete(list *L, int i) {
	if(i<1||i>L->len+1) exit;
	char *p;
	p = &(L->elem[i-1]);
	char *q;
	q = L->elem + L->len - 1; 
	for(++p;p<=q;++p) *(p-1) = *p;
	--L->len;
}

void display(list *L) {
	for(int i=0;i<L->len;i++)
		printf("%c ",L->elem[i]);
	printf("\n");
}

list* merg(list *L1, list *L2, list *L3) {
	L3->len = L1->len + L2->len;
	L3->elem = (char *)malloc(L3->listsize*sizeof(char));
	if(!L3->elem) exit;
	
	for(int i=0;i<L1->len;i++) {
		L3->elem[i] = L1->elem[i];
	}
	for(int i=L1->len,j=0;i<L3->len;i++,j++) {
		L3->elem[i] = L2->elem[j];
	}
	return L3;
}

int main() {
	list List1,List2,List3;
    list *L1,*L2,*L3;
	L1 = &List1;
	L2 = &List2;
	L3 = &List3;
	init(L1);
	init(L2);
	printf("创建顺序表1：");
	info(L1,4);
	printf("值为%c在表中的位置为：%d\n",get(L1,0),locate(L1,L1->elem[0]));
	printf("位置4的值为：%c\n",get(L1,3));
	printf("删除第二个结点后顺序表：");
	delete(L1,2);
	display(L1);
	printf("创建顺序表2：");
	info(L2,4);
	printf("合并后的表为：");
	merg(L1,L2,L3);
	display(L3);
    return 0;
}

