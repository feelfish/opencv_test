#include <iostream>
#include <opencv2/opencv.hpp>

extern cv::Mat imgSource;
extern cv::Mat bgrSplit[3];

extern cv::Mat blueMat;
extern int blueUpThresh;
extern int blueLowThresh;

extern cv::Mat redMat;
extern int redUpThresh;
extern int redLowThresh;

extern cv::Point2i leftUp;
extern cv::Point2i rightDown;

void blueThreshBar(int,void*);
void redThreshBar(int,void*);
void selectRect(int,int,int,int,void*);
