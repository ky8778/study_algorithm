// 2019.10.11
#include <cstdio>

using namespace std;

const int MAX = 1005;
int DP[1005];
int P[MAX];
int N;

int getDP(int x){
    if(x==1) return P[1];
    if(DP[x]!=0) return DP[x];
    int price = P[x];
    for(int i=1;i<x;i++){
        if(price < getDP(i)+P[x-i]) price = getDP(i)+P[x-i];
        //printf("%d ",price);
    }
    return DP[x] = price;
}

int main(){
    scanf("%d",&N);
    for(int n=0;n<N;n++){
        scanf("%d",&P[n+1]);
    }
    printf("%d\n",getDP(N));
    return 0;
}