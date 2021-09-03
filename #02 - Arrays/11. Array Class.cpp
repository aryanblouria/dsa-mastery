#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;
    void swap(int *x, int *y);
    bool found(Array arr, int value);
public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }

    Array(int s)
    {
        size = s;
        length = 0;
        A = new int[size];
    }

    ~Array()
    {
        delete[] A;
    }

    void display();
    void append(int x);
    void insert(int index, int x);
    void del1(int index);
    void del2(int value);
    int linear_search1(int value);
    int linear_search2(int value);
    int linear_search3(int value);
    int binary_search1(int value);
    int binary_search2(int value, int l, int h);
    int get(int index);
    void set(int index, int value);
    int max();
    int min();
    int sum();
    double avg();
    void reverse1();
    void reverse2();
    void lshift();
    void rshift();
    void lrotate();
    void rrotate();
    bool check();
    void insert1(int value);
    void insert2(int value);
    void negative_shift1();
    void negative_shift2();
    Array* merge(Array arr2);
    Array* unsorted_union(Array arr2);
    Array* sorted_union(Array arr2);
    Array* unsorted_intersection(Array arr2);
    Array* sorted_intersection(Array arr2);
    Array* unsorted_difference(Array arr2);
    Array* sorted_difference(Array arr2);
};

void Array::display()
{
    cout<<"The elements of the array are: ";
    for(int i = 0; i < length; i++)
        cout<<A[i];
    cout<<"\n";
}

void Array::append(int x)
{
    if(length < size)
        A[length++] = x;
    else
        cout<<"Cannot append.";
}

void Array::insert(int index, int x)
{
    if(length < size && index >= 0 && index <= length)
    {
        for (int i = length; i > index; i--)
            A[i] = A[i-1];
        A[index] = x;
        length++;
    }
    else
        cout<<"Cannot insert.";
}

void Array::del1(int index)
{
    if (index >= 0 && index < length)
    {
        for(int i = index; i < length-1; i++)
            A[i] = A[i+1];
        length--;
    }
}

void Array::del2(int value)
{
    int index = 0;
    for(int i = 0; i < length; i++)
        if (A[i] == value)
            index = i;
    for(int i = index; i < length-1; i++)
        A[i] = A[i+1];
    length--;
}

void Array::swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Array::linear_search1(int value)
{
    for(int i = 0; i < length; i++)
        if (A[i] == value)
            return i;
    return -1;
}

int Array::linear_search2(int value)
{
    for(int i = 0; i < length; i++)
        if (A[i] == value)
        {
            swap(&A[i], &A[i-1]);
            return i - 1;
        }
    return -1;
}

int Array::linear_search3(int value)
{
    for(int i = 0; i < length; i++)
        if (A[i] == value)
        {
            swap(&A[i], &A[0]);
            return 0;
        }
    return -1;
}

int Array::binary_search1(int value)
{
    int l = 0, h = length-1, mid = 0;
    while (l <= h)
    {
        mid = (l+h)/2;
        if (value == A[mid])
            return mid;
        else if (value > A[mid])
            l = mid + 1;
        else
            h = mid - 1;
    }
    return -1;
}

int Array::binary_search2(int value, int l, int h)
{
    if (l <= h)
    {
        int mid = (l+h)/2;
        if (value == A[mid])
            return mid;
        else if (value > A[mid])
            l = mid + 1;
        else
            h = mid - 1;
        return binary_search2(value, l, h);
    }
    return -1;
}

int Array::get(int index)
{
    if (index>=0 && index<length)
        return A[index];
}

void Array::set(int index, int value)
{
    if (index>=0 && index<length)
        A[index] = value;
}

int Array::max()
{
    int m = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] > m)
            m = A[i];
    }
    return m;
}

int Array::min()
{
    int m = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] < m)
            m = A[i];
    }
    return m;
}

int Array::sum()
{
    int s = 0;
    for (int i = 0; i < length; i++)
        s+=A[i];
    return s;
}

double Array::avg()
{
    double s = 0;
    for (int i = 0; i < length; i++)
        s+=A[i];
    return s/length;
}

void Array::reverse1()
{
    int* temp = (int*) malloc (sizeof(int) * length);
    for (int i = 0; i < length; i++)
        temp[i] = A[length - i - 1];

    for (int i = 0; i < length; i++)
        A[i] = temp[i];
}

void Array::reverse2()
{
    for (int i = 0, j = length-1; i < j; i++, j--)
        swap(&A[i], &A[j]);
}

void Array::lshift()
{
    for (int i = 0; i < length-1; i++)
        A[i] = A[i+1];
    A[length-1] = 0;
}

void Array::rshift()
{
    for (int i = length-1; i > 0; i--)
        A[i] = A[i-1];
    A[0] = 0;
}

void Array::lrotate()
{
    int temp = A[0];
    for (int i = 0; i < length-1; i++)
        A[i] = A[i+1];
    A[length-1] = temp;
}

