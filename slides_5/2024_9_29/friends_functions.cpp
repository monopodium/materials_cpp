#include <iostream>
using namespace std;

class TV; // 
class RemoteControl {
public:
    // 通过RemoteControl打开TV
    void powerOn(TV &tv);

    // 通过RemoteControl增加TV音量
    void increaseVolume(TV &tv);

    // 通过RemoteControl尝试降低TV音量，但不是友元函数，无法访问TV的私有成员
    void decreaseVolume(TV& tv) {
        // 无法访问tv.volume，因为此函数不是TV类的友元函数
        cout << "RemoteControl: Cannot access TV's volume directly." << endl;
    }
};
class TV {
private:
    int volume;  // TV的音量（私有成员）
    bool isOn;   // TV的开关状态（私有成员）

public:
    TV() : volume(10), isOn(false) {}  // 初始化TV，音量为10，默认关闭

    void displayStatus() const {
        cout << "TV is " << (isOn ? "On" : "Off") << " and volume is " << volume << endl;
    }
    //这个时候编译器要看到这两个友元函数的declaration
    // 将RemoteControl的特定函数声明为友元函数
    friend void RemoteControl::powerOn(TV& tv);       // 只允许RemoteControl的powerOn访问TV的私有成员
    friend void RemoteControl::increaseVolume(TV& tv); // 只允许RemoteControl的increaseVolume访问TV的私有成员
};

inline void RemoteControl::powerOn(TV &tv){
        tv.isOn = true;
        cout << "RemoteControl: TV is now On." << endl;
}

void RemoteControl::increaseVolume(TV& tv) {
    if (tv.isOn) {
        tv.volume += 1;
        cout << "RemoteControl: Volume increased to " << tv.volume << endl;
    } else {
        cout << "RemoteControl: TV is Off. Cannot change volume." << endl;
    }
}

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

    // 尝试通过RemoteControl调低音量（无权访问私有成员）
    myRemote.decreaseVolume(myTV);

    return 0;
}
