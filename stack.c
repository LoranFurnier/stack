#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
void StackInit(stackT *stackP, int maxSize)
{
  stackElementT *newContents;

  /* нужен новый массив */

  newContents = (stackElementT *)malloc(sizeof(stackElementT)
                                        * maxSize);

  if (newContents == NULL) {
    fprintf(stderr, "ПАМЯТИ НЕ ХВАТАЕТ!!1!АДЫН!\n");
    exit(1);  /*ошибка */
  }

  stackP->contents = newContents;
  stackP->maxSize = maxSize;
  stackP->top = -1;  /*пустота*/
}
void StackDestroy(stackT *stackP)
{
  /* избавляемся от массива */
  free(stackP->contents);

  stackP->contents = NULL;
  stackP->maxSize = 0;
  stackP->top = -1;  /* пустота */
}
int StackIsEmpty(stackT *stackP)
{
  return stackP->top < 0;
}
int StackIsFull(stackT *stackP)
{
  return stackP->top >= stackP->maxSize - 1;
}
void StackPush(stackT *stackP, stackElementT element)
{
  if (StackIsFull(stackP)) {
    fprintf(stderr, "Can't push element on stack: stack is full.\n");
    exit(1);  /* ошибка */
  }
  /* пихнуть информацию в массив */
  stackP->contents[++stackP->top] = element;
}
stackElementT StackPop(stackT *stackP)
{
  if (StackIsEmpty(stackP)) {
    fprintf(stderr, "Can't pop element from stack: stack is empty.\n");
    exit(1);  /* ошибка */
  }

  return stackP->contents[stackP->top--];
}
