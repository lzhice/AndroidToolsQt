﻿#ifndef NFC_H
#define NFC_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QProgressBar>
#include <QTextEdit>
#include <QString>
#include <QSizePolicy>
#include <QDebug>
#include <QFileSystemWatcher>
#include <QStandardPaths>
#include "utils/runsyscmd.h"
#include "utils/cpfilethread.h"

using namespace std;

class Nfc : public QWidget {
    Q_OBJECT

public:
    explicit Nfc(QWidget *parent = nullptr);
    ~Nfc();

signals:

public slots:
    void getCplcBtnClick();
    void jcshellBatPathBtnClick();
    void serverAuthKeyBtnClick();
    void writeAuthKeyBtnClick();
    void checkAuthKeyBtnClick();
    void copyFileSuccess();
    void batGetCplcSuccess();
    void batAuthKeySuccess();
    void batCheckKeySuccess();

private:
    void initUi();
    void showLog(QString log);
    bool checkJcshell();
    bool checkServerAuthKeyPath();
    void showBusy(const bool &busy);

private:
    QString cplc;
    QString jcshellBatPath;
    QString jcshellDirPath;
    QString serverAuthKeyPath;
    uchar copyFileTimes = 0;
    QVBoxLayout *mainLayout = nullptr;
    QHBoxLayout *jcshellBatPathLayout = nullptr;
    QHBoxLayout *serverAuthKeyPathLayout = nullptr;
    QHBoxLayout *operBtnsLayout = nullptr;
    QLineEdit *jcshellBatPathEdit = nullptr;
    QPushButton *jcshellBatPathBtn = nullptr;
    QLineEdit *serverAuthKeyPathEdit = nullptr;
    QPushButton *serverAuthKeyPathBtn = nullptr;
    QTextEdit *logEdit = nullptr;
    QPushButton *getCplcBtn = nullptr;
    QPushButton *writeAuthKeyBtn = nullptr;
    QPushButton *checkAuthKeyBtn = nullptr;
    QFileSystemWatcher *fileWatcher = nullptr;
    QProgressBar *progressBar;
    CpFilethread *cpBatFileThread = nullptr;
    CpFilethread *cpJcshellThread = nullptr;
};

#endif  // NFC_H