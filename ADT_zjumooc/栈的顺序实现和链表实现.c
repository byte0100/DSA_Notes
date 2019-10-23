/**
 *@time 2019/10/1 16:43
 *@version 1.0.0
 *@author byte_rzj
 */

/* 栈的顺序表实现 */
typedef int Position;
struct SNode {
    ElementType *Data; /* 存储元素的数组 */
    Position Top;      /* 栈顶指针 */
    int MaxSize;       /* 堆栈最大容量 */
};
typedef struct SNode *Stack;

Stack CreateStack( int MaxSize )
{
    Stack s = (Stack)malloc(sizeof(struct SNode));
    s->Data = (ElementType*)malloc(sizeof(ElementType)*MaxSize);
    s->Top = -1;
    s->MaxSize = MaxSize;
    return s;
}

bool IsFull( Stack S )
{
    return (S->Top == S->MaxSize - 1);
}

bool Push( Stack S, ElementType X )
{
    if(IsFull(S)) return false;
    else{
        S->Data[++(S->Top)] = X;
        return true;
    }
}

bool IsEmpty( Stack S )
{
    return(S->Top == -1);
}

ElementType Pop( Stack S )
{
    if(IsEmpty(S)) return ERROR;  /* ERROR是ElementType的特殊值，标志错误 */
    else{
        ElementType tmp = S->Data[S->Top--];
        return tmp;
    }
}

/*栈的链表实现*/
typedef struct SNode *PtrToSNode;
struct SNode {
    ElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

Stack CreateStack( )
{ /* 构建一个堆栈的头结点，返回该结点指针 */
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

bool IsEmpty ( Stack S )
{ /* 判断堆栈S是否为空，若是返回true；否则返回false */
    return(S->Next == NULL);
}

bool Push( Stack S, ElementType X )
{ /* 将元素X压入堆栈S */
    Stack tmp = (Stack)malloc(sizeof(struct SNode));
    tmp->Data = X;
    tmp->Next = S->Next;
    S->Next = tmp;
    return true;
}

ElementType Pop( Stack S )
{ /* 删除并返回堆栈S的栈顶元素 */
    if(IsEmpty(S)) return ERROR;
    else{
        Stack tmp = S->Next;
        S->Next = tmp->Next;
        ElementType topElement = tmp->Data;
        free(tmp);
        return topElement;
    }

}