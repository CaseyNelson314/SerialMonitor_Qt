/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *PortNameComboBox;
    QComboBox *PortLateComboBox;
    QPushButton *PortStateButton;
    QLineEdit *writeText;
    QPushButton *SendButton;
    QTabWidget *MonitorSelector;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QPlainTextEdit *SerialMonitor;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *TimestampCheckBox;
    QCheckBox *BinCheckBox;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *MaxLineSpinBox;
    QPushButton *PageDownButton;
    QPushButton *ClearMainMonitorButton;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QWidget *Property;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *log;
    QTextBrowser *LogMonitor;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *ClearPropertyButton;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QListWidget *PropertyPortName;
    QListWidget *PropertyPortData;
    QLabel *port;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *BruetoothEnableChackBox;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_8;
    QLabel *label;
    QTextBrowser *subSerialMonitor;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(907, 868);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(550, 0));
        QFont font;
        font.setStyleStrategy(QFont::PreferDefault);
        MainWindow->setFont(font);
        MainWindow->setFocusPolicy(Qt::WheelFocus);
        MainWindow->setContextMenuPolicy(Qt::DefaultContextMenu);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../serial_port_icon_138204.png"), QSize(), QIcon::Normal, QIcon::On);
        MainWindow->setWindowIcon(icon);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        PortNameComboBox = new QComboBox(centralwidget);
        PortNameComboBox->setObjectName(QString::fromUtf8("PortNameComboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(PortNameComboBox->sizePolicy().hasHeightForWidth());
        PortNameComboBox->setSizePolicy(sizePolicy1);
        PortNameComboBox->setMinimumSize(QSize(80, 0));
        QFont font1;
        font1.setPointSize(10);
        font1.setStyleStrategy(QFont::PreferDefault);
        PortNameComboBox->setFont(font1);
        PortNameComboBox->setMouseTracking(false);
        PortNameComboBox->setTabletTracking(false);
        PortNameComboBox->setFocusPolicy(Qt::NoFocus);
        PortNameComboBox->setContextMenuPolicy(Qt::DefaultContextMenu);
        PortNameComboBox->setAcceptDrops(false);
        PortNameComboBox->setLayoutDirection(Qt::LeftToRight);
        PortNameComboBox->setFrame(false);

        horizontalLayout->addWidget(PortNameComboBox);

        PortLateComboBox = new QComboBox(centralwidget);
        PortLateComboBox->addItem(QString());
        PortLateComboBox->addItem(QString());
        PortLateComboBox->addItem(QString());
        PortLateComboBox->addItem(QString());
        PortLateComboBox->addItem(QString());
        PortLateComboBox->setObjectName(QString::fromUtf8("PortLateComboBox"));
        PortLateComboBox->setEnabled(true);
        sizePolicy1.setHeightForWidth(PortLateComboBox->sizePolicy().hasHeightForWidth());
        PortLateComboBox->setSizePolicy(sizePolicy1);
        PortLateComboBox->setMinimumSize(QSize(80, 0));
        PortLateComboBox->setSizeIncrement(QSize(0, 0));
        PortLateComboBox->setBaseSize(QSize(0, 0));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        font2.setKerning(false);
        font2.setStyleStrategy(QFont::PreferDefault);
        PortLateComboBox->setFont(font2);
        PortLateComboBox->setFocusPolicy(Qt::NoFocus);
        PortLateComboBox->setContextMenuPolicy(Qt::ActionsContextMenu);
        PortLateComboBox->setAcceptDrops(false);
        PortLateComboBox->setLayoutDirection(Qt::LeftToRight);
        PortLateComboBox->setAutoFillBackground(false);
        PortLateComboBox->setInputMethodHints(Qt::ImhNone);
        PortLateComboBox->setEditable(false);
        PortLateComboBox->setInsertPolicy(QComboBox::InsertAlphabetically);
        PortLateComboBox->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        PortLateComboBox->setFrame(false);

        horizontalLayout->addWidget(PortLateComboBox);

        PortStateButton = new QPushButton(centralwidget);
        PortStateButton->setObjectName(QString::fromUtf8("PortStateButton"));
        PortStateButton->setFont(font1);
        PortStateButton->setFocusPolicy(Qt::NoFocus);
        PortStateButton->setCheckable(false);
        PortStateButton->setChecked(false);
        PortStateButton->setAutoRepeat(false);
        PortStateButton->setAutoExclusive(false);
        PortStateButton->setAutoDefault(false);
        PortStateButton->setFlat(false);

        horizontalLayout->addWidget(PortStateButton);

        writeText = new QLineEdit(centralwidget);
        writeText->setObjectName(QString::fromUtf8("writeText"));
        writeText->setFont(font1);
        writeText->setFrame(false);

        horizontalLayout->addWidget(writeText);

        SendButton = new QPushButton(centralwidget);
        SendButton->setObjectName(QString::fromUtf8("SendButton"));
        SendButton->setFont(font1);

        horizontalLayout->addWidget(SendButton);


        verticalLayout->addLayout(horizontalLayout);

        MonitorSelector = new QTabWidget(centralwidget);
        MonitorSelector->setObjectName(QString::fromUtf8("MonitorSelector"));
        MonitorSelector->setTabShape(QTabWidget::Rounded);
        MonitorSelector->setElideMode(Qt::ElideNone);
        MonitorSelector->setUsesScrollButtons(true);
        MonitorSelector->setTabsClosable(false);
        MonitorSelector->setMovable(true);
        MonitorSelector->setTabBarAutoHide(false);
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        SerialMonitor = new QPlainTextEdit(widget);
        SerialMonitor->setObjectName(QString::fromUtf8("SerialMonitor"));
        QFont font3;
        font3.setPointSize(11);
        font3.setStyleStrategy(QFont::PreferDefault);
        SerialMonitor->setFont(font3);
        SerialMonitor->setLineWrapMode(QPlainTextEdit::NoWrap);
        SerialMonitor->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout_2->addWidget(SerialMonitor);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        TimestampCheckBox = new QCheckBox(widget);
        TimestampCheckBox->setObjectName(QString::fromUtf8("TimestampCheckBox"));

        horizontalLayout_5->addWidget(TimestampCheckBox);

        BinCheckBox = new QCheckBox(widget);
        BinCheckBox->setObjectName(QString::fromUtf8("BinCheckBox"));

        horizontalLayout_5->addWidget(BinCheckBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        MaxLineSpinBox = new QSpinBox(widget);
        MaxLineSpinBox->setObjectName(QString::fromUtf8("MaxLineSpinBox"));
        MaxLineSpinBox->setEnabled(true);
        MaxLineSpinBox->setMinimumSize(QSize(110, 24));
        QFont font4;
        font4.setBold(false);
        font4.setItalic(false);
        font4.setUnderline(false);
        font4.setStrikeOut(false);
        font4.setStyleStrategy(QFont::PreferDefault);
        MaxLineSpinBox->setFont(font4);
        MaxLineSpinBox->setMouseTracking(false);
        MaxLineSpinBox->setTabletTracking(false);
        MaxLineSpinBox->setFocusPolicy(Qt::NoFocus);
        MaxLineSpinBox->setContextMenuPolicy(Qt::NoContextMenu);
        MaxLineSpinBox->setAcceptDrops(false);
        MaxLineSpinBox->setWrapping(false);
        MaxLineSpinBox->setFrame(false);
        MaxLineSpinBox->setAlignment(Qt::AlignCenter);
        MaxLineSpinBox->setReadOnly(false);
        MaxLineSpinBox->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        MaxLineSpinBox->setAccelerated(false);
        MaxLineSpinBox->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        MaxLineSpinBox->setKeyboardTracking(false);
        MaxLineSpinBox->setProperty("showGroupSeparator", QVariant(false));
        MaxLineSpinBox->setMinimum(1);
        MaxLineSpinBox->setMaximum(10000);
        MaxLineSpinBox->setSingleStep(100);
        MaxLineSpinBox->setStepType(QAbstractSpinBox::DefaultStepType);
        MaxLineSpinBox->setValue(3000);

        horizontalLayout_5->addWidget(MaxLineSpinBox);

        PageDownButton = new QPushButton(widget);
        PageDownButton->setObjectName(QString::fromUtf8("PageDownButton"));

        horizontalLayout_5->addWidget(PageDownButton);

        ClearMainMonitorButton = new QPushButton(widget);
        ClearMainMonitorButton->setObjectName(QString::fromUtf8("ClearMainMonitorButton"));

        horizontalLayout_5->addWidget(ClearMainMonitorButton);


        verticalLayout_2->addLayout(horizontalLayout_5);

        MonitorSelector->addTab(widget, QString());
        widget_2 = new QWidget();
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView = new QGraphicsView(widget_2);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        MonitorSelector->addTab(widget_2, QString());
        Property = new QWidget();
        Property->setObjectName(QString::fromUtf8("Property"));
        verticalLayout_4 = new QVBoxLayout(Property);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        frame_4 = new QFrame(Property);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        log = new QLabel(frame_4);
        log->setObjectName(QString::fromUtf8("log"));
        log->setFont(font3);
        log->setMargin(6);

        verticalLayout_3->addWidget(log);

        LogMonitor = new QTextBrowser(frame_4);
        LogMonitor->setObjectName(QString::fromUtf8("LogMonitor"));
        LogMonitor->setFont(font1);
        LogMonitor->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        LogMonitor->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout_3->addWidget(LogMonitor);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        ClearPropertyButton = new QPushButton(frame_4);
        ClearPropertyButton->setObjectName(QString::fromUtf8("ClearPropertyButton"));

        horizontalLayout_6->addWidget(ClearPropertyButton);


        verticalLayout_3->addLayout(horizontalLayout_6);


        verticalLayout_4->addWidget(frame_4);

        frame = new QFrame(Property);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(16777215, 250));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(0);
        gridLayout_2->setVerticalSpacing(6);
        gridLayout_2->setContentsMargins(0, 0, 0, -1);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 0, 0, 0);
        PropertyPortName = new QListWidget(frame);
        PropertyPortName->setObjectName(QString::fromUtf8("PropertyPortName"));
        PropertyPortName->setMaximumSize(QSize(100, 16777215));
        PropertyPortName->setFont(font1);
        PropertyPortName->setFocusPolicy(Qt::NoFocus);
        PropertyPortName->setDefaultDropAction(Qt::CopyAction);
        PropertyPortName->setSelectionMode(QAbstractItemView::NoSelection);
        PropertyPortName->setMovement(QListView::Static);
        PropertyPortName->setViewMode(QListView::ListMode);

        horizontalLayout_4->addWidget(PropertyPortName);

        PropertyPortData = new QListWidget(frame);
        PropertyPortData->setObjectName(QString::fromUtf8("PropertyPortData"));
        PropertyPortData->setFont(font1);
        PropertyPortData->setFocusPolicy(Qt::NoFocus);
        PropertyPortData->setContextMenuPolicy(Qt::DefaultContextMenu);
        PropertyPortData->setDragEnabled(false);
        PropertyPortData->setDefaultDropAction(Qt::MoveAction);
        PropertyPortData->setSelectionMode(QAbstractItemView::NoSelection);
        PropertyPortData->setSelectionBehavior(QAbstractItemView::SelectRows);
        PropertyPortData->setMovement(QListView::Free);

        horizontalLayout_4->addWidget(PropertyPortData);


        gridLayout_2->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        port = new QLabel(frame);
        port->setObjectName(QString::fromUtf8("port"));
        port->setFont(font3);
        port->setMargin(6);

        gridLayout_2->addWidget(port, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        BruetoothEnableChackBox = new QCheckBox(frame);
        BruetoothEnableChackBox->setObjectName(QString::fromUtf8("BruetoothEnableChackBox"));

        horizontalLayout_7->addWidget(BruetoothEnableChackBox);


        gridLayout_2->addLayout(horizontalLayout_7, 2, 0, 1, 1);


        verticalLayout_4->addWidget(frame);

        widget_4 = new QWidget(Property);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMaximumSize(QSize(16777215, 65));
        verticalLayout_8 = new QVBoxLayout(widget_4);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 0));
        label->setMaximumSize(QSize(16777215, 16777215));
        label->setFont(font3);
        label->setMargin(6);

        verticalLayout_8->addWidget(label);

        subSerialMonitor = new QTextBrowser(widget_4);
        subSerialMonitor->setObjectName(QString::fromUtf8("subSerialMonitor"));
        subSerialMonitor->setMinimumSize(QSize(0, 0));
        subSerialMonitor->setMaximumSize(QSize(16777215, 30));
        subSerialMonitor->setFont(font1);
        subSerialMonitor->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        subSerialMonitor->setLineWrapMode(QTextEdit::NoWrap);
        subSerialMonitor->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout_8->addWidget(subSerialMonitor);


        verticalLayout_4->addWidget(widget_4);

        MonitorSelector->addTab(Property, QString());

        verticalLayout->addWidget(MonitorSelector);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 907, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        PortLateComboBox->setCurrentIndex(4);
        PortStateButton->setDefault(true);
        MonitorSelector->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "QtSerialMonitor", nullptr));
