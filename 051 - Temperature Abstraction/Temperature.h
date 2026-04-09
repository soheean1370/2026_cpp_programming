#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <string>

enum class Scale { // enum 클래스 명시적
    Celsius,
    Fahrenheit
};

class Temperature { // 클래스 선언만 해두고 구현은 Temperature.cpp에서
public: // 클래스 밖에서 접근이 가능
    Temperature(double temp, Scale scale = Scale::Celsius);// default값을 정해줄 수 있다
    Temperature add(const Temperature& other) const;
    std::string print() const;

private: // 밖에서 접근이 불가능
    double temperature; // 만약 const라면 초기화 이후 변경이 불가능하지만, 현재는 Temperature 객체가 불변이므로 const로 선언하지 않아도 됩니다.
    Scale scale; // const면 바꾸고 싶어도 바꿀 수 없다

    double toCelsius() const;
    double toFahrenheit() const;
};

#endif // TEMPERATURE_H
