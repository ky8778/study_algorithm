
//! 2020.02.03
// TODO BJ2660

#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int MAX = 55;
int N;
vector <int> myGraph[MAX];
bool checkGraph[MAX];
int dist[MAX];
queue <int> myQ;
vector <int> ret;

int BFS(){
    int depth = -1;

    while(!myQ.empty()){
        depth++;
        int sizeQ = myQ.size();
        for(int i=0;i<sizeQ;i++){
            int current = myQ.front();
            myQ.pop();
            int sizeV = myGraph[current].size();
            for(int j=0;j<sizeV;j++){
                int next = myGraph[current][j];
                if(!checkGraph[next]){
                    checkGraph[next] = true;
                    myQ.push(next);
                }
            }
        }
    }
    return depth;
}

int getResult(){
    int minRet = 987654321;
    for(int i=1;i<=N;i++){
        checkGraph[i] = true;
        myQ.push(i);
        int tmp = BFS();
        dist[i] = tmp;
        if(minRet>tmp) minRet = tmp;

        // reset
        queue <int> emptyQ;
        myQ.swap(emptyQ);
        for(int j=1;j<=N;j++) checkGraph[j] = false;
    }

    for(int i=1;i<=N;i++){
        if(dist[i]==minRet) ret.push_back(i);
    }
    sort(ret.begin(),ret.end());
    return minRet;
}

int main(){
    scanf("%d",&N);
    int num1,num2;
    while(true){
        scanf("%d %d",&num1,&num2);
        if(num1<0) break;
        myGraph[num1].push_back(num2);
        myGraph[num2].push_back(num1);
    }
    int result = getResult();
    printf("%d %d\n",result,ret.size());
    for(int i=0;i<ret.size();i++){
        printf("%d ",ret[i]);
    }
    printf("\n");

    return 0;
}