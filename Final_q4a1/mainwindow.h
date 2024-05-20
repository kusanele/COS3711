#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Constructor
    MainWindow(QWidget *parent = nullptr);

private slots:
    // Slot to load file
    void loadFile();

    // Slot to process text
    void processText();

private:
    // Text edit widget
    QTextEdit *textEdit;
};

#endif // MAINWINDOW_H
