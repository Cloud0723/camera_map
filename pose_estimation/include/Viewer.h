#ifndef VIEWER_H
#define VIEWER_H

#include "Drawer.h"
#include <mutex>

class Viewer
{
public:
    Viewer();
    void Run();
    void RequestFinish();
    void RequestStop();
    bool isFinished();
    bool isStopped();
    void Release();
    void clear();
    Drawer mDrawer;
private:
    bool Stop();
    // 1/fps in ms
    double mT;
    float mImageWidth, mImageHeight;
    float mViewpointX, mViewpointY, mViewpointZ, mViewpointF;
    bool CheckFinish();
    void SetFinish();
    bool mbFinishRequested;
    bool mbFinished;
    std::mutex mMutexFinish;
    bool mbStopped;
    bool mbStopRequested;
    std::mutex mMutexStop;
};

#endif // VIEWER_H
