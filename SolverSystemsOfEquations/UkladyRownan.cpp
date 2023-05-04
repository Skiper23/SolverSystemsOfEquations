#include <iostream>
#include <cmath>
#define SIZE 928
#define a1 12
#define a2 -1
#define a3 -1
#define f 7
using namespace std;
void fillMatrix(int** Amatrix, int** Dmatrix, int** Lmatrix, int** Umatrix, int ** DLmatrix)
{
    for (int i = 0; i < SIZE; i++)
    {
        Amatrix[i][i]=Dmatrix[i][i] = a1;
        if (i >= 1)
            Amatrix[i][i - 1] = Lmatrix[i][i - 1] = DLmatrix[i][i - 1] = a2;
        if (i >= 2)
            Amatrix[i][i - 2] = Lmatrix[i][i - 2] = DLmatrix[i][i - 2] = a3;
        if (i <= SIZE - 2)
            Amatrix[i][i + 1] = Umatrix[i][i + 1] = DLmatrix[i][i + 1] = a2;
        if (i <= SIZE - 3)
            Amatrix[i][i + 2] = Umatrix[i][i + 2] = Lmatrix[i][i + 2] = a3;
    }
}
void fillVector(double* bvector, double* rvector)
{
    for (int i = 0; i < SIZE; i++)
    {
        bvector[i] = sin(i * (f + 1));
        rvector[i] = 1;
    }
}
void Jacobiego(int** Amatrix, double* bvector)
{

}
int main()
{
    int** Amatrix = new int* [SIZE];
    int** Dmatrix = new int* [SIZE];
    int** Lmatrix = new int* [SIZE];
    int** Umatrix = new int* [SIZE];
    int** DLmatrix = new int* [SIZE];
    double* bvector = new double[SIZE];
    double* rvector = new double[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        Amatrix[i] = new int[SIZE]();
        Dmatrix[i] = new int[SIZE]();
        Lmatrix[i] = new int[SIZE]();
        Umatrix[i] = new int[SIZE]();
    }
    fillMatrix(Amatrix, Dmatrix, Lmatrix, Umatrix,DLmatrix);
    fillVector(bvector,rvector);

    return 0;
}
