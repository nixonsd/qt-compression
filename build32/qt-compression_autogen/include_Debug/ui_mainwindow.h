/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QCheckBox *firstReplace;
    QPushButton *executeButton;
    QPushButton *DataFolder;
    QCheckBox *secondReplace;
    QLineEdit *LData;
    QProgressBar *progressBar;
    QCheckBox *DeltaBox;
    QPushButton *cancelButton;
    QCheckBox *statisticsBox;
    QLineEdit *DataFolderPath;
    QSpacerItem *horizontalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(451, 200);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 200));
        MainWindow->setMaximumSize(QSize(16777215, 200));
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget#MainWindow {\n"
"margin: 0;\n"
"}\n"
"\n"
"QPushButton {\n"
"height: 17px;\n"
"}\n"
"\n"
"QLineEdit {\n"
"height: 17px;\n"
"}\n"
"\n"
"QPushButton#DataFolder {\n"
"width: 100px;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        firstReplace = new QCheckBox(centralwidget);
        firstReplace->setObjectName(QString::fromUtf8("firstReplace"));

        gridLayout->addWidget(firstReplace, 7, 0, 1, 1);

        executeButton = new QPushButton(centralwidget);
        executeButton->setObjectName(QString::fromUtf8("executeButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(executeButton->sizePolicy().hasHeightForWidth());
        executeButton->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(executeButton, 10, 6, 1, 1);

        DataFolder = new QPushButton(centralwidget);
        DataFolder->setObjectName(QString::fromUtf8("DataFolder"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(DataFolder->sizePolicy().hasHeightForWidth());
        DataFolder->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(DataFolder, 6, 0, 1, 2);

        secondReplace = new QCheckBox(centralwidget);
        secondReplace->setObjectName(QString::fromUtf8("secondReplace"));

        gridLayout->addWidget(secondReplace, 8, 0, 1, 1);

        LData = new QLineEdit(centralwidget);
        LData->setObjectName(QString::fromUtf8("LData"));
        sizePolicy2.setHeightForWidth(LData->sizePolicy().hasHeightForWidth());
        LData->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(LData, 0, 2, 1, 5);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setStyleSheet(QString::fromUtf8("height: 25px;"));
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignCenter);
        progressBar->setTextVisible(true);
        progressBar->setInvertedAppearance(false);
        progressBar->setTextDirection(QProgressBar::TopToBottom);

        gridLayout->addWidget(progressBar, 9, 0, 1, 7);

        DeltaBox = new QCheckBox(centralwidget);
        DeltaBox->setObjectName(QString::fromUtf8("DeltaBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(DeltaBox->sizePolicy().hasHeightForWidth());
        DeltaBox->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(DeltaBox, 7, 6, 1, 1);

        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        sizePolicy2.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(cancelButton, 10, 5, 1, 1);

        statisticsBox = new QCheckBox(centralwidget);
        statisticsBox->setObjectName(QString::fromUtf8("statisticsBox"));
        sizePolicy4.setHeightForWidth(statisticsBox->sizePolicy().hasHeightForWidth());
        statisticsBox->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(statisticsBox, 8, 6, 1, 1);

        DataFolderPath = new QLineEdit(centralwidget);
        DataFolderPath->setObjectName(QString::fromUtf8("DataFolderPath"));
        sizePolicy2.setHeightForWidth(DataFolderPath->sizePolicy().hasHeightForWidth());
        DataFolderPath->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(DataFolderPath, 6, 2, 1, 5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CD", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "L Data", nullptr));
        firstReplace->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\274\320\265\320\275\320\260 1", nullptr));
        executeButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214", nullptr));
        DataFolder->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\320\277\320\272\320\260 \"DATA\"", nullptr));
        secondReplace->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\274\320\265\320\275\320\260 2", nullptr));
        LData->setText(QCoreApplication::translate("MainWindow", "13", nullptr));
        DeltaBox->setText(QCoreApplication::translate("MainWindow", "\320\224\320\265\320\273\321\214\321\202\320\260", nullptr));
        cancelButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        statisticsBox->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
