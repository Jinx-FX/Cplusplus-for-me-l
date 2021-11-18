在数据结构中会看到
```
typedef struct QNode
{
  QElemType data; //数据域 
  struct QNode *next; //指针域 
}QNode,*QueuePtr;

typedef struct
{
  QueuePtr front; //队头指针
  QueuePtr rear; //队尾指针 
};
```

先来解释下上面第一个结构体
关键在于后面的那个部分如何理解
就是
```
typedef struct QNode
{
  QElemType data;
  struct qNode *next;
}QNode,*QueuePtr;
```
就是QNode,*QueuePtr这两个如何理解

可以这样来理解
```
typedef struct QNode Qnode
typedef struct QNode *QueuePtr
```

同样通过这样一个例子可以这样来理解
```
typedef struct int ElemType
typedef struct int* ElemTypePtr
```
第一个是 定义新的整型变量 ElemType

第二个是 定义新的指向整型变量的指针 ElemTypePtr

可以简单理解为 ElemType = int

             ElemTypePtr = int*

同理在上面的结构体中

可以理解为
```
typedef struct QNode QNode
typedef struct QNode* QueuePtr
```
于是

QNode 的对象都是结构体

QueuePtr 的对象都是结构体指针
