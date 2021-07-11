#include <iostream>
using namespace std;

int action = 0;

void hanoiTower(int n, char from, char tmp, char to) {
	if (n == 1) {
		printf("1 �� ������ %c ���� %c �� �ű��.\n", from, to);
		action++;
	}
	else {
		hanoiTower(n - 1, from, to, tmp);
		printf("%d �� ������ %c ���� %c �� �ű��.\n", n, from, to);
		action++;
		hanoiTower(n - 1, tmp, from, to);
	}
}

int main() {
	hanoiTower(8, 'A', 'B', 'C');
	printf("count: %d\n", action);
}