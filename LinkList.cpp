#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}LinkList;
void Display(LinkList *L);
/**
 * ͷ�巨��������
 * @param L
 * @param length
 * @param a
 */
void CreateByHead(LinkList *&L, int length, const int *a) {
    L =(LinkList *) malloc(sizeof(LinkList));
    L->next = NULL;
    LinkList *s ; //���ݽ��
    for (int i = 0; i < length; ++i) {
        s =(LinkList *) malloc(sizeof(LinkList));
        s->data = a[i];

        s->next = L->next;  //ÿ�ζ����뵽ͷ�����棬���˳��ߵ����������
        L->next = s;
    }
}

/**
 * β�巨��������
 * @param L
 * @param length
 * @param a
 */
void CreateByTail(LinkList *&L, int length, const int *a) {
    L =(LinkList *) malloc(sizeof(LinkList));
    L->next = NULL;
    LinkList *s,*r;  //*s���ݽ�㣬*rβ���
    r=L;
    for (int i = 0; i < length; ++i) {
        s = (LinkList *) malloc(sizeof(LinkList));
        s->data = a[i];

        r->next = s;  //rָ��ʼ��ָ���²��������
        r=s;   //rʼ��ָ��ǰ��㣬Ҳ����rָ�����
    }
    r->next = NULL;  //β�����null

}

/**
 * ��������ɾ��ֵΪvalue��Ԫ��
 * @param L
 * @param value
 */
void DeleteRegularValue(LinkList *&L, int value) {
   LinkList *p=L->next;
   LinkList *q,*pre=L; //pre��¼��ǰ�ڵ��ǰ���ڵ�
   while (p != NULL) {
       if(p->data == value) {
            q=p;
            pre->next = p->next;  //��һ������һ��ͬ���ƶ���P����һ���ڵ㣬ѭ���ж���һ���ڵ�
            p=p->next;
           free(q);
       }else {
           pre = p;
           p = p->next;
       }

   }
}

/**
 * ��������ɾ����num��Ԫ��
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
1������ת
2�������л��ļ��
3��������������ϲ�
4��ɾ�������е�����N���ڵ�
5����������м�ڵ�
*/

/**
 * ����ת
 * @param L
 */
void ReverseLinkList(LinkList *&L) {
    LinkList *p1 = L, *p2 = L->next, *p3 = NULL;  //p2ָ���һ������ݽ�㣬p1Ϊǰһ����㣬p3Ϊp2�ĺ�̽��
    while (p2 != NULL) {
        p3 = p2->next;  //��¼��һ������ָ�룬��ֹ����
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }
    L->next = NULL;  //ԭ����ͷ��㣬��λNULL
    L=p1;  //��ת֮��ȱ��ͷ�ڵ�
}

/**
 * �������Ƿ���ڻ�
 * @param L
*/
void HasCircle(LinkList *L) {
    if(L == NULL || L->next == NULL)
    {
        printf("\n����Ϊ�գ����߲����ڻ�\n");
        return ;
    }
    LinkList *slow = L->next, *quick = L->next->next;
    while(quick != NULL && quick->next != NULL) {
        if(quick == slow) {
            printf("\n�����д��ڻ�\n");
            return ;
        }
        quick = quick->next->next;
        slow = slow->next;
    }
    printf("\n�����в����ڻ�\n");

}

/**
 * ��ȡ�����м�ڵ�
 * @param L
*/
void GetMiddleNode(LinkList *L) {
    LinkList *p1=L,*p2=L;  //����ָ�룬p1λ��ָ�룬һ����һ����P2λ��ָ�룬һ��������
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
 * ɾ�������е�����N���ڵ�
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
    if(!fast) {  //n�պõ���������
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
 * �ϲ��������������ϲ���֮��ʹ������
 * @param L
*/
LinkList *MergeOrderLinkList(LinkList *L1, LinkList *L2) {

    printf("*********************�ϲ�֮ǰ\n");
    Display(L1);
    Display(L2);
    printf("*********************�ϲ�֮ǰ\n");

    LinkList *p1,*p2,*p,*head;
    p1 = L1;
    p2 = L2;
    if(L1 == NULL) {   //��һ��Ϊ��ֱ�ӷ�����һ��
        return L2;
    }else if(L2 == NULL) {
        return L1;
    }

    if(p1->data < p2->data) {  //��С��һ������ȷ���µ������ͷ
        head = p1;
        p1 = p1->next;
    }else {
        head = p2;
        p2 = p2->next;
    }
    p = head;
    while(p1 != NULL && p2 != NULL) {  //���αȽϽ�С������׷����pZָ�� :Pָ�����β�巨�е�βָ��
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

    if(p1 != NULL) {   //��ʣ��������������
        p->next = p1;
    }else {
        p->next = p2;
    }
    return head;

}

LinkList *Merge(LinkList *L1, LinkList *L2) {

    printf("*********************�ϲ�֮ǰ\n");
    Display(L1);
    Display(L2);
    printf("*********************�ϲ�֮ǰ\n");

    LinkList *pa, *pb, *pc, *L;
	L = (LinkList *)malloc(sizeof(LinkList));    //����һ��ͷ���L.
	pa = L1->next;    //ָ��paָ��L1�ĵ�һ����㡣
	pb = L2->next;    //ָ��pbָ��L2�ĵ�һ����㡣
	pc = L;    //ָ��pcָ�����洴����ͷ���L.
	while ( pa && pb ) {    //��L1��L2����û�б�����ɵ�ʱ��
		if ( pa->data <= pb->data ) {    //��pa��������С��
			pc->next = pa;    //��pa����L�С�
			pc = pa;    //pc����ǰ���һ�����pa����Ҳ��β�塣
			pa = pa->next;    //��L1�����У�����paλ�á�
		} else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
    /*���L1δ�����꣬��L1ȫ������L�����L2δ�����꣬��L2ȫ������L*/
	pc->next = pa ? pa : pb;
	L1->next = NULL;
	L2->next = NULL;

	return L;
}

/**
 * �������
 * @param L
 */
void Display(LinkList *L) {
    LinkList *p = L->next;
    printf("Ԫ������Ϊ��");
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
 * �������
 * @param L
 */
void DisplayNoHead(LinkList *L) {
    LinkList *p = L;
    printf("Ԫ������Ϊ��");
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
