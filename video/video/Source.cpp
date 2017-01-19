#include <opencv2\opencv.hpp>
using namespace cv;

int main() {
	//读入视频
	VideoCapture capture;
	capture.open(0);//读取摄像头
	//capture.open("test.mp4");//读取视频

	//循环显示每一帧
	while (1) {
		Mat frame;//定义一个Mat变量，用于存储每一帧图像
		capture >> frame;//读取当前帧
		imshow("读取视频", frame);//显示
		waitKey(30);//延时30ms
	}
	return 0;
}