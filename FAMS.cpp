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
#include <QComboBox>
#include <QSqlRecord>




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


void FAMS::on_pushButton_100_clicked()
{
    QString firstName    = ui->lineEdit_1->text().trimmed();
    QString lastName     = ui->lineEdit_2->text().trimmed();
    QString nationalCode = ui->lineEdit_3->text().trimmed();
    QString passportNo   = ui->lineEdit_4->text().trimmed();
    double  balance      = ui->doubleSpinBox_1->value();
    QDate   birthDate    = ui->dateEdit_1->date();

    if (firstName.isEmpty() ||
        lastName.isEmpty()  ||
        nationalCode.isEmpty() ||
        passportNo.isEmpty())
    {
        QMessageBox::warning(this, tr("خطا"),
                             tr("لطفاً همهٔ فیلدهای نام، فامیلی، کد ملی و کد پاسپورت را پر کنید."));
        return;
    }

    // 2. آماده‌سازی کوئری با positional placeholders
    QSqlQuery query;
    query.prepare(R"(
        INSERT INTO passengers
            (first_name, last_name, national_code,
             passport_number, birth_date, balance)
        VALUES (?, ?, ?, ?, ?, ?)
    )");

    // 3. بایند کردن مقادیر به ترتیب
    query.addBindValue(firstName);
    query.addBindValue(lastName);
    query.addBindValue(nationalCode);
    query.addBindValue(passportNo);
    // تبدیل تاریخ به رشته‌ی ISO و ذخیره به‌صورت TEXT
    query.addBindValue(birthDate.toString("yyyy-MM-dd"));
    query.addBindValue(balance);

    // 4. اجرای کوئری و گزارش
    if (!query.exec()) {
        QMessageBox::critical(this, tr("خطای بانک اطلاعاتی"),
                              tr("ثبت مسافر با خطا مواجه شد:\n%1")
                                  .arg(query.lastError().text()));
        return;
    }

    // 5. پاک‌سازی فرم و نمایش موفقیت
    QMessageBox::information(this, tr("موفقیت"),
                             tr("مسافر با موفقیت ثبت شد."));
    ui->lineEdit_1->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->doubleSpinBox_1->setValue(0.0);
    ui->dateEdit_1->setDate(QDate::currentDate());

}


void FAMS::on_pushButton_11_clicked()
{
    auto *model = new QSqlTableModel(this);
    model->setTable("passengers");
    // فقط رکوردهای حذف‌نشده (استفاده از is_deleted اگر دارید)
    // model->setFilter("is_deleted = 0");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    ui->tableView_1->setModel(model);
    ui->tableView_1->resizeColumnsToContents();
}


void FAMS::on_pushButton_10_clicked()
{
    auto *model = qobject_cast<QSqlTableModel*>(ui->tableView_1->model());
    if (!model) {
        QMessageBox::warning(this, tr("خطا"), tr("ابتدا لیست مسافران را بارگذاری کنید."));
        return;
    }

    // 2. گرفتن ردیف‌های انتخاب‌شده
    QItemSelectionModel *selModel = ui->tableView_1->selectionModel();
    QModelIndexList rows = selModel->selectedRows();
    if (rows.isEmpty()) {
        QMessageBox::information(this, tr("اطلاع"), tr("لطفاً حداقل یک مسافر را انتخاب کنید."));
        return;
    }

    // 3. حذف ردیف‌ها (اینجا DELETE فیزیکی انجام می‌شود)
    //    اگر بخواهید Soft-Delete کنید، به جای removeRow از UPDATE is_deleted=1 استفاده کنید.
    for (const QModelIndex &idx : rows) {
        model->removeRow(idx.row());
    }

    // 4. ارسال تغییرات به DB
    if (!model->submitAll()) {
        QMessageBox::critical(this, tr("خطای بانک اطلاعاتی"),
                              tr("عملیات حذف با خطا مواجه شد:\n%1").arg(model->lastError().text()));
        // در صورت نیاز rollback هم می‌توانید بزنید:
        // model->database().rollback();
    } else {
        QMessageBox::information(this, tr("موفقیت"),
                                 tr("مسافران انتخاب‌شده حذف شدند."));
    }

    // 5. تازه‌سازی نما
    model->select();
}


