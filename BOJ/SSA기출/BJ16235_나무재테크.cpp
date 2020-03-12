//! 2020.02.12
// TODO BJ16235_나무재테크
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 15;
const int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
int inMap[MAX][MAX];
int deadMap[MAX][MAX];
int plusMap[MAX][MAX];
vector <int> treeInfo[MAX][MAX];
int N, M, K;

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", treeInfo[i][j].size());
		}
		printf("\n");
	}
}

bool inRange(int y, int x) {
	if (y >= 0 && y < N && x >= 0 && x < N) return true;
	else return false;
}

void spring() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int sizeT = treeInfo[i][j].size();
			if (sizeT != 0) {
				sort(treeInfo[i][j].begin(), treeInfo[i][j].end());
				int idx = 0;
				while (treeInfo[i][j][idx] <= inMap[i][j]) {
					inMap[i][j] -= treeInfo[i][j][idx];
					treeInfo[i][j][idx]++;
					idx++;
					if (idx >= sizeT) break;
				}
				for (int n = sizeT - 1; n >= idx; n--) {
					deadMap[i][j] += (treeInfo[i][j][n] / 2);
					treeInfo[i][j].pop_back();
				}
			}
		}
	}
}

void summer() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			inMap[i][j] += deadMap[i][j];
			deadMap[i][j] = 0;
		}
	}
}

void fall() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int n = 0; n < treeInfo[i][j].size(); n++) {
				if (treeInfo[i][j][n] % 5 == 0) {
					for (int dir = 0; dir < 8; dir++) {
						int nextY = i + dy[dir];
						int nextX = j + dx[dir];
						if (inRange(nextY, nextX)) treeInfo[nextY][nextX].push_back(1);
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			inMap[i][j] += plusMap[i][j];
		}
	}
}

int getResult() {
	int cnt = 0;
	for (int k = 0; k < K; k++) {
		spring();
		summer();
		fall();
		winter();
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cnt += treeInfo[i][j].size();
		}
	}
	return cnt;
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			inMap[i][j] = 5;
			scanf("%d", &plusMap[i][j]);
		}
	}
	for (int m = 0; m < M; m++) {
		int y, x, age;
		scanf("%d %d %d", &y, &x, &age);
		treeInfo[y - 1][x - 1].push_back(age);
	}
	printf("%d\n", getResult());
	return 0;
}
