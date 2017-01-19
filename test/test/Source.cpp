#include<opencv2\highgui\highgui.hpp>//opencv highgui模块头文件
#include<opencv2\imgproc\imgproc.hpp>//图像处理头文件
using namespace cv;

int main()
{
	//载入原图
	Mat srcImage = imread("a.jpg");

	//显示原图
	imshow("原图", srcImage);

	//腐蚀操作
	Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
	Mat dstImage;
	erode(srcImage, dstImage, element);

	//显示效果
	imshow("效果图：腐蚀操作", dstImage);
	waitKey(0);
}
