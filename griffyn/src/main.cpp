#include <iostream>

#include "utils.h"
#include "isp.h"

int main(int argc, char **argv)
{
    std::cout << "ISP Assignment for Griffyn\n\n";
    argparse::ArgumentParser program("g_isp");
    parseArgs(program, argc, argv);

    int height = std::stoi(program.get(std::string("height"))), width = std::stoi(program.get(std::string("width")));
    std::string file_path = program.get("input_file_path");
    std::string output_file = program.get("output_directory") + "/" + removeExtension(fileName(file_path)) + ".png";

    cv::Mat img;

    ISP isp;

    // Read raw image
    img = isp.readRaw(file_path, height, width);
    if (img.empty())
    {
        std::cout << "Could not read the image at: " << file_path << std::endl;
        return 1;
    }

    isp.scaleImage(img);

    cv::Mat img_out(height, width, CV_8UC3);

    // Demosaic the image
    isp.demosaic(img, img_out, cv::COLOR_BayerRG2BGR);

    // Apply white balance
    isp.whiteBalance(img_out);

    // adjust gammam and brightness
    isp.brightnessCorrection(img_out, 4.0, -150, 1.7);

    // save output image
    cv::imwrite(output_file, img_out);
    return 0;
}
