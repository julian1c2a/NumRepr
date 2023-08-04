#ifndef GUITYPESNHELPERS_HPP
#define GUITYPESNHELPERS_HPP

#include "../include/digit_variant_t.hpp"
#include "../include/varlist_definitions.hpp"
//#include "./ui_mainwindow.h"

using llint_varlist_t = typename NumRepr::MemHand::llint_varlist_t;
using ullint_varlist_t = typename NumRepr::MemHand::ullint_varlist_t;
using ld_varlist_t = typename NumRepr::MemHand::ld_varlist_t;
using digit_varlist_t = typename NumRepr::MemHand::digit_varlist_t;
using NumRepr::make_digit_variant;
using sllint_t = signed long long int;
using ullint_t = unsigned long long int;
using ldouble_t = long double;

enum class tipo_o_plantilla_de_tipo_e {
    longlong,
    unsignedlonglong,
    longdouble,
    digito,
    registro,
    regnatural,
    regentero,
    racionalnat,
    racionalent,
    natural,
    entero,
    desconocido
};

using NumRepr::digit_variant;
using valor_t = std::variant<sllint_t, ullint_t, ldouble_t, digit_variant>;
enum class tipo_variant_e { longlong, unsignedlonglong, longdouble, digito, desconocido };

tipo_variant_e a_tipo_variant_e(int ind);

int a_indice(tipo_variant_e case_enum);

struct datos_de_entrada_desde_ui
{
    std::string nombre;
    ullint_t base;
    valor_t valor;
    ullint_t longPE;
    ullint_t longPF;
    tipo_o_plantilla_de_tipo_e tipo;
};

tipo_o_plantilla_de_tipo_e a_tipoenum(int index);

int a_indice(tipo_o_plantilla_de_tipo_e case_enum);

std::string a_texto(tipo_o_plantilla_de_tipo_e case_enum);

bool objeto_completo(const auto &uiObj_0,
                     const auto &uiObj_1,
                     const auto &uiObj_2,
                     const auto &uiObj_3,
                     const auto &uiObj_4,
                     const auto &uiObj_5);

//void on_lineEdit_nombre_textEdited(const std::string &arg1,
//                                   auto &objeto,
//                                   std::size_t indice,
//                                   auto &ll_lista,
//                                   auto &ull_lista,
//                                   auto &ld_lista,
//                                   auto &digito_lista)
//{
//    if (!arg1.empty()) {
//        objeto[indice].nombre = arg1;
//    } else {
//        objeto[indice].nombre = llint_varlist_t::default_name;
//    }

//    switch (objeto[indice].tipo) {
//    case tipo_o_plantilla_de_tipo_e::longlong:
//        objeto[indice].valor = arg1.toLongLong();
//        ll_lista.create_var(objeto[indice].nombre, std::get<sllint_t>(objeto[indice].valor));
//        break;
//    case tipo_o_plantilla_de_tipo_e::unsignedlonglong:
//        objeto[indice].valor = arg1.toULongLong();
//        ull_lista.create_var(objeto[indice].nombre, std::get<ullint_t>(objeto[indice].valor));
//        break;
//    case tipo_o_plantilla_de_tipo_e::longdouble:
//        objeto[indice].valor = static_cast<ldouble_t>(arg1.toDouble());
//        ld_lista.create_var(objeto[indice].nombre, std::get<ldouble_t>(objeto[indice].valor));
//        break;
//    case tipo_o_plantilla_de_tipo_e::digito:
//        objeto[indice].valor = make_digit_variant(objeto[0].base, arg1.toLongLong());
//        digito_lista.create_var(objeto[indice].nombre,
//                                std::get<digit_variant>(objeto[indice].valor));
//        break;
//    case tipo_o_plantilla_de_tipo_e::desconocido:
//    default:;
//    }
//}

#endif // GUITYPESNHELPERS_HPP
