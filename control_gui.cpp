#include "control_gui.h"

using namespace cv;

Mat blueMat;
Mat redMat;

int blueLowThresh = 0;
int blueUpThresh = 0;

int redLowThresh = 0;
int redUpThresh = 0;

Point2i leftUp(-1,-1);
Point2i rightDown(-1,-1);

void blueThreshBar(int, void*){
    inRange(bgrSplit[0],Scalar(blueLowThresh,0,0),Scalar(blueUpThresh,255,255),blueMat);
    imshow("blueThreshed",blueMat);
}

void redThreshBar(int,void*){
    inRange(bgrSplit[2],Scalar(0,0,redLowThresh),Scalar(255,255,redUpThresh),redMat);
    imshow("redThreshed",redMat);
}

void selectRect(int event,int x,int y,int flags, void* para){
	if (CV_EVENT_LBUTTONDOWN == event){
		leftUp.x = x;
		leftUp.y = y;
	}
	if(CV_EVENT_LBUTTONUP == event){
		rightDown.x = x;
		rightDown.y = y;
	}

}
