#include "image_processor.hpp"
#include <iostream>
#include <string.h>



int main(int argc, char **argv)
{
    if (strcmp(argv[1], "-compress") == 0)
    {
        if (argc != 5)
        {
            std::cerr << "required three extra args" << std::endl;
            return 1;
        }
        std::string inputPath = argv[2];
        std::string outputPath = argv[3];
        int quality = std::stoi(argv[4]);
        compressImage(inputPath, outputPath, quality);
    }
    else if (strcmp(argv[1], "-chformat") == 0)
    {
        if (argc != 4)
        {
            std::cerr << "required two extra arguments" << std::endl;
            return 1;
        }
        std::string inputPath = argv[2];
        std::string outputPath = argv[3];
        convertImageFormat(inputPath, outputPath);
    }
    else if (strcmp(argv[1], "-help") == 0)
    {
        std::cout << "Compress command: ImageManager -compress <input_image> <output_image> <quality>" << std::endl;
        std::cout << "Change format command: ImageManager -chformat <input_image> <output_image>" << std::endl;
    }
    else
    {
        std::cerr << "The arg: '" << argv[1] << "' is not recognised" << std::endl;
        return 1;
    }
}