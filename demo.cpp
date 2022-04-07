#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#define STACK_INIT_SIZE 100		//初始存储空间
#define STACKINCREMENT 10		//空间增量大小
using namespace std;

typedef struct
{
	char* base;					//栈底指针
	char* top;					//栈顶指针
	int stacksize;				//栈可用最大容量
}SqStack;

//初始化一个栈
void IntStack(SqStack &S)
{
	S.base = (char*)malloc(STACK_INIT_SIZE * sizeof(char));
	if (!S.base)
	{  
		printf("\nStack Overflow.\n");
		return;
	}
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	printf("\nStack Initialization Succeeded\n");
}

//入栈  e
void Push(SqStack &S, char e)			//e为入栈的元素			eg:  Push(S,11);
{
	if (S.top - S.base == S.stacksize)
	{
		char *newBase;
		newBase = (char*)realloc((S.base), (S.stacksize + STACKINCREMENT) * sizeof(char));
		if (!newBase)
		{
			printf("\nNewbase Crease Fail\n");
			return;
		}
		S.base = newBase;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top = e;
	S.top++;
	//printf("\nNewbase Crease Succeeded\n");
}

//出栈
char Pop(SqStack &S)
{
	/*
	if (S.top == S.base)
	{
		printf("\n栈为空，删除失败。\n");
		return '0';
	}	
	*/
	--S.top;
	char e = *(S.top);
	//printf("\n已成功删除栈顶元素 %c\n", e);
	return e;
}

//取栈顶元素
char GetTop(SqStack &S)
{
	char e;
	if (S.top == S.base)
	{
		printf("\n栈为空，取值失败。\n");
		return false;
	}
	e = *(S.top-1);
	return e;
}

//返回栈长度
int StackLength(SqStack S)
{
	return S.top - S.base;
}

//返回是否为空栈
bool StackEmpty(SqStack S)
{
	if (StackLength(S) == 0)
		return true;
	else
		return false;
}

//遍历&输出栈
int OutPut(SqStack* S) {
	char* p;

	if (S->top == S->base) {
		printf("Stack is NULL.\n");
		return 0;
	}
	p = S->top;
	// 由栈顶依次向下遍历
	while (p > S->base) {
		p--;
		printf("%c ", *p);
	}
	printf("\n");
	return 1;
}

//UI界面
void UI(SqStack &S)
{
	int commend;
	printf("请选择接下来要进行的操作：\n");
	printf("----------------------\n");
	printf("1：将元素压栈\n");
	printf("2：出栈\n");
	printf("3：取栈顶元素\n");
	printf("4：查看栈长度\n");
	printf("5：检查栈是否为空\n");
	printf("6：遍历&输出栈中元素\n");
	printf("0：退出该程序\n");
	commend = (int)getch() - 48;
	system("cls");

	switch (commend)
	{
	case 1: {
		printf("请输入压栈元素个数：");
		int cout = (int)getch() - 48;
		printf("%d\n", cout);
		for (int i = 0;i < cout;i++)
		{
			printf("\n请输入第%d个元素：", i + 1);
			char temp = getch();
			printf("%c\n", temp);
			Push(S, temp);
		}
		printf("\n压栈已完成，按任意键返回。\n");
	}
		  break;
	case 2: {
		S.top != S.base?printf("元素%c已出栈\n\n按任意键返回", Pop(S)):printf("栈为空，删除失败。\n\n按任意键返回");
	}
		  break;
	case 3: {
		printf("\n栈顶元素为：%c\n", GetTop(S));
	}
		  break;
	case 4: {
		printf("\n栈的长度为：%d\n", StackLength(S));
	}
		  break;
	case 5: {
		cout <<endl<< "栈是否为空:" << boolalpha << StackEmpty(S) << endl;
	}
		  break;
	case 6: {
		OutPut(&S);
	}
		  break;
	case 0:exit(1);
		break;
	default: {
		printf("\n您输入的指令有误，请重新输入0~6之间的数字");
	}
		break;
	}
	getch();
}

int main()
{
	int commend;
	char e;
	SqStack S;
	IntStack(S);
	printf("顺序栈已初始化\n");
	cout << "栈是否为空:" << boolalpha << StackEmpty(S) << endl;
	while (1)
	{
		system("cls");
		UI(S);
	}
}