#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD.h"

extern ST* Creat(ST*);                        //录入学生信息
extern ST* Chang(ST*,char[]);                 //修改学生信息
extern void Add(ST*);                          //增加学生信息
extern ST* Cut(ST*,char[]);                   //删除学生信息
extern void Find_name(ST*,char[]);            //按姓名查询
extern void Find_class(ST*,char[]);           //按班级查询
extern void Find_num(ST*,char[]);             //按学号查询
extern void Find_sub(ST*,char[]);             //按课程名称查询
extern void Find_grate(ST*,char[]);           //查询班级优秀率
extern void Find_faul(ST*head,char cla[]);    //查询班级不及格率
extern void Sort_sum(ST*);                    //按总分高低排序
extern void Sort_sub(ST*,char[]);             //单科成绩排名


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
        printf("|********************学生管理系统***********************|\n");
        printf("|                                                       |\n");
        printf("|                 1  输入学生信息                       |\n");
        printf("|                 2  修改学生信息                       |\n");
        printf("|                 3  增加学生信息                       |\n");
        printf("|                 4  删除学生信息                       |\n");
        printf("|                 5  按姓名查询                         |\n");
        printf("|                 6  按班级查询                         |\n");
        printf("|                 7  按学号查询                         |\n");
        printf("|                 8  按课程名称查询                     |\n");
        printf("|                 9  按总分从高低排序                   |\n");
        printf("|                10  单科成绩排名                       |\n");
        printf("|                11  查询班级优秀率                     |\n");
		printf("|                12  查询班级不及格率                   |\n");
        printf("|                13  退出系统                           |\n");
        printf("|                                                       |\n");
        printf("|*******************************************************|\n");
        printf("请输入操作数：");
        scanf("%d",&a);
        switch(a)
        {
        case 1:  //输入学生信息
            {
                head=Creat(head);
                break;
            }
        case 2:  //修改学生信息
            {
				system("CLS");
				printf("请输入你想修改的学生的学号：");
				fflush(stdin);
				gets(num);
				head=Chang(head,num);
				break;
            }
        case 3:  //增加学生信息
        {
			system("CLS");
            Add(head);
            break;
        }
        case 4:  //删除学生信息
			{
				system("CLS");
			    printf("请输入你想删除的学生的学号：");
			    fflush(stdin);
				gets(num);
				head=Cut(head,num);
				break;
			}
        case 5:   //按姓名查询
			{
				system("CLS");
			    printf("请输入你想查询的姓名：");
			    fflush(stdin);
				gets(nam);
				Find_name(head,nam);
				break;
			}
        case 6:   //按班级查询
			{
				system("CLS");
                printf("请输入你想查询的班级：");
			    fflush(stdin);
				gets(cla);
				Find_class(head,cla);
				break;
			}
        case 7:   //按学号查询
			{
				system("CLS");
			    printf("请输入你想查询的学号：");
			    fflush(stdin);
			    gets(num);
				Find_num(head,num);
				break;
			}
		case 8:   //按课程名称查询
			{
				system("CLS");
			    printf("请输入你想查询的课程名称：");
			    fflush(stdin);
			    gets(sub);
				Find_sub(head,sub);
				break;
			}
		case 9:   //按总分高低排序
			{
				Sort_sum(head);
				break;
			}
		case 10:   //单科成绩排名
			{
				printf("请输入你想查询排名的科目：");
				fflush(stdin);
				gets(sub);
				Sort_sub(head,sub);
				break;
			}
		case 11:  //查询班级优秀率
			{
				system("CLS");
			    printf("请输入你想查询的班级：");
			    fflush(stdin);
			    gets(cla);
				Find_grate(head,cla);
				break;
			}
		case 12:  //查询班级不及格率
			{
				system("CLS");
			    printf("请输入你想查询的班级：");
			    fflush(stdin);
			    gets(cla);
				Find_faul(head,cla);
				break;
			}
		case 13:  //退出系统
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
