// A program to represent weighted-directed-Graph using Linked list

#include "./libs/linkedListGraph.h"

// A function to create a new data node
Node *initNode(Person p, int cash)
{
    Node *newNode = new Node;
    newNode->data = p;
    newNode->cash = cash;
    newNode->next = NULL;
    return newNode;
}

// A function to declare the graph according to the number of vertices
Graph *initGraph(int v)
{
    Graph *newGraph = new Graph;
    newGraph->v = v;
    newGraph->nodeList = new Node *;

    for (int i = 0; i < v; i++)
        newGraph->nodeList[i] = NULL;

    return newGraph;
}

// A function to input a person's data
Person init1Person(int index, string name)
{
    Person p;
    p.index = index;
    p.name = name;
    return p;
}

// A function to add a person into graph
void insertPerson(Graph *graph, string arr[])
{
    for (int i = 0; i < graph->v; i++)
    {
        cout << "[Insert a person into graph...]" << endl;
        Person p = init1Person(i + 1, arr[i]);
        Node *node = initNode(p, 0);
        graph->nodeList[i] = node;
        cout << endl;
    }
    cout << "[Complete vertices entry into Graph...]" << endl;
}

// A function to add an edge into the directed graph
void addEdge(Graph *graph, int source, int target, int cash)
{
    // Add connection from source to target
    graph->nodeList[target]->cash = cash;
    Node *newNode = initNode(graph->nodeList[target]->data, graph->nodeList[target]->cash);
    if (graph->nodeList[source]->next == NULL)
        graph->nodeList[source]->next = newNode;
    else {
        newNode->next = graph->nodeList[source]->next;
        graph->nodeList[source]->next = newNode;
    }
}

// Browse adjacency list
void printGraph(Graph *graph)
{
    cout << "[Print a graph...]" << endl;
    for (int i = 0; i < graph->v; i++) {
        cout << graph->nodeList[i]->data.name << " needs to pay: ";
        Node* temp = graph->nodeList[i]->next;
        while (temp) {
            cout << temp->data.name << "[" << temp->cash << "K] ";
            temp = temp->next;
        }
        cout << endl;
    }
}