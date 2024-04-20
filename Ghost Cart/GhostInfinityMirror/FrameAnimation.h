#pragma once

class FrameAnimationManager {
  public:
    inline unsigned int GetCurrentFrameIndex(unsigned long frameLengthMillis, unsigned int animationFrameCount) { return ((GetAnimationMillisSoFar() / frameLengthMillis) % animationFrameCount); }
    
    inline bool IterateFrame(unsigned long frameLengthMillis, unsigned int animationFrameCount = 65535) {
      unsigned int currentFrame = GetCurrentFrameIndex(frameLengthMillis, animationFrameCount);

      if (LastFrameIndex < currentFrame) {
        LastFrameIndex = currentFrame;
        return true;
      }
      return false;
    }
    
    //  This should be called whenever a new animation begins
    inline void ResetAnimation() {
      AnimationStartMillis = millis();
      LastFrameIndex = 0;
    }    
  
  private:
    unsigned long AnimationStartMillis = 0;   //  The exact millis() return when the current animation started (used to determine the current frame)
    unsigned int LastFrameIndex = 0;

    inline unsigned long GetAnimationMillisSoFar() { return millis() - AnimationStartMillis; }
};








//  INTERNAL variables
unsigned long millisOffset = 0;
//  INTERNAL methods
inline unsigned long FrameMillis() { return millis() - millisOffset; }
///
///
///
//  EXTERNAL variables
unsigned long nextFrameMillis = 0;

//  EXTERNAL methods
inline bool IsNextFrameReady() { return (FrameMillis() >= nextFrameMillis); }
inline void UpdateMillisOffset() { millisOffset = millis(); nextFrameMillis = 0; }
inline int GetFrame(int animationLength, int frameMillis) { return ((FrameMillis() / frameMillis) % animationLength); }