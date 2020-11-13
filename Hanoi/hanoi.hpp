#ifndef HANOI_HPP
#define HANOI_HPP
#include <cassert>
#include <list>
#include <memory>
#include <tuple>
#include <functional>
#include <iostream>
#include <memory>
namespace HanoiTest
{
  int move = 1;
  void f(std::list<int> *L, std::list<int> *C, std::list<int> *R)
  {
    for (auto &X : *L)
    {
      std::cout << X << " ";
    }
    std::cout << std::endl;
    for (auto &X : *C)
    {
      std::cout << X << " ";
    }
    std::cout << std::endl;
    for (auto &X : *R)
    {
      std::cout << X << " ";
    }
    std::cout << std::endl;
    std::cout << "ssssssss " << move++ << " ssssssss" << std::endl;
  }

} // namespace HanoiTest
template <int Size = 5>
class Hanoi
{
public:
  Hanoi(std::function<void(std::list<int> *, std::list<int> *, std::list<int> *)> f = HanoiTest::f)
      : max_value_(Size),
        SendTowerCurrentValue(f)
  {
    static_assert(Size <= 10, "Size should <= 10");
    for (int i = 1; i <= Size; ++i)
    {
      L_tower_.push_front(i);
    }
    HanoiStart(max_value_, &L_tower_, &C_tower_, &R_tower_);
  }

private:
  std::list<int> L_tower_;
  std::list<int> C_tower_;
  std::list<int> R_tower_;
  int max_value_;

public:
  std::function<void(std::list<int> *, std::list<int> *, std::list<int> *)> SendTowerCurrentValue;
  //使用tuple构造时，很难指定需要的是引用还是复制。使用 std::ref()显式声明
  auto GetCurrentTower()
  {
    return std::make_tuple(std::ref(L_tower_), std::ref(C_tower_), std::ref(R_tower_));
  }

private:
  //在运动的步骤中给出静止量。根据静止量确定更多的边界。 每次最大的数如果不移动它，都是可以无视的。ll
  void HanoiStart(int n, std::list<int> *x, std::list<int> *y, std::list<int> *z)
  {
    if (n > 0)
    {
      HanoiStart(n - 1, x, z, y);
      int value = x->back();
      x->pop_back();
      y->push_back(value);
      SendTowerCurrentValue(&L_tower_, &C_tower_, &R_tower_);
      HanoiStart(n - 1, z, y, x);
    }
  }
};

#endif // HANOI_HPP
