#include <string>
#include <iostream>
using namespace std;


class SimilarityChecker {
public:
	SimilarityChecker() {}
	void setCompareString(string str1, string str2) {
		compareStringSet = { str1,str2 };
	}

	int getLengthPoint() {
		int gap = compareStringSet.first.length() - compareStringSet.second.length();

		if (gap == 0)
			return 60;

		double denominator = 1;
		if (gap > 0)
			denominator = compareStringSet.second.length();
		if (gap < 0)
			denominator = compareStringSet.first.length();
		
		return (1 - (abs(gap) / denominator)) * 60;

	}

private:
	pair<string, string> compareStringSet;
};