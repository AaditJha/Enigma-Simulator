#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QChar encrypted;
    bool lampState = false;
    bool plugBoardConfig = false;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


protected:
    char enigmaIt(char decrypted);
    void keyPressEvent(QKeyEvent *keyPressed);
    void keyReleaseEvent(QKeyEvent *keyReleased);
    void lampGlow();
private slots:
    void on_radioButton_clicked(bool checked);

    void on_plugW_clicked(bool checked);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
