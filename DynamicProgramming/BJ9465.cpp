// 2019.10.11
#include<cstdio>

using namespace std;

const int MAX = 100050;
int DP[3][MAX];
int map[2][MAX];
int T,N;

int getMAX(int a,int b,int c){
    if(a>b){
        if(a>c) return a;
        else return c;
    }else{
        if(b>c) return b;
        else return c;
    }
}

int getDP(int x){
    if(x==1){
        DP[0][x] = map[0][x];
        DP[1][x] = map[1][x];
        return DP[0][x]>DP[1][x]?DP[0][x]:DP[1][x];
    }
    getDP(x-1);
    int first = DP[0][x-1];
    int second = DP[1][x-1];
    int third = DP[2][x-1];
    DP[0][x] = (second+map[0][x]>third+map[0][x]?second+map[0][x]:third+map[0][x]);
    DP[1][x] = (first+map[1][x]>third+map[1][x]?first+map[1][x]:third+map[1][x]);
    DP[2][x] = getMAX(first,second,third);
    return getMAX(DP[0][x],DP[1][x],DP[2][x]);
}

int main(){
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&N);
        for(int i=0;i<2;i++){
            for(int n=1;n<=N;n++){
                scanf("%d",&map[i][n]);
            }
        }
        printf("%d\n",getDP(N));
    }
    return 0;
}