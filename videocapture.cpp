//��������֡��֣�ȡ����ֵ��Ȼ������Ҷ�ͼ

#include<opencv2/opencv.hpp>
#include<iostream>
#include<opencv2/imgproc.hpp>

using namespace cv;


void main() {
	VideoCapture cap;
	cap.open("1.MP4");
	if (!cap.isOpened())
		return;

	Mat frame;
	while (1) {
		cap >> frame;
			if (frame.empty())
				break;

			imshow("video", frame);
		waitKey(42);
	}
	cap.release();

}