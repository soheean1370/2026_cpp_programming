#include "StringSplitter.h"
#include <cctype>
#include <sstream>

// TODO: 아래 함수들을 구현하세요.
// trim(), replaceSubstring(), removePunctuation() 은 *this 를 반환하여
// 메서드 체이닝을 가능하게 합니다.

StringSplitter::StringSplitter(const std::string& str) {
    // data_ 에 입력 문자열을 저장합니다.
    data_ = str;
}

StringSplitter& StringSplitter::trim() {
    // data_ 의 앞뒤 공백을 제거합니다.
    // 힌트: find_first_not_of(' ') 와 find_last_not_of(' ') 사용
    // find_first_not_of(' ') 는 문자열에서 공백이 아닌 첫 번째 문자의 위치를 반환
    // find_last_not_of(' ') 는 문자열에서 공백이 아닌 마지막 문자의 위치를 반환

    // 반드시 return *this; 로 끝내세요.
    size_t start = data_.find_first_not_of(' ');
    size_t end = data_.find_last_not_of(' ');
    // npos는 찾는 문자가 없을때 반환되는 값
    if(start == std::string::npos){
        data_.clear(); // 문자열이 모두 공백인 경우 빈 문자열로 설정
    } else {
        // substr은 문자열의 일부분을 추출
        // substr(pos, len) 는 pos 위치에서 len 길이만큼의 문자열을 반환
        data_ = data_.substr(start, end - start + 1); //앞뒤 공백 제거
        
    }

    return *this;
}

StringSplitter& StringSplitter::replaceSubstring(const std::string& from,
                                                   const std::string& to) {
    // data_ 에서 from 을 찾아 to 로 교체합니다 (첫 번째 등장만).
    // 힌트: data_.find(from) 으로 위치를 찾고
    //       data_.replace(pos, from.length(), to) 로 교체
    // from 이 없으면 아무 것도 하지 않습니다.
    // replace(pos, len, str) 는 pos 위치에서 len 길이만큼의 문자열을 str로 교체

    size_t pos = data_.find(from); // 위치 찾기
    if(pos != std::string::npos){ // from이 존재하면
         data_.replace(pos, from.length(), to); // 교체
    }
    return *this;
}

StringSplitter& StringSplitter::removePunctuation() {
    // data_ 에서 구두점 문자를 모두 제거합니다.
    // 힌트: std::ispunct(c) 가 true 인 문자를 제거
    //       erase-remove 관용구 또는 std::erase_if(data_, ::ispunct) 사용
    
    // erase_if 는 조건에 맞는 요소를 제거하는 함수
    // ispunct는 구두점인지 확인하는 함수
    data_.erase(std::remove_if(data_.begin(), data_.end(), ::ispunct), data_.end());
    return *this;
}

std::vector<std::string> StringSplitter::split(char delimiter) const {
    // data_ 를 delimiter 기준으로 나눠 벡터로 반환합니다.
    // 빈 토큰은 포함하지 않습니다.
    // 힌트: std::istringstream 으로 getline(iss, token, delimiter) 반복
    // istringstream은 문자열을 스트림으로 다루는 클래스
    // 스트림이란 데이터를 순차적으로 읽거나 쓸 수 있는 객체
    

    std::vector<std::string> tokens;
    std::istringstream iss(data_);
    std::string token;
    // getline은 스트림에서 구분자까지의 문자열을 읽어서 token에 저장
    while(std::getline(iss, token, delimiter)){
        if(!token.empty()){
            tokens.push_back(token);
        }
    }
    return tokens;
}
