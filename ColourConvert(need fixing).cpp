#include <opencv2/opencv.hpp>
#include<iostream>
#include<opencv2/imgproc/types_c.h>

using namespace cv;


int main() {
	VideoCapture cap;
	cap.open("P:\\videos\\1.mp4");//Capture webcam or a video

	Mat frame;
	Size size0 = Size(cap.get(CAP_PROP_FRAME_WIDTH), cap.get(CAP_PROP_FRAME_HEIGHT));
	//int width = cap.get(CAP_PROP_FRAME_WIDTH);
	//int height = cap.get(CAP_PROP_FRAME_HEIGHT);
	//int framerate = cap.get(CAP_PROP_FPS);
	//int totalrate = cap.get(CAP_PROP_FRAME_COUNT);
	//std::cout << "width.=" << width << std::endl;
	//std::cout << "height=" << height << std::endl;
	//std::cout << "franerate=" << framerate<< std::endl;
	//std::cout << "rates=" << totalrate<< std::endl;
	VideoWriter writer("P:\\videos\\out1.mp4", -1, cap.get(CAP_PROP_FPS), size0, false);
	if (!cap.isOpened())
		return;
	while (1) {
		cap >> frame;
		cvtColor(frame, frame, CV_BGR2GRAY);
		if (frame.empty())
			break;
		writer << frame;
		imshow("videos", frame);
		if (waitKey(41) >= 0)
			break;
		//)waitKey(41.7);
	}
	std::cout << "write successfully";
	cap.release();
	destroyAllWindows();

}
