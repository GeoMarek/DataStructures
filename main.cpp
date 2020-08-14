#include <iostream>
#include "List.h"
using namespace std;
int main()
{
    List<int> intList;
    intList.Insert(0, 21);
    intList.Insert(1, 47);



    List<double> doubleList;
    doubleList.Insert(0, 11.11);
    doubleList.Insert(1, 22.22);

    List<std::string> stringList;
    stringList.Insert(0, "marek");
    stringList.Insert(1, "grudkowski");



    return 0;
}