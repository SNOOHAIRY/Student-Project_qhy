#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD.h"

void Swap(ST *p,ST *q)     //��������
{
	ST t=*p;
	t.node=q->node;
	q->node=p->node;
	*p=*q;
	*q=t;
}

void Sort_sum(ST*head)            //���ִܷӸߵ�������
{
	ST *p,*t,*max;
	int j;
	system("CLS");
	p=head;
	max=p;
	while(p->node!=NULL)
	{
		max=p;
		t=p->node;
		while(t->node!=NULL)
		{
			if(t->sum>max->sum)
				max=t;	
			t=t->node;
		}
		if(t->node==NULL)
		{
			if(t->sum>max->sum)
				max=t;
		}
		Swap(p,max);
		p=p->node;
	}

	p=head;
	printf("�����ֳܷɼ��ߵ��������£�\n");
	for(;p!=NULL;)
	{
		printf("ѧ�ţ�%s\n������%s\n�༶��%s\n���䣺%d\n",p->num,p->nam,p->cla,p->age); 
		for(j=0;j<4;j++)
		{
			printf("��%d�ŵĿγ̣�",j+1);
			printf("�γ����ƣ�%s   ƽʱ�ɼ���%d   ���Գɼ���%d   ���Գɼ�ռ�ȣ�%f   �ܷ֣�%f  ",p->sub[j].sub_nam,p->sub[j].usgoal,p->sub[j].exgoal,p->sub[j].ratio,p->sub[j].sugoal); 
		}
		printf("���ſ�Ŀ���ܷ�Ϊ��%f\n",p->sum);
		p=p->node;
	}
	system("pause");
}




void Sort_sub(ST*head,char sub[])            //���Ƴɼ�����
{
	ST *p,*t,*max,i;
	int j,flag=0;
	system("CLS");
	p=head;
	for(;p!=NULL;)
	{
		for(j=0;j<4;j++)
		{
			if(strcmp(sub,p->sub[j].sub_nam)==0)
			{
				flag=1;
				break;
			}
		}
		if(flag) break;
		p=p->node;
	}
	if(!flag)
	{
		printf("The wrong subject!\n");
		return ;
	}
	p=head;
	max=p;
	while(p->node!=NULL)
	{
		max=p;
		t=p->node;
		while(t->node!=NULL)
		{
			if((t->sub[j].sugoal)>(max->sub[j].sugoal))
				max=t;	
			t=t->node;
		}
		if(t->node==NULL)
		{
			if((t->sub[j].sugoal)>(max->sub[j].sugoal))
				max=t;
		}
		Swap(p,max);
		p=p->node;
	} 
	p=head;
	printf("�����ֳܷɼ��ߵ��������£�\n");
	for(;p!=NULL;)
	{
		printf("ѧ�ţ�%s\n������%s\n�༶��%s\n���䣺%d\n",p->num,p->nam,p->cla,p->age); 
		printf("��%d�ŵĿγ̣�",j+1);
		printf("�γ����ƣ�%s   ƽʱ�ɼ���%d   ���Գɼ���%d   ���Գɼ�ռ�ȣ�%f   �ܷ֣�%f  ",p->sub[j].sub_nam,p->sub[j].usgoal,p->sub[j].exgoal,p->sub[j].ratio,p->sub[j].sugoal); 
		printf("���ſ�Ŀ���ܷ�Ϊ��%f\n",p->sum);
		p=p->node;
	}
	system("pause");
}
