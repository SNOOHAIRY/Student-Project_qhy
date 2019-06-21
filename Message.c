#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD.h"

void file(ST*);         //将信息存入文件

ST* Creat(ST* head)     //录入学生信息
{
	ST *curr,*p;
	int usgoal,exgoal,age,i;
	char sub[52],num[52],nam[82],cla[52];
	float ratio,sugoal,sum;
	system("CLS");
	head=curr=NULL;
	printf("请输入学生信息，以0结束\n");
	printf("请输入学生的学号：");
	getchar();
	gets(num);
	while(strcmp(num,"0")!=0)
	{
		
		p=(ST*) malloc(sizeof(ST));
		strcpy(p->num,num);
		printf("请输入学生的姓名：");
		gets(nam);
		strcpy(p->nam,nam);
		printf("请输入学生的班级：");
		gets(cla);
		strcpy(p->cla,cla);
		printf("请输入学生的年龄：");
		scanf("%d",&age);
		p->age=age;
		sum=0;
		for(i=0;i<4;i++)
		{
			printf("请输入学生的第%d门课程的信息：\n",i+1);
			printf("请输入课程的名称：");
			getchar();
			gets(nam);
			strcpy(p->sub[i].sub_nam,nam);                  //课程的名称
			printf("请输入该课程学生的平时成绩：");
			scanf("%d",&usgoal);
			p->sub[i].usgoal=usgoal;                        //该课程学生的平时成绩
			printf("请输入该课程学生的考试成绩：");
			scanf("%d",&exgoal);
			p->sub[i].exgoal=exgoal;                        //该课程学生的考试成绩
			printf("请输入该课程考试成绩所占的比例：");
			scanf("%f",&ratio);    
			p->sub[i].ratio=ratio;                          //该课程考试成绩所占的比例
			sugoal=exgoal*ratio+(1-ratio)*usgoal;           //根据比例算出总评成绩
			p->sub[i].sugoal=sugoal;
			sum+=sugoal;                                    //算出学生所有科目的总成绩
		}
		p->sum=sum;                                         
		/*建立链表*/ 
		if(head==NULL) head=p;
		else curr->node=p;
		curr=p;
		printf("请输入学生的学号：");
		getchar();
		gets(num);
	}
	curr->node=NULL;
	file(head);  //将信息存入文件
	system("pause");
	return(head);
//	free(fp);
}


ST* Chang(ST*head,char num[])   //修改学生信息
{
	ST *p;
	int i,j,age,flag=0,usgoal,exgoal,nod=1;
	float ratio;
	char sub[52],cnum[52],nam[82],cla[52],cgnam[52];
	system("CLS");
	p=head;
	for(;p!=NULL;)
	{
		if(strcmp(num,p->num)==0) 
		{
			flag=1;
			break;
		}
		p=p->node;
	}
	if(!flag) 
	{
		printf("没有找到对应的学号\n");
		system("pause");
	}
		else
	{
	while(flag)
	{
		system("CLS");
	    printf("|*************请输入你想修改的信息**********************|\n");
        printf("|                                                       |\n");
        printf("|                 1  学号                               |\n");
        printf("|                 2  姓名                               |\n");
        printf("|                 3  班级                               |\n");
        printf("|                 4  年龄                               |\n");
        printf("|                 5  成绩                               |\n");
        printf("|                                                       |\n");
        printf("|*******************************************************|\n");
		printf("请输入你的操作数：");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
			{
				printf("请输入修改后的学号：");
				fflush(stdin);
				scanf("%s",cnum);
				strcpy(p->num,cnum);
				break;
			}
			case 2:
			{
				printf("请输入修改后的姓名：");
				fflush(stdin);
				scanf("%s",nam);
				strcpy(p->nam,nam);
				break;
			}
			case 3:
			{
				printf("请输入修改后的班级：");
				fflush(stdin);
				scanf("%s",cla);
				strcpy(p->cla,cla);
				break;
			}
			case 4:
			{
				printf("请输入修改后的年龄：");
				scanf("%d",&age);
				p->age=age;
				break;
			}
			case 5:
			{
				printf("请输入你想修改的课程名称：");
				fflush(stdin);
				scanf("%s",nam);
				for(i=0;i<4;i++)
				{
					age=0;
					if(strcmp(nam,p->sub[i].sub_nam)==0) 
					{
						while(nod)
						{
							system("CLS");
							age=1;
							printf("|*************请输入你想修改的成绩信息******************|\n");
							printf("|                                                       |\n");
							printf("|                 1  科目名称                           |\n");
							printf("|                 2  科目平时成绩                       |\n");
							printf("|                 3  科目考试成绩                       |\n");
							printf("|                 4  科目考试成绩占比                   |\n");
							printf("|                                                       |\n");
							printf("|*******************************************************|\n");
							printf("请输入操作数：");
							scanf("%d",&j);
							switch(j)
							{
							case 1:
								{
									printf("请输入修改之后的名称：");
									fflush(stdin);
									scanf("%s",cgnam);
									strcpy(p->sub[i].sub_nam,cgnam);
									break;
								}
							case 2:
								{
									printf("请输入修改后的平时成绩");
									scanf("%d",usgoal);
									p->sum-=p->sub[i].sugoal;                                   //计算修改总评成绩
									p->sub[i].sugoal-=(p->sub[i].usgoal)*(1-p->sub[i].ratio);   //计算修改这门课程的总评成绩
  									p->sub[i].sugoal+=usgoal*(1-p->sub[i].ratio);
									p->sub[i].usgoal=usgoal;
									p->sum+=p->sub[i].sugoal;
									break;
								}
							case 3:
								{
									printf("请输入修改后的考试成绩");
									scanf("%d",exgoal);
									p->sum-=p->sub[i].sugoal;                                   //计算修改总评成绩
									p->sub[i].sugoal-=(p->sub[i].exgoal)*(p->sub[i].ratio);     //计算修改这门课程的总评成绩
									p->sub[i].sugoal+=exgoal*(p->sub[i].ratio);
									p->sum+=p->sub[i].sugoal;
									p->sub[i].exgoal=exgoal;
									break;
								}
							case 4:
								{
									printf("请输入修改后的成绩占比");
									scanf("%f",&ratio);
									p->sum-=p->sub[i].sugoal;                                   //计算修改总评成绩
									p->sub[i].sugoal-=p->sub[i].sugoal;                         //计算修改这门课程的总评成绩
									p->sub[i].sugoal=(p->sum)+(p->sub[i].exgoal*ratio)+(p->sub[i].usgoal)*(1-ratio);
									p->sub[i].ratio=ratio;
									p->sum+=p->sub[i].sugoal;
									break;
								}
							default: printf("输入操作数错误！");
							}
							printf("修改成功！\n是否继续修改：是1 否0:");
							scanf("%d",&nod);
							system("pause");
						}
						break;
					}
				}
			
				if(age)  printf("修改成功！\n");
				else  printf("请输入正确的课程名称！");
			}
			default: 	printf("输入操作数错误！");
		}
		printf("是否继续修改（是 1，否 0）：");
		scanf("%d",&flag);
		}
	}
	file(head);        //将信息存入文件
	return(head);
}

