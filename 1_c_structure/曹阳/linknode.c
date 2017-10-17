#include <stdio.h>
#include <stdlib.h>
struct LNode
{
    int data;
    struct LNode * next;
};
typedef struct LNode LNode,* LinkList;
void InitList(LinkList *L)
{
    *L = (LinkList*)malloc(sizeof(struct LNode));
    (*L)->next=NULL;
}
int InsertList(LinkList  L,int j,int num)  //�ڵ�j���ڵ������µĽڵ㣬����Ϊdata
{
    int i;
    LinkList  s = L, tmp;
    for( i = 1;i<j;i++)
    {
        s = s->next;
    }
    if(j<i || !s )
    {
        printf("error");
        return 0;
    }
    else{
        tmp=(LinkList)malloc(sizeof(struct LNode));
        tmp->next = s->next;
        tmp->data = num;
        s->next = tmp;
        return 0;
    }
}
int DeleteList(LinkList  L,int j) //ɾ����j���ڵ�
{
    int i;
    LinkList  s = L,tmp;
    for(i = 2;i<j;i++)
        s = s->next;
    if(j<i || !(s->next))
    {
        printf("error");
        return 0;
    }
    else{
        tmp = s->next;
        s->next = tmp->next;
        free(tmp);

        return 0;
    }

}
int ResearchList(LinkList * L,int j,int * num)
{
    int i;
    LinkList * s = L;
    for(i = 1;i<j;i++)
        *s = (*s)->next;
    if(j<i || !(*s)->data)
    {
        printf("error");
        return 0;
    }
    else{
        *num = (*s)->data;
        return 0;
    }
}
int main(void)
{
    int length;
    LinkList S;
    InitList(&S);
    S->data=0;
    printf("����һ������,���򽫴���һ������Ϊ������ֵ�����\n�������а�˳�򴢴���Ȼ��");
    printf("Ȼ������Ļ�ϴ�ӡ������������\n");
    scanf("%d",&length);
    for(int i=length;i>0;i--)
    {
        InsertList(S,1,i);
    }
    LinkList tmp = S;
    for(int i = 0;i<length;i++)
    {
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n�����������ֱ���Ϊ���������λ�ú�����\n"
           "֮������ٴδ�ӡ�������\n");
    int num,e;
    scanf("%d %d",&num,&e);
    InsertList(S,num-1,e);
    tmp = S;
    for(int i = 0;i<length+1;i++)
    {
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n����һ�����֣�����ɾ�����λ�ò��ٴδ�ӡ�������\n");
    scanf("%d",&num);
    DeleteList(S,num);
    tmp = S;
    for(int i = 0;i<length;i++)
    {
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n����һ������,���򽫲��Ҹ�λ�����ݲ���ӡ\n");
    scanf("%d",&num);
    int * w;
    ResearchList(&S,num,w);
    printf("%d",*w);

    return 0;
}

