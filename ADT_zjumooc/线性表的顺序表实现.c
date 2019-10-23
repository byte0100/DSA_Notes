/**
 *@time 2019/9/27 23:35
 *@version 1.0.0
 *@author byte_rzj
 */
 /*
  * 浙江大学 数据结构mooc 线性表的定义与操作 顺序表实现
  */
//#define MAXSIZE 100;

 typedef int ElementType; //可通过修改 ElementType的类型别名语句中的基本类型 来对该线性表实例化
 typedef  int Position;
 typedef  struct LNode *List;
 struct LNode{
     ElementType Data[MAXSIZE];
     Position Last; //说明队尾元素位置
 };

 /* 初始化*/
 List MakeEmpty()
 {
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
 }

 /*查找*/
#define  ERROR -1;

 Position Find(List L, ElementType X)
 {
     if(!L) return ERROR;
     Position i = 0;
     for(;i<=L->Last;++i){
        if(L->Data[i] == X) return i;
     }
     return ERROR;
 }

 /* 插入*/
 bool Insert(List L, ElementType X, Position P)
 {
     if(P<0 || P > L->Last+1) return false;
     if(L->Last == MAXSIZE-1) return false;
     for(Position i =L->Last; i >= P; --i){
         L->Data[i+1] = L->Data[i];
     }
     L->Data[P] = X;
     L->Last++;
     return true;
 }

 /* 删除*/
 bool Delete(List L, Position P)
 {
     Position  i = P;
     if(P<0||P>L->Last) return false;
     while(i<L->Last){
         L->Data[i] = L->Data[i+1];
         ++i;
     }
     L->Last--;
     return true;
 }