void FAMS::on_pushButton_12_clicked()
{
    auto *model = new QSqlTableModel(this);
    model->setTable("passengers");
    // اگر از ستون is_deleted برای حذف نرم استفاده می‌کنید:
    // model->setFilter("is_deleted = 0");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    // 2. بارگذاری داده‌ها
    model->select();

    // 3. اتصال مدل به view
    ui->tableView_2->setModel(model);
    ui->tableView_2->resizeColumnsToContents();
}


void FAMS::on_pushButton_70_clicked()
{
    QString flightNum   = ui->lineEdit_5->text().trimmed();
    QString origin      = ui->lineEdit_6->text().trimmed();
    QString destination = ui->lineEdit_7->text().trimmed();
    int     seatsTotal  = ui->spinBox_1->value();
    int     seatsAvail  = ui->spinBox_2->value();
    double  price       = ui->doubleSpinBox_2->value();
    QDateTime depTime   = ui->dateTimeEdit_1->dateTime();

    // 2. اعتبارسنجی پر بودن فیلدهای متنی و مقادیر معقول
    if (flightNum.isEmpty() ||
        origin.isEmpty() ||
        destination.isEmpty())
    {
        QMessageBox::warning(this, tr("خطا"),
                             tr("لطفاً فیلدهای شماره پرواز، مبدا و مقصد را کامل کنید."));
        return;
    }
    if (seatsTotal <= 0 || seatsAvail < 0) {
        QMessageBox::warning(this, tr("خطا"),
                             tr("تعداد کل صندلی‌ها باید بزرگ‌تر از صفر و صندلی‌های موجود صفر یا مثبت باشد."));
        return;
    }
    if (price < 0.0) {
        QMessageBox::warning(this, tr("خطا"),
                             tr("قیمت نمی‌تواند منفی باشد."));
        return;
    }

    // ۳. آماده‌سازی رشته‌های تاریخ/زمان به‌صورت TEXT
    QString depTimeStr     = depTime.toString("yyyy-MM-dd HH:mm:ss");
    QString currentTimeStr = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

    // ۴. کوئری INSERT با positional placeholders
    QSqlQuery query;
    query.prepare(R"(
        INSERT INTO flights
          (flight_number, origin, destination,
           departure_time, seats_total, seats_available,
           price, created_at, updated_at)
        VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)
    )");
    query.addBindValue(flightNum);
    query.addBindValue(origin);
    query.addBindValue(destination);
    query.addBindValue(depTimeStr);
    query.addBindValue(seatsTotal);
    query.addBindValue(seatsAvail);
    query.addBindValue(price);
    query.addBindValue(currentTimeStr);
    query.addBindValue(currentTimeStr);

    // ۵. اجرای کوئری و نمایش نتیجه
    if (!query.exec()) {
        QMessageBox::critical(this, tr("خطای بانک اطلاعاتی"),
                              tr("ثبت پرواز با خطا مواجه شد:\n%1")
                                  .arg(query.lastError().text()));
        return;
    }

    QMessageBox::information(this, tr("موفقیت"),
                             tr("پرواز با موفقیت ثبت شد."));

    // ۶. پاک‌سازی فرم (اختیاری)
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->spinBox_1->setValue(0);
    ui->spinBox_2->setValue(0);
    ui->doubleSpinBox_2->setValue(0.0);
    ui->dateTimeEdit_1->setDateTime(QDateTime::currentDateTime());
}


void FAMS::on_pushButton_21_clicked()
{
    auto *model = new QSqlTableModel(this);
    model->setTable("flights");
    // اگر از حذف نرم استفاده می‌کنید:
    // model->setFilter("is_deleted = 0");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    // 2. اتصال مدل به ویو
    ui->tableView_3->setModel(model);
    ui->tableView_3->resizeColumnsToContents();
}


