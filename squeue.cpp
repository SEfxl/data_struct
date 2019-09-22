#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10


typedef struct qnode {
    int data[MaxSize];
    int fronts,reals;
}SqQueue;

// ��ʼ������
void initQueue(SqQueue *&q) {
    q =(SqQueue *) malloc(sizeof(SqQueue));
    q->fronts = q->reals = -1;
}

// �����
bool enQueue(SqQueue *&q, int e) {
    if((q->reals + 1)%MaxSize == q->fronts) {  //��������
        return false;
    }
    q->reals = (q->reals + 1) % MaxSize;
    q->data[q->reals] = e;
    return true;
}
// ������
void deQueue(SqQueue *&q) {
    if(q->fronts == q->reals ) { //�����ѿ�
        return ;
    }
    q->fronts = (q->fronts+1)%MaxSize;
    printf("�����У�%d\n",q->data[q->fronts]);
}

// ���ٶ���
void destroyQueue(SqQueue *&q) {
    free(q);
}

// �����Ƿ�Ϊ��
void isEmpty(SqQueue *q) {
    if(q->fronts == q->reals) {
        printf("����Ϊ��\n");
    }else {
        printf("���в�Ϊ��\n");
    }
}

// ���ζ��У�Լ���ڽ���ʱ����һ������Ԫ�ؿռ�
// ����������(q->reals +1) % MaxSize == q->fronts
// �Կ�������q->reals == q->fronts
int main()
{
    SqQueue *q;
    initQueue(q);
    int num = 9;
    for(int i=1;i<=num;i++) {
        enQueue(q,i);
    }
    for(int i=1;i<=num;i++) {
        deQueue(q);
    }
    isEmpty(q);

    return 0;
}
