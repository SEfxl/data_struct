#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}LinkList;
void Display(LinkList *L);
/**
 * 头插法建立链表
 * @param L
 * @param length
 * @param a
 */
void CreateByHead(LinkList *&L, int length, const int *a) {
    L =(LinkList *) malloc(sizeof(LinkList));
    L->next = NULL;
    LinkList *s ; //数据结点
    for (int i = 0; i < length; ++i) {
        s =(LinkList *) malloc(sizeof(LinkList));
        s->data = a[i];

        s->next = L->next;  //每次都插入到头结点后面，如果顺序颠倒则链表断裂
        L->next = s;
    }
}

/**
 * 尾插法建立链表
 * @param L
 * @param length
 * @param a
 */
void CreateByTail(LinkList *&L, int length, const int *a) {
    L =(LinkList *) malloc(sizeof(LinkList));
    L->next = NULL;
    LinkList *s,*r;  //*s数据结点，*r尾结点
    r=L;
    for (int i = 0; i < length; ++i) {
        s = (LinkList *) malloc(sizeof(LinkList));
        s->data = a[i];

        r->next = s;  //r指针始终指向新插入的数据
        r=s;   //r始终指向当前结点，也就是r指针后移
    }
    r->next = NULL;  //尾结点致null

}

/**
 * 从链表中删除值为value的元素
 * @param L
 * @param value
 */
void DeleteRegularValue(LinkList *&L, int value) {
   LinkList *p=L->next;
   LinkList *q,*pre=L; //pre记录当前节点的前驱节点
   while (p != NULL) {
       if(p->data == value) {
            q=p;
            pre->next = p->next;  //这一步和下一步同步移动到P的下一个节点，循环判断下一个节点
            p=p->next;
           free(q);
       }else {
           pre = p;
           p = p->next;
       }

   }
}

/**
 * 从链表中删除第num个元素
 * @param L
 * @param index
 */
void DeleteIndexValue(LinkList *&L, int num) {
   int j=0;
   LinkList *p=L,*q;
   while(j < num-1 && p != NULL) {
        j++;
        p=p->next;
   }
   if(p == NULL) {
        return ;
   }else{
       q = p->next;
       if(q == NULL)
            return ;
       p->next = q->next;
       free(q);
   }
}

/*
1、链表反转
2、链表中环的检测
3、两个有序链表合并
4、删除链表中倒数第N个节点
5、求链表的中间节点
*/

/**
 * 链表反转
 * @param L
 */
void ReverseLinkList(LinkList *&L) {
    LinkList *p1 = L, *p2 = L->next, *p3 = NULL;  //p2指向第一你个数据结点，p1为前一个结点，p3为p2的后继结点
    while (p2 != NULL) {
        p3 = p2->next;  //记录下一个结点的指针，防止断裂
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }
    L->next = NULL;  //原来的头结点，置位NULL
    L=p1;  //翻转之后缺少头节点
}

/**
 * 链表中是否存在环
 * @param L
*/
void HasCircle(LinkList *L) {
    if(L == NULL || L->next == NULL)
    {
        printf("\n链表为空，或者不存在环\n");
        return ;
    }
    LinkList *slow = L->next, *quick = L->next->next;
    while(quick != NULL && quick->next != NULL) {
        if(quick == slow) {
            printf("\n链表中存在环\n");
            return ;
        }
        quick = quick->next->next;
        slow = slow->next;
    }
    printf("\n链表中不存在环\n");

}

/**
 * 获取链表中间节点
 * @param L
*/
void GetMiddleNode(LinkList *L) {
    LinkList *p1=L,*p2=L;  //快慢指针，p1位慢指针，一次走一步：P2位快指针，一次走两步
    while(p2!= NULL) {
        if(p2->next != NULL) {
             p2 = p2->next->next;
        }else {
            break;
        }
        p1 = p1->next;
    }
    printf("middle_num = %d\n",p1->data);

}

