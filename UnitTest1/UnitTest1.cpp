#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include <cstdio> 
#include "../PDS_LAB_10/PDS_LAB_10.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestReadGraph)
        {
            const char* filename = "test_graph.txt";

           
            std::ofstream testFile(filename);
            testFile << "3 3\n"; 
            testFile << "1 2 1\n"; 
            testFile << "2 3 1\n"; 
            testFile << "1 3 2\n"; 
            testFile.close();

           
            int n = 0, m = 0;
            std::vector<std::vector<int>> weightMatrix;

            
            readGraph(filename, weightMatrix, n, m);

            
            Assert::AreEqual(3, n); 
            Assert::AreEqual(3, m); 

            
            int expectedGraph[3][3] = {
                {0, 1, 2},
                {0, 0, 1},
                {0, 0, 0}
            };

            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    Assert::AreEqual(expectedGraph[i][j], weightMatrix[i][j]);
                }
            }

            
            std::remove(filename);
        }
    };
}
