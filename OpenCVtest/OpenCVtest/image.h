#pragma once

#include <opencv2/opencv.hpp>

int Image(void)
{
	// �摜���i�[����I�u�W�F�N�g��錾����
	cv::Mat	image;

	// �摜�t�@�C������摜�f�[�^��ǂݍ���
	image = cv::imread("C:\\Users\\aoi05\\source\\repos\\OpenCVtest\\OpenCVtest\\moment.png");

	if (image.empty() == true) {
		// �摜�f�[�^���ǂݍ��߂Ȃ������Ƃ��͏I������
		return 0;
	}

	// �E�B���h�E�ɉ摜��\������
	// # �����ł̓E�B���h�E�Ɂu�f�ʌ`��v�Ƃ������ʖ���t���Ă���
	cv::imshow("�f�ʌ`��", image);

	// �����L�[���������܂ő҂�
	cv::waitKey();

	return 0;
}