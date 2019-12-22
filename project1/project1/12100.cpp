#include <iostream>
#include <queue>

using namespace std;

const int MAX = 20;

int N;
int board[MAX][MAX];
int maxBlock;

void shift(int type) {
	queue<int> q;

	// ���ڵ��� ť�� ����ְ� �� ����
	// �ش���� ���������� ���ڸ� �ֱ� ����
	switch (type) {
	
	// ����
	case 0:
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j])
					q.push(board[i][j]);
				board[i][j] = 0;
			}

			int idx = 0;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (board[i][idx] == 0)
					board[i][idx] = data;
				else if (board[i][idx] == data) {
					board[i][idx] *= 2;

					idx++;
				}
			}
		}
		break;
	case 1:
		break;
	}
}

void DFS(int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				maxBlock = max(maxBlock, board[i][j]);
			return;
		}
	}

	int copyBoard[MAX][MAX];

	// ���� ������¸� ����
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			copyBoard[i][j] = board[i][j];

	for (int i = 0; i < 4; i++) {
		shift(i);
		DFS(cnt + 1);

		// �����س��� ������·� ���󺹱�
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				board[i][j] = copyBoard[i][j];
	}
}

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	DFS(0);
	cout << maxBlock << endl;
	return 0;
}