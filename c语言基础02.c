/*
c���Ժ���
���壺[��������] ������(��ʽ����)
����������Ƕ�׶��壬���ǿ���Ƕ�׵���
������ȱ�ٷ���ֵ���ͣ�Ĭ��Ϊint
c�����ɺ�����ɣ������ҽ���һ��main�������ǳ������еĿ�ʼ

���ڳ������϶�������,main��֪�������Ӻ����Ƿ��Ѵ���:
�Ӻ���дmain��ǰ������������ iszhishu(int);	
�Ӻ���д��main����Ҫ��main����ǰ����
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
		printf("%d������\n", zhishu);
	}
	else {
		printf("%d��������\n", zhishu);
	}

	//��׳�n!
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


