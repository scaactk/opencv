#include<opencv2/opencv.hpp>
using namespace cv;

int main() {
	VideoCapture capture;
	capture.open(0);
	Mat edges;

	while (1) {
		//load Image
		Mat frame;
		capture >> frame;

		//change Image to gray

		//opencv2：
		//cvtColor(frame, edges, CV_BGR2GRAY);

		//opencv3:
		cvtColor(frame, edges, COLOR_BGR2GRAY);

		//使用3x3内核来降噪（2*3+1=7）
		blur(edges, edges, Size(7, 7));//进行模糊

		//进行canny边缘检测并显示
		Canny(edges, edges, 0, 30, 3);
		imshow("show", edges);
		if (waitKey(1000) >= 0) {
			break;//延时1s
		}
	}
}