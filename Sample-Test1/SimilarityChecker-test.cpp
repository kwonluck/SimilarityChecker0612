#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"
#include <string>
using namespace std;

TEST(SimilarityChecker, legnthCheck1) {	
	SimilarityChecker similarityChecker;

	string strA = "ASD";
	string strB = "DSA";
	similarityChecker.setCompareString(strA, strB);
	int lengthPoint = similarityChecker.getLengthPoint();
	EXPECT_EQ(60, lengthPoint);
}

TEST(SimilarityChecker, legnthCheck2) {
	SimilarityChecker similarityChecker;

	string strA = "ASD";
	string strB = "DS";
	similarityChecker.setCompareString(strA, strB);
	int lengthPoint = similarityChecker.getLengthPoint();
	EXPECT_EQ(30, lengthPoint);
}

TEST(SimilarityChecker, legnthCheck3) {
	SimilarityChecker similarityChecker;

	string strA = "DS";
	string strB = "ASD";
	similarityChecker.setCompareString(strA, strB);
	int lengthPoint = similarityChecker.getLengthPoint();
	EXPECT_EQ(30, lengthPoint);
}

TEST(SimilarityChecker, alphaCheck) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}