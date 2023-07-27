#ifndef MEMORY_HANDLER_HPP_INCLUDED
#define MEMORY_HANDLER_HPP_INCLUDED

#include <variant>

#include <string>
#include <ostream>
#include <map>
#include <set>

namespace NumRepr {
namespace MemHand {

using namespace std::literals::string_literals;

template<typename VALUE_TYPE>
using varmap_t = typename std::map<std::string, VALUE_TYPE>;

template<class Variant_t>
struct TC_varlist_t : public varmap_t<Variant_t>
{
public:
    using key_t = typename std::string;
    using value_t = Variant_t;
    using node_t = typename std::pair<key_t, value_t>;
    using varlist_t = varmap_t<value_t>;

protected:
    TC_varlist_t(const TC_varlist_t &) = delete;
    TC_varlist_t(TC_varlist_t &&) = delete;
    TC_varlist_t &operator=(const TC_varlist_t &) = delete;
    TC_varlist_t &operator=(TC_varlist_t &&) = delete;

public:
    inline static const value_t default_value{Variant_t()};
    inline static const key_t default_name{"default_name"s};
    inline static const std::size_t max_size{64ull};

public:
    TC_varlist_t()
        : varlist_t{}
    {
        this->varlist_t::insert({default_name, default_value});
    }

    std::size_t size() const { return this->varlist_t::size(); }

    bool contains(key_t nombre) const { return this->varlist_t::contains(nombre); }

    bool not_fully() const { return (this->varlist_t::size() < max_size); }

    bool assign(key_t nombre, value_t valor)
    {
        if (contains(nombre)) {
            this->varlist_t::operator[](nombre) = valor;
            return true;
        } else if (not_fully()) {
            this->varlist_t::insert({nombre, valor});
            return true;
        } else
            return false;
    }

    const value_t &operator[](key_t nombre) const
    {
        if (contains(nombre)) {
            return (this->varlist_t::operator[](nombre));
        } else if (not_fully()) {
            this->varlist_t::insert({nombre, default_value});
            return (this->varlist_t::operator[](nombre));
        } else {
            this->varlist_t::operator[](default_name) = default_value;
            return (this->varlist_t::operator[](default_name));
        }
    }

    value_t &operator[](key_t nombre)
    {
        if (contains(nombre)) {
            return (this->varlist_t::operator[](nombre));
        } else if (not_fully()) {
            this->insert({nombre, default_value});
            return (this->varlist_t::operator[](nombre));
        } else {
            this->varlist_t::operator[](default_name) = default_value;
            return (this->varlist_t::operator[](default_name));
        }
    }

    bool erase_var(key_t nombre)
    {
        if (contains(nombre)) {
            this->varlist_t::erase(nombre);
            return true;
        }
        return false;
    }
};

} // namespace memory_handler
} // namespace NumRepr
#endif // MEMORY_HANDLER_HPP_INCLUDED
