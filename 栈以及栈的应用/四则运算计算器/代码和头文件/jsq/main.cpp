#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
bool suan(int n[],char x);
bool change(string text,char s[],double n[]);
double num[100001];
char s[100001];
int main()
{
	int d,a,temp;//�������
	bool dd=0,first=0;//dd 0���� 1�쳣���� first �Ƿ��һ�����У����ڳ�ʼ�� 
	string text;
	do
	{
		memset(num,0,sizeof(num));
		memset(s,0,sizeof(s));
		dd=0;
		system("cls");
		cout<<"�� �� �� ��"<<endl;
		cout<<"������������ʽ����ע��ֻ��ʹ�� + - * / ()�;���ֵС��1e9��������������ʽ��������Ϊ�Ƿ�����" <<endl;
		cin>>text;
		if(change(text,s,num)==1)
		{
			cout<<"����ǣ�"<<num[1]<<endl;
			system("pause");
			continue;
		}
		else
		{
			dd=1;
			cout<<"�Ƿ���������������Щʲô���ݲ������"<<endl; 
			system("pause");
			continue;
		}
	}while(1);
	return 0;
}

