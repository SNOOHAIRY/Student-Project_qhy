#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD.h"

void file(ST*);         //����Ϣ�����ļ�

ST* Creat(ST* head)     //¼��ѧ����Ϣ
{
	ST *curr,*p;
	int usgoal,exgoal,age,i;
	char sub[52],num[52],nam[82],cla[52];
	float ratio,sugoal,sum;
	system("CLS");
	head=curr=NULL;
	printf("������ѧ����Ϣ����0����\n");
	printf("������ѧ����ѧ�ţ�");
	getchar();
	gets(num);
	while(strcmp(num,"0")!=0)
	{
		
		p=(ST*) malloc(sizeof(ST));
		strcpy(p->num,num);
		printf("������ѧ����������");
		gets(nam);
		strcpy(p->nam,nam);
		printf("������ѧ���İ༶��");
		gets(cla);
		strcpy(p->cla,cla);
		printf("������ѧ�������䣺");
		scanf("%d",&age);
		p->age=age;
		sum=0;
		for(i=0;i<4;i++)
		{
			printf("������ѧ���ĵ�%d�ſγ̵���Ϣ��\n",i+1);
			printf("������γ̵����ƣ�");
			getchar();
			gets(nam);
			strcpy(p->sub[i].sub_nam,nam);                  //�γ̵�����
			printf("������ÿγ�ѧ����ƽʱ�ɼ���");
			scanf("%d",&usgoal);
			p->sub[i].usgoal=usgoal;                        //�ÿγ�ѧ����ƽʱ�ɼ�
			printf("������ÿγ�ѧ���Ŀ��Գɼ���");
			scanf("%d",&exgoal);
			p->sub[i].exgoal=exgoal;                        //�ÿγ�ѧ���Ŀ��Գɼ�
			printf("������ÿγ̿��Գɼ���ռ�ı�����");
			scanf("%f",&ratio);    
			p->sub[i].ratio=ratio;                          //�ÿγ̿��Գɼ���ռ�ı���
			sugoal=exgoal*ratio+(1-ratio)*usgoal;           //���ݱ�����������ɼ�
			p->sub[i].sugoal=sugoal;
			sum+=sugoal;                                    //���ѧ�����п�Ŀ���ܳɼ�
		}
		p->sum=sum;                                         
		/*��������*/ 
		if(head==NULL) head=p;
		else curr->node=p;
		curr=p;
		printf("������ѧ����ѧ�ţ�");
		getchar();
		gets(num);
	}
	curr->node=NULL;
	file(head);  //����Ϣ�����ļ�
	system("pause");
	return(head);
//	free(fp);
}


ST* Chang(ST*head,char num[])   //�޸�ѧ����Ϣ
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
		printf("û���ҵ���Ӧ��ѧ��\n");
		system("pause");
	}
		else
	{
	while(flag)
	{
		system("CLS");
	    printf("|*************�����������޸ĵ���Ϣ**********************|\n");
        printf("|                                                       |\n");
        printf("|                 1  ѧ��                               |\n");
        printf("|                 2  ����                               |\n");
        printf("|                 3  �༶                               |\n");
        printf("|                 4  ����                               |\n");
        printf("|                 5  �ɼ�                               |\n");
        printf("|                                                       |\n");
        printf("|*******************************************************|\n");
		printf("��������Ĳ�������");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
			{
				printf("�������޸ĺ��ѧ�ţ�");
				fflush(stdin);
				scanf("%s",cnum);
				strcpy(p->num,cnum);
				break;
			}
			case 2:
			{
				printf("�������޸ĺ��������");
				fflush(stdin);
				scanf("%s",nam);
				strcpy(p->nam,nam);
				break;
			}
			case 3:
			{
				printf("�������޸ĺ�İ༶��");
				fflush(stdin);
				scanf("%s",cla);
				strcpy(p->cla,cla);
				break;
			}
			case 4:
			{
				printf("�������޸ĺ�����䣺");
				scanf("%d",&age);
				p->age=age;
				break;
			}
			case 5:
			{
				printf("�����������޸ĵĿγ����ƣ�");
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
							printf("|*************�����������޸ĵĳɼ���Ϣ******************|\n");
							printf("|                                                       |\n");
							printf("|                 1  ��Ŀ����                           |\n");
							printf("|                 2  ��Ŀƽʱ�ɼ�                       |\n");
							printf("|                 3  ��Ŀ���Գɼ�                       |\n");
							printf("|                 4  ��Ŀ���Գɼ�ռ��                   |\n");
							printf("|                                                       |\n");
							printf("|*******************************************************|\n");
							printf("�������������");
							scanf("%d",&j);
							switch(j)
							{
							case 1:
								{
									printf("�������޸�֮������ƣ�");
									fflush(stdin);
									scanf("%s",cgnam);
									strcpy(p->sub[i].sub_nam,cgnam);
									break;
								}
							case 2:
								{
									printf("�������޸ĺ��ƽʱ�ɼ�");
									scanf("%d",usgoal);
									p->sum-=p->sub[i].sugoal;                                   //�����޸������ɼ�
									p->sub[i].sugoal-=(p->sub[i].usgoal)*(1-p->sub[i].ratio);   //�����޸����ſγ̵������ɼ�
  									p->sub[i].sugoal+=usgoal*(1-p->sub[i].ratio);
									p->sub[i].usgoal=usgoal;
									p->sum+=p->sub[i].sugoal;
									break;
								}
							case 3:
								{
									printf("�������޸ĺ�Ŀ��Գɼ�");
									scanf("%d",exgoal);
									p->sum-=p->sub[i].sugoal;                                   //�����޸������ɼ�
									p->sub[i].sugoal-=(p->sub[i].exgoal)*(p->sub[i].ratio);     //�����޸����ſγ̵������ɼ�
									p->sub[i].sugoal+=exgoal*(p->sub[i].ratio);
									p->sum+=p->sub[i].sugoal;
									p->sub[i].exgoal=exgoal;
									break;
								}
							case 4:
								{
									printf("�������޸ĺ�ĳɼ�ռ��");
									scanf("%f",&ratio);
									p->sum-=p->sub[i].sugoal;                                   //�����޸������ɼ�
									p->sub[i].sugoal-=p->sub[i].sugoal;                         //�����޸����ſγ̵������ɼ�
									p->sub[i].sugoal=(p->sum)+(p->sub[i].exgoal*ratio)+(p->sub[i].usgoal)*(1-ratio);
									p->sub[i].ratio=ratio;
									p->sum+=p->sub[i].sugoal;
									break;
								}
							default: printf("�������������");
							}
							printf("�޸ĳɹ���\n�Ƿ�����޸ģ���1 ��0:");
							scanf("%d",&nod);
							system("pause");
						}
						break;
					}
				}
			
				if(age)  printf("�޸ĳɹ���\n");
				else  printf("��������ȷ�Ŀγ����ƣ�");
			}
			default: 	printf("�������������");
		}
		printf("�Ƿ�����޸ģ��� 1���� 0����");
		scanf("%d",&flag);
		}
	}
	file(head);        //����Ϣ�����ļ�
	return(head);
}

