// 20200121
// BJ2231 : https://www.acmicpc.net/problem/2231
#include<stdio.h>

int N;

int checkNum(int inputN){
    int sum = inputN;
    while(inputN>0){
        sum += inputN%10;
        inputN/=10;
    }
    if(sum==N) return 1;
    else return 0;
}

int getResult(){
    int result = 0;
    int tmp = N;
    int start=1;
    while(tmp>0){
        tmp/=10;
        start*=10;
    }
    start/=100;
    if(start==0) start = 1;
    // printf("start : %d\n",start);

    while(start<N){
        if(checkNum(start)) return start;
        else start++;
    }
    return 0;
}

int main(){
    scanf("%d",&N);
    
    printf("%d\n",getResult());
    return 0;
}