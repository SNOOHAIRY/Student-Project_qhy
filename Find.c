#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD.h"

void Find_name(ST*head,char nam[])  //按姓名查找
{
	int j,flag=0;
	ST *p;
	p=head;
	for(;p!=NULL;)
	{
		if(strcmp(nam,p->nam)==0)   //姓名可能会出现一样的，所以搜索直到链表结束
		{   
			flag=1;
			printf("该学生的信息为：");
			printf("学号：%s\n姓名：%s\n班级：%s\n年龄：%d\n",p->num,p->nam,p->cla,p->age); 
			for(j=0;j<4;j++)
			{
				printf("第%d门的课程：",j+1);
				printf("课程名称：%s   平时成绩：%d   考试成绩：%d   考试成绩占比：%f   总分：%f\n",p->sub[j].sub_nam,p->sub[j].usgoal,p->sub[j].exgoal,p->sub[j].ratio,p->sub[j].sugoal); 
			}
			printf("四门科目的总分为：%f\n",p->sum);
		}
		p=p->node;
	}
	if(!flag) printf("The wrong name!\n");
	system("pause");
}
void Find_class(ST*head,char cla[])  //按班级查找
{
	int j,flag=0;
	ST *p;
	p=head;
	for(;p!=NULL;)
	{
		if(strcmp(cla,p->cla)==0) 
		{
		//	printf("这个班级的信息为：");
			printf("学号：%s\n姓名：%s\n班级：%s\n年龄：%d\n",p->num,p->nam,p->cla,p->age); 
			for(j=0;j<4;j++)
			{
				printf("第%d门的课程：",j+1);
				printf("课程名称：%s   平时成绩：%d   考试成绩：%d   考试成绩占比：%f   总分：%f  ",p->sub[j].sub_nam,p->sub[j].usgoal,p->sub[j].exgoal,p->sub[j].ratio,p->sub[j].sugoal); 
			}
			printf("四门科目的总分为：%f\n",p->sum);
			flag=1;
		}
		p=p->node;
	}
	if(!flag)  printf("The wrong class!\n");
	system("pause");
}
void Find_sub(ST*head,char sub[])     //按科目查询
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
				printf("考了该科目的学生信息为：");
				printf("学号：%s\n姓名：%s\n班级：%s\n年龄：%d\n",p->num,p->nam,p->cla,p->age); 
				//printf("第%d门的课程：",j+1);
				printf("课程名称：%s   平时成绩：%d   考试成绩：%d   考试成绩占比：%f   总分：%f\n",p->sub[j].sub_nam,p->sub[j].usgoal,p->sub[j].exgoal,p->sub[j].ratio,p->sub[j].sugoal); 
				flag=1;
			}
			
		}
		p=p->node;
	}
	if(!flag)  printf("The wrong subject!\n");
	system("pause");

}

void Find_grate(ST*head,char cla[])  //查询班级的优秀率
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
		printf("该班级第一门科目的优秀率为：%f\n",sub1/cout);
		printf("该班级第二门科目的优秀率为：%f\n",sub2/cout);
		printf("该班级第三门科目的优秀率为：%f\n",sub3/cout);
		printf("该班级第四门科目的优秀率为：%f\n",sub4/cout);
	}
	else printf("The wrong class!\n");
	system("pause");
}

void Find_faul(ST*head,char cla[])  //查询班级的不及格率
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
		printf("该班级第一门科目的不及格率为：%f\n",sub1/cout);
		printf("该班级第二门科目的不及格率为：%f\n",sub2/cout);
		printf("该班级第三门科目的不及格率为：%f\n",sub3/cout);
		printf("该班级第四门科目的不及格率为：%f\n",sub4/cout);
	}
	else printf("The wrong class!\n");
	system("pause");
}

void Find_num(ST*head,char num[])  //按学号查找
{
	int j,flag=0;
	ST *p;
	p=head;
	for(;p!=NULL;)
	{
		if(strcmp(num,p->num)==0) 
		{
			flag=1;
			break;                //学号不会出现一样的，所以找到就结束
		}
		p=p->node;
	}
	if(flag)
	{
		printf("该学生的信息为：");
		printf("学号：%s\n姓名：%s\n班级：%s\n年龄：%d\n",p->num,p->nam,p->cla,p->age); 
		for(j=0;j<4;j++)
		{
			printf("第%d门的课程：",j+1);
			printf("课程名称：%s   平时成绩：%d   考试成绩：%d   考试成绩占比：%f   总分：%f\n",p->sub[j].sub_nam,p->sub[j].usgoal,p->sub[j].exgoal,p->sub[j].ratio,p->sub[j].sugoal); 
		}
		printf("四门科目的总分为：%f\n",p->sum);
	}
	else printf("The wrong number!\n");
	system("pause");
}