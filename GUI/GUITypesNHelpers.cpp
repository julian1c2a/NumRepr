#include "GUITypesNHelpers.hpp"
#include <QMainWindow>
#include "mainwindow.hpp"
//#include "./ui_mainwindow.h"
//#include "mainwindow.hpp"
#include <string>

bool objeto_completo(const QString &uiObj_0, // nombre string QString
                     const int &uiObj_1,     // tipo   int -> tipo_o_plantilla_de_tipo_e
                     const QString &uiObj_2, // base   numero QString
                     const QString &uiObj_3, // longPE numero QString
                     const QString &uiObj_4, // longPF numero QString
                     const QString &uiObj_5  // valor  numero QString
)
{
    bool ok_nombre;
    const std::string nombre{uiObj_0.toStdString()};
    if (nombre != "") {
        ok_nombre = true;
    } else {
        ok_nombre = false;
        return false;
    }

    bool ok_tipo;
    if ((uiObj_1 >= 1) && (uiObj_1 <= 12)) {
        ok_tipo = true;
    } else {
        ok_tipo = false;
        return false;
    }
    const tipo_o_plantilla_de_tipo_e tipo{a_tipoenum(uiObj_1)};

    bool ok_base;
    bool ok_sem_base;
    const ullint_t base{uiObj_2.toULongLong(&ok_base)};
    if (ok_base) {
        if ((base > 1) && (base < 66)) {
            ok_sem_base = true;
        } else {
            ok_sem_base = false;
        }
    } else {
        ok_sem_base = false;
    }

    bool ok_longPE;
    bool ok_sem_longPE;
    const ullint_t longPE{uiObj_3.toULongLong(&ok_longPE)};
    if (ok_longPE) {
        if ((longPE > 0) && (longPE < 33)) {
            ok_sem_longPE = true;
        } else {
            ok_sem_longPE = false;
        }
    } else {
        ok_sem_longPE = false;
    }

    bool ok_longPF;
    bool ok_sem_longPF;
    const ullint_t longPF{uiObj_4.toULongLong(&ok_longPF)};
    if (ok_longPF) {
        if ((longPF > 0) && (longPF < 33)) {
            ok_sem_longPF = true;
        } else {
            ok_sem_longPF = false;
        }
    } else {
        ok_sem_longPF = false;
    }

    bool ok_valor_sint;
    bool ok_valor_uint;
    bool ok_valor_ldbl;
    [[maybe_unused]] sllint_t valor_sint{uiObj_5.toLongLong(&ok_valor_sint)};
    [[maybe_unused]] ullint_t valor_uint{uiObj_5.toULongLong(&ok_valor_uint)};
    [[maybe_unused]] ldouble_t valor_ldbl{static_cast<ldouble_t>(uiObj_5.toDouble(&ok_valor_ldbl))};
    if (ok_tipo) {
        switch (tipo) {
        case tipo_o_plantilla_de_tipo_e::longlong: {
            if (ok_valor_sint) {
                return (ok_nombre);
            } else {
                return false;
            }
        }
        case tipo_o_plantilla_de_tipo_e::unsignedlonglong: {
            if (ok_valor_uint) {
                return (ok_nombre);
            } else {
                return false;
            }
        }
        case tipo_o_plantilla_de_tipo_e::longdouble: {
            if (ok_valor_ldbl) {
                return (ok_nombre);
            } else {
                return false;
            }
        }
        case tipo_o_plantilla_de_tipo_e::digito: {
            if (ok_base && ok_sem_base && ok_valor_sint) {
                return (ok_nombre);
            } else {
                return false;
            }
        }
        case tipo_o_plantilla_de_tipo_e::registro: {
            if (ok_base && ok_sem_base && ok_longPE && ok_sem_longPE && ok_valor_uint) {
                return (ok_nombre);
            } else {
                return false;
            }
        }
        case tipo_o_plantilla_de_tipo_e::regnatural: {
            if (ok_base && ok_sem_base && ok_longPE && ok_sem_longPE && ok_valor_uint) {
                return (ok_nombre);
            } else {
                return false;
            }
        }
        case tipo_o_plantilla_de_tipo_e::regentero: {
            if (ok_base && ok_sem_base && ok_longPE && ok_sem_longPE && ok_valor_sint) {
                return (ok_nombre);
            } else {
                return false;
            }
        }
        case tipo_o_plantilla_de_tipo_e::racionalnat: {
            if (ok_base && ok_sem_base && ok_longPE && ok_sem_longPE && ok_longPF && ok_sem_longPF
                && ok_valor_uint) {
                return (ok_nombre);
            } else {
                return false;
            }
        }
        case tipo_o_plantilla_de_tipo_e::racionalent: {
            if (ok_base && ok_sem_base && ok_longPE && ok_sem_longPE && ok_longPF && ok_sem_longPF
                && ok_valor_sint) {
                return (ok_nombre);
            } else {
                return false;
            }
        }
        case tipo_o_plantilla_de_tipo_e::natural: {
            if (ok_base && ok_sem_base && ok_valor_uint) {
                return (ok_nombre);
            } else {
                return false;
            }
        }
        case tipo_o_plantilla_de_tipo_e::entero: {
            if (ok_base && ok_sem_base && ok_valor_sint) {
                return (ok_nombre);
            } else {
                return false;
            }
        }
        case tipo_o_plantilla_de_tipo_e::desconocido:
        default: {
            return false;
        }
        }
    } else {
        return false;
    }
}

