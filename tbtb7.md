https://www.acmicpc.net/problem/17281

<strong><span style="color:blue">안녕</span></strong>

### 풀이

> > 알고리즘
> >
> > BruteForce + Simulation
> >
> > 시간복잡도
> >
> > 50(이닝수) * 27(최악의 simulation : 3 아웃되는 동안 모든 타자가 타석에 서는 경우) * 8팩토리얼(타자 순서 정하는 모든 경우의 수) = 5500만 정도
>
> 



### 코드

```c++
//! 2020.02.20
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
	for (int i = 0; i < 3; i++) {
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
			int player = orderP[cur % 10];
			if (inData[t][player] == 0) cnt++;
			else movePlayer(inData[t][player]);
			cur++;
		}
        printf("cur : %d\n",cur);
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
	orderP[3] = 1;
	printf("%d\n", getResult(0));
	return 0;
}
```

