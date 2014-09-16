#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : ui(new Ui::MainWindow)
{
    infile=fopen("succes!.txt","w");                         //succes라는 파일 열기, w는 읽기파일
    this->mainlayout = new QGridLayout;
    this->testlabel = new QLabel;
    this->testlabel2 = new QLabel;
    this->line = new QLineEdit;
    this->line2 = new QLineEdit;
    this->push1 = new QPushButton;
    this->push2 = new QPushButton;
    this->push3 = new QPushButton;
    this->push4 = new QPushButton;
    this->view= new QTableView;
    this->model = new QStandardItemModel(0,0,this);


    model->setHorizontalHeaderItem(0, new QStandardItem(QString("이름")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("전화번호")));

    view->setModel(model);                                  //모델에 저장된 것을 보여줌
    view->show();                                           //show함수는 main.cpp에 있음



    testlabel->setText("이름");
    testlabel2->setText("전화번호");
    push1->setText("입력");
    push2->setText("한줄 삭제");
    push3->setText("모두 삭제");
    push4->setText("저장");

    mainlayout->addWidget(testlabel,0,0);
    mainlayout->addWidget(testlabel2,0,1);
    mainlayout->addWidget(line,1,0);
    mainlayout->addWidget(line2,1,1);
    mainlayout->addWidget(push1,1,2);
    mainlayout->addWidget(push2,2,2);
    mainlayout->addWidget(push3,2,3);
    mainlayout->addWidget(push4,1,3);

    connect(push1,SIGNAL(clicked()),this,SLOT(click()));    //입력하였을때 함수호출??
    connect(push2,SIGNAL(clicked()),this,SLOT(click2()));
    connect(push3,SIGNAL(clicked()),this,SLOT(click3()));
    connect(push4,SIGNAL(clicked()),this,SLOT(click4()));

    this->setLayout(mainlayout);                            //마지막에 적는것?

}

void MainWindow::click()                                    //클래스 함수 호출
{

    QStandardItem *firstRow = new QStandardItem(line->text());
    model->setItem(n,0,firstRow);
    QStandardItem *secondRow = new QStandardItem(line2->text());
    model->setItem(n,1,secondRow);

    ++n;
}

void MainWindow::click2()                                    //클래스 함수 호출
{
    --n;

    QStandardItem *firstRow = new QStandardItem(QString(" "));
    model->setItem(n,0,firstRow);
    QStandardItem *secondRow = new QStandardItem(QString(" "));
    model->setItem(n,1,secondRow);

}

void MainWindow::click3()                                    //클래스 함수 호출
{

    for(m=0; m<n; m++){
    QStandardItem *firstRow = new QStandardItem(QString(" "));
    model->setItem(m,0,firstRow);
    QStandardItem *secondRow = new QStandardItem(QString(" "));
    model->setItem(m,1,secondRow);
    }

    n=0;

}

void MainWindow::click4()                                    //텍스트 파일에 저장
{
    for(k=0; k<n; k++){
        fprintf(infile,"%s %s \n",
                model->item(k,0)->text().toUtf8().constData(),model->item(k,1)->text().toUtf8().constData());
    }
        fclose(infile);
}



MainWindow::~MainWindow()
{
    delete mainlayout;
    delete testlabel;
    delete line;
    delete line2;
    delete push1;
    delete push2;
    delete ui;


}

