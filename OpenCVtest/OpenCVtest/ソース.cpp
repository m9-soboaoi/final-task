#include "image.h"
#include <iostream>
#include <algorithm> 
#include <stdlib.h>
using namespace std;

//�N���X�̒�`
struct Material {
public:
	double I;
	double S;
	double n;

	Material(double ie, double se, double ne) {
		I = ie;
		S = se;
		n = ne;
	}
};

//��r�֐��̒�`
bool compI(const Material& left, const Material& right) {
	return left.I > right.I;
}
bool compS(const Material& left, const Material& right) {
	return left.S < right.S;
}


int main() {
	const double PI = 3.141592653589793;
	cout << "�摜���\�����ꂽ�牽��1�L�[�������Ă��������D" << endl;
	Image();
	cout << endl;
	//�f�[�^�̐�
	int m;
	cout << "�f�ʓ񎟃��[�����g��f�ʐς̔�r���s���܂��D��r�������f�[�^�̐�����͂��Ă��������D" << endl;
	cin >> m;
	cout << "���P�ʁFm" << endl;
	int n;
	vector<Material> vecM;
	
	for (int i = 0; i < m; ++i) {
		cout << "[" << i+1 << "�Ԗ�]�f�ʓ񎟃��[�����g�����߂����`���I���1�`5����͂��Ă��������D" << endl;
		cin >> n;
		//�f�ʓ񎟃��[�����gI
		double I;
		//�f�ʐ�S
		double S;
		
		if (n == 1) {
			double b;
			double h;
			cout << "b�̒l����͂��Ă��������D" << endl;
			cin >> b;
			cout << "h�̒l����͂��Ă��������D" << endl;
			cin >> h;
			I = b * pow(h, 3.0) / 12;
			S = b * h;
		}

		else if (n == 2) {
			double b;
			double h1;
			double h2;
			cout << "b�̒l����͂��Ă��������D" << endl;
			cin >> b;
			cout << "h1�̒l����͂��Ă��������D" << endl;
			cin >> h1;
			cout << "h2�̒l����͂��Ă��������D" << endl;
			cin >> h2;
			I = b * (pow(h2, 3.0) - pow(h1, 3.0)) / 12;
			S = b * (h2 - h1);
		}

		else if (n == 3) {
			double b1;
			double b2;
			double h1;
			double h2;
			cout << "b1�̒l����͂��Ă��������D" << endl;
			cin >> b1;
			cout << "b2�̒l����͂��Ă��������D" << endl;
			cin >> b2;
			cout << "h1�̒l����͂��Ă��������D" << endl;
			cin >> h1;
			cout << "h2�̒l����͂��Ă��������D" << endl;
			cin >> h2;
			I = (b2 * pow(h2, 3.0) - b1 * pow(h1, 3.0)) / 12;
			S = b2 * h2 - b1 * h1;
		}

		else if (n == 4) {
			double d;
			cout << "d�̒l����͂��Ă��������D" << endl;
			cin >> d;
			I = PI * pow(d, 4.0) / 64;
			S = PI * pow(d, 2.0) / 4;
		}

		else if (n == 5) {
			double d1;
			double d2;
			cout << "d1�̒l����͂��Ă��������D" << endl;
			cin >> d1;
			cout << "d2�̒l����͂��Ă��������D" << endl;
			cin >> d2;
			I = PI * (pow(d2, 4.0) - pow(d1, 4.0)) / 64;
			S = PI * (pow(d2, 2.0) - pow(d1, 2.0)) / 4;
		}

		else {
			cout << "1�`5�ȊO�̓��͂�����܂����D�ŏ������蒼���Ă��������D" << endl;
			exit(1);
		}

		vecM.push_back(Material(I, S, n));
		cout << endl;
	}
	cout << endl;

	cout << "���͂��ꂽ�f�[�^�͈ȉ��D" << endl;
	for (int j = 0; j < vecM.size(); j++) {
		cout << j + 1 << ".�f�ʌ`��F" << vecM[j].n << ",  I=" << vecM[j].I << "[m^4],  S=" << vecM[j].S << "[m^2]" << endl;
	}
	cout << endl;

	//I�̍~��
	sort(vecM.begin(), vecM.end(), compI);

	cout << "�f�ʓ񎟃��[�����gI���傫�����D" << endl;
	for (int j = 0; j < vecM.size(); j++) {
		cout << j+1 << ".�f�ʌ`��F" << vecM[j].n << ",  I=" << vecM[j].I << "[m^4],  S=" << vecM[j].S << "[m^2]" << endl;
	}
	cout << endl;

	//S�̍~��
	sort(vecM.begin(), vecM.end(), compS);

	cout << "�f�ʐ�S�����������D" << endl;
	for (int j = 0; j < vecM.size(); j++) {
		cout << j + 1 << ".�f�ʌ`��F" << vecM[j].n << ",  I=" << vecM[j].I << "[m^4],  S=" << vecM[j].S << "[m^2]" << endl;
	}
}