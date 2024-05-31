#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"
#include <string>
using namespace std;

TEST(SimilarityChecker, legnthCheck) {	
	SimilarityChecker similarityChecker;

	string strA = "ASD";
	string strB = "DSA";
	similarityChecker.setCompareString(strA, strB);
	int lengthPoint = similarityChecker.getLegnthPoint();
	EXPECT_EQ(60, lengthPoint);
}

TEST(SimilarityChecker, alphaCheck) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}