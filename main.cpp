// ✅ 1. Get data from .txt (or .xlsx) file
// ✅ 2. Save and represent data with Graph as Linked list
// ✅ 3. Add, remove, browse data by methods of Linked list
// ✅ 4. Use Greedy algorithm to minimize cash flow, calculate efficiency
//    5. Display comparison between input and output diagrams after minimization
// ✅ 6. Update data to the another output file

#include "./libs/base.h"
#include "./libs/linkedListGraph.h"
#include "./libs/dataHandling.h"
#include "./libs/findMinMax.h"
#include "./libs/minCashFlow.h"

// Driver program to test above function
int main()
{
    string outputData;
    fstream fileOutput;
    
    fileOutput.open("./tests/outputList-1.txt", ios::out);

    string data = dataConvertToString("./tests/testCashList-1.txt");

    Graph *dataGraph = dataHandling(data);

    // Print the solution
    cout << "\n[Minimize cash flow...]" << endl;
    minCashFlow(dataGraph, outputData);

    // Insert solution into output file
    fileOutput << outputData;

    fileOutput.close();
    return 0;
}

// Data Structure Used: Linked list, Graph
// Algorithmic Paradigm: Greedy
// Time Complexity: O(n^2) where n is the number of people