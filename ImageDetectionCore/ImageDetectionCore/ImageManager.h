#pragma once
#include "CUtil.h"
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

typedef struct {
	wstring fileName;
	Mat img;
}tagImage;

class CImageManager
{
public:
	CImageManager();
	CImageManager(wstring path);
	CImageManager(wstring path, wstring extension);
	~CImageManager();

	void ConvertIntoGrayscale();
	static void ShowMatImage(Mat img, const string &windowName, const int waitTimeMs, const double scale);
	const vector<tagImage> &GetImages(void) { return vImage_;	}

#ifndef _TEST
private:
#endif // !_TEST
	vector<tagImage> vImage_;
	wstring folderPath_;
	void LoadImages(wstring path, wstring extension);
};
