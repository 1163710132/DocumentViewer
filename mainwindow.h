#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <functional>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void add_docSite(const QString& key, std::function<QString(const QString&)> mapper);

private slots:
    void on_lineEdit_returnPressed();

private:
    Ui::MainWindow *ui;
    QMap<QString, std::function<QString(const QString&)>> siteMap;
};
#endif // MAINWINDOW_H
