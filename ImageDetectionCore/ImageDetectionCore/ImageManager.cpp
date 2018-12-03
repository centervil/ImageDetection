#include "ImageManager.h"

using namespace cv;

CImageManager::CImageManager()
{
}

CImageManager::CImageManager(wstring path)
{
	vImage_.clear();
	LoadImages(path, L"jpg");
	LoadImages(path, L"jpeg");
	LoadImages(path, L"png");
	LoadImages(path, L"bmp");
	LoadImages(path, L"tiff");
}

CImageManager::CImageManager(wstring path, wstring extension)
{
	vImage_.clear();
	LoadImages(path, extension);
}

CImageManager::~CImageManager()
{
}

void CImageManager::LoadImages(wstring path, wstring extension)
{
	//path‚ÌêŠ‚Ì‰æ‘œƒtƒ@ƒCƒ‹‚ğ“Ç‚İ‚Ş
	std::vector<std::wstring> vFilePath = CUtil::get_file_path_in_dir(path.c_str(), extension.c_str());

	for (unsigned int i = 0; i < vFilePath.size(); i++) {
		wstring pathStr = path + L"\\" + vFilePath.at(i);
		Mat img = imread(CUtil::ConvertToString(pathStr));
		tagImage imageInfo = { vFilePath.at(i), img };
		vImage_.push_back(imageInfo);
	}
}

void CImageManager::ConvertIntoGrayscale()
{
	for (unsigned int i = 0; i < vImage_.size(); i++) {
		cvtColor(vImage_.at(i).img, vImage_.at(i).img, CV_BGR2GRAY);
	}
}

void CImageManager::ShowMatImage(Mat img, const string &windowName, const int waitTimeMs, const double scale)
{
	Mat resizeImg;
	resize(img, resizeImg, Size(), scale, scale);

	const char *window = windowName.c_str();

	cv::namedWindow(window, CV_WINDOW_AUTOSIZE);
	cv::imshow(window, resizeImg);
	cv::waitKey(1);
	Sleep(waitTimeMs);
	cv::destroyWindow(window);
}
