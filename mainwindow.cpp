#include <QWidget>
#include <QTextEdit>
#include <QToolBar>
#include <QTextFrameFormat>
#include <QTextFrame>
#include <QDate>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow()
{
    textEdit = new QTextEdit;
    //ui->setupUi(this);
    setCentralWidget(textEdit);
    setWindowTitle(tr("Редактор"));
    //void createActions();
    //void createStatusBar();
    createActions();
    newLetter();
}

MainWindow::~MainWindow()
{
    //delete ui;
}

void MainWindow::newLetter()
{
    textEdit->clear();
    QTextCursor cursor(textEdit->textCursor());
    cursor.movePosition(QTextCursor::Start);
    QTextFrame *topFrame = cursor.currentFrame();
    QTextFrameFormat topFrameFormat = topFrame->frameFormat();
    topFrameFormat.setPadding(16);
    topFrame->setFrameFormat(topFrameFormat);

    QTextCharFormat textFormat;
    QTextCharFormat boldFormat;
    boldFormat.setFontWeight(QFont::Bold);
    QTextCharFormat italicFormat;
    italicFormat.setFontItalic(true);

    QTextTableFormat tableFormat;
    tableFormat.setBorder(1);
    tableFormat.setCellPadding(16);
    tableFormat.setAlignment(Qt::AlignRight);
    cursor.insertTable(1, 1, tableFormat);
    cursor.insertText("Школа Нашого Кола", boldFormat);
    cursor.insertBlock();
    cursor.insertText("Шкільна, 1", textFormat);
    cursor.insertBlock();
    cursor.insertText("Київ");
    cursor.insertBlock();
    cursor.insertText("Україна");
    cursor.setPosition(topFrame->lastPosition());
    cursor.insertText(QDate::currentDate().toString("d MM yyyy"), textFormat);
    cursor.insertBlock();
    cursor.insertBlock();
    cursor.insertText("Шановний", textFormat);
    cursor.insertText("Ім'я", italicFormat);
    cursor.insertText(",", textFormat);
    for (int i = 0; i < 7; ++i)
    {
        cursor.insertBlock();
        cursor.insertText("", italicFormat);
    }
        cursor.insertBlock();
        cursor.insertText(tr("З повагою,"), textFormat);
        cursor.insertBlock();
        cursor.insertText("Іван Кушнерчук", textFormat);
        cursor.insertBlock();
}
void MainWindow::createActions()
{
        QToolBar* menu = addToolBar(tr("file"));
        QIcon icon = QIcon::fromTheme("document-new", QIcon(":/images/new.png"));
        QAction* action = new QAction(icon, tr("&новий"), this);
        connect(action, &QAction::triggered, this, &MainWindow::newLetter);
        menu->addAction(action);
}
