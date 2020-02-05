
//! 2020.02.05
// TODO BJ15685 : acmicpc.net/problem/15685
#include<cstdio>
#include<vector>

using namespace std;

const int MAX = 105;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,-1,0,1};
int inMap[MAX][MAX];
vector <int> dirData;
int N;
int endGeneration;

void DFS(int y,int x,int d,int g){
    // y, x : start point
    // d : start direction
    // g : current generation
    if(g>endGeneration){
        vector <int> empty;
        empty.swap(dirData);
        return;
    }
    else if(g==0){
        inMap[y][x] = 1;
        x+=dx[d];
        y+=dy[d];
        dirData.push_back(d);
        inMap[y][x] = 1;
        DFS(y,x,d,g+1);
    }
    else{
        vector <int> tmpDir;
        int sizeV = dirData.size();
        // printf("%d\n",sizeV);
        int dir = 0;
        for(int i=0;i<sizeV;i++){
            tmpDir.push_back(dirData[i]);
        }
        for(int i=0;i<sizeV;i++){
            dir = (dirData.back()+1)%4;
            tmpDir.push_back(dir);
            dirData.pop_back();
            x += dx[dir];
            y += dy[dir];
            inMap[y][x] = 1;
        }
        tmpDir.swap(dirData);
        DFS(y,x,0,g+1);
    }
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int a1,a2,a3,a4;
        scanf("%d %d %d %d",&a1,&a2,&a3,&a4);
        endGeneration = a4;
        DFS(a2,a1,a3,0);
    }
    
    // for(int i=0;i<10;i++){
    //     for(int j=0;j<10;j++){
    //         printf("%d ",inMap[i][j]);
    //     }
    //     printf("\n");
    // }
    int result = 0;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            int sum = inMap[i][j]+inMap[i+1][j]+inMap[i][j+1]+inMap[i+1][j+1];
            if(sum==4) result++;
        }
    }
    printf("%d\n",result);
    return 0;
}