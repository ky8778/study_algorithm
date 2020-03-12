// 2019.10.11
#include<cstdio>

using namespace std;

const int MAX = 105;
long long DP[MAX][10];
int N;

long long getDP(int x){
    if(x==1){
        for(int i=1;i<=9;i++) DP[x][i] = 1;
        return 9;
    }
    getDP(x-1);
    DP[x][0] = DP[x-1][1]%1000000000;
    DP[x][9] = DP[x-1][8]%1000000000;
    long long result = (DP[x][0]+DP[x][9])%1000000000;
    for(int i=1;i<=8;i++){
        DP[x][i] = (DP[x-1][i-1] + DP[x-1][i+1])%1000000000;
        result = (result + DP[x][i])%1000000000;
    }
    return result;
}

int main(){
    scanf("%d",&N);
    printf("%lld\n",getDP(N));
    return 0;
}