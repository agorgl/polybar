#pragma once

#include "common.hpp"

POLYBAR_NS

namespace factory_util {
  struct null_deleter {
    template <typename T>
    void operator()(T*) const {}
  };

  template <class InstanceType, class... Deps>
  unique_ptr<InstanceType> generic_instance(Deps... deps) {
    return make_unique<InstanceType>(deps...);
  }

  template <class InstanceType, class... Deps>
  shared_ptr<InstanceType> generic_singleton(Deps... deps) {
    static auto instance = make_shared<InstanceType>(deps...);
    return instance;
  }
}

POLYBAR_NS_END
