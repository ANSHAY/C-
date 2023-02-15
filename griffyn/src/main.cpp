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
    // std::string of = program.get("output_directory") + "/" + "in/" + output_file;
    // cv::imwrite(output_file + "in.png", img);

    isp.scaleImage(img);
    // of = program.get("output_directory") + "/" + "scaled/" + output_file;
    // cv::imwrite(output_file + "sc.png", img);

    cv::Mat img_out(height, width, CV_8UC3);

    // Demosaic the image
    isp.demosaic(img, img_out, cv::COLOR_BayerRG2BGR);
    cv::cvtColor(img_out, img_out, cv::COLOR_RGB2BGR);

    // of = program.get("output_directory") + "/" + "dem/" + output_file;
    // cv::imwrite(output_file + "de.png", img_out);

    // of = program.get("output_directory") + "/" + "rgb/" + output_file;
    // cv::imwrite(output_file + "rgb.png", img_out);

    // Apply white balance
    isp.whiteBalance(img_out);
    // of = program.get("output_directory") + "/" + "wb/" + output_file;
    // cv::imwrite(output_file + "wb.png", img_out);

    // adjust gammam and brightness
    isp.brightnessCorrection(img_out, 4.0, -150, 1.7);
    // of = program.get("output_directory") + "/" + "gc/" + output_file;
    // cv::imwrite(output_file + "gc.png", img_out);
    // brightnessCorrection(img_out, 4.0, -150);
    // of = program.get("output_directory") + "/" + "bc/" + output_file;
    // cv::imwrite(output_file + "bc.png", img_out);

    // save output image
    cv::imwrite(output_file, img_out);
    return 0;
}
