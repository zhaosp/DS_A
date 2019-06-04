#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

template <typename T1, typename T2>
int compare(T1 v, T2 w) {
    if(v < w)
        return -1;
    else if(v > w)
        return 1;
    else
        return 0;
}


int main() {
    printf("%p\t%p\n", "hi", "world");
    printf("%d\n", compare("hi", "world"));
    printf("%d\n", compare(string("hi"), string("world")));

    return 0;
}