/**
 * 删除链表中倒数第N个节点
 * @param L
*/
void DeleteDescNode(LinkList *&L, int n) {
    LinkList *fast = L, *slow = L, *del = NULL;

    if(fast == NULL){
        return ;
    }

    while(n--) {
        fast = fast->next;
    }
    printf("\ndata = %d \n",fast->data);
    if(!fast) {  //n刚好等于链表长度
        printf("first data=%d\n",fast->data);
        return ;
    }
    while(fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    del = slow->next;
    slow->next = del->next;
    free(del);
    return ;
}

/**
 * 合并两个有序链表，合并完之后使其有序
 * @param L
*/
LinkList *MergeOrderLinkList(LinkList *L1, LinkList *L2) {

    printf("*********************合并之前\n");
    Display(L1);
    Display(L2);
    printf("*********************合并之前\n");

    LinkList *p1,*p2,*p,*head;
    p1 = L1;
    p2 = L2;
    if(L1 == NULL) {   //有一个为空直接返回另一个
        return L2;
    }else if(L2 == NULL) {
        return L1;
    }

    if(p1->data < p2->data) {  //用小的一个链表确定新的链表表头
        head = p1;
        p1 = p1->next;
    }else {
        head = p2;
        p2 = p2->next;
    }
    p = head;
    while(p1 != NULL && p2 != NULL) {  //依次比较将小的依次追加至pZ指针 :P指针就是尾插法中的尾指针
        if(p1->data <= p2->data) {
            p->next = p1;
            p = p1;
            p1 = p1->next;
        } else {
            p->next = p2;
            p = p2;
            p2 = p2->next;
        }
    }

    if(p1 != NULL) {   //将剩余的添加至链表中
        p->next = p1;
    }else {
        p->next = p2;
    }
    return head;

}

LinkList *Merge(LinkList *L1, LinkList *L2) {

    printf("*********************合并之前\n");
    Display(L1);
    Display(L2);
    printf("*********************合并之前\n");

    LinkList *pa, *pb, *pc, *L;
	L = (LinkList *)malloc(sizeof(LinkList));    //申请一个头结点L.
	pa = L1->next;    //指针pa指向L1的第一个结点。
	pb = L2->next;    //指针pb指向L2的第一个结点。
	pc = L;    //指针pc指向上面创立的头结点L.
	while ( pa && pb ) {    //当L1和L2链表都没有遍历完成的时候。
		if ( pa->data <= pb->data ) {    //若pa结点的数据小。
			pc->next = pa;    //把pa串入L中。
			pc = pa;    //pc移向当前最后一个结点pa，这也是尾插。
			pa = pa->next;    //在L1链表中，更新pa位置。
		} else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
    /*如果L1未遍历完，将L1全部串入L，如果L2未遍历完，将L2全部串入L*/
	pc->next = pa ? pa : pb;
	L1->next = NULL;
	L2->next = NULL;

	return L;
}

/**
 * 输出链表
 * @param L
 */
void Display(LinkList *L) {
    LinkList *p = L->next;
    printf("元素依次为：");
    while (p != NULL) {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

void show(LinkList *L) {
    LinkList *slow = L->next;
    printf("%d",slow->data);
}

/**
 * 输出链表
 * @param L
 */
void DisplayNoHead(LinkList *L) {
    LinkList *p = L;
    printf("元素依次为：");
    while (p != NULL) {
        printf("\n head = %d \n",p->data);
        p = p->next;
    }
    printf("\n");
}


int main()
{
    //int a[]={1,2,3,4,5};
    //int a[] ={1};
    int a[] ={1,2,5};
    int b[] ={1,3,4};
    LinkList *L,*L2,*L3;
    int length = sizeof(a)/sizeof(int);
    int length2 = sizeof(b)/sizeof(int);
    //CreateByHead(L,length,a);
    CreateByTail(L,length,a);
    Display(L);

    CreateByTail(L2,length2,b);
    Display(L2);
    //show(L);
    //DeleteRegularValue(L,3);
    //Display(L);

    //DeleteIndexValue(L,4);
    //Display(L);

    //ReverseLinkList(L);
    //DisplayNoHead(L);

    //GetMiddleNode(L);

    //DeleteDescNode(L,1);
    //Display(L);

    //L3 = MergeOrderLinkList(L,L2);


    L3 = Merge(L,L2);
    Display(L3);

    return 0;
}
