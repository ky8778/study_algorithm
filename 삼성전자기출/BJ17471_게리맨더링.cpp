//! 2020.02.15
// TODO BJ17471_게리맨더링
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

const int MAX = 15;
const int INF = 987654321;
int N;
int inMap[MAX];                     // numbers of people in map
int numMap[MAX];                    // number of local in map
vector <int> myMap[MAX];            // graph
bool checkMap[MAX];              // checkMap for BFS
queue <int> myQ;

void resetCheck(){
    for(int i=1;i<=N;i++) checkMap[i] = false;
}

int BFS(int start,int sizeMap){
    int cnt = 0;
    int numPeople = 0;
    myQ.push(start);
    checkMap[start] = true;

    while(!myQ.empty()){
        int current = myQ.front();
        myQ.pop();
        cnt++;
        numPeople+=inMap[current];
        int sizeV = myMap[current].size();
        for(int i=0;i<sizeV;i++){
            int next = myMap[current][i];
            if(!checkMap[next] && numMap[start]==numMap[next]){
                checkMap[next] = true;
                myQ.push(next);
            }
        }
    }
    if(cnt<sizeMap) return INF;
    else return numPeople;    
}

int getSize(int nn1,int nn2){
    if(nn1==0 || nn2==0) return INF;
    
    int size1,size2;
    for(int i=1;i<=N;i++){
        if(numMap[i]==1){
            size1 = BFS(i,nn1);
            break;
        }
    }
    resetCheck();
    if(size1>900000000) return INF;

    for(int i=1;i<=N;i++){
        if(numMap[i]==2){
            size2 = BFS(i,nn2);
            break;
        }
    }
    if(size2>900000000) return INF;
    resetCheck();
    // printf("size1 : %d, size2 : %d\n",size1,size2);
    return size1>=size2?size1-size2:size2-size1;
}

int getResult(int idx,int n1,int n2){
    if(idx>N) return getSize(n1,n2);
    else{
        int minRet = INF;
        numMap[idx] = 1;
        int tmpRet = getResult(idx+1,n1+1,n2);
        if(tmpRet<minRet) minRet = tmpRet;
        numMap[idx] = 2;
        tmpRet = getResult(idx+1,n1,n2+1);
        if(tmpRet<minRet) minRet = tmpRet;
        // printf("min : %d\n",minRet);
        return minRet;
    }
}

int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++) scanf("%d",&inMap[i]);
    for(int i=1;i<=N;i++){
        int tmpN;
        scanf("%d",&tmpN);
        for(int j=1;j<=tmpN;j++){
            int next;
            scanf("%d",&next);
            myMap[i].push_back(next);
        }
    }
    
    int result = getResult(1,0,0);
    if(result>900000000) result = -1;
    printf("%d\n",result);
    return 0;
}