// 2019.10.11
#include<cstdio>

using namespace std;

const int MAX = 1050;
int N;
int A[MAX];
int DP[MAX];

void getDP(int x){
    if(x==1){
        DP[x] = 1;
        return;
    }
    getDP(x-1);
    int max = -1;

    for(int i=1;i<x;i++){
        if(A[i]<A[x]){
            if(max<DP[i]+1) max = DP[i]+1;
        }
    }
    if(max<0) max = 1;
    DP[x] = max;
}

int main(){
    scanf("%d",&N);
    for(int n=1;n<=N;n++) scanf("%d",&A[n]);
    getDP(N);
    int result = -1;
    for(int n=1;n<=N;n++){
        if(DP[n]>result) result = DP[n];
    }
    printf("%d\n",result);
    return 0;
}