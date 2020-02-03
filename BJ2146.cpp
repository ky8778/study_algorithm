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

int BFS2(int num){

}

void BFS(int num){
    queue <pair<int,int>> tmp;
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
}

void getResult(){
    // indexing BFS
    int number = 0;
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

    // for(int i=0;i<myQ.size();i++){
    //     int tmp = BFS2(i);
    //     if(tmp<minResult)
    // }
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
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",inMap[i][j]);
        }
        printf("\n");
    }

    // for(int i=0;i<myQ.size();i++){
    //     for(int j=0;j<myQ[i].size();j++){
    //         printf("%d, %d\t",myQ[i].front().first,myQ[i].front().second);
    //     }

    //     printf("\n");
    // }
    
    return 0;
}