ST* Cut(ST*head,char num[])   //删除学生信息
{
    ST *t,*p;
	int flag=0,cont=0;
    t=NULL;
	p=head;
   // node=(SN*)malloc(sizeof(SN));
    system("CLS");
    for(;p!=NULL;)
	{
		if(strcmp(num,p->num)==0) 
		{
			flag=1;
			break;
		}
		p=p->node;
		cont++;
	}
	if(!flag) 
	{
		printf("没有找到对应的学号\n");
		system("pause");
	}
	else
	{
		t=p;
		p=t->node;
		free(t);
		printf("删除成功！\n");
		system("pause");
	}
	if(!cont)   //判断删除的是否是头节点
	{
		file(p);       //将信息存入文件
		return (p);
	}
	else
	{
		file(head);    //将信息存入文件
		return (head);
	}
}


void Add(ST* head)   //增加学生信息
{
	int usgoal,exgoal,age,i,flag=1;
	char sub[52],num[52],nam[82],cla[52];
	float ratio,sugoal,sum;
	ST *p,*t;
	t=NULL;
	system("CLS");
	p=head;
    //t=NULL;
	for(;p->node!=NULL;)
	{
		p=p->node;
	}
	while(flag)
	{
		t=p;
		p=p->node;
		p=(ST*)(malloc)(sizeof(ST));
		//printf("请输入你想添加几位学生：");
		//scanf("%d")
		printf("请输入你想添加的学生的信息：\n");
		printf("学号：");
		fflush(stdin);
		gets(num);
		strcpy(p->num,num);
		printf("请输入学生的姓名：");
		gets(nam);
		strcpy(p->nam,nam);
		printf("请输入学生的班级：");
		gets(cla);
		strcpy(p->cla,cla);
		printf("请输入学生的年龄：");
		scanf("%d",&age);
		p->age=age;
		sum=0;
		for(i=0;i<4;i++)
		{
			printf("请输入学生的第%d门课程的信息：\n",i+1);
			printf("请输入课程的名称：");
			getchar();
			gets(nam);
			strcpy(p->sub[i].sub_nam,nam);                  //课程的名称
			printf("请输入该课程学生的平时成绩：");
			scanf("%d",&usgoal);
			p->sub[i].usgoal=usgoal;                //该课程学生的平时成绩
			printf("请输入该课程学生的考试成绩：");
			scanf("%d",&exgoal);
			p->sub[i].exgoal=exgoal;                //该课程学生的考试成绩
			printf("请输入该课程考试成绩所占的比例：");
			scanf("%f",&ratio);
			p->sub[i].ratio=ratio;                  //该课程考试成绩所占的比例
			sugoal=exgoal*ratio+(1-ratio)*usgoal;    //根据比例算出总评成绩
			p->sub[i].sugoal=sugoal;
			sum+=sugoal;                             //算出总分
		}
		p->sum=sum;
		t->node=p;
		p->node=NULL;
		printf("添加成功！\n");
		system("pause");
		printf("是否还需继续添加：是 1，否 0：");
		scanf("%d",&flag);
	}
	file(head);        //将信息存入文件
}


void file(ST* head)    //将信息录入文件
{
	int j;
	ST* p;
	FILE *fp;
	p=head;    //头指针赋给p
	fp=fopen("massage.txt","w");
	if(!fp)
	{
		printf("ERROR!\n");
		exit(0);
	}
	/*将成绩输出到文件里*/
	for(;p!=NULL;)  
	{
		fprintf(fp,"%s %s %s %d",p->num,p->nam,p->cla,p->age); 
		for(j=0;j<4;j++)
		{
			fprintf(fp,"%s %d %d %f %f",p->sub[j].sub_nam,p->sub[j].usgoal,p->sub[j].exgoal,p->sub[j].ratio,p->sub[j].sugoal); 
		}
		fprintf(fp,"  %f",p->sum);
		fprintf(fp,"\n");
		p=p->node;
	}
	fclose(fp);   //关闭文件
}
