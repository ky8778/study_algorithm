//! 2020.02.26
// TODO AS_JLIS (Joined Longest Increasing Sequence)
#include<cstdio>
#include<limits>
using namespace std;
const int MAX = 105;
const long long NEGINF = numeric_limits<long long>::min();
int T,N,M;
int A[MAX];
int B[MAX];
int DP[MAX][MAX];

void initDP(){
    for(int n=0;n<=N;n++){
        for(int m=0;m<=M;m++){
            DP[n][m] = -1;
        }
    }
}

long long max(long long n1,long long n2){
    if(n1>n2) return n1;
    else return n2;
}

int getResult(int idxA,int idxB){
    int& ret = DP[idxA+1][idxB+1];
    if(ret!=-1) return ret;
    ret = 2;

    long long valA = (idxA==-1? NEGINF:A[idxA]);
    long long valB = (idxB==-1? NEGINF:B[idxB]);
    long long maxVal = max(valA,valB);

    for(int i=idxA+1;i<N;i++)
        if(maxVal<A[i]) ret = max(ret,1+getResult(i,idxB));
    
    for(int j=idxB+1;j<M;j++)
        if(maxVal<B[j]) ret = max(ret,1+getResult(idxA,j));
    // printf("idx1 : %d, idx2 : %d\n",idxA,idxB);
    // printf("valA : %lld, valB : %lld, maxVal : %lld\n",valA,valB,maxVal);
    // printf("ret : %d\n",ret);
    return ret;
}

int main(){
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        scanf("%d %d",&N,&M);
        for(int n=0;n<N;n++) scanf("%d",&A[n]);
        for(int m=0;m<M;m++) scanf("%d",&B[m]);
        initDP();
        printf("%d\n",getResult(-1,-1)-2);
    }
    return 0;
}

/*
3
3 3
1 2 4
3 4 7
3 3
1 2 3
4 5 6
5 3
10 20 30 1 2
10 20 30
*/