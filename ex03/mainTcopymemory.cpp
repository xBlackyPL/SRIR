#include <netpbm/pgm.h>
#include <chrono>
#include <cstdio>
#include <iostream>
#include <thread>
#include <vector>

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

void laplaceMask(gray **sourceImage, gray **outputImage, int width, int heigth,
                 int index, int np) {
    // lapaceMaskProcessingInfo();
    int start = index > 0 ? heigth * index : heigth * index + 1;
    int stop =
        index < np - 1 ? heigth * (index + 1) + 1 : (heigth * (index + 1));

    for (int i = start; i < stop - 1; ++i) {
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

void constructImageFromParts(gray ** outputImage, std::vector<gray**> &outputImageParts, int xAxisBound, int yAxisBound, int np) {
    int partNumber = 0;
    int partHeight = yAxisBound / np;

    std::cout << "Part height " << partHeight << std::endl;
    std::cout << "YAxisBound " << yAxisBound << std::endl;
    for(int i = 1; i < yAxisBound - 2; ++i)
    {
        if(i % partHeight == 0) {
            partNumber++;
            std::cout << "I: " << i << " part: " << partNumber<< std::endl;
        }       
        for(int j = 1; j < xAxisBound - 2; ++j)
        {
            outputImage[i][j] = outputImageParts[partNumber][i][j];
        }
 
    }
}
}  // namespace

int main(int argc, char **argv) {
    const std::string inputImageFilePath = "foto01.pgm";
    const std::string outputImageFilePath = "output.pgm";
    FILE *sourceFileHandler = fopen(inputImageFilePath.c_str(), "r");
    const int processes = 2;

    int columns = 0;
    int rows = 0;
    gray maxValues;

    gray **inputImage =
        pgm_readpgm(sourceFileHandler, &columns, &rows, &maxValues);
    // imageDescription(inputImageFilePath, columns, rows, maxValues);

    gray **outputImage = pgm_allocarray(columns, rows);

    std::vector<gray**> outputImageParts;
    std::vector<std::thread> threadPool;

    for(int i = 0; i < processes; ++i) {
        outputImageParts.push_back(pgm_allocarray(columns,rows));
    }
    
    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < processes; ++i) {
        threadPool.emplace_back(std::thread([=]() {
            laplaceMask(inputImage, outputImageParts[i], columns, rows / processes, i,
                        processes);
        }));
    }

    for (auto &&thread : threadPool) {
        thread.join();
    }
    constructImageFromParts(outputImage,outputImageParts, columns, rows, processes);
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