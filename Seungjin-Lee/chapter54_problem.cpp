#include <iostream>
#include <string>
using namespace std;
// 1. class의 함수들과 생성자를 쓰기 위해 해야하는 한 가지 작업이 있다. 해당 작업을 하시오.
class TV {
    string company;
    bool power;
    int channel;
    int volume;

    
    
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

    // 2.파워 on/off 설정할 수 있는 함수를 만드시오(입력 _power에 따라 bool power 수정; true: on, false: off)
    void setPower(bool _power) {
        
    }

    // 3.볼륨 설정을 할 수 있는 함수를 만드시오(0~100이 아닐 경우에는 false, 0~100인 경우 true return)
    bool setVolume(int _volume) {

    }

    // 4.채널을 설정할 수 있는 함수를 만드시오(0~1000이 아닐 경우에는 동작x, 작업이 성공적으로 끝났을 경우 true return 아니면 false return)
    bool setChannel(int _channel) {

    }
};

int main() {
    string tvcompany;
    cin >> tvcompany;
    TV tv(tvcompany);
    while(true) {
        bool _power;
        cout << "tv의 전원을 어떻게 하시겠습니까? (on: true, off: false)" << endl;
        while(true) {
            try{
                cin >> _power;
                break;
            } catch(int exceptioncode) {
                cout << "제대로 되지 않은 입력입니다. 다시 입력해주세요(on: true, off: false)." << endl;
                cout << "Error code: " << exceptioncode << endl;
            }
        }
        tv.setPower(_power);
        
        cout << "Volume 크기를 설정하시오(0~100)" << endl;
        while(!tv.setVolume()) {
            cout << "Volume 크기를 0~100 사이로 설정하세요" << endl;
        }

        while(!tv.setChannel()) {
            cout << "Channel을 0~1000 사이로 설정하세요" << endl;
        }

        cout << "---------------------------------------------------------------------------------" << endl;
        cout << "현재 tv 상태는 다음과 같습니다." << endl;
        tv.showCompany();
        tv.showPower();
        tv.showVolume();
        tv.showChannel();
        string status;
        cout << "종료하려면 exit, 계속 하려면 아무거나 입력하세요" << endl;
        cin >> status;
        if (status == "exit") break;
    }
	return 0;
}