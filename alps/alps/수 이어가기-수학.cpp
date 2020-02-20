#include <iostream>
using namespace std;

struct Range {
	double left = 0.5;  //ù��°
	double right = 1;   //�ι�° �ε��
	int count = 4;
};

double fib(int n) {
	if (n <= 1)
		return n;
	else
		return fib(n - 2) + fib(n - 1);
}


Range get_range(int n) {  //�ε���� �����ϴ� ���� k�� ������ ���� �۾����µ�
	Range k;              //�� ������ 0 �� �Ǳ� ������ �ε�� ������ ���ϴ� �Լ�
	if (n == 1)
		return k;

	double now_left, now_right;
	double before = 0;


	int i;
	int count = 1;   //�ε���� �����ϴ� ����k�� ����

	for (i = 2; count > 0; i++) {  //i��° ����
		if (i % 2) {       //Ȧ�����϶� �����ʿ��� ��������
			before = k.right;
			k.right = fib(i) / fib(i + 1);
		}
		else {  //¦�����϶� ���� ���� ����
			before = k.left;
			k.left = fib(i) / fib(i + 1);
		}

		now_left = k.left*n;              //@@@@@@@@@@ k���� @@@@@@@@@@@
		now_right = k.right*n;           //���� now_left <= k <= now_right


		//�ε���� �����ϴ� k ���� ������Ʈ
		if (now_left - (int)now_left == 0)  //�����϶�
			count = (int)now_right - now_left + 1;
		else  //�Ҽ��϶�
			count = (int)now_right - ((int)now_left + 1) + 1;
	}
	if (i % 2)
		k.left = before;
	else
		k.right = before;

	k.count = i;
	return k;
}


int main() {
	int n;
	cin >> n;
	if (!(0 < n&&n <= 30000))  //���ǰ˻�
		return 0;

	Range r = get_range(n);         //n=100 �̸�         61.5385 <= k <= 62.5
	//cout <<n*r.left << " <= k <= " << n*r.right << endl;

	int answer;
	if (n*r.left - (int)(n*r.left) == 0) //�ε���� �����ϴ� ���� k�� ���� ���� ��
		answer = n * r.left;
	else
		answer = ((int)n*r.left) + 1;


	//���
	cout << r.count << endl;
	cout << n << " " << answer << " ";
	while (n - answer >= 0) {
		cout << n - answer << " ";
		int temp = answer;
		answer = n - answer;
		n = temp;
	}
	cout << endl;
}