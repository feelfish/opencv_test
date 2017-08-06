#ifndef PATHFINDER_H
#define PATHFINDER_H

#include<iostream>
#include<vector>
#include<opencv2/opencv.hpp>
class obstObj{
 obstObj(std::vector<cv::Point2i>& pointList);
public:
 int centerX = 0;
 int centerY = 0;
 std::vector<cv::Point2i> obstContour;
};

void gate(std::vector<cv::Point2i> &contour0,std::vector<cv::Point2i>& contour1,int width);

#endif // PATHFINDER_H
