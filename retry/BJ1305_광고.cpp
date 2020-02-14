//! 2020.02.14
// TODO BJ1305_±¤°í
#include <cstdio>
#include <vector>
#include<deque>

using namespace std;

const int MAX = 1000005;
int L;
deque <char> inStr;
vector <int> myPi;

void getPi() {
	int j = 0;
	vector<int> pi(L, 0);
	for (int i = 1; i < L; i++) {
		while (j > 0 && inStr[i] != inStr[j])
			j = pi[j - 1];
		if (inStr[i] == inStr[j])
			pi[i] = ++j;
	}
	myPi.swap(pi);
}

int getResult() {
	getPi();
	int result = 0;
	printf("L : %d, A : %d\n", L, myPi[L - 1]);
	for (int i = 0; i < myPi[L - 1]; i++) {
		inStr.pop_back();
		//printf("%d\n",myPi[0]);
	}
	L = inStr.size();
	getPi();
	printf("L : %d, A : %d\n", L, myPi[L - 1]);
	while (L > 1 && (myPi[L - 1] == (L / 2))) {
		result += (myPi[L - 1]*2);
		for (int i = 0; i < myPi[L - 1]; i++) {
			inStr.pop_back();
			inStr.pop_front();
		}
		L = inStr.size();
		getPi();
		printf("L : %d\n", L);
	}
	result += L;
	return result;
}

int main() {
	scanf("%d", &L);
	char input[MAX];
	scanf("%s", input);
	for (int i = 0; i < L; i++) {
		inStr.push_back(input[i]);
	}
	printf("%d\n", getResult());
	return 0;
}