ST* Cut(ST*head,char num[])   //ɾ��ѧ����Ϣ
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
		printf("û���ҵ���Ӧ��ѧ��\n");
		system("pause");
	}
	else
	{
		t=p;
		p=t->node;
		free(t);
		printf("ɾ���ɹ���\n");
		system("pause");
	}
	if(!cont)   //�ж�ɾ�����Ƿ���ͷ�ڵ�
	{
		file(p);       //����Ϣ�����ļ�
		return (p);
	}
	else
	{
		file(head);    //����Ϣ�����ļ�
		return (head);
	}
}


void Add(ST* head)   //����ѧ����Ϣ
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
		//printf("������������Ӽ�λѧ����");
		//scanf("%d")
		printf("������������ӵ�ѧ������Ϣ��\n");
		printf("ѧ�ţ�");
		fflush(stdin);
		gets(num);
		strcpy(p->num,num);
		printf("������ѧ����������");
		gets(nam);
		strcpy(p->nam,nam);
		printf("������ѧ���İ༶��");
		gets(cla);
		strcpy(p->cla,cla);
		printf("������ѧ�������䣺");
		scanf("%d",&age);
		p->age=age;
		sum=0;
		for(i=0;i<4;i++)
		{
			printf("������ѧ���ĵ�%d�ſγ̵���Ϣ��\n",i+1);
			printf("������γ̵����ƣ�");
			getchar();
			gets(nam);
			strcpy(p->sub[i].sub_nam,nam);                  //�γ̵�����
			printf("������ÿγ�ѧ����ƽʱ�ɼ���");
			scanf("%d",&usgoal);
			p->sub[i].usgoal=usgoal;                //�ÿγ�ѧ����ƽʱ�ɼ�
			printf("������ÿγ�ѧ���Ŀ��Գɼ���");
			scanf("%d",&exgoal);
			p->sub[i].exgoal=exgoal;                //�ÿγ�ѧ���Ŀ��Գɼ�
			printf("������ÿγ̿��Գɼ���ռ�ı�����");
			scanf("%f",&ratio);
			p->sub[i].ratio=ratio;                  //�ÿγ̿��Գɼ���ռ�ı���
			sugoal=exgoal*ratio+(1-ratio)*usgoal;    //���ݱ�����������ɼ�
			p->sub[i].sugoal=sugoal;
			sum+=sugoal;                             //����ܷ�
		}
		p->sum=sum;
		t->node=p;
		p->node=NULL;
		printf("��ӳɹ���\n");
		system("pause");
		printf("�Ƿ��������ӣ��� 1���� 0��");
		scanf("%d",&flag);
	}
	file(head);        //����Ϣ�����ļ�
}


void file(ST* head)    //����Ϣ¼���ļ�
{
	int j;
	ST* p;
	FILE *fp;
	p=head;    //ͷָ�븳��p
	fp=fopen("massage.txt","w");
	if(!fp)
	{
		printf("ERROR!\n");
		exit(0);
	}
	/*���ɼ�������ļ���*/
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
	fclose(fp);   //�ر��ļ�
}