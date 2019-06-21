#ifndef STD
#define STD

typedef struct Studentlink ST;
typedef struct Subject Sc;

struct Subject
{
	char sub_nam[52];    //课程名
	int  usgoal;         //平时成绩
	int  exgoal;         //考试成绩
	float ratio;         //考试成绩所占的比例
	float sugoal;        //总评成绩
};

struct Studentlink
{
	 char  num[52];   //学号
	 char  nam[82];   //姓名
	 char  cla[52];   //班级
	 int   age;       //年龄
	 Sc    sub[4];    //记录四门课程的成绩
	 float sum;       //总分
	 ST   *node;  
};

#endif