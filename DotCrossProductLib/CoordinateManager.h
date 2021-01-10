#pragma once
#include <iostream>
#include <string>
#include <sstream> 
#include <vector>


enum dimensions { TwoDimension = 2, ThreeDimension = 3 };


class CoordinateManager {
public:
	CoordinateManager();
	void getCoordinatesFromStandardInput();
	void getCoordinatesFromFile(std::string);
	std::vector<std::vector<int>> getCoordinateSetList();
	int getNumberDimensions();
	

private:
	int numberDimensions;
	std::vector<std::vector<int>> coordinateSetList;

};

namespace CoordinateLineUtility {

	bool parseCoordinateLine(std::string, std::vector<int>&, int expectedDimensions);

};