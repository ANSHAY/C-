#include "whiteBalance.h"

void WhiteBalance::whiteBalance(cv::Mat &img, int type)
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
    default:
        std::cout << "WARNING: INCORRECT White Balance Algo type!\nUsing GrayWorld instead.";
        wb = cv::xphoto::createGrayworldWB();

        break;
    }
    wb->balanceWhite(img, img);
}
