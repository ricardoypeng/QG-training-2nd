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
	int d,a,temp;//�������
	ElemType *aa,bb;
	bool dd=0,first=0,first_=0;//dd 0���� 1�쳣���� first �Ƿ��һ�����У����ڳ�ʼ�� 
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
		cout<<"����������������������������������������������������������������������������"<<endl; 
		cout<<"��             ��ջ����ϰ             ��"<<endl;
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
				if(s->count!=-1)
					destroyLStack(s);
				s->count=0; 
				cout<<"��ʼ�����"<<endl; 
				system("PAUSE");
				break;
				
			case 2 ://������ջ 
				dd=0; 
				if(s->count==-1)
				{
					cout<<"�㶼ûջ����������ݲ������"<<endl; 
					system("pause");
					break;
				}
				LStackLength(s,&temp);
				cout<<"���ڵ�ջ��"<<temp<<"��Ԫ��"<<endl; 
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
				pushLStack(&Stack,a);
				cout<<endl<<"��ջ���"<<endl; 
				system("pause");
				break;
				
			case 3 ://�����ջ 
				dd=0;
				if(s->count==-1)
				{
					cout<<"�㶼ûջ����������ݲ������"<<endl; 
					system("pause");
					break;
				}
				cout<<"������Ҫ��ջ��Ԫ�ص���������ջ����ʼ���룩"<<endl;
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
				cout<<"��ֱ�������Ҫ��ջ��Ԫ��(������ֵС��1e9)"<<endl;
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
				cout<<endl<<"��ջ���"<<endl; 
				system("PAUSE");
				break;
				
			case 4 ://������ջ 
				if(s->count==-1)
				{
					cout<<"�㶼ûջ�����������ݲ������"<<endl; 
					system("pause");
					break;
				}
				if(s->count==0)
				{
					cout<<"ջ�ǿյ���"<<endl;
					system("PAUSE"); 
					break;
				}
				popLStack(s,&bb);			
				cout<<"����ջ���ǣ�"<<bb<<endl;	
				system("PAUSE"); 
				break;
				
			case 5 ://�����ջ
				dd=0;
				if(s->count==-1)
				{
					cout<<"�㶼ûջ�����������ݲ������"<<endl; 
					system("pause");
					break;
				}
				if(s->count==0)
				{
					cout<<"ջ�ǿյ���"<<endl;
					system("PAUSE"); 
					break;
				}
				cout<<"�����ж��ٸ�Ԫ��Ҫ��ջ����ջ����ʼ������������"<<s->count<<"��Ԫ��"<<endl;
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
					cout<<"����ջ���ǣ�"<<bb<<endl;
				}
				if(dd==0)
					cout<<endl<<"��ջ���"<<endl; 
				system("PAUSE");
				break;
				
			case 6 ://������ʾ
				if(s->count==-1)
				{
					cout<<"�㶼ûջ������ʾ�����ݲ������"<<endl; 
					system("pause");
					break;
				}
				if(s->count==0)
				{
					cout<<"ջ�ǿյ���"<<endl;
					system("PAUSE"); 
					break;
				}
				getTopLStack(s,&bb);
				cout<<"ջ��Ԫ����"<<bb<<endl;
				system("PAUSE");
				break;
				
			case 7 : //�����ʾ 
				dd=0; 
				if(s->count==-1)
				{
					cout<<"�㶼ûջ������ʾ�����ݲ������"<<endl; 
					system("pause");
					break;
				}
				if(s->count==0)
				{
					cout<<"ջ�ǿյ���"<<endl;
					system("PAUSE"); 
					break;
				}
				cout<<"����Ҫ��ʾ���ٸ�Ԫ�أ���ջ����ʼ������������"<<s->count<<"��Ԫ��"<<endl;
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
				
			case 8 ://����Ƿ�Ϊ�� 
				if(s->count==0)
				{
					cout<<"ջ�ǿյ���"<<endl; 
					system("PAUSE");
					break;
				}
				if(s->count==-1)
				{
					cout<<"�㶼ûջ�����ո����ݲ������" <<endl;
					system("pause");
					break; 
				}
				cout<<"ջ���ǿյ���"<<endl;
				system("PAUSE");
				break;
				
			case 9 : //��ջ���� 
				if(s->count==0)
				{
					cout<<"ջ�ǿյ���"<<endl; 
					system("pause");
					break;
				}
				if(s->count==-1)
				{
					cout<<"�㶼ûջ�����ո����ݲ������" <<endl;
					system("pause");
					break; 
				}
				clearLStack(s);
				cout<<"ջ�Ѿ�������"<<endl;
				system("pause");
				break;	
				
			case 10 ://��ջû��
				if(s->count!=-1)
				{
					cout<<"��ջû��" <<endl; 
					destroyLStack(s);
					s->count=-1;
					system("pause");
					break; 
				}
				else
				{
					cout<<"�㶼ûջ�������ٸ����ݲ������" <<endl;
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
