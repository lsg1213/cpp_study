#include <iostream>
#include <string>
using namespace std;

class TV {
    string company;
    bool power;
    int channel;
    int volume;

    
    public:
    TV(string _company) {
        company = _company;
        power = false;
    }
    void showCompany() {
        cout << "TV is made by " << company << endl;
    }
    void showPower() {
        string _power;
        if (power) _power = "on";
        else _power = "off";
        cout << "TV is " << _power << "now" << endl;
    }
    void showVolume() {
        cout << "Volume is " << volume << "now" << endl;
    }
    void showChannel() {
        cout << "Channel is " << channel << "now" << endl;
    }

    // 1.파워 on/off 설정할 수 있는 함수를 만들어라(작업이 성공적으로 끝났을 경우 true return 아니면 false return)
    bool setPower(bool _power) {

    }

    // 2.볼륨 설정을 할 수 있는 함수를 만들어라(0~100이 아닐 경우에는 동작x, 작업이 성공적으로 끝났을 경우 true return 아니면 false return)
    bool setVolume() {

    }

    // 3.채널을 설정할 수 있는 함수를 만들어라(0~1000이 아닐 경우에는 동작x, 작업이 성공적으로 끝났을 경우 true return 아니면 false return)
    bool setChannel() {

    }
};

int main() {
    string tvcompany;
    cin >> tvcompany;
    TV tv(tvcompany);
    
    bool _power;
    while(!tv.setPower(_power)) {
        cout << "Power를 어떻게 할껀지 제대로 쓰시오(on: true, off: false)." << endl;
        cin >> _power;
    }
    while(!tv.setVolume()) {

    }
    
    tv.showChannel();

	return 0;
}