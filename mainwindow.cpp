#include "mainwindow.h"
#include <QDebug>
#include <algorithm>
#include <sstream>
#include <string>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  editor = new QPlainTextEdit();
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
  connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
}

MainWindow::~MainWindow() {}

void MainWindow::str2vec() {
  std::string tempS;
  size_t foundAt{0};
  // Read through s to find valid numbers. Every time a \n is found, create a
  // new vector3d object -- currently I only do this for vector3d which kinda
  // defeats the point of the template sorting function, but to be fair that
  // function can be used elsewhere and I guess I could always just add a bunch
  // of if statements to find out what type it is, in case it's just one int per
  // line or one float per line or whatever
  for (size_t i = 0; i < s.size(); i++) {
    //    size_t lastline = foundAt; // First time will initialize to 0
    //    foundAt = s.find('\n');
    //    tempS = s.substr(lastline, foundAt); // Read the first value into
    //    tempS
    std::stringstream ss(s);
    float tempNum;
    while (ss >> tempNum) {
      v_float.push_back(tempNum);
      // Need an if statement here or something so that it only goes down here
      // if newline is found
      if ((foundAt = ss.str().find('\n', foundAt)) != std::string::npos) //
        switch (v_float.size()) {
        case 1:
          container.push_back(vector3d<float>(v_float[0], 0, 0));
          v_float.clear();
          break;
        case 2:
          container.push_back(vector3d<float>(v_float[0], v_float[1], 0));
          v_float.clear();
          break;
        case 3:
          container.push_back(
              vector3d<float>(v_float[0], v_float[1], v_float[2]));
          v_float.clear();
          break;
        default:
          break; // Throw an error message here
        }
      foundAt++;
    }
  }
}

void MainWindow::vec2str() {
  std::stringstream ss;
  s.clear();
  for (auto it = container.begin(); it != container.end(); it++) {
    ss << *it;
    ss << '\n';
    s.append(ss.str());
  }
}
void MainWindow::close() { QMainWindow::close(); }

void MainWindow::sort() {
  container.clear();
  QString qs = editor->toPlainText();
  s = qs.toStdString();
  //  sortingFunction(container);
  str2vec();
  vec2str();
  qs.fromStdString(s);
  sortedText->appendPlainText(qs);
}
