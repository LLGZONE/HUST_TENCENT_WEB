#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
 int data;
 struct Node *next;
}Node;

/*==========������ĳ�ʼ��================*/
/*
*ͷ���ָ������������Ϊ��
*/
void initList(Node **pNode){
 *pNode=NULL;
}
/*===========������Ĵ���=================*/
/*
*����ʵ�֣�ͨ���û������������ݣ���������
*�����α�����ָ�루p1,p2�����������µ����ݿ�(�����û���������)����������
*/
Node *create(Node *pHead){
 Node *p1;
 Node *p2;
 p1=p2=(Node *)malloc(sizeof(Node));     //�����ڴ�ռ�
 memset(p1,0,sizeof(Node));       //�������������
 scanf("%d",&p1->data);  //�������������p1ָ�����data��
 p1->next=NULL;
 while(p1->data>0){         //���븺������
  if(pHead==NULL)
   pHead=p1;
  else
   p2->next=p1;
  p2=p1;
  p1=(Node *)malloc(sizeof(Node));
  memset(p1,0,sizeof(Node));
  scanf("%d",&p1->data);
  p1->next=NULL;
 }
 return pHead;
}
/*=================����ı���==================*/
/**
*��ͷ��㿪ʼ�����ϱ���������������ݽ������
*/
void printList(Node *pHead){
 if(NULL==pHead)
  printf("����Ϊ��\n");
 else{
  while(pHead!=NULL){
   printf("%d ",pHead->data);
   pHead=pHead->next;
  }
 }
 printf("\n");
}
/*===============����ڵ�==================*/
/**
*Node **pNode ����ͷ���ռ��ַ
*int i ����Ҫ����Ľ��λ��
*/
void insert_data(Node **pNode,int i){
 Node *temp;
 Node *target;
 Node *p;
 int item;
 int j=1;
 printf("����Ҫ����Ľڵ�ֵ:");
 scanf("%d",&item);
 target=*pNode;
 for(;j<i-1;target=target->next,++j);  //�����ƶ�targetλ�ã���Ҫ������λ�ã�
 temp=(Node *)malloc(sizeof(Node));   //�����ڴ�ռ�
 temp->data=item;       //����Ҫ���������λ��
 p=target->next;
 target->next=temp;
 temp->next=p;
}
/*===============ɾ���ڵ�====================*/
/**
*ɾ�������ͷ��ڴ�ռ�free(temp)
*/
void delete_data(Node **pNode,int i){
 Node *target;
 Node *temp;
 int j=1;
 target=*pNode;
 for(;j<i-1;target=target->next,++j);
 temp=target->next;
 target->next=temp->next;
 free(temp);
}
/*===============���ҽ��====================*/
int search_data(Node *pNode,int elem){
 Node *target;
 int i=1;
 for(target=pNode;target->data!=elem && target->next!=NULL;++i,target=target->next);
 if(target->next==NULL)
  return 0;
 else
  return i;/**���ﻹ�ǲ�̫��....................*/

}
int main(){
 int i;
 Node *pHead=NULL;
 initList(&pHead);
 pHead=create(pHead);
 printList(pHead);
 printf("�������ڵ�λ��\n");
 scanf("%d",&i);
 insert_data(&pHead,i);
 printList(pHead);
 printf("����ɾ���ڵ�λ��\n");
 scanf("%d",&i);
 delete_data(&pHead,i);
 printList(pHead);
 printf("������ҽڵ�\n");
 scanf("%d",&i);
 printf("�ڵ�����λ�ã�%d",search_data(pHead,i));
 return 0;
}
