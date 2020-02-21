//! 2020.02.20 ~ 2020.02.21
// TODO BJ17281_Baseball
#include<cstdio>
using namespace std;
const int MAX = 55;
const int NP = 9;
int inData[MAX][NP];
int T;
bool check[NP];
int orderP[NP];
int Nru[4];

void movePlayer(int hits) {
	for (int i = 2; i >= 0 ; i--) {
		if (Nru[i] != 0) {
			int next = i + hits;
			if (next >= 3) next = 3;
			Nru[i]--;
			Nru[next]++;
		}
	}
	Nru[hits - 1]++;
}

int playGame() {
	int thisRet = 0;
	int cur = 0;
	for (int t = 0; t < T; t++) {
		int cnt = 0;
		while (cnt < 3) {
			int player = orderP[cur % NP];
			if (inData[t][player] == 0) cnt++;
			else movePlayer(inData[t][player]);
			cur++;
		}
		thisRet += Nru[3];
		for (int i = 0; i < 4; i++) {
			Nru[i] = 0;
		}
	}

	return thisRet;
}

int getResult(int orderIdx) {
	if (orderIdx >= NP) return playGame();
	else {
		if (orderIdx == 3) orderIdx++;
		int maxRet = -1;
		for (int idx = 1; idx < NP; idx++) {
			if (!check[idx]) {
				check[idx] = true;
				orderP[orderIdx] = idx;
				int tmpRet = getResult(orderIdx + 1);
				if (tmpRet > maxRet) maxRet = tmpRet;
				check[idx] = false;
			}
		}
		return maxRet;
	}
}

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < NP; j++) {
			scanf("%d", &inData[i][j]);
		}
	}
	check[0] = true;
	orderP[3] = 0;
	printf("%d\n", getResult(0));
	return 0;
}