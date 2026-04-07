#include <iostream>
#include <map>
#include <string>

// g++ main.cpp tools.cpp -o main && ./main 명령어
int main() {
    int n;
    std::cin >> n;

    // map의 key는 단어, value는 등장 횟수
    
    std::map<std::string, int> counts;

    // TODO: 단어 n개를 입력받아 counts[word] 를 증가시키세요.
    for(int i = 0; i<n; i++){
        std::string word;
        std::cin >> word;
        counts[word]++;
    }
    /****
     for (int i = 0; i< n; i++){
        std::string word;
        std::cin >> word;
        if (counts.find(word) != counts.end()) {
            counts[word] += 1; //  이미 등장한 단어는 기존 값에
        } else {
            counts[word] == 1; // 처음 등장하는 단어는 1로 초기화
        }
     */
    // TODO: for 문으로 map 을 순회하며 "단어 개수" 형식으로 출력하세요.
    for(const auto& [word, count]: counts){
        std::cout << word << ' ' << count << '\n';
    }

    return 0;
}
