#include<iostream>
using namespace std;

typedef struct linkList {
	int data;
	linkList *address;
};

typedef struct dlinkList {
	dlinkList *forward;
	int data;
	dlinkList* next;
};

linkList *linkListInit(linkList *head);//��ʼ������
linkList *relinkListInit(linkList *head);
void linkListDiplay(linkList *head);//�������
void linkListInsert(linkList *head, int position, int data);//����һ���ڵ�
void linkListDeleteNode(linkList *head, int position);//ɾ��һ���ڵ�
void deletelinkList(linkList *head);//ɾ������
dlinkList *dlinkListInte(dlinkList* head);
void dlinkListDiplay(dlinkList* head);//�������

int main() {
	linkList *link;
	link = new linkList;
	dlinkList* dlink;
	dlink = new dlinkList;
	linkListInit(link);
	linkListDiplay(link);
	//linkListInsert(link, 3, 22);
	//linkListDeleteNode(link, 2);
	//linkListDiplay(link);
	//deletelinkList(link);
	//linkListDiplay(link);
	dlinkListInte(dlink);
	dlinkListDiplay(dlink);
	system("pause");
	return 0;
}

linkList *linkListInit(linkList *head) {
	int cnt;
	linkList *pr=NULL;
	linkList *temp;
	cout << "�������ʼ�������ݸ���" << endl;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int data;
		temp = new linkList;
		
		cout << "�������" << (i + 1) << "������" << endl;
		cin >> data;
		if (i == 0) {
			head->address = temp;
			temp->data = data;
			pr = temp;
		}
		else if (i!=0&&i!=cnt-1)
		{
			temp->data = data;
			pr->address = temp;
	
			pr = temp;
		}
		else {
			temp->data = data;
			temp->address = NULL;
			pr->address = temp;
		}

		//delete temp;
	}
	
	return head;
}

void linkListDiplay(linkList *head) {
	linkList *pr = head;
	if (pr->address == NULL) {
		cout << "no linkList\n" << endl;
		return;
	}
	linkList *temp;
	temp = pr;
	bool state = true;
	while (true)
	{	
		
		temp = pr->address;
		cout << temp->data;
		pr = temp;
		if (pr->address == NULL) {
			cout << "\n" << endl;
			break;
		}
		cout << "->";
	}
}

void linkListInsert(linkList *head, int position, int data) {
	linkList *New = new linkList;
	New->data = data;
	linkList *temp = NULL;
	linkList *pr = head;
	for (int i = 0; i < position; i++) {
		temp = pr->address;
		pr = temp;
	}
	New->address = pr->address;
	pr->address = New;

}

void linkListDeleteNode(linkList *head, int position) {
	linkList *temp = NULL;
	linkList *pr = head;
	for (int i = 0; i < position;i++) {
		temp = pr->address;
		pr = temp;
		if (i == position - 2) {
			pr->address = pr->address->address;
		}
	}
}

void deletelinkList(linkList *head) {
	head->address = NULL;
}

linkList *relinkListInit(linkList *head) {
	int cnt;
	linkList *pr = NULL;
	linkList *temp;
	cout << "�������ʼ�������ݸ���" << endl;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int data;
		temp = new linkList;

		cout << "�������" << (i + 1) << "������" << endl;
		cin >> data;
		if (i == 0) {
			head->address = temp;
			temp->data = data;
			pr = temp;
		}
		else if (i != 0 && i != cnt - 1)
		{
			temp->data = data;
			pr->address = temp;

			pr = temp;
		}
		else {
			temp->data = data;
			temp->address = head;
			pr->address = temp;
		}

		//delete temp;
	}

	return head;
}

dlinkList *dlinkListInte(dlinkList* head) {
	int cnt;
	dlinkList* pr = NULL;
	dlinkList* temp;
	cout << "�������ʼ�������ݸ���" << endl;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int data;
		temp = new dlinkList;

		cout << "�������" << (i + 1) << "������" << endl;
		cin >> data;
		if (i == 0) {
			head->next = temp;
			head->forward = NULL;
			temp->data = data;
			temp->forward = head;
			pr = temp;
		}
		else if (i != 0 && i != cnt - 1)
		{
			temp->data = data;
			pr->next = temp;
			temp->forward = pr;
			pr = temp;
		}
		else {
			temp->data = data;
			temp->next = NULL;
			temp->forward = pr;
			pr->next = temp;
		}

		//delete temp;
	}

	return head;
}

void dlinkListDiplay(dlinkList* head) {
	dlinkList* pr = head;
	if (pr->next == NULL) {
		cout << "no linkList\n" << endl;
		return;
	}
	dlinkList* temp;
	temp = pr;
	bool state = true;
	while (true)
	{

		temp = pr->next;
		cout << temp->data;
		pr = temp;
		if (pr->next == NULL) {
			cout << "\n" << endl;
			break;
		}
		cout << "<->";
	}
}