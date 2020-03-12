
//! 20200123
// TODO BackTracking
// BJ14889 : https://www.acmicpc.net/problem/14889

#include<cstdio>
#include<vector>

using namespace std;

const int MAX = 25;
int N;
int powerMap[MAX][MAX];
int resultMin;
vector <int> teamStart;
vector <int> teamLink;

int calcScore(){
    int score1 = 0;
    int score2 = 0;
    for(int idx=0;idx<teamStart.size();idx++){
        for(int nextIdx=idx+1;nextIdx<teamStart.size();nextIdx++){
            int P1 = teamStart[idx];
            int P2 = teamStart[nextIdx];
            score1 += powerMap[P1][P2];
            score1 += powerMap[P2][P1];
        }
    }
    for(int idx = 0; idx<teamLink.size();idx++){
        for(int nextIdx=idx+1;nextIdx<teamLink.size();nextIdx++){
            int P1 = teamLink[idx];
            int P2 = teamLink[nextIdx];
            score2+=powerMap[P1][P2];
            score2+=powerMap[P2][P1];
        }
    }
    return score1-score2>0?score1-score2:score2-score1;
}

void getResult(int currentIdx){
    if(currentIdx>=N){
        int resultTmp = calcScore();
        // printf("resultTmp : %d\n",resultTmp);
        if(resultTmp<resultMin) resultMin = resultTmp;
        return;
    }else{
        teamStart.push_back(currentIdx);
        getResult(currentIdx+1);
        teamStart.pop_back();
        teamLink.push_back(currentIdx);
        getResult(currentIdx+1);
        teamLink.pop_back();
    }
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&powerMap[i][j]);
        }
    }

    resultMin = 987987987;
    getResult(0);
    printf("%d",resultMin);

    return 0;
}

