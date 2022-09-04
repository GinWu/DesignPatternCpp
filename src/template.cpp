#include <iostream>
#include <string>

using namespace std;


class Game {
public:
    virtual void initialize() = 0;
    virtual void startPlay() = 0;
    virtual void endPlay() = 0;
    void play() {
        // initialize game
        initialize();
        // start playing
        startPlay();
        // end playing
        endPlay();
    } 
    virtual ~Game() {}
};


class Cricket: public Game {
public:
    void initialize() {
        cout << "Cricket Game Initialized! Start playing." << endl;
    }

    void startPlay() {
        cout << "Cricket Game Started. Enjoy the game!" << endl;
    }

    void endPlay() {
        cout << "Cricket Game Finished! Byebye~" << endl;
    }
};

class Football: public Game {
public:
    void initialize() {
        cout << "Football Game Initialized! Start playing." << endl;
    }

    void startPlay() {
        cout << "Football Game Started. Enjoy the game!" << endl;
    }

    void endPlay() {
        cout << "Football Game Finished! Byebye~" << endl;
    }
};

int main() {
    Game* cricket = new Cricket;
    Game* football = new Football;

    cricket->play();
    football->play();

    delete cricket;
    delete football;
    cricket = nullptr;
    football = nullptr;

    system("pause");
    return 0;
}