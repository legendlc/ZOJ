#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXHEIGHT 2000

int maxInt(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n >= 0)
    {
        if(n == 0)
        {
            printf("Sorry\n");
            scanf("%d", &n);
            continue;
        }
        int* height_diff = (int*)malloc((n+1)*(MAXHEIGHT)*sizeof(int));
        memset(height_diff, 0, (n+1)*(MAXHEIGHT)*sizeof(int));

        for(int i = 0; i < n; i++)
        {
            int height;
            scanf("%d", &height);
            for(int j = 0; j < MAXHEIGHT; j++)
            {
                int tmp = height_diff[i*MAXHEIGHT+j];
                if(tmp != 0)
                {
                    int sum = j + height;
                    bool biggerisbigger = (j > height ? true : false);
                    int dif = (biggerisbigger ? j - height : height - j);
                    height_diff[(i+1)*MAXHEIGHT+sum] = maxInt(height_diff[(i)*MAXHEIGHT+sum], tmp+height);
                    height_diff[(i+1)*MAXHEIGHT+dif] = maxInt(height_diff[(i)*MAXHEIGHT+dif], (biggerisbigger ? tmp : tmp + dif));
                    //printf("i:%d j:%d sum:%d dif:%d sum-->max(%d, %d) dif-->max(%d, %d)\n", i, j, sum, dif, height_diff[(i)*MAXHEIGHT+sum], tmp+height, height_diff[(i)*MAXHEIGHT+dif], (biggerisbigger ? tmp : tmp + dif));
                }
                if(height_diff[(i+1)*MAXHEIGHT+j] < tmp)
                        height_diff[(i+1)*MAXHEIGHT+j] = tmp;
                if(height_diff[(i)*MAXHEIGHT+height] < height)
                    height_diff[(i+1)*MAXHEIGHT+height] = height;
            }
        }
        if(height_diff[n*MAXHEIGHT] > 0)
            printf("%d\n", height_diff[n*MAXHEIGHT]);
        else
            puts("Sorry");
        free(height_diff);
        scanf("%d", &n);
    }

    return 0;
}
