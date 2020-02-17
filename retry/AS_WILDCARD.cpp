//! 2020.02.17
// TODO AS_WILDCARD
// Brute Force (Dynamic Programming)
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 105;
int C, N;
vector <string> result;
int sizeStr;
string input1;
string input2;
int DP[MAX][MAX];

bool compare(string s1, string s2) {
	if (s1.compare(s2) < 0) return true;
	else return false;
}

bool getResult(int idx1, int idx2) {
	int& ret = DP[idx1][idx2];
	if (ret != -1) return ret;
	if (idx1 >= input1.length()) {
		if (idx2 >= input2.length()) return ret = 1;
		else return ret = 0;
	}
	else {
		if (input1[idx1] == '*') {
			if (idx2 >= input2.length()) return ret = getResult(idx1 + 1, idx2);
			else return ret = getResult(idx1 + 1, idx2 + 1) || getResult(idx1, idx2 + 1) || getResult(idx1 + 1, idx2)? 1:0;
		}
		else {
			if (idx2 >= input2.length()) return ret = 0;
			else if (input1[idx1] == '?') return ret = getResult(idx1 + 1, idx2 + 1);
			else if (input1[idx1] == input2[idx2]) return ret = getResult(idx1 + 1, idx2 + 1);
			else return ret = 0;
		}
	}
}

void resetDP(int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			DP[i][j] = -1;
		}
	}
}

int main() {
	resetDP(MAX, MAX);
	cin >> C;
	for (int c = 0; c < C; c++) {
		cin >> input1;
		cin >> N;
		for (int n = 0; n < N; n++) {
			cin >> input2;
			//cout << input1 << endl << input2 << endl;
			if (getResult(0, 0)==1) result.push_back(input2);
			resetDP(input1.length()+1, input2.length()+1);
		}
		//printf("%d\n", result[0].compare(result[1]));
		sort(result.begin(), result.end(), compare);
		//cout << "my results!!!" << endl;
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << endl;
		}
		vector <string> empty;
		result.swap(empty);
	}

	return 0;
}