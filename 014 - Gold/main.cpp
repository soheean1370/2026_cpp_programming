#include <iomanip>
#include <iostream>

int main() {
    const int baseGold = 1000;
    int minionGold = 0;
    std::cin >> minionGold;

    // TODO: Calculate totalGold and averageGold, then print the final status based on totalGold >= 4000.
    int totalGold = baseGold + minionGold;
    double averageGold = totalGold / 2;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Total Gold: " << totalGold << "\n";
    std::cout << "Average Gold: " << averageGold << "\n";

    if (totalGold >= 4000){
        std::cout << "Item Purchase Available\n";
    } else {
        std::cout << "More Gold Needed\n";
    }
    return 0;
}
