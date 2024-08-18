#include "image_processor.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>


void compressImage(const std::string& inputPath, const std::string& outputPath, int quality)
{
    cv::Mat image = cv::imread(inputPath, cv::IMREAD_UNCHANGED);
    if (image.empty())
    {
        std::cerr << "Error Loading Image: " << inputPath << std::endl;
        return;
    }
    std::vector<int> compression_params;
    if (outputPath.find(".jpg") != std::string::npos || outputPath.find(".jpeg") != std::string::npos)
    {
        compression_params.push_back(cv::IMWRITE_JPEG_QUALITY);
        compression_params.push_back(quality);
    }
    else if (outputPath.find(".png") != std::string::npos)
    {
        compression_params.push_back(cv::IMWRITE_PNG_COMPRESSION);
        compression_params.push_back(quality / 10);
    }

    bool sucess = cv::imwrite(outputPath, image, compression_params);
    if (sucess)
    {
        std::cout << "Image was sucessful comprimed in: " << outputPath << std::endl;
    }
    else
    {
        std::cerr << "Error saving image in: " << outputPath << std::endl;
    }
}

void convertImageFormat(const std::string& inputPath, const std::string& outputPath)
{
    cv::Mat image = cv::imread(inputPath, cv::IMREAD_UNCHANGED);
    if (image.empty())
    {
        std::cerr << "Error loading image: " << inputPath << std::endl;
        return;
    }

    bool sucess = cv::imwrite(outputPath, image);
    if (sucess)
    {
        std::cout << "Converted image saved in: " << outputPath << std::endl;
    }
    else
    {
        std::cerr << "Error trying to convert image: " << outputPath << std::endl;
    }
}