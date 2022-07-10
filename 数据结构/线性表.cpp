#include<iostream>
using namespace std;
#define MAXSIZE 20
typedef struct Sqlist {
	int data[MAXSIZE];
	int length;
};

Sqlist *InitList(Sqlist *L);//��ʼ�����Ա�
bool ListEmpty(Sqlist *L);//�ж����Ա��Ƿ�Ϊ��
void ClearList(Sqlist *L);//�����Ա����
void GetElem(Sqlist *L, int i, int *e);//�����Ա��е�i��λ��Ԫ��ֵ���ظ�e��
void LocateElem(Sqlist *L, int e);//����e
void ListInsert(Sqlist *L, int i, int e);//��iԪ�غ����e
void ListDelete(Sqlist *L, int i, int *e);//ɾ��i������������ֵ
int ListLength(Sqlist *L);
void ListDisplay(Sqlist *L);//������Ա�Ԫ�ؼ����;

int main(){
	int *e = new int;//��Ҫ���ҵ�iλ��Ԫ��ֵ
	int e_local = 5;//����5���Ԫ�ص�λ��
	int e_insert = 100;//��������
	int *e_delete = new int;
	Sqlist *L = new Sqlist;
	L = InitList(L);
	ListDisplay(L);
	GetElem(L, 3, e);
	cout << "\n" << "��3��Ԫ��Ϊ��" << *e << endl;
	LocateElem(L, e_local);
	ListInsert(L, 3, e_insert);
	ListDelete(L, 3, e_delete);
	cout << "��ɾ����Ԫ��Ϊ:" << *e_delete << endl;
	ListDisplay(L);
	delete L;
	delete e;
	delete e_delete;
	system("pause");
	return 0;
}

Sqlist *InitList(Sqlist *L) {
	int cnt = 0;
	int data = 0;
	
	L->length = 0;
	cout << "�������Ա�Ҫ��Ӽ������ݣ�" << endl;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cout << "�������" << i + 1 << "������" << endl;
		cin >> data;
		L->data[i] = data;
	}
	L->length = cnt;

	return L;
}

void ListDisplay(Sqlist *L) {
	for (int i = 0; i < L->length; i++) {
		cout << i + 1 << ":" << L->data[i] << "->";
	}
	return;
}

bool ListEmpty(Sqlist *L) {
	if (L->length == 0) {
		return true;
	}
	else
		return false;
}

void ClearList(Sqlist *L) {
	L->length = 0;
	return;
}

void GetElem(Sqlist *L, int i, int *e) {
	*e = L->data[i - 1];
	return;
}

void LocateElem(Sqlist *L, int e) {
	for (int i = 0; i < L->length; i++) {
		if (L->data[i] == e) {
			cout << "Ԫ��5��λ��Ϊ:" << i + 1 << endl;
			break;
		}
		else if (i!=L->length-1)
		{
			continue;
		}
		else
		{
			cout << "�����Ա���û��5���Ԫ��" << endl;
		}
	}
	return;
}
void ListInsert(Sqlist *L, int i, int e) {
	if (L->length == MAXSIZE) {
		cout << "�����Ա��ѵ�����������޷����" << endl;
		return;
	}
	else {
		for (int j = L->length; j >= i; j--) {
			if (j != i) {
				L->data[j] = L->data[j - 1];
			}
			else
			{
				L->data[j] = e;
			}
		}
		L->length += 1;
	}
	return;
}

void ListDelete(Sqlist *L, int i, int *e) {
	*e = L->data[i - 1];
	for (int j = i - 1; j < L->length-1; j++) {
		L->data[j] = L->data[j + 1];
	}
	L->length -= 1;
	return;
}