/**
 *@time 2019/10/1 19:42
 *@version 1.0.0
 *@author byte_rzj
 */

/*带头结点的单链表表示*/
typedef struct Node *PtrToNode;
struct Node { /* 队列中的结点 */
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position;

struct QNode {
    Position Front, Rear;  /* 队列的头、尾指针 */
    int MaxSize;           /* 队列最大容量 */
};
typedef struct QNode *Queue;

Queue CreateQueue(int Maxsize){
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->MaxSize = Maxsize;
    Q->Front = Q->Rear = (Position)malloc(sizeof(Node));
    Q->Front->Next = NULL;
    return Q;
}

bool IsEmpty( Queue Q )
{
    return (Q->Front == Q->Rear);
}

bool EnQueue(Queue Q, ElementType X){
    Position p = (Position)malloc(sizeof(Node));
    p->Data = X;
    p->Next = NULL;
    Q->Rear->Next = p;
    Q->Rear = p;
    return true;
}

ElementType DeleteQ( Queue Q )
{
    if(IsEmpty(Q)) return ERROR;
    else{
        ElementType front_element = Q->Front->Next->Data;
        Position  tmp = Q->Front->Next;
        Q->Front->Next = tmp->Next;
        if(Q->Rear == tmp){ //如果出队的是队尾元素，则出队后队列为空
            Q->Rear = Q->Front;
        }
        free(tmp);
        return front_element;
    }
}