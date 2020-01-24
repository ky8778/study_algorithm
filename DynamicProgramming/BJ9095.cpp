// 2019.10.11
#include <cstdio>

using namespace std;

const int MAX = 15;
int DP[MAX];
int T,N;

int getDP(int x){
    if(x==1) return 1;
    if(x==2) return 2;
    if(x==3) return 4;
    return DP[x] = getDP(x-1)+getDP(x-2)+getDP(x-3);
}

int main(){
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&N);
        printf("%d\n",getDP(N));
    }
    return 0;
}