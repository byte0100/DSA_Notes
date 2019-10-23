/**
 *@time 2019/10/9 14:34
 *@version 1.0.0
 *@author byte_rzj
 */


struct TNode{
    ElementType Element;
    struct TNode *lchild;
    struct TNode *rchild;
}*BiTree;

/*
 * 先序遍历
 */

void preOrder(BiTree root){
    if(!root) return;
    else{
        visit(root);
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}

/*
 * 中序遍历
 */

void inOrder(BiTree root){
    if(!root) return;
    else{
        inOrder(root->lchild);
        visit(root);
        inOrder(root->rchild);
    }
}

/*
 * 后序遍历
 */

void postOrder(BiTree root){
    if(!root) return;
    else{
        postOrder(root->lchild);
        postOrder(root->rchild);
        visit(root);
    }
}

/*
 * 先序遍历 非递归版本
 */

void preOrder_stack(BiTree root){
    stack<BiTree> S;
    BiTree p = root;
    while(p || !S.empty()){
        if(p){
            visit(p);
            S.push(p);
            p = p->lchild;
        }else{
            p = S.top();
            s.pop();
            p = p->rchild;
        }
    }

}

/*
 * 中序遍历 非递归版本
 */

void inOrder_stack(BiTree root){
    stack<BiTree> S;
    BiTree p = root;
    while(p || !S.empty()){
        if(p){
            S.push(p);
            p = p->lchild;
        }else{
            p = S.top();S.pop();
            visit(p);
            p = p->rchild;
        }
    }
}

/*
 * 后序遍历 非递归版本
 * 后序遍历的非递归版本的区别在于，当访问结点时要判断是从左子树回来的还是右子树回来的
 * 两种方法：1.建立一个指针指向刚访问过的结点 2.在结点中增加一个成员，记录是否访问过该结点
 */

void postOrder_stack(BiTree root){
    stack<BiTree> S;
    BiTree p = root;
    BiTree r = NULL;
    while(p || !S.empty()){
        if(p){
            S.push(p);
            p = p->lchild;
        }else{
            p = S.top();
            if(p->rchild && p->rchild != r){ // 从左子树回来
                p = p->rchild;
            }else{
                visit(p);
                S.pop();
                r = p;
                p = NULL;
            }
        }
    }
}

/*
 * 层序遍历 通过队列实现
 */

void level(BiTree root){
    BiTree Queue[MAXSIZE];
    int front = rear = 0;
    Queue[rear++] = root;
    while(front < rear){
        BiTree p = Queue[front++];
        visit(p);
        if(p->lchild) Queue[rear++] = p->lchild;
        if(p->rchild) Queue[rear++] = p->rchild;
    }
}