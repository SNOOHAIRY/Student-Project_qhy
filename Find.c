#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD.h"

void Find_name(ST*head,char nam[])  //����������
{
	int j,flag=0;
	ST *p;
	p=head;
	for(;p!=NULL;)
	{
		if(strcmp(nam,p->nam)==0)   //�������ܻ����һ���ģ���������ֱ���������
		{   
			flag=1;
			printf("��ѧ������ϢΪ��");
			printf("ѧ�ţ�%s\n������%s\n�༶��%s\n���䣺%d\n",p->num,p->nam,p->cla,p->age); 
			for(j=0;j<4;j++)
			{
				printf("��%d�ŵĿγ̣�",j+1);
				printf("�γ����ƣ�%s   ƽʱ�ɼ���%d   ���Գɼ���%d   ���Գɼ�ռ�ȣ�%f   �ܷ֣�%f\n",p->sub[j].sub_nam,p->sub[j].usgoal,p->sub[j].exgoal,p->sub[j].ratio,p->sub[j].sugoal); 
			}
			printf("���ſ�Ŀ���ܷ�Ϊ��%f\n",p->sum);
		}
		p=p->node;
	}
	if(!flag) printf("The wrong name!\n");
	system("pause");
}
void Find_class(ST*head,char cla[])  //���༶����
{
	int j,flag=0;
	ST *p;
	p=head;
	for(;p!=NULL;)
	{
		if(strcmp(cla,p->cla)==0) 
		{
		//	printf("����༶����ϢΪ��");
			printf("ѧ�ţ�%s\n������%s\n�༶��%s\n���䣺%d\n",p->num,p->nam,p->cla,p->age); 
			for(j=0;j<4;j++)
			{
				printf("��%d�ŵĿγ̣�",j+1);
				printf("�γ����ƣ�%s   ƽʱ�ɼ���%d   ���Գɼ���%d   ���Գɼ�ռ�ȣ�%f   �ܷ֣�%f  ",p->sub[j].sub_nam,p->sub[j].usgoal,p->sub[j].exgoal,p->sub[j].ratio,p->sub[j].sugoal); 
			}
			printf("���ſ�Ŀ���ܷ�Ϊ��%f\n",p->sum);
			flag=1;
		}
		p=p->node;
	}
	if(!flag)  printf("The wrong class!\n");
	system("pause");
}
void Find_sub(ST*head,char sub[])     //����Ŀ��ѯ
{
	int j,flag=0;
	ST *p;
	p=head;
	for(;p!=NULL;)
	{
		for(j=0;j<4;j++)
		{
			if(strcmp(sub,p->sub[j].sub_nam)==0)
			{
				printf("���˸ÿ�Ŀ��ѧ����ϢΪ��");
				printf("ѧ�ţ�%s\n������%s\n�༶��%s\n���䣺%d\n",p->num,p->nam,p->cla,p->age); 
				//printf("��%d�ŵĿγ̣�",j+1);
				printf("�γ����ƣ�%s   ƽʱ�ɼ���%d   ���Գɼ���%d   ���Գɼ�ռ�ȣ�%f   �ܷ֣�%f\n",p->sub[j].sub_nam,p->sub[j].usgoal,p->sub[j].exgoal,p->sub[j].ratio,p->sub[j].sugoal); 
				flag=1;
			}
			
		}
		p=p->node;
	}
	if(!flag)  printf("The wrong subject!\n");
	system("pause");

}

void Find_grate(ST*head,char cla[])  //��ѯ�༶��������
{
	int sub1,sub2,sub3,sub4,flag=0;
	double cout;
	ST* p;
	p=head;
	cout=sub1=sub2=sub3=sub4=0;
	for(;p!=NULL;)
	{
		if(strcmp(cla,p->cla)==0) 
		{
			if(p->sub[0].sugoal>=90) sub1++;
			if(p->sub[1].sugoal>=90) sub2++;
			if(p->sub[2].sugoal>=90) sub3++;
			if(p->sub[3].sugoal>=90) sub4++;
			cout++;
			flag=1;
		}
		p=p->node;
	}
	if(flag)
	{
		printf("�ð༶��һ�ſ�Ŀ��������Ϊ��%f\n",sub1/cout);
		printf("�ð༶�ڶ��ſ�Ŀ��������Ϊ��%f\n",sub2/cout);
		printf("�ð༶�����ſ�Ŀ��������Ϊ��%f\n",sub3/cout);
		printf("�ð༶�����ſ�Ŀ��������Ϊ��%f\n",sub4/cout);
	}
	else printf("The wrong class!\n");
	system("pause");
}

void Find_faul(ST*head,char cla[])  //��ѯ�༶�Ĳ�������
{
	int sub1,sub2,sub3,sub4,flag=0;
	double cout;
	ST* p;
	p=head;
	cout=sub1=sub2=sub3=sub4=0;
	for(;p!=NULL;)
	{
		if(strcmp(cla,p->cla)==0) 
		{
			if(p->sub[0].sugoal<60) sub1++;
			if(p->sub[1].sugoal<60) sub2++;
			if(p->sub[2].sugoal<60) sub3++;
			if(p->sub[3].sugoal<60) sub4++;
			cout++;
			flag=1;
		}
		p=p->node;
	}
	if(flag)
	{
		printf("�ð༶��һ�ſ�Ŀ�Ĳ�������Ϊ��%f\n",sub1/cout);
		printf("�ð༶�ڶ��ſ�Ŀ�Ĳ�������Ϊ��%f\n",sub2/cout);
		printf("�ð༶�����ſ�Ŀ�Ĳ�������Ϊ��%f\n",sub3/cout);
		printf("�ð༶�����ſ�Ŀ�Ĳ�������Ϊ��%f\n",sub4/cout);
	}
	else printf("The wrong class!\n");
	system("pause");
}

void Find_num(ST*head,char num[])  //��ѧ�Ų���
{
	int j,flag=0;
	ST *p;
	p=head;
	for(;p!=NULL;)
	{
		if(strcmp(num,p->num)==0) 
		{
			flag=1;
			break;                //ѧ�Ų������һ���ģ������ҵ��ͽ���
		}
		p=p->node;
	}
	if(flag)
	{
		printf("��ѧ������ϢΪ��");
		printf("ѧ�ţ�%s\n������%s\n�༶��%s\n���䣺%d\n",p->num,p->nam,p->cla,p->age); 
		for(j=0;j<4;j++)
		{
			printf("��%d�ŵĿγ̣�",j+1);
			printf("�γ����ƣ�%s   ƽʱ�ɼ���%d   ���Գɼ���%d   ���Գɼ�ռ�ȣ�%f   �ܷ֣�%f\n",p->sub[j].sub_nam,p->sub[j].usgoal,p->sub[j].exgoal,p->sub[j].ratio,p->sub[j].sugoal); 
		}
		printf("���ſ�Ŀ���ܷ�Ϊ��%f\n",p->sum);
	}
	else printf("The wrong number!\n");
	system("pause");
}