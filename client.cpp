#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    dataSize = 0;
    scene = new QGraphicsScene(this);
    ui->graphicsView->setSceneRect(0, 0, 512, 512);
    ui->graphicsView->setScene(scene);
    connect(this, SIGNAL(ui->pushButton->clicked();), this, SLOT(gotMessage();));
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

void Client::gotMessage(uint8_t * bytes, int size){
    std::cout << "I got message" << std::endl;
    QByteArray * img = new QByteArray(reinterpret_cast<const char*>(bytes), size);

    QFile file("C:/MyDir/Last_Image.jpg");
    file.open(QIODevice::WriteOnly);
    file.write(*img);
    file.close();

    QPixmap m("C:/MyDir/Last_Image.jpg");
    scene->setBackgroundBrush(m.scaled(512,512,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->graphicsView->setScene(scene);
}

void Client::on_pushButton_clicked()
{
    int size = dataSize;
    std::cout << "I got message" << std::endl;
    QByteArray * img = new QByteArray(reinterpret_cast<const char*>(bytes), size);

    QFile file("C:/MyDir/Last_Image.jpg");
    file.open(QIODevice::WriteOnly);
    file.write(*img);
    file.close();

    QPixmap m("C:/MyDir/Last_Image.jpg");
    scene->setBackgroundBrush(m.scaled(512,512,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->graphicsView->setScene(scene);
}
