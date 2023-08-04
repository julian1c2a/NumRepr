#include "mainwindow.hpp"
#include <QMainWindow>
#include "./ui_mainwindow.h"
#include "GUITypesNHelpers.hpp"

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

void MainWindow::on_comboBox_plantilla_0_currentIndexChanged(int index)
{
    objeto[0].tipo = a_tipoenum(index);
}

void MainWindow::on_comboBox_plantilla_1_currentIndexChanged(int index)
{
    objeto[1].tipo = a_tipoenum(index);
}

void MainWindow::on_lineEdit_Base_0_textEdited(const QString &arg1)
{
    const ullint_t user_radix{arg1.toULongLong()};
    if ((user_radix > 1) && (user_radix < 66))
        objeto[0].base = user_radix;
    //else
    //    throw std::logic_error("El valor de la base ha de estar entre 2 y 65, ambos incluidos");
}

bool objeto_completo(const QString &uiObj_0,                  // nombre de la variable
                     const int &uiObj_1,                      // tipo de objeto simple o variant
                     const QString &uiObj_2,                  // base de representación
                     [[maybe_unused]] const QString &uiObj_3, // longitud de la parte entera
                     [[maybe_unused]] const QString &uiObj_4, // longitud de la parte fraccionaria
                     const QString &uiObj_5)                  // valor
{
    if (uiObj_0.isEmpty()) { // uiOjb_0 es el nombre de la variable
        return false;
    } else {
        if (a_tipoenum(uiObj_1) != tipo_o_plantilla_de_tipo_e::desconocido) {
            switch (a_tipoenum(uiObj_1)) {
            case tipo_o_plantilla_de_tipo_e::longlong: {
                bool ok;
                [[maybe_unused]] sllint_t valor{uiObj_5.toLongLong(&ok, 10)};
                if (!uiObj_5.isEmpty()) {
                    if (ok) {
                        return true;
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
            case tipo_o_plantilla_de_tipo_e::unsignedlonglong: {
                bool ok;
                [[maybe_unused]] ullint_t valor{uiObj_5.toULongLong(&ok, 10)};
                if (ok) {
                    if (valor) {
                        return true;
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
            case tipo_o_plantilla_de_tipo_e::longdouble: {
                bool ok_value;
                [[maybe_unused]] ldouble_t valor{uiObj_5.toDouble(&ok_value)};
                if (!uiObj_5.isEmpty()) {
                    if (ok_value) {
                        return true;
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
            case tipo_o_plantilla_de_tipo_e::digito: {
                bool ok_radix;
                [[maybe_unused]] ullint_t radix{uiObj_2.toULongLong(&ok_radix, 10)};
                bool ret;
                if (!uiObj_2.isEmpty()) {
                    if (ok_radix) {
                        if ((radix > 1) && (radix < 66)) {
                            ret = true;
                        } else {
                            ret = false;
                        }
                    } else {
                        ret = false;
                    }
                } else {
                    ret = false;
                }

                bool ok_value;
                [[maybe_unused]] sllint_t value{uiObj_2.toLongLong(&ok_value, 10)};
                if (!uiObj_5.isEmpty()) {
                    if (ok_value) {
                        return ret;
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
            case tipo_o_plantilla_de_tipo_e::registro:
                return false;
            case tipo_o_plantilla_de_tipo_e::regnatural:
                return false;
            case tipo_o_plantilla_de_tipo_e::regentero:
                return false;
            case tipo_o_plantilla_de_tipo_e::racionalnat:
                return false;
            case tipo_o_plantilla_de_tipo_e::racionalent:
                return false;
            case tipo_o_plantilla_de_tipo_e::natural:
                return false;
            case tipo_o_plantilla_de_tipo_e::entero:
                return false;
            case tipo_o_plantilla_de_tipo_e::desconocido:
            default:
                return false;
            }
        } else {
            return false;
        }
    }
}

void MainWindow::on_lineEdit_Base_1_textEdited(const QString &arg1)
{
    const ullint_t user_radix{arg1.toULongLong()};
    if ((user_radix > 1) && (user_radix < 66))
        objeto[1].base = user_radix;
    //else
    //    throw std::logic_error("El valor de la base ha de estar entre 2 y 65, ambos incluidos");
}

void MainWindow::on_lineEdit_longitud_PE_0_textEdited(const QString &arg1)
{
    const ullint_t user_length{arg1.toULongLong()};
    if ((user_length > 0) && (user_length < 33))
        objeto[0].longPE = user_length;
    //else
    //    throw std::logic_error("El valor de la longitud ha de estar entre 1 y 32, ambos incluidos");
}

void MainWindow::on_lineEdit_longitud_PE_1_textEdited(const QString &arg1)
{
    const ullint_t user_length{arg1.toULongLong()};
    if ((user_length > 0) && (user_length < 33))
        objeto[0].longPE = user_length;
    //else
    //    throw std::logic_error("El valor de la longitud ha de estar entre 1 y 32, ambos incluidos");
}

void MainWindow::on_lineEdit_longitud_PF_0_textEdited(const QString &arg1)
{
    const ullint_t user_length{arg1.toULongLong()};
    if ((user_length > 0) && (user_length < 33))
        objeto[0].longPF = user_length;
    //else
    //    throw std::logic_error("El valor de la longitud ha de estar entre 1 y 32, ambos incluidos");
}

void MainWindow::on_lineEdit_longitud_PF_1_textEdited(const QString &arg1)
{
    const ullint_t user_length{arg1.toULongLong()};
    if ((user_length > 0) && (user_length < 33))
        objeto[1].longPF = user_length;
    //else
    //    throw std::logic_error("El valor de la longitud ha de estar entre 1 y 32, ambos incluidos");
}

void MainWindow::on_lineEdit_valor_0_textEdited(const QString &arg1)
{
    switch (objeto[0].tipo) {
    case tipo_o_plantilla_de_tipo_e::longlong:
        objeto[0].valor = arg1.toLongLong();
        break;
    case tipo_o_plantilla_de_tipo_e::unsignedlonglong:
        objeto[0].valor = arg1.toULongLong();
        break;
    case tipo_o_plantilla_de_tipo_e::longdouble:
        objeto[0].valor = static_cast<ldouble_t>(arg1.toDouble());
        break;
    case tipo_o_plantilla_de_tipo_e::digito:
        objeto[0].valor = make_digit_variant(objeto[0].base, arg1.toLongLong());
        break;
    default:;
    }
}

void MainWindow::on_lineEdit_valor_1_textEdited(const QString &arg1)
{
    switch (objeto[1].tipo) {
    case tipo_o_plantilla_de_tipo_e::longlong:
        objeto[1].valor = arg1.toLongLong();
        break;
    case tipo_o_plantilla_de_tipo_e::unsignedlonglong:
        objeto[1].valor = arg1.toULongLong();
        break;
    case tipo_o_plantilla_de_tipo_e::longdouble:
        objeto[1].valor = static_cast<ldouble_t>(arg1.toDouble());
        break;
    case tipo_o_plantilla_de_tipo_e::digito:
        objeto[1].valor = make_digit_variant(objeto[0].base, arg1.toLongLong());
        break;
    default:;
    }
}

void crear_variable(int index)
{
    if ((index >= 0) && (index <= 2)) {
        switch (objeto[index].tipo) {
        case tipo_o_plantilla_de_tipo_e::longlong:
            if (ull_lista.contains(objeto[index].nombre))
                ull_lista.erase_var(objeto[index].nombre);
            if (ld_lista.contains(objeto[index].nombre))
                ld_lista.erase_var(objeto[index].nombre);
            if (digito_lista.contains(objeto[index].nombre))
                digito_lista.erase_var(objeto[index].nombre);
            ll_lista.create_var(objeto[index].nombre, std::get<sllint_t>(objeto[index].valor));
            break;
        case tipo_o_plantilla_de_tipo_e::unsignedlonglong:
            if (ll_lista.contains(objeto[index].nombre))
                ll_lista.erase_var(objeto[index].nombre);
            if (ld_lista.contains(objeto[index].nombre))
                ld_lista.erase_var(objeto[index].nombre);
            if (digito_lista.contains(objeto[index].nombre))
                digito_lista.erase_var(objeto[index].nombre);
            ull_lista.create_var(objeto[index].nombre, std::get<ullint_t>(objeto[index].valor));
            break;
        case tipo_o_plantilla_de_tipo_e::longdouble:
            if (ull_lista.contains(objeto[index].nombre))
                ull_lista.erase_var(objeto[index].nombre);
            if (ll_lista.contains(objeto[index].nombre))
                ll_lista.erase_var(objeto[index].nombre);
            if (digito_lista.contains(objeto[index].nombre))
                digito_lista.erase_var(objeto[index].nombre);
            ld_lista.create_var(objeto[index].nombre, std::get<ldouble_t>(objeto[index].valor));
            break;
        case tipo_o_plantilla_de_tipo_e::digito:
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
                objeto[index].valor = std::get<digit_variant>(objeto[index].valor);
                break;
            case tipo_variant_e::desconocido:
            default:;
            }

            digito_lista.create_var(objeto[index].nombre,
                                    std::get<digit_variant>(objeto[index].valor));
            break;
        case tipo_o_plantilla_de_tipo_e::registro:
            //registro_lista.create_var(objeto[index].nombre,
            //                          objeto[index].base,
            //                          objeto[index].longPE,
            //                          objeto[index].valor);
            break;
        case tipo_o_plantilla_de_tipo_e::regnatural:
            //natural_reg_lista.create_var(objeto[index].nombre,
            //                             objeto[index].base,
            //                             objeto[index].longPE,
            //                             objeto[index].valor);
            break;
        case tipo_o_plantilla_de_tipo_e::regentero:
            //entero_reg_lista.create_var(objeto[index].nombre,
            //                            objeto[index].base,
            //                            objeto[index].longPE,
            //                            objeto[index].valor);
            break;
        case tipo_o_plantilla_de_tipo_e::racionalnat:
            //racional_natural_lista.create_var(objeto[index].nombre,
            //                                  objeto[index].base,
            //                                  objeto[index].longPE,
            //                                  objeto[index].longPF,
            //                                  objeto[index].valor);
            break;
        case tipo_o_plantilla_de_tipo_e::racionalent:
            //racional_entero_lista.create_var(objeto[index].nombre,
            //                                 objeto[index].base,
            //                                 objeto[index].longPE,
            //                                 objeto[index].longPF,
            //                                 objeto[index].valor);
            break;
        case tipo_o_plantilla_de_tipo_e::natural:
            //natural_lista.create_var(objeto[index].nombre, objeto[index].base, objeto[index].valor);
            break;
        case tipo_o_plantilla_de_tipo_e::entero:
        default:;
            //entero_lista.create_var(objeto[index].nombre, objeto[index].base, objeto[index].valor);
        }
    }
}

void MainWindow::on_checkBox_variable_0_preparada_stateChanged(int arg1)
{
    if (arg1 != 0) {
        crear_variable(0);
    }
}

void MainWindow::on_checkBox_variable_1_preparada_stateChanged(int arg1)
{
    if (arg1 != 0) {
        crear_variable(1);
    }
}

void MainWindow::on_checkBox_variable_2_preparada_stateChanged(int arg1)
{
    if (arg1 != 0) {
        crear_variable(2);
    }
}

QString to_text(tipo_o_plantilla_de_tipo_e case_enum)
{
    switch (case_enum) {
    case tipo_o_plantilla_de_tipo_e::longlong:
        return QString("long long");
    case tipo_o_plantilla_de_tipo_e::unsignedlonglong:
        return QString("unsigned long long");
    case tipo_o_plantilla_de_tipo_e::longdouble:
        return QString("long double");
    case tipo_o_plantilla_de_tipo_e::digito:
        return QString("digito");
    case tipo_o_plantilla_de_tipo_e::registro:
        return QString("registro");
    case tipo_o_plantilla_de_tipo_e::regnatural:
        return QString("registro natural");
    case tipo_o_plantilla_de_tipo_e::regentero:
        return QString("registro entero");
    case tipo_o_plantilla_de_tipo_e::racionalnat:
        return QString("racional natural");
    case tipo_o_plantilla_de_tipo_e::racionalent:
        return QString("racional entero");
    case tipo_o_plantilla_de_tipo_e::natural:
        return QString("natural");
    case tipo_o_plantilla_de_tipo_e::entero:
        return QString("entero");
    case tipo_o_plantilla_de_tipo_e::desconocido:
    default:
        return QString("desconocido");
    }
}

void MainWindow::on_pushButton_asignacion_clicked()
{
    using NumRepr::ldouble_t;
    using NumRepr::sllint_t;
    using NumRepr::ullint_t;

    /// A = B ; R = A;
    /// A -> objeto[0] //    HAY QUE ACTUALIZARLO
    /// B -> objeto[1] // NO HAY QUE ACTUALIZARLO
    /// R -> objeto[2] //    HAY QUE ACTUALIZARLO

    // CUANDO TENEMOS UN NOMBRE DE VARIABLE LA DUPLICAMOS EN LL_LISTA ULL_LISTA LD_LISTA DIGITO_LISTA
    // SI LA VARIABLE HAY QUE CREARLA EN OTRA LISTA SE BORRA DE LA LISTA ACTUAL

    // REALIZAMOS LA OPERACION
    // SE HACE UN CAST DEL OBJETO 1 Y SE ASIGNA AL OBJETO 0
    // EL CAST SOLO CUANDO ES NECESARIO
    // SI EL CAST NO SE PUEDE HACER DEBERÍA DE SALTAR UN MENSAJE: TODO
    //tipo_o_plantilla_de_tipo_e tipo_de_resultado = tipo_o_plantilla_de_tipo_e::desconocido;
    const tipo_o_plantilla_de_tipo_e tipo_de_resultado{objeto[1].tipo};
    switch (tipo_de_resultado) {
    case tipo_o_plantilla_de_tipo_e::longlong: {
        objeto[0].valor = objeto[1].valor;
        objeto[0].tipo = tipo_de_resultado;
        ll_lista[objeto[0].nombre] = ll_lista[objeto[1].nombre]; /// A <- B
        objeto[2].valor = objeto[0].valor;
        objeto[2].tipo = tipo_de_resultado;
        ll_lista[objeto[2].nombre] = ll_lista[objeto[0].nombre]; /// R <- A
    } break;
    case tipo_o_plantilla_de_tipo_e::unsignedlonglong: {
        objeto[0].valor = objeto[1].valor;
        objeto[0].tipo = tipo_de_resultado;
        ull_lista[objeto[0].nombre] = ull_lista[objeto[1].nombre]; /// A <- B
        objeto[2].valor = objeto[0].valor;
        objeto[2].tipo = tipo_de_resultado;
        ull_lista[objeto[2].nombre] = ull_lista[objeto[0].nombre]; /// R <- A
    } break;
    case tipo_o_plantilla_de_tipo_e::longdouble: {
        objeto[0].valor = objeto[1].valor;
        objeto[0].tipo = tipo_de_resultado;
        ld_lista[objeto[0].nombre] = ld_lista[objeto[1].nombre]; /// A <- B
        objeto[2].valor = objeto[0].valor;
        objeto[2].tipo = tipo_de_resultado;
        ld_lista[objeto[2].nombre] = ld_lista[objeto[0].nombre]; /// R <- A
    } break;
    case tipo_o_plantilla_de_tipo_e::digito: {
        const bool copia_posible = (((objeto[0].tipo == tipo_o_plantilla_de_tipo_e::digito)
                                     && (objeto[0].base == objeto[1].base))
                                    || (objeto[0].tipo != tipo_o_plantilla_de_tipo_e::digito));
        if (copia_posible) {
            objeto[0].valor = objeto[1].valor;
            objeto[0].base = objeto[1].base;
            objeto[0].tipo = tipo_de_resultado;
            digito_lista[objeto[0].nombre] = digito_lista[objeto[1].nombre]; /// A <- B
            objeto[2].valor = objeto[0].valor;
            objeto[2].base = objeto[0].base;
            objeto[2].tipo = tipo_de_resultado;
            digito_lista[objeto[2].nombre] = digito_lista[objeto[0].nombre]; /// R <- A
        }
    } break;
    case tipo_o_plantilla_de_tipo_e::registro: {
    } break;
    case tipo_o_plantilla_de_tipo_e::regnatural: {
    } break;
    case tipo_o_plantilla_de_tipo_e::regentero: {
    } break;
    case tipo_o_plantilla_de_tipo_e::racionalnat: {
    } break;
    case tipo_o_plantilla_de_tipo_e::racionalent: {
    } break;
    case tipo_o_plantilla_de_tipo_e::natural: {
    } break;
    case tipo_o_plantilla_de_tipo_e::entero: {
    } break;
    case tipo_o_plantilla_de_tipo_e::desconocido:
    default: {
    }
    }

    // ACTUALIZAMOS (PINTAMOS EN UI) EL OBJETO 2 RESULTADO
    ui->lineEdit_nombre_in_2->setText(QString::fromStdString(objeto[2].nombre));
    ui->label_plantilla_2->setVisible(true);
    ui->label_plantilla_2->setText(to_text(tipo_de_resultado));
    switch (tipo_de_resultado) {
    case tipo_o_plantilla_de_tipo_e::longlong:
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_valor_2->setText(QString::number(sllint_t(ll_lista[objeto[2].nombre])));
        break;
    case tipo_o_plantilla_de_tipo_e::unsignedlonglong:
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_valor_2->setText(QString::number(ullint_t(ull_lista[objeto[2].nombre])));
        break;
    case tipo_o_plantilla_de_tipo_e::longdouble:
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_valor_2->setText(QString::number(ldouble_t(ld_lista[objeto[2].nombre]), 'g', 6));
        break;
    case tipo_o_plantilla_de_tipo_e::digito:
        ui->label_base_2->setVisible(true);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_base_2->setText(QString::number(ullint_t(digito_lista[objeto[2].nombre].radix())));
        ui->label_valor_2->setText(QString::number(ullint_t(digito_lista[objeto[2].nombre]())));
        break;
    case tipo_o_plantilla_de_tipo_e::registro:
        ui->label_base_2->setVisible(true);
        ui->label_longPE_2->setVisible(true);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        break;
    case tipo_o_plantilla_de_tipo_e::regnatural:
        ui->label_base_2->setVisible(true);
        ui->label_longPE_2->setVisible(true);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        break;
    case tipo_o_plantilla_de_tipo_e::regentero:
        ui->label_base_2->setVisible(true);
        ui->label_longPE_2->setVisible(true);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        break;
    case tipo_o_plantilla_de_tipo_e::racionalnat:
        ui->label_base_2->setVisible(true);
        ui->label_longPE_2->setVisible(true);
        ui->label_longPF_2->setVisible(true);
        ui->label_valor_2->setVisible(true);
        break;
    case tipo_o_plantilla_de_tipo_e::racionalent:
        ui->label_base_2->setVisible(true);
        ui->label_longPE_2->setVisible(true);
        ui->label_longPF_2->setVisible(true);
        ui->label_valor_2->setVisible(true);
        break;
    case tipo_o_plantilla_de_tipo_e::natural:
        ui->label_base_2->setVisible(true);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        break;
    case tipo_o_plantilla_de_tipo_e::entero:
        ui->label_base_2->setVisible(true);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        break;
    case tipo_o_plantilla_de_tipo_e::desconocido:
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(false);
        break;
    }

    /// ACTUALIZAMOS EL OBJETO 0 EN EL UI
    /// EL BOJETO 0 HA CAMBIADO EN TODAS PARTES MENOS EN EL UI
    ui->lineEdit_nombre_in_0->setText(QString::fromStdString(objeto[0].nombre));
    ui->comboBox_plantilla_0->setCurrentIndex(a_indice(tipo_de_resultado));
    switch (tipo_de_resultado) {
    case tipo_o_plantilla_de_tipo_e::longlong: {
        ui->lineEdit_Base_0->setVisible(false);
        ui->lineEdit_longitud_PE_0->setVisible(false);
        ui->lineEdit_longitud_PF_0->setVisible(false);
        ui->lineEdit_valor_0->setVisible(true);
        ui->lineEdit_valor_0->setText(QString::number(sllint_t(ll_lista[objeto[0].nombre])));
    } break;
    case tipo_o_plantilla_de_tipo_e::unsignedlonglong: {
        ui->lineEdit_Base_0->setVisible(false);
        ui->lineEdit_longitud_PE_0->setVisible(false);
        ui->lineEdit_longitud_PF_0->setVisible(false);
        ui->lineEdit_valor_0->setVisible(true);
        ui->lineEdit_valor_0->setText(QString::number(ullint_t(ull_lista[objeto[0].nombre])));
    } break;
    case tipo_o_plantilla_de_tipo_e::longdouble: {
        ui->lineEdit_Base_0->setVisible(false);
        ui->lineEdit_longitud_PE_0->setVisible(false);
        ui->lineEdit_longitud_PF_0->setVisible(false);
        ui->lineEdit_valor_0->setVisible(true);
        ui->lineEdit_valor_0->setText(
            QString::number(ldouble_t(ld_lista[objeto[0].nombre]), 'g', 6));
    } break;
    case tipo_o_plantilla_de_tipo_e::digito: {
        ui->lineEdit_longitud_PE_0->setVisible(false);
        ui->lineEdit_longitud_PF_0->setVisible(false);
        ui->lineEdit_valor_0->setVisible(true);
        ui->lineEdit_Base_0->setVisible(true);
        ui->lineEdit_Base_0->setText(
            QString::number(ullint_t(digito_lista[objeto[0].nombre].radix())));
        ui->lineEdit_valor_0->setText(QString::number(ullint_t(digito_lista[objeto[0].nombre]())));
    } break;
    case tipo_o_plantilla_de_tipo_e::registro: {
        ui->lineEdit_longitud_PE_0->setVisible(true);
        ui->lineEdit_longitud_PF_0->setVisible(false);
        ui->lineEdit_valor_0->setVisible(true);
        ui->lineEdit_Base_0->setVisible(true);
    } break;
    case tipo_o_plantilla_de_tipo_e::regnatural: {
        ui->lineEdit_longitud_PE_0->setVisible(true);
        ui->lineEdit_longitud_PF_0->setVisible(false);
        ui->lineEdit_valor_0->setVisible(true);
        ui->lineEdit_Base_0->setVisible(true);
    } break;
    case tipo_o_plantilla_de_tipo_e::regentero: {
        ui->lineEdit_longitud_PE_0->setVisible(true);
        ui->lineEdit_longitud_PF_0->setVisible(false);
        ui->lineEdit_valor_0->setVisible(true);
        ui->lineEdit_Base_0->setVisible(true);
    } break;
    case tipo_o_plantilla_de_tipo_e::racionalnat: {
        ui->lineEdit_longitud_PE_0->setVisible(true);
        ui->lineEdit_longitud_PF_0->setVisible(true);
        ui->lineEdit_valor_0->setVisible(true);
        ui->lineEdit_Base_0->setVisible(true);
    } break;
    case tipo_o_plantilla_de_tipo_e::racionalent: {
        ui->lineEdit_longitud_PE_0->setVisible(true);
        ui->lineEdit_longitud_PF_0->setVisible(true);
        ui->lineEdit_valor_0->setVisible(true);
        ui->lineEdit_Base_0->setVisible(true);
    } break;
    case tipo_o_plantilla_de_tipo_e::natural: {
        ui->lineEdit_longitud_PE_0->setVisible(false);
        ui->lineEdit_longitud_PF_0->setVisible(false);
        ui->lineEdit_valor_0->setVisible(true);
        ui->lineEdit_Base_0->setVisible(false);
    } break;
    case tipo_o_plantilla_de_tipo_e::entero: {
        ui->lineEdit_longitud_PE_0->setVisible(false);
        ui->lineEdit_longitud_PF_0->setVisible(false);
        ui->lineEdit_valor_0->setVisible(true);
        ui->lineEdit_Base_0->setVisible(false);
    } break;
    case tipo_o_plantilla_de_tipo_e::desconocido:
    default: {
        ui->lineEdit_longitud_PE_0->setVisible(false);
        ui->lineEdit_longitud_PF_0->setVisible(false);
        ui->lineEdit_valor_0->setVisible(false);
        ui->lineEdit_Base_0->setVisible(false);
    } break;
    }
}

void MainWindow::on_comboBox_plantilla_0_activated(int index)
{
    objeto[0].tipo = a_tipoenum(index);
    switch (objeto[0].tipo) {
    case tipo_o_plantilla_de_tipo_e::longlong:
        ui->lineEdit_nombre_in_0->setVisible(true);
        ui->lineEdit_valor_0->setVisible(true);
        ui->lineEdit_Base_0->setVisible(false);
        ui->lineEdit_longitud_PE_0->setVisible(false);
        ui->lineEdit_longitud_PF_0->setVisible(false);
        break;
    case tipo_o_plantilla_de_tipo_e::unsignedlonglong:
        ui->lineEdit_nombre_in_0->setVisible(true);
        ui->lineEdit_valor_0->setVisible(true);
        ui->lineEdit_Base_0->setVisible(false);
        ui->lineEdit_longitud_PE_0->setVisible(false);
        ui->lineEdit_longitud_PF_0->setVisible(false);
        break;
    case tipo_o_plantilla_de_tipo_e::longdouble:
        ui->lineEdit_nombre_in_0->setVisible(true);
        ui->lineEdit_valor_0->setVisible(true);
        ui->lineEdit_Base_0->setVisible(false);
        ui->lineEdit_longitud_PE_0->setVisible(false);
        ui->lineEdit_longitud_PF_0->setVisible(false);
        break;
    case tipo_o_plantilla_de_tipo_e::digito:
        ui->lineEdit_nombre_in_0->setVisible(true);
        ui->lineEdit_valor_0->setVisible(true);
        ui->lineEdit_Base_0->setVisible(true);
        ui->lineEdit_longitud_PE_0->setVisible(false);
        ui->lineEdit_longitud_PF_0->setVisible(false);
        break;
    case tipo_o_plantilla_de_tipo_e::natural:
        ui->lineEdit_nombre_in_0->setVisible(true);
        ui->lineEdit_valor_0->setVisible(true);
        ui->lineEdit_Base_0->setVisible(true);
        ui->lineEdit_longitud_PE_0->setVisible(false);
        ui->lineEdit_longitud_PF_0->setVisible(false);
        break;
    case tipo_o_plantilla_de_tipo_e::entero:
        ui->lineEdit_nombre_in_0->setVisible(true);
        ui->lineEdit_valor_0->setVisible(true);
        ui->lineEdit_Base_0->setVisible(true);
        ui->lineEdit_longitud_PE_0->setVisible(false);
        ui->lineEdit_longitud_PF_0->setVisible(false);
        break;
    case tipo_o_plantilla_de_tipo_e::registro:
        ui->lineEdit_nombre_in_0->setVisible(true);
        ui->lineEdit_valor_0->setVisible(true);
        ui->lineEdit_Base_0->setVisible(true);
        ui->lineEdit_longitud_PE_0->setVisible(true);
        ui->lineEdit_longitud_PF_0->setVisible(false);
        break;
    case tipo_o_plantilla_de_tipo_e::regnatural:
        ui->lineEdit_nombre_in_0->setVisible(true);
        ui->lineEdit_valor_0->setVisible(true);
        ui->lineEdit_Base_0->setVisible(true);
        ui->lineEdit_longitud_PE_0->setVisible(true);
        ui->lineEdit_longitud_PF_0->setVisible(false);
        break;
    case tipo_o_plantilla_de_tipo_e::regentero:
        ui->lineEdit_nombre_in_0->setVisible(true);
        ui->lineEdit_valor_0->setVisible(true);
        ui->lineEdit_Base_0->setVisible(true);
        ui->lineEdit_longitud_PE_0->setVisible(true);
        ui->lineEdit_longitud_PF_0->setVisible(false);
        break;
    case tipo_o_plantilla_de_tipo_e::racionalnat:
        ui->lineEdit_nombre_in_0->setVisible(true);
        ui->lineEdit_valor_0->setVisible(true);
        ui->lineEdit_Base_0->setVisible(true);
        ui->lineEdit_longitud_PE_0->setVisible(true);
        ui->lineEdit_longitud_PF_0->setVisible(true);
        break;
    case tipo_o_plantilla_de_tipo_e::racionalent:
        ui->lineEdit_nombre_in_0->setVisible(true);
        ui->lineEdit_valor_0->setVisible(true);
        ui->lineEdit_Base_0->setVisible(true);
        ui->lineEdit_longitud_PE_0->setVisible(true);
        ui->lineEdit_longitud_PF_0->setVisible(true);
        break;
    default:;
    }
}

void MainWindow::on_comboBox_plantilla_1_activated(int index)
{
    objeto[1].tipo = a_tipoenum(index);
    switch (objeto[1].tipo) {
    case tipo_o_plantilla_de_tipo_e::longlong:
        ui->lineEdit_nombre_in_1->setVisible(true);
        ui->lineEdit_valor_1->setVisible(true);
        ui->lineEdit_Base_1->setVisible(false);
        ui->lineEdit_longitud_PE_1->setVisible(false);
        ui->lineEdit_longitud_PF_1->setVisible(false);
        break;
    case tipo_o_plantilla_de_tipo_e::unsignedlonglong:
        ui->lineEdit_nombre_in_1->setVisible(true);
        ui->lineEdit_valor_1->setVisible(true);
        ui->lineEdit_Base_1->setVisible(false);
        ui->lineEdit_longitud_PE_1->setVisible(false);
        ui->lineEdit_longitud_PF_1->setVisible(false);
        break;
    case tipo_o_plantilla_de_tipo_e::longdouble:
        ui->lineEdit_nombre_in_1->setVisible(true);
        ui->lineEdit_valor_1->setVisible(true);
        ui->lineEdit_Base_1->setVisible(false);
        ui->lineEdit_longitud_PE_1->setVisible(false);
        ui->lineEdit_longitud_PF_1->setVisible(false);
        break;
    case tipo_o_plantilla_de_tipo_e::digito:
        ui->lineEdit_nombre_in_1->setVisible(true);
        ui->lineEdit_valor_1->setVisible(true);
        ui->lineEdit_Base_1->setVisible(true);
        ui->lineEdit_longitud_PE_1->setVisible(false);
        ui->lineEdit_longitud_PF_1->setVisible(false);
        break;
    case tipo_o_plantilla_de_tipo_e::natural:
        ui->lineEdit_nombre_in_1->setVisible(true);
        ui->lineEdit_valor_1->setVisible(true);
        ui->lineEdit_Base_1->setVisible(true);
        ui->lineEdit_longitud_PE_1->setVisible(false);
        ui->lineEdit_longitud_PF_1->setVisible(false);
        break;
    case tipo_o_plantilla_de_tipo_e::entero:
        ui->lineEdit_nombre_in_1->setVisible(true);
        ui->lineEdit_valor_1->setVisible(true);
        ui->lineEdit_Base_1->setVisible(true);
        ui->lineEdit_longitud_PE_1->setVisible(false);
        ui->lineEdit_longitud_PF_1->setVisible(false);
        break;
    case tipo_o_plantilla_de_tipo_e::registro:
        ui->lineEdit_nombre_in_1->setVisible(true);
        ui->lineEdit_valor_1->setVisible(true);
        ui->lineEdit_Base_1->setVisible(true);
        ui->lineEdit_longitud_PE_1->setVisible(true);
        ui->lineEdit_longitud_PF_1->setVisible(false);
        break;
    case tipo_o_plantilla_de_tipo_e::regnatural:
        ui->lineEdit_nombre_in_1->setVisible(true);
        ui->lineEdit_valor_1->setVisible(true);
        ui->lineEdit_Base_1->setVisible(true);
        ui->lineEdit_longitud_PE_1->setVisible(true);
        ui->lineEdit_longitud_PF_1->setVisible(false);
        break;
    case tipo_o_plantilla_de_tipo_e::regentero:
        ui->lineEdit_nombre_in_1->setVisible(true);
        ui->lineEdit_valor_1->setVisible(true);
        ui->lineEdit_Base_1->setVisible(true);
        ui->lineEdit_longitud_PE_1->setVisible(true);
        ui->lineEdit_longitud_PF_1->setVisible(false);
        break;
    case tipo_o_plantilla_de_tipo_e::racionalnat:
        ui->lineEdit_nombre_in_1->setVisible(true);
        ui->lineEdit_valor_1->setVisible(true);
        ui->lineEdit_Base_1->setVisible(true);
        ui->lineEdit_longitud_PE_1->setVisible(true);
        ui->lineEdit_longitud_PF_1->setVisible(true);
        break;
    case tipo_o_plantilla_de_tipo_e::racionalent:
        ui->lineEdit_nombre_in_1->setVisible(true);
        ui->lineEdit_valor_1->setVisible(true);
        ui->lineEdit_Base_1->setVisible(true);
        ui->lineEdit_longitud_PE_1->setVisible(true);
        ui->lineEdit_longitud_PF_1->setVisible(true);
        break;
    case tipo_o_plantilla_de_tipo_e::desconocido:
    default:;
    }
}

void MainWindow::on_lineEdit_nombre_in_2_textEdited(const QString &arg1)
{
    if (!arg1.isEmpty()) {
        objeto[2].nombre = arg1.toStdString();
    } else {
        objeto[2].nombre = ld_varlist_t::default_name;
    }

    switch (objeto[2].tipo) {
    case tipo_o_plantilla_de_tipo_e::longlong:
        objeto[2].valor = arg1.toLongLong();
        ll_lista.create_var(objeto[2].nombre, std::get<sllint_t>(objeto[2].valor));
        break;
    case tipo_o_plantilla_de_tipo_e::unsignedlonglong:
        objeto[2].valor = arg1.toULongLong();
        ull_lista.create_var(objeto[2].nombre, std::get<ullint_t>(objeto[2].valor));
        break;
    case tipo_o_plantilla_de_tipo_e::longdouble:
        objeto[2].valor = static_cast<ldouble_t>(arg1.toDouble());
        ld_lista.create_var(objeto[2].nombre, std::get<ldouble_t>(objeto[2].valor));
        break;
    case tipo_o_plantilla_de_tipo_e::digito:
        objeto[2].valor = make_digit_variant(objeto[0].base, arg1.toLongLong());
        digito_lista.create_var(objeto[2].nombre, std::get<digit_variant>(objeto[2].valor));
        break;
    case tipo_o_plantilla_de_tipo_e::desconocido:
    default:;
    }
}

void MainWindow::on_lineEdit_nombre_in_0_textEdited(const QString &arg1)
{
    objeto[0].nombre = arg1.toStdString();
}

void MainWindow::on_lineEdit_nombre_in_1_textEdited(const QString &arg1)
{
    objeto[1].nombre = arg1.toStdString();
}

void MainWindow::on_pushButton_suma_clicked()
{
    using NumRepr::ldouble_t;
    using NumRepr::sllint_t;
    using NumRepr::ullint_t;

    /// R = A + B ;
    /// A -> objeto[0] // NO HAY QUE ACTUALIZARLO
    /// B -> objeto[1] // NO HAY QUE ACTUALIZARLO
    /// R -> objeto[2] //    HAY QUE ACTUALIZARLO

    // CUANDO TENEMOS UN NOMBRE DE VARIABLE LA DUPLICAMOS EN LL_LISTA ULL_LISTA LD_LISTA DIGITO_LISTA
    // SI LA VARIABLE HAY QUE CREARLA EN OTRA LISTA SE BORRA DE LA LISTA ACTUAL

    // REALIZAMOS LA OPERACION
    // SE HACE UN CAST DEL OBJETO 1 Y SE ASIGNA AL OBJETO 0
    // EL CAST SOLO CUANDO ES NECESARIO
    // SI EL CAST NO SE PUEDE HACER DEBERÍA DE SALTAR UN MENSAJE: TODO
    //tipo_o_plantilla_de_tipo_e tipo_de_resultado = tipo_o_plantilla_de_tipo_e::desconocido;

    /// ll_lista es una lista de variables de tipo long long int
    /// ull_lista es una lista de variables de tipo unsigned long long int
    /// ld_lista es una lista de variables de tipo long double
    /// digito_lista es una lista de variable de tipo dig_variant

    const tipo_o_plantilla_de_tipo_e tipo_de_resultado{objeto[0].tipo};
    objeto[2].tipo = tipo_de_resultado;
    const tipo_o_plantilla_de_tipo_e tipo_de_left{objeto[0].tipo};
    const tipo_o_plantilla_de_tipo_e tipo_de_right{objeto[1].tipo};
    switch (tipo_de_left) {
    case tipo_o_plantilla_de_tipo_e::longlong: {
        switch (tipo_de_right) {
        case tipo_o_plantilla_de_tipo_e::longlong: {
            ll_lista[objeto[2].nombre] = ll_lista[objeto[0].nombre] + ll_lista[objeto[1].nombre];
            objeto[2].valor = ll_lista[objeto[2].nombre];
        } break;
        case tipo_o_plantilla_de_tipo_e::unsignedlonglong: {
            ll_lista[objeto[2].nombre] = ll_lista[objeto[0].nombre] + ull_lista[objeto[1].nombre];
            objeto[2].valor = ll_lista[objeto[2].nombre];
        } break;
        case tipo_o_plantilla_de_tipo_e::longdouble: {
            ll_lista[objeto[2].nombre] = ll_lista[objeto[0].nombre]
                                         + static_cast<sllint_t>(ld_lista[objeto[1].nombre]);
            objeto[2].valor = ll_lista[objeto[2].nombre];
        } break;
        case tipo_o_plantilla_de_tipo_e::digito: {
        } break;
        case tipo_o_plantilla_de_tipo_e::registro: {
        } break;
        case tipo_o_plantilla_de_tipo_e::regnatural: {
        } break;
        case tipo_o_plantilla_de_tipo_e::regentero: {
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalnat: {
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalent: {
        } break;
        case tipo_o_plantilla_de_tipo_e::natural: {
        } break;
        case tipo_o_plantilla_de_tipo_e::entero: {
        } break;
        case tipo_o_plantilla_de_tipo_e::desconocido:
        default: {
        }
        }
    } break;
    case tipo_o_plantilla_de_tipo_e::unsignedlonglong: {
        switch (tipo_de_right) {
        case tipo_o_plantilla_de_tipo_e::longlong: {
            ull_lista[objeto[2].nombre] = static_cast<ullint_t>(ull_lista[objeto[0].nombre]
                                                                + ll_lista[objeto[1].nombre]);
            objeto[2].valor = ull_lista[objeto[2].nombre];
        } break;
        case tipo_o_plantilla_de_tipo_e::unsignedlonglong: {
            ull_lista[objeto[2].nombre] = ull_lista[objeto[0].nombre] + ull_lista[objeto[1].nombre];
            objeto[2].valor = ull_lista[objeto[2].nombre];
        } break;
        case tipo_o_plantilla_de_tipo_e::longdouble: {
            ull_lista[objeto[2].nombre] = ull_lista[objeto[0].nombre]
                                          + static_cast<ullint_t>(ld_lista[objeto[1].nombre]);
            objeto[2].valor = ll_lista[objeto[2].nombre];
        } break;
        case tipo_o_plantilla_de_tipo_e::digito: {
        } break;
        case tipo_o_plantilla_de_tipo_e::registro: {
        } break;
        case tipo_o_plantilla_de_tipo_e::regnatural: {
        } break;
        case tipo_o_plantilla_de_tipo_e::regentero: {
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalnat: {
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalent: {
        } break;
        case tipo_o_plantilla_de_tipo_e::natural: {
        } break;
        case tipo_o_plantilla_de_tipo_e::entero: {
        } break;
        case tipo_o_plantilla_de_tipo_e::desconocido:
        default: {
        }
        }
    } break;
    case tipo_o_plantilla_de_tipo_e::longdouble: {
        switch (tipo_de_right) {
        case tipo_o_plantilla_de_tipo_e::longlong: {
            ld_lista[objeto[2].nombre] = ld_lista[objeto[0].nombre]
                                         + static_cast<ldouble_t>(ll_lista[objeto[1].nombre]);
            objeto[2].valor = ld_lista[objeto[2].nombre];
        } break;
        case tipo_o_plantilla_de_tipo_e::unsignedlonglong: {
            ld_lista[objeto[2].nombre] = ld_lista[objeto[0].nombre]
                                         + static_cast<ldouble_t>(ull_lista[objeto[1].nombre]);
            objeto[2].valor = ld_lista[objeto[2].nombre];
        } break;
        case tipo_o_plantilla_de_tipo_e::longdouble: {
            ld_lista[objeto[2].nombre] = ld_lista[objeto[0].nombre] + ld_lista[objeto[1].nombre];
            objeto[2].valor = ld_lista[objeto[2].nombre];
        } break;
        case tipo_o_plantilla_de_tipo_e::digito: {
        } break;
        case tipo_o_plantilla_de_tipo_e::registro: {
        } break;
        case tipo_o_plantilla_de_tipo_e::regnatural: {
        } break;
        case tipo_o_plantilla_de_tipo_e::regentero: {
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalnat: {
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalent: {
        } break;
        case tipo_o_plantilla_de_tipo_e::natural: {
        } break;
        case tipo_o_plantilla_de_tipo_e::entero: {
        } break;
        case tipo_o_plantilla_de_tipo_e::desconocido:
        default: {
        }
        }
    } break;
    case tipo_o_plantilla_de_tipo_e::digito: {
        const bool copia_posible = ((tipo_de_right == tipo_de_left)
                                    && (objeto[0].base == objeto[1].base));
        if (copia_posible) {
            objeto[2].base = objeto[1].base;
            objeto[2].tipo = tipo_de_resultado;
            digito_lista[objeto[2].nombre] = digito_lista[objeto[0].nombre]
                                             + digito_lista[objeto[1].nombre]; /// R <- A + B
            objeto[2].valor = digito_lista[objeto[2].nombre];
        }
    } break;
    case tipo_o_plantilla_de_tipo_e::registro: {
    } break;
    case tipo_o_plantilla_de_tipo_e::regnatural: {
    } break;
    case tipo_o_plantilla_de_tipo_e::regentero: {
    } break;
    case tipo_o_plantilla_de_tipo_e::racionalnat: {
    } break;
    case tipo_o_plantilla_de_tipo_e::racionalent: {
    } break;
    case tipo_o_plantilla_de_tipo_e::natural: {
    } break;
    case tipo_o_plantilla_de_tipo_e::entero: {
    } break;
    case tipo_o_plantilla_de_tipo_e::desconocido:
    default: {
    }
    }

    // ACTUALIZAMOS (PINTAMOS EN UI) EL OBJETO 2 RESULTADO
    ui->lineEdit_nombre_in_2->setText(QString::fromStdString(objeto[2].nombre));
    ui->label_plantilla_2->setText(to_text(tipo_de_resultado));
    switch (tipo_de_resultado) {
    case tipo_o_plantilla_de_tipo_e::longlong:
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_valor_2->setText(QString::number(sllint_t(ll_lista[objeto[2].nombre])));
        break;
    case tipo_o_plantilla_de_tipo_e::unsignedlonglong:
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_valor_2->setText(QString::number(ullint_t(ull_lista[objeto[2].nombre])));
        break;
    case tipo_o_plantilla_de_tipo_e::longdouble:
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_valor_2->setText(QString::number(ldouble_t(ld_lista[objeto[2].nombre]), 'g', 6));
        break;
    case tipo_o_plantilla_de_tipo_e::digito:
        ui->label_base_2->setVisible(true);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_base_2->setText(QString::number(ullint_t(digito_lista[objeto[2].nombre].radix())));
        ui->label_valor_2->setText(QString::number(ullint_t(digito_lista[objeto[2].nombre]())));
        break;
    case tipo_o_plantilla_de_tipo_e::registro:
        ui->label_base_2->setVisible(true);
        ui->label_longPE_2->setVisible(true);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        break;
    case tipo_o_plantilla_de_tipo_e::regnatural:
        ui->label_base_2->setVisible(true);
        ui->label_longPE_2->setVisible(true);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        break;
    case tipo_o_plantilla_de_tipo_e::regentero:
        ui->label_base_2->setVisible(true);
        ui->label_longPE_2->setVisible(true);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        break;
    case tipo_o_plantilla_de_tipo_e::racionalnat:
        ui->label_base_2->setVisible(true);
        ui->label_longPE_2->setVisible(true);
        ui->label_longPF_2->setVisible(true);
        ui->label_valor_2->setVisible(true);
        break;
    case tipo_o_plantilla_de_tipo_e::racionalent:
        ui->label_base_2->setVisible(true);
        ui->label_longPE_2->setVisible(true);
        ui->label_longPF_2->setVisible(true);
        ui->label_valor_2->setVisible(true);
        break;
    case tipo_o_plantilla_de_tipo_e::natural:
        ui->label_base_2->setVisible(true);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        break;
    case tipo_o_plantilla_de_tipo_e::entero:
        ui->label_base_2->setVisible(true);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        break;
    case tipo_o_plantilla_de_tipo_e::desconocido:
    default:
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(false);
        break;
    }
}

void MainWindow::on_pushButton_igual_clicked()
{
    bool resultado;
    bool comparacion_hecha = false;
    const std::string nombre_0{objeto[0].nombre};
    const std::string nombre_1{objeto[1].nombre};
    switch (objeto[0].tipo) {
    case tipo_o_plantilla_de_tipo_e::longlong:
        switch (objeto[1].tipo) {
        case tipo_o_plantilla_de_tipo_e::longlong: {
            resultado = (ll_lista[nombre_0] == ll_lista[nombre_1]);
            comparacion_hecha = true;
        } break;
        case tipo_o_plantilla_de_tipo_e::unsignedlonglong: {
            if (ll_lista[nombre_0] >= 0) {
                resultado = (static_cast<ullint_t>(ll_lista[nombre_0]) == ull_lista[nombre_1]);
                comparacion_hecha = true;
            } else {
                resultado = false;
                comparacion_hecha = true;
            }
        } break;
        case tipo_o_plantilla_de_tipo_e::longdouble: {
            resultado = (static_cast<ldouble_t>(ll_lista[nombre_0]) == ld_lista[nombre_1]);
            comparacion_hecha = true;
        } break;
        case tipo_o_plantilla_de_tipo_e::digito: {
            comparacion_hecha = false;
            // el dígito a la derecha no funciona
            // para comparar un dígito con un built-in el dítigo dever ser left
        } break;
        case tipo_o_plantilla_de_tipo_e::registro: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::regnatural: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::regentero: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalnat: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalent: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::natural: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::entero: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::desconocido:
        default: {
            comparacion_hecha = false;
        }
        }
        break;
    case tipo_o_plantilla_de_tipo_e::unsignedlonglong:
        switch (objeto[1].tipo) {
        case tipo_o_plantilla_de_tipo_e::longlong: {
            if (ll_lista[nombre_1] >= 0) {
                resultado = (ull_lista[nombre_0] == static_cast<ullint_t>(ll_lista[nombre_1]));
                comparacion_hecha = true;
            } else {
                resultado = false;
                comparacion_hecha = true;
            }
        } break;
        case tipo_o_plantilla_de_tipo_e::unsignedlonglong: {
            resultado = (ull_lista[nombre_0] == ull_lista[nombre_1]);
            comparacion_hecha = true;
        } break;
        case tipo_o_plantilla_de_tipo_e::longdouble: {
            resultado = (static_cast<ldouble_t>(ull_lista[nombre_0]) == ld_lista[nombre_1]);
            comparacion_hecha = true;
        } break;
        case tipo_o_plantilla_de_tipo_e::digito: {
            comparacion_hecha = false;
            // el dígito a la derecha no funciona
            // para comparar un dígito con un built-in el dítigo dever ser left
        } break;
        case tipo_o_plantilla_de_tipo_e::registro: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::regnatural: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::regentero: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalnat: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalent: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::natural: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::entero: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::desconocido:
        default: {
            comparacion_hecha = false;
        }
        }
        break;
    case tipo_o_plantilla_de_tipo_e::longdouble:
        switch (objeto[1].tipo) {
        case tipo_o_plantilla_de_tipo_e::longlong: {
            resultado = (ld_lista[nombre_0] == static_cast<ldouble_t>(ll_lista[nombre_1]));
            comparacion_hecha = true;
        } break;
        case tipo_o_plantilla_de_tipo_e::unsignedlonglong: {
            resultado = (ld_lista[nombre_0] == static_cast<ldouble_t>(ull_lista[nombre_1]));
            comparacion_hecha = true;
        } break;
        case tipo_o_plantilla_de_tipo_e::longdouble: {
            resultado = (ld_lista[nombre_0] == ld_lista[nombre_1]);
            comparacion_hecha = true;
        } break;
        case tipo_o_plantilla_de_tipo_e::digito: {
            comparacion_hecha = false;
            // el dígito a la derecha no funciona
            // para comparar un dígito con un built-in el dítigo dever ser left
        } break;
        case tipo_o_plantilla_de_tipo_e::registro: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::regnatural: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::regentero: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalnat: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalent: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::natural: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::entero: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::desconocido:
        default: {
            comparacion_hecha = false;
        }
        }
        break;
    case tipo_o_plantilla_de_tipo_e::digito:
        switch (objeto[1].tipo) {
        case tipo_o_plantilla_de_tipo_e::longlong: {
            /// POR HACER LA COMPARACIÓN EN EL DIG_VARIANT
            /// resultado = (digito_lista[nombre_0] == ll_lista[nombre_1]);
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::unsignedlonglong: {
            /// POR HACER LA COMPARACIÓN EN EL DIG_VARIANT
            /// resultado = (digito_lista[nombre_0] == ull_lista[nombre_1]);
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::longdouble: {
            /// POR HACER LA COMPARACIÓN EN EL DIG_VARIANT
            /// resultado = (digito_lista[nombre_0] == static_cast<sllint_t>(ld_lista[nombre_1]));
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::digito: {
            if (digito_lista[nombre_0].radix() == digito_lista[nombre_1].radix()) {
                resultado = (digito_lista[nombre_0] == digito_lista[nombre_1]);
                comparacion_hecha = true;
            } else {
                comparacion_hecha = false;
            }
        } break;
        case tipo_o_plantilla_de_tipo_e::registro: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::regnatural: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::regentero: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalnat: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalent: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::natural: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::entero: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::desconocido:
        default: {
            comparacion_hecha = false;
        }
        }
        break;
    case tipo_o_plantilla_de_tipo_e::registro:
        switch (objeto[1].tipo) {
        case tipo_o_plantilla_de_tipo_e::longlong: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::unsignedlonglong: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::longdouble: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::digito: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::registro: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::regnatural: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::regentero: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalnat: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalent: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::natural: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::entero: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::desconocido:
        default: {
            comparacion_hecha = false;
        }
        }
        break;
    case tipo_o_plantilla_de_tipo_e::regnatural:
        switch (objeto[1].tipo) {
        case tipo_o_plantilla_de_tipo_e::longlong: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::unsignedlonglong: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::longdouble: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::digito: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::registro: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::regnatural: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::regentero: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalnat: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalent: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::natural: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::entero: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::desconocido:
        default: {
            comparacion_hecha = false;
        }
        }
        break;
    case tipo_o_plantilla_de_tipo_e::regentero:
        switch (objeto[1].tipo) {
        case tipo_o_plantilla_de_tipo_e::longlong: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::unsignedlonglong: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::longdouble: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::digito: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::registro: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::regnatural: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::regentero: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalnat: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalent: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::natural: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::entero: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::desconocido:
        default: {
            comparacion_hecha = false;
        }
        }
        break;
    case tipo_o_plantilla_de_tipo_e::racionalnat:
        switch (objeto[1].tipo) {
        case tipo_o_plantilla_de_tipo_e::longlong: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::unsignedlonglong: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::longdouble: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::digito: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::registro: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::regnatural: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::regentero: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalnat: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalent: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::natural: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::entero: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::desconocido:
        default: {
            comparacion_hecha = false;
        }
        }
        break;
    case tipo_o_plantilla_de_tipo_e::racionalent:
        switch (objeto[1].tipo) {
        case tipo_o_plantilla_de_tipo_e::longlong: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::unsignedlonglong: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::longdouble: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::digito: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::registro: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::regnatural: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::regentero: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalnat: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalent: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::natural: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::entero: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::desconocido:
        default: {
            comparacion_hecha = false;
        }
        }
        break;
    case tipo_o_plantilla_de_tipo_e::natural:
        switch (objeto[1].tipo) {
        case tipo_o_plantilla_de_tipo_e::longlong: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::unsignedlonglong: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::longdouble: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::digito: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::registro: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::regnatural: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::regentero: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalnat: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalent: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::natural: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::entero: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::desconocido:
        default: {
            comparacion_hecha = false;
        }
        }
        break;
    case tipo_o_plantilla_de_tipo_e::entero:
        switch (objeto[1].tipo) {
        case tipo_o_plantilla_de_tipo_e::longlong: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::unsignedlonglong: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::longdouble: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::digito: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::registro: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::regnatural: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::regentero: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalnat: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalent: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::natural: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::entero: {
            comparacion_hecha = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::desconocido:
        default: {
            comparacion_hecha = false;
        }
        }
        break;
    case tipo_o_plantilla_de_tipo_e::desconocido:
    default: {
        comparacion_hecha = false;
    }
    }

    /// ACTUALIZACION DE LA LINEA 3 (RESULTADO)
    ui->lineEdit_nombre_in_2->setVisible(true);
    ui->lineEdit_nombre_in_2->setText("Resultado opcional");
    ui->label_plantilla_2->setVisible(true);
    ui->label_plantilla_2->setText("tipo bool");
    ui->label_base_2->setVisible(false);
    ui->label_longPE_2->setVisible(false);
    ui->label_longPF_2->setVisible(false);
    ui->label_valor_2->setVisible(true);
    if (comparacion_hecha) {
        if (resultado) {
            ui->label_valor_2->setText("true");
        } else {
            ui->label_valor_2->setText("false");
        }
    } else {
        ui->label_valor_2->setText("Comparacion no hecha");
    }
}

void MainWindow::on_pushButton_compl_Bm1_op_clicked()
{
    const auto tipo_de_resultado{objeto[0].tipo};
    objeto[2].tipo = tipo_de_resultado;
    const auto nombre_0{objeto[0].nombre};
    const auto nombre_2{objeto[2].nombre};
    bool ok;
    switch (tipo_de_resultado) {
    case tipo_o_plantilla_de_tipo_e::longlong: {
        ll_lista[nombre_2] = ~(ll_lista[nombre_0]);
        objeto[2].valor = ll_lista[nombre_2];
        ok = true;
    } break;
    case tipo_o_plantilla_de_tipo_e::unsignedlonglong: {
        ull_lista[nombre_2] = ~(ull_lista[nombre_0]);
        objeto[2].valor = ull_lista[nombre_2];
        ok = true;
    } break;
    case tipo_o_plantilla_de_tipo_e::longdouble: {
        ok = false;
    } break;
    case tipo_o_plantilla_de_tipo_e::digito: {
        const auto radix_0{digito_lista[nombre_0].radix()};
        const auto radix_2{radix_0};
        digito_lista[nombre_2] = ~(digito_lista[nombre_0]);
        objeto[2].base = radix_2;
        objeto[2].valor = digito_lista[nombre_2];
        ok = true;
    } break;
    case tipo_o_plantilla_de_tipo_e::registro: {
        ok = false;
    } break;
    case tipo_o_plantilla_de_tipo_e::regnatural: {
        ok = false;
    } break;
    case tipo_o_plantilla_de_tipo_e::regentero: {
        ok = false;
    } break;
    case tipo_o_plantilla_de_tipo_e::racionalnat: {
        ok = false;
    } break;
    case tipo_o_plantilla_de_tipo_e::racionalent: {
        ok = false;
    } break;
    case tipo_o_plantilla_de_tipo_e::natural: {
        ok = false;
    } break;
    case tipo_o_plantilla_de_tipo_e::entero: {
        ok = false;
    } break;
    case tipo_o_plantilla_de_tipo_e::desconocido:
    default: {
        ok = false;
    }
    }

    /// ACTUALIZACIÓN DEL RESULTADO (LINEA 3)

    switch (tipo_de_resultado) {
    case tipo_o_plantilla_de_tipo_e::longlong: {
        ui->label_plantilla_2->setVisible(true);
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_plantilla_2->setText(
            QString::fromStdString(a_texto(tipo_o_plantilla_de_tipo_e::longlong)));
        ui->label_valor_2->setText(QString::number(ll_lista[nombre_2]));
    } break;
    case tipo_o_plantilla_de_tipo_e::unsignedlonglong: {
        ui->label_plantilla_2->setVisible(true);
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_plantilla_2->setText(
            QString::fromStdString(a_texto(tipo_o_plantilla_de_tipo_e::unsignedlonglong)));
        ui->label_valor_2->setText(QString::number(ull_lista[nombre_2]));
    } break;
    case tipo_o_plantilla_de_tipo_e::longdouble: {
        ui->label_plantilla_2->setVisible(false);
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_plantilla_2->setText(
            QString::fromStdString(a_texto(tipo_o_plantilla_de_tipo_e::desconocido)));
    } break;
    case tipo_o_plantilla_de_tipo_e::digito: {
        ui->label_plantilla_2->setVisible(true);
        ui->label_base_2->setVisible(true);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_plantilla_2->setText(
            QString::fromStdString(a_texto(tipo_o_plantilla_de_tipo_e::desconocido)));
        ui->label_base_2->setText(QString::number(digito_lista[nombre_2].radix()));
        ui->label_valor_2->setText(QString::number(static_cast<ullint_t>(digito_lista[nombre_2]())));
    } break;
    case tipo_o_plantilla_de_tipo_e::registro: {
        ui->label_plantilla_2->setVisible(false);
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_plantilla_2->setText(
            QString::fromStdString(a_texto(tipo_o_plantilla_de_tipo_e::desconocido)));
    } break;
    case tipo_o_plantilla_de_tipo_e::regnatural: {
        ui->label_plantilla_2->setVisible(false);
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_plantilla_2->setText(
            QString::fromStdString(a_texto(tipo_o_plantilla_de_tipo_e::desconocido)));
    } break;
    case tipo_o_plantilla_de_tipo_e::regentero: {
        ui->label_plantilla_2->setVisible(false);
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_plantilla_2->setText(
            QString::fromStdString(a_texto(tipo_o_plantilla_de_tipo_e::desconocido)));
    } break;
    case tipo_o_plantilla_de_tipo_e::racionalnat: {
        ui->label_plantilla_2->setVisible(false);
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_plantilla_2->setText(
            QString::fromStdString(a_texto(tipo_o_plantilla_de_tipo_e::desconocido)));
    } break;
    case tipo_o_plantilla_de_tipo_e::racionalent: {
        ui->label_plantilla_2->setVisible(false);
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_plantilla_2->setText(
            QString::fromStdString(a_texto(tipo_o_plantilla_de_tipo_e::desconocido)));
    } break;
    case tipo_o_plantilla_de_tipo_e::natural: {
        ui->label_plantilla_2->setVisible(false);
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_plantilla_2->setText(
            QString::fromStdString(a_texto(tipo_o_plantilla_de_tipo_e::desconocido)));
    } break;
    case tipo_o_plantilla_de_tipo_e::entero: {
        ui->label_plantilla_2->setVisible(false);
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_plantilla_2->setText(
            QString::fromStdString(a_texto(tipo_o_plantilla_de_tipo_e::desconocido)));
    } break;
    case tipo_o_plantilla_de_tipo_e::desconocido:
    default: {
        ui->label_plantilla_2->setVisible(false);
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_plantilla_2->setText(
            QString::fromStdString(a_texto(tipo_o_plantilla_de_tipo_e::desconocido)));
    }
    }
}

void MainWindow::on_pushButton_orwise_clicked()
{
    const auto nombre_0{objeto[0].nombre};
    const auto nombre_1{objeto[1].nombre};
    const auto nombre_2{objeto[2].nombre};
    const auto tipo_0{objeto[0].tipo};
    const auto tipo_1{objeto[1].tipo};

    bool ok;

    if (tipo_0 == tipo_1) {
        objeto[2].tipo = tipo_0;
        switch (tipo_0) {
        case tipo_o_plantilla_de_tipo_e::longlong: {
            ll_lista[nombre_2] = ll_lista[nombre_0] | ll_lista[nombre_1];
            objeto[2].valor = ll_lista[nombre_2];
            ok = true;
        } break;
        case tipo_o_plantilla_de_tipo_e::unsignedlonglong: {
            ull_lista[nombre_2] = ull_lista[nombre_0] | ull_lista[nombre_1];
            objeto[2].valor = ull_lista[nombre_2];
            ok = true;
        } break;
        case tipo_o_plantilla_de_tipo_e::longdouble: {
            ok = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::digito: {
            const auto radix_0{digito_lista[nombre_0].radix()};
            const auto radix_1{digito_lista[nombre_1].radix()};
            if (radix_0 == radix_1) {
                digito_lista[nombre_2] = digito_lista[nombre_0] | digito_lista[nombre_1];
                objeto[2].valor = digito_lista[nombre_2];
                objeto[2].base = digito_lista[nombre_2].radix();
                ok = true;
            } else {
                objeto[2].tipo = tipo_o_plantilla_de_tipo_e::desconocido;
                ok = false;
            }
        } break;
        case tipo_o_plantilla_de_tipo_e::registro: {
            ok = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::regnatural: {
            ok = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::regentero: {
            ok = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalnat: {
            ok = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::racionalent: {
            ok = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::natural: {
            ok = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::entero: {
            ok = false;
        } break;
        case tipo_o_plantilla_de_tipo_e::desconocido:
        default: {
            ok = false;
        } break;
        }
    } else {
        objeto[2].tipo = tipo_o_plantilla_de_tipo_e::desconocido;
        ok = false;
    }

    /// ACTUALIZACIÓN DEL RESULTADO (LINEA 3)

    switch (tipo_0) {
    case tipo_o_plantilla_de_tipo_e::longlong: {
        ui->label_plantilla_2->setVisible(true);
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_plantilla_2->setText(QString::fromStdString(a_texto(objeto[2].tipo)));
        ui->label_valor_2->setText(QString::number(ll_lista[nombre_2]));
    } break;
    case tipo_o_plantilla_de_tipo_e::unsignedlonglong: {
        ui->label_plantilla_2->setVisible(true);
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_plantilla_2->setText(QString::fromStdString(a_texto(objeto[2].tipo)));
        ui->label_valor_2->setText(QString::number(ull_lista[nombre_2]));
    } break;
    case tipo_o_plantilla_de_tipo_e::longdouble: {
        ui->label_plantilla_2->setVisible(false);
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_plantilla_2->setText(
            QString::fromStdString(a_texto(tipo_o_plantilla_de_tipo_e::desconocido)));
    } break;
    case tipo_o_plantilla_de_tipo_e::digito: {
        ui->label_plantilla_2->setVisible(true);
        ui->label_base_2->setVisible(true);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_plantilla_2->setText(QString::fromStdString(a_texto(objeto[2].tipo)));
        ui->label_base_2->setText(QString::number(digito_lista[nombre_2].radix()));
        ui->label_valor_2->setText(QString::number(static_cast<ullint_t>(digito_lista[nombre_2]())));
    } break;
    case tipo_o_plantilla_de_tipo_e::registro: {
        ui->label_plantilla_2->setVisible(false);
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_plantilla_2->setText(
            QString::fromStdString(a_texto(tipo_o_plantilla_de_tipo_e::desconocido)));
    } break;
    case tipo_o_plantilla_de_tipo_e::regnatural: {
        ui->label_plantilla_2->setVisible(false);
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_plantilla_2->setText(
            QString::fromStdString(a_texto(tipo_o_plantilla_de_tipo_e::desconocido)));
    } break;
    case tipo_o_plantilla_de_tipo_e::regentero: {
        ui->label_plantilla_2->setVisible(false);
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_plantilla_2->setText(
            QString::fromStdString(a_texto(tipo_o_plantilla_de_tipo_e::desconocido)));
    } break;
    case tipo_o_plantilla_de_tipo_e::racionalnat: {
        ui->label_plantilla_2->setVisible(false);
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_plantilla_2->setText(
            QString::fromStdString(a_texto(tipo_o_plantilla_de_tipo_e::desconocido)));
    } break;
    case tipo_o_plantilla_de_tipo_e::racionalent: {
        ui->label_plantilla_2->setVisible(false);
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_plantilla_2->setText(
            QString::fromStdString(a_texto(tipo_o_plantilla_de_tipo_e::desconocido)));
    } break;
    case tipo_o_plantilla_de_tipo_e::natural: {
        ui->label_plantilla_2->setVisible(false);
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_plantilla_2->setText(
            QString::fromStdString(a_texto(tipo_o_plantilla_de_tipo_e::desconocido)));
    } break;
    case tipo_o_plantilla_de_tipo_e::entero: {
        ui->label_plantilla_2->setVisible(false);
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_plantilla_2->setText(
            QString::fromStdString(a_texto(tipo_o_plantilla_de_tipo_e::desconocido)));
    } break;
    case tipo_o_plantilla_de_tipo_e::desconocido:
    default: {
        ui->label_plantilla_2->setVisible(false);
        ui->label_base_2->setVisible(false);
        ui->label_longPE_2->setVisible(false);
        ui->label_longPF_2->setVisible(false);
        ui->label_valor_2->setVisible(true);
        ui->label_plantilla_2->setText(
            QString::fromStdString(a_texto(tipo_o_plantilla_de_tipo_e::desconocido)));
    }
    }
}
