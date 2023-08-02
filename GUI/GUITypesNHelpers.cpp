#include "GUITypesNHelpers.hpp"

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
