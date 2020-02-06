#include <iostream>
using namespace std;
#define K 27    //�ִ�����
#define N 1001   //�ִ� ��ٸ���

struct Point {
	int i, j;
};

class Ladder {
private:
	char data[N + 2][K + 1];             //��ٸ�
	int k, n;                       //���,��ٸ� ��
	char end[K + 1];                  //���� ���ڿ� 
	Point s, e;                     //����, �� ������
	int line;                       //ã�����ϴ� ����ǥ ������ �ε���
public:
	Ladder();
	~Ladder();
	void play();

	bool init();         //��ٸ� �ʱ�ȭ
	void show();
	void ready(char ch);  //s,e������ �ʱ�ȭ
	void go();              //?���� s,e�����͸� �̵�
	bool isValid();         //?�� ������ s,e �� ��ȿ�� �˻�
	bool check_and_add(Point a, Point b);  //�߰��ϰų� �˻�
	void show_answer();
	void show_x();
	void test();
	int min(int x, int y);
	int abs(int num);
};

Ladder::Ladder() {
}

Ladder::~Ladder() {

}

bool Ladder::init() {
	cin >> k;
	cin >> n;   //[n+2][k+1]���� �迭 �ʿ�

	if (!(3 <= k && k <= K && 3 <= n && n <= N)) //�ִ밪 Ȯ��
		return false;

	for (int i = 0; i < n + 2; i++) {  //��ٸ� *�� �ʱ�ȭ
		for (int j = 0; j < k + 1; j++)
			data[i][j] = '*';
	}

	cin >> end;
	for (int i = 1; i < k + 1; i++) {
		data[0][i] = 'A' + i - 1;     //���� ���ڿ� �ʱ�ȭ
		data[n + 1][i] = end[i - 1];  //���� ���ڿ� �ʱ�ȭ
	}

	for (int i = 0; i < n; i++) {  //��ٸ� �Է�
		cin >> end; //end��Ȱ��
		if (end[0] == '?')
			line = i + 1;
		for (int j = 0; j < k - 1; j++)
			data[i + 1][j + 1] = end[j];
	}

	return true;
}

void Ladder::show() {
	cout << endl;
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < k + 1; j++)
			cout << data[i][j];
		cout << endl;
	}
}

void Ladder::ready(char ch) {       //s,e �غ�Ϸ�
	for (int i = 0; i < k; i++) {
		if (ch == data[0][i + 1]) {
			s.i = 0;
			s.j = i + 1;
		}
		if (ch == data[n + 1][i + 1]) {
			e.i = n + 1;
			e.j = i + 1;
		}
	}
}

void Ladder::go() {    //�ڽŰ� ���ʳ��� ���� �� "**"�� �ƹ��͵� "-*"�� �������� "*-"�� ����������
	while (s.i != line) {        //����ǥ���� ����
		if (data[s.i][s.j - 1] == '-'&& data[s.i][s.j] == '*') {  //����
			s.j--;
		}
		else if (data[s.i][s.j - 1] == '*'&& data[s.i][s.j] == '-') {  //������
			s.j++;
		}
		s.i++;  //�Ʒ��� �����̴� s������
	}
	while (e.i != line) {
		if (data[e.i][e.j - 1] == '-'&& data[e.i][e.j] == '*') {
			e.j--;
		}
		else if (data[e.i][e.j - 1] == '*'&& data[e.i][e.j] == '-') {
			e.j++;
		}
		e.i--;  //���� �����̴� e������
	}
}

bool Ladder::isValid() { //j ���̰� -1,0,1 �� ��ȿ
	return abs(s.j - e.j) <= 1;
}

bool Ladder::check_and_add(Point a, Point b) {
	char same_answer[5] = "**";          //s,e �����Ͱ� ������ ??�� "**"
	char dif_answer[5] = "*-*";        //s,e �����Ͱ� �ٸ��� ???�� "*-*"

	if (a.j == b.j) {  //s==e
		for (int i = 0; i < 2; i++) {      //"**"
			if (data[line][a.j - 1 + i] == '?')         //?�� �߰�
				data[line][a.j - 1 + i] = same_answer[i];
			else if (data[line][a.j - 1 + i] != same_answer[i])  //?�� �ƴϰ� ����� �ٸ��ٸ�
				return false; //��ȿ�� ��ٸ�
		}
	}
	else {  //s!=e
		int val = min(a.j, b.j);
		for (int i = 0; i < 3; i++) {   //"*-*"
			if (data[line][val - 1 + i] == '?')
				data[line][val - 1 + i] = dif_answer[i];
			else if (data[line][val - 1 + i] != dif_answer[i])
				return false;
		}
	}
	return true;
}

void Ladder::show_answer() {
	for (int i = 0; i < k - 1; i++)
		cout << data[line][i + 1];
	cout << endl;
}

void Ladder::show_x() {
	for (int i = 0; i < k - 1; i++)
		cout << 'x';
	cout << endl;
}

void Ladder::test() {
	cout << s.i << "," << s.j << endl;
	cout << e.i << "," << e.j << endl << endl;
}

int Ladder::min(int x, int y) {
	if (x > y)
		return y;
	else
		return x;
}

int Ladder::abs(int num) {
	if (num < 0)
		return -num;
	else
		return num;
}

void Ladder::play() {
	if (init()) {                  //�ʱ�ȭ ������
		int i;
		for (i = 0; i < k; i++) { //����� ��ŭ
			ready('A' + i);       //s,e ������ �ʱ�ȭ
			go();                 //?���� s,e������ ���
			if (!isValid())       //?���� ������ s,e�����Ͱ� ��ȿ���� �˻�
				break;
			else if (!check_and_add(s, e)) //�߰��ϰų� �˻��ϰų�
				break;

		}

		if (i == k)  //�ݺ����� break�����ʰ� ������ �Դٸ�
			show_answer();
		else        //�߰��� break �ߴٸ� ��ȿ�� ��ٸ�
			show_x();

	}
}

int main() {

	Ladder l;
	l.play();
}