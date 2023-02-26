#pragma once

#include "base.h"
#include "linkedListGraph.h"

// A function responsible for counting number of elements in an array of string
int countArr(string arr[]);

// A function responsible for string splitting
string splitStr(string str, string delimiter);

// A function responsible for string replacing
string replaceStr(string str, string replaced, string replace);

// A function responsible for getting data from .txt file and convert it to string
string dataConvertToString(string filePath);

// A function responsible for transferring string data to arrays, 
// then preprocessing data and insert preprocessed data into Graph
Graph *dataHandling(string data);