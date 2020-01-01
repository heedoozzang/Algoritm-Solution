#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> list;
int cnt = 0;
int minCount = 0;

void BFS(int N, int number) {
	if (cnt >= minCount) return;
	if (list.size() >= minCount) return;
	int lastNumber = (list.size() == 0) ? 0 : list.back();

	if (lastNumber == number) {
		minCount = min(cnt, minCount);
		return;
	}

	int n = 0;
	int addCount = 0;

	for (int i = 1; i < 10000000; i *= 10) {
		addCount++;
		if (cnt + addCount >= minCount) continue;

		n += (N * i);

		cnt += addCount;

		list.push_back(lastNumber + n);
		BFS(N, number);
		list.pop_back();
		
		if (lastNumber - n != 0) {
			list.push_back(lastNumber - n);
			BFS(N, number);
			list.pop_back();
		}

		list.push_back(lastNumber * n);
		BFS(N, number);
		list.pop_back();

		if (lastNumber / n != 0) {
			list.push_back(lastNumber / n);
			BFS(N, number);
			list.pop_back();
		}

		cnt -= addCount;
	}
	return;
}

int solution(int N, int number) {
	BFS(N, number);

	return minCount < 9 ? minCount : -1;
}

int main() {

}