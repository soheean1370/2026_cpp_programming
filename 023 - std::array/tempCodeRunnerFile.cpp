#include <array>
#include <iostream>
#include <algorithm>

int main() {
    std::array<int, 10> values{};

    // TODO: values에 정수 10개를 입력받으세요.
    for (int i = 0; i< values.size(); i++){
        std::cin >> values[i];
    }
    // TODO: 가장 큰 값과 가장 작은 값을 찾아 공백 하나로 출력하세요.
    
    int minValue = *(std::minmax_element(values.begin(), values.end()).first); // 가장 작은 값
    int maxValue = *(std::minmax_element(values.begin(), values.end()).second); // 가장 큰 값

    std::cout << maxValue << " " << minValue << std::endl;
    // TODO: 필요하면 <algorithm> 헤더를 추가해 std::minmax_element를 사용할 수 있습니다.

    return 0;
}