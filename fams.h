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

private:
    Ui::FAMS *ui;
};
#endif // FAMS_H
