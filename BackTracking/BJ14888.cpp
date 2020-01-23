
//! 20200123
// TODO BackTracking
// BJ14888 : https://www.acmicpc.net/problem/14888

#include<cstdio>
#include<vector>

using namespace std;

int N,resultMax,resultMin;
int numbers[15];
vector <int> calcs;
int calc[4];

int calculate(const vector <int> inputCalc){
    int result = numbers[0];
    for(int i=0;i<N-1;i++){
        // printf("i : %d\n",i);
        switch(calcs[i]){
            case 0:
                result+=numbers[i+1];
                break;
            case 1:
                result-=numbers[i+1];
                break;
            case 2:
                result*=numbers[i+1];
                break;
            case 3:
                result/=numbers[i+1];
                break;
        }
    }
    return result;
}

void getResult(int currentIdx){
    if(currentIdx>=N-1){
        int resultCalc = calculate(calcs);
        if(resultCalc>resultMax) resultMax = resultCalc;
        if(resultCalc<resultMin) resultMin = resultCalc;
        return;
    }else{
        for(int i=0;i<4;i++){
            if(calc[i]>0){
                // printf("i : %d\n",i);
                calc[i]--;
                calcs.push_back(i);
                getResult(currentIdx+1);
                calcs.pop_back();
                calc[i]++;
            }
        }
    }
}

int main(){
    scanf("%d",&N);
    for(int n=0;n<N;n++){
        int tmp;
        scanf("%d",&numbers[n]);
    }
    scanf("%d %d %d %d",&calc[0],&calc[1],&calc[2],&calc[3]);

    resultMax = -987987987;
    resultMin = 987987987;
    getResult(0);
    printf("%d\n",resultMax);
    printf("%d\n",resultMin);

    return 0;
}