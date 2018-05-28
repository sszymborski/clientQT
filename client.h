#ifndef CLIENT_H
#define CLIENT_H

#include<iostream>
#include<cstdint>

#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>

namespace Ui {
class Client;
}

class Client : public QDialog
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();

    void setConnectParameters(std::string IPaddress, std::string Port);

private slots:
    void on_loadPictureButton_clicked();
    void on_sendButton_clicked();

private:
    Ui::Client *ui;
    std::string IPaddress;
    std::string port;
    uint8_t * bytes;
    int dataSize;
};

#endif // CLIENT_H
