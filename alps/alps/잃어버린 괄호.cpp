#include <iostream>
#include <string>
#include <vector>
#define SIZE 51
using namespace std;


int main() {
	vector<int> num;
	string s = "";
	char ch;
	int ans = 0;
	int first = 0;   //ù��°�� -�� ������ �ε���
	bool tof = true;
	for (int i = 0; i < SIZE; i++) {  //�Է�
		ch = getchar();
		if (ch == '\n') {
			num.push_back(stoi(s));
			break;
		}
		else if (ch == '+' || ch == '-') {
			num.push_back(stoi(s));
			if (ch == '-' && tof) {
				first = num.size();
				tof = false;
			}
			s = "";
		}
		else
			s += ch;
	}



	if (first == 0) {   //��� +��
		for (int i = 0; i < num.size(); i++) {
			ans += num[i];
		}
	}
	else {  //�ϳ��� -�� ������
		for (int i = 0; i < num.size(); i++) {
			if (i < first)
				ans += num[i];
			else
				ans -= num[i];
		}
	}
	cout << ans << endl;
}