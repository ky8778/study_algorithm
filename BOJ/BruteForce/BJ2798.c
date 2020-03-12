// 20200121
// BJ2798 : https://www.acmicpc.net/problem/2798
#include<stdio.h>

int N,M,result;
int card[105];
int check[105];

void getResult(int num,int sum){
    //printf("num : %d, sum : %d\n",num,sum);
    if(num>3){
        if(sum>result&&sum<=M){
            result = sum;
        }
        return;
    }else{
        for(int i=0;i<N;i++){
            if(check[i]==0){
                check[i]=1;
                sum+=card[i];
                getResult(num+1,sum);
                sum-=card[i];
                check[i]=0;
            }
        }
    }
}

int main(){
    scanf("%d %d",&N,&M);
    for(int n=0;n<N;n++){
        scanf("%d",&card[n]);
    }
    
    getResult(1,0);

    printf("%d\n",result);
    return 0;
}