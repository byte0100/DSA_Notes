/**
 *@time 2019/10/9 14:34
 *@version 1.0.0
 *@author byte_rzj
 */

/*
 * 二叉树的链表存储结构
 */

typedef struct TNode{
    ElementType Element;
    struct TNode *lchild;
    struct TNode *rchild;
}BiTNode,*BiTree;

/*
 * 二叉树的数组存储结构
 */

typedef int Position;
struct TNode{
    ElementType Element;
    Position lchild;
    Position rchild;
}T[MAXSIZE];