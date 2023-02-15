#pragma once

#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/xphoto/white_balance.hpp>

enum WBTYPE
{
    SIMPLE,
    GRAYWORLD,
    LEARNINGBASED
};

class WhiteBalance
{
public:
    void whiteBalance(cv::Mat &img, int type = 1);
};