#include "board_util.h"
#include <vector>
#include <algorithm>
#include <ranges>
#include <functional>

static std::vector<std::vector<int>> board;

static auto is_full = [](const std::vector<int>& row) {
    return std::ranges::all_of(row, [](int v) { return v == 1; });
};

void init_board() {
    board = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 1, 0, 0},
        {1, 1, 1, 1, 1}
    };
}

const std::vector<std::vector<int>>& get_board() {
    return board;
}

int count_full_lines() {
    // TODO: 모든 칸이 1인 행의 수를 반환하세요.
    // std::ranges::count_if + std::ranges::a
    return (int)std::ranges::count_if(board, is_full);
}

void remove_full_lines() {
    // TODO: 완성된 행을 제거하고, 제거된 수만큼 빈 행을 위에 삽입하세요.
    // std::erase_if(board, is_full) + board.insert(board.begin(), removed, ...) 사용 권장
    int cols = board.empty() ? 0 : (int)board[0].size();
    int removed = (int)std::erase_if(board, is_full);
    board.insert(board.begin(), removed, std::vector<int>(cols, 0));
}

std::vector<int> get_heights() {
    // TODO: 각 열에서 블록이 쌓인 높이를 반환하세요.
    // views::iota(0, cols) | views::transform([&](int c){ ranges::find_if ... })
    //   | ranges::to<std::vector>()
    int rows = (int)board.size();
    int cols = board.empty() ? 0 : (int)board[0].size();

    return std::views::iota(0, cols)
        | std::views::transform([&](int c) {
            auto it = std::ranges::find_if(board, [c](const std::vector<int>& row) {
                return row[c] == 1;
            });
            if (it == board.end()) return 0;
            return rows - (int)(it - board.begin());
        })
        | std::ranges::to<std::vector>();
}

int count_empty() {
    // TODO: 보드 전체에서 빈 칸(0)의 수를 반환하세요.
    // ranges::fold_left(board | views::transform([](auto& row){ ranges::count(row, 0); }), 0, plus{})
    return (int)std::ranges::fold_left(
        board | std::views::transform([](const auto& row) {
            return (int)std::ranges::count(row, 0);
        }),
        0,
        std::plus{}
    );
}
