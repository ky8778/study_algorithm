
//! 20200126,27 BruteForce
// TODO BruteForce
// AS_BOARDCOVER : https://www.algospot.com/judge/problem/read/BOARDCOVER

#include<cstdio>
#include<vector>
using namespace std;

const int MAX = 55;
const int nextIdx[4][2][2] = {
    {{0,1},{1,0}},
    {{0,1},{1,1}},
    {{1,0},{1,-1}},
    {{1,0},{1,1}}
};

int map[MAX][MAX];
int C,H,W;

bool inRange(int y, int x){
    if(y>=0&&x>=0&&y<H&&x<W) return true;
    return false;
}

bool checkMap(int y,int x,int type){
    bool ok = true;
    for(int i=0;i<2;i++){
        int xx = x+nextIdx[type][i][1];
        int yy = y+nextIdx[type][i][0];
        if(!inRange(yy,xx)) ok = false;
        else if(map[yy][xx]==1) ok = false;
    }            
    return ok;
}

int getResult(int startY,int startX){
    int nextY = -1;
    int nextX = -1;

    for(int y=0;y<H;y++){
        for(int x=0;x<W;x++){
            if(map[y][x]==0){
                nextY = y;
                nextX = x;
                break;
            }
        }
        if(nextY!=-1) break;
    }
    
    if(nextY==-1){
        return 1;
    }else{
        // printf("nextY : %d, nextX : %d\n",nextY,nextX);
        int result = 0;
        map[nextY][nextX] = 1;
        for(int type=0;type<4;type++){
            if(checkMap(nextY,nextX,type)){
                // 채우기 + 비우기
                for(int i=0;i<2;i++){
                    int xx = nextX + nextIdx[type][i][1];
                    int yy = nextY + nextIdx[type][i][0];
                    map[yy][xx] = 1;
                }
                result += getResult(nextY,nextX);

                for(int i=0;i<2;i++){
                    int xx = nextX + nextIdx[type][i][1];
                    int yy = nextY + nextIdx[type][i][0];
                    map[yy][xx] = 0;
                }
            }
        }
        map[nextY][nextX] = 0;
        return result;
    }
}

int main(){
    scanf("%d",&C);
    for(int c=0;c<C;c++){
        scanf("%d %d",&H,&W);
        for(int h=0;h<H;h++){
            char tmp[MAX];
            scanf("%s",tmp);
            for(int w=0;w<W;w++){
                if(tmp[w]=='#') map[h][w] = 1;
                else map[h][w] = 0;
            }
        }

        printf("%d\n",getResult(0,0));
        for(int h=0;h<H;h++){
            for(int w=0;w<W;w++){
                // printf("%d ",map[h][w]);
                map[h][w] = 0;
            }
            // printf("\n");
        }
    }
    return 0;
}