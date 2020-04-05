#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "../head/LinkStack.h"
using namespace std;
//链栈
Status initLStack(LinkStack *s)//初始化栈
{
	destroyLStack(s);
	s->count=0;
	s->top->next=NULL;
	return SUCCESS; 
} 
Status isEmptyLStack(LinkStack *s)//判断栈是否为空
{
	if(s->count==0)
	{
		return SUCCESS;//空 
	} 
	return ERROR;//非空 
} 
Status getTopLStack(LinkStack *s,ElemType *e)//得到栈顶元素
{
	*e=s->top->data;
	return SUCCESS;
} 
Status clearLStack(LinkStack *s)//清空栈
{
	LinkStackPtr a=s->top;
	do
	{
		a->data=0;
		a=a->next; 
	}while(--s->count!=0);
	return SUCCESS;
}
Status destroyLStack(LinkStack *s)//销毁栈
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
//		cout<<"count："<<s->count<<endl;
	}while(--s->count!=0);
	return SUCCESS;
}
Status LStackLength(LinkStack *s,int *length)//检测栈长度
{
	*length=s->count;
	return SUCCESS;
} 
Status pushLStack(LinkStack *s,ElemType data)//入栈
{
//	cout<<"前data in:"<<data<<" n:"<<s->count<<endl;
	LinkStackPtr a=(StackNode*)malloc(sizeof(StackNode));
	a->next=s->top;
	a->data=data;
	s->top=a;
	s->count++; 
//	cout<<"data in:"<<data<<" n:"<<s->count<<endl;
	return SUCCESS;
} 
Status popLStack(LinkStack *s,ElemType *data)//出栈
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
int SHURU(int *n)//输入 
{
	string gg;//字符串 
	bool zf=0;//正负 
	int x,z=0;//x长度，z值 
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
void error_()//报错 
{
	cout<<endl<<"错误输入，请检查后重新输入"<<endl; 
	system("PAUSE");
	return;
}
