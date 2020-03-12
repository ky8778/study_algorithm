
//! 20200122
// TODO BruteForce
// BJ1436 : https://www.acmicpc.net/problem/1436

#include<cstdio>

using namespace std;

const int finalNum = 666;

int N;

bool checkNum(int inputNum){
    int cnt = 0;
    while(inputNum>0){
        if(inputNum%10==6) cnt++;
        else cnt = 0;
        if(cnt>=3) return true;
        inputNum/=10;
    }
    return false;
}

int getResult(int inputN){
    int number = 1;
    while(inputN>0){
        if(checkNum(number)){
            inputN--;
        }
        number++;
    }

    return number-1;
}

int main(){
    scanf("%d",&N);
    printf("%d",getResult(N));
    return 0;
}
