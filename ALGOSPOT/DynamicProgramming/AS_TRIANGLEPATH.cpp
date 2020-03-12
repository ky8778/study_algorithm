//! 2020.02.17
// TODO AS_TRIANGLEPATH.cpp
// Dynamic Programming
#include<cstdio>
using namespace std;

const int MAX = 105;
int DP[MAX][MAX];
int inMap[MAX][MAX];
int C, N;

void resetMap(int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			DP[i][j] = -1;
			inMap[i][j] = 0;
		}
	}
}

int getResult(int y,int x) {
	int& ret = DP[y][x];
	if (ret != -1) return ret;
	if (y>=N-1) {
		return ret = inMap[y][x];
	}
	else {
		int tmpMax1 = inMap[y][x];
		int tmpMax2 = inMap[y][x];
		tmpMax1 += getResult(y+1, x + 1);
		tmpMax2 += getResult(y+1, x);
		return ret = tmpMax1 > tmpMax2 ? tmpMax1 : tmpMax2;
	}
}

int main() {
	scanf("%d", &C);
	resetMap(MAX, MAX);
	for (int c = 0; c < C; c++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < i+1; j++) {
				scanf("%d", &inMap[i][j]);
			}
		}
		printf("%d\n", getResult(0,0));
		resetMap(N, N);
	}

	return 0;
}