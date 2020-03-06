// 2019.10.22
/*
algorithm : Dijkstra algorithm
input : V(# of nodes) E(# of edges) / K(start node index) / E * u,v,w(u->v,weight)
output : V * shortest path distance to i (to start : 0, if there is not any path ~ print INF)
1) select shortest path from set to other node
2) update path information
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int MAX = 20050;
int V,E,K;
int INF = 1000000000;

vector <pair<int,int>> a[MAX];  
int d[MAX];                     
bool check[MAX];

void dijkstra(int start){
    priority_queue<pair<int,int>> pq;   // priority queue
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        // select front node if this is first visit & push every adjacent nodes
        int current = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();
        if(check[current]) continue;
        else check[current] = true;
        //printf("current : %d, distance : %d\n",current,distance);
        
        d[current] = distance;
        
        for(int i=0;i<a[current].size();i++){
            int next = a[current][i].first;
            int nextDistance = distance + a[current][i].second;
            pq.push(make_pair(-nextDistance,next));
        }
    }
}

int main(){
    scanf("%d %d",&V,&E);
    for(int i=1;i<= V;i++){
        d[i] = INF;
    }
    scanf("%d",&K);
    for(int e=1;e<=E;e++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        a[u].push_back(make_pair(v,w));
    }
    dijkstra(K);
    // 결과를 출력
    for(int i=1;i<=V;i++){
        if(d[i]==INF) printf("INF\n");
        else printf("%d\n",d[i]);
    }
    return 0;
}