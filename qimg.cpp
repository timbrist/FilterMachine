#include "qimg.h"
//======QImg.cpp===========
void QImg::Mat2QImage(cv::Mat _src, QImage &_dst)
{

    switch(_src.channels())
    {
        case 3:
            cv::cvtColor(_src,_src,CV_BGR2RGB);
            _dst= QImage(static_cast<uchar*>( _src.data ),
                             _src.cols,
                             _src.rows,
                             static_cast<int>(_src.step),
                             QImage::Format_RGB888);
            break;
        case 4:
            _dst= QImage(static_cast<uchar*>( _src.data ),
                             _src.cols,
                             _src.rows,
                             QImage::Format_ARGB32);
            break;
        default:
            _dst = QImage( _src.cols, _src.rows , QImage::Format_Indexed8);
            uchar *matdata = _src.data;
            for(int y = 0; y < _src.rows; y++)
            {
                uchar *rowdata = _dst.scanLine(y);
                memcpy(rowdata, matdata, static_cast<size_t>( _src.cols));
            }
            break;
     }
}
QImage QImg::FilterMachine(QString &img_path, int type)
{
    if(!img_path.isEmpty())
    {
        this->src = cv::imread(img_path.toStdString());
    }
    else {
        throw "img_path is empty";
    }

    switch(type)
    {
    case 0:
        cv::GaussianBlur(this->src, this->dst,cv::Size(11,11),0);
        break;
    case 1:
        cv::medianBlur(this->src, this->dst, 3);
        break;
    default:
        cv::medianBlur(this->src, this->dst, 3);
        break;
    }


    if(!this->dst.empty())
    {
        qst = dst.clone();
        Mat2QImage(this->qst, qimg);
     }
    else {
        throw "dst failed";
    }
    return qimg;
}
bool QImg::SaveImage(QString &img_path)
{
    if(!this->dst.empty() && !img_path.isEmpty())
    {
        imwrite(img_path.toStdString(), this->dst);
        return true;
    }
    else {
        return false;
    }
}
