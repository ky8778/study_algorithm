//! 2020.04.02
// TODO AS_JOSEPHUS LinkedList
#include <cstdio>
#include <list>
using namespace std;

const int MAX = 1050;
int N,K,T;
list <int> myList;

void getResult(){
    list<int>::iterator it=myList.begin();
    
    while(N>2){
        // printf("die : %d\n",*it);
        it = myList.erase(it);
        N--;
        if(it==myList.end()) it = myList.begin();
        for(int i=0;i<K-1;i++){
            it++;
            if(it==myList.end()) it = myList.begin();
        }
    }
}

int main(){
    // freopen("input.txt","r",stdin);
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        scanf("%d %d",&N,&K);
        for(int i=1;i<=N;i++) myList.push_back(i);
        getResult();
        for(list<int>::iterator it=myList.begin();it!=myList.end();it++){
            printf("%d ",*it);
        }
        printf("\n");
        list<int> empty;
        myList.swap(empty);
    }

    return 0;
}