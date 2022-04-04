#include <iostream>

#include "mpi.h"
#include "imgProcessing.h"
#include "opencv2/opencv.hpp"

using namespace cv;

int main(int argc, char** argv)
{
    Mat image, new_image;
    uchar* sector_data;
    size_t full_size, sector_size;
    int channels;
    /////////////////////////////////////
    int size, rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    /////////////////////////////////////
    if (rank == 0)
    {
        image = imread("img/123.bmp", IMREAD_UNCHANGED); //load grayscale image

        if (image.empty()) //get empty image error
        {
            std::cout << "(err) Image has not been loaded!" << std::endl;
            return -1;
        }

        channels = image.channels(); //get channels number
        full_size = image.step[0] * image.rows; //get full matrix size
        
        if (image.total() % size) //get sector size error
        { //image.total() == image.rows * image.cols
            std::cout << "(err) Cannot evenly divide the image." << std::endl;
            return -2;
        }

        sector_size = full_size / size; //get sector size
        std::cout << "Dividing image into " << sector_size << " byte sectors" << std::endl;

        // broadcast sector size and channels number from #0 to other processes
        MPI_Bcast(&sector_size, 1, MPI_UNSIGNED_LONG_LONG, 0, MPI_COMM_WORLD);
        MPI_Bcast(&channels, 1, MPI_INT, 0, MPI_COMM_WORLD);
        MPI_Barrier(MPI_COMM_WORLD); //wait for all processes to get sizes

        sector_data = new uchar[sector_size]; //init the sector data buffer
        MPI_Barrier(MPI_COMM_WORLD); //wait for all processes to initialize their buffer

        // scatter image between processes
        MPI_Scatter(image.data, sector_size, MPI_UNSIGNED_CHAR, sector_data, sector_size, MPI_UNSIGNED_CHAR, 0, MPI_COMM_WORLD);
        MPI_Barrier(MPI_COMM_WORLD); // wait for all processes to get their own image sector
        
        //after all of thi is done, each process will have their own image sector, now we can work on image processing
        //image is divided by rows (thats how it's stored in the memory)
        //sector_data buffer contains a sequence of (B, G, R) values

        for (size_t i = 0; i < sector_size; i += channels)
        {
            // get the pixel:
            uchar* B = &sector_data[i];
            uchar* G = &sector_data[i + 1];
            uchar* R = &sector_data[i + 2];

            *B = 255; 
            *G = 255;
            *R = 0;
        }
        MPI_Barrier(MPI_COMM_WORLD);    // wait for all the processes to be done with image processing


        if (rank == 0)
        {
            new_image = cv::Mat(image.size(), image.type()); //init the output image
        }
        //get the scattered info back, but this time it's been processed
        MPI_Gather(sector_data, sector_size, MPI_UNSIGNED_CHAR, new_image.data, sector_size, MPI_UNSIGNED_CHAR, 0, MPI_COMM_WORLD);

        if (rank == 0)
        {
            // save the image:
            imwrite("img/new_image.jpg", new_image);
            destroyAllWindows();
        }
        delete[] sector_data;
        MPI_Finalize();
    }
























    /////////////////////////////////////
    MPI_Finalize();
}