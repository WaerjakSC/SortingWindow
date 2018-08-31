#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QPushButton;
class QPlainTextEdit;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void sort();
    void close();

private:
    void str2vec();
    void vec2str();
    QPlainTextEdit *editor;
    QPushButton* sortButton;
    QPushButton* button2;
    std::string s;
    std::vector<float> v;
};

#endif // MAINWINDOW_H
