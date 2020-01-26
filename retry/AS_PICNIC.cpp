
//! 20200126 BruteForce
// TODO BruteForce
// AS_PICNIC : https://www.algospot.com/judge/problem/submit/PICNIC
#include<cstdio>
#include<vector>
using namespace std;

const int MAX = 100;
int C,N,M;
vector <int> team[MAX];
bool check[MAX];
int result;

void getResult(int current, int toPick){
    if(toPick<=0){
        result++;
        return;
    }
    if(check[current]){
        getResult(current+1,toPick-1);
    }else{
        check[current] = true;
        int size = team[current].size();
        for(int idx=0;idx<size;idx++){
            if(!check[team[current][idx]]){
                check[team[current][idx]] = true;
                getResult(current+1,toPick-1);
                check[team[current][idx]] = false;
            }
        }
        check[current] = false;
    }
}

int main(){
    scanf("%d",&C);
    for(int c=0;c<C;c++){
        scanf("%d %d",&N,&M);
        for(int m=0;m<M;m++){
            int num1,num2;
            scanf("%d %d",&num1,&num2);
            num1>num2?team[num2].push_back(num1):team[num1].push_back(num2);
        }

        getResult(0,N);

        printf("%d\n",result);
        for(int n=0;n<N;n++){
            vector <int> empty;
            team[n].swap(empty);
        }
        result = 0;
    }

    return 0;
}