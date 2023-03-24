#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Stack.h"
#include"StackArray.h"
#include "QueueArray.h"
#include "CheckBalanceBrackets.h"
#include <cctype>

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

char* process(char* dest, const char* src, const int queueSize) {
    QueueArray<char> queue(queueSize);
    if (!(checkBalanceBrackets(src, 1)) ){
        throw std::invalid_argument("invalid src\n");
    }
    size_t k = 0;
    while (*src && (isalpha(*src) || *src == '[' || *src ==' ')) {
        if (*src == '[') {
            src++;
            while (*src != ']' && *src) {
                if (isalpha(*src) || *src == ' ') {
                    queue.enQueue(*src);
                }
                else {
                    throw std::invalid_argument("invalid src\n");
                }
                src++;
            }
            if (*src == ']') {
                src++;
                continue;
            }
        }
        else {
            dest[k] = *src;
            k++;
        }
        src++;
    }
    while (!queue.isEmpty()) {
        dest[k] = queue.deQueue();
        k++;
    }
    dest[k] = '\0';
    return dest;
}

int main()
{
    char string [] = "Fall seven [times an]d sta[nd up] eight";
    char dest[] = "                                         ";
    try {
        std::cout << process(dest, string, 55)<<'\n';
    }
    catch (std::exception& error) {
        std::cout << error.what();
        return -1;
    }
    char string1[] = "abcd[efgh]";
    char dest1[] = "                                         ";
    try {
        std::cout << process(dest1, string1, 55)<<'\n';
    }
    catch (std::exception& error) {
        std::cout << error.what();
        return -1;
    }
    char string2[] = "[efgh]abcd";
    char dest2[] = "                                         ";
    try {
        std::cout << process(dest2, string2, 55);
    }
    catch (std::exception& error) {
        std::cout << error.what();
        return -1;
    }
    return 0;
}

