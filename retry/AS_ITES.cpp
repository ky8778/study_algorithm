// TODO Queue AS_ITES
//! 2020.04.03 ~ 2020.04.04
#include<cstdio>
#include<queue>

using namespace std;

int N,T,K;

// Linear Congruentiall Random Number Generator
struct RNG{
    unsigned seed;                          // http://www.ktword.co.kr/abbr_view.php?m_temp1=5796
    RNG() : seed(1983){}                    // https://dreamaz.tistory.com/437
    unsigned next(){
        unsigned ret = seed;
        seed = ((seed * 214013u)+2531011u);
        return ret%10000+1;
    }
};

// Online Algorithm : O(N)
int getResult(){
    RNG rng;
    queue<int> range;
    int ret = 0, rangeSum = 0;
    for(int i=0;i<N;i++){
        int newSignal = rng.next();
        rangeSum+=newSignal;
        range.push(newSignal);
        while(rangeSum>K){
            rangeSum-=range.front();
            range.pop();
        }
        if(rangeSum==K) ret++;
    }
    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d %d",&K,&N);
        printf("%d\n",getResult());
    }
    return 0;
}