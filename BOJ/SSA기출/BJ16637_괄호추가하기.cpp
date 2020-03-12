//! 2020.02.19
// TODO BJ16637_괄호추가하기
#include<cstdio>
#include<vector>
using namespace std;

const int MAX = 20;
int N;
char inData[MAX];
bool check[MAX];
// + : 1, - : 2, * : 3, / :4
vector <int> numbers;
vector <char> calcs;

void changeArr() {
	for (int i = 0; i < N; i++) {
		if (i & 1) calcs.push_back(inData[i]);
		else numbers.push_back(inData[i] - '0');
	}
}

int calculate(char c,int n1,int n2) {
	//printf("c : %c, n1 : %d, n2 : %d\n",c, n1, n2);
	switch (c) {
	case '+':
		return n1 + n2;
	case '-':
		return n1 - n2;
	case '*':
		return n1 * n2;
	case '/':
		return n1 / n2;
	}
}

int getCalcRet() {
	int sum = numbers[0];
	for (int i = 1; i < numbers.size(); i++) {
		int next = numbers[i];
		if (check[i]) {
			next = calculate(calcs[i], next, numbers[i + 1]);
			sum = calculate(calcs[i - 1], sum, next);
			i++;
		}
		else {
			sum = calculate(calcs[i - 1], sum, next);
		}
	}
	//printf("sum : %d\n", sum);
	return sum;
}

int getResult(int idx) {
	if (idx >= N / 2) {
		return getCalcRet();
	}
	else {
		int maxRet = -987654321;
		int tmpRet = getResult(idx + 1);
		if (tmpRet > maxRet) maxRet = tmpRet;
		check[idx] = true;
		tmpRet = getResult(idx + 2);
		if (tmpRet > maxRet) maxRet = tmpRet;
		check[idx] = false;
		return maxRet;
	}
}

int main() {
	scanf("%d", &N);
	scanf("%s", inData);
	changeArr();
	printf("%d\n",getResult(0));
	return 0;
}