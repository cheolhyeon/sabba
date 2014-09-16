#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGridLayout>
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QTableView>           
#include <QMainWindow>
#include <QStandardItemModel>   
#include <string>
#include <stdio.h>
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int n=0;		              	//mainwindow에서 사용할 변수들
    int m=0;
    int k=0;

private:

    Ui::MainWindow *ui;
    QGridLayout * mainlayout;   //위치설정
    QLabel* testlabel;          //라벨
    QLabel* testlabel2;
    QLineEdit * line;           //빈공간
    QLineEdit * line2;
    QPushButton * push1;        //입력
    QPushButton * push2;
    QPushButton * push3;
    QPushButton * push4;
    QTableView * view;          //뷰어
    QStandardItemModel *model;  //뷰어 텍스트 공간
    FILE *infile;               //저장


public slots :                  //입력, 삭제 저장 함수
    void click();

public slots :
    void click2();		

public slots :
    void click3();		

public slots :
    void click4();


};




#endif // MAINWINDOW_H
