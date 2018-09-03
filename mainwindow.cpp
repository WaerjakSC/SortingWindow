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

void MainWindow::str2vec(const QStringList list) {
  // Read through s to find valid numbers. Every time a \n is found, create a
  // new vector3d object -- currently I only do this for vector3d which kinda
  // defeats the point of the template sorting function, but to be fair that
  // function can be used elsewhere and I guess I could always just add a bunch
  // of if statements to find out what type it is, in case it's just one int per
  // line or one float per line or whatever
  for (auto i = 0; i < list.size(); i++) {
    std::stringstream ss(list.at(i).toStdString());
    float tempNum;
    while (ss >> tempNum) {
      v_float.push_back(tempNum);
    }
    switch (v_float.size()) {
    case 1:
      container.push_back(vector3d(v_float[0], 0, 0));
      v_float.clear();
      break;
    case 2:
      container.push_back(vector3d(v_float[0], v_float[1], 0));
      v_float.clear();
      break;
    case 3:
      container.push_back(vector3d(v_float[0], v_float[1], v_float[2]));
      v_float.clear();
      break;
    default:
      break; // Throw an error message here
    }
  }
}

QStringList MainWindow::vec2str() {
  std::stringstream ss;
  QStringList list;
  QString qs;
  for (size_t it = 0; it < container.size(); it++) {
    ss << container[it];
    qs = QString::fromStdString(ss.str());
    list.append(qs);
    // Empty ss for next loop
    ss.clear();
    ss.str(std::string());
  }
  return list;
}
void MainWindow::close() { QMainWindow::close(); }

QStringList MainWindow::splitByLines(const QTextDocument *doc) {
  if (!doc)
    return QStringList();
  QStringList ret;
  QTextBlock tb = doc->begin();
  while (tb.isValid()) {
    QString blockText = tb.text();
    Q_ASSERT(tb.layout());
    if (!tb.layout())
      continue;
    for (int i = 0; i != tb.layout()->lineCount(); ++i) {
      QTextLine line = tb.layout()->lineAt(i);
      ret.append(blockText.mid(line.textStart(), line.textLength()));
    }
    tb = tb.next();
  }
  return ret;
}
void MainWindow::sort() {
  container.clear();
  QStringList qsList = splitByLines(editor->document());
  str2vec(qsList);
  sortingFunction(container);
  qsList = vec2str();
  while (!qsList.empty()) {
    sortedText->appendPlainText(qsList.first());
    qsList.erase(qsList.begin());
  }
}
