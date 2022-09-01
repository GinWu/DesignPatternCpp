#include <iostream>
#include <string>
#include <ctime>

using namespace std;
class User {
public:
    User(string name): _name(name) {}
    void setName(string name) {
        _name = name;
    }

    string getName() {
        return _name;
    }

    void sendMessage(string message);

private:
    string _name;
}; 

class ChatRoom {
public:
    static void showMessage(string message, User user) {
        time_t now = time(0);
        cout << ctime(&now) << " [" << user.getName() << "] " \
             << message << endl;
    }
};

void User::sendMessage(string message) {
        ChatRoom::showMessage(message, *this);
};

int main() {
    User tom("Tom");
    User mike("Mike");
    tom.sendMessage("Hi Mike!");
    mike.sendMessage("Hi Tom, how are you?");
    system("pause");
    return 0;
};