#include <iostream>
#include <cmath>
using namespace std;

template <class T>
void Print(T& vec, int n, string s)
{
    cout << s << ": [";
    for (int i=0; i<n; i++)
    {
        cout << vec[i];
        if (i < n-1)
            cout << ", ";
    }
    cout << "]" << endl;
}

int Max(int A[], int n)
{
    int max = -32768;
    for (int i=0; i<n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

class Node
{
    public:
        int value;
        Node* next;
};

int countDigits(int x)
{
    int count = 0;
    while (x != 0)
    {
        x = x / 10;
        count++;
    }
    return count;
}

void initializeBins(Node** p, int n)
{
    for (int i=0; i<n; i++)
        p[i] = nullptr;
}

void Insert(Node** ptrBins, int value, int idx)
{
    Node* temp = new Node;
    temp->value = value;
    temp->next = nullptr;

    if (ptrBins[idx] == nullptr)
        ptrBins[idx] = temp;
    else
    {
        Node* p = ptrBins[idx];
        while (p->next != nullptr)
            p = p->next;
        p->next = temp;
    }
}

int Delete (Node** ptrBins, int idx)
{
    Node* p = ptrBins[idx];
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    delete p;
    return x;
}

int getBinIndex(int x, int idx)
{
    return (int)(x / pow(10, idx)) % 10;
}

void RadixSort(int A[], int n)
{
    int max = Max(A, n);
    int nPass = countDigits(max);

    Node** bins = new Node* [10];
    initializeBins(bins, 10);

    for (int pass=0; pass<nPass; pass++)
    {
        for (int i=0; i<n; i++)
        {
            int binIdx = getBinIndex(A[i], pass);
            Insert(bins, A[i], binIdx);
        }

        int i = 0;
        int j = 0;
        while (i < 10)
        {
            while (bins[i] != nullptr)
                A[j++] = Delete(bins, i);
            i++;
        }
        initializeBins(bins, 10);
    }
    delete [] bins;
}

int main()
{
    int A[] = {237, 146, 259, 348, 152, 163, 235, 48, 36, 62};
    int n = sizeof(A)/sizeof(A[0]);

    Print(A, n, "\tA");
    RadixSort(A, n);
    Print(A, n, " Sorted A");
    return 0;
}
