#include "contest.h"
#include <map>
#include <iostream>

// TODO: 아래 다섯 함수를 구현하세요.
// 순위표는 아래 static 변수로 관리합니다. 함수 파라미터로 전달하지 않습니다.
static std::map<std::string, Player> board;

void join(const Player& p) {
    // 참가자를 순위표에 등록합니다. 이미 있으면 덮어씁니다.
    board[p.name] = p;
}

void quit(const std::string& name) {
    // 참가자를 순위표에서 제거합니다. 없으면 무시합니다.
    board.erase(name);
}

void update(const std::string& name, int score, int solved) {
    // 이미 등록된 참가자의 점수와 해결 수를 갱신합니다. 없는 참가자는 추가하지 않습니다.
    if (board.count(name) > 0){
        board[name].score = score;
        board[name].solved = solved;
    }
}

std::vector<std::string> qualifiers(int cutoff) {
    // cutoff 이상의 점수를 가진 참가자 이름을 이름 오름차순으로 반환합니다.
    std::vector<std::string> result;
    for (const auto& [name, player]: board){
        if (player.score >= cutoff){
            result.push_back(name);
        }
    }
    std::sort(result.begin(), result.end());
    return result;
}

void print_board() {
    // 순위표를 이름 오름차순으로 "이름 점수 해결수" 형식으로 한 줄씩 출력합니다.
    std::vector<std::string> names;
    for (const auto& [name, player]: board){
        names.push_back(name);
    }
    std::sort(names.begin(), names.end());
    for (const auto& name: names){
        const auto& player = board[name];
        std::cout << name << ' '<< player.score << ' ' << player.solved << '\n';
    }
}
