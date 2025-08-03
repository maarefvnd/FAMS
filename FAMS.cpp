#include "fams.h"
#include "ui_fams.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlTableModel>
#include <algorithm>
#include <QItemSelectionModel>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QDate>
#include <QtSql>
#include <QComboBox>




FAMS::FAMS(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FAMS)
//------------------------------------------------------------------------------------------------------
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);



    QSqlDatabase db;
    db = QSqlDatabase :: addDatabase("QSQLITE");
    db.setDatabaseName("M:/Programming/FAMS/FAMS/FAMS_DB/FAMS_DB.db");
    db.open();




//---------------------------------------------------------------------------------------------------------

    connect(ui->pushButton_1, &QPushButton::clicked, this, [=](){
         ui->stackedWidget->setCurrentIndex(1); // برگشت به منو
    });

    connect(ui->pushButton_2, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(5); // برگشت به منو
    });

    connect(ui->pushButton_3, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(10); // برگشت به منو
    });

    connect(ui->pushButton_4, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(13); // برگشت به منو
    });

    connect(ui->pushButton_1, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(1); // برگشت به منو
    });

    connect(ui->pushButton_5, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(2); // برگشت به منو
    });

    connect(ui->pushButton_7, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(3); // برگشت به منو
    });

    connect(ui->pushButton_6, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(4); // برگشت به منو
    });

    connect(ui->pushButton_69, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(0); // برگشت به منو
    });

    connect(ui->pushButton_8, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(1); // برگشت به منو
    });

    connect(ui->pushButton_9, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(1); // برگشت به منو
    });

    connect(ui->pushButton_13, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(1); // برگشت به منو
    });

    connect(ui->pushButton_18, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(0); // برگشت به منو
    });

    connect(ui->pushButton_14, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(6); // برگشت به منو
    });

    connect(ui->pushButton_15, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(7); // برگشت به منو
    });

    connect(ui->pushButton_16, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(8); // برگشت به منو
    });

    connect(ui->pushButton_17, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(9); // برگشت به منو
    });

    connect(ui->pushButton_28, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(11); // برگشت به منو
    });

    connect(ui->pushButton_29, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(12); // برگشت به منو
    });

    connect(ui->pushButton_30, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(0); // برگشت به منو
    });

    connect(ui->pushButton_32, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(10); // برگشت به منو
    });

    connect(ui->pushButton_66, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(10); // برگشت به منو
    });

    connect(ui->pushButton_68, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(0); // برگشت به منو
    });

    connect(ui->pushButton_27, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(5); // برگشت به منو
    });

    connect(ui->pushButton_25, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(5); // برگشت به منو
    });

    connect(ui->pushButton_23, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(5); // برگشت به منو
    });

    connect(ui->pushButton_20, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(5); // برگشت به منو
    });







//----------------------------------------------------------------------------------------------------------
}

FAMS::~FAMS()
{
    delete ui;
}





void FAMS::on_pushButton_19_clicked()
{
    close();
}

