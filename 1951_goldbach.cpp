#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>

#define Max 10000000

bool isPrime(long num)
{
    if(num == 2)
        return true;
    for(long i = 3; i*i <= num; i++)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}

bool isPrime(long target, long* table, int beg, int end)
{
    int b = beg, e = end;
    while(b < e)
    {
        int half = (b+e)/2;
        if(target < table[half])
        {
            e = half;
        }
        else if(target > table[half])
        {
            b = half+1;
        }
        else
            return true;
    }
    return false;
}

int init(long* table)
{
    table[0] = 2;
    int cnt = 1;
    for(int i = 3; i < Max; i++)
    {
        bool flag = true;
        for(int j = 0; j < cnt && table[j] * table[j] <= i; j++)
        {
            if(i % table[j] == 0)
            {
                flag = false;
                break;
            }
        }
        if(flag == true)
        {
            table[cnt++] = i;
        }
    }
    return cnt;
}

int main()
{

    long* primeTable = (long*)malloc(Max * sizeof(long));
    memset(primeTable, -1, Max);

    unsigned long start = clock();
    int len = init(primeTable);
    unsigned long end = clock();
    printf("Time is %.2fms.\n", (end - start) * 1000.0 / CLOCKS_PER_SEC);
    long n;
    scanf("%ld", &n);
    while(n > 0)
    {
        for(int i = 0; primeTable[i] <= n / 2; i++)
        {
            if(isPrime(n - primeTable[i], primeTable, 0, len)){
                printf("%ld = %ld + %ld\n", n, primeTable[i], n - primeTable[i]);
                break;
            }
        }
        scanf("%ld", &n);
    }
    return 0;
}
