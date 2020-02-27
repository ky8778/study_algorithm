//! 2020.02.17
// TODO BJ17070_파이프옮기기1
#include<cstdio>
using namespace std;
const int dx[3] = { 1,1,0 };
const int dy[3] = { 0,1,1 };
const int MAX = 20;
int N;
int inMap[MAX][MAX];
bool checkMap[MAX][MAX];

bool checking(int y, int x) {
	if (y >= 0 && y < N && x < N && x >= 0) {
		if (!checkMap[y][x]) return true;
		else return false;
	}
	else return false;
}

bool checkNext(int dir, int y, int x) {
	if (dir == 1) {
		for (int i = 0; i < 3; i++) {
			int nextY = y + dy[i];
			int nextX = x + dx[i];
			if (!checking(nextY, nextX)) return false;
		}
	}
	else {
		if (!checking(y + dy[dir], x + dx[dir])) return false;
	}
	return true;
}

int getResult(int prevDir,int y,int x) {
	if (y >= N - 1 && x >= N - 1) return 1;
	else {
		int ret = 0;
		int startDir, endDir;
		if (prevDir == 0) {
			startDir = 0;
			endDir = 1;
		}
		else if (prevDir == 2) {
			startDir = 1;
			endDir = 2;
		}
		else if(prevDir==1){
			startDir = 0;
			endDir = 2;
		}

		for (int dir = startDir; dir <= endDir; dir++) {
			if (checkNext(dir, y, x)) {
				if (dir == 1) {
					for (int i = 0; i < 3; i++) {
						int nextY = y + dy[i];
						int nextX = x + dx[i];
						checkMap[nextY][nextX] = true;
					}
				}
				else checkMap[y + dy[dir]][x + dx[dir]] = true;

				ret += getResult(dir,y + dy[dir], x + dx[dir]);
				
				if (dir == 1) {
					for (int i = 0; i < 3; i++) {
						int nextY = y + dy[i];
						int nextX = x + dx[i];
						checkMap[nextY][nextX] = false;
					}
				}
				else checkMap[y + dy[dir]][x + dx[dir]] = false;
			}
		}
		return ret;
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &inMap[i][j]);
			if(inMap[i][j]==1) checkMap[i][j] = true;
		}
	}
	checkMap[0][0] = true;
	checkMap[0][1] = true;
	printf("%d\n", getResult(0,0,1));
	return 0;
}