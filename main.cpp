#include <iostream>
#include "container.hpp"

int main()
{

    using namespace container;
    Container<int> con;
    for (int i = 0; i < 5; i++)
    {
        con.push_back(i);
        std::cout << i << std::endl;
    }
    std::cout<< "size " << con.size()<<std::endl;
    for (auto &item : con){
        std::cout<< item << std::endl;
    }
    return 0;
}
