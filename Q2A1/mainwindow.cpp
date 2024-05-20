#include "mainwindow.h"
#include "reviewdata.h"
#include <QVBoxLayout>
#include <QDateTime>
#include <QLabel>
#include <QDebug>
#include <QMessageBox>
#include <QVariant>
#include <QMetaObject>
#include <QMetaProperty>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout *layout = new QVBoxLayout;
    centralWidget->setLayout(layout);
    // Title
    QLabel *titleLabel = new QLabel("Fill in the data and click Add", this);
    layout->addWidget(titleLabel);
    // Name input box
    QHBoxLayout *nameLayout = new QHBoxLayout;
    QLabel *nameLabel = new QLabel("Name:", this);
    nameLineEdit = new QLineEdit(this);
    nameLayout->addWidget(nameLabel);
    nameLayout->addWidget(nameLineEdit);
    layout->addLayout(nameLayout);
    // Date input box
    QHBoxLayout *dateLayout = new QHBoxLayout;
    QLabel *dateLabel = new QLabel("Date:", this);
    dateEdit = new QDateTimeEdit(QDateTime::currentDateTime(), this);
    dateLayout->addWidget(dateLabel);

    dateLayout->addWidget(dateEdit);
    layout->addLayout(dateLayout);
    // Recommended checkbox
    recommendedCheckBox = new QCheckBox("Recommend", this);
    layout->addWidget(recommendedCheckBox);
    // Add review button
    QPushButton *addButton = new QPushButton("Add", this);
    connect(addButton, &QPushButton::clicked, this, &MainWindow::addReview);
    layout->addWidget(addButton);
    QPushButton *displayButton = new QPushButton("Display (Reflection)", this);
    connect(displayButton, &QPushButton::clicked, this, &MainWindow::printReviews);
    layout->addWidget(displayButton);

    // Buttons layout
    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(addButton);
    buttonsLayout->addWidget(displayButton);
    layout->addLayout(buttonsLayout);
}
void MainWindow::addReview() {
    QString softwareName = nameLineEdit->text();
    QDateTime reviewDate = dateEdit->dateTime();
    bool recommended = recommendedCheckBox->isChecked();

    ReviewData *review = new ReviewData(softwareName, reviewDate, recommended, this);
    reviews.append(review);
    QMessageBox::information(nullptr, "Sucessfull", "Software review successfully Added.");
}
void MainWindow::printReviews() {
    for (ReviewData *review : reviews)
    {
        qDebug() <<Qt::endl<<"******************************";
        const QMetaObject *metaobject = review->metaObject();
        int count = metaobject->propertyCount();
        for (int i=0; i<count; ++i) {
            QMetaProperty metaproperty = metaobject->property(i);
            const char *name = metaproperty.name();
            QVariant value = review->property(name);
            qDebug() << QString("%1: %2").arg(name, value.toString());
        }
    }
}
