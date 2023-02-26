// Get data from .txt (or .xlsx) file
// Save and represent data with Graph as LinkedList
// Update data to the another output file

#include "./libs/dataHandling.h"

// A function responsible for counting number of elements in an array of string
int countArr(string arr[])
{
    int count = 0;
    for (int i = 0; i < MAX_QUANTITY; i++)
    {
        if (arr[i] == "")
            return count;
        count++;
    }
    return count;
}

// A function responsible for string splitting
string splitStr(string str, string delimiter)
{
    size_t pos = 0;
    string token;
    string result = "";
    while ((pos = str.find(delimiter)) != string::npos)
    {
        token = str.substr(0, pos);
        result += (token + "\n");
        str.erase(0, pos + delimiter.length());
    }
    result += str;
    return result;
}

// A function responsible for string replacing
string replaceStr(string str, string replaced, string replace)
{
    size_t pos = 0;
    string token;
    while ((pos = str.find(replaced)) != string::npos)
    {
        token = str.substr(0, pos);
        str.replace(pos, replaced.length(), replace);
    }
    return str;
}

// A function responsible for getting data from .txt file and convert it to string
string dataConvertToString(string filePath)
{
    fstream fileInput;
    fstream fileOutput;

    fileInput.open(filePath, ios::in);

    if (fileInput.fail())
    {
        string errMessage = "Failed to open this file!";
        cout << errMessage << endl;
        return errMessage;
    }

    string data;
    string line;

    while (!fileInput.eof()) // fileInput.eof() check if the file has ended?
    {
        // if not, continue to get data (next line) from file to line
        getline(fileInput, line); 
        data += (line + "\n");
    }

    fileInput.close();

    data = replaceStr(data, "0K", "0");
    data = splitStr(replaceStr(data, ": ", "\n"), " needs to pay ");
    data.pop_back();

    return data;
}

// A function responsible for transferring string data to arrays,
// then preprocessing data and insert preprocessed data into Graph
Graph *dataHandling(string data)
{
    // Transferring string data to arrays
    string humanData[MAX_QUANTITY];
    string debtorData[MAX_QUANTITY];
    string lenderData[MAX_QUANTITY];
    string cashData[MAX_QUANTITY];

    int cashList[MAX_QUANTITY];

    int count = 0, j = 0, k = 0;

    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == '\n')
        {
            count++;
            if (count % 3 == 2)
                k++;
            if (count % 3 == 0 || count % 3 == 1)
                j++;
        }

        switch (count % 3)
        {
        case 1:
            humanData[j] += data[i];
            lenderData[k] += data[i];
            break;
        case 2:
            cashData[k - 1] += data[i];
            break;
        default:
            humanData[j] += data[i];
            debtorData[k] += data[i];
            break;
        }
    }

    // Preprocessing data
    for (int i = 0; i < k; i++)
    {
        if (i > 0)
            debtorData[i].erase(0, 1);
        lenderData[i].erase(0, 1);
        cashList[i] = stoi(cashData[i].erase(0, 1));
    }

    for (int i = 0; i < j + 1; i++)
    {
        if (i > 0)
            humanData[i].erase(0, 1);
    }

    for (int i = 0; i < j + 1; ++i)
    {
        for (int s = i + 1; s < j + 1; ++s)
            if (humanData[s] == humanData[i])
            {
                memmove(&humanData[s], &humanData[s + 1], sizeof(string) * (j - s));
                --j;
                --s;
            }
    }

    // Insert preprocessed data into Graph
    Graph *dataGraph = initGraph(j + 1);
    insertPerson(dataGraph, humanData);
    for (int i = 0; i < k; i++)
    {
        int source, target;
        for (int s = 0; s < j + 1; s++)
        {
            if (debtorData[i] == humanData[s])
                source = s;
            if (lenderData[i] == humanData[s])
                target = s;
        }
        addEdge(dataGraph, source, target, cashList[i]);
    }
    cout << "[Complete edges entry into Graph...]" << endl;

    cout << "\n[Print out data...]" << endl;
    printGraph(dataGraph);

    return dataGraph;
}