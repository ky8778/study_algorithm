
//! 2020.02.11
// TODO BJ12100_2048(Easy)
#include<cstdio>
#include<queue>

using namespace std;

const int MAX = 25;
int dirInfo[10];		// up : 0 down : 2 left : 1 right : 3
int newMap[MAX][MAX];
int inMap[MAX][MAX];
int N;
bool check[MAX];
queue <int> myQ;

void print() {
	printf("\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", newMap[i][j]);
		}
		printf("\n");
	}
}

int mapCopy(int reset) {
	int maxRet = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (reset == 1) {
				if (maxRet < newMap[i][j]) maxRet = newMap[i][j];
				newMap[i][j] = 0;
			}
			else newMap[i][j] = inMap[i][j];
		}
	}
	return maxRet;
}

bool inRange(int idx) {
	if (idx >= 0 && idx < N) return true;
	else return false;
}

void doNext(int& _prev, int& _cur,int& _cnt) {
	if (_prev == 0) {
		_cnt = 1;
		_prev = _cur;
	}
	else {
		if (_cur == _prev) {
			_cnt = 0;
			myQ.push(_prev * 2);
			_prev = 0;
		}
		else {
			myQ.push(_prev);
			_prev = _cur;
		}
	}
}

int getMax() {
	for (int c = 0; c < N; c++) check[c] = false;

	mapCopy(0);
	//print();
	int tmp;
	for (int m = 0; m < 5; m++) {
		int nextDir = dirInfo[m];
		//printf("direction : %d\n", nextDir);
		if (nextDir & 1) {
			for (int i = 0; i < N; i++) {
				int cnt = 0;
				int prev = 0;
				if (int(nextDir / 2) > 0) {
					for (int j = N - 1; j >= 0; j--) {
						int cur = newMap[i][j];
						if (cur == 0) continue;
						doNext(prev, cur,cnt);
					}
					if (cnt != 0) myQ.push(prev);
					int idx = N - 1;
					while (!myQ.empty()) {
						newMap[i][idx] = myQ.front();
						myQ.pop();
						idx--;
					}
					for (int j = idx; j >= 0; j--) newMap[i][j] = 0;
				}
				else {
					int cnt = 0;
					int prev = 0;
					for (int j = 0; j < N; j++) {
						int cur = newMap[i][j];
						if (cur == 0) continue;
						doNext(prev, cur, cnt);
					}
					if (cnt != 0) myQ.push(prev);
					int idx = 0;
					while (!myQ.empty()) {
						newMap[i][idx] = myQ.front();
						myQ.pop();
						idx++;
					}
					for (int j = idx; j < N; j++) newMap[i][j] = 0;
				}

			}
		}
		else {
			for (int j = 0; j < N; j++) {
				if (int(nextDir / 2) > 0) {
					int cnt = 0;
					int prev = 0;
					for (int i = N - 1; i >= 0; i--) {
						int cur = newMap[i][j];
						if (cur == 0) continue;
						doNext(prev, cur, cnt);
					}
					if (cnt != 0) myQ.push(prev);
					int idx = N - 1;
					while (!myQ.empty()) {
						newMap[idx][j] = myQ.front();
						myQ.pop();
						idx--;
					}
					for (int i = idx; i >= 0; i--) newMap[i][j] = 0;
				}
				else {
					int cnt = 0;
					int prev = 0;
					for (int i = 0; i < N; i++) {
						int cur = newMap[i][j];
						if (cur == 0) continue;
						doNext(prev, cur, cnt);
					}
					if (cnt != 0) myQ.push(prev);
					int idx = 0;
					while (!myQ.empty()) {
						newMap[idx][j] = myQ.front();
						myQ.pop();
						idx++;
					}
					for (int i = idx; i < N; i++) newMap[i][j] = 0;
				}
			}
		}
		//print();
	}
	//print();
	return mapCopy(1);
}


