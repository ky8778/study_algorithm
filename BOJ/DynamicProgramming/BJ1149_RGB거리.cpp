//! 2020.03.12
// TODO BJ1149_RGB거리.cpp
#include<cstdio>
using namespace std;

const int MAX = 1050;
const int INF = 987654321;
int N;
int myMap[MAX][3];
int DP[3][MAX];

int getMin(int n1,int n2){
    if(n1<n2) return n1;
    else return n2;
}

int getResult(int prev,int idx){
    if(idx>=N) return 0;

    int& ret = DP[prev][idx];
    if(ret!=-1) return ret;

    ret = INF;
    if(idx==0){
        for(int i=0;i<3;i++){
            ret = getMin(ret,myMap[idx][i]+getResult(i,idx+1));
        }
    }else{
        for(int i=0;i<3;i++){
            if(i!=prev)
                ret = getMin(ret,myMap[idx][i]+getResult(i,idx+1));
        }
    }
    
    // printf("idx : %d, ret : %d\n",idx,ret);
    return ret;
}

int main(){
    scanf("%d",&N);

    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&myMap[i][j]);
            DP[j][i] = -1;
        }
    }

    printf("%d\n",getResult(0,0));

    return 0;
}