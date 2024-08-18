#ifndef IMAGE_PROCESSOR_HPP
#define IMAGE_PROCESSOR_HPP

#include <iostream>
#include <string.h>


void compressImage(const std::string& inputPath, const std::string& outputPath, int quality);
void convertImageFormat(const std::string& inputPath, const std::string& outputPath);


#endif //IMAGE_PROCESSOR_HPP