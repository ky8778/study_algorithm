//! 2020.03.12
// TODO BJ1932_정수삼각형.cpp
#include<cstdio>
using namespace std;

const int MAX = 505;
int N;
int myMap[MAX][MAX];
int DP[MAX][MAX];

int getMax(int n1,int n2){
    if(n1>n2) return n1;
    else return n2;
}

int getResult(int y,int x){
    if(y>=N) return 0;
    int& ret = DP[y][x];
    if(ret!=-1) return ret;

    ret = myMap[y][x];
    ret += getMax(getResult(y+1,x),getResult(y+1,x+1));

    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<i+1;j++){
            scanf("%d",&myMap[i][j]);
            DP[i][j] = -1;
        }
    }
    printf("%d\n",getResult(0,0));
    return 0;
}
