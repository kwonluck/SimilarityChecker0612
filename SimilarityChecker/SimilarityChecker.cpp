#include <string>
#include <iostream>
#include <set>
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
			return NO_POINT;

		return getLengthPartialPoint();
	}

	int getAlphaPoint() {
		int totalCnt = getTotalCharCnt();
		int sameCnt = getSameCharCnt();

		if (sameCnt == 0)
			return NO_POINT;

		if (totalCnt == sameCnt)
			return MAX_ALPHA_POINT;
		
		return sameCnt / totalCnt * MAX_ALPHA_POINT;

		return 0;
	}

private:
	const int MAX_LENGTH_POINT = 60;
	const int MAX_ALPHA_POINT = 40;
	const int NO_POINT = 0;

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

	int getTotalCharCnt() {
		set<char> charList;
		for (auto ch : compareStringSet.first)
			charList.insert(ch);
		for (auto ch : compareStringSet.second)
			charList.insert(ch);

		return charList.size();
	}

	int getSameCharCnt() {
		set<char> sameCharList;
		for (auto ch1 : compareStringSet.first) {
			for (auto ch2 : compareStringSet.second) {
				if (ch1 == ch2)	{
					sameCharList.insert(ch1);
					break;
				}
			}
		}

		return sameCharList.size();
	}
};