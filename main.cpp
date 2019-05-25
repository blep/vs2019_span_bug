#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#if 0
// The issue disappear if I force memmove to be a function pointer
// (which I guess disable intrinsic optimization)
void *(*memmoveFnPtr)(void*, const void*, size_t) = &memmove;
#define memmove memmoveFnPtr
#endif

template<size_t size>
static void dumpArray(const int(&arr)[size], const char *context)
{
    printf("%s", context);
    for (int v : arr)
    {
        printf("%d, ", v);
    }
    printf("\n");
}


int main()
{
    int valuesC[5] = { 10, 20, 30, 40, 50 };
    const int expectedC[5] = { 10, 20, 20, 30, 40 };

    dumpArray(valuesC, "Before:   ");

    memmove(valuesC + 2, valuesC + 1, 3 * sizeof(int));

    dumpArray(valuesC, "After:    ");
    dumpArray(expectedC, "Expected: ");

    for (int index = 0; index < 5; ++index)
    {
        if (expectedC[index] != valuesC[index])
        {
            printf("\nFAILED!\n");
            abort();
        }
    }

    printf("\nOK\n");

    return 0;
}
