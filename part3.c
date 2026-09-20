#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int squ(int a) {       //平方运算（square）的封装
    int result;
    result = a * a;
    return result;
}

int zh(int a, int b, int c) {    //综合成绩计算的过程进行封装(用到了平方运算的子函数)
    int p = (a + b + c) / 3;
    int f = (squ(a) + squ(b) + squ(c)) / 3;
    int zh = 3 * p + f / 3;
    return zh;
}

void sort(int zh1,int zh2,int zh3) { //使用void可以不用输出，避免了用int声明函数时返回值得是一个数值。
    if (zh1 >= zh2 && zh2 >= zh3) {
        printf("小明 > 小强 > 小林");
    }
    else if (zh1 >= zh3 && zh3 >= zh2) {
        printf("小明 > 小林 > 小强");
    }
    else if (zh2 >= zh1 && zh1 >= zh3) {
        printf("小强 > 小明 > 小林");
    }
    else if (zh2 >= zh3 && zh3 >= zh1) {
        printf("小强 > 小林 > 小明");
    }
    else if (zh3 >= zh1 && zh1 >= zh2) {
        printf("小林 > 小明 > 小强");
    }
    else {
        printf("小林 > 小强 > 小明");
    }
}

int main(void) {

    int x1, x2, x3;
    int y1, y2, y3;
    int z1, z2, z3;

    printf("请输入小明的三项成绩（顺序为A B C,以一个空格为间隔）：");
    scanf("%d %d %d", &x1, &x2, &x3);
    printf("请输入小强的三项成绩（顺序为A B C,以一个空格为间隔）：");
    scanf("%d %d %d", &y1, &y2, &y3);
    printf("请输入小林的三项成绩（顺序为A B C,以一个空格为间隔）：");
    scanf("%d %d %d", &z1, &z2, &z3);

    int zh1 = zh(x1, x2, x3);
    int zh2 = zh(y1, y2, y3);
    int zh3 = zh(z1, z2, z3);

    sort(zh1, zh2, zh3);

    return 0;
}


