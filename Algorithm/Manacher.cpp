//#define Manacher
#ifdef Manacher
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 100001

using namespace std;

int p[MAXN]; // �Ӹ������ �ݰ�
char o[MAXN]; // ���ڿ�
int main() {
	int i;
	int n; // ���ڿ��� ����
	int r, c; // �� ���� ��ġ, �߰��� ��ġ
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
		if (r >= i) p[i] = min(r - i, p[c * 2 - i]); // ���� ���� �־��ش�.
		else p[i] = 0;

		while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && o[i + p[i] + 1] == o[i - p[i] - 1]) p[i]++; // ������ ����
		if (i + p[i] > r) { // �������� �Ѿ�� �׶����� ����
			r = i + p[i];
			c = i;
		}
	}

	for (i = 0; i < n; i++) printf("%d ", p[i]);
	return 0;
}
#endif