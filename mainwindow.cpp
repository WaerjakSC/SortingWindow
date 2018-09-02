#include "mainwindow.h"
#include <QDebug>
#include <sstream>
#include <string>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  editor = new QLineEdit();
  editor->setPlaceholderText("Enter the value or text you want to sort");
  sortButton = new QPushButton("Sort");
  closeButton = new QPushButton("Close");

  QHBoxLayout *m_hBoxLayout = new QHBoxLayout();
  m_hBoxLayout->addWidget(sortButton);
  m_hBoxLayout->addWidget(closeButton);

  QVBoxLayout *mainLayout = new QVBoxLayout;
  sortedText = new QPlainTextEdit();
  sortedText->setReadOnly(true);
  mainLayout->addWidget(editor);
  mainLayout->addWidget(sortedText);
  mainLayout->addLayout(m_hBoxLayout);

  QWidget *mainWidget = new QWidget();
  mainWidget->setLayout(mainLayout);
  setCentralWidget(mainWidget);

  setWindowTitle(tr("Sorting GUI"));
  connect(sortButton, SIGNAL(clicked()), this, SLOT(sort()));
  connect(editor, SIGNAL(editingFinished()), this, SLOT(sort()));
  connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
}

MainWindow::~MainWindow() {}

void MainWindow::str2vec() {
  v.clear();
  std::stringstream ss(s);
  float temp;

  while (ss >> temp)
    v.push_back(temp);
}

void MainWindow::vec2str() {
  std::stringstream ss;
  s.clear();
  for (auto it = v.begin(); it != v.end(); it++) {
    ss << *it;
    s.append(ss.str());
  }
}
void MainWindow::close() { QMainWindow::close(); }

void MainWindow::sort() {
  QString qs = editor->text();
  s = qs.toStdString();
  str2vec();
  // insert sorting function here
  vec2str();
  qs.fromStdString(s);
  sortedText->appendPlainText(qs);
}
