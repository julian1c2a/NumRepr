#ifndef AUXILIARY_FUNCTIONS_HPP_INCLUDED
#define AUXILIARY_FUNCTIONS_HPP_INCLUDED

#include <cmath>
#include <cstddef>
#include <cstdint>
#include <numeric>
namespace NumRepr {

namespace detail {

// precondition: low*low <= n, high*high > n.
constexpr std::size_t ceilsqrt(std::size_t n, std::size_t low, std::size_t high) noexcept
{
    const auto mid{std::midpoint(low, high)};
    const auto sqmid{mid * mid};
    return ((low + 1 >= high) ? high
            : (sqmid == n)    ? mid
            : (sqmid < n)     ? ceilsqrt(n, mid, high)
                              : ceilsqrt(n, low, mid));
}

// returns ceiling(sqrt(n))
constexpr std::size_t ceilsqrt(std::size_t n) noexcept
{
    const auto num_max_dig{std::numeric_limits<std::size_t>::digits};
    return ((n < 3) ? n : ceilsqrt(n, 1, std::size_t(1) << (num_max_dig / 2)));
}

// returns true if n divisible by an odd integer in
// [2 * low + 1, 2 * high + 1).
constexpr bool find_factor(std::size_t n, std::size_t low, std::size_t high) noexcept
{
    const auto mid{std::midpoint(low, high)};
    return ((low + 1 >= high) ? (n % (2 * low + 1)) == 0
                              : (find_factor(n, low, mid) || find_factor(n, mid, high)));
}

} // namespace detail

namespace auxiliary_functions {

constexpr bool is_prime(std::size_t n) noexcept
{
    if (n < 2)
        return false;
    else if ((n == 2) || (n == 3))
        return true;
    else
        return (!detail::find_factor(n, 1, (detail::ceilsqrt(n) + 1) / 2));
}

constexpr bool is_power_of_2(std::uint64_t num) noexcept
{
    if ((num % 2) != 0)
        return false;
    else
        return is_power_of_2(num / 2);
}

} // namespace auxiliary_functions
} // namespace NumRepr

#endif // AUXILIARY_FUNCTIONS_HPP_INCLUDED
