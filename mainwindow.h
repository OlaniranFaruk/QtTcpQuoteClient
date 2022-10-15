#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include "quotewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void closewindow();

//    void on_pushButton_clicked();
    void readyToRead();
    void startOperation();

private:
    Ui::MainWindow *ui;
    QTcpSocket *m_tcpSocket;
    QString m_numOfQuotes;
    QList<QByteArray> QuotesPerLines;
    QuoteWidget *newquote;
};
#endif // MAINWINDOW_H
