#pragma once

#include "base.h"

// A structure to represent a person with key information (name, index number)
typedef struct Person
{
    string name;
    int index;
} Person;

// A structure to represent a node
typedef struct Node
{
    int cash;
    Person data;
    struct Node *next;
} Node;

// A structure to maintain the graph vertexes and its connections to other vertexes
typedef struct Graph
{
    int v; // Number of vertices
    struct Node **nodeList; // an array of linked lists each of which is a 'Node' pointer
} Graph;

// A function to create a new data node
Node *initNode(Person p, int cash);

// A function to declare the graph according to the number of vertices
Graph *initGraph(int v);

// A function to input a person's data
Person init1Person(int index, string name);

// A function to add a person to graph
void insertPerson(Graph *graph, string arr[]);

// A function to add an edge into the directed graph
void addEdge(Graph *graph, int source, int target, int cash);

// Browse adjacency list
void printGraph(Graph *graph);