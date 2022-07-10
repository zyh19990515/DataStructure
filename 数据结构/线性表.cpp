#include<iostream>
using namespace std;
#define MAXSIZE 20
typedef struct Sqlist {
	int data[MAXSIZE];
	int length;
};

Sqlist *InitList(Sqlist *L);//初始化线性表
bool ListEmpty(Sqlist *L);//判断线性表是否为空
void ClearList(Sqlist *L);//将线性表清空
void GetElem(Sqlist *L, int i, int *e);//将线性表中第i个位置元素值返回给e。
void LocateElem(Sqlist *L, int e);//查找e
void ListInsert(Sqlist *L, int i, int e);//在i元素后插入e
void ListDelete(Sqlist *L, int i, int *e);//删除i处，并返回其值
int ListLength(Sqlist *L);
void ListDisplay(Sqlist *L);//输出线性表元素及序号;

int main(){
	int *e = new int;//需要查找第i位的元素值
	int e_local = 5;//查找5这个元素的位置
	int e_insert = 100;//插入数据
	int *e_delete = new int;
	Sqlist *L = new Sqlist;
	L = InitList(L);
	ListDisplay(L);
	GetElem(L, 3, e);
	cout << "\n" << "第3个元素为：" << *e << endl;
	LocateElem(L, e_local);
	ListInsert(L, 3, e_insert);
	ListDelete(L, 3, e_delete);
	cout << "被删除的元素为:" << *e_delete << endl;
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
	cout << "请问线性表要添加几个数据：" << endl;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cout << "请输入第" << i + 1 << "个数据" << endl;
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
			cout << "元素5的位置为:" << i + 1 << endl;
			break;
		}
		else if (i!=L->length-1)
		{
			continue;
		}
		else
		{
			cout << "此线性表中没有5这个元素" << endl;
		}
	}
	return;
}
void ListInsert(Sqlist *L, int i, int e) {
	if (L->length == MAXSIZE) {
		cout << "此线性表已到最大容量，无法添加" << endl;
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