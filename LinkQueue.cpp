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

//��ʼ������
void initQueue(LiQueue *&q) {
    q = (LiQueue *)malloc(sizeof(LiQueue));
    q->reals = q->fronts = NULL;
    printf("��ʼ��������ϣ�\n");
}

//�����
void enQueue(LiQueue *&q, int e) {
    QNode *p;
    p =(QNode *) malloc(sizeof(QNode));
    p->data = e;
    p->next = NULL;
    if(q->reals == NULL){ //�������Ϊ��,�½ڵ㼴�Ƕ��׽ڵ����Ƕ�β�ڵ�
       q->reals = q->fronts = p;
    } else {  //��*p�ڵ�������β������realsָ����
        q->reals->next = p;
        q->reals = p;
    }
}

//������
void deQueue(LiQueue *&q) {
    QNode *t;
    if(q->reals == NULL) {  //����Ϊ��
        return ;
    }
    t = q->fronts;  //ָ���һ������Ԫ��
    if(q->fronts == q->reals) { //������ֻ��һ��Ԫ��,fronts��reals����ΪNULL
        q->fronts = q->reals = NULL;
    }else {
        q->fronts = q->fronts->next;
    }
    printf("����Ԫ��Ϊ��%d\n",t->data);
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


