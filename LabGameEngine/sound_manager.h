#pragma once

#include "PesAudioWrapper.h"

#define N_AUDIO_CHANNEL 10

class SoundManager{
public:

    enum SOUNDS : char {
        FIRE,
        DANGER,
        EXPLOSION,
        ATMOSPHERE
    };

    enum PLAYMODE : char {
        ONESHOT,
        LOOP
    };

    enum AUDIOIMPL : char {
        FMOD = PAW_IMPL::PAW_FMOD,
        OPENAL = PAW_IMPL::PAW_OPENAL
    };

    ~SoundManager();
    static SoundManager * GetInstance();
    void Init(AUDIOIMPL impl = FMOD, unsigned int nChannels = N_AUDIO_CHANNEL);
    void PlaySound(SOUNDS sound, PLAYMODE mode = ONESHOT);
    //void StopLoopSound();
    void Update();
    void Shutdown();
private:
    SoundManager();
    void PreloadAllSound();
    static SoundManager * instance;
    char * soundFiles[6] = {
        "D:/AudioAsset/Gun+Silencer.wav",
        "D:/AudioAsset/Industrial-Alarm.wav",
        "D:/AudioAsset/explosion.wav",
        "D:/AudioAsset/drumloop.wav"
    };
    
    bool isPlaying;
};

