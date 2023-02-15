#pragma once

#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/xphoto/white_balance.hpp>

class Demosaicing
{
public:
    void demosaic(cv::Mat &img, cv::Mat &img_out, int code = 0); // Perform demosaicing process
};