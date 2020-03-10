//! 2020.03.10
// TODO AS_ASYMTILING
#include<cstdio>
using namespace std;
const int MOD = 1000000007;
const int MAX = 105;
int T,N;
int DP1[MAX];
int DP2[MAX];

int getDP1(int n){
    int& ret = DP1[n];
    if(ret!=-1) return ret;
    return ret = (getDP1(n-1)+getDP1(n-2))%MOD;
}

int getDP2(int n){
    int& ret = DP2[n];
    if(ret!=-1) return ret;
    if(n&1) return ret = getDP1(n/2)%MOD;                   // odd
    else return ret = (getDP1(n/2-1)+getDP1(n/2))%MOD;
}

void initDP(){
    for(int i=0;i<MAX;i++){
        DP1[i] = -1;
        DP2[i] = -1;
    }
    DP1[0] = 0;
    DP1[1] = 1;
    DP1[2] = 2;
    
    DP2[0] = 0;
    DP2[1] = 0;
    DP2[2] = 2;
    DP2[3] = 1;
    DP2[4] = 3;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    initDP();
    for(int t=0;t<T;t++){
        scanf("%d",&N);
        int result = getDP1(N)-getDP2(N);
        if(result<0) result += MOD;
        printf("%d\n",result);
    }
    return 0;
}