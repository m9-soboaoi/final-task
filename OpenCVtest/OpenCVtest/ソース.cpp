#include "image.h"
#include <iostream>
#include <algorithm> 
#include <stdlib.h>
using namespace std;

//クラスの定義
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

//比較関数の定義
bool compI(const Material& left, const Material& right) {
	return left.I > right.I;
}
bool compS(const Material& left, const Material& right) {
	return left.S < right.S;
}


int main() {
	const double PI = 3.141592653589793;
	cout << "画像が表示されたら何か1つキーを押してください．" << endl;
	Image();
	cout << endl;
	//データの数
	int m;
	cout << "断面二次モーメントや断面積の比較を行います．比較したいデータの数を入力してください．" << endl;
	cin >> m;
	cout << "※単位：m" << endl;
	int n;
	vector<Material> vecM;
	
	for (int i = 0; i < m; ++i) {
		cout << "[" << i+1 << "番目]断面二次モーメントを求めたい形状を選んで1～5を入力してください．" << endl;
		cin >> n;
		//断面二次モーメントI
		double I;
		//断面積S
		double S;
		
		if (n == 1) {
			double b;
			double h;
			cout << "bの値を入力してください．" << endl;
			cin >> b;
			cout << "hの値を入力してください．" << endl;
			cin >> h;
			I = b * pow(h, 3.0) / 12;
			S = b * h;
		}

		else if (n == 2) {
			double b;
			double h1;
			double h2;
			cout << "bの値を入力してください．" << endl;
			cin >> b;
			cout << "h1の値を入力してください．" << endl;
			cin >> h1;
			cout << "h2の値を入力してください．" << endl;
			cin >> h2;
			I = b * (pow(h2, 3.0) - pow(h1, 3.0)) / 12;
			S = b * (h2 - h1);
		}

		else if (n == 3) {
			double b1;
			double b2;
			double h1;
			double h2;
			cout << "b1の値を入力してください．" << endl;
			cin >> b1;
			cout << "b2の値を入力してください．" << endl;
			cin >> b2;
			cout << "h1の値を入力してください．" << endl;
			cin >> h1;
			cout << "h2の値を入力してください．" << endl;
			cin >> h2;
			I = (b2 * pow(h2, 3.0) - b1 * pow(h1, 3.0)) / 12;
			S = b2 * h2 - b1 * h1;
		}

		else if (n == 4) {
			double d;
			cout << "dの値を入力してください．" << endl;
			cin >> d;
			I = PI * pow(d, 4.0) / 64;
			S = PI * pow(d, 2.0) / 4;
		}

		else if (n == 5) {
			double d1;
			double d2;
			cout << "d1の値を入力してください．" << endl;
			cin >> d1;
			cout << "d2の値を入力してください．" << endl;
			cin >> d2;
			I = PI * (pow(d2, 4.0) - pow(d1, 4.0)) / 64;
			S = PI * (pow(d2, 2.0) - pow(d1, 2.0)) / 4;
		}

		else {
			cout << "1～5以外の入力がありました．最初からやり直してください．" << endl;
			exit(1);
		}

		vecM.push_back(Material(I, S, n));
		cout << endl;
	}
	cout << endl;

	cout << "入力されたデータは以下．" << endl;
	for (int j = 0; j < vecM.size(); j++) {
		cout << j + 1 << ".断面形状：" << vecM[j].n << ",  I=" << vecM[j].I << "[m^4],  S=" << vecM[j].S << "[m^2]" << endl;
	}
	cout << endl;

	//Iの降順
	sort(vecM.begin(), vecM.end(), compI);

	cout << "断面二次モーメントIが大きい順．" << endl;
	for (int j = 0; j < vecM.size(); j++) {
		cout << j+1 << ".断面形状：" << vecM[j].n << ",  I=" << vecM[j].I << "[m^4],  S=" << vecM[j].S << "[m^2]" << endl;
	}
	cout << endl;

	//Sの降順
	sort(vecM.begin(), vecM.end(), compS);

	cout << "断面積Sが小さい順．" << endl;
	for (int j = 0; j < vecM.size(); j++) {
		cout << j + 1 << ".断面形状：" << vecM[j].n << ",  I=" << vecM[j].I << "[m^4],  S=" << vecM[j].S << "[m^2]" << endl;
	}
}