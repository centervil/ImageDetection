#include "AnalyzeModel.h"
#include <iostream>

using namespace cv;

CAnalyzeModel::CAnalyzeModel(const wstring & srcPath, const wstring & tempPath, const wstring & savePath, const wstring &option)
	:srcFolderPath_(srcPath),
	tempFolderPath_(tempPath),
	saveFolderPath_(savePath),
	pSrcImgManager_(nullptr),
	pTempImgManager_(nullptr),
	isDemoMode_(false),
	isShowResultImg_(false),
	isSaveImg_(false)
{
	pSrcImgManager_ = new CImageManager(srcPath);
	pTempImgManager_ = new CImageManager(tempPath);
	CheckOption(option);
}

CAnalyzeModel::~CAnalyzeModel()
{
	if (nullptr != pSrcImgManager_) {
		delete pSrcImgManager_;
		pSrcImgManager_ = nullptr;
	}
	if (nullptr != pTempImgManager_) {
		delete pTempImgManager_;
		pTempImgManager_ = nullptr;
	}
}

void CAnalyzeModel::AnalyzeAllImages(void)
{
	for (unsigned int i = 0;i < pSrcImgManager_->GetImages().size();i++) {
		Mat srcImg = pSrcImgManager_->GetImages().at(i).img.clone();
		wstring fname = pSrcImgManager_->GetImages().at(i).fileName;
		if (isDemoMode_ ) CImageManager::ShowMatImage(srcImg, "source", 5000, 0.5);
		AnalyzeAndSetResult(srcImg, fname);
		if (isSaveImg_) SaveResult(srcImg, fname);
	}
}

void CAnalyzeModel::ShowResult(void)
{
	for (unsigned int i = 0;i < vResults_.size();i++) {
		cout << vResults_.at(i).count << " : " << CUtil::ConvertToString(vResults_.at(i).fileName).c_str() << endl;
	}
}

void CAnalyzeModel::AnalyzeAndSetResult(Mat src, /*Mat temp,*/ wstring fileName)
{
	Mat binSrc = ConvertBin(src).clone();
	tagResult resultInfo = { fileName, 0 };

	for (unsigned int j = 0; j < pTempImgManager_->GetImages().size(); j++) {
		Mat tmpImg = pTempImgManager_->GetImages().at(j).img.clone();
		Mat binTmp = ConvertBin(tmpImg).clone();
		if (isDemoMode_) CImageManager::ShowMatImage(tmpImg, "template", 5000, 1.0);
		resultInfo.count += Analyze(binSrc, src, binTmp);
	}

	vResults_.push_back(resultInfo);
}

int CAnalyzeModel::Analyze(Mat bin, Mat color, Mat temp)
{
	int count = 0;
	Mat result;
	vector<Point> detectedPoint;
	float threshold = 0.90f;

	matchTemplate(bin, temp, result, CV_TM_CCOEFF_NORMED);

	if(isDemoMode_) CImageManager::ShowMatImage(color, "matchingResult", 2000, 0.5);

	for (int y = 0; y < result.rows; y++) {
		for (int x = 0; x < result.cols; x++) {
			if (result.at<float>(y, x) > threshold) {
				detectedPoint.push_back(Point(x, y));
			}
		}
	}

	count = (int)detectedPoint.size();

	for (int i = 0;i < count;i++) {
		Point LeftTop = detectedPoint.at(i);
		Point RightBottom = Point(LeftTop.x + temp.cols, LeftTop.y + temp.rows);
		rectangle(color, LeftTop, RightBottom, Scalar(0, 0, 255), 2, 8, 0); //Œ³‰æ‘œ‚ÌŒŸo‰ÓŠ‚ðÔ˜g‚ÅˆÍ‚Þ
		rectangle(bin, LeftTop, RightBottom, Scalar(255, 255, 255), -1, CV_AA); //“ñ’l‰»‰æ‘œ‚ÌŒŸo‰ÓŠ‚ð“h‚è‚Â‚Ô‚·
	}

	if (isDemoMode_ || isShowResultImg_) CImageManager::ShowMatImage(color, "Result", 2000, 0.5);
	if (isDemoMode_ || isShowResultImg_) CImageManager::ShowMatImage(bin, "bin", 2000, 0.5);

	return count;
}

Mat CAnalyzeModel::ConvertBin(Mat color)
{
	Mat binImg;
	cvtColor(color, binImg, CV_BGR2GRAY); //gray
	threshold(binImg, binImg, 0, 255, THRESH_BINARY | THRESH_OTSU); //bin
	return binImg;
}

void CAnalyzeModel::SaveResult(Mat colorResult, const wstring & filePath)
{
	wstring fullPath = saveFolderPath_ + L"\\" + filePath;
	imwrite(WSTR2STR(fullPath), colorResult);
}

void CAnalyzeModel::CheckOption(const wstring & option)
{
	if (-1 != option.find(OPTION_DEMO)) isDemoMode_ = true;
	if (-1 != option.find(OPTION_SAVE)) isSaveImg_ = true;
	if (-1 != option.find(OPTION_SHOW)) isShowResultImg_ = true;
}
