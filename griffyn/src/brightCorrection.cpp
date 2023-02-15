#include "brightnessCorrection.h"

void BrightnessCorrection::gammaCorrection(cv::Mat &img, double gamma)
{
    if (abs(gamma) < 0.001)
        gamma = 0.001;
    double invG = 1 / gamma;
    uint8_t table[256];
    for (auto i = 0; i < 256; i++)
    {
        table[i] = cv::saturate_cast<uint8_t>(pow((float)(i / 255.0), invG) * 255.0f);
    }
    cv::MatIterator_<cv::Vec3b> it, end;
    for (it = img.begin<cv::Vec3b>(), end = img.end<cv::Vec3b>(); it != end; ++it)
    {
        (*it)[0] = table[(*it)[0]];
        (*it)[1] = table[(*it)[1]];
        (*it)[2] = table[(*it)[2]];
    }
}

void BrightnessCorrection::brightnessCorrection(cv::Mat &img, double alpha, double beta)
{
    img = alpha * img + beta;
    img.setTo(0, img < 0);
    img.setTo(255, img > 255);
}