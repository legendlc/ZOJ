#include <iostream>

using namespace std;

const int nLocos = 3;

int maxPassengers(int* arr, int num, int maxCoaches);

inline int sumof(int* arr, int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

inline int maxInt(const int& a, const int& b)
{
    int tmp = (a > b ? a : b);
    return tmp;
}

int main()
{
    int testTimes;
    cin >> testTimes;

    for(int i = 0; i < testTimes; i++)
    {
        int nCoaches;
        int maxCoaches;
        cin >> nCoaches;
        int* coaches = new int[nCoaches];
        for(int i = 0; i < nCoaches; i++)
        {
            cin >> coaches[i];
        }
        cin >> maxCoaches;

        cout << maxPassengers(coaches, nCoaches, maxCoaches) << endl;

        delete[] coaches;
    }
}

int maxPassengers(int* arr, int num, int maxCoaches)
{
    int* table = new int[(nLocos+1)*(num+1)];
    for(int i = 0; i <= nLocos; i++){
        table[i*(num+1)] = 0;
    }
    for(int i = 0; i <= num; i++){
        table[i] = 0;
    }
    for(int i = 1; i <= nLocos; i++)
    {
        for(int j = 1; j <= num; j++)
        {
            if(j <= i * maxCoaches)
            {
                table[i*(num+1)+j] = sumof(arr, j);
            }
            else
            {
                table[i*(num+1)+j] = maxInt(table[i*(num+1)+j-1], table[(i-1)*(num+1)+j-maxCoaches]+sumof(arr+j-maxCoaches, maxCoaches));
            }
        }
    }
    /******test********
    for(int i = 0; i <= nLocos; i++)
    {
        for(int j = 0; j <= num; j++)
        {
            cout << table[i*(num+1)+j] << ' ';
        }
        cout << endl;
    }
    ******************/
    int tmp = table[nLocos*(num+1)+num];
    delete[] table;
    return tmp;
}
