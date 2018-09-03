#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "vector3d.h"
#include <QMainWindow>
#include <QtWidgets>

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  template <typename T> void sortingFunction(std::vector<T> &tempVector) {
    // Function to create a vector3d class for each separate line Put
    // all of them into a vector and sort that vector return the vector to
    // sort() function which just prints each object To sort in ascending order
    // the largest object needs to be printed first, aka in slot 0 of the
    // returned vector
    size_t i, j;
    int flag = 1;  // set flag to 1 to start first pass
    vector3d temp; // holding variable
    auto numLength = tempVector.size();
    for (i = 1; (i <= numLength) && flag; i++) {
      flag = 0;
      for (j = 0; j < (numLength - 1); j++) {
        if (tempVector[j + 1] >
            tempVector[j]) // ascending order simply changes to <
        {
          temp = tempVector[j]; // swap elements
          tempVector[j] = tempVector[j + 1];
          tempVector[j + 1] = temp;
          flag = 1; // indicates that a swap occurred.
        }
      }
    }
  }
  QStringList splitByLines(const QTextDocument *doc);
public slots:
  void sort();
  void close();

private:
  void str2vec(const QStringList list);
  QStringList vec2str();
  QPlainTextEdit *editor;
  QPlainTextEdit *sortedText;
  QPushButton *sortButton;
  QPushButton *closeButton;
  std::vector<float> v_float;
  std::vector<vector3d> container;
};

#endif // MAINWINDOW_H
