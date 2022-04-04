#pragma once
#include<opencv2/opencv.hpp>
#include <iostream>
#include <cmath>

using namespace cv;     //OpenCV2 - Computer Vision
using namespace std;    //std::

Mat defaultBorders(Mat IMAGE) { //выделение границ оператором Робертса без MPI
    int first, second, result, p1, p2, p3, p4;
    int x, y;
    for (x = 0; x < IMAGE.rows - 1; x++) {          //Все циклы длиной = размер - 1 пикс.
        for (y = 0; y < IMAGE.cols - 1; y++) {
            p1 = IMAGE.at<uchar>(x, y);             // A = x     , y
            p2 = IMAGE.at<uchar>(x + 1, y + 1);     // B = x + 1 , y + 1
            p3 = IMAGE.at<uchar>(x + 1, y);         // C = x + 1 , y
            p4 = IMAGE.at<uchar>(x, y + 1);         // D = x     , y + 1
            first = p1 - p2;                                                 // I  = A - B
            second = p3 - p4;                                                // II = C - D
            result = sqrt(pow(first, 2) + pow(second, 2));                   // Результирующий пиксель: R = (I^2 + II^2)^1/2;
            IMAGE.at<uchar>(x, y) = result;                                  // Запись в пиксель
        }
    }
    return IMAGE; //возврат матрицы
}