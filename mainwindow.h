#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

QT_BEGIN_NAMESPACE
class QPushButton;
class QPlainTextEdit;
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  template <typename T> std::vector<T> sortingFunction() {}
public slots:
  void sort();
  void close();

private:
  void str2vec();
  void vec2str();
  QLineEdit *editor;
  QPlainTextEdit *sortedText;
  QPushButton *sortButton;
  QPushButton *closeButton;
  std::string s;
  std::vector<float> v;
};

#endif // MAINWINDOW_H
