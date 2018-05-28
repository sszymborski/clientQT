#ifndef CLIENTCONNECTION_H
#define CLIENTCONNECTION_H

#include <QWidget>

#include "controller.h"
#include "client.h"

namespace Ui {
class ClientConnection;
}

class ClientConnection : public QWidget
{
    Q_OBJECT

public:
    Controller *controller;
    explicit ClientConnection(QWidget *parent = 0);
    ~ClientConnection();

private slots:
    void on_connectButton_clicked();

private:
    Ui::ClientConnection *ui;
};

#endif // CLIENTCONNECTION_H
