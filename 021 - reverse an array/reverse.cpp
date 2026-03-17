#include <iostream>

int main() {
    int n;
    int arr[100]; // 최대 100개의 정수를 저장할 수 있는 배열
    // TODO: 길이 n의 정수 배열을 준비하세요.
    std::cin >> n;
    // TODO: n개의 정수를 입력받아 배열에 저장하세요.
    for (int i = 0; i < n; ++i) {
        // 입력받은 정수를 배열에 저장하는 코드 작성
        std::cin >> arr[i];
    }
    // TODO: 배열의 마지막 원소부터 첫 원소까지 역순으로 출력
    for (int i = n - 1; i >= 0; --i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}