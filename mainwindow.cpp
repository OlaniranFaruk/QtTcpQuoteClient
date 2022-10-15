#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "quotewidget.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(closewindow()));
    connect(ui->actionRenew, SIGNAL(triggered()), this, SLOT(startOperation()));
    connect(ui->pushButton, SIGNAL(clicked()), this ,SLOT(startOperation()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closewindow()
{
    this->close();
}



void MainWindow::startOperation()
{
    //1): connect to the server via localhost on port 64000
    m_tcpSocket = new QTcpSocket(this);
    m_tcpSocket->connectToHost("127.0.0.1", 64000);

    //2). Forward the spinbox number as an ASCII string
    m_numOfQuotes = ui->spinBox->text();


       //receive number as ASCII
        m_tcpSocket->write(m_numOfQuotes.toLatin1());

        connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(readyToRead()));


}


void MainWindow::readyToRead()
{


    QTcpSocket * client = qobject_cast<QTcpSocket *>(sender());
    Q_ASSERT(client != NULL);
    QByteArray Quotes = client->readAll();

    QuotesPerLines = Quotes.split('\n');

    qDebug() << QuotesPerLines;


     //4). Close the connection
    m_tcpSocket->close();

    QVBoxLayout *quoteLayout = new QVBoxLayout();

    int i = 0;


    //skip the empty indexes of the list cause be the double \n at the end of the response
    while(QuotesPerLines[i] != "") {
        newquote = new QuoteWidget(this, QuotesPerLines[i]);
        quoteLayout->addWidget(newquote);
        i++;

    }


        ui->groupBox->setLayout(quoteLayout);

}