void FAMS::on_pushButton_22_clicked()
{
    auto *model = qobject_cast<QSqlTableModel*>(ui->tableView_3->model());
    if (!model) {
        QMessageBox::warning(this, tr("خطا"),
                             tr("ابتدا باید لیست پروازها را با دکمهٔ «بارگذاری» نمایش دهید."));
        return;
    }

    // 2. گرفتن ردیف‌های انتخاب‌شده
    QItemSelectionModel *selModel = ui->tableView_3->selectionModel();
    QModelIndexList rows = selModel->selectedRows();
    if (rows.isEmpty()) {
        QMessageBox::information(this, tr("اطلاع"),
                                 tr("لطفاً حداقل یک پرواز را انتخاب کنید."));
        return;
    }

    // 3. حذف ردیف‌ها (physical delete)
    for (const QModelIndex &idx : rows) {
        model->removeRow(idx.row());
    }

    // 4. اعمال تغییرات در دیتابیس
    if (!model->submitAll()) {
        QMessageBox::critical(this, tr("خطای بانک اطلاعاتی"),
                              tr("عملیات حذف با خطا مواجه شد:\n%1")
                                  .arg(model->lastError().text()));
        model->revertAll();
    } else {
        QMessageBox::information(this, tr("موفقیت"),
                                 tr("پروازهای انتخاب‌شده حذف شدند."));
    }

    // 5. تازه‌سازی مدل
    model->select();
}


void FAMS::on_pushButton_24_clicked()
{
    QString term = ui->lineEdit_8->text().trimmed();
    if (term.isEmpty()) {
        QMessageBox::warning(this, tr("خطا"), tr("لطفاً یک عبارت برای جستجو وارد کنید."));
        return;
    }

    // %term% برای LIKE
    QString like = QString("%%1%").arg(term);

    // فیلتر ترکیبی روی همهٔ فیلدها
    QString filter = QString(
                         "flight_number LIKE '%1' OR "
                         "origin        LIKE '%1' OR "
                         "destination   LIKE '%1' OR "
                         "CAST(seats_total   AS TEXT) LIKE '%1' OR "
                         "CAST(seats_available AS TEXT) LIKE '%1' OR "
                         "departure_time LIKE '%1'"
                         ).arg(like);

    auto *model = new QSqlTableModel(this);
    model->setTable("flights");
    model->setFilter(filter);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    ui->tableView_4->setModel(model);
    ui->tableView_4->resizeColumnsToContents();
}


void FAMS::on_pushButton_26_clicked()
{
    auto *model = new QSqlTableModel(this);
    model->setTable("flights");
    // اگر از حذف نرم (soft delete) استفاده می‌کنید، می‌توانید فیلتر بگذارید:
    // model->setFilter("is_deleted = 0");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    // 2. بارگذاری داده‌ها
    model->select();

    // 3. تنظیم مدل روی tableView_5
    ui->tableView_5->setModel(model);
    ui->tableView_5->resizeColumnsToContents();
}



void FAMS::on_pushButton_71_clicked()
{
    auto *model = new QSqlTableModel(this);
    model->setTable("passengers");
    // اگر از حذف نرم استفاده می‌کنید:
    // model->setFilter("is_deleted = 0");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    // 2. بارگذاری داده‌ها
    model->select();

    // 3. اتصال مدل به tableView_13
    ui->tableView_13->setModel(model);
    ui->tableView_13->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_13->setSelectionMode(QAbstractItemView::SingleSelection);
    // در صورت وجود ستون‌های سیستمی مثل is_deleted، آنها را مخفی کنید:
    // int col = model->fieldIndex("is_deleted");
    // if (col >= 0) ui->tableView_13->hideColumn(col);
    ui->tableView_13->resizeColumnsToContents();
}




void FAMS::on_pushButton_72_clicked()
{
    auto *model = new QSqlTableModel(this);
    model->setTable("flights");
    // اگر از حذف نرم استفاده می‌کنید:
    // model->setFilter("is_deleted = 0");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    // 2. بارگذاری داده‌ها
    model->select();

    // 3. اتصال مدل به tableView_12
    ui->tableView_12->setModel(model);
    ui->tableView_12->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_12->setSelectionMode(QAbstractItemView::SingleSelection);
    // در صورت وجود ستون‌های سیستمی مثل is_deleted، می‌توانید آن را مخفی کنید:
    // int col = model->fieldIndex("is_deleted");
    // if (col >= 0) ui->tableView_12->hideColumn(col);
    ui->tableView_12->resizeColumnsToContents();
}




