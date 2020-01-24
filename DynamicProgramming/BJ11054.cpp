// 2019.10.11
#include<cstdio>

using namespace std;

const int MAX = 1050;
int N;
int A[MAX];
int DP[MAX][2];

int getDP(int x,int up_down){       //up_down = 0 : up 1 : down
    int max = -1;
    
    if(up_down==0){
        if(x==1) return DP[x][0] = 1;    
        if(DP[x][0]!=0) return DP[x][0];

        for(int i=1;i<x;i++){
            if(A[i]<A[x]) max = (max < getDP(i,0) ? getDP(i,0) : max);
        }

    }else{
        if(x==N) return DP[x][1] = 1;
        if(DP[x][1]!=0) return DP[x][1];

        for(int i=N;i>x;i--){
            if(A[i]<A[x]) max = (max < getDP(i,1) ? getDP(i,1) : max);
        }
    }
    //printf("max : %d ",max);
    return DP[x][up_down] = (max < 0 ? 1 : max+1);
}

int main(){
    scanf("%d",&N);
    for(int n=1;n<=N;n++) scanf("%d",&A[n]);
    int result = -1;
    for(int n=1;n<=N;n++) {
        //printf("n : %d, DP1 : %d, DP2 : %d\n",n,getDP(n,0),getDP(n,1));
        int tmp = getDP(n,0) + getDP(n,1) - 1;
        result = (result < tmp ? tmp : result);
    }
    printf("%d\n",result);
    
    return 0;
}