#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "../head/SqStack.h"
using namespace std;
int main()
{
	SqStack Stack,*s=&Stack;
	int d,a,temp;//�������
	ElemType *aa,bb;
	bool dd=0,first=0,first_=0;//dd 0���� 1�쳣���� first �Ƿ��һ�����У����ڳ�ʼ�� 
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
		cout<<"����������������������������������������������������������������������������"<<endl; 
		cout<<"��            ˳��ջ����ϰ            ��"<<endl;
		cout<<"����������������������������������������������������������������������������"<<endl;
		cout<<"��        �˵�(���������Լ���)        ��"<<endl;
		cout<<"����������������������������������������������������������������������������"<<endl; 
		cout<<"��1.��ʼ��ջ������������������������������������������������������"<<endl;
		cout<<"����������������������������������������������������������������������������"<<endl; 
		cout<<"��2.������ջ������������������������������������������������������"<<endl;
		cout<<"����������������������������������������������������������������������������"<<endl; 
		cout<<"��3.�����ջ������������������������������������������������������"<<endl;
		cout<<"����������������������������������������������������������������������������"<<endl;
		cout<<"��4.������ջ������������������������������������������������������"<<endl;
		cout<<"����������������������������������������������������������������������������"<<endl;
		cout<<"��5.�����ջ������������������������������������������������������"<<endl;
		cout<<"����������������������������������������������������������������������������"<<endl;
		cout<<"��6.������ʾ������������������������������������������������������"<<endl;
		cout<<"����������������������������������������������������������������������������"<<endl;
		cout<<"��7.�����ʾ������������������������������������������������������"<<endl;
		cout<<"����������������������������������������������������������������������������"<<endl;
		cout<<"��8.ջ����񩤩���������������������������������������������������"<<endl;
		cout<<"����������������������������������������������������������������������������"<<endl;
		cout<<"��9.ջ����˩�����������������������������������������������������"<<endl;
		cout<<"����������������������������������������������������������������������������"<<endl;
		cout<<"��10.ջ��û�˩���������������������������������������������������"<<endl;
		cout<<"����������������������������������������������������������������������������"<<endl;
		cout<<"��11.�˳����򩤩�������������������������������������������������"<<endl;
		cout<<"����������������������������������������������������������������������������"<<endl;
		while(SHURU(&d))//��������Ƿ�Ϸ� 
		{
			error_();
			dd=1;
			break;
		}
		if(dd==1)//���� ���¿�ʼ 
			continue;
		if(d==11)
		{
			break;
		}
		switch(d)
		{
			case 1 ://��ʼ�� 
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
					cout<<"��������Ҫ��ջ�ĳ���"<<endl; 
					while(SHURU(&a))
					{
						if(a<1)
						{
							cout<<"�������ڽ������ݲ������������"<<endl;
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
					cout<<endl<<"ִ�����"<<endl; 
					system("PAUSE");
					break;
				}while(1);
				break;
			case 2 ://������ջ 
				dd=0; 
				if(s->top==-1)
				{
					cout<<"ջ��û���أ��ȳ�ʼ��������"<<endl; 
					system("pause");
					break;
				}
				if(s->top==s->size)
				{
					cout<<"ջ�Ѿ�װ�����ˣ���...�����Ļ�Ҫ...Ҫ������ˣ�"<<endl; 
					system("pause");
					break;
				}
				cout<<endl;
				stackLength(s,&temp);
				cout<<"���ڵ�ջ��"<<temp<<"��Ԫ�أ�������"<<s->size-temp<<"��Ԫ��"<<endl; 
				cout<<"��������Ҫ��ջ��Ԫ��(������ֵС��1e9)"<<endl; 
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
				cout<<endl<<"��ջ���"<<endl; 
				system("pause");
				break;
			case 3 ://�����ջ 
				dd=0;
				if(s->top==-1)
				{
					cout<<"ջ��û���أ��ȳ�ʼ��������"<<endl; 
					system("pause");
					break;
				}
				if(s->top==s->size)
				{
					cout<<"ջ�Ѿ�װ�����ˣ���...�����Ļ�Ҫ...Ҫ������ˣ�"<<endl; 
					system("pause");
					break;
				}
				cout<<endl;	
				cout<<"������Ҫ��ջ��Ԫ�ص���������ջ����ʼ���룩��������"<<s->size-s->top<<"��Ԫ��"<<endl;
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
				cout<<"��ֱ�������Ҫ��ջ��Ԫ��(������ֵС��1e9)"<<endl;
				for(int i=1;i<=a;i++)
				{
					while(SHURU(&temp))
					{
						error_();
						break;
					} 
					pushStack(s,temp);	
				}
				cout<<endl<<"��ջ���"<<endl; 
				system("PAUSE");
				break;
			case 4 ://������ջ 
				if(s->top==0)
				{
					cout<<"ջ�ǿյ���"<<endl; 
					system("pause");
					break;
				}
				if(s->top==-1)
				{
					cout<<"ջ��û���أ���Ȼ�ǿյģ�"<<endl; 
					system("pause");
					break;
				}
				popStack(s,&bb); 
				cout<<"����ջ���ǣ�"<<bb<<endl;
				system("pause");
				break;
			case 5 ://�����ջ 
				dd=0; 
				if(s->top==0)
				{
					cout<<"ջ�ǿյ���"<<endl; 
					system("pause");
					break;
				}
				if(s->top==-1)
				{
					cout<<"ջ��û���أ���Ȼ�ǿյģ�"<<endl; 
					system("pause");
					break;
				}
				cout<<"�����ж��ٸ�Ԫ��Ҫ��ջ����ջ����ʼ���룩��������"<<s->top<<"��Ԫ��"<<endl;
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
					cout<<"����ջ���ǣ�"<<*aa<<endl;
					popStack(s,&bb); 
				}
				cout<<endl<<"��ջ���"<<endl; 
				system("PAUSE");
				break;
			case 6 ://������ʾ
				if(s->top==0)
				{
					cout<<"ջ�ǿյ���"<<endl;
					system("PAUSE"); 
					break;
				}
				if(s->top==-1)
				{
					cout<<"ջ��û���أ���ʾ�����ݲ����"<<endl; 
					system("PAUSE");
					break;
				}
//				cout<<"0��"<<bb<<endl;
				getTopStack(s,&bb);
				cout<<"ջ��Ԫ����"<<bb<<endl;
				system("PAUSE");
				break;
			case 7 : //�����ʾ 
				dd=0; 
				if(s->top==0)
				{
					cout<<"ջ�ǿյ���"<<endl;
					system("PAUSE"); 
					break;
				}
				if(s->top==-1)
				{
					cout<<"ջ��û���أ���ʾ�����ݲ����"<<endl; 
					system("PAUSE");
					break;
				}	
				cout<<"����Ҫ��ʾ���ٸ�Ԫ�أ���ջ����ʼ������������"<<s->top<<"��Ԫ��"<<endl;
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
			case 8 ://����Ƿ�Ϊ�� 
				do
				{
					if(s->top==0)
					{
						cout<<"ջ�ǿյ���"<<endl; 
						break;
					}
					if(s->top==-1)
					{
						cout<<"ջ��û���أ���Ȼ�ǿյģ�"<<endl; 
						break;
					}
					cout<<"ջ���ǿյ���"<<endl;
					break;	
				}while(1);
				system("PAUSE");
				break;
			case 9 : //��ջ���� 
				{
					if(s->top==0)
					{
						cout<<"ջ�ǿյ���"<<endl; 
						system("pause");
						break;
					}
					if(s->top==-1)
					{
						cout<<"ջ��û���أ���Ȼ�ǿյģ�"<<endl; 
						system("pause");
						break;
					}
					clearStack(s);
					cout<<"ջ�Ѿ�������"<<endl;
					system("pause");
					break;	
				}
			case 10 ://��ջû��
				{
//					cout<<"top:"<<s->top<<" size:"<<s->size<<endl; 
					if(s->top!=-1)
					{
						cout<<"��ջû��" <<endl; 
						destroyStack(s);
						system("pause");
						break; 
					}
					else
					{
						cout<<"�㶼ûջ�������ٸ����ݲ������" <<endl;
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

