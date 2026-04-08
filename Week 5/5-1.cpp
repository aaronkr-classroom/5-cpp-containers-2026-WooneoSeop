#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include "sp.h"

using namespace std;

struct Entry {
    string left;
    string keyword;
    string right;
};

// 대소문자 구분 없이 비교하기 위한 보조 함수
bool compareInsensitive(const string& a, const string& b) {
    string a_lower = a, b_lower = b;
    transform(a_lower.begin(), a_lower.end(), a_lower.begin(), ::tolower);
    transform(b_lower.begin(), b_lower.end(), b_lower.begin(), ::tolower);
    return a_lower < b_lower;
}

int main() {

    cout << "Enter any string, EOF to quit : ";
    string s;
    vector<Entry> index;
    size_t max_left = 0;

    while (getline(cin, s)) {
        if (s.empty()) continue; // 빈 줄 건너뛰기
        vector<string> v = sp(s);

        for (int i = 0; i < (int)v.size(); i++) {
            string keyword = v[i];

            // 오른쪽 문맥 구성
            string right = "";
            for (int j = i + 1; j < (int)v.size(); j++) {
                right += v[j];
                if (j != (int)v.size() - 1) right += " ";
            }

            // 왼쪽 문맥 구성
            string left = "";
            for (int j = 0; j < i; j++) {
                left += v[j];
                if (j != i - 1) left += " ";
            }

            max_left = max(max_left, left.size());
            index.push_back({ left, keyword, right });
        }
    }

    // 1. 키워드 기준 정렬 (사진 결과에 맞춰 대소문자 무관 정렬)
    // 2. 키워드가 같을 경우 오른쪽 문맥으로 2차 정렬
    sort(index.begin(), index.end(), [](const Entry& a, const Entry& b) {
        if (compareInsensitive(a.keyword, b.keyword)) return true;
        if (compareInsensitive(b.keyword, a.keyword)) return false;
        return compareInsensitive(a.right, b.right);
        });

    // 결과 출력
    for (const auto& e : index) {
        // 왼쪽 문맥: max_left만큼 너비를 잡고 우측 정렬
        cout << setw((int)max_left) << e.left;

        // 키워드와 오른쪽 문맥 사이 간격 유지
        cout << "   " << e.keyword;
        if (!e.right.empty()) cout << " " << e.right;

        cout << endl;
    }

    return 0;
}