#if QT_CONFIG(tooltip)
        PortNameComboBox->setToolTip(QCoreApplication::translate("MainWindow", "Port", nullptr));
#endif // QT_CONFIG(tooltip)
        PortNameComboBox->setCurrentText(QString());
        PortLateComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "9600", nullptr));
        PortLateComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "19200 ", nullptr));
        PortLateComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "38400 ", nullptr));
        PortLateComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "57600 ", nullptr));
        PortLateComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "115200", nullptr));

#if QT_CONFIG(tooltip)
        PortLateComboBox->setToolTip(QCoreApplication::translate("MainWindow", "Portlate(bps)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        PortLateComboBox->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        PortLateComboBox->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        PortLateComboBox->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        PortLateComboBox->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        PortLateComboBox->setCurrentText(QCoreApplication::translate("MainWindow", "115200", nullptr));
        PortLateComboBox->setPlaceholderText(QString());
        PortStateButton->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
#if QT_CONFIG(shortcut)
        PortStateButton->setShortcut(QCoreApplication::translate("MainWindow", "S", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(accessibility)
        writeText->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        SendButton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
#if QT_CONFIG(shortcut)
        SendButton->setShortcut(QCoreApplication::translate("MainWindow", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        MonitorSelector->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        TimestampCheckBox->setText(QCoreApplication::translate("MainWindow", "Timestamp", nullptr));
        BinCheckBox->setText(QCoreApplication::translate("MainWindow", "BIN", nullptr));
        MaxLineSpinBox->setSpecialValueText(QString());
        MaxLineSpinBox->setSuffix(QCoreApplication::translate("MainWindow", " Line", nullptr));
        MaxLineSpinBox->setPrefix(QCoreApplication::translate("MainWindow", "Max ", nullptr));
        PageDownButton->setText(QCoreApplication::translate("MainWindow", "Down", nullptr));
        ClearMainMonitorButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        MonitorSelector->setTabText(MonitorSelector->indexOf(widget), QCoreApplication::translate("MainWindow", "Monitor", nullptr));
        MonitorSelector->setTabText(MonitorSelector->indexOf(widget_2), QCoreApplication::translate("MainWindow", "Plotter", nullptr));
        log->setText(QCoreApplication::translate("MainWindow", "Log", nullptr));
        ClearPropertyButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        port->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        BruetoothEnableChackBox->setText(QCoreApplication::translate("MainWindow", "Bluetooth", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Monitor", nullptr));
        MonitorSelector->setTabText(MonitorSelector->indexOf(Property), QCoreApplication::translate("MainWindow", "Property", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
