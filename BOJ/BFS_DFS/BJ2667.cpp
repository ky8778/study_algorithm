
//! 2020.02.03
// TODO BJ2667
// BFS & DFS

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 30;
int N;
int inMap[MAX][MAX];
bool checkMap[MAX][MAX];
vector <int> ret;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool inRange(int y, int x){
    if(x<N && x>=0 && y<N && y>=0) return true;
    else return false;
}

int DFS(pair<int,int> current,int number){
    int curX = current.second;
    int curY = current.first;
    int cnt = 1;
    inMap[curY][curX] = number;
    for(int i=0;i<4;i++){
        int nextX = curX + dx[i];
        int nextY = curY + dy[i];
        if(inRange(nextY,nextX)){
            if(!checkMap[nextY][nextX] & inMap[nextY][nextX]==1){
                checkMap[nextY][nextX] = true;
                cnt += DFS(make_pair(nextY,nextX),number);
            }
        }
    }
    return cnt;
}

void getResult(){
    int num = 1;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!checkMap[i][j] && inMap[i][j]==1){
                checkMap[i][j] = true;
                ret.push_back(DFS(make_pair(i,j),num));
                num++;
            }
        }
    }
    sort(ret.begin(),ret.end());
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        char tmp[MAX];
        scanf("%s",tmp);
        for(int j=0;j<N;j++){
            inMap[i][j] = tmp[j] - '0';
        }
    }
    
    getResult();
    printf("%d\n",ret.size());
    for(int i=0;i<ret.size();i++){
        printf("%d\n",ret[i]);
    }
    return 0;
}