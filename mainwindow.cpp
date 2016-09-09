#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ouvrir_clicked()
{
    imageLink = QFileDialog::getOpenFileName(this, "Ouvrir", QDir::homePath(), "Images (*.jpg *.jpeg *.png)");
    QMessageBox::information(this, "Fichier", "Le fichier que vous avez ouvert est : " + imageLink);
    image.load(imageLink);
    QPixmap imagePix = QPixmap(QPixmap::fromImage(image));
    imagePix = imagePix.scaled(ui->emplacementImage->size(), Qt::IgnoreAspectRatio, Qt::FastTransformation);
    ui->emplacementImage->setPixmap(imagePix);
}
