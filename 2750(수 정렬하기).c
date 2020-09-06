#include <stdio.h>

int main(void)
{
    int nNum;
    int nArray[1000] = {0};
    int i, j, nTmp;
    
    scanf("%d", &nNum);
    for (i = 0; i < nNum; ++i)
    {
        scanf("%d", &nArray[i]);
    }

    for (i = (nNum-1); i > 0; --i)
    {
        j = 0;
        while (j < i)
        {
            if (nArray[j] > nArray[j + 1])
            {
                nTmp = nArray[j];
                nArray[j] = nArray[j + 1];
                nArray[j + 1] = nTmp;
            }
            ++j;
        }    
    }
    
     for(i=0; i<nNum; ++i)
        printf("%d\n", nArray[i]);

    return 0;
}