#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::add_docSite(const QString &key, std::function<QString(const QString &)> mapper)
{
    ui->listWidget->addItem(key);
    siteMap.insert(key, mapper);
}

void MainWindow::on_lineEdit_returnPressed()
{
    if(ui->listWidget->currentItem() == nullptr){
        return;
    }
    auto name = ui->listWidget->currentItem()->data(Qt::DisplayRole).toString();
    auto site = siteMap[name];
    auto searchText = ui->lineEdit->text();
    ui->webEngineView->setUrl(QUrl(site(searchText)));
}
