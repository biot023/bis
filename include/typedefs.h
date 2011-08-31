#pragma once

#include <memory>

typedef unsigned int uint;
typedef unsigned long ulong;
typedef long long llong;
typedef unsigned long long ullong;

template <typename T>
struct sptr {
  typedef std::shared_ptr<T> t;
};

template <typename T>
struct wptr {
  typedef std::weak_ptr<T> t;
};
