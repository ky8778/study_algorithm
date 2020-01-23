
//! 20200123
// TODO DynamicProgramming
// BJ2748 : https://www.acmicpc.net/problem/2748

#include<cstdio>
using namespace std;

const int MAX = 100;
long long DP[MAX];
long long N;

long long fibonacci(int number){
    if(DP[number]>0) return DP[number];
    else if(number==0) return DP[number] = 0;
    else if(number==1) return DP[number] = 1;
    else return DP[number] = fibonacci(number-1)+fibonacci(number-2);
}

int main(){
    scanf("%d",&N);
    printf("%lld",fibonacci(N));
    
    return 0;
}