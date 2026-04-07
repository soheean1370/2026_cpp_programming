#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int score;
};
bool compare(const Student& a, const Student& b) {
        if (a.score != b.score) return a.score > b.score;
        return a.name < b.name;
    }
int main() {
    int n;
    std::cin >> n;

    std::vector<Student> students(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> students[i].name >> students[i].score;
    }

    std::vector<Student> qualified;
    int index = 0;

    // TODO: while 문으로 students를 검사하며 90점 이상인 학생만 qualified에 넣으세요.
    while(index < students.size()){
        if(students[index].score >= 90){
            qualified.push_back(students[index]);
        }
        index++;
    }
    // TODO: qualified를 점수 내림차순, 이름 오름차순으로 정렬하세요.
    // 사용
    std::sort(qualified.begin(), qualified.end(), compare);

    // TODO: qualified가 비어 있으면 None을 출력하고, 아니면 앞에서부터 최대 3명의 이름을 출력하세요.
    if (qualified.empty()) {
        std::cout << "None\n";
    } else {
        size_t maxOutput = std::min(qualified.size(), size_t(3));
        for(size_t i = 0; i < maxOutput; ++i) {
            std::cout << qualified[i].name << "\n";
        }
    }
    // TODO: 필요하면 std::sort 또는 std::ranges::sort를 사용할 수 있습니다.

    return 0;
}
