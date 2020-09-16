#include"detector.h"

int main()
{
      cv::Mat img = cv::imread("F:/task.jpg");
      Detector detector;
      detector.set_img(img);
      detector.detect();
      detector.print();

      return 0;
}
