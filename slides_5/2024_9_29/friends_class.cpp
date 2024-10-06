#include <iostream>
using namespace std;

class TV {
private:
    int volume;  // TV的音量（私有成员）
    bool isOn;   // TV的开关状态（私有成员）

public:
    TV() : volume(10), isOn(false) {}  // 初始化TV，音量为10，默认关闭

    void displayStatus() {
        cout << "TV is " << (isOn ? "On" : "Off") << " and volume is " << volume << endl;
    }

    // 将RemoteControl类声明为友元类
    friend class RemoteControl;
};

class RemoteControl {
public:
    // 通过RemoteControl打开TV
    void powerOn(TV& tv) {
        tv.isOn = true;
        cout << "RemoteControl: TV is now On." << endl;
    }

    // 通过RemoteControl调整TV音量
    void increaseVolume(TV& tv) {
        if (tv.isOn) {
            tv.volume += 1;
            cout << "RemoteControl: Volume increased to " << tv.volume << endl;
        } else {
            cout << "RemoteControl: TV is Off. Cannot change volume." << endl;
        }
    }

    // 通过RemoteControl调低音量
    void decreaseVolume(TV& tv) {
        if (tv.isOn) {
            tv.volume -= 1;
            cout << "RemoteControl: Volume decreased to " << tv.volume << endl;
        } else {
            cout << "RemoteControl: TV is Off. Cannot change volume." << endl;
        }
    }

    // 通过RemoteControl关闭TV
    void powerOff(TV& tv) {
        tv.isOn = false;
        cout << "RemoteControl: TV is now Off." << endl;
    }
};

int main() {
    TV myTV;
    RemoteControl myRemote;

    // 显示TV初始状态
    myTV.displayStatus();

    // 使用RemoteControl打开TV并调整音量
    myRemote.powerOn(myTV);
    myRemote.increaseVolume(myTV);
    myRemote.increaseVolume(myTV);
    myTV.displayStatus();

    // 调低音量并关闭TV
    myRemote.decreaseVolume(myTV);
    myRemote.powerOff(myTV);
    myTV.displayStatus();

    return 0;
}
