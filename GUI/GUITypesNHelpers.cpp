#include "GUITypesNHelpers.hpp"
#include <QMainWindow>
//#include "./ui_mainwindow.h"
//#include "mainwindow.hpp"
#include <string>

//bool objeto_completo(const datos_de_entrada_desde_ui &obj)
//{
//    if (obj.tipo != tipo_o_plantilla_de_tipo_e::desconocido) {
//        switch (obj.tipo) {
//        case tipo_o_plantilla_de_tipo_e::longlong: {
//            const bool ret{ };
//        }
//        case tipo_o_plantilla_de_tipo_e::unsignedlonglong: {
//            const bool ret{};
//        }

//        case tipo_o_plantilla_de_tipo_e::longdouble:
//        case tipo_o_plantilla_de_tipo_e::digito:
//        case tipo_o_plantilla_de_tipo_e::registro:
//        case tipo_o_plantilla_de_tipo_e::regnatural:
//        case tipo_o_plantilla_de_tipo_e::regentero:
//        case tipo_o_plantilla_de_tipo_e::racionalnat:
//        case tipo_o_plantilla_de_tipo_e::racionalent:
//        case tipo_o_plantilla_de_tipo_e::natural:
//        case tipo_o_plantilla_de_tipo_e::entero:
//        case tipo_o_plantilla_de_tipo_e::desconocido:
//            break;
//        }
//    } else {
//        return false;
//    }
//}

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
