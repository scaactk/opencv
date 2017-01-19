#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;
#define WINDOW_NAME "线性混合示例" //为窗口标题定义的宏

//全局变量声明部分
const int g_nMaxAlphaValue = 100;//alpha最大值
int g_nAlphaValueSlider;//滑动条对应的变量
double g_dAlphaValue;
double g_dBetaValue;

//声明存储图像的变量
Mat g_srcImage1;
Mat g_srcImage2;
Mat g_dstImage;

//on_Trackbar()函数
//响应滑动条的回调函数

void on_Trackbar(int, void *) {
	//求出当前Alphac值相当于最大值的比例
	g_dAlphaValue = (double)g_nAlphaValueSlider / g_nMaxAlphaValue;

	//beta为1减去alpha
	g_dBetaValue = (1.0 - g_dAlphaValue);
	

	//根据alpha和beta值进行线性运算
	addWeighted(g_srcImage1, g_dAlphaValue, g_srcImage2, g_dBetaValue, 0.0, g_dstImage);

	//显示效果图
	imshow(WINDOW_NAME, g_dstImage);
}

int main(int argc, char** argv){

	//加载图像（两图像尺寸需要相同）
	g_srcImage1 = imread("a.jpg");
	g_srcImage2 = imread("b.jpg");

	if (!g_srcImage1.data) {
		printf("读取第一张图失败\n");
		return -1;
	}
	if (!g_srcImage2.data) {
		printf("读取第二张图片失败\n");
		return -1;
	}

	//设置滑动条初值为100
	g_nAlphaValueSlider = 100;

	//创建窗体
	namedWindow(WINDOW_NAME, 1);

	//在窗口中创建一个滑动条控件
	char TrackBarName[50];
	sprintf(TrackBarName, "透明值 %d", g_nAlphaValueSlider);

	createTrackbar(TrackBarName, WINDOW_NAME, &g_nAlphaValueSlider, g_nMaxAlphaValue, on_Trackbar);

	//结果在回调函数中显示
	on_Trackbar(g_nAlphaValueSlider, 0);
	
	waitKey(0);
	return 0;
}