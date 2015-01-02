#include "StringUtils.h"

#include <iostream>


using namespace std;

void StringUtils::reverse( std::string &input)
{
    if (input.length() <= 1)
    {
        return;
    }

    int front = 0;
    int back = input.length() - 1;

    while(front != back)
    {
        if( swap(input, front, back))
        {
            front ++;
            back--;
        }
        else
        {
            break;
        }
    }

}

bool StringUtils::swap(string &in, int p1, int p2)
{
    if(p1 < p2 && in.length() > 1)
    {
        char tmp = in[p1];
        in[p1] = in[p2];
        in[p2] = tmp;
        return true;
    }
    else 
    {
        return false;
    }
}
