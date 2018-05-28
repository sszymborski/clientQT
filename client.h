#ifndef CLIENT_H
#define CLIENT_H

#include<iostream>
#include<cstdint>

#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QTextStream>
#include <QDataStream>
#include <QGraphicsView>

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

public slots:
    void gotMessage(uint8_t * bytes, int size);

private slots:
    void on_loadPictureButton_clicked();
    void on_sendButton_clicked();
    void on_pushButton_clicked();

private:
    Ui::Client *ui;

    QGraphicsScene *scene;

    std::string IPaddress;
    std::string port;
    uint8_t * bytes;
    int dataSize;
};

#endif // CLIENT_H
