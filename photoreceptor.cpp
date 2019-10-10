#include "opencv2\opencv.hpp"
#include <opencv2\imgproc\types_c.h>

using namespace cv;
using namespace std;

void main()
{
	VideoCapture cap;
	cap.open("3.mp4");
	Size size0 = Size(cap.get(CAP_PROP_FRAME_WIDTH), cap.get(CAP_PROP_FRAME_HEIGHT)); //define width and height 
	VideoWriter writer("out3absdiff.mp4", -1, cap.get(CAP_PROP_FPS), size0, false); //video writer properties
	if (!cap.isOpened())
	{
		return ;
	}
	
	Mat framePre; /*This equals the f-1 frame in p layer*/
	Mat frameNow; /*This is the f frame*/
	Mat frameDiff; /*This is the absdiff frame, equalling to p*/
	cap>> framePre; /*Input the first frame*/
	cvtColor(framePre, framePre, CV_BGR2GRAY);/*Convert BGR2GRAY and the gray frame is the new input*/
	while (1)           /*Loop: make sure all the frames are captured and converted to gray images*/
	{
		cap >> frameNow; /*equals to i++*/
		if (frameNow.empty()) 
			break;   /*stop when video ends*/
		cvtColor(frameNow, frameNow, CV_BGR2GRAY);
		absdiff(frameNow, framePre, frameDiff);
		framePre = frameNow; /*equals to i++*/
		imshow("Difference", frameDiff); /*can be deleted if no need to preview the absdiff video*/
		/*Change this factor in order to change your output. frameNow is the gray frame so the video is gray, frameDiff is the difference between 2 frames. Make sure you change your out put name in the line 12*/
		writer << frameDiff; 
	
		if (waitKey(42) >0)
			break; 
	}
	cout:"write ends!";
	cap.release();
	destroyAllWindows();
	
}

