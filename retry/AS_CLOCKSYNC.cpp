
//! 20200127 BruteForce
// TODO Optimization Problems
// AS_CLOCKSYNC : https://www.algospot.com/judge/problem/read/CLOCKSYNC

//! 첫번째 시도 : 시간초과
/*
#include<cstdio>
#include<vector>
using namespace std;
const int MAX = 100;
const int INF = 987654321;

int inputClock[16];
int C;
vector<vector<int>> switchButton = {
    {0,1,2},
    {3,7,9,11},
    {4,10,14,15},
    {0,4,5,6,7},
    {6,7,8,10,12},
    {0,2,14,15},
    {3,14,15},
    {4,5,7,14,15},
    {1,2,3,4,5},
    {3,4,5,9,13}
};

void turnClock(int switchIdx,int type,int num){
    int dir;
    if(type==1) dir = -3;
    else if(type==2) dir = 3;
    int size = switchButton[switchIdx].size();
    for(int t=0;t<num;t++){
        for(int i=0;i<size;i++){
            int tmpIdx = switchButton[switchIdx][i]; 
            inputClock[tmpIdx] += dir;
            if(inputClock[tmpIdx] <= 0) inputClock[tmpIdx] = 12;
            else if(inputClock[tmpIdx] > 12) inputClock[tmpIdx] %= 12;
        }
    }
}

bool checkTime(){
    bool result = true;
    for(int i=0;i<16;i++) if(inputClock[i]!=12) result = false;
    return result; 
}

int getResult(int currentIdx,int currentNum){
    if(currentIdx >= 10) return INF;
    else{
        int ret = INF;
        for(int t=0;t<=4;t++){
            turnClock(currentIdx,2,t);
            if(t>0 && checkTime()){
                ret = currentNum + t < ret ? currentNum + t : ret;
                turnClock(currentIdx,1,t);
                break;
            }
            else{
                int tmpResult = getResult(currentIdx + 1, currentNum + t);
                ret = tmpResult < ret ? tmpResult : ret;
                turnClock(currentIdx,1,t);
            }
        }
        return ret;
    }
}

int main(){
    scanf("%d",&C);
    for(int c=0;c<C;c++){
        for(int i=0;i<16;i++){
            scanf("%d",&inputClock[i]);
        }
        
        int result = getResult(0,0);
        printf("%d\n",result<50?result:-1);

        for(int i=0;i<16;i++){
            inputClock[i] = 0;
        }
    }
    return 0;
}
*/

//! 20200128 두번째 시도 정답!
#include<cstdio>
#include<vector>
using namespace std;
const int INF = 987654321;

int inputClock[16];
int C;
vector<vector<int>> switchButton = {
    {0,1,2},
    {3,7,9,11},
    {4,10,14,15},
    {0,4,5,6,7},
    {6,7,8,10,12},
    {0,2,14,15},
    {3,14,15},
    {4,5,7,14,15},
    {1,2,3,4,5},
    {3,4,5,9,13}
};

void turnClock(int switchIdx){
    int size = switchButton[switchIdx].size();
    for(int i=0;i<size;i++){
        int tmpIdx = switchButton[switchIdx][i]; 
        inputClock[tmpIdx] += 3;
        if(inputClock[tmpIdx] > 12) inputClock[tmpIdx] %= 12;
    }
}

bool checkTime(){
    bool result = true;
    for(int i=0;i<16;i++){
        if(inputClock[i]!=12){
            result = false;
            break;
        }
    }
    return result; 
}

int getResult(int currentIdx,int currentNum){
    int ret = INF;
    if(checkTime()) return currentNum;
    else if(currentIdx >= 10) return ret;
    else{
        for(int t=1;t<=4;t++){
            turnClock(currentIdx);
            int tmpResult = getResult(currentIdx + 1, currentNum + (t%4));
            ret = tmpResult < ret ? tmpResult : ret;
        }
        return ret;
    }
}

int main(){
    scanf("%d",&C);
    for(int c=0;c<C;c++){
        for(int i=0;i<16;i++){
            scanf("%d",&inputClock[i]);
        }
        
        int result = getResult(0,0);
        printf("%d\n",result<50?result:-1);

        for(int i=0;i<16;i++){
            inputClock[i] = 0;
        }
    }
    return 0;
}
/*
2
12 6 6 6 6 6 12 12 12 12 12 12 12 12 12 12 
12 9 3 12 6 6 9 3 12 9 12 9 12 12 6 6
*/