tipo_variant_e a_tipo_variant_e(int ind)
{
    switch (ind) {
    case 0:
        return tipo_variant_e::longlong;
    case 1:
        return tipo_variant_e::unsignedlonglong;
    case 2:
        return tipo_variant_e::longdouble;
    case 3:
        return tipo_variant_e::digito;
    case 4:
    default:
        return tipo_variant_e::desconocido;
    }
}

int a_indice(tipo_variant_e case_enum)
{
    switch (case_enum) {
    case tipo_variant_e::longlong:
        return 0;
    case tipo_variant_e::unsignedlonglong:
        return 1;
    case tipo_variant_e::longdouble:
        return 2;
    case tipo_variant_e::digito:
        return 3;
    case tipo_variant_e::desconocido:
    default:
        return 4;
    }
}

tipo_o_plantilla_de_tipo_e a_tipoenum(int index)
{
    switch (index) {
    case 0:
        return tipo_o_plantilla_de_tipo_e::longlong;
    case 1:
        return tipo_o_plantilla_de_tipo_e::unsignedlonglong;
    case 2:
        return tipo_o_plantilla_de_tipo_e::longdouble;
    case 3:
        return tipo_o_plantilla_de_tipo_e::digito;
    case 4:
        return tipo_o_plantilla_de_tipo_e::registro;
    case 5:
        return tipo_o_plantilla_de_tipo_e::regnatural;
    case 6:
        return tipo_o_plantilla_de_tipo_e::regentero;
    case 7:
        return tipo_o_plantilla_de_tipo_e::racionalnat;
    case 8:
        return tipo_o_plantilla_de_tipo_e::racionalent;
    case 9:
        return tipo_o_plantilla_de_tipo_e::natural;
    case 10:
        return tipo_o_plantilla_de_tipo_e::entero;
    default:
        return tipo_o_plantilla_de_tipo_e::desconocido;
    }
}

int a_indice(tipo_o_plantilla_de_tipo_e case_enum)
{
    switch (case_enum) {
    case tipo_o_plantilla_de_tipo_e::longlong:
        return 0;
    case tipo_o_plantilla_de_tipo_e::unsignedlonglong:
        return 1;
    case tipo_o_plantilla_de_tipo_e::longdouble:
        return 2;
    case tipo_o_plantilla_de_tipo_e::digito:
        return 3;
    case tipo_o_plantilla_de_tipo_e::registro:
        return 4;
    case tipo_o_plantilla_de_tipo_e::regnatural:
        return 5;
    case tipo_o_plantilla_de_tipo_e::regentero:
        return 6;
    case tipo_o_plantilla_de_tipo_e::racionalnat:
        return 7;
    case tipo_o_plantilla_de_tipo_e::racionalent:
        return 8;
    case tipo_o_plantilla_de_tipo_e::natural:
        return 9;
    case tipo_o_plantilla_de_tipo_e::entero:
        return 10;
    case tipo_o_plantilla_de_tipo_e::desconocido:
    default:
        return -1;
    }
}

