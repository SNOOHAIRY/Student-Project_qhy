#ifndef STD
#define STD

typedef struct Studentlink ST;
typedef struct Subject Sc;

struct Subject
{
	char sub_nam[52];    //�γ���
	int  usgoal;         //ƽʱ�ɼ�
	int  exgoal;         //���Գɼ�
	float ratio;         //���Գɼ���ռ�ı���
	float sugoal;        //�����ɼ�
};

struct Studentlink
{
	 char  num[52];   //ѧ��
	 char  nam[82];   //����
	 char  cla[52];   //�༶
	 int   age;       //����
	 Sc    sub[4];    //��¼���ſγ̵ĳɼ�
	 float sum;       //�ܷ�
	 ST   *node;  
};

#endif