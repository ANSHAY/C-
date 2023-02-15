#include <iostream>

#include "utils.h"
#include "isp.h"

int main(int argc, char **argv)
{
    std::cout << "ISP Assignment for Griffyn\n\n";
    argparse::ArgumentParser program("g_isp");
    parseArgs(program, argc, argv);

    std::string file_path = program.get("input_file_path");
    std::string output_file = program.get("output_directory") + "/" + removeExtension(fileName(file_path)) + ".png";
    std::string config_file_path = program.get("config_file_path");

    // read config
    Json::Value config = readConfig(config_file_path);
    int height = config["img"]["height"].asInt();
    int width = config["img"]["width"].asInt();

    if (auto fn = program.present("--height"))
    {
        height = std::stoi(*fn);
    }
    if (auto fn = program.present("--width"))
    {
        width = std::stoi(*fn);
    }

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
    int wbtype = config["wb"]["type"].asInt();
    double percentile = config["wb"]["percentile"].asDouble();
    isp.whiteBalance(img_out, wbtype, percentile);

    // adjust gammam and brightness
    double alpha = config["bc"]["alpha"].asDouble();
    double beta = config["bc"]["beta"].asDouble();
    double gamma = config["bc"]["gamma"].asDouble();
    isp.brightnessCorrection(img_out, 4.0, -150, 1.7);

    // save output image
    cv::imwrite(output_file, img_out);
    return 0;
}
