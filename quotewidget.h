#ifndef QUOTEWIDGET_H
#define QUOTEWIDGET_H

#include <QWidget>

class QuoteWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QuoteWidget(QWidget *parent = nullptr, QString qoutesTxt ="");

signals:

};

#endif // QUOTEWIDGET_H
