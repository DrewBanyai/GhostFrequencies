//  INTERNAL Generic Values
#define FRAME_MILLISECONDS 333

//  INTERNAL variables
unsigned long startTime = 0;
unsigned long millisOffset = 0;

//  INTERNAL methods
inline unsigned long FrameMillis() { return millis() - millisOffset; }

//  EXTERNAL variables
unsigned long nextFrameMillis = 0;

//  EXTERNAL methods
inline bool IsNextFrameReady() { return (FrameMillis() >= nextFrameMillis); }
inline void UpdateMillisOffset() { millisOffset = millis(); nextFrameMillis = 0; }
inline int GetFrame(int animationLength) { return (((FrameMillis() - startTime) / FRAME_MILLISECONDS) % animationLength); }
inline int GetFrame(int animationLength, int frameMillis) { return (((FrameMillis() - startTime) / frameMillis) % animationLength); }