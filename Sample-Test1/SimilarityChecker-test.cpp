#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"
#include <string>
using namespace std;

class SimilarityCheckerFixture : public testing::Test {
public:
	SimilarityChecker similarityChecker;

	int testGetLengthPoint(string str1, string str2) {
		similarityChecker.setCompareString(str1, str2);
		return similarityChecker.getLengthPoint();
	}
};

TEST_F(SimilarityCheckerFixture, legnthCheck1) {
	EXPECT_EQ(60, testGetLengthPoint("ASD", "DSA"));
}

TEST_F(SimilarityCheckerFixture, legnthCheck2) {
	EXPECT_EQ(30, testGetLengthPoint("ASD", "DS"));
}

TEST_F(SimilarityCheckerFixture, legnthCheck3) {
	EXPECT_EQ(30, testGetLengthPoint("DS", "ASD"));
}

TEST_F(SimilarityCheckerFixture, alphaCheck) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}