#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10

typedef struct sequenceStack {
    int data[MaxSize];
    int top;
}seqStack;

/**
 * 初始化栈
 */
void initStack(seqStack *&s) {
    s =(seqStack *) malloc(sizeof(seqStack));
    s->top = -1;
    printf("初始化栈完毕!\n");
}

/**
 * 入栈
 */
bool push(seqStack *&s,int e) {
    if(s->top == MaxSize -1)
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}

/**
 * 出栈
 */
void pop(seqStack *s) {
    if(s->top == -1)
        return ;
    printf("出栈元素为：%d\n",s->data[s->top]);
    s->top--;
}

/**
 * 销毁栈
 */
void destoryStack(seqStack *&s) {
    free(s);  //没有释放掉
    s->top = -1;
}

/**
 * 取栈顶元素
 */
void getTop(seqStack *s) {
    if(s->top == -1)
        return ;
    printf("栈顶元素为：%d\n",s->data[s->top]);
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
