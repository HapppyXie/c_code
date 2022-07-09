/*
* 源文件可有多个文件，但只可有一个main函数
一个c语言程序有且只有一个主函数main(),是程序运行的起点
每个c语言程序写完后，都是先编译(.c),后链接(  .obj),最后运行(.exe)
	.c和.obj都无法运行，只有.exe可运行

每个字符在ASCII中都有一个对应的整型
*/

#include<stdio.h>
#include<Windows.h>
int runnian(int);
int countdigit(int, int);

void main() {
	printf("Hello World-来自c语言");
	printf(" ");
	char a = 65;
	printf("%c",a); //%c 后面的参数以字符类型输出
	printf(" ");	
	printf("%d",a);	//%d 后面的参数以int类型输出
	
	char c1 = 'A', c2 = 'N';
	printf("a\tbc\tABC\n");
	printf("xyz\t%c%c\n", c1, c2);

	printf("a=%d,b=%d\n",12,34);
	printf("a=%d,\nb=%d",12, 34);
	printf("\n");
	int x = 017;
	printf("%d\n", x);	//15 10进制
	printf("%o\n", x); //17 8进制
	printf("%#o\n", x); //017 带前导的8进制

	printf("%x\n", x); //f 16进制
	printf("%#x\n",x); //0xf  带前导的16进制

	int x1 = 12, x2 = 34;
	char z = 'a';
	printf("%d\n", x1, x2);	//	一个格式说明，两个输出变量，后面的y不输出
	printf("%c\n",z);

	printf("%2d\n", 123); //第二部分三位，大于指定的两位，原样输出123
	printf("%5d\n", 123);//第二部分三位，小于指定的五位，左边补两个空格

	printf("%10.6f\n", 1.25);	//1前补一个空格，25后面补4个0
	printf("%5.3f\n", 1.25);	//25后面补个0
	printf("%3.1f\n", 1.25);	//小数两位，指定一位，四舍五入

	int x3 = 1;
	int y = 2;
	int t;
	t = x3;
	x3 = y;
	y = t;
	printf("a=%d,b=%d\n", x3, y);

	int a2 = 1, b2 = 0;
	if (!a2) { b2++; }
	else if (a2 == 0) {
		if (a2)b2 += 2;
	}
	else { b2 += 3; }
	printf("%d\n", b2);

	//条件表达式简写		表达式1 ？ 表达式2 : 表达式2	真前假后
	int a3 = 1, b3 = 2, c3 = 3, d3 = 4;
	int k = a3 < b3 ? c3 : d3;
	printf("%d\n",k);

	char grade = 'B';
	switch (grade) {
	case 'A':printf("成绩为A\n");
		break;
	case 'B':printf("成绩为B\n");
		break;
	case 'C':printf("成绩为C\n");
		break;
	case 'D':printf("成绩为D\n");
		break;
	default:printf("无效的成绩");
	}

	for (int i = 0; i <= 100; i++) {
		printf("%d ",i);
		if ((i + 1) % 5 == 0) {
			printf("\n");
		}
	}
	printf("\n");
	
	//如何整除一个数
	//i%5==0表示整除5;i%2==0表示整除2,同时表示其为偶数

	//逆序输出123
	int i = 123;
	while (i != 0) {
		printf("%d", i % 10);
		i = i / 10;
	}
	printf("\n");

	
	for (int i = 3; i < 6; i++) {
		printf("%d", i);
	}
	printf("\n");
	printf("#");
	printf("\n");

	//三种语句实现1+2+3+..+1000	这种结构的for循环以缩进控制代码范围
	int sum1 = 0;
	for (int i = 1; i <= 1000; i++)
		sum1 += i;
	printf("%d\n", sum1);

	int i_sum2=1, sum2=0;
	while (i_sum2 <= 1000) {
		sum2 += i_sum2;
		i_sum2++;
	}
	printf("%d\n",sum2);

	int i_sum3 = 1, sum3 = 0;
	do {
		sum3 += i_sum3;
		i_sum3++;
	} while (i_sum3 <= 1000);
	printf("%d\n", sum3);


	//输入数字中有几个数字digit
	int a_digit, b, t_digit;
	printf("请输入一个正整数:");
	scanf_s("%d",&a_digit);
	printf("请输入指定的数字:");
	scanf_s("%d", &b);
	t_digit= countdigit(a_digit,b);
	printf("%d中有%d个%d\n", a_digit, t_digit, b);
	system("pause");


	//不停的输入，直到输入#停止输入	getchar()获得键盘输入的一个字符
	//while ((x = getchar()) != '#');

	
	/*
	int year;
	printf("请输入一个年份");
	scanf_s("%d", &year);
	if (runnian(year) == 1) {
		printf("%d是闰年\n", year);
	}
	else {
		printf("%d不是闰年\n", year);
	}
	system("pause");
	return 0;
	*/
	


}

int runnian(int year) {

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		year = 1;
	}
	else {
		year = 0;

	}
	return year;
}


int countdigit(int number, int digit) {
	int i = 0;
	while (number != 0) {
		if(number%10==digit){
			i++;
		}
		number = number / 10;
	}
	return i;
}