#include "demosaicing.h"

void Demosaicing::bleed(cv::Mat &img, int channel, uchar val, int r, int c)
{
    img.at<cv::Vec3b>(r, c)[channel] = val;
    val = val >> 1;
    if (r < height - 1)
        img.at<cv::Vec3b>(r + 1, c)[channel] += val;
    if (r > 0)
        img.at<cv::Vec3b>(r - 1, c)[channel] += val;
    if (c < width - 1)
        img.at<cv::Vec3b>(r, c + 1)[channel] += val;
    if (c > 0)
        img.at<cv::Vec3b>(r, c - 1)[channel] += val;
    val = val >> 1;
    if (r < height - 1)
    {
        if (c < width - 1)
            img.at<cv::Vec3b>(r + 1, c + 1)[channel] += val;
        if (c > 0)
            img.at<cv::Vec3b>(r + 1, c - 1)[channel] += val;
    }
    if (r > 0)
    {
        if (c < width - 1)
            img.at<cv::Vec3b>(r - 1, c + 1)[channel] += val;
        if (c > 0)
            img.at<cv::Vec3b>(r - 1, c + 1)[channel] += val;
    }
}

void Demosaicing::fillInnerMat(cv::Mat &img, cv::Mat &img_out, int channel, int start)
{
    int height = img.rows, width = img.cols;

    for (int r = start; r < height; r += 2)
    {
        for (int c = start; c < width; c += 2)
        {
            uchar val = img.at<uchar>(r, c);
            bleed(img_out, channel, val, r, c);
        }
    }
}

uchar Demosaicing::avg(cv::Mat &img, int r, int c)
{
    int val = 0, count = 0;
    if (r > 0)
    {
        val += img.at<uchar>(r - 1, c);
        count++;
    }
    if (r < height - 1)
    {
        val += img.at<uchar>(r + 1, c);
        count++;
    }
    if (c > 0)
    {
        val += img.at<uchar>(r, c - 1);
        count++;
    }
    if (c < width - 1)
    {
        val += img.at<uchar>(r, c + 1);
        count++;
    }
    return (uchar)(val / count);
}

void Demosaicing::fillInnerMatInv(cv::Mat &img, cv::Mat &img_out, int channel, int start)
{

    for (int r = start; r < height; r += 2)
    {
        for (int c = start; c < width; c += 2)
        {
            img_out.at<cv::Vec3b>(r, c)[channel] = avg(img, r, c);
            if (c < width - 1)
                img_out.at<cv::Vec3b>(r, c + 1)[channel] = img.at<uchar>(r, c + 1);
            if (r < height - 1)
                img_out.at<cv::Vec3b>(r + 1, c)[channel] = img.at<uchar>(r + 1, c);
        }
    }
}

void Demosaicing::demosaic(cv::Mat &img, cv::Mat &img_out)
{
    height = img.rows;
    width = img.cols;

    // blue
    fillInnerMat(img, img_out, 0, 1);
    // fillBoundary(img, img_out, 0, true);

    // red
    fillInnerMat(img, img_out, 2, 0);
    // fillBoundary(img, img_out, 2, false);

    // green
    fillInnerMatInv(img, img_out, 1, 1);
    fillInnerMatInv(img, img_out, 1, 0);
    // fillBoundary(img, img_out, 1, false);
    // fillBoundary(img, img_out, 1, true);
}

void Demosaicing::demosaicCV(cv::Mat &img, cv::Mat &img_out, int code)
{
    cv::demosaicing(img, img_out, code); // Perform demosaicing process
}
