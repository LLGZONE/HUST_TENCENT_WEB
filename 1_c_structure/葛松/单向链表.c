#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct list{
    struct list *next;
    char name[30];//�û�����
    char addr[50];//��ַ
    char num[8];//����
}user;

void insert(user *h);
void edit(user *h);
void del(user *h);
void S_byName(user *h);
void S_byNum(user *h);
void display(user *h);

int main()
{
    int flag;
    user *head=(user *)malloc(sizeof(user));
    head->next=NULL;
    while(1)
    {
        printf("�绰����Ŀ¼ϵͳ\n");
        printf("    1������µ绰�û���Ϣ\n");
        printf("    2���޸ĵ绰�û���Ϣ\n");
        printf("    3��ɾ�����е绰�û���Ϣ\n");
        printf("    4�������û�����ѯ�绰��Ϣ\n");
        printf("    5�����ݵ绰�����ѯ�û���Ϣ\n");
        printf("    6����ʾȫ���û���Ϣ\n");
        printf("    7���˳�\n");
        printf("��ѡ��");
        scanf("%d",&flag);
        if(flag==1)
            insert(head);
        else if(flag==2)
            edit(head);
        else if(flag==3)
            del(head);
        else if(flag==4)
            S_byName(head);
        else if(flag==5)
               S_byNum(head);
          else if(flag==6)
            display(head);
        else if(flag==7)
            return 0;
        else
            printf("��������������ѡ��\n");
    }
}
void insert(user *h)
{
    user *p=(user *)malloc(sizeof(user));
    p->next=h->next;
    h->next=p;
    printf("�����������û����ƣ����30���֣���");
    scanf("%s",p->name);
    printf("�����������û��ļ�ͥסַ(���50��)��");
    scanf("%s",p->addr);
    printf("�����������û��ĵ绰���루8λ������");
    scanf("%s",p->num);
    printf("���û���¼�ɹ���ӣ�%s  %s  %s\n\n",p->name,p->addr,p->num);
}
void edit(user *h)
{
    char name[30];
    int flag=0;
    user *lh=h->next;
    printf("����Ҫ�޸��û������ƣ�");
    scanf("%s",name);
    while(lh)
    {
        if(strcmp(name,lh->name)==0)
        {
            flag=1;
            printf("�������µ����ƣ�30�����ڣ���");
            scanf("%s",lh->name);
            printf("�������µĵ�ַ��50�����ڣ�:");
            scanf("%s",lh->addr);
            printf("�������µĺ���(8λ)��");
            scanf("%s",lh->num);
            printf("�û���¼�޸ĳɹ���%s  %s  %s\n\n",lh->name,lh->addr,lh->num);
            break;
        }
        lh=lh->next;
    }
    if(!flag)
        printf("�������������û�\n\n");
}
void S_byName(user *h)
{
    char name[30];
    int flag=0;
    user *lh=h->next;
    printf("����Ҫ���ҵ��û����ƣ�");
    scanf("%s",name);
    while(lh)
    {
        if(strcmp(name,lh->name)==0)
        {
            flag=1;
            printf("�û���ϢΪ��%s  %s  %s\n\n",lh->name,lh->addr,lh->num);
            break;
        }
        lh=lh->next;
    }
    if(!flag)
        printf("�û���������\n\n");
}
void S_byNum(user *h)
{
    char num[30];
    int flag=0;
    user *lh=h->next;
    printf("����Ҫ���ҵĵ绰���룺");
    scanf("%s",num);
    while(lh)
    {
        if(strcmp(num,lh->num)==0)
        {
            flag=1;
            printf("�û���ϢΪ��%s  %s  %s\n\n",lh->name,lh->addr,lh->num);
            break;
        }
        lh=lh->next;
    }
    if(!flag)
        printf("�Ҳ���ƥ��ĺ���\n\n");
}
void display(user *h)
{
    user *lh=h->next;
    int i=1;
    while(lh)
    {
        printf("��%d���û���Ϣ:%s  %s  %s\n",i,lh->name,lh->addr,lh->num);
        lh=lh->next;
        i++;
    }
    printf("\n");
}
void del(user *h)
{
    char name[30];
    int flag=0;
    user *lh=h;
    printf("����Ҫɾ�����û����ƣ�");
    scanf("%s",name);
    while(lh->next)
    {
        if(strcmp(name,lh->next->name)==0)
        {
            flag=1;
            printf("ɾ���û��ɹ���%s  %s  %s\n\n",lh->next->name,lh->next->addr,lh->next->num);
            lh->next=lh->next->next;
            break;
        }
        lh=lh->next;
    }
    if(!flag)
        printf("�û���������\n\n");
}
