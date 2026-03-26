#include <iostream>
#include <random>

using namespace std;
enum class Hand {
    Rock = 0,
    Scissors = 1,
    Paper = 2
};

const char* hand_to_text(Hand hand) {
    switch (hand) {
        case Hand::Rock:
            return "묵";
        case Hand::Scissors:
            return "찌";
        case Hand::Paper:
            return "빠";
    }

    return "?";
}

int main() {
    int player_code;
    std::cin >> player_code;

    std::mt19937 rng(20260324u);
    const Hand computer = static_cast<Hand>(rng() % 3);
    const Hand player = static_cast<Hand>(player_code);

    std::cout << "컴퓨터: " << hand_to_text(computer) << '\n';
    std::cout << "플레이어: " << hand_to_text(player) << '\n';

    switch (computer) {
        // TODO: 고정 seed 20260324 로 만든 mt19937 의 첫 난수 % 3 값을 컴퓨터 손으로 사용합니다.
        // TODO: computer 와 player 의 조합에 따라 결과를 출력하세요.
        case Hand::Rock:
            if (player == Hand::Rock) {
                cout << "결과: 비김" << '\n';
            } else if(player == Hand::Scissors){
                cout << "결과: 컴퓨터 승" << '\n';
            } else if(player == Hand::Paper){
                cout << "결과: 플레이어 승" << '\n';
            } break;
        
        case Hand::Scissors:
            if (player == Hand::Scissors) {
                cout << "결과: 비김" << '\n';
            } else if(player == Hand::Paper){
                cout << "결과: 컴퓨터 승" << '\n';
            } else if(player == Hand::Rock){
                cout << "결과: 플레이어 승" << '\n';
            } break;
        case Hand::Paper:
            if (player == Hand::Paper) {
                cout << "결과: 비김" << '\n';
            } else if(player == Hand::Rock){
                cout << "결과: 컴퓨터 승" << '\n';
            } else if(player == Hand::Scissors){
                cout << "결과: 플레이어 승" << '\n';
            } break;
    }

    return 0;
}
