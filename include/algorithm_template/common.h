#ifndef ALGORITHM_TEMPLATE_COMMON_H
#define ALGORITHM_TEMPLATE_COMMON_H

#include <concepts>
#include <sstream>
namespace algorithm_template {

template <typename T>
concept Streamable = requires(std::ostream& os, T t) {
  { os << t } -> std::convertible_to<std::ostream&>;
};
}  // namespace algorithm_template

#endif // ALGORITHM_TEMPLATE_COMMON_H