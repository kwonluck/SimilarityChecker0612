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

	int testGeAlphaPoint(string str1, string str2) {
		similarityChecker.setCompareString(str1, str2);
		return similarityChecker.getAlphaPoint();
	}
};

TEST_F(SimilarityCheckerFixture, legnthCheck1) {
	EXPECT_EQ(60, testGetLengthPoint("ASD", "DSA"));
}

TEST_F(SimilarityCheckerFixture, legnthCheck2) {
	EXPECT_EQ(0, testGetLengthPoint("AS", "DESA"));
}

TEST_F(SimilarityCheckerFixture, legnthCheck3) {
	EXPECT_EQ(30, testGetLengthPoint("ASD", "DS"));
}

TEST_F(SimilarityCheckerFixture, legnthCheck4) {
	EXPECT_EQ(30, testGetLengthPoint("DS", "ASD"));
}

TEST_F(SimilarityCheckerFixture, alphaCheck1) {
	EXPECT_EQ(40, testGeAlphaPoint("ASD", "ASD"));
}

TEST_F(SimilarityCheckerFixture, alphaCheck2) {
	EXPECT_EQ(0, testGeAlphaPoint("A", "BB"));
}

TEST_F(SimilarityCheckerFixture, alphaCheck3) {
	EXPECT_EQ(0, testGeAlphaPoint("AA", "EEA"));
}