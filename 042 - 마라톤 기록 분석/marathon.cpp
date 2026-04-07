#include "marathon.h"
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

// TODO: 아래 여덟 함수를 구현하세요.
// 참가자 목록은 아래 static 변수로 관리합니다. 함수 파라미터로 전달하지 않습니다.
static std::vector<Runner> runners;

void add_runner(const Runner& r) {
    // 참가자를 목록에 추가합니다.
    runners.push_back(r);
}

void remove_runner(const std::string& name) {
    // 이름이 name인 첫 번째 참가자를 목록에서 제거합니다. 없으면 아무것도 하지 않습니다.
    // 힌트: std::find_if 로 반복자를 얻고, end()가 아닐 때만 erase 합니다.
    auto it = std::find_if(runners.begin(), runners.end(), [&](const Runner& r) {
        return r.name == name;
    });
    if (it != runners.end()) {
        runners.erase(it);
    }
}

void update_time(const std::string& name, int new_time) {
    // 이름이 name인 첫 번째 참가자의 기록을 new_time으로 수정합니다. 없으면 무시합니다.
    // 힌트: std::find_if 로 반복자를 얻고, it->time = new_time; 으로 수정합니다.
    auto it = std::find_if(runners.begin(), runners.end(), [&](const Runner& r){
        return r.name == name;
    });
    if( it != runners.end()){
        it-> time = new_time;
    }
}

void print_runner(const std::string& name) {
    // 이름이 name인 참가자를 모두 출력합니다. 형식: "name time age"
    // 한 명도 없으면 "NOT FOUND" 를 출력합니다.
    bool found = false;
    for ( const Runner& r : runners){
        if(r.name == name){
            std::cout << r.name << ' ' << r.time << ' '<< r.age<< '\n';
            found = true;
        }
    }
    if (!found){
        std::cout << "NOT FOUND\n";
    }
}

int total_time() {
    // 모든 완주 기록의 합계를 반환합니다.
    //  std::accumulate를 사용해야함
    // accumulate(시작, 끝, 초기값, 함수)
    int total = std::accumulate(runners.begin(), runners.end(), 0, [](int sum, const Runner& r){
        return sum + r.time;
    });
    return total;
}

double avg_time() {
    // 완주 기록의 평균을 반환합니다. (정수 나눗셈 주의)
    // 평균(소수점 둘째 자리
    int total = total_time();
    if (!runners.empty()){
        return static_cast<double>(total) / runners.size();
    }
    return 0.0;
}

int best_time() {
    // 가장 빠른 기록(최솟값)을 반환합니다.
    if(runners.empty()){
        return 0; // 참가자가 없으면 0 반환
    }
    auto it = std::min_element(runners.begin(), runners.end(), [](const Runner& a, const Runner& b){
        return a.time < b.time;
    });
    return it->time;
}

int worst_time() {
    // 가장 느린 기록(최댓값)을 반환합니다.
    if(runners.empty()){
        return 0; // 참가자가 없으면 0 반환
    }
    auto it = std::max_element(runners.begin(), runners.end(), [](const Runner& a, const Runner& b){
        return a.time < b.time;
    });
    return it->time;
}
