#include "whiteBalance.h"

void WhiteBalance::wbPercentile(cv::Mat &img, double percentile)
{
    std::vector<cv::Mat> channels(3);
    cv::split(img, channels);
    for (int i = 0; i < 3; i++)
    {
        cv::Mat tmp;
        channels[i].reshape(1, 1).copyTo(tmp);
        cv::sort(tmp, tmp, cv::SORT_EVERY_ROW + cv::SORT_ASCENDING);
        int lowval = tmp.at<uchar>(cvFloor(((float)tmp.cols) * percentile));
        int highval = tmp.at<uchar>(cvCeil(((float)tmp.cols) * (1.0 - percentile)));

        channels[i] = ((channels[i] - lowval) * 255 / (highval - lowval));
        // saturate below the low percentile and above the high percentile
        channels[i].setTo(255, channels[i] > 255);
    }
    cv::merge(channels, img);
}

void WhiteBalance::wbHistEq(cv::Mat &img)
{
    std::vector<cv::Mat> channels(3);
    cv::split(img, channels);
    for (int i = 0; i < 3; i++)
    {
        cv::equalizeHist(channels[i], channels[i]);
    }
    cv::merge(channels, img);
}

void WhiteBalance::wbNormalSums(cv::Mat &img)
{
    std::vector<cv::Mat> channels(3);
    cv::split(img, channels);
    cv::Scalar sums = cv::sum(img);

    int maxSum = std::max(sums[0], std::max(sums[1], sums[2]));

    double gainB = (double)maxSum / sums[0];
    double gainG = (double)maxSum / sums[1];
    double gainR = (double)maxSum / sums[2];

    double maxGain = std::max(gainB, std::max(gainG, gainR));

    gainB /= maxGain;
    gainG /= maxGain;
    gainR /= maxGain;

    channels[0] = channels[0] * gainB;
    channels[1] = channels[1] * gainG;
    channels[2] = channels[2] * gainR;
    cv::merge(channels, img);
}

void WhiteBalance::whiteBalance(cv::Mat &img, int type, double percentile)
{
    cv::Ptr<cv::xphoto::WhiteBalancer> wb;
    switch (type)
    {

    case WBTYPE::SIMPLE:
        wb = cv::xphoto::createSimpleWB();
        break;
    case WBTYPE::GRAYWORLD:
        wb = cv::xphoto::createGrayworldWB();
        break;
    case WBTYPE::LEARNINGBASED:
        wb = cv::xphoto::createLearningBasedWB();
        break;
    case WBTYPE::PERCENTILE:
        wbPercentile(img, percentile);
        return;
    case WBTYPE::NORMALSUMS:
        wbNormalSums(img);
        return;
    case WBTYPE::HISTEQ:
        wbHistEq(img);
        return;
    default:
        std::cout << "WARNING: INCORRECT White Balance Algo type!\nUsing GrayWorld instead.";
        wb = cv::xphoto::createGrayworldWB();
        break;
    }
    wb->balanceWhite(img, img);
}
