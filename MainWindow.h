#pragma once
#include <QMainWindow>
#include <QSplitter>
#include <QShowEvent>

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void showEvent(QShowEvent *event) override;
private:
    QSplitter *splitter;
private slots:
    void onButtonClick();

};
