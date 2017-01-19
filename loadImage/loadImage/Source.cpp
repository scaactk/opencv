#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;

int main() {
	//载入图像和显示
	Mat girl = imread("a.jpg");
	namedWindow("人像图片");
	imshow("人像图片", girl);

	//图像混合
	Mat image = imread("test.jpg", 4);
	Mat logo = imread("test2.jpg");

	//显示
	namedWindow("原图");
	imshow("原图", image);

	namedWindow("logo");
	imshow("logo", logo);
	
	//定义一个Mat类型，用于存放图像的ROI
	Mat imageROI;

	//方法一
	imageROI = image(Rect(200, 50, logo.cols, logo.rows));

	//方法二
	//imageROI = image(Range(350, 350 + logo.rows), Range(800, 800 + logo.cols));

	//将logo加到原图上
	addWeighted(imageROI, 0.1, logo, 0.5, 0., imageROI);

	//显示结果
	namedWindow("原画+logo图");
	imshow("原画+logo", image);

	//图像的输出
	//将一个MAt图像输出到文件
	imwrite("生成图.jpg", image);
	waitKey();
	return 0;
}