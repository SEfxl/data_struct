#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10


typedef struct qnode {
    int data[MaxSize];
    int fronts,reals;
}SqQueue;

// 初始化队列
void initQueue(SqQueue *&q) {
    q =(SqQueue *) malloc(sizeof(SqQueue));
    q->fronts = q->reals = -1;
    printf("初始化队列完毕!\n");
}

// 入队列
bool enQueue(SqQueue *&q, int e) {
    if((q->reals + 1)%MaxSize == q->fronts) {  //队列已满
        return false;
    }
    q->reals = (q->reals + 1) % MaxSize;
    q->data[q->reals] = e;
    return true;
}
// 出队列
void deQueue(SqQueue *&q) {
    if(q->fronts == q->reals ) { //队列已空
        return ;
    }
    q->fronts = (q->fronts+1)%MaxSize;
    printf("出队列：%d\n",q->data[q->fronts]);
}

// 销毁队列
void destroyQueue(SqQueue *&q) {
    free(q);
}

// 队列是否为空
void isEmpty(SqQueue *q) {
    if(q->fronts == q->reals) {
        printf("队列为空\n");
    }else {
        printf("队列不为空\n");
    }
}
//求解报数问题
void number(SqQueue *&q) {
    printf("出列顺序为：");
    while(q->fronts!=q->reals) {
        q->fronts = (q->fronts+1)%MaxSize;
        printf("%d ",q->data[q->fronts]);
        if(q->fronts != q->reals) {
            q->fronts = (q->fronts+1)%MaxSize;
            q->reals = (q->reals+1)%MaxSize;
            q->data[q->reals] = q->data[q->fronts];
        }
    }
    printf("\n");
}

// 环形队列，约定在进队时少用一个数据元素空间
// 队满条件：(q->reals +1) % MaxSize == q->fronts
// 对空条件：q->reals == q->fronts
int main()
{
    SqQueue *q;
    initQueue(q);
    int num = 8;
    for(int i=1;i<=num;i++) {
        enQueue(q,i);
    }
    number(q);

    //for(int i=1;i<=num;i++) {
    //    deQueue(q);
    //}
    //isEmpty(q);

    return 0;
}
