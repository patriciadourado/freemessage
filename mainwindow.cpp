#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "OtherWords.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    ui->setupUi(this);
    const QString filepath = "C:/Users/freemessage/";

    setWindowIcon(QIcon(filepath + "favicon.ico"));

    ui->ConvertButton->setEnabled(false);

    connect(ui->Box1,
            SIGNAL(textChanged()),
            this,
            SLOT(EnableConvert()));

    connect(ui->ClearButton,
            SIGNAL(clicked()),
            this,
            SLOT(ClearBoxes()));

    connect(ui->ConvertButton,
            SIGNAL(clicked()),
            this,
            SLOT(ConvertMessage()));

    connect(ui->EnterKeys,
            SIGNAL(clicked()),
            this,
            SLOT(ShowMessage()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::EnableConvert(){
    if(ui->Box1->toPlainText().size() > 0){
        ui->ConvertButton->setEnabled(true);
    }
    else{
        ui->ConvertButton->setEnabled(false);
    }
}

void MainWindow::ConvertMessage(){
    OtherWords ow;

    if(ValidateKeys(ui->key1->text(),ui->key2->text())){
        ow.SetMessage(ui->Box1->toPlainText());
        ow.ConvertMessage(ui->key1->text(),ui->key2->text());
        ui->Box2->setPlainText(ow.GetMessage());
        ui->errorMessage->clear();
    }
    else{
        ui->errorMessage->setStyleSheet("color: #ff557f");
        ui->errorMessage->setText("Invalid Format of Keys!");
    }

}

void MainWindow::ShowMessage(){
    if(ValidateKeys(ui->key1->text(), ui->key2->text())){
        ui->errorMessage->setStyleSheet("color: #5555ff");
        ui->errorMessage->setText("You have valid keys!");
    }
    else{
        ui->errorMessage->setStyleSheet("color: #ff557f");
        ui->errorMessage->setText("Invalid Format of Keys!");
    }
}

void MainWindow::ClearBoxes(){
    ui->Box1->clear();
    ui->Box2->clear();
}

bool MainWindow::CheckRepeated(
    QString Key
){
    ui->errorMessage->setText(Key);

    for(int i = 1; i < Key.size(); i++){
        for(int j = 1; j < Key.size(); j++){
            if((i != j) && (Key[i] == Key[j])){
                return true;
            }
        }
    }
    return false;
}

bool MainWindow::CheckEqual(
    QString Key1,
    QString Key2
){
    int i, j;
    for(i = 0; i < Key1.size(); i++){
        for(j = 0; j < Key2.size(); j++){
            if(Key1[i] == Key2[j])//equal keys
                return true;
        }
    }
    return false;
}

bool MainWindow::ValidateKeys(
    QString Key1,
    QString Key2
){
    if(Key1 == Key2){
        return false;
    }
    else{
        if(Key1.size() == Key2.size()){
            if(CheckEqual(Key1, Key2)){
                return false;
            }
            else if(CheckRepeated(Key1) || CheckRepeated(Key2)){//equal char in same key
                return false;
            }
            else if(Key1.size() < 5){//if size of key
                return false;
            }
            return true;//first validation
        }
        else
            return false;
    }
}
