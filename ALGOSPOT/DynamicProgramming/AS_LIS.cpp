//!2020.02.18
// TODO AS_LIS (Longest Increasing Sequence)
#include<cstdio>
#include<vector>
using namespace std;

const int MAX = 1000050;
vector <int> myV;
int DP[MAX];
int N, C;

int findMax(int number) {
	int maxRet = 0;
	for (int i = 0; i < myV.size(); i++) {
		int idx = myV[i];
		if (idx < number && maxRet < DP[idx]) maxRet = DP[idx];
	}
	return maxRet;
}

int main() {
	scanf("%d", &C);
	for (int c = 0; c < C; c++) {
		scanf("%d", &N);
		
		int result = -1;
		for (int n = 0; n < N; n++) {
			int num = 0;
			scanf("%d", &num);
			if (DP[num] == 0) myV.push_back(num);
			int tmpRet = findMax(num)+1;
			//printf("%d\n", tmpRet);
			if (DP[num] < tmpRet) DP[num] = tmpRet;
			if (result < tmpRet) result = tmpRet;
		}
		printf("%d\n", result);

		for (int i = 0; i < MAX; i++) DP[i] = 0;
	}
	return 0;
}