
#include <iostream>
#include <string>
#include <sstream> 
#include <vector>
#include "CoordinateManager.h"


// Stores coordinates for a vector.
struct CoordinateVector {
    // dimensions for the coordinates.  (2 or 3)
    int dimensionNum;
    // stores the coordinates in an array.
    int coordinates[ThreeDimension];
};

void showUsage()
{
    std::cout << "Usage: \n"
        << "Options:\n"
        << "\t-h,--help\tShow this help message\n"
        << "\t-f,--inputfile\tFiles containing vectors (optional). If this option isn't given the program will manually prompt the user for input.  \n"
        << "\t\t\tEach vector will be separated by a new line.  Each coordinate in the vector will be separated by a space.\n"
        << "\t-s,--showsteps\tFlag to enable showing work for the dot & cross product calculations (optional).\n\n";
}




int main(int argc, char* argv[])
{

    std::string inputFile = "";
    bool showSteps = false;

    // code similar to this article http://www.cplusplus.com/articles/DEN36Up4/
    // read any options the user supplies to the program.  
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if ((arg == "-h") || (arg == "--help")) {
            showUsage();
            return 0;
        }
        else if ((arg == "-f") || (arg == "--inputfile")) {
            if (i + 1 < argc) {
                i++;
                inputFile = std::string(argv[i]);
            }
            else {
                std::cerr << "-f, --inputfile requires an argument.\n";
                return 1;
            }
        }
        else if ((arg == "-s") || (arg == "--showsteps")) {
            showSteps = true;
        }
    }

    std::cout << "Input file: " << inputFile << " ShowStepsFlag: " << showSteps << "\n";
    CoordinateManager coordinateManager;
    coordinateManager.getCoordinatesFromStandardInput();
    

    return 0;
    
}

