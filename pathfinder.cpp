#include"pathfinder.h"

using namespace std;
using namespace cv;

//Remember to fill the obstacles;
vector<Point2i> pointPath(Mat& map,const Point2i& startP,const Point2i& endP){
	LineIterator linePoints(map, startP, endP);//Default 8 Connected labeling
	uchar* mapP = map.data;
	for (int i = 0; i < linePoints.count; i++,++linePoints)
	{	
		if(!mapP[linePoints.pos().y * map.cols + linePoints.pos().x])
			continue;
		else{
			int tempX = linePoints.pos().x;
			int tempY = linePoints.pos().y;
			long tempPtr = tempY * map.cols + tempX; 
			unsigned char bfsQueue[30000][2];
			long lstPtr = 0;
			long curPtr = 0; curPtr++;
			bfsQueue[lstPtr][0] = tempX;
			bfsQueue[lstPtr][1] = tempY;
			int leftmost = 0; int rightmost = 9999;
			int downmost = 0; int upmost = 9999;
			while(lstPtr != curPtr){
				tempX = bfsQueue[lstPtr][0];
				tempY = bfsQueue[lstPtr][1];
				if (tempX > map.cols -2 || tempX < 2 || tempY > map.rows || tempY < 2){
					lstPtr++; 
					continue;
				}
				if (!mapP[tempPtr+1]){
					curPtr++;
					bfsQueue[curPtr][0] = tempX + 1; 
					bfsQueue[curPtr][1] = tempY;
					if (tempX + 1 > leftmost){
						leftmost = tempX + 1;
					}
				}
				if (!mapP[tempPtr-1]){
					curPtr++;
					bfsQueue[curPtr][0] = tempX - 1;
					bfsQueue[curPtr][1] = tempY;
					if ( tempX - 1 < rightmost){
						rightmost = tempX - 1;
					}
				}
				if (!mapP[tempPtr + map.cols])
				{
					curPtr++;
					bfsQueue[curPtr][0] = tempX;
					bfsQueue[curPtr][1] = tempY + 1;
					if(tempY + 1 > downmost){
						downmost = tempY + 1;
					}
				}
				if (!mapP[tempPtr - map.cols])
				{
					curPtr++;
					bfsQueue[curPtr][0] = tempX;
					bfsQueue[curPtr][1] = tempY - 1;
					if (tempY -1 < upmost){
						upmost = tempY - 1;
					}
				}
				lstPtr++;
			}
		}
	}
}

obstObj::obstObj(vector<Point2i>& pointList){
    obstContour = pointList;
    Moments obstMome = moments(pointList);
    centerX =(int) obstMome.m10 / obstMome.m00;
    centerY =(int) obstMome.m01 / obstMome.m00;
}

void gate(vector<Point2i> &contour0, vector<Point2i> &contour1,int width){

}
