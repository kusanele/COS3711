#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLineEdit>
#include <QDateTimeEdit>
#include <QCheckBox>
#include <QListWidget>
#include <QPushButton>
#include "ReviewData.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void addReview();
    void printReviews();
private:
    QListWidget *listWidget;
    QPushButton *addButton;
    QPushButton *printButton;
    QLineEdit *nameLineEdit;
    QDateTimeEdit *dateEdit;
    QCheckBox *recommendedCheckBox;
    QList<ReviewData*> reviews;
};
#endif // MAINWINDOW_H
