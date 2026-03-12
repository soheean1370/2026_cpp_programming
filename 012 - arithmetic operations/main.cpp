# include <iostream>
#include <iomanip>

int main(){
    float a, b;
    /** 5.00 + 3.00 = 8.00
        5.00 - 3.00 = 2.00
        5.00 * 3.00 = 15.00
        5.00 / 3.00 = 1.67 */

    std::cin >> a >> b;
    std::cout << std::fixed << std::setprecision(2); // 소수점 2자리까지 고정
    std::cout << a << " + " << b << " = " << a + b << std::endl;
    std::cout << a << " - " << b << " = " << a - b << std::endl;
    std::cout << a << " * " << b << " = " << a * b << std::endl;
    std::cout << a << " / " << b << " = " << a / b << std::endl;

    
    return 0;
}