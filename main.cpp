#include "main.h"
#include <chrono>
#include <sys/time.h>

using namespace cv;
using namespace std;
using namespace chrono;

const int imgWidth = 640;
const int imgHeight = 480;


Mat imgSource;
Mat bgrSplit[3];
Mat grayImg;
Mat splitDiff;
bool chooseFlag = false;

int main()
{
        //string TrackbarWindow = "TrackbarWindow";
        //namedWindow(TrackbarWindow,WINDOW_AUTOSIZE);
        // createTrackbar("BlueBarL",TrackbarWindow,&blueLowThresh,255,blueThreshBar);
        // createTrackbar("BlueBarU",TrackbarWindow,&blueUpThresh,255,blueThreshBar);
        // createTrackbar("RedBarL",TrackbarWindow,&redLowThresh,255,redThreshBar);
        // createTrackbar("RedBarH",TrackbarWindow,&redUpThresh,255,redThreshBar);
        string CamWindow = "CamWindow";
        namedWindow(CamWindow,WINDOW_AUTOSIZE);
        VideoCapture cap(0);
        cap.open(0);

         //cap>>imgSource;
         //cap.set(CV_CAP_PROP_FOURCC,CV_FOURCC('M','J','P','G'));
        cap.set(CV_CAP_PROP_FRAME_WIDTH,imgWidth);
        cap.set(CV_CAP_PROP_FRAME_HEIGHT,imgHeight);
        //cap.set(CV_CAP_PROP_BRIGHTNESS,0.45);

        Rect selRect(0,0,0,0);
        while(1){
            cap>>imgSource;
            if(!imgSource.empty()){             
                vector<KeyPoint> keyPoints;
                split(imgSource,bgrSplit);
                splitDiff = bgrSplit[2] - bgrSplit[0];
                //cvtColor(imgSource,grayImg,CV_BGR2GRAY);
                //equalizeHist(grayImg,grayImg);

                struct timeval start, end;
                long mtime, seconds, useconds;

                //auto start = std::chrono::high_resolution_clock::now();
                gettimeofday(&start, NULL);
                findLights(imgSource);
                gettimeofday(&end, NULL);
                seconds  = end.tv_sec  - start.tv_sec;
                useconds = end.tv_usec - start.tv_usec;
                mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
                printf("Elapsed time: %ld milliseconds\n", mtime);
                //auto end   = std::chrono::high_resolution_clock::now();
                //auto duration = duration_cast<microseconds>(end - start);
                //std::chrono::duration<double> diff = end-start;
                //std::cout << " ints : " << diff.count() * 1000 << " ms\n";
                //imgSource.copyTo(temp,BGRSplit[0]);
                //imshow(CamWindow,temp);
                imshow(CamWindow,imgSource);
            }
            if(27==waitKey(30))
            {   cout<<"User EXIT"<<endl;
                break;
            }
        }
        return 0;
}
