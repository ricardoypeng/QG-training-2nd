#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "../head/SqStack.h"
using namespace std;
Status initStack(SqStack *s,int sizes)//��ʼ��ջ
{
	ElemType *a=(ElemType*)malloc(sizeof(ElemType)*(sizes+1));
	s->elem=a;
	s->size=sizes;
	s->top=0;
	return SUCCESS;
} 
Status isEmptyStack(SqStack *s)//�ж�ջ�Ƿ�Ϊ��
{
	if(s->top==0||s->top==-1)
	{
		return SUCCESS;
	}
	return ERROR;
}
Status getTopStack(SqStack *s,ElemType *e) //�õ�ջ��Ԫ��
{
	ElemType *temp;
	if(!isEmptyStack(s))
	{
		temp=s->elem+s->top;
		*e=*temp;
		return SUCCESS;
	}
	return ERROR; 
} 
Status clearStack(SqStack *s)//���ջ
{
	ElemType *aa; 
	do
	{
		aa=s->elem+s->top;
		*aa=0;	
	}while(--s->top);
	return SUCCESS; 
} 
Status destroyStack(SqStack *s)//����ջ
{	
	delete [] s->elem;
	s->top=-1;
	s->size=0;
	return SUCCESS;
} 
Status stackLength(SqStack *s,int *length)//���ջ����
{
	*length=s->top;
	return SUCCESS;
}
Status pushStack(SqStack *s,ElemType data)//��ջ
{
	ElemType *temp;
	s->top++;
	temp=s->elem+s->top;
	*temp=data;
	return SUCCESS;
}
Status popStack(SqStack *s,ElemType *data)//��ջ
{
	ElemType a,*temp;
	getTopStack(s,&a);
	*data=a;
	temp=s->elem+s->top;
	*temp=0;
	s->top--;
	return SUCCESS;
} 
int SHURU(int *n)//���� 
{
	string gg;//�ַ��� 
	bool zf=0;//���� 
	int x,z=0;//x���ȣ�zֵ 
	cin>>gg;
	x=gg.length();
	if(gg[0]=='-')
	{
		if(x>11)
		{
			return 1;
		}
		for(int i=1;i<x;i++)
		{
			if(gg[i]<'0'||gg[i]>'9')
				return 1;
			z+=gg[i]-'0';
			if(i!=x-1)
				z*=10;
		}
		*n=-z;
		return 0;
	}
	else
	{
		if(x>10)
		{
			return 1;
		}
		for(int i=0;i<x;i++)
		{
			if(gg[i]<'0'||gg[i]>'9')
				return 1;
			z+=gg[i]-'0';
			if(i!=x-1)
				z*=10;
		}
		*n=z;
		return 0;
	}
}
void error_()//���� 
{
	cout<<endl<<"�������룬�������������"<<endl; 
	system("PAUSE");
	return;
}
