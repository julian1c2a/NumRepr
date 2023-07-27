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
    void on_lineEdit_nombre_in_1_textChanged(const QString &arg1);

    void on_lineEdit_nombre_in_2_textChanged(const QString &arg1);

    void on_comboBox_plantilla_1_currentIndexChanged(int index);

    void on_comboBox_plantilla_2_currentIndexChanged(int index);

    void on_lineEdit_longitud_PE_1_textChanged(const QString &arg1);

    void on_lineEdit_longitud_PE_2_textChanged(const QString &arg1);

    void on_lineEdit_longitud_PF_1_textChanged(const QString &arg1);

    void on_lineEdit_longitud_PF_2_textChanged(const QString &arg1);

    void on_lineEdit_valor_1_textChanged(const QString &arg1);

    void on_lineEdit_valor_2_textChanged(const QString &arg1);

    void on_checkBox_variable_1_preparada_stateChanged(int arg1);

    void on_checkBox_variable_2_preparada_stateChanged(int arg1);

    void on_pushButton_asignacion_clicked();

    //void on_lineEdit_nombre_in_result_textChanged(const QString &arg1);

    void on_comboBox_plantilla_1_activated(int index);

    void on_comboBox_plantilla_2_activated(int index);

    void on_lineEdit_Base_1_textEdited(const QString &arg1);

    void on_lineEdit_Base_2_textEdited(const QString &arg1);

    void on_lineEdit_nombre_in_result_textEdited(const QString &arg1);

    void on_checkBox_variable_result_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_HPP
