#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair <int,int> a,pair<int,int> b){
    if(a.first>b.first) return true;
    else if(a.first<b.first) return false;
    else{
        if(a.second>=b.second) return true;
        else return false;
    }
}

int main(){
    vector <pair<int,int>> a;
    a.push_back(make_pair(1,2));
    a.push_back(make_pair(2,1));
    sort(a.begin(),a.end(),compare);
    printf("%d %d %d %d\n",a[0].first,a[0].second,a[1].first,a[1].second);

    return 0;
}