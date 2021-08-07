#pragma once

#include <opencv2/opencv.hpp>

int Image(void)
{
	// 画像を格納するオブジェクトを宣言する
	cv::Mat	image;

	// 画像ファイルから画像データを読み込む
	image = cv::imread("C:\\Users\\aoi05\\source\\repos\\OpenCVtest\\OpenCVtest\\moment.png");

	if (image.empty() == true) {
		// 画像データが読み込めなかったときは終了する
		return 0;
	}

	// ウィンドウに画像を表示する
	// # ここではウィンドウに「断面形状」という識別名を付けている
	cv::imshow("断面形状", image);

	// 何かキーが押されるまで待つ
	cv::waitKey();

	return 0;
}