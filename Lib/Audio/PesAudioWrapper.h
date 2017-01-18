#pragma once

#include <string>

#define DLL_EXPORT __declspec(dllexport)

enum PAW_IMPL : char {
    PAW_FMOD,
    PAW_OPENAL //TODO
};


extern "C" {


    class AudioInterface {
    public:
        virtual bool init(int _NChannels) = 0;
        virtual bool loadStatic(char * _filename) = 0;
        virtual bool loadStreamSound(char * _filename, bool _enableLoop) = 0;
        virtual bool removeSound(char * _filename) = 0;
        virtual bool play(char * _filename) = 0;
        virtual bool pause(char * _filename) = 0;
        virtual bool stop(char * _filename) = 0;
        virtual bool update() = 0;
        virtual bool isPlaying(char * _filename) = 0;
        virtual bool isPlayingSomething() = 0;
        virtual bool shutdown() = 0;
        virtual ~AudioInterface() {};
    private:

    };


    class DLL_EXPORT PesAudioWrapper {
    public:

        static bool init(int _NChannels, PAW_IMPL = PAW_IMPL::PAW_FMOD);
        static bool loadOneShotSound(char * _filename);
        static bool loadStreamSound(char * _filename, bool _enableLoop = true);
        static bool removeSound(char * _filename);
        static bool playSound(char * _filename);
        static bool pauseSound(char * _filename);
        static bool stopSound(char * _filename);
        static bool update();
        static bool isPlaying(char * _filename);
        static bool isPlayingSomething();
        static bool shutdown();
        ~PesAudioWrapper();
    private:
        PesAudioWrapper();
        static PAW_IMPL m_eCurrImpl;
        static AudioInterface * m_oAudioInterface;
    };
}

//using PAW = PesAudioWrapper; C++11
typedef PesAudioWrapper PAW;