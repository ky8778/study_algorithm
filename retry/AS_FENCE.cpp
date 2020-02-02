
// TODO Divide & Conquer
// algospot FENCE
// https://www.algospot.com/judge/problem/read/FENCE

#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 20050;
int C, N;
int input[MAX];

int getMax(int a,int b){
    return a>b?a:b;
}

int getMin(int a,int b){
    return a<b?a:b;
}

int getResult(int start, int end){
    if(start>=end) return input[start];
    else{
        int mid = (start+end)/2;
        int a1 = getResult(start,mid);
        int a2 = getResult(mid+1,end);
        int tmpResult = getMax(a1,a2);
        int leftIdx = mid;
        int rightIdx = mid+1;
        int height = getMin(input[leftIdx],input[rightIdx]);
        tmpResult = getMax(tmpResult,height*2);

        while(leftIdx > start || rightIdx < end){
            if(leftIdx <= start){
                rightIdx++;
                height = getMin(height,input[rightIdx]);
            }
            else if(rightIdx >= end){
                leftIdx--;
                height = getMin(height,input[leftIdx]);
            }
            else{
                if(input[leftIdx-1]>input[rightIdx+1]){
                    leftIdx--;
                    height = getMin(height,input[leftIdx]);
                }
                else{
                    rightIdx++;
                    height = getMin(height,input[rightIdx]);
                }
            }
            tmpResult = getMax(tmpResult,height*(rightIdx-leftIdx+1));
            // printf("h : %d tmpResult : %d\n",h,tmpResult);
        }
        return tmpResult;
    }
}

int main(){
    scanf("%d",&C);
    for(int t=1;t<=C;t++){
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            scanf("%d",&input[i]);
        }

        printf("%d\n",getResult(0,N-1));

        for(int i=0;i<N;i++){
            input[i] = 0;
        }
    }
    return 0;
}

/*
3
7
7 1 5 9 6 7 3
7
1 4 4 4 4 1 1
4
1 8 2 2

*/