void Array::rrotate()
{
    int temp = A[length-1];
    for (int i = length-1; i > 0; i--)
        A[i] = A[i-1];
    A[0] = temp;
}

void Array::insert1(int value)
{
   for (int i = 0; i < length; i++)
        if (A[i] > value)
        {
            for (int j = length-1; j >= i; j--)
                A[j+1] = A[j];
            A[i] = value;
            length++;
            return;
        }
   A[length++] = value;
}

void Array::insert2(int value)
{
    int i = length-1;
    while (A[i] > value)
    {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = value;
    length++;
}

void Array::negative_shift1()
{
    int index = 0;
    for (int i = 0; i < length; i++)
        if (A[index] > 0)
        {
            int temp = A[index];
            for (int j = index; j < length-1; j++)
                A[j] = A[j+1];
            A[length-1] = temp;
        }
        else
            index++;
}

void Array::negative_shift2()
{
   int i = 0, j = length-1;
   while(i < j)
   {
       while (A[i] < 0)
            i++;
       while (A[j] >= 0)
            j--;
       if (i < j)
           swap(&A[i], &A[j]);
   }
}

Array* Array::merge(Array arr2)
{
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = arr2.A[j++];
    }

    for (; i < length; i++)
        arr3->A[k++] = A[i];
    for (; j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];

    arr3->length = length + arr2.length;
    return arr3;
}

bool Array::found(struct Array arr, int value)
{
    for (int i = 0; i < arr.length; i++)
        if (value == arr.A[i])
            return true;
    return false;
}

Array* Array::unsorted_union(Array arr2)
{
    int k = 0;
    Array *arr3 = new Array(length + arr2.length);

    for (int i = 0; i < length; i++)
        arr3->A[k++] = A[i];

    arr3->length = length;
    for (int j = 0; j < arr2.length; j++)
        if (!found(*arr3, arr2.A[j]))
            arr3->A[k++] = arr2.A[j];

    arr3->length = k;
    return arr3;
};

Array* Array::sorted_union(Array arr2)
{
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else if (arr2.A[j] < A[i])
            arr3->A[k++] = arr2.A[j++];
        else
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }

    for (; i < length; i++)
        arr3->A[k++] = A[i];
    for (; j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];

    arr3->length = k;
    return arr3;
}

Array* Array::unsorted_intersection(Array arr2)
{
    int k = 0;
    Array *arr3 = new Array(length);

    for (int i = 0; i < length; i++)
        if (found(arr2, A[i]))
            arr3->A[k++] = A[i];

    arr3->length = k;
    return arr3;
};

Array* Array::sorted_intersection(Array arr2)
{
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(length);

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
            i++;
        else if (arr2.A[j] < A[i])
            j++;
        else
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }

    arr3->length = k;
    return arr3;
};

Array* Array::unsorted_difference(Array arr2)
{
    int k = 0;
    Array *arr3 = new Array(length);

    for (int i = 0; i < length; i++)
        if (!found(arr2, A[i]))
            arr3->A[k++] = A[i];

    arr3->length = k;
    return arr3;
};

Array* Array::sorted_difference(Array arr2)
{
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(length);

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else if (arr2.A[j] < A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }

    for (; i < length; i++)
        arr3->A[k++] = A[i];
    arr3->length = k;
    return arr3;
};

int main()
{
    Array *arr;
    int s, choice;
    int x, index;

    printf("Enter array size: ");
    scanf("%d", &s);

    arr = new Array(s);
    do
    {
       cout<<endl<<"Menu of Operations"<<endl;
       cout<<"=================="<<endl<<endl;
       cout<<"1. Display"<<endl;
       cout<<"2. Insert"<<endl;
       cout<<"3. Delete"<<endl;
       cout<<"4. Linear Search"<<endl;
       cout<<"5. Binary Search"<<endl;
       cout<<"6. Get"<<endl;
       cout<<"7. Set"<<endl;
       cout<<"8. Maximum"<<endl;
       cout<<"9. Minimum"<<endl;
       cout<<"10. Sum"<<endl;
       cout<<"11. Average"<<endl;
       cout<<"12. Reverse"<<endl;
       cout<<"13. Left Shift"<<endl;
       cout<<"14. Right Shift"<<endl;
       cout<<"15. Left Rotate"<<endl;
       cout<<"16. Right Rotate"<<endl;
       cout<<"17. Check if Sorted"<<endl;
       cout<<"18. Shift Negatives"<<endl;
       cout<<"19. Merge"<<endl;
       cout<<"20. Union"<<endl;
       cout<<"21. Intersection"<<endl;
       cout<<"22. Difference"<<endl;
       cout<<"23. Exit"<<endl<<endl;

       cout<<"Enter your choice: ";
       cin>>choice;

       switch(choice)
       {
        //Enter cases here
       }
    } while (choice<23);

    return 0;
}
