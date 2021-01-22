//使用这个代替#ifdef#endif
//_Pragma("once")
#include <iostream>
#include "Hanoi/hanoi.hpp"
#include <list>
#include "Sort/sort.hpp"
#include <iostream>
#include "ConvexHull/ConvexHull.hpp"
#include <algorithm>

// class A
// {
// };
// template<typename...Ts>
// constexpr int sum(Ts...args) {
//   return (0+...+args);
// }
// int main(int argc,char** argv)
// {
//   char *p;
//   Hanoi<2> h;
// #ifdef UNIX
//   std::cout<<"Linux"<<std::endl;
// #elif WIN32
//   std::cout<<"Windows"<<std::endl;
// #endif 
// }

class B
{
public:
void f() {
    static int j = 0;
    std::cout<<"class B:"<<j++<<std::endl;
}

};
class A
{
public:
void f()
{
    static int i = 0;
    std::cout<<"class A:"<<i++<<std::endl;
}
void (A::*f_p)();
void (B::*f_p1)();

};

int main() { 

    std::cout<<"Hello,World";

    
}
