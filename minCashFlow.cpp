// Use Greedy algorithm to minimize cash flow

#include "./libs/minCashFlow.h"

// Recursive function that finds the index of the minimum 
// and maximum values in a list of net amounts
void minCashFlowRec(Graph *graph, int amount[], string &output)
{
    // Find the indexes of minimum and maximum values in amount[]
    // amount[mxCredit] indicates the maximum amount to be given (or credited) to any person
    // And amount[mxDebit] indicates the maximum amount to be taken (or debited) from any person
    // So if there is a positive value in amount[], then there must be a negative value
    int mxCredit = getMax(amount), mxDebit = getMin(amount);

    // If both amounts are 0, then all amounts are settled
    if (amount[mxCredit] == 0 && amount[mxDebit] == 0)
        return;

    // Find the minimum of two amounts
    int min = minOf2(-amount[mxDebit], amount[mxCredit]);
    amount[mxCredit] -= min;
    amount[mxDebit] += min;

    // If minimum is the maximum amount to be
    cout << graph->nodeList[mxDebit]->data.name << " needs to pay "
         << graph->nodeList[mxCredit]->data.name << ": " << min << "K" << endl;

    output += (graph->nodeList[mxDebit]->data.name + " needs to pay "
                  + graph->nodeList[mxCredit]->data.name + ": " + to_string(min) + "K\n");
    // Recur for the amount array.  Note that it is guaranteed that
    // the recursion would terminate as either amount[mxCredit] or amount[mxDebit] becomes 0
    minCashFlowRec(graph, amount, output);
}

// A function to find and print the minimum cash flow to settle all debts
void minCashFlow(Graph *graph, string &output)
{
    // Create an array amount[], initialize all value in it as 0
    int n = graph->v;
    int *netAmount = new int;

    // Calculate the net amount to be paid to person 'p', and
    // stores it in amount[p]. The value of netAmount[p] can be
    // calculated by subtracting debts of 'p' from credits of 'p'
    int *creditAmount, *debitAmount;
    for (int i = 0; i < graph->v; i++) {
        for (Node *p = graph->nodeList[i]->next; p != NULL; p = p->next) {
            creditAmount[i] += graph->nodeList[i]->cash;
            debitAmount[graph->nodeList[i]->data.index] += graph->nodeList[i]->cash;
        }
    }

    for (int i = 0; i < graph->v; i++) {
        netAmount[i] = creditAmount[i] - debitAmount[i];
    }

    minCashFlowRec(graph, netAmount, output);
}