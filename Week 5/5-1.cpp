// 5-1.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include "sp.h"
#include <iomanip> // setw()함수

using namespace std;


int main(void) {
	
	string s;
	cout << "Enter any string, EOF to quit : ";
	vector<string> v;

	// 문자열을 한 행씩 입력 받아 분할
	while (getline(cin, s)) {
		v = sp(s);

		// 벡터 v에 저장한 단어를 각각 출력
		for (vector<string >::size_type i = 0; i < v.size(); i++) {
			for (vector<string >::size_type j = 0; j < v.size(); j++) {
				cout << v[(i + j) % v.size()] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}


