// 2019.10.18
// 45M
// algorithm : DP
#include<cstdio>

using namespace std;

const int MAX = 20;
int N;
int DP[MAX];
int T[MAX];
int P[MAX];

int getResult(int n){
    if(n>N) return 0;
    if(DP[n]!=0) return DP[n];
    int result1 = 0;
    result1 += getResult(n+1);
    int result2 = 0;
    int endDate = n+T[n]-1;
    if(endDate<=N){
        result2 += P[n];
        result2 += getResult(n+T[n]);
    }
    //printf("n %d result1 : %d result2 : %d\n",n,result1,result2);
    return DP[n] = (result1 > result2 ? result1 : result2);
}

int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d %d",&T[i],&P[i]);
    }
    printf("%d\n",getResult(1));
    //for(int i=1;i<=N;i++) printf("DP : %d\t",DP[i]);
    return 0;
}