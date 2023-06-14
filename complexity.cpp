#include <iostream>
#include <cstdio>

using namespace std;

template<typename T>
T Localmax(T x, T y)
{
     return (x > y) ? x : y;
}

#define MAX(a,b) \
    a > b ? a : b

int main(int argc, char *argv[])
{
     float x = 100.f;
     float y = 120.f;

     cout << Localmax<float>(x, y) << endl;
     cout << (x > y ? x : y) << endl;

     return 0;
}
