#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD.h"

void Swap(ST *p,ST *q)     //交换函数
{
	ST t=*p;
	t.node=q->node;
	q->node=p->node;
	*p=*q;
	*q=t;
}

void Sort_sum(ST*head)            //按总分从高到低排序
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
	printf("按照总分成绩高低排序如下：\n");
	for(;p!=NULL;)
	{
		printf("学号：%s\n姓名：%s\n班级：%s\n年龄：%d\n",p->num,p->nam,p->cla,p->age); 
		for(j=0;j<4;j++)
		{
			printf("第%d门的课程：",j+1);
			printf("课程名称：%s   平时成绩：%d   考试成绩：%d   考试成绩占比：%f   总分：%f  ",p->sub[j].sub_nam,p->sub[j].usgoal,p->sub[j].exgoal,p->sub[j].ratio,p->sub[j].sugoal); 
		}
		printf("四门科目的总分为：%f\n",p->sum);
		p=p->node;
	}
	system("pause");
}




void Sort_sub(ST*head,char sub[])            //单科成绩排名
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
	printf("按照总分成绩高低排序如下：\n");
	for(;p!=NULL;)
	{
		printf("学号：%s\n姓名：%s\n班级：%s\n年龄：%d\n",p->num,p->nam,p->cla,p->age); 
		printf("第%d门的课程：",j+1);
		printf("课程名称：%s   平时成绩：%d   考试成绩：%d   考试成绩占比：%f   总分：%f  ",p->sub[j].sub_nam,p->sub[j].usgoal,p->sub[j].exgoal,p->sub[j].ratio,p->sub[j].sugoal); 
		printf("四门科目的总分为：%f\n",p->sum);
		p=p->node;
	}
	system("pause");
}
