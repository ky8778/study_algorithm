//! 2020.02.18
// TODO BJ17135_Ä³½½µðÆæ½º
#include<cstdio>
#include<vector>
using namespace std;

const int MAX = 20;
int N, M, D;
int inMap[MAX][MAX];
int nextMap[MAX][MAX];
int length[MAX];
int nextLen[MAX];
bool check[MAX];
int T;
int army[3];

bool inRange(int y, int x) {
	if(y >= 0 && y < N && x >= 0 && x < M) return true;
	else return false;
}

pair<int, int> search(int y, int x) {
	pair<int, int> ret = make_pair(-1, -1);
	for (int d = 0; d < D; d++) {
		for (int j = x - d; j <= x + d; j++) {
			int i;
			if(j<=x) i = x + y - d - j;
			else i = y - (x + d -j);
			//printf("i : %d,j : %d\n", i, j);
			if (inRange(i,j) && nextMap[i][j] == 1) {
				ret.first = i;
				ret.second = j;
				return ret;
			}
		}
	}
	return ret;
}

int kill() {
	vector <pair<int, int>> myV;
	for (int k = 0; k < 3; k++) {
		int px = army[k];
		int py = N - 1;
		myV.push_back(search(py, px));
	}
	int killCnt = 0;

	for (int k = 0; k < 3; k++) {
		int y = myV[k].first;
		int x = myV[k].second;
		if (y != -1 && nextMap[y][x] > 0) {
			//printf("y : %d, x : %d\n", y, x);;
			nextMap[y][x] -= 1;
			killCnt++;
		}
	}
	return killCnt;
}

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", nextMap[i][j]);
		}
		printf("\n");
	}
}

void move() {
	for (int j = 0; j < M; j++) {
		for (int i = N - 1; i >= nextLen[j]+1; i--) {
			nextMap[i][j] = nextMap[i - 1][j];
		}
		if (nextLen[j] < N) {
			nextMap[nextLen[j]][j] = 0;
			nextLen[j]++;
		}
	}
}

int simulate() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			nextMap[i][j] = inMap[i][j];
		}
		for(int j=0;j<M;j++) nextLen[j] = length[j];
	}

	for (int t = T; t <= N; t++) {
		//printf("%d %d %d\n", army[0], army[1], army[2]);
		//printf("\nkill\n");
		ret += kill();
		//print();
		//printf("move\n");
		move();
		//print();
		//printf("ret : %d\n", ret);
	}

	return ret;
}

int getResult(int idx,int prev) {
	if (idx >= 3) return simulate();
	else {
		int maxRet = -1;
		for (int j = prev + 1; j < M; j++) {
			army[idx] = j;
			int tmpRet = getResult(idx + 1, j);
			if (tmpRet > maxRet) maxRet = tmpRet;
		}
		return maxRet;
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &D);
	T = -1;
	for (int j = 0; j < M; j++) length[j] = N-1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &inMap[i][j]);
			if (inMap[i][j] == 1) {
				if (T == -1) T = i;
				if (!check[j]) {
					check[j] = true;
					length[j] = i;
				}
			}
		}
	}
	printf("%d\n", getResult(0,-1));
	return 0;
}