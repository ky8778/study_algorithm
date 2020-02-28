//! 2020.02.28
// TODO SWEA1486_장훈이의높은선반
#include<cstdio>
using namespace std;
const int MAX = 25;
const int INF = 987654321;
int T,N,B,S;
int H[MAX];
int myH[MAX];
int setSize;

int getSum(int number){
    int ret = 0;
    for(int i=0;i<number;i++){
        ret += myH[i];
    }
    printf("ret : %d\n",ret);
    return ret;
}

int min(int n1,int n2){
    if(n1<n2) return n1;
    else return n2;
}

int getResult(int prev,int number){
    if(number>=setSize){
        int tmpSum = getSum(number);
        if(tmpSum>=B) return tmpSum;
        else return INF;
    }else{
        int minSum = INF;
        for(int next = prev+1;next<N;next++){
            myH[number] = H[next];
            minSum = min(minSum,getResult(next,number+1));
            printf("B : %d, next : %d, minSum : %d\n",B,next,minSum);
        }
        return minSum;
    }
}

int main(){
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        scanf("%d %d",&N,&B);
        for(int n=0;n<N;n++){
            scanf("%d",&H[n]);
        }
        int result = INF;
        for(setSize=1;setSize<=N;setSize++){
            result = min(result,getResult(-1,0));
        }
        printf("#%d %d\n",t+1,result-B);
    }
    return 0;
}