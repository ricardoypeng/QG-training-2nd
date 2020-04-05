#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "../head/change.h"
using namespace std;
bool suan(double n[],char x)
{
//	cout<<"shurule:"<<x<<endl;
	if(x=='+')
	{
		n[(int)n[0]-1]+=n[(int)n[0]];
		n[(int)n[0]]=0;
		n[0]--;
//		cout<<n[(int)n[0]-1]<<endl;
		return 0;
	}
	if(x=='-')
	{
		n[(int)n[0]-1]-=n[(int)n[0]];
		n[(int)n[0]]=0;
		n[0]--;
//		cout<<n[(int)n[0]-1]<<endl;
		return 0;
	}
	if(x=='*')
	{
		n[(int)n[0]-1]*=n[(int)n[0]];
		n[(int)n[0]]=0;
		n[0]--;
//		cout<<n[(int)n[0]-1]<<endl;
		return 0;
	}
	if(x=='/')
	{
		if(n[(int)n[0]]==0)
			return 1;
		n[(int)n[0]-1]/=n[(int)n[0]];
		n[(int)n[0]]=0;
		n[0]--;
//		cout<<n[(int)n[0]-1]<<endl;
		return 0;
	}
}
bool change(string text,char s[],double n[])
{
	int length,l;
	bool dd=0; 
	char x;
	length=text.length();
	l=length;
//	cout<<"n:"<<l<<endl<<text<<endl;
	for(int i=0;i<length;i++)
	{
		dd=0;
//		cout<<"i:"<<i<<" : "<<text[i]<<endl;
		if(text[i]>='0'&&text[i]<='9')					
		{
			if(i==0||text[i-1]<'0'||text[i]>'9')
			{
				n[0]++;
			}
			n[(int)n[0]]*=10;
			n[(int)n[0]]+=text[i]-'0';
			continue;
		}
		if(text[i]=='(')
		{
			s[(int)++s[0]]=text[i];
			continue;
		}
		if(text[i]==')')
		{
			do
			{
				if(s[0]!=0)
					x=s[(int)s[0]];
				if(s[0]==0)
				{
					dd=1;
					break;
				} 
				if(x=='(')
				{
					s[(int)s[0]]=0;
					s[0]--;
					break;
				}
				else
				{
//					cout<<"x:?"<<x<<endl;
					if(suan(n,x))
					{
						dd=1;
						break;
					}
					s[(int)s[0]]=0;
					s[0]--;
				}
			}while(1);
			if(dd)
				break;
			continue;
		}
		if(text[i]=='+')
		{
			do
			{
				if(s[0]!=0)
					x=s[(int)s[0]];
				if(x=='('||s[0]==0) //比他小或者空就压入 
				{
//					cout<<"放进去了！1"<<endl; 
					s[(int)++s[0]]=text[i];
					break;
				}
				if(x=='+'||x=='-'||x=='*'||x=='/')//优先级比他大或相等的就弹出 
				{
//					cout<<"x:1"<<x<<endl;
					if(suan(n,x))
					{
						dd=1;
						break;
					}
					s[(int)s[0]]=0;
					s[0]--;
					continue;
				}	
			}while(1);
			if(dd)
				break;
			continue;
		}
		if(text[i]=='-')
		{
			do
			{
				if(s[0]!=0)
					x=s[(int)s[0]];
				if(x=='('||s[0]==0) //比他小或者空就压入 
				{
//					cout<<"放进去了！2"<<endl; 
					s[(int)++s[0]]=text[i];
					break;
				}
				if(x=='+'||x=='-'||x=='*'||x=='/')//优先级比他大或相等的就弹出 
				{
//					cout<<"x:?2"<<x<<endl;
					if(suan(n,x))
					{
						dd=1;
						break;
					}
					s[(int)s[0]]=0;
					s[0]--;
					continue;
				}		
			}while(1);
			if(dd)
				break;
			continue;
		}
		if(text[i]=='*')
		{
			do
			{
				if(s[0]!=0)
					x=s[(int)s[0]];
				if(x=='('||x=='+'||x=='-'||s[0]==0) //比他小或者空就压入 
				{
//					cout<<"放进去了！3"<<endl; 
					s[(int)++s[0]]=text[i];
					break;
				}
				if(x=='*'||x=='/')//优先级比他大或相等的就弹出 
				{
//					cout<<"x:?3"<<x<<endl;
					if(suan(n,x))
					{
						dd=1;
						break;
					}
					s[(int)s[0]]=0;
					s[0]--;
					continue;
				}
			}while(1);
			if(dd)
				break;
			continue;
		}
		if(text[i]=='/')
		{
			do
			{
				if(s[0]!=0)
					x=s[(int)s[0]];
				if(x=='('||x=='+'||x=='-'||s[0]==0) //比他小或者空就压入 
				{
//					cout<<"放进去了！4"<<endl; 
					s[(int)++s[0]]=text[i];
					break;
				}
				if(x=='*'||x=='/')//优先级比他大或相等的就弹出 
				{
//					cout<<"x:?4"<<x<<endl;
					if(suan(n,x))
					{
						dd=1;
						break;
					}
					s[(int)s[0]]=0;
					s[0]--;
					continue;
				}
			}while(1);
			if(dd)
				break;
			continue;
		}
		dd=1;
	}
	if(s[0]!=0)
	{
		do
		{
			x=s[(int)s[0]];
//			cout<<"x:?6"<<x<<endl;
			if(suan(n,x))
			{
				dd=1;
				break;
			}	
			s[(int)s[0]]=0;
		}while(--s[0]);	
	} 
	if(dd)
		return 0;
	return 1;
}



