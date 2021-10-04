#include<iostream>
using namespace std;

class Element
{
public:
    int i;
    int j;
    int x;
};

class Sparse_Matrix
{
private:
    int rows;
    int columns;
    int n;
    Element *e;
public:
    Sparse_Matrix()
    {
        rows = 3;
        columns = 3;
        n = 3;
        e = new Element[3];
    }

    Sparse_Matrix(int row, int col, int num)
    {
        rows = row;
        columns = col;
        n = num;
        e = new Element[n];
    }

    ~Sparse_Matrix()
    {
        delete[] e;
    }

    Sparse_Matrix operator+(Sparse_Matrix &s);
    friend istream & operator>>(istream &is, Sparse_Matrix &s);
    friend ostream & operator<<(ostream &os, Sparse_Matrix &s);
};

Sparse_Matrix Sparse_Matrix::operator+(Sparse_Matrix &s)
{
    if (rows == s.rows && columns == s.columns)
    {
         int max_size = n + s.n;
         Sparse_Matrix *sum = new Sparse_Matrix(rows, columns, max_size);

         int i = 0, j = 0, k = 0;
         while (i < n && j < s.n)
            {
                if (e[i].i < s.e[j].i)
                    sum->e[k++] = e[i++];
                else if (e[i].i > s.e[j].i)
                    sum->e[k++] = s.e[j++];
                else
                {
                    if (e[i].j < s.e[j].j)
                        sum->e[k++] = e[i++];
                    else if (e[i].j > s.e[j].j)
                        sum->e[k++] = s.e[j++];
                    else
                    {
                        sum->e[k] = e[i];
                        sum->e[k++].x = e[i++].x + s.e[j++].x;
                    }
                }
            }
         for(; i < n; i++)
            sum->e[k++] = e[i];
         for(; j < s.n; j++)
            sum->e[k++] = s.e[j];
         sum->rows = rows;
         sum->columns = columns;
         sum->n = k;
         return *sum;
      }
      return Sparse_Matrix();
}

istream & operator>>(istream &is, Sparse_Matrix &s)
{
    cout<<"Enter non-zero elements: \n";
    for (int i = 0; i < s.n; i++)
        is>>s.e[i].i>>s.e[i].j>>s.e[i].x;
    return is;
}

ostream & operator<<(ostream &os, Sparse_Matrix &s)
{
    int k = 0;
    for (int i = 0; i < s.rows; i++)
    {
        for (int j = 0; j < s.columns; j++)
        {
            if (i == s.e[k].i && j == s.e[k].j)
                os<<s.e[k++].x<<" ";
            else
                os<<"0 ";
        }
    os<<"\n";
    }
    return os;
}

int main()
{
    Sparse_Matrix s1 (5, 5, 5);
    Sparse_Matrix s2 (5, 5, 5);

    cin>>s1;
    cout<<s1;
    cin>>s2;
    cout<<s2;

    Sparse_Matrix s3 = s1 + s2;
    cout<<endl<<s3;
}


