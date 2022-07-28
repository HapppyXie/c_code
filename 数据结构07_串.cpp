//����˳��洢
#define MAXLEN 255
typedef struct {
	char ch[MAXLEN + 1];
	int length;
}SString;

//���Ķ�ʽ˳��洢�ṹ
typedef struct {
	char* ch;
	int length;
}HString;

//������ʽ�洢�ṹ
#define CHUNKSIZE 80
typedef struct Chunk {
	char ch[CHUNKSIZE];
	struct Chunk* next;
}Chunk;

typedef struct {
	Chunk* head, * tail;
	int length;
}LString;

//BF�㷨
int index_BF(SString S, SString T, int pos) {
	int i = pos; int j = 1;
	while (i <= S.length && j <= T.length) {
		if (S.ch[i] == T.ch[j]) { ++i; ++j; }
		else { i = i - j + 2; }
	}
	if (j > T.length)return i - T.length;
	else return 0;
}

//����next����������ֵ
void get_nextval(SString T, int nextval[]) {
	int i = 1;
	int j = 1;
	nextval[1] = 0;
	while (i < T.length) {
		if (j == 0 || T.ch[i] == T.ch[j]) {
			++i; ++j;
			if (T.ch[i] == T.ch[j])nextval[i] = j;
			else nextval[i] = nextval[j];
		}
		else {
			j = nextval[j];
		}
	}
}

//KMP�㷨
int index_KMP(SString S, SString T, int pos) {
	int next[50];
	int i = pos;
	int j = 1;
	while (i <= S.length && j <= T.length) {
		if (j == 0 || S.ch[i] == T.ch[j]) { ++i; ++j; }
		else { j = next[j]; }
	}
	if (j > T.length)return i - T.length;
	else return 0;
}


void main() {
}