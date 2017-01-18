#include "sound_manager.h"

SoundManager* SoundManager::instance = nullptr;

SoundManager::SoundManager() {
    isPlaying = false;
}

void SoundManager::PreloadAllSound() {
    PAW::loadOneShotSound(soundFiles[SOUNDS::FIRE]);
    PAW::loadOneShotSound(soundFiles[SOUNDS::DANGER]);
    PAW::loadOneShotSound(soundFiles[SOUNDS::EXPLOSION]);
    PAW::loadStreamSound(soundFiles[SOUNDS::ATMOSPHERE]);
}


SoundManager::~SoundManager() {}

SoundManager * SoundManager::GetInstance() {
    if (SoundManager::instance == nullptr)
        SoundManager::instance = new SoundManager();
    return SoundManager::instance;
}

void SoundManager::Init(AUDIOIMPL impl, unsigned int nChannels) {
    PAW::init(nChannels, (PAW_IMPL)impl);
    PreloadAllSound();
}

void SoundManager::PlaySound(SOUNDS sound, PLAYMODE mode) {
    if (mode == PLAYMODE::ONESHOT) {
        bool res = PAW::playSound(soundFiles[sound]);
    } else if (mode == PLAYMODE::LOOP) {
        PAW::loadStreamSound(soundFiles[sound]);
    }
}

void SoundManager::Update() {
    isPlaying = PAW::isPlayingSomething();
    if(isPlaying) {
        PAW::update();
    }
}

void SoundManager::Shutdown() {
    PAW::shutdown();
}
