#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QToolBar>
#include<QPushButton>
#include<QStatusBar>
#include<QLabel>
#include<QDockWidget>
#include<QTextEdit>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //重置窗口大小；
    resize(600,400);
    setWindowTitle("菜单栏");
    //菜单栏创建
    QMenuBar * bar=menuBar();
    //将菜单栏放到窗口中；
    setMenuBar(bar);
    //创建菜单
    QMenu * fileMenu=bar->addMenu("文件");
    QMenu * ediMenu=bar->addMenu("编辑");
    //创建菜单项
    QAction * newAction= fileMenu->addAction("新建");
    //添加分隔符
    fileMenu->addSeparator();
    QAction * openAction =fileMenu->addAction("打开");

    //工具栏 可以有多个
    QToolBar * toolbar=new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea,toolbar);

    //后期设置 只允许左右情况
    toolbar->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea);
    //设置浮动
    toolbar->setFloatable(false);
    //设置移动(总开关)
    toolbar->setMovable(false);

    //工具栏可以设置内容,这里用菜单栏的新建和打开，就是共用了一个槽
    toolbar->addAction(newAction);
    toolbar->addSeparator();
    toolbar->addAction(openAction);

    //工具栏中添加控件
    QPushButton * btn=new QPushButton("奥利给",this);
    toolbar->addWidget(btn);

    //创建状态栏 最多一个
    QStatusBar * stbar=new QStatusBar();
    setStatusBar(stbar);
    //放标签控件
    QLabel *label=new QLabel("提示信息",this);
    stbar->addWidget(label);

    QLabel *label2=new QLabel("右侧提示信息",this);
    stbar->addPermanentWidget(label2);

    //铆接部件（浮动窗口）  可以有多个
    QDockWidget * dockWidget=new QDockWidget("浮动",this);
    addDockWidget(Qt::BottomDockWidgetArea,dockWidget);
    //设置后期停靠区域，只让上下
    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);
    //设置中心部件,最多一个
    QTextEdit * edit=new QTextEdit(this);
    setCentralWidget(edit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

