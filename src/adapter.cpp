#include <iostream>
#include <string>


using namespace std;


class AdvancedMediaPlayer {
public:
    virtual void playVlc(string mediaType, string mediaName) = 0;
    virtual void playMp4(string mediaType, string mediaName) = 0;
    virtual ~AdvancedMediaPlayer() {};
};

class VlcPlayer: public AdvancedMediaPlayer {
public:
    void playVlc(string mediaType, string mediaName) {cout << "play [type: " << mediaType << ", name: " << mediaName << "]" << endl;};
    void playMp4(string mediaType, string mediaName) {
    }
};

class Mp4Player: public AdvancedMediaPlayer {
public:
    void playVlc(string mediaType, string mediaName) {
    }
    void playMp4(string mediaType, string mediaName) {
        cout << "play [type: " << mediaType << ", name: " << mediaName << "]" << endl;
    }

};

class MediaPlayer {
public:
    virtual void play(string mediaType, string mediaName) = 0;
    virtual ~MediaPlayer() {};
};

class MediaAdapter: public MediaPlayer {
public:
    void play(string mediaType, string mediaName) {
        if (mediaType == "vlc") {
            advancedMediaPlayer = new VlcPlayer;
            if (advancedMediaPlayer != nullptr) {
                advancedMediaPlayer->playVlc(mediaType, mediaName);
            }
            
        } else if (mediaType == "mp4") {
            advancedMediaPlayer = new Mp4Player;  
            if (advancedMediaPlayer != nullptr) {
                advancedMediaPlayer->playMp4(mediaType, mediaName);
            }   
        }
        if (advancedMediaPlayer == nullptr) {
            cout << "[ERROR] video [type: " << mediaType << ", name: " << mediaName << "] played failed.\n";
        } else {
            delete advancedMediaPlayer;
            advancedMediaPlayer = nullptr;
        }
        
    }

    ~MediaAdapter() {
        delete advancedMediaPlayer;
        advancedMediaPlayer = nullptr;
    }
private:
    AdvancedMediaPlayer* advancedMediaPlayer = nullptr;
};

class AudioPlayer: public MediaPlayer {
public:
    void play(string mediaType, string mediaName) {\
        if (mediaType == "mp3") {
            cout << "play [type: " << mediaType << ", name: " << mediaName << "]" << endl;
        } else if (mediaType == "mp4" || mediaType == "vlc") {
            mediaAdapter.play(mediaType, mediaName);
        }
    }
private:
    MediaAdapter mediaAdapter;
};


int main() {
    // cout << "prepare to play 你是我的玫瑰花" << endl;
    AudioPlayer audioPlayer;
    string mediaName = "heartbeats";
    string mediaType = "mp5";
    audioPlayer.play(mediaType, mediaName);
    system("pause");
    return 0;
}
 
