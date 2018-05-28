#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    dataSize = 0;
}

Client::~Client()
{
    delete ui;
}

void Client::on_loadPictureButton_clicked()
{
    const QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
    ui->fileNameLabel->setText(fileName);
    QFile* file = new QFile(fileName);
    file->open(QIODevice::ReadOnly);
    QByteArray image = file->readAll();
    int originalSize = image.length();
    char * tmp = image.data();
    bytes = new uint8_t[originalSize];
    for (unsigned int i = 0; i < originalSize; ++i)
        bytes[i] = (uint8_t) tmp[i];
    dataSize = originalSize;
}

void Client::setConnectParameters(std::string givenIPaddress, std::string givenPort){
   IPaddress = givenIPaddress;
   port = givenPort;
   std::cout << IPaddress << std::endl;
   std::cout << port << std::endl;
}

void Client::on_sendButton_clicked()
{
    if(dataSize > 0){
    for (unsigned int i = 0; i < dataSize; ++i)
        std::cout << bytes[i] << std::endl;
    }
    else{
        QMessageBox::information(this, tr("Client"), tr("First choose Picture") );
    }
}
