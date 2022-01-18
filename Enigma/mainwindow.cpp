#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QDebug>
#include <QThread>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Enigma");
    ui->plugBoard->setVisible(false);
    ui->labelDecrypt->setText("");
    ui->labelEncrypt->setText("");
}

MainWindow::~MainWindow()
{
    delete ui;
}

char MainWindow::enigmaIt(char decrypted)
{
    //90 - (91 - num)%26

    return char (90 - (91 - decrypted)%26);

}

void MainWindow::keyPressEvent(QKeyEvent *keyPressed)
{
    if (!keyPressed->isAutoRepeat() and !plugBoardConfig)
    {
        bool isAlpha = true;
        switch(keyPressed->key())
        {
            case Qt::Key_A:
                ui->buttonA->setStyleSheet("background-image: url(:/images/images/pressed.png);");
                break;
            case Qt::Key_B:
                ui->buttonB->setStyleSheet("background-image: url(:/images/images/pressed.png);");
                break;
            case Qt::Key_C:
                ui->buttonC->setStyleSheet("background-image: url(:/images/images/pressed.png);");
                break;
            case Qt::Key_D:
                ui->buttonD->setStyleSheet("background-image: url(:/images/images/pressed.png);");
                break;
            case Qt::Key_E:
                ui->buttonE->setStyleSheet("background-image: url(:/images/images/pressed.png);");
                break;
            case Qt::Key_F:
                ui->buttonF->setStyleSheet("background-image: url(:/images/images/pressed.png);");
                break;
            case Qt::Key_G:
                ui->buttonG->setStyleSheet("background-image: url(:/images/images/pressed.png);");
                break;
            case Qt::Key_H:
                ui->buttonH->setStyleSheet("background-image: url(:/images/images/pressed.png);");
                break;
            case Qt::Key_I:
                ui->buttonI->setStyleSheet("background-image: url(:/images/images/pressed.png);");
                break;
            case Qt::Key_J:
                ui->buttonJ->setStyleSheet("background-image: url(:/images/images/pressed.png);");
                break;
            case Qt::Key_K:
                ui->buttonK->setStyleSheet("background-image: url(:/images/images/pressed.png);");
                break;
            case Qt::Key_L:
                ui->buttonL->setStyleSheet("background-image: url(:/images/images/pressed.png);");
                break;
            case Qt::Key_M:
                ui->buttonM->setStyleSheet("background-image: url(:/images/images/pressed.png);");
                break;
            case Qt::Key_N:
                ui->buttonN->setStyleSheet("background-image: url(:/images/images/pressed.png);");
                break;
            case Qt::Key_O:
                ui->buttonO->setStyleSheet("background-image: url(:/images/images/pressed.png);");
                break;
            case Qt::Key_P:
                ui->buttonP->setStyleSheet("background-image: url(:/images/images/pressed.png);");
                break;
            case Qt::Key_Q:
                ui->buttonQ->setStyleSheet("background-image: url(:/images/images/pressed.png);");
                break;
            case Qt::Key_R:
                ui->buttonR->setStyleSheet("background-image: url(:/images/images/pressed.png);");
                break;
            case Qt::Key_S:
                ui->buttonS->setStyleSheet("background-image: url(:/images/images/pressed.png);");
                break;
            case Qt::Key_T:
                ui->buttonT->setStyleSheet("background-image: url(:/images/images/pressed.png);");
                break;
            case Qt::Key_U:
                ui->buttonU->setStyleSheet("background-image: url(:/images/images/pressed.png);");
                break;
            case Qt::Key_V:
                ui->buttonV->setStyleSheet("background-image: url(:/images/images/pressed.png);");
                break;
            case Qt::Key_W:
                ui->buttonW->setStyleSheet("background-image: url(:/images/images/pressed.png);");
                break;
            case Qt::Key_X:
                ui->buttonX->setStyleSheet("background-image: url(:/images/images/pressed.png);");
                break;
            case Qt::Key_Y:
                ui->buttonY->setStyleSheet("background-image: url(:/images/images/pressed.png);");
                break;
            case Qt::Key_Z:
                ui->buttonZ->setStyleSheet("background-image: url(:/images/images/pressed.png);");
                break;
            default:
                isAlpha = false;
        }
        if(isAlpha)
        {
            if(lampState)
            {
                lampState = false;
                lampGlow();
            }
            encrypted = enigmaIt(toupper(char(keyPressed->key())));
            lampState = true;
            lampGlow();
            QString tempLabel = ui->labelDecrypt->text();
            tempLabel += keyPressed->text().toUpper() + ' ';
            if(tempLabel.size() > 24) tempLabel.remove(0,2);
            ui->labelDecrypt->setText(tempLabel);

            tempLabel = ui->labelEncrypt->text();
            tempLabel += encrypted + ' ';
            if(tempLabel.size() > 24) tempLabel.remove(0,2);
            ui->labelEncrypt->setText(tempLabel);
            qDebug() << encrypted<<lampState;
        }
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *keyReleased)
{
    if (!keyReleased->isAutoRepeat() and !plugBoardConfig)
    {
        switch(keyReleased->key())
        {
            case Qt::Key_A:
                ui->buttonA->setStyleSheet("background-image: url(:/images/images/released.png);\ncolor: rgb(255, 255, 255);");
                break;
            case Qt::Key_B:
                ui->buttonB->setStyleSheet("background-image: url(:/images/images/released.png);\ncolor: rgb(255, 255, 255);");
                break;
            case Qt::Key_C:
                ui->buttonC->setStyleSheet("background-image: url(:/images/images/released.png);\ncolor: rgb(255, 255, 255);");
                break;
            case Qt::Key_D:
                ui->buttonD->setStyleSheet("background-image: url(:/images/images/released.png);\ncolor: rgb(255, 255, 255);");
                break;
            case Qt::Key_E:
                ui->buttonE->setStyleSheet("background-image: url(:/images/images/released.png);\ncolor: rgb(255, 255, 255);");
                break;
            case Qt::Key_F:
                ui->buttonF->setStyleSheet("background-image: url(:/images/images/released.png);\ncolor: rgb(255, 255, 255);");
                break;
            case Qt::Key_G:
                ui->buttonG->setStyleSheet("background-image: url(:/images/images/released.png);\ncolor: rgb(255, 255, 255);");
                break;
            case Qt::Key_H:
                ui->buttonH->setStyleSheet("background-image: url(:/images/images/released.png);\ncolor: rgb(255, 255, 255);");
                break;
            case Qt::Key_I:
                ui->buttonI->setStyleSheet("background-image: url(:/images/images/released.png);\ncolor: rgb(255, 255, 255);");
                break;
            case Qt::Key_J:
                ui->buttonJ->setStyleSheet("background-image: url(:/images/images/released.png);\ncolor: rgb(255, 255, 255);");
                break;
            case Qt::Key_K:
                ui->buttonK->setStyleSheet("background-image: url(:/images/images/released.png);\ncolor: rgb(255, 255, 255);");
                break;
            case Qt::Key_L:
                ui->buttonL->setStyleSheet("background-image: url(:/images/images/released.png);\ncolor: rgb(255, 255, 255);");
                break;
            case Qt::Key_M:
                ui->buttonM->setStyleSheet("background-image: url(:/images/images/released.png);\ncolor: rgb(255, 255, 255);");
                break;
            case Qt::Key_N:
                ui->buttonN->setStyleSheet("background-image: url(:/images/images/released.png);\ncolor: rgb(255, 255, 255);");
                break;
            case Qt::Key_O:
                ui->buttonO->setStyleSheet("background-image: url(:/images/images/released.png);\ncolor: rgb(255, 255, 255);");
                break;
            case Qt::Key_P:
                ui->buttonP->setStyleSheet("background-image: url(:/images/images/released.png);\ncolor: rgb(255, 255, 255);");
                break;
            case Qt::Key_Q:
                ui->buttonQ->setStyleSheet("background-image: url(:/images/images/released.png);\ncolor: rgb(255, 255, 255);");
                break;
            case Qt::Key_R:
                ui->buttonR->setStyleSheet("background-image: url(:/images/images/released.png);\ncolor: rgb(255, 255, 255);");
                break;
            case Qt::Key_S:
                ui->buttonS->setStyleSheet("background-image: url(:/images/images/released.png);\ncolor: rgb(255, 255, 255);");
                break;
            case Qt::Key_T:
                ui->buttonT->setStyleSheet("background-image: url(:/images/images/released.png);\ncolor: rgb(255, 255, 255);");
                break;
            case Qt::Key_U:
                ui->buttonU->setStyleSheet("background-image: url(:/images/images/released.png);\ncolor: rgb(255, 255, 255);");
                break;
            case Qt::Key_V:
                ui->buttonV->setStyleSheet("background-image: url(:/images/images/released.png);\ncolor: rgb(255, 255, 255);");
                break;
            case Qt::Key_W:
                ui->buttonW->setStyleSheet("background-image: url(:/images/images/released.png);\ncolor: rgb(255, 255, 255);");
                break;
            case Qt::Key_X:
                ui->buttonX->setStyleSheet("background-image: url(:/images/images/released.png);\ncolor: rgb(255, 255, 255);");
                break;
            case Qt::Key_Y:
                ui->buttonY->setStyleSheet("background-image: url(:/images/images/released.png);\ncolor: rgb(255, 255, 255);");
                break;
            case Qt::Key_Z:
                ui->buttonZ->setStyleSheet("background-image: url(:/images/images/released.png);\ncolor: rgb(255, 255, 255);");
                break;
        }
    }
}

void MainWindow::lampGlow()
{
    QString styleGlow;
    if(lampState) styleGlow = "color: rgb(250, 170, 55);";
    else styleGlow = "color: rgb(136, 136, 136);";

    switch(encrypted.toLatin1())
    {
        case 'A':
        ui->lampA->setStyleSheet(styleGlow);
        break;
        case 'B':
        ui->lampB->setStyleSheet(styleGlow);
        break;
        case 'C':
        ui->lampC->setStyleSheet(styleGlow);
        break;
        case 'D':
        ui->lampD->setStyleSheet(styleGlow);
        break;
        case 'E':
        ui->lampE->setStyleSheet(styleGlow);
        break;
        case 'F':
        ui->lampF->setStyleSheet(styleGlow);
        break;
        case 'G':
        ui->lampG->setStyleSheet(styleGlow);
        break;
        case 'H':
        ui->lampH->setStyleSheet(styleGlow);
        break;
        case 'I':
        ui->lampI->setStyleSheet(styleGlow);
        break;
        case 'J':
        ui->lampJ->setStyleSheet(styleGlow);
        break;
        case 'K':
        ui->lampK->setStyleSheet(styleGlow);
        break;
        case 'L':
        ui->lampL->setStyleSheet(styleGlow);
        break;
        case 'M':
        ui->lampM->setStyleSheet(styleGlow);
        break;
        case 'N':
        ui->lampN->setStyleSheet(styleGlow);
        break;
        case 'O':
        ui->lampO->setStyleSheet(styleGlow);
        break;
        case 'P':
        ui->lampP->setStyleSheet(styleGlow);
        break;
        case 'Q':
        ui->lampQ->setStyleSheet(styleGlow);
        break;
        case 'R':
        ui->lampR->setStyleSheet(styleGlow);
        break;
        case 'S':
        ui->lampS->setStyleSheet(styleGlow);
        break;
        case 'T':
        ui->lampT->setStyleSheet(styleGlow);
        break;
        case 'U':
        ui->lampU->setStyleSheet(styleGlow);
        break;
        case 'V':
        ui->lampV->setStyleSheet(styleGlow);
        break;
        case 'W':
        ui->lampW->setStyleSheet(styleGlow);
        break;
        case 'X':
        ui->lampX->setStyleSheet(styleGlow);
        break;
        case 'Y':
        ui->lampY->setStyleSheet(styleGlow);
        break;
        case 'Z':
        ui->lampZ->setStyleSheet(styleGlow);
        break;
    }

}


void MainWindow::on_radioButton_clicked(bool checked)
{
    ui->plugBoard->setVisible(checked);
    plugBoardConfig = checked;
}


void MainWindow::on_plugW_clicked(bool checked)
{
    if(checked)
    {
        return;

    }
}

