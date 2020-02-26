#include <iostream>
#include <algorithm>
#include <string>
#define SIZE 500001
using namespace std;
int A[SIZE];

int lower_binary(int target, int size) {
	int mid, start, end;
	start = 0, end = size - 1;

	while (end > start) {
		mid = (start + end) / 2;
		if (A[mid] >= target)
			end = mid;
		else start = mid + 1;
	}
	return end;
}

int upper_binary(int target, int size) {
	int mid, start, end;
	start = 0, end = size - 1;

	while (end > start) {
		mid = (start + end) / 2;
		if (A[mid] > target)
			end = mid;
		else start = mid + 1;
	}
	return end;
}



int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	sort(A, A + N);

	int M; cin >> M;
	int m;
	string answer = "";
	for (int i = 0; i < M; i++) {
		cin >> m; //m==1
		if (A[0] > m || A[N - 1] < m) {  //���� ��
			answer += "0 ";
			continue;
		}
		else { //���� ��
			int left = 0, right = N - 1;
			int mid;
			while (left <= right) {
				mid = (left + right) / 2;
				if (A[mid] == m) {  //������
					int upper = upper_binary(m, N);
					int lower = lower_binary(m, N);
					if (upper == N - 1 && A[N - 1] == m)
						upper++;
					answer += to_string(upper - lower) + ' ';
					break;
				}
				else if (A[mid] > m) { //����
					right = mid - 1;
				}
				else { //������
					left = mid + 1;
				}
			}
			if (left > right)
				answer += "0 ";
		}
	}
	cout << answer << endl;
}