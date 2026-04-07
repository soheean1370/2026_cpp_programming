#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> values;
    values.reserve(n);

    // TODO: std::copy_n 과 std::istream_iterator<int> 로 n개의 정수를 읽으세요.

    std::istream_iterator<int> iter{std::cin}; // 입력 스트림에서 정수를 차례대로 읽어옴
    std::copy_n(iter, n , std::back_inserter(values)); // iter에서 n개의 정수를 읽어 values 벡터에 추가
    // TODO: 정렬한 뒤 std::copy 와 std::ostream_iterator<int> 로 한 줄에 하나씩 출력하세요.

    std::sort(values.begin(), values.end()); // 벡터를 오름차순으로 정렬
    std::copy(values.begin(), values.end(), std::ostream_iterator<int>{std::cout , "\n"});
    // std::copy는 시작과 끝을 지정하여 범위의 요소를 복사하는 알고리즘
    // std::copy_n 는 시작과 개수를 지정하여 요소를 복사하는 알고리즘
    // ostream_iterator<int>는 값을 출력 스트림에 차례대로 씀
    
    return 0;
}
