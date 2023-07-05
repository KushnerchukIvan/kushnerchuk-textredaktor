#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
class QAction;
class QListWidget;
class QMenu;
class QTextEdit;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();
private slots:
    void newLetter();
    //void save();
    //void about();
    //void undo();
private:
    //Ui::MainWindow *ui;
    QTextEdit *textEdit;
    QMenu *viewMenu;
    void createActions();
    void createStatusBar();
};
#endif // MAINWINDOW_H
