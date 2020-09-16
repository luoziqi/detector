#pragma once
#include<opencv2/opencv.hpp>
#include <iostream>
#include<vector>

#ifndef DETECTOR_H
#define DETECTOR_H

class Detector
{
private:
    cv::Mat _img;
    std::vector<cv::Point> _points;

public:
    void set_img(cv::Mat& img);
    std::vector<cv::Point> detect();
    void print();
};

#endif // DETECTOR_H