std::string a_texto(tipo_o_plantilla_de_tipo_e case_enum)
{
    switch (case_enum) {
    case tipo_o_plantilla_de_tipo_e::longlong:
        return static_cast<std::string>("entero C++ built-in");
    case tipo_o_plantilla_de_tipo_e::unsignedlonglong:
        return static_cast<std::string>("entero sin signo C++ built-in");
    case tipo_o_plantilla_de_tipo_e::longdouble:
        return static_cast<std::string>("flotante C++ built-in");
    case tipo_o_plantilla_de_tipo_e::digito:
        return static_cast<std::string>("variant digito");
    case tipo_o_plantilla_de_tipo_e::registro:
        return static_cast<std::string>("variant registro");
    case tipo_o_plantilla_de_tipo_e::regnatural:
        return static_cast<std::string>("variant registro natural");
    case tipo_o_plantilla_de_tipo_e::regentero:
        return static_cast<std::string>("variant registro entero");
    case tipo_o_plantilla_de_tipo_e::racionalnat:
        return static_cast<std::string>("variant racional natural");
    case tipo_o_plantilla_de_tipo_e::racionalent:
        return static_cast<std::string>("variant racional entero");
    case tipo_o_plantilla_de_tipo_e::natural:
        return static_cast<std::string>("variant natural");
    case tipo_o_plantilla_de_tipo_e::entero:
        return static_cast<std::string>("variant entero");
    case tipo_o_plantilla_de_tipo_e::desconocido:
    default:
        return static_cast<std::string>("desconocido");
    }
}

void create_variable(const std::string &nombre,
                     datos_de_entrada_desde_ui &objeto,
                     auto &ll_lista,
                     auto &ull_lista,
                     auto &ld_lista,
                     auto &digito_lista)
{
    if (!nombre.empty()) {
        objeto.nombre = nombre;
    } else {
        objeto.nombre = llint_varlist_t::default_name; // El nombre por defecto es igual
                                                       // en todas las listas
    }

    switch (objeto.tipo) {
    case tipo_o_plantilla_de_tipo_e::longlong: {
        objeto.valor = QString::fromStdString(nombre).toLongLong();
        ll_lista.create_var(objeto.nombre, std::get<sllint_t>(objeto.valor));
        if (ull_lista.contains(nombre)) {
            ull_lista.erase_var(nombre);
        } else if (ld_lista.contains(nombre)) {
            ld_lista.erase_var(nombre);
        } else if (digito_lista.contains(nombre)) {
            digito_lista.erase_var(nombre);
        }
    } break;
    case tipo_o_plantilla_de_tipo_e::unsignedlonglong: {
        objeto.valor = (QString::fromStdString(nombre)).toULongLong();
        ull_lista.create_var(objeto.nombre, std::get<ullint_t>(objeto.valor));
    } break;
    case tipo_o_plantilla_de_tipo_e::longdouble: {
        objeto.valor = static_cast<ldouble_t>(QString::fromStdString(nombre).toDouble());
        ld_lista.create_var(objeto.nombre, std::get<ldouble_t>(objeto.valor));
    } break;
    case tipo_o_plantilla_de_tipo_e::digito: {
        objeto.valor = make_digit_variant(objeto.base,
                                          (QString::fromStdString(nombre)).toLongLong());
        digito_lista.create_var(objeto.nombre, std::get<digit_variant>(objeto.valor));
    } break;
    case tipo_o_plantilla_de_tipo_e::desconocido:
    default: {
    }
    }
}
