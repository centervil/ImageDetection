#include <iostream>
#include "AnalyzeModel.h"

int main(int argc, char **argv)
{
	if (4 > argc) {
		cout << L"usage:countingStars.exe <sourceImageFolderPath> <templateImageFolderPath> <ResultImageFolderPath> (<option>)" << endl;
		return 0;
	}

	string srcPath(argv[1]);
	string tmpPath(argv[2]);
	string savePath(argv[3]);
	string option;
	if (4 < argc) {
		for (int i = 0; i < (argc - 4);i++) {
			option += argv[4+i];
		}
	}
	CAnalyzeModel analyzeModel(STR2WSTR(srcPath), STR2WSTR(tmpPath), STR2WSTR(savePath), STR2WSTR(option));

	analyzeModel.AnalyzeAllImages();
	analyzeModel.ShowResult();

	return 0;
}