void FAMS::on_pushButton_74_clicked()
{
    QString term = ui->lineEdit_18->text().trimmed();

    // 2. گرفتن مدل متصل به tableView_13
    auto *model = qobject_cast<QSqlTableModel*>(ui->tableView_13->model());
    if (!model) {
        QMessageBox::warning(this, tr("خطا"),
                             tr("ابتدا لیست مسافران را با دکمهٔ «نمایش» بارگذاری کنید."));
        return;
    }

    // 3. اعمال فیلتر بر اساس عبارت جستجو
    if (term.isEmpty()) {
        // اگر چیزی وارد نشده، همهٔ ردیف‌ها را نمایش بده
        model->setFilter("");
    } else {
        // جستجو در چهار ستون متنی
        QString filter = QString(
                             "first_name LIKE '%%1%' OR "
                             "last_name LIKE '%%1%' OR "
                             "national_code LIKE '%%1%' OR "
                             "passport_number LIKE '%%1%'"
                             ).arg(term);
        model->setFilter(filter);
    }

    // 4. بارگذاری مجدد داده‌ها و تنظیم ستون‌ها
    model->select();
    ui->tableView_13->resizeColumnsToContents();
}


void FAMS::on_pushButton_73_clicked()
{
    QString term = ui->lineEdit_17->text().trimmed();

    // 2. گرفتن مدل متصل به tableView_12
    auto *model = qobject_cast<QSqlTableModel*>(ui->tableView_12->model());
    if (!model) {
        QMessageBox::warning(this, tr("خطا"),
                             tr("ابتدا لیست پروازها را با دکمهٔ «نمایش» بارگذاری کنید."));
        return;
    }

    // 3. اعمال فیلتر بر اساس عبارت جستجو
    if (term.isEmpty()) {
        // اگر عبارت خالی است، فیلتر را حذف کن تا همهٔ ردیف‌ها نمایش داده شوند
        model->setFilter("");
    } else {
        // جستجو در ستون‌های متنی و عددی (با CAST به TEXT)
        QString like  = QString("%%1%").arg(term);
        QString filter = QString(
                             "flight_number   LIKE '%1' OR "
                             "origin          LIKE '%1' OR "
                             "destination     LIKE '%1' OR "
                             "CAST(seats_total    AS TEXT) LIKE '%1' OR "
                             "CAST(seats_available AS TEXT) LIKE '%1' OR "
                             "departure_time  LIKE '%1'"
                             ).arg(like);
        model->setFilter(filter);
    }

    // 4. بارگذاری مجدد داده‌ها و تنظیم ستون‌ها
    model->select();
    ui->tableView_12->resizeColumnsToContents();
}


