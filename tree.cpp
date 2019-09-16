#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50

typedef struct node {
    char data;
    struct node *lchild;
    struct node *rchild;
}BTNode;

//创建二叉树
void CreateBTNode(BTNode *&b, char *str) {
    BTNode *St[MaxSize],*p;
    int top=-1,k,j=0;
    char ch;
    b = NULL;
    ch = str[j];
    while(ch != '\0')
    {
        switch(ch)
        {
        case '(' :
            top++;St[top]=p;k=1;break;
        case ')':
            top--;break;
        case ',':
            k=2;break;
        default:
            p = (BTNode *)malloc(sizeof(BTNode));
            p->data = ch; p->lchild = p->rchild = NULL;
            if(b == NULL){
                b = p;
            } else {
                switch(k) {
            case 1:
                St[top]->lchild = p; break;
            case 2:
                St[top]->rchild = p; break;
                }
            }
        }
        j++;
        ch = str[j];
    }
}

BTNode *FindNode(BTNode *b, char c) {

    BTNode *p;
    if(b == NULL) {
        return NULL;
    }else if(b->data == c) {
        return b;
    }else {
        p = FindNode(b->lchild,c);
        if(p != NULL) {
            return p;
        }else {
            return FindNode(b->rchild,c);
        }
    }
}

int BTNodeHeight(BTNode *b) {
    int lchild,rchild;
    if(b == NULL) {
        return 0;
    }else {
        lchild = BTNodeHeight(b->lchild);
        rchild = BTNodeHeight(b->rchild);
        return (lchild > rchild) ? (lchild + 1) : (rchild + 1);
    }
}

//输出二叉树
void DisplayBTNode(BTNode *b) {
    if(b!=NULL) {
        printf("%c",b->data);
        if(b->lchild != NULL || b->rchild != NULL) {
            printf("(");
            DisplayBTNode(b->lchild);
            if(b->rchild != NULL)
                printf(",");
            DisplayBTNode(b->rchild);
            printf(")");
        }
    }
}

int main() {
    char str[]="A(B(D(,G)),C(E,F))";
    int high=0;
    BTNode *p,*head;
    CreateBTNode(p,str);
    DisplayBTNode(p);
    printf("\n");
    char c = 'H';
    head = FindNode(p,c);
    if(head == NULL) {
        printf("树中节点不存在此值\n");
    }else {
        printf("树中存在此节点，该节点在树中的值为：%c\n",head->data);
    }
    high = BTNodeHeight(p);
    printf("树的高度为：%d\n",high);
    return 0;
 }
