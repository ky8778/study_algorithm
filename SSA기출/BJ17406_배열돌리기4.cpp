//! 2020.02.16
// TODO BJ17406_배열돌리기4
#include<cstdio>
#include<vector>

using namespace std;

const int MAX = 55;
int N,M,K;
int inMap[MAX][MAX];
int nextMap[MAX][MAX];
int rotateOrder[10];                // 0 ~ K-1 : rotate order
bool checkRotate[10];               // 0 ~ k-1 : idx-th rotate number
vector <pair<int,int>> rotateInfo;  // 0 ~ K-1 : rotate center point
vector <int> rotateSize;            // 0 ~ K-1 : rotate box size\

int getMin(){
    int minRet = 987654321;
    for(int i=0;i<N;i++){
        int tmpSum = 0;
        for(int j=0;j<M;j++){
            tmpSum += nextMap[i][j];
            nextMap[i][j] = inMap[i][j];
        }
        if(minRet>tmpSum) minRet = tmpSum;
    }
    return minRet;
}

int simulate(){
    for(int k=0;k<K;k++){
        int idx = rotateOrder[k];
        int r = rotateInfo[idx].first;
        int c = rotateInfo[idx].second;
        int s = rotateSize[idx];
        
        int tmpMap[MAX][MAX];
        for(int i=-s;i<=s;i++){
            for(int j=-s;j<=s;j++){
                tmpMap[i+s][j+s] = nextMap[r+i][c+j];
            }
        }
        for(int ss=1;ss<=s;ss++){
            for(int j=c-ss+1;j<=c+ss;j++){
                nextMap[r-ss][j] = tmpMap[s-ss][j-c+s-1];
                nextMap[r+ss][j-1] = tmpMap[s+ss][j-c+s];
            }
            for(int i=r-ss;i<=r+ss-1;i++){
                nextMap[i][c-ss] = tmpMap[i-r+s+1][s-ss];
                nextMap[i+1][c+ss] = tmpMap[i-r+s][s+ss];
            }
        }
    }
    return getMin();
}

int getResult(int idx){
    if(idx>=K){
        return simulate();
    }else{
        int minResult = 987654321;
        for(int i=0;i<K;i++){
            if(!checkRotate[i]){
                checkRotate[i] = true;
                rotateOrder[idx] = i;
                int tmpResult = getResult(idx+1);
                checkRotate[i] = false;
                if(minResult>tmpResult) minResult = tmpResult;
            }
        }
        return minResult;
    }
}

int main(){
    scanf("%d %d %d",&N,&M,&K);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d",&inMap[i][j]);
            nextMap[i][j] = inMap[i][j];
        }
    }
    for(int i=0;i<K;i++){
        int r,c,s;
        scanf("%d %d %d",&r,&c,&s);
        rotateInfo.push_back(make_pair(r-1,c-1));
        rotateSize.push_back(s);
    }

    printf("%d\n",getResult(0));
    return 0;
}