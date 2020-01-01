#include <iostream>
#include <vector>

using namespace std;

vector<int> tile;

void solution(int n) {
	int res;

	tile.push_back(1);
	tile.push_back(2);

	for (int i = 2; i < n; i++) {
		res = (tile[i - 1] + tile[i - 2]) % 1000000007;
		tile.push_back(res);
	}
}

int main() {
	int n;

	cin >> n;
	solution(n);
	cout << tile[n-1];
}