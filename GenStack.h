#include <iostream>
using namespace std;

template <class T>
class GenStack
{
  public:

    GenStack()
    {
      myArray = new char[128];
      m_size = 128;
      top = -1;
    }

    GenStack(int maxSize)
    {
      myArray = new char[maxSize];
      m_size = maxSize;
      top = -1;

    }

    //~GenStack();

    void push(T c)
    {
      top++;
      myArray[top] = c;
    }


    T pop()
    {
      int indextopop=top;
      top--;
      return myArray[indextopop];
    }

    //helper functions

    bool isFull()
    {
      return (top == m_size-1);
    }

    bool isEmpty()
    {
      return (top <=-1);
    }

    //char peek();

    int m_size;
    int top;

    char *myArray;
};
