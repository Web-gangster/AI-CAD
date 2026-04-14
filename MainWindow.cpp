#include "MainWindow.h"
#include <QPushButton>
#include <QMessageBox>
#include <QSplitter>
#include <QVBoxLayout>
#include <QLabel>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenu *fileMenu = menuBar()->addMenu(tr("File"));
    QAction *newAction = new QAction(tr("New"), this);
    QAction *openAction = new QAction(tr("Open"), this);
    QAction *exitAction = new QAction(tr("Exit"), this);
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);
    connect(exitAction, &QAction::triggered, this, &MainWindow::close);
    newAction->setShortcut(QKeySequence::New);
    openAction->setShortcut(QKeySequence::Open);
    exitAction->setShortcut(QKeySequence("Ctrl+Q"));

    QToolBar *toolBar = addToolBar(tr("Main Toolbar"));
    toolBar->addAction(newAction);
    toolBar->addAction(openAction);
    toolBar->addSeparator();
    toolBar->addAction(exitAction);
    
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    
    splitter = new QSplitter(Qt::Horizontal, centralWidget);
    

    QWidget *leftPanel = new QWidget(splitter);
    leftPanel->setStyleSheet("background-color: #444;");
    leftPanel->setMinimumWidth(0);

    QVBoxLayout *leftLayout = new QVBoxLayout(leftPanel);
    leftLayout->setContentsMargins(0,0,0,0);
    leftLayout->setSpacing(0);

    QLabel *leftHeader = new QLabel("Object", leftPanel);
    leftHeader->setStyleSheet("background-color: #333; color: white; padding: 5px;");
    leftHeader->setFixedHeight(25);
    leftHeader->setAlignment(Qt::AlignCenter);
    leftHeader->setMinimumWidth(0);
    leftHeader->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);

    leftLayout->addWidget(leftHeader);
    leftLayout->addStretch();

    QLabel *rightPanel = new QLabel(tr("3D Viewport"), splitter);
    rightPanel->setStyleSheet("background-color: #222; color: white;");\
    rightPanel->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    rightPanel->setContentsMargins(0, 10, 0, 0);
    

    mainLayout->addWidget(splitter);
    setCentralWidget(centralWidget);

}
MainWindow::~MainWindow()
{
}
void MainWindow::onButtonClick(){
    QMessageBox::information(this, "Привет", "Кнопка нажалась");
}
void MainWindow::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event);
    QTimer::singleShot(0, this, [this]() {
        splitter->setSizes({splitter->width() / 8, splitter->width() * 7 / 8});
    });
}