#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/xphoto/white_balance.hpp>
#include <argparse/argparse.hpp>

using namespace std;

void parseArgs(argparse::ArgumentParser &program, int argc, char **argv)
{
    program.add_argument("--input_file_path")
        .required()
        .help("specify the input file path.");
    program.add_argument("--output_directory")
        .required()
        .help("specify the output directory.");
    program.add_argument("--height")
        .required()
        .help("specify the height of image.");
    program.add_argument("--width")
        .required()
        .help("specify the width of image.");
    try
    {
        program.parse_args(argc, argv);
    }
    catch (const std::runtime_error &err)
    {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        std::exit(1);
    }
}

cv::Mat readRaw(std::string filename, int height, int width, int bayer_format = cv::COLOR_BayerRG2BGR)
{
    FILE *fp = NULL;
    uint16_t *imagedata = NULL;
    int framesize = height * width;

    // Open raw Bayer image.
    fp = fopen(filename.c_str(), "rb");

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

void whiteBalance(cv::Mat &img)
{
    // cv::Ptr<cv::xphoto::WhiteBalancer> wb = cv::xphoto::createSimpleWB();
    cv::Ptr<cv::xphoto::WhiteBalancer> wb = cv::xphoto::createGrayworldWB();
    // cv::Ptr<cv::xphoto::WhiteBalancer> wb = cv::xphoto::createLearningBasedWB();
    wb->balanceWhite(img, img);
}

void gammaCorrection(cv::Mat &img, double gamma = 1.0)
{
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

void brightnessCorrection(cv::Mat &img, double alpha = 1.0, double beta = 0.0)
{
    img = alpha * img + beta;
    img.setTo(0, img < 0);
    img.setTo(255, img > 255);
}

std::string fileName(std::string const &path)
{
    return path.substr(path.find_last_of("/\\") + 1);
}

std::string removeExtension(std::string const &filename)
{
    std::string::size_type const p(filename.find_last_of('.'));
    return p > 0 && p != std::string::npos ? filename.substr(0, p) : filename;
}

void scaleImage(cv::Mat &img)
{
    img = (img / (256 * 256 - 1)) * 255;
    img.convertTo(img, CV_8U);
}

int main(int argc, char **argv)
{
    std::cout << "ISP Assignment for Griffyn\n\n";
    argparse::ArgumentParser program("g_isp");
    parseArgs(program, argc, argv);

    int height = std::stoi(program.get(std::string("height"))), width = std::stoi(program.get(std::string("width")));
    std::string file_path = program.get("input_file_path");
    std::string output_file = program.get("output_directory") + "/" + removeExtension(fileName(file_path)) + ".png";

    cv::Mat img;

    // Read raw image
    img = readRaw(file_path, height, width);
    // std::string of = program.get("output_directory") + "/" + "in/" + output_file;
    // cv::imwrite(output_file + "in.png", img);

    scaleImage(img);
    // of = program.get("output_directory") + "/" + "scaled/" + output_file;
    // cv::imwrite(output_file + "sc.png", img);

    // Demosaic the image
    cv::Mat img_out(height, width, CV_8UC3);
    cv::demosaicing(img, img_out, cv::COLOR_BayerRG2BGR); // Perform demosaicing process
    cv::cvtColor(img_out, img_out, cv::COLOR_RGB2BGR);

    // of = program.get("output_directory") + "/" + "dem/" + output_file;
    // cv::imwrite(output_file + "de.png", img_out);

    // of = program.get("output_directory") + "/" + "rgb/" + output_file;
    // cv::imwrite(output_file + "rgb.png", img_out);

    // Apply white balance
    whiteBalance(img_out);
    // of = program.get("output_directory") + "/" + "wb/" + output_file;
    // cv::imwrite(output_file + "wb.png", img_out);

    // adjust gammam and brightness
    gammaCorrection(img_out, 1.7);
    // of = program.get("output_directory") + "/" + "gc/" + output_file;
    // cv::imwrite(output_file + "gc.png", img_out);
    brightnessCorrection(img_out, 4.0, -150);
    // of = program.get("output_directory") + "/" + "bc/" + output_file;
    // cv::imwrite(output_file + "bc.png", img_out);

    // save output image
    cv::imwrite(output_file, img_out);
}
