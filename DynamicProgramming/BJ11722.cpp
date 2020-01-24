// 2019.10.11
#include<cstdio>

using namespace std;

const int MAX = 1050;
int N;
int A[MAX];
int DP[MAX];

int getDP(int x){
    if(x==1) return DP[x] = 1;

    if(DP[x]!=0) return DP[x];
    int max = -1;
    for(int i=1;i<x;i++)
        if(A[i]>A[x]) max = (getDP(i) > max ? getDP(i) : max);

    return DP[x] = (max < 0 ? 1 : max + 1);
}

int main(){
    scanf("%d",&N);
    for(int n=1;n<=N;n++) scanf("%d",&A[n]);
    int result = -1;
    for(int n=1;n<=N;n++) result = (getDP(n)>result?getDP(n):result);
    printf("%d\n",result);
    return 0;
}