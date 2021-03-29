#include <iostream>
#include <string>
using namespace std;

class Student {
	int id;
	string name;
	string dept;
public:
	Student(int i, string n, string d) { id = i, name = n, dept = d; }
	~Student(){}
	void display() {
		printf(" �й�: %-15d �̸�: %-15s �а�: %-15s\n", id, name.c_str(), dept.c_str());
	}
};

class Node:public Student {
	Node* link;
public:
	Node(int i, string n, string d)
		:Student(i, n, d) {
		link = NULL;
	}
	~Node() {}
	Node* getLink() { return link; }
	void setLink(Node* p) { link = p; }
};

class LinkedQueue {
	Node* front;
	Node* rear;
public:
	LinkedQueue() { front = NULL, rear = NULL; }
	~LinkedQueue() { while (!isEmpty()) delete pop(); }
	bool isEmpty() { return front == NULL && rear==NULL; }
	void push(Node* p) {
		if (isEmpty()){
			front = p;
			rear = p;
		}
		else {
			rear->setLink(p);
			rear = p;
		}
	}
	Node* pop() {
		if (isEmpty())
			return NULL;
		else {
			Node* p = front;
			front = p->getLink();
			if ( front == NULL ) rear = NULL;
			return p;
		}
	}
	Node* peek() { return front; }
	void display() {
		for (Node* p = front; p != NULL; p = p->getLink())
			p->display();
	}

};

int main() {
	LinkedQueue que;
	que.push(new Node(201611218, "�̱���", "��ǻ�Ͱ��к�"));
	que.push(new Node(201611218, "����", "�����"));
	que.push(new Node(201611218, "���ȯ", "��ǻ�Ͱ��к�"));
	que.display();

	cout <<"isEmpty?: "<< que.isEmpty() << endl;

	Node* node = que.pop();
	cout << "pop: ";
	node->display();

	node = que.pop();
	cout << "pop: ";
	node->display();

	node = que.pop();
	cout << "pop: ";
	node->display();

	cout << "isEmpty?: " << que.isEmpty() << endl;


	que.push(new Node(201611218, "������", "��ǻ�Ͱ��к�"));
	que.display();

	node = que.pop();
	cout << "pop: ";
	node->display();

	cout << "isEmpty?: " << que.isEmpty() << endl;
	delete node;
}