#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10

typedef struct sequenceStack {
    int data[MaxSize];
    int top;
}seqStack;

/**
 * ��ʼ��ջ
 */
void initStack(seqStack *&s) {
    s =(seqStack *) malloc(sizeof(seqStack));
    s->top = -1;
    printf("��ʼ��ջ���!\n");
}

/**
 * ��ջ
 */
bool push(seqStack *&s,int e) {
    if(s->top == MaxSize -1)
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}

/**
 * ��ջ
 */
void pop(seqStack *s) {
    if(s->top == -1)
        return ;
    printf("��ջԪ��Ϊ��%d\n",s->data[s->top]);
    s->top--;
}

/**
 * ����ջ
 */
void destoryStack(seqStack *&s) {
    free(s);  //û���ͷŵ�
    s->top = -1;
}

/**
 * ȡջ��Ԫ��
 */
void getTop(seqStack *s) {
    if(s->top == -1)
        return ;
    printf("ջ��Ԫ��Ϊ��%d\n",s->data[s->top]);
}

int main()
{
    seqStack *s;
    initStack(s);
    int a[] = {1,2,3,4,5,6,7,8};
    for(int i=0;i<8;i++) {
        push(s,a[i]);
    }
    pop(s);
    pop(s);
    getTop(s);

    destoryStack(s);
    getTop(s);
    pop(s);
    pop(s);
    pop(s);
    return 0;
}
