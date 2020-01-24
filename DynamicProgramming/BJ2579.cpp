// 2019.10.11
#include<cstdio>

using namespace std;

const int MAX = 305;
int N;
int num[MAX];
int DP[MAX][2];

int getDP(int x,int index){
    if(index==0){
        if(x==0) return 0;
        if(x==1) return DP[x][index] = num[x];
        if(DP[x][index]!=0) return DP[x][index];
        int first = getDP(x-2,0);
        int second = getDP(x-2,1);
        return DP[x][index] = num[x]+(first>second?first:second);
    }else{
        if(x==0) return 0;
        if(x==1) return 0;
        if(DP[x][index]!=0) return DP[x][index];
        return DP[x][index] = num[x]+getDP(x-1,0);
    }
}

int main(){
    scanf("%d",&N);
    for(int n=1;n<=N;n++) scanf("%d",&num[n]);
    int result1 = getDP(N,0);
    int result2 = getDP(N,1);
    printf("%d\n",result1>result2?result1:result2);
    return 0;
}