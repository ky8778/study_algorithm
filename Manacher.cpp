//#define Manacher
#ifdef Manacher
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 100001

using namespace std;

int p[MAXN]; // 팰린드롬의 반경
char o[MAXN]; // 문자열
int main() {
	int i;
	int n; // 문자열의 길이
	int r, c; // 맨 끝의 위치, 중간의 위치
	r = c = -1;
	scanf("%s", o);
	n = strlen(o);


	// even palindrome
	for (i = n - 1; i >= 0; i--) {
		o[(i << 1) + 1] = o[i];
		o[i << 1] = '#';
	}
	n <<= 1;
	o[n++] = '#';


	for (i = 0; i < n; i++) {
		if (r >= i) p[i] = min(r - i, p[c * 2 - i]); // 작은 쪽을 넣어준다.
		else p[i] = 0;

		while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && o[i + p[i] + 1] == o[i - p[i] - 1]) p[i]++; // 같으면 증가
		if (i + p[i] > r) { // 끝지점을 넘어서면 그때마다 갱신
			r = i + p[i];
			c = i;
		}
	}

	for (i = 0; i < n; i++) printf("%d ", p[i]);
	return 0;
}
#endif