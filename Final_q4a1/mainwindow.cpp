#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QIODevice>
#include <QTextDocument>
#include <QRegularExpression>
#include <QTextCursor>
#include <QTextCharFormat>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Set window size and title
    setFixedSize(800, 400);
    setWindowTitle("Search");

    // Central widget and layout
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Button layout
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QPushButton *loadButton = new QPushButton("Load", this);
    connect(loadButton, &QPushButton::clicked, this, &MainWindow::loadFile);
    buttonLayout->addWidget(loadButton);
    QPushButton *processButton = new QPushButton("Process", this);
    connect(processButton, &QPushButton::clicked, this, &MainWindow::processText);
    buttonLayout->addWidget(processButton);
    layout->addLayout(buttonLayout);

    // Text edit widget
    textEdit = new QTextEdit(this);
    layout->addWidget(textEdit);
}

void MainWindow::loadFile() {
    // Open file dialog to choose a file
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files(*.txt)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString content = in.readAll();
            file.close();

            // Set file content to the text edit widget
            QTextDocument *document = textEdit->document();
            document->setPlainText(content);
        }
    }
}

void MainWindow::processText() {
    // Get text content from the text edit widget
    QTextDocument *document = textEdit->document();

    // Regular expressions for phone numbers and emails
    QRegularExpression phonePattern("\\b\\d{3}[-\\s.]?\\d{3}[-\\s.]?\\d{4}\\b|\\(\\d{3}\\)\\s?\\d{3}[-\\s.]?\\d{4}\\b");
    QRegularExpression emailPattern("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}\\b");

    QTextCursor cursor(document);
    QTextCharFormat format;

    // Apply formatting to phone numbers and emails
    format.setFontWeight(QFont::Bold);
    cursor.beginEditBlock();

    while (!cursor.atEnd()) {
        cursor = document->find(phonePattern, cursor);
        if (cursor.isNull())
            break;
        cursor.mergeCharFormat(format);
    }

    cursor.setPosition(0);
    while (!cursor.atEnd()) {
        cursor = document->find(emailPattern, cursor);
        if (cursor.isNull())
            break;
        cursor.mergeCharFormat(format);
    }

    cursor.endEditBlock();

    // Refresh the GUI
    textEdit->setDocument(document);
}
