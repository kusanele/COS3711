#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QWidget>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QTableView>
class MainWindow : public QMainWindow
{
    Q_OBJECT
    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index);
    private slots:
        void addRecord();
        void deleteRecord();
    private:
        QListWidget *listWidget;
        QLineEdit *composerLineEdit;
        QLineEdit *albumTitleLineEdit;
        QDoubleSpinBox *replacementCostSpinBox;
        QSpinBox *ratingSpinBox;
        QStandardItemModel model;
        QTableView tableView;
};
#endif // MAINWINDOW_H
