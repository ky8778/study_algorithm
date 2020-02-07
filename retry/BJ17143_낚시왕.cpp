
//! 2020.02.07
// TODO BJ17143_낚시왕
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

const int MAX = 105;
const int dx[4] = {0,0,1,-1};
const int dy[4] = {-1,1,0,0};
const int changeDir[4] = {1,0,3,2};
int R,C,M;
int inMap[2][MAX][MAX][3];          // 0: odd==false, 1: odd==true
                                    // 0: size 1: dir 2: speed
int isOdd;
vector <pair<int,int>> sharks;

void print(){
    
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            printf("%d ",inMap[(isOdd+1)&1][i][j][0]);
        }
        printf("\n");
    }
}

int catching(int col){
    for(int i=0;i<R;i++){
        int size = inMap[isOdd][i][col][0];
        if(size!=0){
            inMap[isOdd][i][col][0] = 0;
            inMap[isOdd][i][col][1] = 0;
            inMap[isOdd][i][col][2] = 0;
            for(int s=0;s<sharks.size()-1;s++){
                if(sharks[s].first==i&&sharks[s].second==col){
                    pair <int,int> tmp = sharks[s];
                    sharks[s] = sharks[s+1];
                    sharks[s+1] = tmp;
                }
            }
            sharks.pop_back();
            return size;
        }
    }
    return 0;
}

void moving(){
    int next = (isOdd+1)&1;
    vector <pair<int,int>> newShark;
    for(int s=0;s<sharks.size();s++){
        int y = sharks[s].first;
        int x = sharks[s].second;
        int size = inMap[isOdd][y][x][0];
        int dir = inMap[isOdd][y][x][1];
        int speed = inMap[isOdd][y][x][2];
        inMap[isOdd][y][x][0] = 0;
        inMap[isOdd][y][x][1] = 0;
        inMap[isOdd][y][x][2] = 0;

        y += (dy[dir]*speed);
        x += (dx[dir]*speed);
        while(x<0 || y<0 || x>=C || y>=R){
            if(x<0){
                x = -x;
                dir = changeDir[dir];
            }
            else if(x>=C){
                x = 2*(C-1)-x;
                dir = changeDir[dir];
            }
            if(y<0){
                y = -y;
                dir = changeDir[dir];
            }
            else if(y>=R){
                y = 2*(R-1)-y;
                dir = changeDir[dir];
            }
        }
        if(inMap[next][y][x][0]==0){
            inMap[next][y][x][0] = size;
            inMap[next][y][x][1] = dir;
            inMap[next][y][x][2] = speed;
        }else{
            if(inMap[next][y][x][0]>size) continue;
            else{
                inMap[next][y][x][0] = size;
                inMap[next][y][x][1] = dir;
                inMap[next][y][x][2] = speed;
                for(int s=0;s<newShark.size()-1;s++){
                    if(newShark[s].first==y&&newShark[s].second==x){
                        pair <int,int> tmp = newShark[s];
                        newShark[s] = newShark[s+1];
                        newShark[s+1] = tmp;
                    }
                }
                newShark.pop_back();
            }
        }
        newShark.push_back(make_pair(y,x));
    }
    newShark.swap(sharks);
}

int getResult(){
    int sum = 0;
    // print();
    for(int t=0;t<C;t++){
        isOdd = (t&1);
        sum += catching(t);
        moving();
        // print();
        // printf("%d\n",sum);
    }
    return sum;
}

int main(){
    scanf("%d %d %d",&R,&C,&M);
    for(int m=0;m<M;m++){
        int r,c,s,d,z;
        scanf("%d %d %d %d %d",&r,&c,&s,&d,&z);
        inMap[0][r-1][c-1][0] = z;
        inMap[0][r-1][c-1][1] = d-1;
        inMap[0][r-1][c-1][2] = s;
        
        sharks.push_back(make_pair(r-1,c-1));
    }
    printf("%d\n",getResult());
    return 0;
}