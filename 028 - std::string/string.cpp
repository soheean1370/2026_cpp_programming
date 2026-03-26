#include <cctype>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

int countCharacter(const std::string& str, char ch) {
    // TODO: str에서 문자 ch가 몇 번 등장하는지 세어 반환하세요.
    // 읽기만 가능하므로 const std::string&를 사용합니다.
    int cnt = 0;
    for(const char& c : str){
        if(c== ch){
            cnt++;
        }
    }
    return cnt;
}

void toUpperCase(std::string& str) {
    // TODO: str의 모든 문자를 대문자로 바꾸세요.
    // 원본을 수정해야 하므로 std::string&를 사용합니다.
    // &를 안 쓰면 값만 바뀌고 원본은 바뀌지 않습니다
    for(char& c : str){
        c = std::toupper(c);
    }
}

bool startsWith(std::string_view str, std::string_view prefix) {
    // TODO: str이 prefix로 시작하면 true, 아니면 false를 반환하세요.
    // str과 prefix 모두 읽기만 가능하므로 std::string_view를 사용합니다.
    if (str.size() < prefix.size()) {
        return false;
    }   
    for(size_t i = 0; i < prefix.size(); i++){
        if(str[i] != prefix[i]){
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<std::string> words = {"hello", "world", "example"};

    char characterToCount = 'l';
    for (const auto& word : words) {
        std::cout << "Count of '" << characterToCount << "' in \"" << word << "\": "
                  << countCharacter(word, characterToCount) << '\n';
    }
    std::cout << '\n';

    for (auto& word : words) {
        toUpperCase(word);
        std::cout << "Modified string: " << word << '\n';
    }
    std::cout << '\n';

    std::string_view prefix = "EX";
    for (const auto& word : words) {
        std::cout << "Does \"" << word << "\" start with '" << prefix << "'? "
                  << (startsWith(word, prefix) ? "Yes" : "No") << '\n';
    }

    return 0;
}
