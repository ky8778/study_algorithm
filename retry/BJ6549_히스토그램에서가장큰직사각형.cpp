//! 2020.04.03
// TODO BJ6549_히스토그램에서가장큰직사각형 stack
#include<cstdio>
#include<stack>
#include<vector>
using namespace std;

int N;
vector <int> h;
stack <int> myStack;

long long getMax(long long n1,long long n2){
    if(n1>n2) return n1;
    else return n2;
}

long long getResult(){
    long long ret = 0;
    h.push_back(0);
    myStack.push(0);
    int width = 0;

    for(int i=1;i<=N;i++){
        while(!myStack.empty() && h[myStack.top()]>=h[i]){
            int j = myStack.top();
            myStack.pop();
            if(myStack.empty()){
                width = i;
            }else{
                width = i - myStack.top() - 1;
            }
            long long size = (long long)width*(long long)h[j];
            ret = getMax(ret,size);
        }
        myStack.push(i);
    }
    stack <int> empty;
    myStack.swap(empty);
    return ret;
}

int main(){
    freopen("input.txt","r",stdin);
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        for(int i=0;i<N;i++){
            int num;
            scanf("%d",&num);
            h.push_back(num);
        }

        printf("%lld\n",getResult());
        vector <int> empty;
        h.swap(empty);
    }

    return 0;
}