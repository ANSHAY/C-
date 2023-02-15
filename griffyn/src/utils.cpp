#include <utils.h>

void parseArgs(argparse::ArgumentParser &program, int argc, char **argv)
{
    program.add_argument("--input_file_path")
        .required()
        .help("specify the input file path.");
    program.add_argument("--output_directory")
        .required()
        .help("specify the output directory.");
    program.add_argument("--height")
        .help("specify the height of image.");
    program.add_argument("--width")
        .help("specify the width of image.");
    program.add_argument("--config_file_path")
        .required()
        .help("specify the config file path.");
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

std::string fileName(std::string const &path)
{
    return path.substr(path.find_last_of("/\\") + 1);
}

std::string removeExtension(std::string const &filename)
{
    std::string::size_type const p(filename.find_last_of('.'));
    return p > 0 && p != std::string::npos ? filename.substr(0, p) : filename;
}

Json::Value readConfig(std::string filepath)
{
    Json::Value config;
    try
    {
        std::ifstream fin(filepath);
        fin >> config;
        fin.close();
    }
    catch (...)
    {
        std::cout << "Error in reading config file: " << filepath;
        exit(0);
    }
    std::cout << "Config file read.";
    return config;
}