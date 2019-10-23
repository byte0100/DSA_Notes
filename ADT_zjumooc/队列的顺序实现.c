/**
 *@time 2019/10/1 16:44
 *@version 1.0.0
 *@author byte_rzj
 */
 /*循环队列*/
typedef int Position;
struct QNode {
    ElementType *Data;     /* 存储元素的数组 */
    Position Front, Rear;  /* 队列的头、尾指针 */
    int MaxSize;           /* 队列最大容量 */
};
typedef struct QNode *Queue;

Queue CreateQueue( int MaxSize )
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType*) malloc(MaxSize*sizeof(ElementType));
    Q->Front = 0;
    Q->Rear = 0;
    Q->MaxSize = MaxSize;
    return Q;
}

bool IsFull( Queue Q )
{
    return ((Q->Rear+1)%Q->MaxSize == Q->Front);//Rear指向队尾元素下一个位置
}

bool AddQ( Queue Q, ElementType X )
{
    if(IsFull(Q)) return false;
    else{
        Q->Data[Q->Rear] = X;
        Q->Rear = (Q->Rear+1)%Q->MaxSize;
        return true;
    }
}

bool IsEmpty( Queue Q )
{
    return (Q->Rear == Q->Front);
}

ElementType DeleteQ( Queue Q )
{
    if(IsEmpty(Q)) return false;
    else{
        ElementType tmp = Q->Data[Q->Front];
        Q->Front = (Q->Front+1)%Q->MaxSize;
        return tmp;
    }
}