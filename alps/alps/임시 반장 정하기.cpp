#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 1001
using namespace std;

class Leader {
private:
	int n;
	vector<int> data[5];  //�������� �����ϳ��� ����. �ѹ��� ���ؾ��ϴ� ������ ������(�г�)�̱⶧����.
	vector<int> answer[SIZE];  //�л�����ŭ�� ���交�� ����
public:
	bool init() {
		int now;
		cin >> n;
		if (!(3 <= n && n <= SIZE))
			return false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> now;
				if (!(1 <= now && now <= 9))
					return false;
				data[j].push_back(now);  //�г⺰����
			}
		}
		return true;
	}
	void calc() {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < n; j++) {
				int now = data[i][j];  //j+1��° �л���
				for (int k = j + 1; k < n; k++) {
					if (now == data[i][k]) {//k+1��° �л��� ���� ������
						append_answer(j, k);//j ��° �л��� ���� ���Ϳ� k�л��߰�
						append_answer(k, j);//���ÿ� k��°�л��� ���交�Ϳ��� j�л��߰�
					}
				}
			}
		}
	}
	void append_answer(int index,int val) {
		if(!(find(answer[index].begin(), answer[index].end(),val)!= answer[index].end()))//!(�̹� �������� ���� ������)
			answer[index].push_back(val);
	}
	int find_max() { //�� �л��� ���� ���͵��� ����ū ������(����ģ���� �������̵�)�� ���� �༮�� �ӽù��� �缱 ������
		int idx=0;
		int max = answer[0].size();
		for (int i = 1; i < n; i++) {
			if (max < answer[i].size()) {
				idx = i;
				max = answer[i].size();
			}
		}
		return idx+1;
	}
	void play() {
		if (init()) {
			calc();
		}
		cout << find_max() << endl;
	}
	void test() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < answer[i].size(); j++) {
				cout << answer[i][j] << " ";
			}
			cout << endl;
			
		}
	}
};

int main() {
	Leader l;
	l.play();
}