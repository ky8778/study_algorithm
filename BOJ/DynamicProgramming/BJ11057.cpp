// 2019.10.11
#include <cstdio>

using namespace std;

const int MAX = 1005;
int DP[MAX][10];
int N;

int getDP(int x){
    if(x==1){
        for(int i=0;i<10;i++) DP[x][i] = 1;
        return 10;
    }
    getDP(x-1);
    int result = 0;
    for(int i=0;i<10;i++){
        for(int j=i;j>=0;j--){
            DP[x][i]+=(DP[x-1][j]%10007);
        }
        result = (result + DP[x][i])%10007;
    }
    return result;
}

int main(){
    scanf("%d",&N);
    printf("%d\n",getDP(N));
    return 0;
}