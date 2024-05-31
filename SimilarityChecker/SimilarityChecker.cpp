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
		if (isSameStringLength())
			return MAX_LENGTH_POINT;

		if (isStringLegnthTwice())
			return MIN_LENGTH_POINT;

		return getLengthPartialPoint();
	}

	int getAlphaPoint() {
		return 0;
	}

private:
	const int MAX_LENGTH_POINT = 60;
	const int MIN_LENGTH_POINT = 0;
	pair<string, string> compareStringSet;

	bool isSameStringLength() {
		int strLengthA = compareStringSet.first.length();
		int strLengthB = compareStringSet.second.length();
		return strLengthA == strLengthB;
	}

	bool isStringLegnthTwice() {
		double strLengthA = compareStringSet.first.length();
		double strLengthB = compareStringSet.second.length();
		int gap = strLengthA - strLengthB;
		if (gap > 0)
			return strLengthA > strLengthB*2;
		if (gap < 0)
			return strLengthB > strLengthA *2;
	}

	int getLengthPartialPoint() {
		int gap = compareStringSet.first.length() - compareStringSet.second.length();
		double denominator = 1;
		if (gap > 0)
			denominator = compareStringSet.second.length();
		if (gap < 0)
			denominator = compareStringSet.first.length();

		return (1 - (abs(gap) / denominator)) * MAX_LENGTH_POINT;
	}
};