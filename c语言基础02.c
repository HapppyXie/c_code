/*
c语言函数
定义：[函数类型] 函数名(形式参数)
函数不可以嵌套定义，但是可以嵌套调用
函数名缺少返回值类型，默认为int
c语言由函数组成，但有且仅有一个main函数，是程序运行的开始

由于程序至上而下运行,main不知道后面子函数是否已存在:
子函数写main在前不用声明：如 iszhishu(int);	
子函数写在main后需要在main函数前声明
*/
//
#include<stdio.h>
#include<string.h>

int iszhishu(int);
int fun(int);

void main() {
	int zhishu = 11;
	int result = iszhishu(zhishu);
	if (result) {
		printf("%d是质数\n", zhishu);
	}
	else {
		printf("%d不是质数\n", zhishu);
	}

	//求阶乘n!
	int jiecheng = fun(4);
	printf("%d\n", jiecheng);

	printf("%d\n", abs(-123));
	printf("%d\n", fabs(-0.3));
	printf("%d\n", sqrt(0, 2));
	printf("%d\n", pow(2, 3));
	printf("%d\n", sin(90));
}

int iszhishu(int number) {
	int flag = 0;
	for (int i = 2; i < number / 2; i++) {
		if (number % i == 0) {
			return flag;
		}else {
			flag = 1;
			return flag;
		}
	}
}

int fun(int n) {
	int p = 1;
	for (int i = 1; i <= n; i++) {
		p *= i;
	}
	return p;
}


