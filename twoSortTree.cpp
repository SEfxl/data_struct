#include <stdio.h>
#include <stdlib.h>

//����������
typedef struct Nodes {
    int key;
    struct Nodes *lchild;
    struct NOdes *rchild;
}BSTNode;

/**
 * ���������ݽڵ���뵽����������p��
 * ʹ����ߵĶ�С�ڸ��ڵ㣬�ұߵĶ����ڸ��ڵ�
 * @param p
 * @param e
 * @return
 */
int InsertBST(BSTNode *p, int e) {  //1&

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
 * �������������������ε��ò��뵥���ڵ�ķ���
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
 * �������
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
 * �������������ң��ҵ���ֵ�Ľڵ�
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
 * ��bt�в��ң������ҳɹ��򷵻ظýڵ�ָ��,f����˫�׽ڵ�,���򷵻�NULL
 * f1�����м����������f,��ʼ����ΪNULL
 * ���÷�ʽ��SearchParent(bt,e,NULL,f);
 * @param bt
 * @param e
 * @param f1
 * @param f
 * @return
 */
BSTNode *SearchParent(BSTNode *bt, int e, BSTNode *f1, BSTNode *f) {  // 1&4&
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
 * ��ȡ���ֵ
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
 * ��ȡ��Сֵ
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
 * ���ڸ����������ڵ�p,�ҳ������������ڵ�,�ҳ���������С�ڵ�
 * @param p
 */
void getMaxAndMinNode(BSTNode *p) {
    if(p == NULL) {
        printf("�ýڵ�û�к��ӽڵ�\n");
    }
    if(p->lchild != NULL) {
        int maxData = getMaxNode(p->lchild);
        printf("���������ڵ�Ϊ��%d",maxData);
    }
    if(p->rchild != NULL) {
        int minData = getMinNode(p->rchild);
        printf("��������С�ڵ�Ϊ��%d",minData);
    }

}


void Delete1(BSTNode *p, BSTNode *r) { //2&
    BSTNode *q;
    if(r->rchild != NULL) {
        Delete1(p,r->rchild);
    }
}

void Delete(BSTNode *p) {  //�Ӷ�����������ɾ��p�ڵ� 1&
    BSTNode *q;
    if(p->rchild == NULL) {  //p�ڵ�û��������
        q = p;
        p = p->lchild;  //�����������ڵ���ڱ�ɾ���ڵ�
        free(q);
    }else if(p->lchild == NULL) {   //p�ڵ�û��������
        q = p;
        p = p->rchild;  //�������������ڱ�ɾ���ڵ�
        free(q);
    } else {
        Delete1(p,p->lchild);  //p�ڵ��������������������
    }

}

/**
 * ɾ���ؼ���Ϊe�Ľڵ�
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
    printf("�����������������Ϊ��");
    MidOutput(p);
    printf("\n");

    BSTNode *bt;
    bt = SearchBST(p,6);
    if(bt != NULL) {
        printf("�ýڵ�ֵΪ��%d\n",bt->key);
    }else {
        printf("�����ڸýڵ�\n");
    }

    //��ȡĳ�ڵ㣬�����������ֵ������������Сֵ
    getMaxAndMinNode(p);


    return 0;
}
