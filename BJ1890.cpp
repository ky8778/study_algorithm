#include <stdio.h>
#define MAX 105

char map[MAX][MAX];
long long DP[MAX][MAX];
bool visit[MAX][MAX];
int N;

long long getResult(int y,int x){
    long long result=0;
    if(x>=N||y>=N) return 0;
    if(x == N-1 && y==N-1) return 1;
    if(visit[y][x]==true){
        return DP[y][x];
    }
    visit[y][x] = true;
    
    int dist = map[y][x];
    result+=getResult(y+dist, x);
    result+=getResult(y, x+dist);
    DP[y][x] += result;

    return result;
}

int main(){
    scanf("%d",&N);
    printf("%d",N);
    long long R;
    for(int j=0;j<N;j++){
        for(int i=0;i<N;i++){
            scanf("%c",&map[j][i]);
        }
    }
    
    R = getResult(0,0);
    printf("%lld\n",R);
    return 0;
}