#include "LimkList.h"

LinkList MakeNode(ElemType n){
    LinkList p=NULL;

    p = (LinkList)malloc(sizeof(LNode));
    if (p==NULL) return NULL;

    p->data = n;
    p->next = NULL;
 
    return p;
}

/*
* 尾插入
*/
LNode *createLinkList_tail_in(int a[], int n){
    LinkList head = NULL;
    LinkList p_fa = NULL;
    int i = 0;
    while (i<n)
    {
        if(i==0){
            p_fa = head = MakeNode(a[i++]);
            if(p_fa==NULL) return NULL;
        }
        else{
            p_fa->next = MakeNode(a[i++]);
            p_fa = p_fa->next;
            if(p_fa==NULL) return NULL;
        }
    }
    

    return head;
}


/*
* 头插入
*/
LNode *createLinkList_head_in(int a[], int n){
    LinkList head = (LinkList)malloc(sizeof(LNode));
    head->data = a[0];
    while (n>=1)
    {
        LinkList p = MakeNode(a[n--]);
        p->next = head->next;
        head->next = p;
    }
    
    return head;
}

Status free_L(LinkList &head){
    LinkList t_p = head->next;

    while(t_p!=NULL){
        free(head);
        head = t_p;
        t_p = t_p->next;
    }
    free(head);
    head = NULL;
    return OK;
}


void visit(LinkList head){
    while(head != NULL){
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(){
    LNode *p=NULL;
    LinkList q=NULL;
    //malloc 
    // p = MakeNode(1);
    // q = MakeNode(2);

    // p->next = q;

    // printf("%d", p->data);
    // printf("%d", q->data);
    int num;
    printf("想要创建的长度:");
    scanf("%d", &num);
    int *a = (int*)malloc(sizeof(int)*num);
    
    for(int i=0;i<num;i++){
        a[i] = i+1;
        printf("%d", a[i]);
    }

    printf("\n================\n");
    LinkList head1=NULL;
    head1 = createLinkList_tail_in(a, num);
    visit(head1);
    free_L(head1);
    visit(head1);


    LinkList head2=NULL;
    printf("\n================\n");
    head2 = createLinkList_tail_in(a, num);
    visit(head2);
    free_L(head2);
    visit(head2);
     return 0;
}