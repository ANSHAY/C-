#pragma once

#include <argparse/argparse.hpp>
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/xphoto/white_balance.hpp>

void parseArgs(argparse::ArgumentParser &program, int argc, char **argv);

std::string fileName(std::string const &path);

std::string removeExtension(std::string const &filename);
