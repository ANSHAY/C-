#pragma once

#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/xphoto/white_balance.hpp>

#include "whiteBalance.h"
#include "brightnessCorrection.h"
#include "demosaicing.h"

class ISP
{
    Demosaicing dm;
    WhiteBalance wb;
    BrightnessCorrection bc;

public:
    cv::Mat readRaw(std::string filename, int height, int width, int bayer_format = cv::COLOR_BayerRG2BGR);
    void demosaic(cv::Mat &img, cv::Mat &img_out, int code = 0);
    void scaleImage(cv::Mat &img);
    void whiteBalance(cv::Mat &img, int type = 2, double perentile = 0.05);
    void brightnessCorrection(cv::Mat &img, double alpha = 1.0, double beta = 0.0, double gamma = 1.0);
};