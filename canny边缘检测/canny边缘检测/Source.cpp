#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;

int main() {
	Mat srcImage;
	srcImage = imread("a.jpg");
	imshow("原始图:canny边缘检测",srcImage);

	Mat edge, grayImage;

	//将原图转换为灰度图像
	cvtColor(srcImage, grayImage, CV_BGR2GRAY);

	//利用3x3内核来降噪
	blur(grayImage, edge, Size(3, 3));

	//运行Canny算子
	Canny(edge, edge, 3, 9, 3);

	//显示效果
	imshow("效果：Canny边缘检测", edge);

	waitKey(0);
}