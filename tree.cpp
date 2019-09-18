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

//查找值为C的节点
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

//求树的高度
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

//前序遍历
void PreOrder(BTNode *b) {
    if(b!= NULL) {
       printf("%c ",b->data);
       PreOrder(b->lchild);
       PreOrder(b->rchild);
    }
}

//中序遍历
void InOrder(BTNode *b) {
    if(b!= NULL) {
        InOrder(b->lchild);
        printf("%c ",b->data);
        InOrder(b->rchild);
    }
}

//后序遍历
void PostOrder(BTNode *b) {
    if(b!= NULL) {
        PostOrder(b->lchild);
        PostOrder(b->rchild);
        printf("%c ",b->data);
    }
}
//层次遍历
void GradurationOrder(BTNode *b) {
    if(b!= NULL) {
        printf("%c ",b->data);

    }
}

//从左到右输出叶子节点
void outputLeadsLeft(BTNode *b) {
    if(b!= NULL){
        if(b->lchild == NULL && b->rchild == NULL){
            printf("%c ",b->data);
        }
        outputLeadsLeft(b->lchild);
        outputLeadsLeft(b->rchild);
    }
}

//从右到左输出叶子节点
void outputLeadsRight(BTNode *b) {
    if(b!= NULL) {
        if(b->lchild == NULL && b->rchild == NULL) {
            printf("%c ",b->data);
        }
        outputLeadsRight(b->rchild);
        outputLeadsRight(b->lchild);
    }
}

//输出有两个孩子的节点
void outputTwoChildLeads(BTNode *b) {
    if(b!= NULL) {
        if(b->lchild != NULL && b->rchild != NULL) {
            printf("%c ",b->data);
        }
        outputTwoChildLeads(b->rchild);
        outputTwoChildLeads(b->lchild);
    }
}

//输出有一个孩子的节点
void outputOneChildLeads(BTNode *b) {
    if(b!= NULL) {
        if((b->lchild != NULL && b->rchild == NULL) || (b->lchild == NULL && b->rchild!= NULL)) {
            printf("%c ",b->data);
        }
        outputOneChildLeads(b->rchild);
        outputOneChildLeads(b->lchild);
    }
}

//求二叉树中节点值为X的节点的层数
int level(BTNode *b, char c, int h) {
    int k;
    if(b == NULL) {
        return 0;
    }else if(b->data == c) {
        return h;
    }else {
        k = level(b->lchild,c,h+1);   //左孩子节点中查找
        if(k!=0){
            return k;
        }else {
            return level(b->rchild,c,h+1);  //右孩子节点中查找
        }
    }
}

//判断两个树是否相似
bool like(BTNode *b1, BTNode *b2) {
    bool like1,like2;
    if(b1 == NULL && b2 == NULL)
        return true;
    else if(b1 == NULL || b2 == NULL) {
        return false;
    }else {
        like1 = like(b1->lchild,b2->lchild);
        like2 = like(b1->rchild,b2->rchild);
        return like1&&like2;
    }
}

//求节点x的所有祖先节点
bool ancestor(BTNode *b, char x) {
    if(b == NULL) {
        return false;
    }else if(b->lchild!=NULL && b->lchild->data == x || b->rchild!=NULL && b->rchild->data == x) {
        printf("%c ",b->data);
        return true;
    }else if(ancestor(b->lchild,x) || ancestor(b->rchild,x)){
        printf("%c ",b->data);
        return true;
    }else {
        return false;
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

    printf("前序遍历结果为：");
    PreOrder(p);
    printf("\n");

    printf("中序遍历结果为：");
    InOrder(p);
    printf("\n");

    printf("后序遍历结果为：");
    PostOrder(p);
    printf("\n");

    printf("从左到右输出叶子结点为：");
    outputLeadsLeft(p);
    printf("\n");

    printf("从右到左输出叶子结点为：");
    outputLeadsRight(p);
    printf("\n");

    printf("有两个孩子的节点为：");
    outputTwoChildLeads(p);
    printf("\n");

    printf("有一个孩子的节点为：");
    outputOneChildLeads(p);
    printf("\n");

    printf("求二叉树中节点值为X的节点的层数\n");
    int ceng = level(p,'B',1);
    printf("位于第 %d 层\n",ceng);

    printf("求二叉树中节点值为X的祖先节点\n");
    ancestor(p,'G');
    printf("\n");

    return 0;
 }
