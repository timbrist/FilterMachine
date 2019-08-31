#ifndef QIMG_H
#define QIMG_H

#pragma once
/* C++11 -STL*/
#include <opencv2/opencv.hpp>
#include <QImage>
#include <QString>
using namespace std;
using namespace cv;

//QImg do the image operation with opencv
class QImg
{
private:
    cv::Mat src;
    cv::Mat dst;
    cv::Mat qst;
    QImage qimg;
private:
    void Mat2QImage(cv::Mat _src, QImage &_dst);
public:
    QImage FilterMachine(QString &img_path, int type);
    bool SaveImage(QString &img_path);
};

#endif // QIMG_H
