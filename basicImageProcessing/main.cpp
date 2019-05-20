#include <iostream>
#include <string>
#include <opencv2/core/core.hpp>			//core library for reading writing
#include <opencv2/highgui/highgui.hpp>		//for displaying 
#include <opencv2/imgproc/imgproc.hpp>		//mostly for image proceesing


using namespace std;
using namespace cv;


int main() {

	//Reading image
	Mat img;
	img = imread("coins-orig.jpg", IMREAD_COLOR);
	//img = imread("C:\\Users\\mimtiaz\\visualStudio17Projects\\getMeHired\\computerVision\\standredImages\\fruits.png", IMREAD_COLOR);

	if (!img.data) {
		printf("There is no image to load\n");
		return 0;
	}
	else {
		printf("Successfully load the image\n");
	}

	//Some attributes of Mat
	printf("Number of Rows::: %d\n", img.rows);
	printf("Number of Cols::: %d\n", img.cols);
	printf("Number of Dims::: %d\n", img.dims);

	//Displying image
	string windowName = "Display loaded image";
	namedWindow(windowName,WINDOW_AUTOSIZE);
	imshow(windowName, img);
	//waitKey();

	//Mat channel[3];
	//split(img, channel);
	//windowName = "B channel";
	//namedWindow(windowName, WINDOW_AUTOSIZE);
	//imshow(windowName, channel[0]);

	//windowName = "G channel";
	//namedWindow(windowName, WINDOW_AUTOSIZE);
	//imshow(windowName, channel[1]);

	//windowName = "R channel";
	//namedWindow(windowName, WINDOW_AUTOSIZE);
	//imshow(windowName, channel[2]);


	//writing image
	string writeName = "saved_HappyFish.png";
	imwrite(writeName, img);

	//Processing
	//RGB to Gray
	Mat grayImg(img.rows, img.cols, CV_8UC1);
	//Mat processImg;
	cvtColor(img, grayImg, COLOR_BGR2GRAY);

	//writing image
	writeName = "saved_gray.png";
	imwrite(writeName, grayImg);

	//Displying image
	windowName = "Gray image";
	namedWindow(windowName, WINDOW_AUTOSIZE);
	imshow(windowName, grayImg);

	//Mat labImg;
	//cvtColor(img, labImg, COLOR_BGR2Lab);

	////Displying image
	//windowName = "LAB image";
	//namedWindow(windowName, WINDOW_AUTOSIZE);
	//imshow(windowName, labImg);

	//Mat hsvImg;
	//cvtColor(img, hsvImg, COLOR_BGR2HSV);

	////Displying image
	//windowName = "HSV image";
	//namedWindow(windowName, WINDOW_AUTOSIZE);
	//imshow(windowName, hsvImg);


	//Mat channelHSV[3];
	//split(hsvImg, channelHSV);
	//windowName = "H channel";
	//namedWindow(windowName, WINDOW_AUTOSIZE);
	//imshow(windowName, channelHSV[0]);

	//windowName = "S channel";
	//namedWindow(windowName, WINDOW_AUTOSIZE);
	//imshow(windowName, channelHSV[1]);

	//windowName = "V channel";
	//namedWindow(windowName, WINDOW_AUTOSIZE);
	//imshow(windowName, channelHSV[2]);


	Mat binaryimg;
	int thresh = 120;
	threshold(grayImg, binaryimg, thresh, 255, THRESH_BINARY_INV);
	//threshold(grayImg, binaryimg, thresh, 255, THRESH_BINARY);
	//Displying image
	windowName = "Binary image";
	namedWindow(windowName, WINDOW_AUTOSIZE);
	imshow(windowName, binaryimg);

	Mat binaryimg1;
	adaptiveThreshold(grayImg, binaryimg1, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV,7,0);
	//Displying image
	windowName = "Adaptive Binary image";
	namedWindow(windowName, WINDOW_AUTOSIZE);
	imshow(windowName, binaryimg1);

	Mat maskImg = Mat::zeros(img.rows,img.cols,CV_8UC3);
	//Mat maskImg = Mat::zeros(img.rows, img.cols, CV_8UC1);
	img.copyTo(maskImg, binaryimg);
	windowName = "Mask image";
	namedWindow(windowName, WINDOW_AUTOSIZE);
	imshow(windowName, maskImg);

	waitKey();
	return 1;
}
