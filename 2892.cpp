#include <cstdlib>
#include <cstdio>
#include <malloc.h>

void recover(int* arr, int scale)
{
    int half = scale / 2;
    int* backup = (int*)malloc(sizeof(int)*(scale+1));
    for(int i = 1; i <= scale; i++)
    {
        backup[i] = arr[i];
    }
    for(int i = 1; i <= half; i++)
    {
        int sum = backup[i], diff = backup[i+half];
        arr[2*i-1] = (sum + diff)/2;
        arr[2*i] = (sum - diff)/2;
    }
    free(backup);
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n > 0)
    {
        int* arr = (int*)malloc((n+1)*sizeof(int));
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
        }
        int scale = 2;
        while(scale <= n)
        {
            recover(arr, scale);
            scale *= 2;
        }
        for(int i = 1; i <= n; i++)
        {
            printf("%d", arr[i]);
            if(i < n)
                printf(" ");
        }
        printf("\n");
        free(arr);
        scanf("%d", &n);
    }
}
