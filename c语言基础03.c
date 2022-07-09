#include<stdio.h>
#include<Windows.h>

void fun1(int,int);
void fun2(int,int);
int *fun3(int, int);

void main() {
	/*
	指针变量的本质是用来存放地址，而一般的变量存放的是数值		指针是一种类型，用来接收指针
	*/
	//1.指针的定义（两种形式）
	//(1)定义一个整型的变量x，再定义一个整型的指针(前面用*来表示，用以区分普通变量)*p,取值为x的地址(&x)
	int x1 = 3,*p1 = &x1;

	//(2)先定义，后赋值
	int	x2,*p2;
	x2 = 3; p2 = &x2;	


	/*
		int *p中，*p和p的差别，*p是数值,p是地址
		*p可以当作变量来用，*的作用是取后面地址p里面的数值
		p是当作地址来使用，可以在scanf函数中：scanf("%d",p);

	2.*p++和(*p)++的之间的差别：
		*p++：地址会改变	地址+1再取值	即*(p++)
		(*p)++：数值会改变	取值再+1
	*/

	int *p3,a[] = { 1,3,5,7,9 };
	p3 = a;//把a的第一个元素的地址给p2
	printf("%d %d\n",p3,*p3);	//将p3地址，其中数值打印出来
	printf("%d\n", *p3++);		//++在后，*p3取出1，后面开始*p3才为3
	//printf("%d\n", *(p3++));	
	printf("%d\n",(*p3)++);		//前面*p3为3，此处++在后,后面开始的*p3才为5
	

	/*
	3.二级指针
	*p：一级指针，存放变量的地址
	**p：二级指针，只存放一级指针的地址，不能存放变量的地址
	*/
	int x3= 7;
	int *p4 = &x3, **q = p4;
	// *p4为7，*q为p4（将*q理解为一个整体即可），**q为7(取*q的值即取p4的值，p4的值为7)

	/*
	3.三名主义：
	数组名：表示第一个元素的地址。数组名不可以自加，它是地址常量名
	函数名：表示该函数的入口地址
	字符串常量名：表示第一个字符的地址
	*/

	/*
	4.移动指针

	这个s首先指向第一个字母m，然后通过循环会一次打印出一个字符，s++是地址移动，打印了一个字符后，就会移动到下一个字母
	*/
	char *s = "meikanshu";//定义一个char类型的指针,其为指针，不同于一般的定义		char a = "wsdas";	错误
	while (*s) {	//当*s指向的内容不为空时，循环;一次指向一个字符
		printf("%c", *s);
		s++;
	}
	printf("\n");
	

	//5.传数值和传地址
	//(1)传数值
	int num1 = 1, num2 = 2;
	fun1(1, 2);
	printf("%d,%d\n", num1, num2);

	//(2)传地址
	int num3 = 1, num4 = 2;
	fun2(&num3, &num4);
	printf("%d,%d\n",num3,num4);
	
	//6.函数指针
	int num5 = 1, num6 = 2,*max;
	max = fun3(&num5, &num6);
	printf("%d\n", *max);
	
}

void fun1(int a, int b) {
	int t;
	t = a;
	a = b;
	b = t;
}
	//相当于 int *a = &num3;	传参数的时候，定义了*a指针
void fun2(int *a, int *b) {
	int t;
	t = *a;		//按照地址，将地址里的值改变了
	*a = *b;
	*b = t;
}
	//函数返回值是地址
int	*fun3(int *a, int *b) {
	if (*a > *b) {
		return a;
	}
	else {
		return b;
	}
}

