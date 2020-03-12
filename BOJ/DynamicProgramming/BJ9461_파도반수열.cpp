//! 2020.03.12
// TODO BJ9461_파도반수열
#include<cstdio>
using namespace std;

const int MAX = 105;
long long DP[MAX];
long long P[MAX][6];
int N,T;

int findMax(int n){
    int idx = -1;
    long long maxVal = -1;
    for(int i=0;i<6;i++){
        if(P[n][i]>maxVal){
            idx = i;
            maxVal = P[n][i];
        }
    }
    return idx;
}

long long getResult(int n){
    long long& ret = DP[n];
    if(ret!=-1) return ret;

    if(DP[n-1]==-1){
        getResult(n-1);
    }

    int nextSide = findMax(n-1);
    ret = P[n-1][nextSide];

    for(int i=0;i<6;i++)
        P[n][i] = P[n-1][i];

    int idx1 = (nextSide+1)%6;
    int idx2 = (nextSide+5)%6;

    P[n][idx1] += ret;
    P[n][idx2] += ret;
    P[n][nextSide] = 0;

    // printf("N : %d\n",n);
    // for(int i=0;i<6;i++) printf("%d ",P[n][i]);
    // printf("\n");

    return ret;
}

int main(){
    scanf("%d",&T);
    for(int i=0;i<MAX;i++) DP[i] = -1;
    DP[0] = 0;
    DP[1] = 1;
    for(int i=1;i<=5;i+=2) P[1][i] = 1;

    for(int t=0;t<T;t++){
        scanf("%d",&N);
        printf("%lld\n",getResult(N));
    }
    return 0;
}
