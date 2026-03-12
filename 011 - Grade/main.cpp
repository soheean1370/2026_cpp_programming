#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

int main() {
    int studentCount = 0;
    std::cin >> studentCount;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int sum = 0;
    std::string highest_name;
    int higest_score = -1;
    int average;

    for (int i = 0; i < studentCount; i++) {
        std::string name;
        int score;

        std::cin >> name >> score;
        sum += score;

        if (score > higest_score) {
            higest_score = score;
            highest_name = name;
        }
    }

    average = (double)sum / studentCount;

    std::cout << "Average: " << std::fixed << std::setprecision(2) << average << std::endl;
    std::cout << "Highest: " << highest_name << " " << higest_score << std::endl;
}