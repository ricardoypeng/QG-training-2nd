#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "../head/LinkStack.h"
using namespace std;
int main()
{
	LinkStack Stack,*s=&Stack,*p,q;//s=top
	LinkStackPtr zz;
	StackNode *head;
	int d,a,temp;//缓存变量
	ElemType *aa,bb;
	bool dd=0,first=0,first_=0;//dd 0正常 1异常跳出 first 是否第一次运行（用于初始化 
	do
	{
		if(first==0)
		{
			s->count=-1;
			s->top->next=head;
			s->top->data=0;
			first++;
		}
		dd=0;
		system("cls");
		cout<<"┌────────────────────────────────────┐"<<endl; 
		cout<<"│             链栈的练习             │"<<endl;
		cout<<"│────────────────────────────────────│"<<endl;
		cout<<"│        菜单(输入数字以继续)        │"<<endl;
		cout<<"├────────────────────────────────────┤"<<endl; 
		cout<<"│1.初始化栈──────────────────────────│"<<endl;
		cout<<"├────────────────────────────────────┤"<<endl; 
		cout<<"│2.单个入栈──────────────────────────│"<<endl;
		cout<<"├────────────────────────────────────┤"<<endl; 
		cout<<"│3.多个入栈──────────────────────────│"<<endl;
		cout<<"├────────────────────────────────────┤"<<endl;
		cout<<"│4.单个出栈──────────────────────────│"<<endl;
		cout<<"├────────────────────────────────────┤"<<endl;
		cout<<"│5.多个出栈──────────────────────────│"<<endl;
		cout<<"├────────────────────────────────────┤"<<endl;
		cout<<"│6.单个显示──────────────────────────│"<<endl;
		cout<<"├────────────────────────────────────┤"<<endl;
		cout<<"│7.多个显示──────────────────────────│"<<endl;
		cout<<"├────────────────────────────────────┤"<<endl;
		cout<<"│8.栈空与否──────────────────────────│"<<endl;
		cout<<"├────────────────────────────────────┤"<<endl;
		cout<<"│9.栈你空了──────────────────────────│"<<endl;
		cout<<"├────────────────────────────────────┤"<<endl;
		cout<<"│10.栈你没了─────────────────────────│"<<endl;
		cout<<"├────────────────────────────────────┤"<<endl;
		cout<<"│11.退出程序─────────────────────────│"<<endl;
		cout<<"└────────────────────────────────────┘"<<endl; 
		while(SHURU(&d))//检测输入是否合法 
		{
			error_();
			dd=1;
			break;
		}
		if(dd==1)//出错 重新开始 
			continue;
		if(d==11)
		{
			break;
		}
		switch(d)
		{
			case 1 ://初始化 
				if(s->count!=-1)
					destroyLStack(s);
				s->count=0; 
				cout<<"初始化完毕"<<endl; 
				system("PAUSE");
				break;
				
			case 2 ://单个入栈 
				dd=0; 
				if(s->count==-1)
				{
					cout<<"你都没栈，还入个泡泡茶壶啦！"<<endl; 
					system("pause");
					break;
				}
				LStackLength(s,&temp);
				cout<<"现在的栈有"<<temp<<"个元素"<<endl; 
				cout<<"请输入你要入栈的元素(数绝对值小于1e9)"<<endl; 
				while(SHURU(&a))
				{
					error_();
					dd=1;
					break;
				}
				if(dd==1)
				{
					break;
				}
				pushLStack(&Stack,a);
				cout<<endl<<"入栈完毕"<<endl; 
				system("pause");
				break;
				
			case 3 ://多个入栈 
				dd=0;
				if(s->count==-1)
				{
					cout<<"你都没栈，还入个泡泡茶壶啦！"<<endl; 
					system("pause");
					break;
				}
				cout<<"输入你要入栈的元素的数量（从栈顶开始输入）"<<endl;
				while(SHURU(&a)||a<1)
				{
					error_();
					dd=1;
					break;
				} 
				if(dd==1)
				{
					break;	
				} 
				cout<<"请分别输入你要入栈的元素(数绝对值小于1e9)"<<endl;
				for(int i=1;i<=a;i++)
				{
					while(SHURU(&temp))
					{
						error_();
						continue;
					} 
					pushLStack(s,temp);	
//					cout<<"data3:"<<s->top->data<<" n:"<<s->count<<endl;
				}
				cout<<endl<<"入栈完毕"<<endl; 
				system("PAUSE");
				break;
				
			case 4 ://单个出栈 
				if(s->count==-1)
				{
					cout<<"你都没栈，还出个泡泡茶壶啦！"<<endl; 
					system("pause");
					break;
				}
				if(s->count==0)
				{
					cout<<"栈是空的呢"<<endl;
					system("PAUSE"); 
					break;
				}
				popLStack(s,&bb);			
				cout<<"被出栈的是："<<bb<<endl;	
				system("PAUSE"); 
				break;
				
			case 5 ://多个出栈
				dd=0;
				if(s->count==-1)
				{
					cout<<"你都没栈，还出个泡泡茶壶啦！"<<endl; 
					system("pause");
					break;
				}
				if(s->count==0)
				{
					cout<<"栈是空的呢"<<endl;
					system("PAUSE"); 
					break;
				}
				cout<<"输入有多少个元素要出栈（从栈顶开始出）最多可输入"<<s->count<<"个元素"<<endl;
				while(SHURU(&a)||a<1||a>s->count)
				{
					error_();
					dd=1;
					break;
				} 
				if(dd==1)
				{
					break;	
				} 
				for(int i=1;i<=a;i++)
				{
					popLStack(s,&bb);
					cout<<"被出栈的是："<<bb<<endl;
				}
				if(dd==0)
					cout<<endl<<"出栈完毕"<<endl; 
				system("PAUSE");
				break;
				
			case 6 ://单个显示
				if(s->count==-1)
				{
					cout<<"你都没栈，还显示个泡泡茶壶啦！"<<endl; 
					system("pause");
					break;
				}
				if(s->count==0)
				{
					cout<<"栈是空的呢"<<endl;
					system("PAUSE"); 
					break;
				}
				getTopLStack(s,&bb);
				cout<<"栈顶元素是"<<bb<<endl;
				system("PAUSE");
				break;
				
			case 7 : //多个显示 
				dd=0; 
				if(s->count==-1)
				{
					cout<<"你都没栈，还显示个泡泡茶壶啦！"<<endl; 
					system("pause");
					break;
				}
				if(s->count==0)
				{
					cout<<"栈是空的呢"<<endl;
					system("PAUSE"); 
					break;
				}
				cout<<"输入要显示多少个元素（从栈顶开始输出）最多可输出"<<s->count<<"个元素"<<endl;
				while(SHURU(&a)||a<1||a>s->count)
				{
					error_();
					dd=1;
					break;
				} 
				if(dd==1)
				{
					break;	
				} 
				zz=s->top;
				for(int i=a;i>=1;i--)
				{
					bb=zz->data;
					cout<<bb;
					if(i!=1)
						cout<<" ";
					zz=zz->next;
				}
				cout<<endl;
				system("PAUSE");
				break; 
				
			case 8 ://检测是否为空 
				if(s->count==0)
				{
					cout<<"栈是空的呢"<<endl; 
					system("PAUSE");
					break;
				}
				if(s->count==-1)
				{
					cout<<"你都没栈，还空个泡泡茶壶啦！" <<endl;
					system("pause");
					break; 
				}
				cout<<"栈不是空的呢"<<endl;
				system("PAUSE");
				break;
				
			case 9 : //你栈空了 
				if(s->count==0)
				{
					cout<<"栈是空的呢"<<endl; 
					system("pause");
					break;
				}
				if(s->count==-1)
				{
					cout<<"你都没栈，还空个泡泡茶壶啦！" <<endl;
					system("pause");
					break; 
				}
				clearLStack(s);
				cout<<"栈已经空了呢"<<endl;
				system("pause");
				break;	
				
			case 10 ://你栈没了
				if(s->count!=-1)
				{
					cout<<"你栈没了" <<endl; 
					destroyLStack(s);
					s->count=-1;
					system("pause");
					break; 
				}
				else
				{
					cout<<"你都没栈，还销毁个泡泡茶壶啦！" <<endl;
					system("pause");
					break; 
				} 
			default :error_();break;
		}

	}while(1);
	if(s->count!=-1)
	{
		destroyLStack(s);

	}
	system("pause");
	return 0;
}
