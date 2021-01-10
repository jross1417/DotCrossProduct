#include "pch.h"
#include "CoordinateManager.h"


TEST(ParseCoordinateLineTest, CoordinateLineGood) {
	std::vector<int> expectedCoordinates{ 1, 5 };
	int expectedSize = 2;
	std::string valid2DVector = "1 5";
	
	std::vector<int> actualCoordinates;
	bool parseSuccessful = CoordinateLineUtility::parseCoordinateLine(valid2DVector, actualCoordinates, TwoDimension);
	ASSERT_TRUE(parseSuccessful);
	ASSERT_EQ(actualCoordinates.size(), expectedSize) << "The vector size does not match the expected. \n";
	ASSERT_EQ(actualCoordinates, expectedCoordinates) << "The contents of the actual coordinate vector do not match the expected. \n";
}

TEST(ParseCoordinateLineTest, CoordinateLine2DGoodExpectedDimensions0) {
	std::vector<int> expectedCoordinates{ 1, 5 };
	int expectedSize = 2;
	// uninitialized dimensions
	int expectedDimensions = 0;
	std::string valid2DVector = "1 5";

	std::vector<int> actualCoordinates;
	bool parseSuccessful = CoordinateLineUtility::parseCoordinateLine(valid2DVector, actualCoordinates, expectedDimensions);
	ASSERT_TRUE(parseSuccessful);
	ASSERT_EQ(actualCoordinates.size(), expectedSize) << "The vector size does not match the expected. \n";
	ASSERT_EQ(actualCoordinates, expectedCoordinates) << "The contents of the actual coordinate vector do not match the expected. \n";
}

TEST(ParseCoordinateLineTest, CoordinateLine3DGoodExpectedDimensions0) {
	std::vector<int> expectedCoordinates{ 1, 5, 3 };
	int expectedSize = 3;
	// uninitialized dimensions
	int expectedDimensions = 0;
	std::string valid3DVector = "1 5 3";

	std::vector<int> actualCoordinates;
	bool parseSuccessful = CoordinateLineUtility::parseCoordinateLine(valid3DVector, actualCoordinates, expectedDimensions);
	ASSERT_TRUE(parseSuccessful);
	ASSERT_EQ(actualCoordinates.size(), expectedSize) << "The vector size does not match the expected. \n";
	ASSERT_EQ(actualCoordinates, expectedCoordinates) << "The contents of the actual coordinate vector do not match the expected. \n";
}

TEST(ParseCoordinateLineTest, CoordinateLineSizeNotEqualExpectedDimensions) {
	std::vector<int> expectedCoordinates;
	int expectedSize = 0;
	int expectedDimensions = 2;
	std::string valid2DVector = "1 5 4";

	std::vector<int> actualCoordinates;
	bool parseSuccessful = CoordinateLineUtility::parseCoordinateLine(valid2DVector, actualCoordinates, expectedDimensions);
	ASSERT_FALSE(parseSuccessful);
	ASSERT_EQ(actualCoordinates.size(), expectedSize) << "The vector size does not match the expected. \n";
	ASSERT_EQ(actualCoordinates, expectedCoordinates) << "The contents of the actual coordinate vector do not match the expected. \n";
}


TEST(ParseCoordinateLineTest, CoordinateLineStringInvalid) {
	std::string nonIntegerVector = "1 Apple 5";
	std::vector<int> expectedCoordinates;
	int expectedSize = 0;

	std::vector<int> actualCoordinates;
	bool parseSuccessful = CoordinateLineUtility::parseCoordinateLine(nonIntegerVector, actualCoordinates, TwoDimension);
	ASSERT_FALSE(parseSuccessful);
	ASSERT_EQ(actualCoordinates.size(), expectedSize) << "The vector size does not match the expected. \n";
	ASSERT_EQ(actualCoordinates, expectedCoordinates) << "The contents of the actual coordinate vector do not match the expected. \n";
}

