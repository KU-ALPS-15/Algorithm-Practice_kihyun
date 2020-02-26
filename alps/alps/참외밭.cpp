#include <iostream>
using namespace std;

struct Set {
	int way;
	int len;
};

Set s[6];
int max_size, min_size; //ū �簢������ ���� �簢���� �� ���̰� ������ ��ü ����!

void get_size(int way1, int way2) {
	int M_width, M_height;
	int m_width, m_height;

	for (int i = 0; i < 6; i++) {
		if (s[i].way == way1)
			M_height = s[i].len;
		else if (s[i].way == way2) {
			M_width = s[i].len;
			m_width = s[(i + 2) % 6].len;
			m_height = s[(i + 3) % 6].len;
		}

	}
	max_size = M_width * M_height;
	min_size = m_width * m_height;
}

int main() {
	int K; cin >> K;

	int right_count = 0, down_count = 0;  //�������� �������� ��� Ȯ��!!!

	for (int i = 0; i < 6; i++) {
		cin >> s[i].way >> s[i].len;
		if (s[i].way == 1)
			right_count++;
		if (s[i].way == 3)
			down_count++;
	}

	if (right_count == 1 && down_count == 1) { //������ ���� ��
		get_size(3, 1);
	}
	else if (right_count == 1 && down_count == 2) { //���� ���� ��
		get_size(1, 4);
	}
	else if (right_count == 2 && down_count == 1) { //������ �Ʒ��� ��
		get_size(2, 3);
	}
	else if (right_count == 2 && down_count == 2) { //���� �Ʒ��� ��
		get_size(4, 2);
	}

	cout << K * (max_size - min_size) << endl;
}