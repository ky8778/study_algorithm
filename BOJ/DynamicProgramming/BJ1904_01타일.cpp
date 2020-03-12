//! 2020.03.12
// TODO BJ1904_01타일
#include<cstdio>
using namespace std;

const int MOD = 15746;
const int MAX = 1000050;
int DP[MAX];
int N;

int getResult(int n){
    int& ret = DP[n];
    if(ret!=-1) return ret;
    return ret = (getResult(n-1)+getResult(n-2))%MOD;
}

void initDP(){
    for(int i=0;i<=N;i++) DP[i] = -1;
    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 2;
}

int main(){
    scanf("%d",&N);
    initDP();
    printf("%d\n",getResult(N));
    return 0;
}