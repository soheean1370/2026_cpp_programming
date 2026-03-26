#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> values(n);

    for ( int i =0; i<n;i++){
        cin >> values[i];
    }
    int even_sum = 0;
    int odd_sum = 0;

    for (int num : values){ // range-based for 문
        if (num %2 ==0){
            even_sum += num;
        } else{
            odd_sum += num;
        }
    }
    cout << even_sum << endl;
    cout << odd_sum << endl;
    return 0;
}