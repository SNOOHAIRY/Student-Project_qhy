#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD.h"

extern ST* Creat(ST*);                        //¼��ѧ����Ϣ
extern ST* Chang(ST*,char[]);                 //�޸�ѧ����Ϣ
extern void Add(ST*);                          //����ѧ����Ϣ
extern ST* Cut(ST*,char[]);                   //ɾ��ѧ����Ϣ
extern void Find_name(ST*,char[]);            //��������ѯ
extern void Find_class(ST*,char[]);           //���༶��ѯ
extern void Find_num(ST*,char[]);             //��ѧ�Ų�ѯ
extern void Find_sub(ST*,char[]);             //���γ����Ʋ�ѯ
extern void Find_grate(ST*,char[]);           //��ѯ�༶������
extern void Find_faul(ST*head,char cla[]);    //��ѯ�༶��������
extern void Sort_sum(ST*);                    //���ָܷߵ�����
extern void Sort_sub(ST*,char[]);             //���Ƴɼ�����


//void Menu();


int main()
{
	ST *head=NULL;
//	int usgoal,exgoal,age,i,j,cout=0;
	char sub[52],num[52],nam[82],cla[52];
	int a;
	while(1)
	{
		system("CLS");
        printf("|********************ѧ������ϵͳ***********************|\n");
        printf("|                                                       |\n");
        printf("|                 1  ����ѧ����Ϣ                       |\n");
        printf("|                 2  �޸�ѧ����Ϣ                       |\n");
        printf("|                 3  ����ѧ����Ϣ                       |\n");
        printf("|                 4  ɾ��ѧ����Ϣ                       |\n");
        printf("|                 5  ��������ѯ                         |\n");
        printf("|                 6  ���༶��ѯ                         |\n");
        printf("|                 7  ��ѧ�Ų�ѯ                         |\n");
        printf("|                 8  ���γ����Ʋ�ѯ                     |\n");
        printf("|                 9  ���ִܷӸߵ�����                   |\n");
        printf("|                10  ���Ƴɼ�����                       |\n");
        printf("|                11  ��ѯ�༶������                     |\n");
		printf("|                12  ��ѯ�༶��������                   |\n");
        printf("|                13  �˳�ϵͳ                           |\n");
        printf("|                                                       |\n");
        printf("|*******************************************************|\n");
        printf("�������������");
        scanf("%d",&a);
        switch(a)
        {
        case 1:  //����ѧ����Ϣ
            {
                head=Creat(head);
                break;
            }
        case 2:  //�޸�ѧ����Ϣ
            {
				system("CLS");
				printf("�����������޸ĵ�ѧ����ѧ�ţ�");
				fflush(stdin);
				gets(num);
				head=Chang(head,num);
				break;
            }
        case 3:  //����ѧ����Ϣ
        {
			system("CLS");
            Add(head);
            break;
        }
        case 4:  //ɾ��ѧ����Ϣ
			{
				system("CLS");
			    printf("����������ɾ����ѧ����ѧ�ţ�");
			    fflush(stdin);
				gets(num);
				head=Cut(head,num);
				break;
			}
        case 5:   //��������ѯ
			{
				system("CLS");
			    printf("�����������ѯ��������");
			    fflush(stdin);
				gets(nam);
				Find_name(head,nam);
				break;
			}
        case 6:   //���༶��ѯ
			{
				system("CLS");
                printf("�����������ѯ�İ༶��");
			    fflush(stdin);
				gets(cla);
				Find_class(head,cla);
				break;
			}
        case 7:   //��ѧ�Ų�ѯ
			{
				system("CLS");
			    printf("�����������ѯ��ѧ�ţ�");
			    fflush(stdin);
			    gets(num);
				Find_num(head,num);
				break;
			}
		case 8:   //���γ����Ʋ�ѯ
			{
				system("CLS");
			    printf("�����������ѯ�Ŀγ����ƣ�");
			    fflush(stdin);
			    gets(sub);
				Find_sub(head,sub);
				break;
			}
		case 9:   //���ָܷߵ�����
			{
				Sort_sum(head);
				break;
			}
		case 10:   //���Ƴɼ�����
			{
				printf("�����������ѯ�����Ŀ�Ŀ��");
				fflush(stdin);
				gets(sub);
				Sort_sub(head,sub);
				break;
			}
		case 11:  //��ѯ�༶������
			{
				system("CLS");
			    printf("�����������ѯ�İ༶��");
			    fflush(stdin);
			    gets(cla);
				Find_grate(head,cla);
				break;
			}
		case 12:  //��ѯ�༶��������
			{
				system("CLS");
			    printf("�����������ѯ�İ༶��");
			    fflush(stdin);
			    gets(cla);
				Find_faul(head,cla);
				break;
			}
		case 13:  //�˳�ϵͳ
			{
				system("pause");
				return 0;
			}
		default:
            {
                printf("Wrong Oprator! Please input again!\n");
                system("pause");
            }
        }
    }
}
