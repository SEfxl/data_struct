#include<stdio.h>
#include<stdlib.h>

typedef struct qnode {
    int data;
    struct qnode *next;
}QNode;

typedef struct {
    QNode *fronts;
    QNode *reals;
}LiQueue;

//初始化队列
void initQueue(LiQueue *&q) {
    q = (LiQueue *)malloc(sizeof(LiQueue));
    q->reals = q->fronts = NULL;
    printf("初始化队列完毕！\n");
}

//入队列
void enQueue(LiQueue *&q, int e) {
    QNode *p;
    p =(QNode *) malloc(sizeof(QNode));
    p->data = e;
    p->next = NULL;
    if(q->reals == NULL){ //如果队列为空,新节点即是队首节点又是队尾节点
       q->reals = q->fronts = p;
    } else {  //将*p节点链到队尾，并将reals指向它
        q->reals->next = p;
        q->reals = p;
    }
}

//出队列
void deQueue(LiQueue *&q) {
    QNode *t;
    if(q->reals == NULL) {  //队列为空
        return ;
    }
    t = q->fronts;  //指向第一个数据元素
    if(q->fronts == q->reals) { //队列中只有一个元素,fronts和reals都置为NULL
        q->fronts = q->reals = NULL;
    }else {
        q->fronts = q->fronts->next;
    }
    printf("出队元素为：%d\n",t->data);
    free(t);
}

int main()
{
    LiQueue *q;
    initQueue(q);
    for(int i=1;i<=8;i++) {
        enQueue(q,i);
    }
    deQueue(q);
    deQueue(q);

    return 0;
}