void FAMS::on_pushButton_31_clicked()
{
    auto *modelP = qobject_cast<QSqlTableModel*>(ui->tableView_13->model());
    auto *modelF = qobject_cast<QSqlTableModel*>(ui->tableView_12->model());
    if (!modelP || !modelF) {
        QMessageBox::warning(this, tr("خطا"),
                             tr("ابتدا لیست مسافران و پروازها را بارگذاری کنید."));
        return;
    }

    // 2. بررسی انتخاب ردیف در هر دو TableView
    QItemSelectionModel *selP = ui->tableView_13->selectionModel();
    QItemSelectionModel *selF = ui->tableView_12->selectionModel();
    if (!selP->hasSelection() || !selF->hasSelection()) {
        QMessageBox::warning(this, tr("خطا"),
                             tr("لطفاً یک مسافر و یک پرواز را انتخاب کنید."));
        return;
    }

    // 3. استخراج passenger_id و flight_id از ردیف‌های انتخاب‌شده
    int rowP = selP->selectedRows().first().row();
    int rowF = selF->selectedRows().first().row();
    int passengerId = modelP->data(modelP->index(rowP, modelP->fieldIndex("passenger_id"))).toInt();
    int flightId    = modelF->data(modelF->index(rowF,    modelF->fieldIndex("flight_id"))).toInt();

    // 4. واکشی موجودی مسافر
    QSqlQuery q;
    q.prepare("SELECT balance FROM passengers WHERE passenger_id = ?");
    q.addBindValue(passengerId);
    if (!q.exec() || !q.next()) {
        QMessageBox::critical(this, tr("خطای DB"),
                              tr("خطا در واکشی موجودی مسافر:\n%1").arg(q.lastError().text()));
        return;
    }
    double balance = q.value(0).toDouble();

    // 5. واکشی تعداد صندلی و قیمت پرواز
    q.prepare("SELECT seats_available, price FROM flights WHERE flight_id = ?");
    q.addBindValue(flightId);
    if (!q.exec() || !q.next()) {
        QMessageBox::critical(this, tr("خطای DB"),
                              tr("خطا در واکشی اطلاعات پرواز:\n%1").arg(q.lastError().text()));
        return;
    }
    int    seatsAvail = q.value(0).toInt();
    double price      = q.value(1).toDouble();

    // 6. بررسی شرایط رزرو
    if (seatsAvail < 1) {
        QMessageBox::warning(this, tr("خطا"),
                             tr("پرواز انتخاب‌شده صندلی خالی ندارد."));
        return;
    }
    if (balance < price) {
        QMessageBox::warning(this, tr("خطا"),
                             tr("کیف‌پول کافی نیست."));
        return;
    }

    // 7. آماده‌سازی زمان جاری و شروع تراکنش
    QString now = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.transaction()) {
        QMessageBox::critical(this, tr("خطای DB"),
                              tr("شروع تراکنش با خطا مواجه شد."));
        return;
    }

    // 8. کم کردن موجودی مسافر
    QSqlQuery updP;
    updP.prepare(R"(
        UPDATE passengers
        SET balance = balance - ?, updated_at = ?
        WHERE passenger_id = ?
    )");
    updP.addBindValue(price);
    updP.addBindValue(now);
    updP.addBindValue(passengerId);
    if (!updP.exec()) {
        db.rollback();
        QMessageBox::critical(this, tr("خطای DB"),
                              tr("کسر مبلغ از کیف‌پول با خطا مواجه شد:\n%1").arg(updP.lastError().text()));
        return;
    }

    // 9. کم کردن صندلی موجود پرواز
    QSqlQuery updF;
    updF.prepare(R"(
        UPDATE flights
        SET seats_available = seats_available - 1, updated_at = ?
        WHERE flight_id = ?
    )");
    updF.addBindValue(now);
    updF.addBindValue(flightId);
    if (!updF.exec()) {
        db.rollback();
        QMessageBox::critical(this, tr("خطای DB"),
                              tr("به‌روزرسانی صندلی‌ها با خطا مواجه شد:\n%1").arg(updF.lastError().text()));
        return;
    }

    // 10. ثبت رکورد رزرو
    QSqlQuery ins;
    ins.prepare(R"(
        INSERT INTO reservations
            (passenger_id, flight_id, reserved_at, amount_paid, status_code)
        VALUES (?, ?, ?, ?, 'booked')
    )");
    ins.addBindValue(passengerId);
    ins.addBindValue(flightId);
    ins.addBindValue(now);
    ins.addBindValue(price);
    if (!ins.exec()) {
        db.rollback();
        QMessageBox::critical(this, tr("خطای DB"),
                              tr("ثبت رزرو با خطا مواجه شد:\n%1").arg(ins.lastError().text()));
        return;
    }

    // 11. پایان تراکنش
    if (!db.commit()) {
        db.rollback();
        QMessageBox::critical(this, tr("خطای DB"),
                              tr("پایان تراکنش با خطا مواجه شد."));
        return;
    }

    // 12. نمایش پیام موفقیت و تازه‌سازی نماها
    QMessageBox::information(this, tr("موفقیت"),
                             tr("رزرو با موفقیت ثبت شد."));
    modelP->select();
    modelF->select();
}


