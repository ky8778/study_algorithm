
//! 2020.02.06
// TODO BJ17140_이차원배열과연산.cpp
// URL : https://www.acmicpc.net/problem/17140
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 105;

int inMap[MAX][MAX];
vector <pair<int,int>> infoNum;         // first : 갯수 second : 숫자
vector <int> memo;
int r,c,k;
int number[MAX];
int maxR,maxC;

bool compare(pair <int,int> a,pair<int,int> b){
    if(a.first<b.first) return true;
    else if(a.first>b.first) return false;
    else{
        if(a.second<=b.second) return true;
        else return false;
    }
}

int changeMap(int RC,int idx){
    for(int n=0;n<memo.size();n++){
        int key = memo[n];
        int val = number[key];
        number[key] = 0;
        infoNum.push_back(make_pair(val,key));
    }
    sort(infoNum.begin(),infoNum.end(),compare);

    for(int n=0;n<infoNum.size() && n<50;n++){
        if(RC==1){
            inMap[idx][n*2] = infoNum[n].second;
            inMap[idx][n*2+1] = infoNum[n].first;
        }else if(RC==2){
            inMap[n*2][idx] = infoNum[n].second;
            inMap[n*2+1][idx] = infoNum[n].first;
        }
    }
    for(int n=infoNum.size()*2;n<100;n++){
        if(RC==1) inMap[idx][n] = 0;
        else if(RC==2) inMap[n][idx] = 0;
    }

    int size = infoNum.size()*2;
    vector <int> empty1;
    empty1.swap(memo);
    vector <pair<int,int>> empty2;
    empty2.swap(infoNum);
    return size;
}

int getResult(){
    for(int t=1;t<=100;t++){
        int nextMax = -1;
        if(maxR>=maxC){
            for(int i=0;i<maxR;i++){
                for(int n=0;n<100;n++){
                    if(inMap[i][n]!=0){
                        if(number[inMap[i][n]]==0) memo.push_back(inMap[i][n]);
                        number[inMap[i][n]]++;
                    }
                }
                int length = changeMap(1,i);
                if(nextMax<length) nextMax = length;
            }
            maxC = nextMax;
        }else{
            for(int j=0;j<maxC;j++){
                for(int n=0;n<100;n++){
                    if(inMap[n][j]!=0){
                        if(number[inMap[n][j]]==0) memo.push_back(inMap[n][j]);
                        number[inMap[n][j]]++;
                    }
                }
                int length = changeMap(2,j);
                if(nextMax<length) nextMax = length;
            }
            maxR = nextMax;
        }
        if(inMap[r][c]==k) return t;
    }
    return -1;
}

int main(){
    scanf("%d %d %d",&r,&c,&k);
    maxR = maxC = 3;
    r--;
    c--;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&inMap[i][j]);
        }
    }
    if(inMap[r][c]==k) printf("0\n");
    else printf("%d\n",getResult());
    return 0;
}