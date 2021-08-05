#include "ZxSet.h"
#include <iostream>
using namespace std;
int main(){

    const int size = 6;
    int array[size] = {-1, -1, -1, -1, -1, -1};
    PrintArray(array, size);

    UnionSet(array, 1, 2);
    std::cout << "After union(1,2):\n";
    PrintArray(array, size);

    UnionSet(array, 0, 2);
    std::cout << "After union(0,2):\n";
    PrintArray(array, size);

    UnionSet(array, 3, 5);
    std::cout << "After union(3,5):\n";
    PrintArray(array, size);

    UnionSet(array, 2, 5);
    std::cout << "After union(2,5):\n";
    PrintArray(array, size);


    std::cout << "element(5) belongs to Set(" << FindSetCollapsing(array, 5) << ").\n";
    std::cout << "After collapsing:\n";
    PrintArray(array, size);

    return 0;
}