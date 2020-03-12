// 2019.10.11
#include<cstdio>

using namespace std;

const int MAX = 10050;
int N;
int map[MAX];
long long DP[MAX][3];

long long getMAX(long long a,long long b,long long c){
    if(a>=b){
        if(a>=c) return a;
        else return c;
    }else{
        if(b>=c) return b;
        else return c;
    }
}

long long getDP(int x){
    if(x==1) {
        DP[x][0] = 0;
        DP[x][1] = map[1];
        DP[x][2] = map[1];
        return map[1];
    }
    getDP(x-1);
    DP[x][0] = getMAX(DP[x-1][0],DP[x-1][1],DP[x-1][2]);
    DP[x][1] = DP[x-1][0] + map[x];
    DP[x][2] = DP[x-1][1] + map[x];
    //printf("x : %d, %d %d %d\n",x,DP[x][0],DP[x][1],DP[x][2]);
    
    return getMAX(DP[x][0],DP[x][1],DP[x][2]);
}

int main(){
    scanf("%d",&N);
    for(int n=1;n<=N;n++) scanf("%d",&map[n]);
    printf("%lld\n",getDP(N));
    return 0;
}