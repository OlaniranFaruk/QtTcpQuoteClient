#include "quotewidget.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QSizePolicy>

QuoteWidget::QuoteWidget(QWidget *parent, QString quoteTxt) : QWidget(parent)
{
    QStringList QuoteAndAuthor = quoteTxt.split(" - ");
    QVBoxLayout *quoteandauthorlayout = new QVBoxLayout(this);

    QLabel *quoteLine1 = new QLabel(this);
    QLabel *quoteLine2 = new QLabel(this);

    quoteandauthorlayout->addWidget(quoteLine1);
    quoteandauthorlayout->addWidget(quoteLine2);

    quoteLine1->setText(QuoteAndAuthor[0]);
    quoteLine2->setText(QuoteAndAuthor[1]);
    quoteLine2->setAlignment(Qt::AlignRight);
//    quoteLine1->setSizePolicy(QSizePolicy::Maximum);

}
