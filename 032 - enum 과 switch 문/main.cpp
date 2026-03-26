# include <iostream>

using namespace std;

enum class TrafficLight{
    Red=0,
    Yellow=1,
    Green=2,
};

int main(){
    int code;
    cin >> code;

    const auto light = static_cast<TrafficLight>(code);

    switch(light){
        // TODO: Red 이면 STOP, Yellow 이면 READY, Green 이면 GO 를 출력하세요.
        // TODO: 그 외 값은 UNKNOWN 을 출력
        case TrafficLight::Red:
            cout << "STOP";
            break;
        case TrafficLight::Yellow:
            cout << "READY";
            break;
        case TrafficLight::Green:
            cout << "GO";
            break;
        default:
            cout << "UNKNOWN";
    }
    return 0;
}