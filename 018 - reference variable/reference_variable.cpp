#include <iostream>

// TODO: 참조 변수(reference variable)를 파라미터로 사용하는
// TODO: void my_swap(int& a, int& b) 함수를 구현하세요.
void my_swap(int& a, int& b) {
    // TODO: 임시 변수를 사용하여 두 값을 서로 교환하세요.
    int temp = a; // 임시 변수에 a의 값을 저장
    a = b;        // a에 b의 값을 저장
    b = temp;     // b에 임시 변수의 값을 저장 (원래 a의 값)
}


int main() {
    int m, n;
    std::cin >> m >> n;
    my_swap(m, n);
    std::cout << m << " " << n;
}
