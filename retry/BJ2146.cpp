
//! 20200204
// TODO BJ2146 : https://www.acmicpc.net/problem/2146

#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

const int MAX = 105;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
int inMap[MAX][MAX];
bool checkMap[MAX][MAX];
int N;
int minResult = 987654321;
vector <queue <pair<int,int>>> myQ;
queue <pair<int,int>> bfsQ;
queue <pair<int,int>> tmp;

bool inRange(int y,int x){
    if(y<N && y>=0 && x>=0 && x<N) return true;
    else return false;
}

int BFS2(int idx){
    tmp.swap(myQ[idx]);
    // printf("Qsize : %d\n",tmp.size());

    int depth = 0;
    while(!tmp.empty()){
        depth++;
        int sizeQ = tmp.size();
        for(int i=0;i<sizeQ;i++){
            pair <int,int> current;
            current = tmp.front();
            tmp.pop();

            for(int dir=0;dir<4;dir++){
                int nextX = current.second + dx[dir];
                int nextY = current.first + dy[dir];
                if(!inRange(nextY,nextX)) continue;

                if(!checkMap[nextY][nextX]){
                    checkMap[nextY][nextX] = true;
                    tmp.push(make_pair(nextY,nextX));
                }else{
                    if(inMap[nextY][nextX]!=idx+2 && inMap[nextY][nextX]!=0){
                        queue <pair<int,int>> empty;
                        tmp.swap(empty);
                        return depth-1;
                    }
                }
            }
        }
    }
    queue <pair<int,int>> empty;
    tmp.swap(empty);
    return depth-1;
}

void BFS(int num){
    while(!bfsQ.empty()){
        int sizeQ = bfsQ.size();
        for(int i=0;i<sizeQ;i++){
            pair <int,int> current;
            current = bfsQ.front();
            bfsQ.pop();
            tmp.push(current);
            inMap[current.first][current.second] = num;
            for(int dir=0;dir<4;dir++){
                int nextX = current.second + dx[dir];
                int nextY = current.first + dy[dir];
                if(!inRange(nextY,nextX)) continue;
                if(!checkMap[nextY][nextX]){
                    if(inMap[nextY][nextX]==1){
                        checkMap[nextY][nextX] = true;
                        bfsQ.push(make_pair(nextY,nextX));
                    }
                }
            }
        }
    }
    myQ.push_back(tmp);
    queue <pair<int,int>> empty;
    tmp.swap(empty);
}

void getResult(){
    // indexing BFS
    int number = 1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!checkMap[i][j]){
                if(inMap[i][j]==1){
                    number++;
                    bfsQ.push(make_pair(i,j));
                    checkMap[i][j] = true;
                    BFS(number);
                }
            }
        }
    }

    for(int i=0;i<myQ.size();i++){
        int tmp = BFS2(i);
        if(tmp<minResult) minResult = tmp;
        // printf("tmp : %d minResult : %d\n",tmp,minResult);
        for(int r=0;r<N;r++){
            for(int c=0;c<N;c++){
                if(inMap[r][c]==0) checkMap[r][c] = false;
            }
        }
    }
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&inMap[i][j]);
        }
    }

    getResult();
    printf("%d\n",minResult);
    
    return 0;
}