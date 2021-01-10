#include "CoordinateManager.h"

CoordinateManager::CoordinateManager() {
    numberDimensions = 0;
}

void CoordinateManager::getCoordinatesFromStandardInput() {
    // prompt user for input
    std::cout << "Enter vectors below.  Separate coordinates by a space.  Press enter after each vector.  \n" <<
        "Press enter twice after the last vector.  Ex. 1 2 3(Press Enter)2 3 4(Press Enter)(Press Enter)\n";
    std::string userInput;
    do {
        std::getline(std::cin, userInput);
        std::vector<int> coordinateSet;
        
        if (CoordinateLineUtility::parseCoordinateLine(userInput, coordinateSet, numberDimensions)) {
            // if number of dimensions is not initialized, set to input count
            if (numberDimensions == 0) {
                numberDimensions = coordinateSet.size();
            }
            // if correct number of coordinates in input.  
            if (coordinateSet.size() == numberDimensions) {
                coordinateSetList.push_back(coordinateSet);
            }
        }
    } while (!userInput.empty());
    for (int i = 0; i < coordinateSetList.size(); i++) {

        std::vector<int> coordinateSet = coordinateSetList.at(i);
        std::cout << "Vector: " << i << "\n";
        std::cout << "Values: ";
        for (int j = 0; j < coordinateSet.size(); j++) {
            std::cout << coordinateSet.at(j) << " ";
        }
        std::cout << "\n";
    }
}

bool CoordinateLineUtility::parseCoordinateLine(std::string coordinateLine, std::vector<int>& coordinateSet, int expectedDimensions) {
    bool parseSuccessful = true;
    
    std::stringstream inputStream(coordinateLine);
    //cout << userInput << "\n";

    int inputCount = 0;
    std::vector<int> tempCoordinateSet;
    // while there is still ints in the stream
    while (!inputStream.eof()) {
        int coordinate;
        
        // if an int is successfully processed from the string stream, add to the temporary list.
        if (inputStream >> coordinate) {
            tempCoordinateSet.push_back(coordinate);
        }
        else {
            parseSuccessful = false;
            break;
        }
        
    }
    
    
    if (expectedDimensions == 0) {
        if (tempCoordinateSet.size() != TwoDimension && tempCoordinateSet.size() != ThreeDimension) {
            parseSuccessful = false;
        }
    }
    else {
        if (tempCoordinateSet.size() != expectedDimensions) {
           parseSuccessful = false;
        }
    }
    if (parseSuccessful) {
        // after the parsing is successful, set the passed in vector to the temporary coordinate vector.
        coordinateSet = tempCoordinateSet;
    }
    return parseSuccessful;
    
}



