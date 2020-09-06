#include <stdio.h>
#include <stdlib.h>


int Sum(int *dwarf);
int compare(const void* a, const void* b);
int FindDwarf(int sum, int* dwarf);

int main(void)
{
    int dwarf[9];
    for (int i = 0; i < 9; ++i)
    {
        scanf("%d", &dwarf[i]);
    }
    
    FindDwarf(Sum(dwarf), dwarf);
    qsort(dwarf, sizeof(dwarf) / sizeof(int), sizeof(int), compare);

    for (int i = 2; i < 9; ++i)
    {
        printf("%d\n", dwarf[i]);
    }

    return 0;
}

int Sum(int *dwarf)
{
    int sum = 0;
    for (int i = 0; i < 9; ++i)
    {
        sum += dwarf[i];
    }
    return sum;
}

int compare(const void* a, const void* b)
{
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if (num1 < num2)
        return -1;

    if (num1 > num2)
        return 1;

    return 0;
}

int FindDwarf(int sum, int* dwarf)
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = i + 1; j < 9; ++j)
        {
            if (sum - (dwarf[i] + dwarf[j]) == 100)
            {
                dwarf[i] = dwarf[j] = -1;
                return 0;
            }
        }
    }

    return -1;
}