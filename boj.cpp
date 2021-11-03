#include <iostream>
using namespace std;

char* mystrcat(const char* str1, const char* str2)
{
    int i = 0, len1 = 0, len2 = 0;

    while (1)
    {
        if (str1[i] == '\0')
        {
          len1 = i;
          break;
        }
        i++;
    }

    i = 0;
    while (1)
    {
        if (str2[i] == '\0')
        {
          len2 = i;
          break;
        }
        i++;
    }

    char* ret = new char[len1 + len2 +1];

    i = 0;
    while (*str1)
    {
        ret[i] = *str1;
        str1++;
        i++;
    }

    i = len1;
    while (*str2)
    {
        ret[i] = *str2;
        str2++;
        i++;
    }

    ret[len1 + len2] = '\0';

    return ret;
}
int main()
{
    char* str = mystrcat("Hello!", "World!");
    cout << str << endl;
}
