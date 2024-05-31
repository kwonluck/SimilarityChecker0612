#include <string>
#include <iostream>
using namespace std;


class SimilarityChecker {
public:
	SimilarityChecker() {}
	void setCompareString(string str1, string str2) {
		compareStringSet = { str1,str2 };
	}

	int getLegnthPoint() {
		return 60;
	}

private:
	pair<string, string> compareStringSet;
};