void FAMS::on_pushButton_75_clicked()
{
    auto *model = new QSqlTableModel(this);
    model->setTable("reservations");
    // اگر از حذف نرم استفاده می‌کنید (مثلاً is_deleted در این جدول):
    // model->setFilter("is_deleted = 0");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    // 2. بارگذاری داده‌ها
    model->select();

    // 3. اتصال مدل به tableView_101
    ui->tableView_101->setModel(model);
    ui->tableView_101->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_101->setSelectionMode(QAbstractItemView::SingleSelection);
    // در صورت وجود ستون‌های سیستمی یا کم‌اهمیت، می‌توانید آنها را مخفی کنید:
    // int col = model->fieldIndex("is_deleted");
    // if (col >= 0) ui->tableView_101->hideColumn(col);

    // 4. تنظیم اندازهٔ ستون‌ها
    ui->tableView_101->resizeColumnsToContents();
}


void FAMS::on_pushButton_101_clicked()
{
    QString term = ui->lineEdit_101->text().trimmed();

    // 2. گرفتن مدل متصل به tableView_101
    auto *model = qobject_cast<QSqlTableModel*>(ui->tableView_101->model());
    if (!model) {
        QMessageBox::warning(this, tr("خطا"),
                             tr("ابتدا باید لیست رزروها را با دکمهٔ «نمایش» بارگذاری کنید."));
        return;
    }

    // 3. اعمال فیلتر بر اساس عبارت جستجو
    if (term.isEmpty()) {
        // اگر خالی است، همهٔ رکوردها را نشان بده
        model->setFilter("");
    } else {
        QString like = QString("%%1%").arg(term);
        // جستجو در ستون‌های متعدد
        QString filter = QString(
                             "reservation_id   LIKE '%1' OR "
                             "passenger_id     LIKE '%1' OR "
                             "flight_id        LIKE '%1' OR "
                             "reserved_at      LIKE '%1' OR "
                             "amount_paid      LIKE '%1' OR "
                             "status_code      LIKE '%1' OR "
                             "refund_amount    LIKE '%1' OR "
                             "updated_at       LIKE '%1'"
                             ).arg(like);

        model->setFilter(filter);
    }

    // 4. بارگذاری مجدد و تنظیم ستون‌ها
    model->select();
    ui->tableView_101->resizeColumnsToContents();
}


