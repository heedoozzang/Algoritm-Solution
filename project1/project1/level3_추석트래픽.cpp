#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<string> lines;

int TimeToNum(string line) {
	string th = line.substr(11, 2);
	string tm = line.substr(14, 2);
	string ts = line.substr(17, 6);
	ts.erase(ts.begin() + 2, ts.begin() + 3); // 소수점 제거

	int hour = stoi(th) * 60 * 60 * 1000;
	int minute = stoi(tm) * 60 * 1000;
	int sec = stoi(ts);

	return hour + minute + sec;
}

int ProcessToNum(string line) {
	string tmp = line.substr(24, line.size() - 25);
	double num = stod(tmp);
	int res = num * 1000;

	return res;
}

int solution() {
	int answer = 0;

	vector<int> process, end_point;

	for (int i = 0; i < lines.size(); i++) {
		string line = lines[i];
		int end_time = TimeToNum(line);
		int process_time = ProcessToNum(line);

		//cout << i << "번 째 " << start_time << " " << end_time << "\n";
		process.push_back(process_time);
		end_point.push_back(end_time);
	}

	int next_start_time, fur_time;
	for (int i = 0; i < lines.size(); i++) {
		int tmp = 0;
		fur_time = end_point[i] + 1000;
		for (int j = i + 1; j < lines.size(); j++) {
			next_start_time = end_point[j] - process[j] + 1;
			if (next_start_time < fur_time) {
				tmp++;
				continue;
			}
		}
		if (tmp > answer)
			answer = tmp;
	}
	return answer + 1;
}

int main() {
	freopen("Text.txt", "r", stdin);

	int n, answer;

	cin >> n;
	cin.get();
	for (int i = 0; i < n; i++) {
		string input;
		getline(cin, input);
		lines.push_back(input);
	}

	for (int i = 0; i < lines.size(); i++)
		cout << lines[i] << "\n";

	answer = solution();
	cout << answer;
}