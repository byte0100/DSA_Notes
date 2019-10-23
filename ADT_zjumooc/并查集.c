#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * 并查集 一种简单的集合表示 支持3种操作：1.Union 将集合root2并入集合root1  2. Find 查找集合中元素X所在的子集
 * 3.Initial 初始化集合将集合中所有元素都各自归为子集
 * 用树的双亲表示法实现，在双亲数组中数组下标代表元素名，根结点的元素值为-size
 */

#define  MAXN 1000
typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MAXN];

SetName Find(SetType S, ElementType X)
{
    if( S[X] < 0)
        return X;
    else
        return S[X] = Find(S,S[X]);
}

void Union(int S[],int root1, int root2)
{
    if(S[root1] > S[root2]){
        S[root2] += S[root1];
        S[root1] = root2;
    }else {
        S[root1] += S[root2];
        S[root2] = root1;
    }
}