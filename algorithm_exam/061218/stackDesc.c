#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define OK 1
#define NOT_OK -1

void printStack(int *stackBuffer)
{       
    int index = 0;
    printf("=============STACK PRINT===============\n");
    while(*(stackBuffer + index) != 0)
    {
        index++;
    }
    index --;
    while (index >= 0)
    {
        printf("%d\n", *(stackBuffer + index));
        index--;
    }
    printf("==============  END  ==================\n");
}


int push(int inputNum, int *stackBuffer, boolean bSort)
{
    int index = 0;

    while( *(stackBuffer + index) != 0 )
    {
        if (MAX == index)
        {
            printf("stackBuffer Full\n");
            return NOT_OK;
        }
        index++;
    }
    
    *(stackBuffer + index) = inputNum;

    if (bSort)
        printf("+\n");
    
    printStack(stackBuffer);

    return OK;
}

int pop(int *stackBuffer)
{
    int index = 0;
    int popNum = 0;
    while ( *(stackBuffer + index) != 0)
    {
        index++;
    }

    popNum = *(stackBuffer + index);

    if (bSort)
        printf("-\n");
    return OK;
}

void sortStack(int *stackBuffer)
{
    int sortedStack[MAX] = {0,};
    int sortedIndex = 0;
    int index = 0;
    while (1)
    {
        if (sortedStack[sortedIndex] < stackBuffer[index])
        {
            push(sortedStack[sortedIndex], sortedStack, true);
        }
        else
        {
            while()
                // pop while under input num of stackbuffer
                // and push sorted index point of sortedStack
        }

    }


}

int main(void)
{
    int inputNum = 0;
    int index = 0;
    int stackBuffer[MAX] = {0,};

    while (1)
    {
        printf("input Number(exit = -1) :");
        scanf("%d",&inputNum);
        fflush(stdin);
        if (-1 == inputNum)
        {
            break;
        }
        
        if (OK != push(inputNum, stackBuffer, false))
            break;
    }

    sortStack(stackBuffer);

    return 0;

}

