#include <netpbm/pgm.h>
#include <chrono>
#include <cstdio>
#include <iostream>
#include <thread>

namespace {
void imageDescription(const std::string &name, int width, int height,
                      int maxValues) {
    std::cout << "Image: " << name << std::endl;
    std::cout << "Width: " << width << " Height: " << height << std::endl;
    std::cout << "Image max values: " << maxValues << std::endl << std::endl;
}

void lapaceMaskProcessingInfo() {
    std::cout << "Image processing - laplace Mask..." << std::endl << std::endl;
}

void laplaceMask(gray **sourceImage, gray **outputImage, int width, int heigth) {
    // lapaceMaskProcessingInfo();
    for (int i = 1; i < heigth - 1; ++i) {
        for (int j = 1; j < width - 1; ++j) {
            outputImage[i][j] = static_cast<float>(sourceImage[i - 1][j] +
                                                   sourceImage[i + 1][j] +
                                                   sourceImage[i][j - 1] +
                                                   sourceImage[i][j + 1]) -
                                4 * sourceImage[i][j];

            outputImage[i][j] =
                static_cast<int>((outputImage[i][j] + 288) * 0.44f);
        }
    }
}
}  // namespace

int main(int argc, char **argv) {
    const std::string inputImageFilePath = "foto01.pgm";
    const std::string outputImageFilePath = "output.pgm";
    FILE *sourceFileHandler = fopen(inputImageFilePath.c_str(), "r");

    int columns = 0;
    int rows = 0;
    gray maxValues;

    gray **inputImage =
        pgm_readpgm(sourceFileHandler, &columns, &rows, &maxValues);
    // imageDescription(inputImageFilePath, columns, rows, maxValues);

    gray **outputImage = pgm_allocarray(columns, rows);
    auto start = std::chrono::system_clock::now();
    laplaceMask(inputImage, outputImage, columns, rows);
    auto stop = std::chrono::system_clock::now();
    std::chrono::duration<double> timeElapsed = stop - start;
    std::cout << timeElapsed.count() << std::endl;

    // imageDescription(outputImageFilePath, columns, rows, maxValues);

    FILE *outputImageFileHandler = fopen(outputImageFilePath.c_str(), "wb");
    pgm_writepgm(outputImageFileHandler, outputImage, columns, rows, maxValues,
                 1);

    fclose(sourceFileHandler);
    fclose(outputImageFileHandler);

    return 0;
}