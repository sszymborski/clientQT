#include "clientconnection.h"
#include "ui_clientconnection.h"

#include <QMessageBox>

ClientConnection::ClientConnection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientConnection)
{
    ui->setupUi(this);
    controller = new Controller();
}

ClientConnection::~ClientConnection()
{
    delete ui;
}

void ClientConnection::on_connectButton_clicked()
{
    if(controller->canConnect()){
        Client *client = new Client();
        client->exec();
        client->setConnectParameters(ui->IPaddressLineEdit->text().toStdString().c_str(),
                                     ui->portLineEdit->text().toStdString().c_str());
    }
    else{
        QMessageBox::information(this, tr("ClientConnection"), tr("Fail to connect") );
    }
}