int getResult(int n) {
	if (n >= N) {
		return getMax();
	}
	else {
		int maxResult = -1;
		for (int dir = 0; dir < 4; dir++) {
			dirInfo[n] = dir;
			int tmpResult = getResult(n + 1);
			if (tmpResult > maxResult) maxResult = tmpResult;
		}
		return maxResult;
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &inMap[i][j]);
		}
	}

	printf("%d\n", getResult(0));
	return 0;
}

/*

//! 2020.02.11
// TODO BJ12100_2048(Easy)
#include<cstdio>

using namespace std;

const int MAX = 25;
int dirInfo[10];		// up : 0 down : 2 left : 1 right : 3
int newMap[MAX][MAX];
int inMap[MAX][MAX];
int N;
bool check[MAX];

void print() {
	printf("\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", newMap[i][j]);
		}
		printf("\n");
	}
}

int mapCopy(int reset) {
	int maxRet = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (reset == 1) {
				if (maxRet < newMap[i][j]) maxRet = newMap[i][j];
				newMap[i][j] = 0;
			}
			else newMap[i][j] = inMap[i][j];
		}
	}
	return maxRet;
}

bool inRange(int idx) {
	if (idx >= 0 && idx < N) return true;
	else return false;
}

int move(int idx, int start,int d, int RC) {
	int ret;
	if (RC == 1) {		// xÃà
		int curVal = newMap[idx][start];
		newMap[idx][start] = 0;
		int nextIdx = start + d;
		while (inRange(nextIdx) && newMap[idx][nextIdx] == 0) nextIdx += d;

		if (!inRange(nextIdx) || check[nextIdx] || newMap[idx][nextIdx] != curVal) {
			nextIdx -= d;
			newMap[idx][nextIdx] = curVal;
		}
		else {
			check[nextIdx] = true;
			newMap[idx][nextIdx] = curVal * 2;
		}
		ret = newMap[idx][nextIdx];
	}
	else if (RC == 2) {		// yÃà
		int curVal = newMap[start][idx];
		newMap[start][idx] = 0;
		int nextIdx = start + d;
		while (inRange(nextIdx) && newMap[nextIdx][idx] == 0) nextIdx += d;

		if (!inRange(nextIdx) || check[nextIdx] || newMap[nextIdx][idx] != curVal) {
			nextIdx -= d;
			newMap[nextIdx][idx] = curVal;
		}
		else {
			check[nextIdx] = true;
			newMap[nextIdx][idx] = curVal * 2;
		}
		ret = newMap[nextIdx][idx];
	}
	return ret;
}

int getMax() {
	for (int c = 0; c < N; c++) check[c] = false;

	mapCopy(0);
	//print();
	int tmp;
	for (int m = 0; m < 5; m++) {
		int nextDir = dirInfo[m];
		//printf("direction : %d\n", nextDir);
		if (nextDir & 1) {
			for (int i = 0; i < N; i++) {
				if (int(nextDir / 2) > 0) {
					for (int j = N - 1; j >= 0; j--) {
						if (newMap[i][j] == 0) continue;
						tmp = move(i, j,1, 1);
					}
				}
				else {
					for (int j = 0; j < N; j++) {
						if (newMap[i][j] == 0) continue;
						tmp = move(i, j, -1, 1);
					}
				}
			}
		}
		else {
			for (int j = 0; j < N; j++) {
				if (int(nextDir / 2) > 0) {
					for (int i = N - 1; i >= 0; i--) {
						if (newMap[i][j] == 0) continue;
						tmp = move(j, i, 1, 2);
					}
				}
				else {
					for (int i = 0; i < N; i++) {
						if (newMap[i][j] == 0) continue;
						tmp = move(j, i, -1, 2);
					}
				}
			}
		}
		//print();
	}
	//print();
	return mapCopy(1);
}


int getResult(int n) {
	if (n >= N) {
		return getMax();
	}
	else {
		int maxResult = -1;
		for (int dir = 0; dir < 4; dir++) {
			dirInfo[n] = dir;
			int tmpResult = getResult(n + 1);
			if (tmpResult > maxResult) maxResult = tmpResult;
		}
		return maxResult;
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &inMap[i][j]);
		}
	}

	printf("%d\n", getResult(0));
	return 0;
}
*/