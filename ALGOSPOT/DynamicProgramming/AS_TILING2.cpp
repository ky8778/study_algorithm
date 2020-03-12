//! 2020.03.07
// TODO AS_TILING2
#include<cstdio>
using namespace std;

const int MOD = 1000000007;
const int MAX = 105;
int N,T;
int DP[MAX];

int getResult(int inN){
    if(inN<=1) return 1;
    int& ret = DP[inN];
    if(ret!=-1) return ret;
    return ret = (getResult(inN-1)+getResult(inN-2))%MOD;
}

int main(){
    scanf("%d",&T);
    for(int i=0;i<MAX;i++) DP[i] = -1;
    for(int t=0;t<T;t++){
        scanf("%d",&N);
        printf("%d\n",getResult(N));
    }
    return 0;
}