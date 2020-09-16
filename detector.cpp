#include"detector.h"

void Detector::set_img(cv::Mat& img)
{
    this->_img = img;
}

std::vector<cv::Point> Detector::detect()
{
    std::vector<cv::Mat>bgr(this->_img.channels());
    std::vector<std::vector<cv::Point>> contours;
    cv::split(this->_img, bgr);
    cv::Mat mask;
    mask = ~(bgr[2]<20 & bgr[1]>160);
    cv::findContours(mask, contours, CV_RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
    cv::Moments mu;
    for(int i = 0; i < contours.size(); i++)
    {
        if(contours[i].size() < 50)
        {
            continue;
        }
        mu = cv::moments(contours[i]);
        this->_points.push_back(cv::Point(mu.m10/mu.m00, mu.m01/mu.m00));
    }
}

void Detector::print()
{
    for(int i = 0; i < this->_points.size(); i++)
    {
        std::cout<<this->_points[i]<<std::endl;
    }
}
