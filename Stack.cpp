#include <iostream>
#include <string>
#include "Stack.h"
#include"StackArray.h"
#include "QueueArray.h"

bool checkBalanceBrackets(const char* text, const int maxDeep);

void testStack()
{
    std::cout << "Stack Test--------------------\n";

    Stack<int>* intStack = new StackArray<int>(5);

    std::cout << "Stack is empty: " << intStack->isEmpty() << '\n';

    intStack->push(1);
    intStack->push(2);
    intStack->push(3);
    intStack->push(4);
    intStack->push(5);

    try
    {
        intStack->push(6);
    }
    catch (const StackOverflow& e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << intStack->pop() << '\n';
    std::cout << intStack->pop() << '\n';

    intStack->push(7);
    intStack->push(8);

    std::cout << "Stack is empty: " << intStack->isEmpty() << '\n';

    std::cout << intStack->pop() << '\n';
    std::cout << intStack->pop() << '\n';
    std::cout << intStack->pop() << '\n';
    std::cout << intStack->pop() << '\n';
    std::cout << intStack->pop() << '\n';

    std::cout << "Stack is empty: " << intStack->isEmpty() << '\n';

    try
    {
        std::cout << intStack->pop() << '\n';
    }
    catch (const StackUnderflow& e)
    {
        std::cout << e.what() << '\n';
    }

    delete intStack;
}

void testQueue()
{
    std::cout << "Queue Test--------------------\n";

    Queue<std::string>* strQueue = new QueueArray<std::string>(5);

    std::cout << "Queue is empty: " << strQueue->isEmpty() << '\n';

    strQueue->enQueue("ab");
    strQueue->enQueue("cd");
    strQueue->enQueue("ef");
    strQueue->enQueue("gh");
    strQueue->enQueue("ij");

    try
    {
        strQueue->enQueue("lm");
    }
    catch (const QueueOverflow& e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << strQueue->deQueue() << '\n';
    std::cout << strQueue->deQueue() << '\n';

    strQueue->enQueue("lm");
    strQueue->enQueue("no");

    std::cout << "Queue is empty: " << strQueue->isEmpty() << '\n';

    std::cout << strQueue->deQueue() << '\n';
    std::cout << strQueue->deQueue() << '\n';
    std::cout << strQueue->deQueue() << '\n';
    std::cout << strQueue->deQueue() << '\n';
    std::cout << strQueue->deQueue() << '\n';

    std::cout << "Queue is empty: " << strQueue->isEmpty() << '\n';

    try
    {
        std::cout << strQueue->deQueue() << '\n';
    }
    catch (const QueueUnderflow& e)
    {
        std::cout << e.what() << '\n';
    }

    delete strQueue;
}

void testBrackets()
{
    std::cout << "Brackets Test--------------------\n";
    std::cout << "Correct:\n";
    std::cout << checkBalanceBrackets("()[]{}({[]}[{}])", 10) << '\n';
    std::cout << checkBalanceBrackets("()", 10) << '\n';
    std::cout << checkBalanceBrackets("(8)*{5/[8-9*(2-a)]}", 10) << '\n';
    std::cout << "Incorrect:\n";
    std::cout << checkBalanceBrackets("(()", 10) << '\n';
    std::cout << checkBalanceBrackets("()}", 10) << '\n';
    std::cout << checkBalanceBrackets("({[])}", 10) << '\n';
    std::cout << checkBalanceBrackets("({[()]})", 2) << '\n';
}

int main()
{
    testStack();
    testQueue();
    testBrackets();

    return 0;
}

