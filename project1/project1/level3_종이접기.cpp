#include <iostream>
#include <vector>
using namespace std;

vector<int> paper;

void nFold(int num) {

	/* 1번접기 2번접기 초기화 */
	if (num == 1)
		paper.push_back(0);
	else if (num == 2) {
		paper.push_back(0);
		paper.push_back(0);
		paper.push_back(1);
	}
	else {
		paper.push_back(0);
		paper.push_back(0);
		paper.push_back(1);

		/* 3번 ~ 20번 접기 */
		for (int i = 3; i <= num; i++) {
			vector<int> next_paper(paper);

			next_paper.assign(paper.begin(), paper.end());
			next_paper.push_back(0); // 무조건 가운데는 0

			int n = (paper.size() / 2);
			paper.at(n)= 1;

			for (int j = 0; j < paper.size(); j++)
				next_paper.push_back(paper[j]);

			paper.clear();
			paper.assign(next_paper.begin(), next_paper.end());
			next_paper.clear();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;

	cin >> num;
	nFold(num);

	cout << "[";
	for (int i = 0; i < paper.size(); i++) {
		if(i == paper.size()-1)
			cout << paper[i];
		else
			cout << paper[i] << ",";
	}
	cout << "]";
}