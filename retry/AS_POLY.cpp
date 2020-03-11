//! 2020.03.11
// TODO AS_POLY
#include<cstdio>
using namespace std;
const int MAX = 105;
const int MOD = 10000000;
int N,T;
int DP[MAX][MAX];

int getResult(int prev,int num){
    if(num<=0) return 1;
    int& ret = DP[prev][num];
    if(ret!=-1) return ret;
    ret = 0;
    for(int cur=1;cur<=num;cur++){
        int mul = (prev == 0 ? 1 : (prev+cur-1));
        ret += (mul*getResult(cur,num-cur)%MOD);
    }
    return ret%=MOD;
}

void initDP(){
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            DP[i][j] = -1;
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        scanf("%d",&N);
        initDP();
        printf("%d\n",getResult(0,N));
    }
    return 0;
}