#include "mainwindow.hpp"
#include "../include/digit_variant_t.hpp"
#include "../include/memory_handler.hpp"
#include "../include/varlist_definitions.hpp"
#include "./ui_mainwindow.h"

using llint_varlist_t = typename NumRepr::MemHand::llint_varlist_t;
using ullint_varlist_t = typename NumRepr::MemHand::ullint_varlist_t;
using ld_varlist_t = typename NumRepr::MemHand::ld_varlist_t;
using digit_varlist_t = typename NumRepr::MemHand::digit_varlist_t;
using NumRepr::make_digit_variant;
using sllint_t = signed long long int;
using ullint_t = unsigned long long int;
using ldouble_t = long double;

enum tipo_o_plantilla_de_tipo_e {
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

struct datos_de_entrada_desde_ui
{
    std::string nombre;
    unsigned long long base;
    valor_t valor;
    unsigned long long longPE;
    unsigned long long longPF;
    tipo_o_plantilla_de_tipo_e tipo;
};

datos_de_entrada_desde_ui objeto[3];

llint_varlist_t ll_lista{};
ullint_varlist_t ull_lista{};
ld_varlist_t ld_lista{};
digit_varlist_t digito_lista{};
//variable_list_t<reg_digs_t> registro_lista{};
//variable_list_t<nat_reg_t> natural_reg_lista{};
//variable_list_t<int_reg_t> entero_reg_lista{};
//variable_list_t<rat_nat_t> racional_natural_lista{};
//variable_list_t<rat_int_t> racional_entero_lista{};
//variable_list_t<natural_t> natural_lista{};
//variable_list_t<integer_t> entero_lista{};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_nombre_in_1_textChanged(const QString &arg1)
{
    objeto[0].nombre = arg1.toStdString();
}

void MainWindow::on_lineEdit_nombre_in_2_textChanged(const QString &arg1)
{
    objeto[1].nombre = arg1.toStdString();
}

tipo_o_plantilla_de_tipo_e a_tipoenum(int index)
{
    switch (index) {
    case 0:
        return longlong;
    case 1:
        return unsignedlonglong;
    case 2:
        return longdouble;
    case 3:
        return digito;
    case 4:
        return registro;
    case 5:
        return regnatural;
    case 6:
        return regentero;
    case 7:
        return racionalnat;
    case 8:
        return racionalent;
    case 9:
        return natural;
    case 10:
        return entero;
    default:
        return desconocido;
    }
}

int a_indice(tipo_o_plantilla_de_tipo_e case_enum)
{
    switch (case_enum) {
    case longlong:
        return 0;
    case unsignedlonglong:
        return 1;
    case longdouble:
        return 2;
    case digito:
        return 3;
    case registro:
        return 4;
    case regnatural:
        return 5;
    case regentero:
        return 6;
    case racionalnat:
        return 7;
    case racionalent:
        return 8;
    case natural:
        return 9;
    case entero:
        return 10;
    default:
        return -1;
    }
}

void MainWindow::on_comboBox_plantilla_1_currentIndexChanged(int index)
{
    objeto[0].tipo = a_tipoenum(index);
}

void MainWindow::on_comboBox_plantilla_2_currentIndexChanged(int index)
{
    objeto[1].tipo = a_tipoenum(index);
}

void MainWindow::on_lineEdit_Base_1_textEdited(const QString &arg1)
{
    const ullint_t user_radix{arg1.toULongLong()};
    if ((user_radix > 1) && (user_radix < 66))
        objeto[0].base = user_radix;
    //else
    //    throw std::logic_error("El valor de la base ha de estar entre 2 y 65, ambos incluidos");
}

void MainWindow::on_lineEdit_Base_2_textEdited(const QString &arg1)
{
    const ullint_t user_radix{arg1.toULongLong()};
    if ((user_radix > 1) && (user_radix < 66))
        objeto[1].base = user_radix;
    //else
    //    throw std::logic_error("El valor de la base ha de estar entre 2 y 65, ambos incluidos");
}

void MainWindow::on_lineEdit_longitud_PE_1_textChanged(const QString &arg1)
{
    const ullint_t user_length{arg1.toULongLong()};
    if ((user_length > 0) && (user_length < 33))
        objeto[0].longPE = user_length;
    //else
    //    throw std::logic_error("El valor de la longitud ha de estar entre 1 y 32, ambos incluidos");
}

void MainWindow::on_lineEdit_longitud_PE_2_textChanged(const QString &arg1)
{
    const ullint_t user_length{arg1.toULongLong()};
    if ((user_length > 0) && (user_length < 33))
        objeto[0].longPE = user_length;
    //else
    //    throw std::logic_error("El valor de la longitud ha de estar entre 1 y 32, ambos incluidos");
}

void MainWindow::on_lineEdit_longitud_PF_1_textChanged(const QString &arg1)
{
    const ullint_t user_length{arg1.toULongLong()};
    if ((user_length > 0) && (user_length < 33))
        objeto[0].longPF = user_length;
    //else
    //    throw std::logic_error("El valor de la longitud ha de estar entre 1 y 32, ambos incluidos");
}

void MainWindow::on_lineEdit_longitud_PF_2_textChanged(const QString &arg1)
{
    const ullint_t user_length{arg1.toULongLong()};
    if ((user_length > 0) && (user_length < 33))
        objeto[1].longPF = user_length;
    //else
    //    throw std::logic_error("El valor de la longitud ha de estar entre 1 y 32, ambos incluidos");
}

void MainWindow::on_lineEdit_valor_1_textChanged(const QString &arg1)
{
    switch (objeto[0].tipo) {
    case longlong:
        objeto[0].valor = arg1.toLongLong();
        break;
    case unsignedlonglong:
        objeto[0].valor = arg1.toULongLong();
        break;
    case longdouble:
        objeto[0].valor = static_cast<ldouble_t>(arg1.toDouble());
        break;
    case digito:
        objeto[0].valor = make_digit_variant(objeto[0].base, arg1.toLongLong());
        break;
    default:;
    }
}

void MainWindow::on_lineEdit_valor_2_textChanged(const QString &arg1)
{
    switch (objeto[1].tipo) {
    case longlong:
        objeto[1].valor = arg1.toLongLong();
        break;
    case unsignedlonglong:
        objeto[1].valor = arg1.toULongLong();
        break;
    case longdouble:
        objeto[1].valor = static_cast<ldouble_t>(arg1.toDouble());
        break;
    case digito:
        objeto[1].valor = make_digit_variant(objeto[0].base, arg1.toLongLong());
        break;
    default:;
    }
}

void crear_variable(int index)
{
    if ((index >= 0) && (index <= 2)) {
        switch (objeto[index].tipo) {
        case longlong:
            if (ull_lista.contains(objeto[index].nombre))
                ull_lista.erase_var(objeto[index].nombre);
            if (ld_lista.contains(objeto[index].nombre))
                ld_lista.erase_var(objeto[index].nombre);
            if (digito_lista.contains(objeto[index].nombre))
                digito_lista.erase_var(objeto[index].nombre);
            ll_lista.create_var(objeto[index].nombre, std::get<sllint_t>(objeto[index].valor));
            break;
        case unsignedlonglong:
            if (ll_lista.contains(objeto[index].nombre))
                ll_lista.erase_var(objeto[index].nombre);
            if (ld_lista.contains(objeto[index].nombre))
                ld_lista.erase_var(objeto[index].nombre);
            if (digito_lista.contains(objeto[index].nombre))
                digito_lista.erase_var(objeto[index].nombre);
            ull_lista.create_var(objeto[index].nombre, std::get<ullint_t>(objeto[index].valor));
            break;
        case longdouble:
            if (ull_lista.contains(objeto[index].nombre))
                ull_lista.erase_var(objeto[index].nombre);
            if (ll_lista.contains(objeto[index].nombre))
                ll_lista.erase_var(objeto[index].nombre);
            if (digito_lista.contains(objeto[index].nombre))
                digito_lista.erase_var(objeto[index].nombre);
            ld_lista.create_var(objeto[index].nombre, std::get<ldouble_t>(objeto[index].valor));
            break;
        case digito:
            if (ull_lista.contains(objeto[index].nombre))
                ull_lista.erase_var(objeto[index].nombre);
            if (ld_lista.contains(objeto[index].nombre))
                ld_lista.erase_var(objeto[index].nombre);
            if (ll_lista.contains(objeto[index].nombre))
                ll_lista.erase_var(objeto[index].nombre);
            switch (a_tipo_variant_e(objeto[index].valor.index())) {
            case tipo_variant_e::longlong:
                objeto[index].valor = NumRepr::make_digit_variant(objeto[index].base,
                                                                  std::get<sllint_t>(
                                                                      objeto[index].valor));
                break;
            case tipo_variant_e::unsignedlonglong:
                objeto[index].valor = NumRepr::make_digit_variant(objeto[index].base,
                                                                  std::get<ullint_t>(
                                                                      objeto[index].valor));
                break;
            case tipo_variant_e::longdouble:
                objeto[index].valor = NumRepr::make_digit_variant(objeto[index].base,
                                                                  static_cast<sllint_t>(
                                                                      std::get<ldouble_t>(
                                                                          objeto[index].valor)));
                break;
            case tipo_variant_e::digito:
                //objeto[index].valor = std::get<digit_variant>(objeto[index].valor);
                break;
            case tipo_variant_e::desconocido:
            default:;
            }

            digito_lista.create_var(objeto[index].nombre,
                                    std::get<digit_variant>(objeto[index].valor));
            break;
        case registro:
            //registro_lista.create_var(objeto[index].nombre,
            //                          objeto[index].base,
            //                          objeto[index].longPE,
            //                          objeto[index].valor);
            break;
        case regnatural:
            //natural_reg_lista.create_var(objeto[index].nombre,
            //                             objeto[index].base,
            //                             objeto[index].longPE,
            //                             objeto[index].valor);
            break;
        case regentero:
            //entero_reg_lista.create_var(objeto[index].nombre,
            //                            objeto[index].base,
            //                            objeto[index].longPE,
            //                            objeto[index].valor);
            break;
        case racionalnat:
            //racional_natural_lista.create_var(objeto[index].nombre,
            //                                  objeto[index].base,
            //                                  objeto[index].longPE,
            //                                  objeto[index].longPF,
            //                                  objeto[index].valor);
            break;
        case racionalent:
            //racional_entero_lista.create_var(objeto[index].nombre,
            //                                 objeto[index].base,
            //                                 objeto[index].longPE,
            //                                 objeto[index].longPF,
            //                                 objeto[index].valor);
            break;
        case natural:
            //natural_lista.create_var(objeto[index].nombre, objeto[index].base, objeto[index].valor);
            break;
        case entero:
        default:;
            //entero_lista.create_var(objeto[index].nombre, objeto[index].base, objeto[index].valor);
        }
    }
}

void MainWindow::on_checkBox_variable_1_preparada_stateChanged(int arg1)
{
    if (arg1 != 0) {
        crear_variable(0);
    }
}

void MainWindow::on_checkBox_variable_2_preparada_stateChanged(int arg1)
{
    if (arg1 != 0) {
        crear_variable(1);
    }
}

void MainWindow::on_checkBox_variable_result_stateChanged(int arg1)
{
    if (arg1 != 0) {
        crear_variable(2);
    }
}

QString to_text(tipo_o_plantilla_de_tipo_e case_enum)
{
    switch (case_enum) {
    case longlong:
        return QString("long long");
    case unsignedlonglong:
        return QString("unsigned long long");
    case longdouble:
        return QString("long double");
    case digito:
        return QString("digito");
    case registro:
        return QString("registro");
        ;
    case regnatural:
        return QString("registro natural");
    case regentero:
        return QString("registro entero");
    case racionalnat:
        return QString("racional natural");
    case racionalent:
        return QString("racional entero");
    case natural:
        return QString("natural");
    case entero:
        return QString("entero");
    case desconocido:
    default:
        return QString("desconocido");
    }
}

void MainWindow::on_pushButton_asignacion_clicked()
{
    using NumRepr::ldouble_t;
    using NumRepr::sllint_t;
    using NumRepr::ullint_t;

    // CUANDO TENEMOS UN NOMBRE DE VARIABLE LA DUPLICAMOS EN LL_LISTA ULL_LISTA LD_LISTA DIGITO_LISTA
    // SI LA VARIABLE HAY QUE CREARLA EN OTRA LISTA SE BORRA DE LA LISTA ACTUAL

    // REALIZAMOS LA OPERACION
    // SE HACE UN CAST DEL OBJETO 1 Y SE ASIGNA AL OBJETO 0
    // EL CAST SOLO CUANDO ES NECESARIO
    // SI EL CAST NO SE PUEDE HACER DEBERÍA DE SALTAR UN MENSAJE: TODO
    tipo_o_plantilla_de_tipo_e tipo_de_resultado = desconocido;
    switch (objeto[0].tipo) {
    case longlong:
        tipo_de_resultado = longlong;
        if (objeto[1].tipo == longlong) {
            ll_lista[objeto[0].nombre] = ll_lista[objeto[1].nombre];
            ll_lista[objeto[2].nombre] = ll_lista[objeto[0].nombre];
            objeto[2].valor = ll_lista[objeto[2].nombre];
        } else if (objeto[1].tipo == unsignedlonglong) {
            if (ull_lista[objeto[1].nombre] <= std::numeric_limits<sllint_t>::max()) {
                ll_lista[objeto[0].nombre] = static_cast<sllint_t>(ull_lista[objeto[1].nombre]);
                ll_lista[objeto[2].nombre] = ll_lista[objeto[0].nombre];
                objeto[2].valor = ll_lista[objeto[2].nombre];
            }
            // else {
            //    throw std::logic_error("Overflow");
            // }
        } else if (objeto[1].tipo == longdouble) {
            if ((ld_lista[objeto[1].nombre] <= std::numeric_limits<sllint_t>::max())
                && (ld_lista[objeto[1].nombre] >= std::numeric_limits<sllint_t>::min())) {
                ll_lista[objeto[0].nombre] = static_cast<sllint_t>(ld_lista[objeto[1].nombre]);
                ll_lista[objeto[2].nombre] = ll_lista[objeto[0].nombre];
                objeto[2].valor = ll_lista[objeto[2].nombre];
            }
            // else if (ld_lista(objeto[1].nombre) >= std::numeric_limits<sllint_t>::max()) {
            //    throw std::logic_error("Overflow");
            // }
            // else {
            //     throw std::logic_error("Underflow");
            // }
        } else if (objeto[1].tipo == digito) {
            ll_lista[objeto[0].nombre] = static_cast<sllint_t>(digito_lista[objeto[1].nombre]());
            ll_lista[objeto[2].nombre] = ll_lista[objeto[0].nombre];
            objeto[2].valor = ll_lista[objeto[2].nombre];
        }
        //else {
        //        throw std::logic_error("NO IMPLEMENTADO AÚN");
        //     }
        break;
    case unsignedlonglong:
        tipo_de_resultado = unsignedlonglong;
        if (objeto[1].tipo == unsignedlonglong) {
            ull_lista[objeto[0].nombre] = ull_lista[objeto[1].nombre];
            ull_lista[objeto[2].nombre] = ull_lista[objeto[0].nombre];
            objeto[2].valor = ull_lista[objeto[2].nombre];
        } else if (objeto[1].tipo == longlong) {
            if (ll_lista[objeto[1].nombre] >= 0) {
                ull_lista[objeto[0].nombre] = static_cast<ullint_t>(ll_lista[objeto[1].nombre]);
                ull_lista[objeto[2].nombre] = ull_lista[objeto[0].nombre];
                objeto[2].valor = ull_lista[objeto[2].nombre];
            }
            // else {
            //     throw std::logic_error("El objeto destino no admite valores negativos");
            // }
        } else if (objeto[1].tipo == longdouble) {
            if ((ld_lista[objeto[1].nombre] >= 0)
                && (ld_lista[objeto[1].nombre] <= std::numeric_limits<ullint_t>::max())) {
                ull_lista[objeto[0].nombre] = static_cast<ullint_t>(ld_lista[objeto[1].nombre]);
                ull_lista[objeto[2].nombre] = ull_lista[objeto[0].nombre];
                objeto[2].valor = ull_lista[objeto[2].nombre];
            }
            // else if ((ld_lista(objeto[1].nombre) < 0)) {
            //     throw std::logic_error("El objeto destino no admite valores negativos");
            // }
            // else if ((ld_lista(objeto[1].nombre) > std::numeric_limits<ullint_t>::max())) {
            //     throw std::logic_error("Overflow");
            // }
        } else if (objeto[1].tipo == digito) {
            ull_lista[objeto[0].nombre] = static_cast<ullint_t>(digito_lista[objeto[1].nombre]());
            ull_lista[objeto[2].nombre] = ull_lista[objeto[0].nombre];
            objeto[2].valor = ull_lista[objeto[2].nombre];
        }
        // else {
        //     throw std::logic_error("NO IMPLEMENTADO AÚN");
        // }
        break;
    case longdouble:
        tipo_de_resultado = longdouble;
        if (objeto[1].tipo == longdouble) {
            ld_lista[objeto[0].nombre] = ld_lista[objeto[1].nombre];
            ld_lista[objeto[2].nombre] = ld_lista[objeto[0].nombre];
            objeto[2].valor = ld_lista[objeto[2].nombre];
        } else if (objeto[1].tipo == longlong) {
            ld_lista[objeto[0].nombre] = static_cast<ldouble_t>(ll_lista[objeto[1].nombre]);
            ld_lista[objeto[2].nombre] = ld_lista[objeto[0].nombre];
            objeto[2].valor = ld_lista[objeto[2].nombre];
        } else if (objeto[1].tipo == unsignedlonglong) {
            ld_lista[objeto[0].nombre] = static_cast<ldouble_t>(ull_lista[objeto[1].nombre]);
            ld_lista[objeto[2].nombre] = ld_lista[objeto[0].nombre];
            objeto[2].valor = ld_lista[objeto[2].nombre];
        } else if (objeto[1].tipo == digito) {
            ld_lista[objeto[0].nombre] = static_cast<ldouble_t>(digito_lista[objeto[1].nombre]());
            ld_lista[objeto[2].nombre] = ld_lista[objeto[0].nombre];
            objeto[2].valor = ld_lista[objeto[2].nombre];
        }
        // else {
        //     throw std::logic_error("NO IMPLEMENTADO AÚN");
        // }
        break;
    case digito:
        tipo_de_resultado = digito;
        if (objeto[1].tipo == digito) {
            const NumRepr::digit_variant obj0{digito_lista[objeto[0].nombre]};
            const auto base0{obj0.radix()};
            const NumRepr::digit_variant obj1{digito_lista[objeto[1].nombre]};
            const auto base1{obj1.radix()};
            if (base0 == base1) {
                digito_lista[objeto[0].nombre] = obj1;
                const NumRepr::digit_variant obj0{digito_lista[objeto[0].nombre]};
                digito_lista[objeto[2].nombre] = obj0;
                objeto[2].base = digito_lista[objeto[2].nombre].radix();
                objeto[2].valor = digito_lista[objeto[2].nombre];
            }
        } else if (objeto[1].tipo == longlong) {
            digito_lista[objeto[0].nombre] = NumRepr::make_digit_variant(objeto[0].base,
                                                                         std::get<sllint_t>(
                                                                             objeto[1].valor));
            digito_lista[objeto[2].nombre] = digito_lista[objeto[0].nombre];
            objeto[2].base = digito_lista[objeto[2].nombre].radix();
            objeto[2].valor = digito_lista[objeto[2].nombre];
        } else if (objeto[1].tipo == unsignedlonglong) {
            digito_lista[objeto[0].nombre] = NumRepr::make_digit_variant(objeto[0].base,
                                                                         std::get<ullint_t>(
                                                                             objeto[1].valor));
            digito_lista[objeto[2].nombre] = digito_lista[objeto[0].nombre];
            objeto[2].base = digito_lista[objeto[2].nombre].radix();
            objeto[2].valor = digito_lista[objeto[2].nombre];
        }
        // else {
        //     throw std::logic_error("NO IMPLEMENTADO AÚN");
        // }
        break;
    case registro:
        tipo_de_resultado = registro;
        // throw std::logic_error("NO IMPLEMENTADO AÚN");
        break;
    case regnatural:
        tipo_de_resultado = regnatural;
        // throw std::logic_error("NO IMPLEMENTADO AÚN");
        break;
    case regentero:
        tipo_de_resultado = regentero;
        // throw std::logic_error("NO IMPLEMENTADO AÚN");
        break;
    case racionalnat:
        tipo_de_resultado = racionalnat;
        // throw std::logic_error("NO IMPLEMENTADO AÚN");
        break;
    case racionalent:
        tipo_de_resultado = racionalent;
        // throw std::logic_error("NO IMPLEMENTADO AÚN");
        break;
    case natural:
        tipo_de_resultado = natural;
        // throw std::logic_error("NO IMPLEMENTADO AÚN");
        break;
    case entero:
        tipo_de_resultado = entero;
        break;
    default:;
        // throw std::logic_error("NO IMPLEMENTADO AÚN");
    }

    // ACTUALIZAMOS EL OBJETO 2 RESULTADO
    ui->lineEdit_nombre_in_result->setText(QString::fromStdString(objeto[2].nombre));
    ui->label_plantilla_resultado->setText(to_text(tipo_de_resultado));
    switch (tipo_de_resultado) {
    case longlong:
        ui->label_base_resultado->setVisible(false);
        ui->label_longPE_resultado->setVisible(false);
        ui->label_longPF_resultado->setVisible(false);
        ui->label_valor_resultado->setVisible(true);
        ui->label_valor_resultado->setText(QString::number(sllint_t(ll_lista[objeto[2].nombre])));
        break;
    case unsignedlonglong:
        ui->label_base_resultado->setVisible(false);
        ui->label_longPE_resultado->setVisible(false);
        ui->label_longPF_resultado->setVisible(false);
        ui->label_valor_resultado->setVisible(true);
        ui->label_valor_resultado->setText(QString::number(ullint_t(ull_lista[objeto[2].nombre])));
        break;
    case longdouble:
        ui->label_base_resultado->setVisible(false);
        ui->label_longPE_resultado->setVisible(false);
        ui->label_longPF_resultado->setVisible(false);
        ui->label_valor_resultado->setVisible(true);
        ui->label_valor_resultado->setText(
            QString::number(ldouble_t(ld_lista[objeto[2].nombre]), 'g', 6));
        break;
    case digito:
        ui->label_base_resultado->setVisible(true);
        ui->label_longPE_resultado->setVisible(false);
        ui->label_longPF_resultado->setVisible(false);
        ui->label_valor_resultado->setVisible(true);
        ui->label_base_resultado->setText(
            QString::number(ullint_t(digito_lista[objeto[2].nombre].radix())));
        ui->label_valor_resultado->setText(
            QString::number(ullint_t(digito_lista[objeto[2].nombre]())));
        break;
    case registro:
        ui->label_base_resultado->setVisible(true);
        ui->label_longPE_resultado->setVisible(true);
        ui->label_longPF_resultado->setVisible(false);
        ui->label_valor_resultado->setVisible(true);
        break;
    case regnatural:
        ui->label_base_resultado->setVisible(true);
        ui->label_longPE_resultado->setVisible(true);
        ui->label_longPF_resultado->setVisible(false);
        ui->label_valor_resultado->setVisible(true);
        break;
    case regentero:
        ui->label_base_resultado->setVisible(true);
        ui->label_longPE_resultado->setVisible(true);
        ui->label_longPF_resultado->setVisible(false);
        ui->label_valor_resultado->setVisible(true);
        break;
    case racionalnat:
        ui->label_base_resultado->setVisible(true);
        ui->label_longPE_resultado->setVisible(true);
        ui->label_longPF_resultado->setVisible(true);
        ui->label_valor_resultado->setVisible(true);
        break;
    case racionalent:
        ui->label_base_resultado->setVisible(true);
        ui->label_longPE_resultado->setVisible(true);
        ui->label_longPF_resultado->setVisible(true);
        ui->label_valor_resultado->setVisible(true);
        break;
    case natural:
        ui->label_base_resultado->setVisible(true);
        ui->label_longPE_resultado->setVisible(false);
        ui->label_longPF_resultado->setVisible(false);
        ui->label_valor_resultado->setVisible(true);
        break;
    case entero:
        ui->label_base_resultado->setVisible(true);
        ui->label_longPE_resultado->setVisible(false);
        ui->label_longPF_resultado->setVisible(false);
        ui->label_valor_resultado->setVisible(true);
        break;
    case desconocido:
        ui->label_base_resultado->setVisible(false);
        ui->label_longPE_resultado->setVisible(false);
        ui->label_longPF_resultado->setVisible(false);
        ui->label_valor_resultado->setVisible(false);
        break;
    }
    /// ACTUALIZAMOS EL OBJETO 0
    switch (objeto[0].tipo) {
    case longlong:
        ui->lineEdit_valor_1->setText(QString::number(sllint_t(ll_lista[objeto[0].nombre])));
        break;
    case unsignedlonglong:
        ui->lineEdit_valor_1->setText(QString::number(ullint_t(ull_lista[objeto[0].nombre])));
        break;
    case longdouble:
        ui->lineEdit_valor_1->setText(
            QString::number(ldouble_t(ld_lista[objeto[0].nombre]), 'g', 6));
        break;
    case digito:
        ui->lineEdit_Base_1->setText(
            QString::number(ullint_t(digito_lista[objeto[0].nombre].radix())));
        ui->lineEdit_valor_1->setText(QString::number(ullint_t(digito_lista[objeto[0].nombre]())));
        break;
    case registro:
        break;
    case regnatural:
        break;
    case regentero:
        break;
    case racionalnat:
        break;
    case racionalent:
        break;
    case natural:
        break;
    case entero:
        break;
    case desconocido:
        break;
    }
}

void MainWindow::on_comboBox_plantilla_1_activated(int index)
{
    objeto[0].tipo = a_tipoenum(index);
    switch (objeto[0].tipo) {
    case longlong:
        ui->lineEdit_nombre_in_1->setVisible(true);
        ui->lineEdit_valor_1->setVisible(true);
        ui->lineEdit_Base_1->setVisible(false);
        ui->lineEdit_longitud_PE_1->setVisible(false);
        ui->lineEdit_longitud_PF_1->setVisible(false);
        break;
    case unsignedlonglong:
        ui->lineEdit_nombre_in_1->setVisible(true);
        ui->lineEdit_valor_1->setVisible(true);
        ui->lineEdit_Base_1->setVisible(false);
        ui->lineEdit_longitud_PE_1->setVisible(false);
        ui->lineEdit_longitud_PF_1->setVisible(false);
        break;
    case longdouble:
        ui->lineEdit_nombre_in_1->setVisible(true);
        ui->lineEdit_valor_1->setVisible(true);
        ui->lineEdit_Base_1->setVisible(false);
        ui->lineEdit_longitud_PE_1->setVisible(false);
        ui->lineEdit_longitud_PF_1->setVisible(false);
        break;
    case digito:
        ui->lineEdit_nombre_in_1->setVisible(true);
        ui->lineEdit_valor_1->setVisible(true);
        ui->lineEdit_Base_1->setVisible(true);
        ui->lineEdit_longitud_PE_1->setVisible(false);
        ui->lineEdit_longitud_PF_1->setVisible(false);
        break;
    case natural:
        ui->lineEdit_nombre_in_1->setVisible(true);
        ui->lineEdit_valor_1->setVisible(true);
        ui->lineEdit_Base_1->setVisible(true);
        ui->lineEdit_longitud_PE_1->setVisible(false);
        ui->lineEdit_longitud_PF_1->setVisible(false);
        break;
    case entero:
        ui->lineEdit_nombre_in_1->setVisible(true);
        ui->lineEdit_valor_1->setVisible(true);
        ui->lineEdit_Base_1->setVisible(true);
        ui->lineEdit_longitud_PE_1->setVisible(false);
        ui->lineEdit_longitud_PF_1->setVisible(false);
        break;
    case registro:
        ui->lineEdit_nombre_in_1->setVisible(true);
        ui->lineEdit_valor_1->setVisible(true);
        ui->lineEdit_Base_1->setVisible(true);
        ui->lineEdit_longitud_PE_1->setVisible(true);
        ui->lineEdit_longitud_PF_1->setVisible(false);
        break;
    case regnatural:
        ui->lineEdit_nombre_in_1->setVisible(true);
        ui->lineEdit_valor_1->setVisible(true);
        ui->lineEdit_Base_1->setVisible(true);
        ui->lineEdit_longitud_PE_1->setVisible(true);
        ui->lineEdit_longitud_PF_1->setVisible(false);
        break;
    case regentero:
        ui->lineEdit_nombre_in_1->setVisible(true);
        ui->lineEdit_valor_1->setVisible(true);
        ui->lineEdit_Base_1->setVisible(true);
        ui->lineEdit_longitud_PE_1->setVisible(true);
        ui->lineEdit_longitud_PF_1->setVisible(false);
        break;
    case racionalnat:
        ui->lineEdit_nombre_in_1->setVisible(true);
        ui->lineEdit_valor_1->setVisible(true);
        ui->lineEdit_Base_1->setVisible(true);
        ui->lineEdit_longitud_PE_1->setVisible(true);
        ui->lineEdit_longitud_PF_1->setVisible(true);
        break;
    case racionalent:
        ui->lineEdit_nombre_in_1->setVisible(true);
        ui->lineEdit_valor_1->setVisible(true);
        ui->lineEdit_Base_1->setVisible(true);
        ui->lineEdit_longitud_PE_1->setVisible(true);
        ui->lineEdit_longitud_PF_1->setVisible(true);
        break;
    default:
        break;
    }
}

void MainWindow::on_comboBox_plantilla_2_activated(int index)
{
    objeto[1].tipo = a_tipoenum(index);
    switch (objeto[1].tipo) {
    case longlong:
        ui->lineEdit_nombre_in_2->setVisible(true);
        ui->lineEdit_valor_2->setVisible(true);
        ui->lineEdit_Base_2->setVisible(false);
        ui->lineEdit_longitud_PE_2->setVisible(false);
        ui->lineEdit_longitud_PF_2->setVisible(false);
        break;
    case unsignedlonglong:
        ui->lineEdit_nombre_in_2->setVisible(true);
        ui->lineEdit_valor_2->setVisible(true);
        ui->lineEdit_Base_2->setVisible(false);
        ui->lineEdit_longitud_PE_2->setVisible(false);
        ui->lineEdit_longitud_PF_2->setVisible(false);
        break;
    case longdouble:
        ui->lineEdit_nombre_in_2->setVisible(true);
        ui->lineEdit_valor_2->setVisible(true);
        ui->lineEdit_Base_2->setVisible(false);
        ui->lineEdit_longitud_PE_2->setVisible(false);
        ui->lineEdit_longitud_PF_2->setVisible(false);
        break;
    case digito:
        ui->lineEdit_nombre_in_2->setVisible(true);
        ui->lineEdit_valor_2->setVisible(true);
        ui->lineEdit_Base_2->setVisible(true);
        ui->lineEdit_longitud_PE_2->setVisible(false);
        ui->lineEdit_longitud_PF_2->setVisible(false);
        break;
    case natural:
        ui->lineEdit_nombre_in_2->setVisible(true);
        ui->lineEdit_valor_2->setVisible(true);
        ui->lineEdit_Base_2->setVisible(true);
        ui->lineEdit_longitud_PE_2->setVisible(false);
        ui->lineEdit_longitud_PF_2->setVisible(false);
        break;
    case entero:
        ui->lineEdit_nombre_in_2->setVisible(true);
        ui->lineEdit_valor_2->setVisible(true);
        ui->lineEdit_Base_2->setVisible(true);
        ui->lineEdit_longitud_PE_2->setVisible(false);
        ui->lineEdit_longitud_PF_2->setVisible(false);
        break;
    case registro:
        ui->lineEdit_nombre_in_2->setVisible(true);
        ui->lineEdit_valor_2->setVisible(true);
        ui->lineEdit_Base_2->setVisible(true);
        ui->lineEdit_longitud_PE_2->setVisible(true);
        ui->lineEdit_longitud_PF_2->setVisible(false);
        break;
    case regnatural:
        ui->lineEdit_nombre_in_2->setVisible(true);
        ui->lineEdit_valor_2->setVisible(true);
        ui->lineEdit_Base_2->setVisible(true);
        ui->lineEdit_longitud_PE_2->setVisible(true);
        ui->lineEdit_longitud_PF_2->setVisible(false);
        break;
    case regentero:
        ui->lineEdit_nombre_in_2->setVisible(true);
        ui->lineEdit_valor_2->setVisible(true);
        ui->lineEdit_Base_2->setVisible(true);
        ui->lineEdit_longitud_PE_2->setVisible(true);
        ui->lineEdit_longitud_PF_2->setVisible(false);
        break;
    case racionalnat:
        ui->lineEdit_nombre_in_2->setVisible(true);
        ui->lineEdit_valor_2->setVisible(true);
        ui->lineEdit_Base_2->setVisible(true);
        ui->lineEdit_longitud_PE_2->setVisible(true);
        ui->lineEdit_longitud_PF_2->setVisible(true);
        break;
    case racionalent:
        ui->lineEdit_nombre_in_2->setVisible(true);
        ui->lineEdit_valor_2->setVisible(true);
        ui->lineEdit_Base_2->setVisible(true);
        ui->lineEdit_longitud_PE_2->setVisible(true);
        ui->lineEdit_longitud_PF_2->setVisible(true);
        break;
    default:
        break;
    }
}

void MainWindow::on_lineEdit_nombre_in_result_textEdited(const QString &arg1)
{
    if (!arg1.isEmpty()) {
        objeto[2].nombre = arg1.toStdString();
    } else {
        objeto[2].nombre = ld_varlist_t::default_name;
    }

    switch (objeto[2].tipo) {
    case longlong:
        objeto[2].valor = arg1.toLongLong();
        ll_lista.create_var(objeto[2].nombre, std::get<sllint_t>(objeto[2].valor));
        break;
    case unsignedlonglong:
        objeto[2].valor = arg1.toULongLong();
        ull_lista.create_var(objeto[2].nombre, std::get<ullint_t>(objeto[2].valor));
        break;
    case longdouble:
        objeto[2].valor = static_cast<ldouble_t>(arg1.toDouble());
        ld_lista.create_var(objeto[2].nombre, std::get<ldouble_t>(objeto[2].valor));
        break;
    case digito:
        objeto[2].valor = make_digit_variant(objeto[0].base, arg1.toLongLong());
        digito_lista.create_var(objeto[2].nombre, std::get<digit_variant>(objeto[2].valor));
        break;
    default:;
    }
}
