#pragma once
#include "ImageManager.h"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <vector>

using namespace std;

#define OPTION_DEMO		L"-d"
#define OPTION_SAVE		L"-w"
#define OPTION_SHOW		L"-s"

typedef struct {
	wstring fileName;
	int count;
}tagResult;

class CAnalyzeModel
{
public:
	explicit CAnalyzeModel(const wstring &srcPath, const wstring &tempPath, const wstring &savePath, const wstring &option);
	virtual ~CAnalyzeModel();

	CImageManager *pSrcImgManager_;
	CImageManager *pTempImgManager_;
	vector<tagResult> vResults_;
	wstring srcFolderPath_;
	wstring tempFolderPath_;
	wstring saveFolderPath_;
	bool isDemoMode_;
	bool isSaveImg_;
	bool isShowResultImg_;

	void AnalyzeAllImages(void);
	void ShowResult(void);
#ifndef _TEST
private:
#endif // !_TEST
	void AnalyzeAndSetResult(Mat src, /*Mat temp,*/ wstring fileName);
	int Analyze(Mat bin, Mat color, Mat temp);
	int Analyze(Mat bin, Mat temp);
	Mat ConvertBin(Mat color);
	void SetResult(const int &count, const wstring &fileName);
	void SaveResult(Mat colorResult, const wstring &filePath);
	void CheckOption(const wstring &option);
};

