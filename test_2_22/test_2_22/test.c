#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//位段涉及很多不确定因素，位段是不跨平台的，注意可移植程序应避免使用位段
//struct S
//{
//	int a : 2;
//	int b : 5;
//	int c : 10;
//	int d : 30;
//};
//int main(void)
//{
//	struct S s;
//	printf("%d\n", sizeof(s));//8
//	return 0;
//}

//struct S
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//int main(void)
//{
//	struct S s = { 0 };
//	s.a = 10;
//	s.b = 20;
//	s.c = 3;
//	s.d = 4;
//
//	return 0;
//}


//枚举类型
//相较于#define的优点，增加代码的可读性和维护性 提高严谨性 便于调试 便于使用
enum Sex
{
	//枚举的可能取值(枚举常量）
	//默认从0开始
	MALE,
	FEMALE,
	SECRET
};
//enum Color
//{
//	RED=2,
//	GREEN,
//	BLUE=8
//};
//#define RED 0
//#define GREEN 1
//#define BLUE 2
//int main(void)
//{
//	enum Ses s = MALE;
//	enum Color c = BLUE;
//	printf("%d %d %d\n", RED, GREEN, BLUE);
//	printf("%d %d %d\n",MALE , FEMALE, SECRET);
//
//
//	return 0;
//}



//联和（共用体）
//联合体的大小至少是最大成员的大小
//当最大成员大小不是最大对齐数的倍数时，就要对齐到最大对齐数的整数倍
//共用体内成员不可同时使用
//union Un
//{
//	char c;
//	int i;
//};
//int main(void)
//{
//	union Un u;
//	printf("%d\n", sizeof(u));//4
//	printf("%p\n", &u);
//	printf("%p\n", &u.c);
//	printf("%p\n", &u.i);
//
//	return 0;
//}


//大小端问题
int check_sys1()
{
	int a = 1;
	//如果返回1说明是小端，返回0是大端
	return *(char*)&a;
}
int check_sys()
{
	union Un
	{
		char c;
		int i;
	}u;
	u.i = 1;
	return u.c;
}
int main(void)
{
	int ret = check_sys();
	if (1 ==ret )
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}
