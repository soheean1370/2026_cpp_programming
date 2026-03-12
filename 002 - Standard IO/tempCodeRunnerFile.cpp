#include <iostream>
using namespace std;

int main( ){
    int n[3];
    int sum = 0;
    for(int i = 0; i < 3; i++){
        cin >> n[i];
        sum += n[i];
    }
    cout << sum << endl;
    return 0;

}