#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;

int main() {
	//载入原始图
	Mat srcImage = imread("a.jpg");

	//显示
	imshow("均值滤波：原图", srcImage);

	//进行均值滤波操作
	Mat dstImage;
	blur(srcImage, dstImage, Size(7, 7));

	//显示
	imshow("均值滤波：效果", dstImage);
	waitKey(0);
}