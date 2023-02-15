#pragma once

#include <vector>

#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/xphoto/white_balance.hpp>

enum WBTYPE
{
    PERCENTILE,
    SIMPLE,
    GRAYWORLD,
    LEARNINGBASED
};

class WhiteBalance
{
public:
    void wbPercentile(cv::Mat &img, double percentile = 0.05);

    void whiteBalance(cv::Mat &img, int type = 2, double percentile = 0.5);
};