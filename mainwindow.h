#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "vector3d.h"
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
  template <typename T> void sortingFunction(std::vector<T> &tempVector) {
    // I need to already have the vector of vector3d before I enter this
    // function Function to create a vector3d class for each separate line Put
    // all of them into a vector and sort that vector return the vector to
    // sort() function which just prints each object To sort in ascending order
    // the largest object needs to be printed first, aka in slot 0 of the
    // returned vector
  }
public slots:
  void sort();
  void close();

private:
  void str2vec();
  void vec2str();
  QPlainTextEdit *editor;
  QPlainTextEdit *sortedText;
  QPushButton *sortButton;
  QPushButton *closeButton;
  std::string s;
  std::vector<float> v_float;
  std::vector<vector3d<float>> container;
};

#endif // MAINWINDOW_H
