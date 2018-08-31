#include "mainwindow.h"
#include <QtWidgets>
#include <QDebug>
#include <sstream>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    editor = new QPlainTextEdit();

    QString tekst("1 2 3 4");
    editor->setPlainText(tekst);

    sortButton = new QPushButton("sort");
    button2 = new QPushButton("");

    QHBoxLayout* m_hBoxLayout = new QHBoxLayout();
    m_hBoxLayout->addWidget(sortButton);
    m_hBoxLayout->addWidget(button2);

    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->addWidget(editor);
    mainLayout->addLayout(m_hBoxLayout);

    QWidget* mainWidget = new QWidget();
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);

    setWindowTitle(tr("qt gui for Algoritmer og datastrukturer"));
    statusBar()->showMessage("generisk plattform");
    connect(sortButton, SIGNAL(clicked()), this, SLOT(sort()));

}

MainWindow::~MainWindow()
{

}

void MainWindow::str2vec()
{
    v.clear();
    std::stringstream ss(s);
    float temp;

    while(ss>>temp)
        v.push_back(temp);
}

void MainWindow::vec2str()
{
    std::stringstream ss;
    s.clear();
    for (auto it=v.begin(); it!=v.end(); it++) {
        ss << *it;
        s.append(ss.str());
    }
}
void MainWindow::close()
{
    QMainWindow::close();
}

void MainWindow::sort()
{
    statusBar()->showMessage("sort clicked, " + editor->toPlainText());
    QString qs = editor->toPlainText();
    s = qs.toStdString();
    str2vec();
    vec2str();
    qDebug() << "clicked";
    qs.fromStdString(s);
    editor->clear();
    editor->appendPlainText(qs);
}
