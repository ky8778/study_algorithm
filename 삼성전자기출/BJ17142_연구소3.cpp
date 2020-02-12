
//! 2020.02.11
// TODO BJ17142_¿¬±¸¼Ò3
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;
const int MAX = 55;
const int INF = 987654321;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
int N, M;
int inMap[MAX][MAX];
bool checkMap[MAX][MAX];
int numBlank;
vector <pair<int, int>> myV;
queue <pair<int, int>> myQ;
int vInfo[15];

bool inRange(int y, int x) {
	if (y >= 0 && y < N && x >= 0 && x < N) return true;
	else return false;
}

int BFS() {
	int cnt = 0;
	int t = -1;
	for (int i = 0; i < M; i++) {
		int idx = vInfo[i];
		int y = myV[idx].first;
		int x = myV[idx].second;
		checkMap[y][x] = true;
		myQ.push(make_pair(y, x));
	}

	while (!myQ.empty() && cnt<numBlank) {
		t++;
		int sizeQ = myQ.size();
		for (int i = 0; i < sizeQ; i++) {
			pair <int, int> current = myQ.front();
			myQ.pop();
			if (inMap[current.first][current.second] == 0) cnt++;

			for (int dir = 0; dir < 4; dir++) {
				int nextY = current.first + dy[dir];
				int nextX = current.second + dx[dir];
				if (inRange(nextY, nextX)) {
					if (!checkMap[nextY][nextX] && inMap[nextY][nextX]!=1){
						checkMap[nextY][nextX] = true;
						myQ.push(make_pair(nextY, nextX));
					}
				}
			}
		}
	}
	queue <pair<int, int>> empty;
	empty.swap(myQ);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			checkMap[i][j] = false;
		}
	}

	if (cnt < numBlank) return INF;
	else return t;
}

int getResult(int n, int prev) {
	if (n >= M) {
		return BFS();
	}
	else {
		int minResult = INF;
		for (int i = prev + 1; i < myV.size(); i++) {
			vInfo[n] = i;
			int tmpResult = getResult(n + 1, i);
			if (tmpResult < minResult) minResult = tmpResult;
		}
		return minResult;
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &inMap[i][j]);
			if (inMap[i][j] == 2) myV.push_back(make_pair(i, j));
			else if (inMap[i][j] == 0) numBlank++;
		}
	}

	if (numBlank == 0) printf("%d\n", 0);
	else {
		int result = getResult(0, -1);
		if (result > 3000) result = -1;
		printf("%d\n", result);
	}
	return 0;
}