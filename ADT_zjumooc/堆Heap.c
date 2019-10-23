#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 *堆 用完全二叉树实现，完全二叉树最适合的存储结构是通过数组存储，通过数组下标反应树结点之间的关系
 * 数组元素值则存储树结点的内容
 *实现一种数据结构，除了定义其数据结构外，还要实现对该数据结构的操作
 * 堆的一般操作有：1.插入 2.删除 3.判空 4.判满 5.创建空堆
 * 堆的创建有两种方式，1.创建空堆后逐个元素插入空堆 O(NlogN) 2.先将所有元素用数组存储，再从倒数第一个非叶子结点开始调整O(2/N * logN)
 */

typedef int ElementType;
typedef struct HNode *Heap;
struct HNode{
    ElementType *Data;
    int Size;
    int Capacity;
};
typedef Heap MaxHeap;
typedef Heap MinHeap;

#define MAXDATA 1000 //该值定义为大于堆中所有可能元素（大根堆）或小于堆中所有可能元素（小根堆）

MaxHeap Create(int Maxsize)
{
    MaxHeap H = (MaxHeap)malloc(sizeof(struct HNode));
    H->Data = (ElementType*)malloc(Maxsize * sizeof(ElementType));
    H->Data[0] = MAXDATA;
    H->Size = 0; // 空堆
    H->Capacity = Maxsize;
}

bool IsFull(MaxHeap H)
{
    return (H->Size == H->Capacity);
}

bool Insert(MaxHeap H, ElementType X)
{
    if(IsFull(H)){
        printf("MaxHeap is full\n");
        return false;
    }else{
        int i = ++H->Size; // 将元素插入到堆中的最后一个位置
        for(;H->Data[i/2] < X; i /= 2){
            H->Data[i] = H->Data[i/2];  // 上滤X
        }
        H->Data[i] = X; //将X插入
        return  true;
    }
}

bool IsEmpty(MaxHeap H)
{
    return H->Size == 0;
}

#define ERROR -1 //定义为堆中元素绝不可能出现的值
/* 删除堆顶元素 并返回堆顶元素值*/
ElementType DeleteMax(MaxHeap H)
{
    if(IsEmpty(H)){
        printf("MaxHeap is empty\n");
        return ERROR;
    }else{
        ElementType MaxItem = H->Data[1];
        ElementType X = H->Data[H->Size--]; //获取最后一个元素，并更新size
        /* 将最后一个元素替换掉堆顶元素值，再进行下滤调整最大堆*/
        int parent = 1, child;
        for(;2*parent<=H->Size; parent = child){
            child = 2*parent; //左孩子
            if(child < H->Size && H->Data[child] < H->Data[child+1]){
                ++child;
            }   /*跟最大的孩子结点做比较*/
            if(H->Data[child] > X){
                H->Data[parent] = H->Data[child]; //下滤
            }else break;
        }
        H->Data[parent] = X;
        return  MaxItem;
    }
}

/*优化版本的建堆*/
void AdjustHeap(MaxHeap H, int p)
{ /* 调整最大堆H的以第p个元素作为根结点的子堆*/
    int parent,child;
    ElementType X = H->Data[p];

    for(parent = p; 2*parent <= H->Size; parent = child){
        child = 2 * parent;
        if(child < H->Size && H->Data[child] < H->Data[child+1]){
            ++child;
        }   /*跟最大的孩子结点做比较*/
        if(H->Data[child] > X){
            H->Data[parent] = H->Data[child]; //下滤
        }else break;
    }
    H->Data[parent] = X;
}

void BuildMaxHeap(MaxHeap H)
{
    int i;
    for(i = H->Size/2; i>0; --i){
        AdjustHeap(H,i);
    }
}