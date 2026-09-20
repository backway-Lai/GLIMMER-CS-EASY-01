#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void){
	//int a = 1;
	//int sum = 0;
	//while (a <= 10) {  //先判断，再运行
	//	sum = sum + a;
	//	a = a + 1;
	//}
	//printf("%d", sum);
	//return 0;


	//int a = 1; //运行至a=10时，仍会进入下一轮。在加完10后a=11，循环结束。
	//int sum = 0;
	//do
	//{
	//	sum = sum + a;.h
	//	a = a + 1;
	//} while (a <= 10);
	//printf("%d", sum);
	//	return 0;



	//逻辑其实很好理解，需要一个循环，循环内容是输出-输入-记录，而判断条件确实一个我原先不熟悉的：用户直接输入。因此我一开始就错了很多次，一开始是不清楚char的规范，在scanf中多余的使用了&，还有就是字符串内容相等要用string.h，一开始我把它写成了ans == "yes"的形式。
	int i = 0;
	int age;
	char ans[50] = "yes";
	char name[100];
	while (strcmp(ans,"yes")== 0) {
		printf("Please enter your name and your age:\n");
		scanf("%s %d",name, &age);
		printf("%s %d\n",name, age);
		i = i + 1;
		printf("Continue entering or not? \n");
		scanf("%s", ans);
	}
	printf("Have entered %d times\n", i);
	return 0;
}