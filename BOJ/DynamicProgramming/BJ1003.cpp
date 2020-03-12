
//! 20200128
// TODO Dynamic Programming
// BJ1003 : https://www.acmicpc.net/problem/1003
#include<cstdio>
using namespace std;
const int MAX = 50;
int DP[MAX][2];
int T,N;
bool check[MAX];

int getResult(int inputNum,int idx){
    if(DP[inputNum][idx]!=0) return DP[inputNum][idx];
    else{
        if(inputNum==0){
            if(idx==0) return DP[inputNum][0] = 1;
            else return DP[inputNum][1] = 0;
        }
        else if(inputNum==1){
            if(idx==0) return DP[inputNum][0] = 0;
            else return DP[inputNum][1] = 1;
        }else{
            return DP[inputNum][idx] = getResult(inputNum-1,idx)+getResult(inputNum-2,idx);
        }
    }
}

int main(){
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        scanf("%d",&N);
        printf("%d %d\n",getResult(N,0),getResult(N,1));
    }
    return 0;
}