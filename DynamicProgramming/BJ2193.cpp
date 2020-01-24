// 2019.10.11
#include <cstdio>

using namespace std;

const int MAX = 100;
int N;
long long DP[MAX][2];

long long getDP(int x){
    if(x==1){
        DP[x][0] = 0;
        DP[x][1] = 1;
        return 1;
    }
    getDP(x-1);
    DP[x][0] = DP[x-1][0] + DP[x-1][1];
    DP[x][1] = DP[x-1][0];
    return DP[x][0] + DP[x][1];
}

int main(){
    scanf("%d",&N);
    printf("%lld\n",getDP(N));
    return 0;
}