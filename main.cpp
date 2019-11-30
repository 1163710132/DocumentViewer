#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
#define ADD_SITE(NAME, URL) w.add_docSite(#NAME, [](const QString& search){\
    return URL + search;\
})
    ADD_SITE(QtDoc, "https://doc.qt.io/qt-5/search-results.html?q=");
    ADD_SITE(PyTorch, "https://pytorch.org/docs/stable/search.html?q=");
    ADD_SITE(Numpy, "https://numpy.org/doc/1.17/search.html?q=");
    ADD_SITE(Baidu, "https://www.baidu.com/s?wd=");
    ADD_SITE(Python, "https://docs.python.org/3.8/search.html?q=");
#undef ADD_SITE
    w.show();
    return a.exec();
}
