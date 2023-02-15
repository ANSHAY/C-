#pragma once

#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/xphoto/white_balance.hpp>

class Demosaicing
{
    int height;
    int width;

public:
    void demosaicCV(cv::Mat &img, cv::Mat &img_out, int code = 0); // Perform demosaicing process
    void demosaic(cv::Mat &img, cv::Mat &img_out);

    void bleed(cv::Mat &img, int channel, uchar val, int r, int c);

    uchar avg(cv::Mat &img, int r, int c);
    void fillInnerMatInv(cv::Mat &img, cv::Mat &img_out, int channel, int start);
    void fillInnerMat(cv::Mat &img, cv::Mat &img_out, int channel, int start);
};