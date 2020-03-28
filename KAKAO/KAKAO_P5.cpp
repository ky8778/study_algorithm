#include <string>
#include <vector>

using namespace std;

// n이하인 숫자가 연속으로 k개 있는 것 중 가장 큰 n
// 이진탐색 가능

bool checkArr(vector<int> arr,int n,int k){
    int maxCnt = 0;
    int cnt = 0;
    for(int i=0;i<k;i++){
        if(arr[i]<=n) cnt++;
    }
    maxCnt = cnt;
    for(int i=k;i<arr.size();i++){
        if(arr[i-k]<=n) cnt--;
        if(arr[i]<=n) cnt++;
        if(maxCnt<cnt) maxCnt = cnt;
        // printf("maxCnt : %d\n",maxCnt);
    }
    
    if(maxCnt>=k) return true;
    else return false;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int maxVal = -1;
    for(int i=0;i<stones.size();i++){
        if(maxVal<stones[i])
            maxVal = stones[i];
    }
    int start = 0;
    int end = maxVal+1;
    // binarySearch
    // start는 무조건 X, end는 무조건 O
    while(start+1<end){
        int mid = (start+end)/2;
        if(checkArr(stones,mid,k)) end = mid;
        else start = mid;
        // printf("start : %d, end : %d\n",start,end);
    }
    answer = end;
    return answer;
}

int main(){
    // [2, 4, 5, 3, 2, 1, 4, 2, 5, 1], 3
    vector <int> a;
    a.push_back(2);
    a.push_back(4);
    a.push_back(5);
    a.push_back(3);
    a.push_back(2);
    a.push_back(1);
    a.push_back(4);
    a.push_back(2);
    a.push_back(5);
    a.push_back(1);
    printf("%d\n",solution(a,3));
    return 0;
}