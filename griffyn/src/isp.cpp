#include "isp.h"

#include <limits>

cv::Mat ISP::readRaw(std::string filename, int height, int width, int bayer_format)
{
    FILE *fp = NULL;
    uint16_t *imagedata = NULL;
    int framesize = height * width;

    // Open raw Bayer image.
    fp = fopen(filename.c_str(), "rb");
    if (fp < 0)
    {
        // failure in reading the file
        std::cout << "Problem in reading the input file. \n Check input file path and try again.";

        fclose(fp);
        return cv::Mat();
    }
    // Memory allocation for bayer image data buffer.
    imagedata = (uint16_t *)malloc(sizeof(uint16_t) * framesize);

    // Read image data and store in buffer.
    // TODO: check if file exists
    fread(imagedata, 2, framesize, fp);

    cv::Mat src = cv::Mat(height, width, CV_16UC1, imagedata).clone();

    free(imagedata);
    fclose(fp);
    return src;
}

void ISP::scaleImage(cv::Mat &img)
{
    img = (img / (256 * 256 - 1)) * 255;
    img.convertTo(img, CV_8U);
}

void ISP::demosaic(cv::Mat &img, cv::Mat &img_out, int code)
{
    dm.demosaic(img, img_out);
}

void ISP::whiteBalance(cv::Mat &img)
{
    wb.whiteBalance(img);
}

void ISP::brightnessCorrection(cv::Mat &img, double alpha, double beta, double gamma)
{
    if (abs(gamma - 1.0) > std::numeric_limits<double>::epsilon())
    {
        bc.gammaCorrection(img, gamma);
    }
    bc.brightnessCorrection(img, alpha, beta);
}