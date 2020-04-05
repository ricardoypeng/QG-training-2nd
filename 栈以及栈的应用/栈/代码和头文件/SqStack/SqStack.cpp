#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "../head/SqStack.h"
using namespace std;
Status initStack(SqStack *s,int sizes)//初始化栈
{
	ElemType *a=(ElemType*)malloc(sizeof(ElemType)*(sizes+1));
	s->elem=a;
	s->size=sizes;
	s->top=0;
	return SUCCESS;
} 
Status isEmptyStack(SqStack *s)//判断栈是否为空
{
	if(s->top==0||s->top==-1)
	{
		return SUCCESS;
	}
	return ERROR;
}
Status getTopStack(SqStack *s,ElemType *e) //得到栈顶元素
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
Status clearStack(SqStack *s)//清空栈
{
	ElemType *aa; 
	do
	{
		aa=s->elem+s->top;
		*aa=0;	
	}while(--s->top);
	return SUCCESS; 
} 
Status destroyStack(SqStack *s)//销毁栈
{	
	delete [] s->elem;
	s->top=-1;
	s->size=0;
	return SUCCESS;
} 
Status stackLength(SqStack *s,int *length)//检测栈长度
{
	*length=s->top;
	return SUCCESS;
}
Status pushStack(SqStack *s,ElemType data)//入栈
{
	ElemType *temp;
	s->top++;
	temp=s->elem+s->top;
	*temp=data;
	return SUCCESS;
}
Status popStack(SqStack *s,ElemType *data)//出栈
{
	ElemType a,*temp;
	getTopStack(s,&a);
	*data=a;
	temp=s->elem+s->top;
	*temp=0;
	s->top--;
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
