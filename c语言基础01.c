/*
* Դ�ļ����ж���ļ�����ֻ����һ��main����
һ��c���Գ�������ֻ��һ��������main(),�ǳ������е����
ÿ��c���Գ���д��󣬶����ȱ���(.c),������(  .obj),�������(.exe)
	.c��.obj���޷����У�ֻ��.exe������

ÿ���ַ���ASCII�ж���һ����Ӧ������
*/

#include<stdio.h>
#include<Windows.h>
int runnian(int);
int countdigit(int, int);

void main() {
	printf("Hello World-����c����");
	printf(" ");
	char a = 65;
	printf("%c",a); //%c ����Ĳ������ַ��������
	printf(" ");	
	printf("%d",a);	//%d ����Ĳ�����int�������
	
	char c1 = 'A', c2 = 'N';
	printf("a\tbc\tABC\n");
	printf("xyz\t%c%c\n", c1, c2);

	printf("a=%d,b=%d\n",12,34);
	printf("a=%d,\nb=%d",12, 34);
	printf("\n");
	int x = 017;
	printf("%d\n", x);	//15 10����
	printf("%o\n", x); //17 8����
	printf("%#o\n", x); //017 ��ǰ����8����

	printf("%x\n", x); //f 16����
	printf("%#x\n",x); //0xf  ��ǰ����16����

	int x1 = 12, x2 = 34;
	char z = 'a';
	printf("%d\n", x1, x2);	//	һ����ʽ˵����������������������y�����
	printf("%c\n",z);

	printf("%2d\n", 123); //�ڶ�������λ������ָ������λ��ԭ�����123
	printf("%5d\n", 123);//�ڶ�������λ��С��ָ������λ����߲������ո�

	printf("%10.6f\n", 1.25);	//1ǰ��һ���ո�25���油4��0
	printf("%5.3f\n", 1.25);	//25���油��0
	printf("%3.1f\n", 1.25);	//С����λ��ָ��һλ����������

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

	//�������ʽ��д		���ʽ1 �� ���ʽ2 : ���ʽ2	��ǰ�ٺ�
	int a3 = 1, b3 = 2, c3 = 3, d3 = 4;
	int k = a3 < b3 ? c3 : d3;
	printf("%d\n",k);

	char grade = 'B';
	switch (grade) {
	case 'A':printf("�ɼ�ΪA\n");
		break;
	case 'B':printf("�ɼ�ΪB\n");
		break;
	case 'C':printf("�ɼ�ΪC\n");
		break;
	case 'D':printf("�ɼ�ΪD\n");
		break;
	default:printf("��Ч�ĳɼ�");
	}

	for (int i = 0; i <= 100; i++) {
		printf("%d ",i);
		if ((i + 1) % 5 == 0) {
			printf("\n");
		}
	}
	printf("\n");
	
	//�������һ����
	//i%5==0��ʾ����5;i%2==0��ʾ����2,ͬʱ��ʾ��Ϊż��

	//�������123
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

	//�������ʵ��1+2+3+..+1000	���ֽṹ��forѭ�����������ƴ��뷶Χ
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


	//�����������м�������digit
	int a_digit, b, t_digit;
	printf("������һ��������:");
	scanf_s("%d",&a_digit);
	printf("������ָ��������:");
	scanf_s("%d", &b);
	t_digit= countdigit(a_digit,b);
	printf("%d����%d��%d\n", a_digit, t_digit, b);
	system("pause");


	//��ͣ�����룬ֱ������#ֹͣ����	getchar()��ü��������һ���ַ�
	//while ((x = getchar()) != '#');

	
	/*
	int year;
	printf("������һ�����");
	scanf_s("%d", &year);
	if (runnian(year) == 1) {
		printf("%d������\n", year);
	}
	else {
		printf("%d��������\n", year);
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