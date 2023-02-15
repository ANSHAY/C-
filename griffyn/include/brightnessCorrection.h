#pragma once

#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/xphoto/white_balance.hpp>

class BrightnessCorrection
{
public:
    void gammaCorrection(cv::Mat &img, double gamma = 1.0);

    void brightnessCorrection(cv::Mat &img, double alpha = 1.0, double beta = 0.0);
};