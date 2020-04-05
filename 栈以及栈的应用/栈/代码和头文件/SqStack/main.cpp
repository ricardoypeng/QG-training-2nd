#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "../head/SqStack.h"
using namespace std;
int main()
{
	SqStack Stack,*s=&Stack;
	int d,a,temp;//缓存变量
	ElemType *aa,bb;
	bool dd=0,first=0,first_=0;//dd 0正常 1异常跳出 first 是否第一次运行（用于初始化 
	do
	{
		if(first==0)
		{
			s->size=0;
			s->top=-1;
			first++;
		}
		dd=0;
		system("cls");
		cout<<"┌────────────────────────────────────┐"<<endl; 
		cout<<"│            顺序栈的练习            │"<<endl;
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
				do
				{
					dd=0;
					if(first_==0)
					{
						first_++;
					}
					else
					{
						if(s->top!=-1)
							free(s->elem);
					}
					system("cls"); 
					cout<<"请输入你要的栈的长度"<<endl; 
					while(SHURU(&a))
					{
						if(a<1)
						{
							cout<<"你这是在建个泡泡茶壶啦！重来！"<<endl;
							dd=1;
							system("PAUSE");
						}
						else
						{
							error_();
							dd=1;
						}	
						break;
					}
					if(dd==1)
						continue;				
					initStack(s,a);
					cout<<endl<<"执行完毕"<<endl; 
					system("PAUSE");
					break;
				}while(1);
				break;
			case 2 ://单个入栈 
				dd=0; 
				if(s->top==-1)
				{
					cout<<"栈都没有呢！先初始化再来！"<<endl; 
					system("pause");
					break;
				}
				if(s->top==s->size)
				{
					cout<<"栈已经装不下了，再...再塞的话要...要溢出来了！"<<endl; 
					system("pause");
					break;
				}
				cout<<endl;
				stackLength(s,&temp);
				cout<<"现在的栈有"<<temp<<"个元素，还能塞"<<s->size-temp<<"个元素"<<endl; 
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
				pushStack(s,a);
				cout<<endl<<"入栈完毕"<<endl; 
				system("pause");
				break;
			case 3 ://多个入栈 
				dd=0;
				if(s->top==-1)
				{
					cout<<"栈都没有呢！先初始化再来！"<<endl; 
					system("pause");
					break;
				}
				if(s->top==s->size)
				{
					cout<<"栈已经装不下了，再...再塞的话要...要溢出来了！"<<endl; 
					system("pause");
					break;
				}
				cout<<endl;	
				cout<<"输入你要入栈的元素的数量（从栈顶开始输入）最多可输入"<<s->size-s->top<<"个元素"<<endl;
				while(SHURU(&a)||a<1||a>s->size-s->top)
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
						break;
					} 
					pushStack(s,temp);	
				}
				cout<<endl<<"入栈完毕"<<endl; 
				system("PAUSE");
				break;
			case 4 ://单个出栈 
				if(s->top==0)
				{
					cout<<"栈是空的呢"<<endl; 
					system("pause");
					break;
				}
				if(s->top==-1)
				{
					cout<<"栈都没有呢！当然是空的！"<<endl; 
					system("pause");
					break;
				}
				popStack(s,&bb); 
				cout<<"被出栈的是："<<bb<<endl;
				system("pause");
				break;
			case 5 ://多个出栈 
				dd=0; 
				if(s->top==0)
				{
					cout<<"栈是空的呢"<<endl; 
					system("pause");
					break;
				}
				if(s->top==-1)
				{
					cout<<"栈都没有呢！当然是空的！"<<endl; 
					system("pause");
					break;
				}
				cout<<"输入有多少个元素要出栈（从栈顶开始输入）最多可输入"<<s->top<<"个元素"<<endl;
				while(SHURU(&a)||a<1||a>s->top)
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
					aa=s->elem+s->top;
					cout<<"被出栈的是："<<*aa<<endl;
					popStack(s,&bb); 
				}
				cout<<endl<<"出栈完毕"<<endl; 
				system("PAUSE");
				break;
			case 6 ://单个显示
				if(s->top==0)
				{
					cout<<"栈是空的呢"<<endl;
					system("PAUSE"); 
					break;
				}
				if(s->top==-1)
				{
					cout<<"栈都没有呢！显示个泡泡茶壶！"<<endl; 
					system("PAUSE");
					break;
				}
//				cout<<"0是"<<bb<<endl;
				getTopStack(s,&bb);
				cout<<"栈顶元素是"<<bb<<endl;
				system("PAUSE");
				break;
			case 7 : //多个显示 
				dd=0; 
				if(s->top==0)
				{
					cout<<"栈是空的呢"<<endl;
					system("PAUSE"); 
					break;
				}
				if(s->top==-1)
				{
					cout<<"栈都没有呢！显示个泡泡茶壶！"<<endl; 
					system("PAUSE");
					break;
				}	
				cout<<"输入要显示多少个元素（从栈顶开始输出）最多可输出"<<s->top<<"个元素"<<endl;
				while(SHURU(&a)||a<1||a>s->top)
				{
					error_();
					dd=1;
					break;
				} 
				if(dd==1)
				{
					break;	
				} 
				for(int i=s->top;i>=s->top-a+1;i--)
				{
					aa=s->elem+i;
					cout<<*aa;
					if(i!=1)
						cout<<" "; 
				}
				cout<<endl;
				system("PAUSE");
				break; 
			case 8 ://检测是否为空 
				do
				{
					if(s->top==0)
					{
						cout<<"栈是空的呢"<<endl; 
						break;
					}
					if(s->top==-1)
					{
						cout<<"栈都没有呢！当然是空的！"<<endl; 
						break;
					}
					cout<<"栈不是空的呢"<<endl;
					break;	
				}while(1);
				system("PAUSE");
				break;
			case 9 : //你栈空了 
				{
					if(s->top==0)
					{
						cout<<"栈是空的呢"<<endl; 
						system("pause");
						break;
					}
					if(s->top==-1)
					{
						cout<<"栈都没有呢！当然是空的！"<<endl; 
						system("pause");
						break;
					}
					clearStack(s);
					cout<<"栈已经空了呢"<<endl;
					system("pause");
					break;	
				}
			case 10 ://你栈没了
				{
//					cout<<"top:"<<s->top<<" size:"<<s->size<<endl; 
					if(s->top!=-1)
					{
						cout<<"你栈没了" <<endl; 
						destroyStack(s);
						system("pause");
						break; 
					}
					else
					{
						cout<<"你都没栈，还销毁个泡泡茶壶啦！" <<endl;
						system("pause");
						break; 
					} 
				}
//			case 7 :
//				DELETE_(&head,&tail,head,tail);break;
			default :error_();break;
		}
//		cout<<head->data<<endl;
//		cout<<tail->data<<endl;
//		system("pause");
	}while(1);
	if(s->top!=-1)
	{
		delete [] s->elem; 
//		cout<<"clean"<<endl; 
	}
	return 0;
}

