#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "../head/LinkStack.h"
using namespace std;
//��ջ
Status initLStack(LinkStack *s)//��ʼ��ջ
{
	destroyLStack(s);
	s->count=0;
	s->top->next=NULL;
	return SUCCESS; 
} 
Status isEmptyLStack(LinkStack *s)//�ж�ջ�Ƿ�Ϊ��
{
	if(s->count==0)
	{
		return SUCCESS;//�� 
	} 
	return ERROR;//�ǿ� 
} 
Status getTopLStack(LinkStack *s,ElemType *e)//�õ�ջ��Ԫ��
{
	*e=s->top->data;
	return SUCCESS;
} 
Status clearLStack(LinkStack *s)//���ջ
{
	LinkStackPtr a=s->top;
	do
	{
		a->data=0;
		a=a->next; 
	}while(--s->count!=0);
	return SUCCESS;
}
Status destroyLStack(LinkStack *s)//����ջ
{
	LinkStackPtr a=s->top,b;
	if(s->count==0)
	{
		s->count=-1;
		return SUCCESS;
	}
	do
	{ 
		b=a;
		a=a->next;
		free(b);
//		cout<<"count��"<<s->count<<endl;
	}while(--s->count!=0);
	return SUCCESS;
}
Status LStackLength(LinkStack *s,int *length)//���ջ����
{
	*length=s->count;
	return SUCCESS;
} 
Status pushLStack(LinkStack *s,ElemType data)//��ջ
{
//	cout<<"ǰdata in:"<<data<<" n:"<<s->count<<endl;
	LinkStackPtr a=(StackNode*)malloc(sizeof(StackNode));
	a->next=s->top;
	a->data=data;
	s->top=a;
	s->count++; 
//	cout<<"data in:"<<data<<" n:"<<s->count<<endl;
	return SUCCESS;
} 
Status popLStack(LinkStack *s,ElemType *data)//��ջ
{
	LinkStackPtr a=s->top;
	*data=a->data;
	a=a->next;
	free(s->top);
	s->top=a;
	s->count--;
//	cout<<"data in:"<<data<<" n:"<<s->count<<" top:"<<s->top->data<<endl;
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
