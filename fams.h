#ifndef FAMS_H
#define FAMS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class FAMS;
}
QT_END_NAMESPACE

class FAMS : public QMainWindow
{
    Q_OBJECT

public:
    FAMS(QWidget *parent = nullptr);
    ~FAMS();

private slots:
    void on_pushButton_19_clicked();

    void on_pushButton_100_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_70_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_71_clicked();

    void on_pushButton_72_clicked();

    void on_pushButton_74_clicked();

    void on_pushButton_73_clicked();

    void on_pushButton_75_clicked();

    void on_pushButton_101_clicked();

    void on_pushButton_65_clicked();

    void on_pushButton_67_clicked();

private:
    Ui::FAMS *ui;
};
#endif // FAMS_H
