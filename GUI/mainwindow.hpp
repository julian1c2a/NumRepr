#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_comboBox_plantilla_0_currentIndexChanged(int index);

    void on_comboBox_plantilla_1_currentIndexChanged(int index);

    void on_lineEdit_longitud_PE_0_textEdited(const QString &arg1);

    void on_lineEdit_longitud_PE_1_textEdited(const QString &arg1);

    void on_lineEdit_longitud_PF_0_textEdited(const QString &arg1);

    void on_lineEdit_longitud_PF_1_textEdited(const QString &arg1);

    void on_lineEdit_valor_0_textEdited(const QString &arg1);

    void on_lineEdit_valor_1_textEdited(const QString &arg1);

    void on_checkBox_variable_0_preparada_stateChanged(int arg1);

    void on_checkBox_variable_1_preparada_stateChanged(int arg1);

    void on_checkBox_variable_2_preparada_stateChanged(int arg1);

    void on_pushButton_asignacion_clicked();

    void on_comboBox_plantilla_0_activated(int index);

    void on_comboBox_plantilla_1_activated(int index);

    void on_lineEdit_Base_0_textEdited(const QString &arg1);

    void on_lineEdit_Base_1_textEdited(const QString &arg1);

    void on_lineEdit_nombre_in_0_textEdited(const QString &arg1);

    void on_lineEdit_nombre_in_1_textEdited(const QString &arg1);

    void on_lineEdit_nombre_in_2_textEdited(const QString &arg1);

    void on_pushButton_suma_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_HPP
