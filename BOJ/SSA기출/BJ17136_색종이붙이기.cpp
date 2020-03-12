//! 2020.02.27
// TODO BJ17136_색종이붙이기
#include<cstdio>
using namespace std;
const int MAX = 15;
const int SIZE = 10;
const int INF = 987654321;
int inMap[MAX][MAX];
int myPaper[5];

bool inRange(int y,int x){
    if(y>=0&&y<SIZE&&x>=0&&x<SIZE) return true;
    else return false;
}

int min(int n1,int n2){
    if(n1<n2) return n1;
    else return n2;
}

bool checkSize(int y,int x,int size){
    for(int i=y;i<y+size;i++){
        for(int j=x;j<x+size;j++){
            if(!inRange(i,j) || inMap[i][j]!=1) return false;
        }
    }
    return true;
}

void fillMap(int y,int x,int size,int val){
    for(int i=y;i<y+size;i++){
        for(int j=x;j<x+size;j++){
            inMap[i][j] = val;
        }
    }
}

bool findNext(int& y,int& x){
    for(int j=x+1;j<SIZE;j++){
        if(inMap[y][j]==1){
            x = j;
            return true;
        }
    }
    for(int i=y+1;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(inMap[i][j]==1){
                x = j;
                y = i;
                return true;
            }
        }
    }
    return false;
}

int getResult(int y,int x,int total){
    int nextY = y;
    int nextX = x;
    
    if(!findNext(nextY,nextX)) return total;
    else{
        int ret = INF;
        for(int size=1;size<=5;size++){
            if(checkSize(nextY,nextX,size) && myPaper[size-1]!=0){
                myPaper[size-1]--;
                fillMap(nextY,nextX,size,2);
                ret = min(ret,getResult(nextY,nextX,total+1));
                fillMap(nextY,nextX,size,1);
                myPaper[size-1]++;
            }
        }
        return ret;
    }
}

int main(){
    for(int n=0;n<5;n++) myPaper[n] = 5;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            scanf("%d",&inMap[i][j]);
        }
    }
    int result = getResult(0,-1,0);
    if(result>30) result = -1;
    printf("%d\n",result);
    return 0;
}