#include "demosaicing.h"

void Demosaicing::demosaic(cv::Mat &img, cv::Mat &img_out, int code)
{
    cv::demosaicing(img, img_out, code); // Perform demosaicing process
}