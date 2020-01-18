#include <iostream>

using namespace std;

int main(){
    string input[3];
    
    for(int i = 0; i< 3;i++){
        cin >> input[i];
    }
    for(int i = 0;i<3;i++){
        cout << input[i] << endl;
    }
    printf("Test!!\n");

    return 0;
}