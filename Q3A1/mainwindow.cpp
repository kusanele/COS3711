#include "mainwindow.h"
#include "ratings.h"
#include <QPushButton>
#include <QHeaderView>
#include <QGridLayout>
#include <QPainter>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(800, 300);
    setWindowTitle("CD Information");
    // Create a grid layout
    QGridLayout *layout = new QGridLayout;

    // Add labels
    layout->addWidget(new QLabel("Composer"), 0, 0);
    layout->addWidget(new QLabel("Album Title"), 0, 1);
    layout->addWidget(new QLabel("Replacement Cost (R)"), 0, 2);
    layout->addWidget(new QLabel("Rating"), 0, 3);
    // Add line edits
    composerLineEdit = new QLineEdit(this);
    layout->addWidget(composerLineEdit, 1, 0);

    albumTitleLineEdit = new QLineEdit(this);
    layout->addWidget(albumTitleLineEdit, 1, 1);
    // Replacement Cost input
    replacementCostSpinBox = new QDoubleSpinBox(this);
    replacementCostSpinBox->setValue(0.00);
    replacementCostSpinBox->setDecimals(2);
    replacementCostSpinBox->setMaximum(999999.99);
    layout->addWidget(replacementCostSpinBox, 1, 2);
    // Rating input
    ratingSpinBox = new QSpinBox(this);
    ratingSpinBox->setValue(0);
    ratingSpinBox->setMaximum(100);
    ratingSpinBox->setMinimumWidth(100);
    layout->addWidget(ratingSpinBox, 1, 3);

    // Add record button
    QPushButton *addButton = new QPushButton("Add", this);
    connect(addButton, &QPushButton::clicked, this, &MainWindow::addRecord);
    layout->addWidget(addButton, 1, 4);
    // Set the layout to the central widget
    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    model.setHorizontalHeaderLabels({"Composer", "Album Name", "Replacement Value", "Rating"});
    tableView.setModel(&model);
    tableView.setItemDelegateForColumn(3, new RatingDelegate(&tableView));
    tableView.horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    layout->addWidget(&tableView, 2,0,1,5);// Span the table across all columns
    QPushButton *deleteButton = new QPushButton("Delete", this);
    connect(deleteButton, &QPushButton::clicked, this, &MainWindow::deleteRecord);
    layout->addWidget(deleteButton, 3,0,1,5,Qt::AlignRight);
}
MainWindow::~MainWindow() {}
void MainWindow::addRecord()
{
    QString composer = composerLineEdit->text();
    QString albumTitle = albumTitleLineEdit->text();
    double replacementCost = replacementCostSpinBox->value();
    int rating = ratingSpinBox->value();
    QList<QStandardItem *> rowItems;
    rowItems.append(new QStandardItem(composer));
    rowItems.append(new QStandardItem(albumTitle));

    rowItems.append(new QStandardItem(QString::number(replacementCost)));
    rowItems.append(new QStandardItem(QString::number(rating)));
    model.appendRow(rowItems);
    // Clear input fields after adding record
    composerLineEdit->clear();
    albumTitleLineEdit->clear();
    replacementCostSpinBox->clear();
    ratingSpinBox->clear();
}
void MainWindow::deleteRecord()
{
    QModelIndexList selectedIndexes = tableView.selectionModel()->selectedIndexes();
    if (!selectedIndexes.isEmpty()) {
        foreach (QModelIndex index, selectedIndexes) {
            model.removeRow(index.row());
        }
    }
}
