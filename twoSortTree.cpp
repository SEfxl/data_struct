#include <stdio.h>
#include <stdlib.h>

//二叉排序树
typedef struct Nodes {
    int key;
    struct Nodes *lchild;
    struct Nodes *rchild;
}BSTNode;

/**
 * 将单个数据节点插入到二叉排序树p中
 * 使得左边的都小于父节点，右边的都大于父节点
 * @param p
 * @param e
 * @return
 */
int InsertBST(BSTNode *&p, int e) {

    if(p == NULL) {
        p =(BSTNode *) malloc(sizeof(BSTNode));
        p->key = e;
        p->lchild = NULL;
        p->rchild = NULL;
        return 1;
    }else if(e == p->key) {
        return 0;
    }else if(e < p->key) {
        InsertBST(p->lchild,e);
    }else {
        InsertBST(p->rchild,e);
    }
}

/**
 * 创建二叉排序树，依次调用插入单个节点的方法
 * @param a
 * @param n
 * @return
 */
BSTNode * CreateBSTNode(int a[],int n) {
    BSTNode *bt = NULL;
    int i = 0;
    while (i<n) {
        InsertBST(bt,a[i]);
        i++;
    }
    return bt;
}

/**
 * 中序遍历
 * @param p
 */
void MidOutput(BSTNode *p) {
    if(p != NULL) {
        MidOutput(p->lchild);
        printf("%d ",p->key);
        MidOutput(p->rchild);
    }
}

/**
 * 二叉排序树查找，找到该值的节点
 * @param p
 * @param e
 * @return
 */
BSTNode * SearchBST(BSTNode *p, int e) {
    if(p == NULL || p->key == e) {
        return p;
    }
    if(e < p->key) {
        SearchBST(p->lchild,e);
    } else {
        SearchBST(p->rchild,e);
    }
    return NULL;
}

/**
 * 在bt中查找，若查找成功则返回该节点指针,f返回双亲节点,否则返回NULL
 * f1用做中间参数用于求f,初始设置为NULL
 * 调用方式：SearchParent(bt,e,NULL,f);
 * @param bt
 * @param e
 * @param f1
 * @param f
 * @return
 */
BSTNode *SearchParent(BSTNode *&bt, int e, BSTNode *f1, BSTNode *&f) {
    if(bt == NULL) {
        f = NULL;
        return NULL;
    }else if(e == bt->key) {
        f = f1;
        return bt;
    }else if(e < bt->key) {
        SearchParent(bt->lchild,e,bt,f);
    }else {
        SearchParent(bt->rchild,e,bt,f);
    }
}

/**
 * 获取最大值
 * @param p
 * @return
 */
int getMaxNode(BSTNode *p) {
    while (p->rchild != NULL) {
        p = p->rchild;
    }
    return p->key;
}

/**
 * 获取最小值
 * @param p
 * @return
 */
int getMinNode(BSTNode *p) {
    while (p->lchild != NULL) {
        p = p->lchild;
    }
    return p->key;
}

/**
 * 对于给定二叉树节点p,找出其左子树最大节点,找出右子树最小节点
 * @param p
 */
void getMaxAndMinNode(BSTNode *p) {
    if(p == NULL) {
        printf("该节点没有孩子节点\n");
    }
    if(p->lchild != NULL) {
        int maxData = getMaxNode(p->lchild);
        printf("左子树最大节点为：%d",maxData);
    }
    if(p->rchild != NULL) {
        int minData = getMinNode(p->rchild);
        printf("右子树最小节点为：%d",minData);
    }

}


void Delete1(BSTNode *p, BSTNode *&r) { //2&
    BSTNode *q;
    if(r->rchild != NULL) {
        Delete1(p,r->rchild);
    }
}

void Delete(BSTNode *&p) {  //从二叉排序树中删除p节点 1&
    BSTNode *q;
    if(p->rchild == NULL) {  //p节点没有右子树
        q = p;
        p = p->lchild;  //将其左子树节点放在被删除节点
        free(q);
    }else if(p->lchild == NULL) {   //p节点没有左子树
        q = p;
        p = p->rchild;  //将其右子树放在被删除节点
        free(q);
    } else {
        Delete1(p,p->lchild);  //p节点既有左子树又有右子树
    }

}

/**
 * 删除关键字为e的节点
 * @param bt
 * @param e
 * @return
 */
int DeleteBST(BSTNode *bt, int e) {
    if(bt == NULL) {
        return 0;
    }else {
        if(e < bt->key) {
            return DeleteBST(bt->lchild,e);
        }else if(e > bt->key) {
            return DeleteBST(bt->rchild,e);
        }else {

            return 1;
        }
    }
}



int main()
{
    BSTNode *p;
    int a[] = {5,2,1,6,7,4,8,3,9};
    int length = sizeof(a)/ sizeof(int);
    p = CreateBSTNode(a,length);
    printf("中序遍历二叉排序树为：");
    MidOutput(p);
    printf("\n");

    BSTNode *bt;
    bt = SearchBST(p,6);
    if(bt != NULL) {
        printf("该节点值为：%d\n",bt->key);
    }else {
        printf("不存在该节点\n");
    }

    //获取某节点，左子树的最大值，右子树的最小值
    getMaxAndMinNode(p);


    return 0;
}
