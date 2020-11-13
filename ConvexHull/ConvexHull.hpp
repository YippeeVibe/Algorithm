#include <vector>
#include <type_traits>
#include <iostream>
/*
1. 使用模板在编译器定义生成返回。（当然也可以使用宏，但是并不是最好的选择。）(has do)
2. 
*/
enum class PointCompareType {
  CompareX,
  CompareY,
  CompareXY
};
template<typename T = int,PointCompareType compareT = PointCompareType::CompareXY>
struct Point {
    Point(T x,T y)
      :x(x),y(y) {  
       static_assert(std::is_arithmetic<T>::value == true, "Type must be arithmetic");
      }
    T x;
    T y;
    friend bool operator <(const Point<T,compareT>& l_p,const Point<T,compareT>& r_p) {
      if constexpr(compareT == PointCompareType::CompareXY) {
        static_assert(compareT == PointCompareType::CompareXY,"Choiced PointCompareType can't work!");
      } else if (compareT == PointCompareType::CompareX) {
        if(l_p.x<r_p.x)
          return true;
        else
          return false;
      } else if (compareT == PointCompareType::CompareY) {
        if(l_p.y<r_p.y)
          return true;
        else
          return false;
      }
    }
    friend bool operator >(const Point<T,compareT>& l_p,const Point<T,compareT>& r_p) {
      return !(l_p<r_p);
    }
    friend bool operator == (const Point<T,compareT>& l_p,const Point<T,compareT>& r_p) {
      if constexpr(compareT == PointCompareType::CompareXY) {
        if (l_p.x == r_p.x&&l_p.y == r_p.y)
          return true;
        else 
          return false;                
      } else if (compareT == PointCompareType::CompareX) {
        if(l_p.x == r_p.x)
          return true;
        else
          return false;
      } else if (compareT == PointCompareType::CompareY) {
        if(l_p.y == r_p.y)
          return true;
        else
          return false;
      }
    }
    friend bool operator <=(const Point<T,compareT>& l_p,const Point<T,compareT>& r_p) {
      if(l_p < r_p||r_p == l_p) 
        return true;
      else
        return false;     
    }
    friend bool operator >= (const Point<T,compareT>& l_p,const Point<T,compareT>& r_p) {
      return !l_p<=r_p;
    }
    friend std::ostream& operator <<(std::ostream& os,const Point<T,compareT>& p) {
      os<<"("<<p.x<<","<<p.y<<")";
      return os;
    }
};

template<typename T = int>
class ConvexHull {
public:
  ConvexHull(std::vector<T>& p)
    :pointS(pointS) {
    static_assert(std::is_arithmetic<T>::value == true, "");
  }
  std::vector<T> pointS;

};

template<typename T = int>
class ConvexHullControl {
public:
  ConvexHullControl(std::vector<T>& p)
    :tem_pointS(p) {
    static_assert(std::is_arithmetic<T>::value == true, "");

  }
private:
  std::vector<T> tem_pointS;

  std::vector<ConvexHull<T>> convexhullS;
};
