#ifndef VARLIST_DEFINITIONS_H
#define VARLIST_DEFINITIONS_H

#include "memory_handler.hpp"
#include "digit_variant_t.hpp"

namespace NumRepr {
namespace MemHand {

using sllint_t = signed long long int;
using ullint_t = unsigned long long int;
using ldouble_t = long double;

struct ullint_varlist_t : public TC_varlist_t<ullint_t>
{
public:
    using value_t = ullint_t;
    using base_t = TC_varlist_t<value_t>;
    using key_t = typename base_t::key_t;
    ullint_varlist_t() = default;
    bool create_var(key_t nombre, value_t valor)
    {
        if (!contains(nombre) && not_fully()) {
            this->insert({nombre, valor});
            return true;
        }
        return false;
    }
};

struct llint_varlist_t : public TC_varlist_t<sllint_t>
{
public:
    using value_t = sllint_t;
    using base_t = typename NumRepr::MemHand::TC_varlist_t<value_t>;
    using key_t = typename base_t::key_t;
    llint_varlist_t() = default;
    bool create_var(std::string nombre, value_t valor)
    {
        if (!contains(nombre) && not_fully()) {
            this->insert({nombre, valor});
            return true;
        }
        return false;
    }
};

struct ld_varlist_t : public TC_varlist_t<ldouble_t>
{
public:
    using value_t = ldouble_t;
    using base_t = typename NumRepr::MemHand::TC_varlist_t<value_t>;
    using key_t = typename base_t::key_t;
    ld_varlist_t() = default;
    bool create_var(key_t nombre, value_t valor)
    {
        if (!contains(nombre) && not_fully()) {
            this->insert({nombre, valor});
            return true;
        }
        return false;
    }
};

struct digit_varlist_t : public TC_varlist_t<digit_variant>
{
public:
    using value_t = digit_variant;
    using base_t = typename NumRepr::MemHand::TC_varlist_t<value_t>;
    using key_t = typename base_t::key_t;

    digit_varlist_t() = default;

    bool create_var(key_t nombre, ullint_t base, sllint_t valor)
    {
        if (!contains(nombre) && not_fully()) {
            this->insert({nombre, make_digit_variant(base, valor)});
            return true;
        }
        return false;
    }

    bool create_var(key_t nombre, value_t arg1)
    {
        if (!contains(nombre) && not_fully()) {
            this->insert({nombre, arg1});
            return true;
        }
        return false;
    }
};

} // namespace memory_handler
} // namespace NumRepr

#endif // VARLIST_DEFINITIONS_H
