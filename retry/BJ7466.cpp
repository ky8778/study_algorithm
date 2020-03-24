// 7466번 3
/*
 2로 나누어 떨어진다 2를 출력 -> 2에서 k/2/2까지 for문 돌리는 함수로 들어간다.
 3으로 나누어 떨어진다. 3을 출력 -> 2에서 k/2/3까지 for문 돌리는 함수로 들어간다.
 -> 소인수들을 담는다.
 
 */

/*
 완전탐색으로 한다면?
 2부터 k나 n중 작은 수 까지 나눠보겠지 두가지를.
 나눠지는 수가 있으면 그만큼 증가시켜서 나누겠지. GCD에 나눠지는 숫자를 저장.
 for(int i=2;i<N;i++){
 if(
 }
 2로 나눈다. 안나눠짐. 3으로 나눈다. 나눠짐. 6으로 나눈다. 안나눠짐. 9로 나눈다. 나눠짐. 18로 나눈다.
 */

// K의 약수를 구한다. 약수들에서 확인한다. 그 중 가장 큰 걸로 한다.
// 약수를 각각 다른 수들로 나타냈을 때 그 중 가장 큰 수가 N보다 작은지 확인.
/*
 GCD -> 빼기로 구하는 방법
 a b r(a-b)
 10 4 6
 6 4 2
 4 2 2
 2 2 0
 G = 2
 */

#include <stdio.h>
int N,K;
int T;
long long factorial=1;
long long count=1;
int G=1;

void GCD(int x){// 가장 작은 소인수부터 출력 -> 2에서부터 N까지 수 중에 나눠지는거 있으면 나누고 그 다음 수부터 시작하도록함.
    int result;
    if(x==1||x==0){
        return;
    }else{
        for(int i=2;i<=x;i++){
            if(x%i==0){
                result = i;
                while(factorial%result!=0){
                    factorial*=(++count);
                    if(count>N) return;
                }
                factorial/=result;
                G*=result;
                GCD(x/i);
                return;
            }
        }
    }
}

int main(){
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d %d",&N,&K);
        GCD(K);
        printf("#%d %d\n",i+1,G);
        G = 1;
        count =1;
        factorial = 1;
    }
    return 0;
}