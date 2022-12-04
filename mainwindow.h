#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool ValidateKeys(
        QString Key1,
        QString Key2
    );

    bool CompareKeys(
        QString Key1,
        QString Key2
    );

    bool CheckRepeated(
        QString Key
    );

    bool CheckEqual(
        QString Key1,
        QString Key2
    );

private slots:
    void EnableConvert();
    void ConvertMessage();
    void ShowMessage();
    void ClearBoxes();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