void FAMS::on_pushButton_65_clicked()
{
    auto *model = qobject_cast<QSqlTableModel*>(ui->tableView_101->model());
    if (!model) {
        QMessageBox::warning(this, tr("خطا"),
                             tr("ابتدا لیست رزروها را بارگذاری کنید."));
        return;
    }

    // 2. بررسی انتخاب یک ردیف
    QItemSelectionModel *sel = ui->tableView_101->selectionModel();
    if (!sel->hasSelection()) {
        QMessageBox::warning(this, tr("خطا"),
                             tr("لطفاً یک رزرو را انتخاب کنید."));
        return;
    }

    // 3. استخراج داده‌های رزرو
    int row = sel->selectedRows().first().row();
    QSqlRecord rec = model->record(row);
    int reservationId = rec.value("reservation_id").toInt();
    int passengerId   = rec.value("passenger_id").toInt();
    int flightId      = rec.value("flight_id").toInt();
    QString status    = rec.value("status_code").toString();
    double amountPaid = rec.value("amount_paid").toDouble();

    // 4. فقط رزروهای وضعیت "booked" قابل استرداد هستند
    if (status != "booked") {
        QMessageBox::warning(this, tr("خطا"),
                             tr("این رزرو قابل استرداد نیست."));
        return;
    }

    // 5. واکشی زمان پرواز
    QSqlQuery q;
    q.prepare("SELECT departure_time FROM flights WHERE flight_id = ?");
    q.addBindValue(flightId);
    if (!q.exec() || !q.next()) {
        QMessageBox::critical(this, tr("خطای DB"),
                              tr("خطا در واکشی زمان پرواز:\n%1").arg(q.lastError().text()));
        return;
    }
    QDateTime depTime = QDateTime::fromString(q.value(0).toString(), "yyyy-MM-dd HH:mm:ss");

    // 6. محاسبه فاصله زمانی تا پرواز
    QDateTime now = QDateTime::currentDateTime();
    qint64 secondsToDeparture = now.secsTo(depTime);

    double refundPercent;
    if (secondsToDeparture < 0) {
        QMessageBox::warning(this, tr("خطا"),
                             tr("پرواز قبلاً انجام شده؛ امکان استرداد نیست."));
        return;
    }
    else if (secondsToDeparture < 24 * 3600) {
        QMessageBox::warning(this, tr("خطا"),
                             tr("کمتر از ۲۴ ساعت تا پرواز مانده؛ امکان استرداد نیست."));
        return;
    }
    else if (secondsToDeparture <= 48 * 3600) {
        refundPercent = 0.50;  // ۵۰٪
    }
    else {
        refundPercent = 0.90;  // ۹۰٪
    }

    double refundAmount = amountPaid * refundPercent;
    QString nowStr = now.toString("yyyy-MM-dd HH:mm:ss");

    // 7. شروع تراکنش
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.transaction()) {
        QMessageBox::critical(this, tr("خطای DB"),
                              tr("شروع تراکنش با خطا مواجه شد."));
        return;
    }

    // 8. به‌روزرسانی وضعیت رزرو
    QSqlQuery updRes;
    updRes.prepare(R"(
        UPDATE reservations
        SET status_code = ?, refund_amount = ?, updated_at = ?
        WHERE reservation_id = ?
    )");
    updRes.addBindValue("refunded");
    updRes.addBindValue(refundAmount);
    updRes.addBindValue(nowStr);
    updRes.addBindValue(reservationId);
    if (!updRes.exec()) {
        db.rollback();
        QMessageBox::critical(this, tr("خطای DB"),
                              tr("خطا در به‌روزرسانی رزرو:\n%1").arg(updRes.lastError().text()));
        return;
    }

    // 9. آزادسازی یک صندلی در پرواز
    QSqlQuery updFlight;
    updFlight.prepare(R"(
        UPDATE flights
        SET seats_available = seats_available + 1, updated_at = ?
        WHERE flight_id = ?
    )");
    updFlight.addBindValue(nowStr);
    updFlight.addBindValue(flightId);
    if (!updFlight.exec()) {
        db.rollback();
        QMessageBox::critical(this, tr("خطای DB"),
                              tr("خطا در به‌روزرسانی صندلی پرواز:\n%1").arg(updFlight.lastError().text()));
        return;
    }

    // 10. بازگشت وجه به کیف‌پول مسافر
    QSqlQuery updPass;
    updPass.prepare(R"(
        UPDATE passengers
        SET balance = balance + ?, updated_at = ?
        WHERE passenger_id = ?
    )");
    updPass.addBindValue(refundAmount);
    updPass.addBindValue(nowStr);
    updPass.addBindValue(passengerId);
    if (!updPass.exec()) {
        db.rollback();
        QMessageBox::critical(this, tr("خطای DB"),
                              tr("خطا در بازگشت وجه به کیف‌پول:\n%1").arg(updPass.lastError().text()));
        return;
    }

    // 11. تایید تراکنش
    if (!db.commit()) {
        db.rollback();
        QMessageBox::critical(this, tr("خطای DB"),
                              tr("تأیید تراکنش با خطا مواجه شد."));
        return;
    }

    // 12. پیام موفقیت و تازه‌سازی نما
    QMessageBox::information(this, tr("موفقیت"),
                             tr("استرداد با موفقیت انجام شد.\nمبلغ برگشتی: %1").arg(refundAmount));
    model->select();
}


void FAMS::on_pushButton_67_clicked()
{
    auto *model = new QSqlTableModel(this);
    model->setTable("reservations");
    // در صورت استفاده از حذف نرم:
    // model->setFilter("status_code <> 'cancelled'");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    // 2. بارگذاری داده‌ها
    model->select();

    // 3. اتصال مدل به tableView_11
    ui->tableView_11->setModel(model);
    ui->tableView_11->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_11->setSelectionMode(QAbstractItemView::SingleSelection);
    // در صورت وجود ستون‌های سیستمی که نیاز به نمایش نیستند:
    // int col = model->fieldIndex("updated_at");
    // if (col >= 0) ui->tableView_11->hideColumn(col);

    // 4. تنظیم اندازهٔ ستون‌ها
    ui->tableView_11->resizeColumnsToContents();
}

