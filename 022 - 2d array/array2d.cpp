#include <iostream>
#include <vector>

int main() {
    int rows, cols;
    std::cin >> rows >> cols;

    // TODO: rows x cols 크기의 2차원 정수 배열을 준비하세요.
    // TODO: 행렬을 입력받으면서 각 행의 합과 각 열의 합을 계산하세요.
    std::vector<std::vector<int>> arr(rows, std::vector<int>(cols)); // 2차원 벡터로 배열 선언
    std::vector<int> rowSums(rows, 0); // 각 행의 합을 저장할 벡터
    std::vector<int> colSums(cols, 0); // 각 열의 합을 저장할 벡터
    // TODO: 첫째 줄에 행의 합, 둘째 줄에 열의 합을 출력하세요.
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            std::cin >> arr[i][j];
            rowSums[i] += arr[i][j]; // 행의 합 계산
            colSums[j] += arr[i][j]; // 열의 합 계산
        }
    }
    for (int i = 0; i < rows; i++) {
        std::cout << rowSums[i] << " ";
    }
    std::cout << std::endl;
    for (int j = 0; j < cols; j++) {
        std::cout << colSums[j] << " ";
    }
    std::cout << std::endl;

    return 0;
}
