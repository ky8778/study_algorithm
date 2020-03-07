//! 2020.03.07
// TODO AS_QUANTIZE
#include<cstdio>
#include<algorithm>
using namespace std;

const int INF = 987654321;
const int MAX = 105;
int N,S,T;
int number[MAX],integ[MAX],sqInteg[MAX];
int DP[MAX][11];

int getMin(int n1,int n2){
    if(n1<n2) return n1;
    else return n2;
}

void preCalc(){
    sort(number,number+N);
    integ[0] = number[0];
    sqInteg[0] = number[0]*number[0];
    for(int i=1;i<N;i++){
        integ[i] = integ[i-1]+number[i];
        sqInteg[i] = sqInteg[i-1]+number[i]*number[i];
    }
}

int minSqError(int start,int end){
    int sum = integ[end] - (start == 0 ? 0 : integ[start-1]);
    int sqSum = sqInteg[end] - (start == 0 ? 0 : sqInteg[start-1]);
    int m = int(0.5 + (double)sum/(end-start+1));
    int ret = sqSum - 2*m*sum + m*m*(end-start+1);
    return ret;
}

int getResult(int start, int part){
    if(start>=N) return 0;
    if(part>=S) return INF;
    int& ret = DP[start][part];
    if(ret!=-1) return ret;
    ret = INF;
    for(int s = 0;start+s<N;s++)
        ret = getMin(ret,minSqError(start,start+s)+getResult(start+s+1,part+1));
    
    return ret;
}

int main(){
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        scanf("%d %d",&N,&S);
        for(int n=0;n<N;n++) scanf("%d",&number[n]);

        for(int i=0;i<N;i++){
            for(int j=0;j<S;j++){
                DP[i][j] = -1;
            }
        }
        
        preCalc();
        printf("%d\n",getResult(0,0));
    }
    return 0;
}