#include<stdio.h>
void SelectionSort(int *num,int n)
{
 int i = 0;
 int min = 0;
 int j = 0;
 int tmp = 0;
 for(i = 0;i < n-1;i++)
 {
    min = i;//ÿ�ν�min�ó���������ʼλ��Ԫ���±�
    for(j = i;j < n;j++)//���������飬�ҵ���СԪ�ء�
    {
      if(num[min]>num[j])
      {
       min = j;
      }
    }
    if(min != i)//�����СԪ�ز�����������ʼλ��Ԫ�أ�������ʼԪ�ؽ���λ��
    {
      tmp = num[min];
      num[min] = num[i];
      num[i] = tmp;
    }
 }
}

int main()
{
 int num[6] = {52,41,34,27,95,14};
 int i = 0;
 SelectionSort(num,6);//������Ҫ������Ԫ�ظ�������
 for(i = 0;i < 6;i++)
 {
   printf("%d ",num[i]);
 }
 return 0;
}
