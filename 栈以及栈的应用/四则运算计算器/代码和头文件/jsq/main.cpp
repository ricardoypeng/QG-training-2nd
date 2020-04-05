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
	int d,a,temp;//缓存变量
	bool dd=0,first=0;//dd 0正常 1异常跳出 first 是否第一次运行（用于初始化 
	string text;
	do
	{
		memset(num,0,sizeof(num));
		memset(s,0,sizeof(s));
		dd=0;
		system("cls");
		cout<<"四 则 运 算"<<endl;
		cout<<"请输入您的算式，请注意只能使用 + - * / ()和绝对值小于1e9的正整数构成算式，否则将视为非法输入" <<endl;
		cin>>text;
		if(change(text,s,num)==1)
		{
			cout<<"结果是："<<num[1]<<endl;
			system("pause");
			continue;
		}
		else
		{
			dd=1;
			cout<<"非法输入啦！你输了些什么泡泡茶壶啦！"<<endl; 
			system("pause");
			continue;
		}
	}while(1);
	return 0;
}

