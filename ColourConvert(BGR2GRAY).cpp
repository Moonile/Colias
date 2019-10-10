#include<opencv2/opencv.hpp>
#include<iostream>
#include<opencv2/imgproc/types_c.h>
using namespace cv;
using namespace std;

void main() {
	VideoCapture cap;
	cap.open("2.mp4");// capture video in the source file
	Size size0 = Size(cap.get(CAP_PROP_FRAME_WIDTH), cap.get(CAP_PROP_FRAME_HEIGHT)); //define width and height 
	VideoWriter writer("out2.mp4", -1, cap.get(CAP_PROP_FPS), size0, false); //video writer properties

	if (!cap.isOpened())   //null video then break
		return;

	Mat frame;
	while (1)
	{
		cap >> frame; 
		cvtColor(frame, frame, CV_BGR2GRAY);// convert BGR2GRAY
		if (frame.empty())//stop when empty
			break; 
		writer << frame; 
		imshow("video", frame); //show the gray video
		if (waitKey(42) > 0)
			break;
	}
	cout << "write end!";
	cap.release();
	destroyAllWindows();
}