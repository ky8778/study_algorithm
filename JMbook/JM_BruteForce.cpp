//! 20200125 BruteForce
#include<cstdio>
#include<vector>
#include<string>

using namespace std;

// TODO 조합
// TODO (0 ~ n-1) n개의 원소 중 m개를 고르는 모든 조합을 찾는 알고리즘
/*
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        for(int k=j+1;k<n;k++){
            for(int l=k+1;l<n;l++){
                printf("%d %d %d %d\n", i, j, k,l);
            }
        }
    }
}

// vector<int>& : 참조로 변수를 넘겨받는 것. 수정 할 수 있음. c++ 문법
// c 에서는 포인터로 받고 넘길 땐 주소값을 넘김.
void pick(int n,vector<int>& picked,int toPick){
    if(toPick==0){
        return;
    }

    int smallest = picked.empty() ? 0 : picked.back()+1;
    for(int next = smallest;next<n;next++){
        picked.push_back(next);
        pick(n,picked,toPick-1);
        picked.pop_back();
    }
}
*/

// TODO 보글 게임판에서 단어를 찾는 재귀 호출 알고리즘
/*
const int MAX = 100;
const int dx[8] = {-1,-1,-1,1,1,1,0,0};
const int dy[8] = {-1,0,1,-1,0,1,-1,1};
int map[MAX][MAX];
int N;

bool inRange(int y, int x){
    if(y<0 || y>=N||x<0||x>=N) return false;
    else return true;
}

// 5x5 보글 게임 판의 해당 위치에서 주어진 단어가 시작하는지를 반환
bool hasWord(int y, int x, const string& word){
    // 기저사례1: 시작 위치가 범위 밖이면 무조건 실패
    if(!inRange(y,x)) return false;
    // 기저사례2 : 첫 글자가 일치하지 않으면 실패
    if(map[y][x]!=word[0]) return false;
    // 기저사례3 : 단어 길이가 1이면 성공
    if(word.size()==1) return true;
    // 인접한 여덟 칸을 검사한다.
    for(int dir = 0;dir<8;dir++){
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];
        // 다음 칸이 범위 안에 있는지, 첫 글자는 일치하는지 확인할 필요가 없다.
        if(hasWord(nextY,nextX,word.substr(1))) return true;
    }

    return false;
}
*/

//! 20200127 BruteForce
// TODO 순열
// TODO 6.7 Optimization Problems
const int MAX = 100;
const int INF = 987987987;
int n;  // number of cities
double dist[MAX][MAX]; // distance of two cities
// path : 지금까지 만든 경로
// visited : 도시 방문 여부
// currentLength : 지금까지 만든 경로의 길이
// 나머지 도시들을 모두 방문하는 경로들 중 가장 짧은 것의 길이를 반환한다.
double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength){
    // 기저 사례 : 모든 도시를 다 방문했을 때는 시작 도시로 돌아가고 종료한다.
    if(path.size()==n){
        return currentLength+dist[path[0]][path.back()];
    }
    double ret = INF;   // 매우 큰 값으로 초기화.
    // 다음 방문할 도시를 전부 시도해 본다.
    for(int next = 0;next<n;next++){
        if(visited[next]) continue;
        int here = path.back();
        path.push_back(next);
        visited[next] = true;
        // 나머지 경로를 재귀 호출을 통해 완성하고 가장 짧은 경로의 길이를 얻는다.
        double cand = shortestPath(path,visited,currentLength+dist[here][next]);
        ret = min(ret, cand);
        visited[next] = false;
        path.pop_back();
    }
    return ret;
}
