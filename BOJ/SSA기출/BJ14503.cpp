// 2019.10.15
#include<cstdio>

using namespace std;

const int MAX = 55;
int N,M,r,c,D;
int map[MAX][MAX];
bool check[MAX][MAX];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

int getResult(int y,int x,int direction,int num){
    for(int d=1;d<=4;d++){
        int go = direction-d;
        if(go<0) go += 4;
        int yy = y+dy[go];
        int xx = x+dx[go];
        if(check[yy][xx]==false && map[yy][xx]==0){
            check[yy][xx] = true;
            return getResult(yy,xx,go,num+1);
        }
    }
    
    int go = (direction+2)%4;
    int yy = y+dy[go];
    int xx = x+dx[go];
    if(map[yy][xx]==1) return num;
    else return getResult(yy,xx,direction,num);
}

int main(){
    scanf("%d %d",&N,&M);
    scanf("%d %d %d",&r,&c,&D);
    for(int i=0;i<N+2;i++){
        for(int j=0;j<M+2;j++){
            if(i==0||j==0||i==N+1||j==M+1) map[i][j] = 1;
            else scanf("%d",&map[i][j]);
        }
    }
    
    check[r+1][c+1] = true;
    printf("%d\n",getResult(r+1,c+1,D,1));
    return 0;
}