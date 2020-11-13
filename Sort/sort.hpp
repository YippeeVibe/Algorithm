#ifndef SORT_HPP
#define SORT_HPP

#include <vector>
#include <memory>
#include <type_traits>
#include <functional>
/******************TODO*******************
驾轻就熟的写一堆排序算法。

1. C++元编程：使用模板生成随机数。
2. 使用C++20概念严格类型。
3. 写满十个以上常用排序算法(has 3)。
******************TODO***********************/
enum class sortType
{
  sort_select,
  sort_buble,
  sort_insert,
  sort_shell,
  sort_merge
};
template <typename T = int>
class Sort
{
public:
  Sort(int maxvalue, sortType sorttype = sortType::sort_select)
      : max_value_(maxvalue),
        sort_type_(sorttype)
  {
    static_assert(std::is_integral<T>::value == true, "Type Must Be Int");
    //todo 生成随机数组。
    SetSortType(sort_type_);
    sort_f_(this);
  }
  Sort(std::vector<T> &valueS, sortType sorttype = sortType::sort_select)
      : sort_type_(sorttype)
  {
    //static_assert(std::is_arithmetic<T>::value == true, "必须是可计算类型");
    sort_valueS_.insert(sort_valueS_.begin(), valueS.begin(), valueS.end());
    SetSortType(sort_type_);
    sort_f_(this);
  }

  static std::vector<T> SortVector(std::vector<T>& sort_v) {
    Sort<T> sort(sort_v);
    return sort.GetSorted();
  }

private:
  std::vector<T> sort_valueS_{};
  int max_value_{0};
  sortType sort_type_;

private:
  std::function<void(Sort<T> *)> sort_f_;

public:
  std::vector<T> &GetSorted()
  {
    return sort_valueS_;
  }

private:
  void SetSortType(sortType sorttype)
  {
    switch (sorttype)
    {
    case sortType::sort_select:
    {
      sort_f_ = &Sort::InsertSort;

      break;
    }
    case sortType::sort_buble:
    {
      sort_f_ = &Sort::BubbleSort;
      break;
    }
    case sortType::sort_insert:
    {
      sort_f_ = &Sort::InsertSort;
      break;
    }
    case sortType::sort_shell:
    {
      sort_f_ = &Sort::ShellSort;
      break;
    }
    default:
    {
    }
    }
  }
  void SelectSort()
  {
    for (int i = 0; i < sort_valueS_.size(); ++i)
    {
      for (int j = i + 1; j < sort_valueS_.size(); ++j)
      {
        if (sort_valueS_.at(i) > sort_valueS_.at(j))
          std::swap(sort_valueS_[i], sort_valueS_[j]);
      }
    }
  }
  void InsertSort()
  {
    for (int i = 0; i < sort_valueS_.size() - 1; ++i)
    {
      int j = i + 1;
      while (j >= 1 && sort_valueS_.at(j) < sort_valueS_.at(j - 1))
      {
        std::swap(sort_valueS_[j], sort_valueS_[j - 1]);
        j--;
      }
    }
  }
  void QuickSort()
  {
  }
  void BubbleSort()
  {
    for (int i = 0; i < sort_valueS_.size(); ++i)
    {
      for (int j = 0; j < sort_valueS_.size() - i - 1; ++j)
      {
        if (sort_valueS_.at(j) > sort_valueS_.at(j + 1))
          std::swap(sort_valueS_[j], sort_valueS_[j + 1]);
      }
    }
  }
  void ShellSort()
  {
  }
  void MergeSort()
  {
    return;
  }
  void hellosort()
  {
    return;
  }
};

#endif // SORT_HPP
