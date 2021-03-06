#include "oesms.h"
#include <QDesktopWidget>
#include <QDesktopServices>
#include <QPropertyAnimation>
#include <QApplication>
#include <QLabel>

#include <QDebug>
#include <QTimer>
const unsigned char uc_default_ico[] = {
    0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 0x00, 0x0D, 0x49, 0x48, 0x44, 0x52,
    0x00, 0x00, 0x00, 0x46, 0x00, 0x00, 0x00, 0x50, 0x04, 0x03, 0x00, 0x00, 0x00, 0x56, 0x8F, 0x1E,
    0x31, 0x00, 0x00, 0x00, 0x04, 0x67, 0x41, 0x4D, 0x41, 0x00, 0x00, 0xB1, 0x8F, 0x0B, 0xFC, 0x61,
    0x05, 0x00, 0x00, 0x00, 0x01, 0x73, 0x52, 0x47, 0x42, 0x00, 0xAE, 0xCE, 0x1C, 0xE9, 0x00, 0x00,
    0x00, 0x2A, 0x50, 0x4C, 0x54, 0x45, 0x4C, 0x69, 0x71, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xE6, 0xD6, 0x4B, 0x99, 0x00, 0x00, 0x00, 0x0D, 0x74, 0x52, 0x4E, 0x53, 0x00, 0xF2, 0x11, 0xA2,
    0x4A, 0x5D, 0xDE, 0x71, 0xB6, 0xCB, 0x3A, 0x28, 0x86, 0x77, 0x87, 0x7C, 0x9C, 0x00, 0x00, 0x01,
    0x29, 0x49, 0x44, 0x41, 0x54, 0x48, 0xC7, 0x63, 0x60, 0x18, 0x05, 0xA3, 0x60, 0x14, 0x10, 0x00,
    0xDA, 0xE1, 0x16, 0x33, 0x9B, 0x4B, 0x37, 0xE1, 0x53, 0xB2, 0xBD, 0xED, 0x2E, 0x08, 0x64, 0x54,
    0xE3, 0x56, 0xA2, 0x9E, 0x7B, 0x17, 0x02, 0x6E, 0x16, 0xE1, 0x52, 0xC2, 0x32, 0xF7, 0x2E, 0x0C,
    0xDC, 0x5C, 0x80, 0x43, 0x4D, 0xE0, 0x5D, 0x04, 0x10, 0xC5, 0xAE, 0x84, 0x5D, 0x16, 0x49, 0xCD,
    0xC5, 0x00, 0x82, 0xC6, 0xDC, 0xBD, 0x2B, 0x82, 0x4D, 0x09, 0x77, 0x2E, 0x8A, 0x9A, 0x9B, 0x0A,
    0x58, 0xD4, 0xF0, 0xDC, 0x45, 0x05, 0x05, 0x58, 0xD4, 0x6C, 0x43, 0x53, 0x33, 0x09, 0x8B, 0x9A,
    0x58, 0x34, 0x35, 0x57, 0xB0, 0xA8, 0x39, 0x0B, 0x14, 0x97, 0x04, 0xBA, 0x29, 0xF3, 0xEE, 0xDD,
    0x6B, 0x13, 0x81, 0xEC, 0x3B, 0x58, 0xD4, 0xD8, 0x02, 0x3D, 0x5C, 0xB4, 0xE3, 0xEE, 0xE5, 0x4D,
    0x67, 0xEF, 0xCE, 0x52, 0x05, 0x06, 0xC3, 0x65, 0xEC, 0x6A, 0x6E, 0x32, 0xB0, 0xDC, 0x95, 0x62,
    0x50, 0x03, 0x3A, 0xD7, 0x16, 0xB7, 0x1A, 0x05, 0x56, 0x60, 0xB8, 0x6C, 0xBB, 0x7B, 0x80, 0xA1,
    0x17, 0xBB, 0x5D, 0xB5, 0x40, 0x37, 0x58, 0x85, 0xDD, 0xBD, 0xE9, 0xD5, 0x7B, 0x57, 0x7C, 0x0D,
    0xD0, 0xAE, 0xAB, 0x58, 0xD4, 0x2C, 0x04, 0xC5, 0x00, 0x10, 0x0B, 0x02, 0x31, 0x28, 0x56, 0xB2,
    0xB1, 0xA8, 0xD1, 0x40, 0xF3, 0xBB, 0x01, 0xB6, 0x94, 0x21, 0x8B, 0xA2, 0xE4, 0x22, 0xD6, 0xD4,
    0x71, 0x16, 0x45, 0xCD, 0x1D, 0xAC, 0xF1, 0x8E, 0x6A, 0x99, 0x11, 0x56, 0x35, 0x4C, 0xBD, 0x48,
    0x4A, 0x2E, 0x2B, 0x60, 0x4F, 0x64, 0xB6, 0x48, 0xAE, 0x39, 0x84, 0x5D, 0x09, 0x17, 0x92, 0xA3,
    0x5B, 0x70, 0x24, 0x67, 0xE6, 0xBB, 0x77, 0xC5, 0x20, 0xCA, 0x2E, 0xB6, 0xE2, 0xB0, 0x09, 0x18,
    0x88, 0x12, 0x4E, 0xCB, 0xCD, 0x04, 0x05, 0x05, 0x93, 0xAB, 0x70, 0xE6, 0xAE, 0x58, 0x89, 0x20,
    0xA0, 0xC3, 0x97, 0xB8, 0x78, 0x2B, 0xE0, 0xCE, 0x81, 0xAA, 0x4E, 0xA3, 0x65, 0x19, 0x3E, 0xC0,
    0xE2, 0x30, 0x1A, 0x06, 0xA3, 0x60, 0x14, 0x10, 0x0D, 0x00, 0x0B, 0x1E, 0x11, 0xE4, 0x0A, 0x91,
    0x1A, 0x2A, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82
};
OESms::OESms(const QString & msg, OESms::TYPE type, QWidget *parent) : QWidget(parent)
{
    setFixedSize(250,80);

    /// 窗口置顶、去掉系统标题栏 (set window general property)
    Qt::WindowFlags flags = windowFlags();
    flags |= Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::X11BypassWindowManagerHint;
    if (parent == nullptr)
        flags |= Qt::Tool;
    setWindowFlags(flags);
    setAttribute(Qt::WA_TranslucentBackground, true);

    /// set ico pos and property
    icoLabel_ = new QLabel(this);
    icoLabel_->setAlignment(Qt::AlignCenter);
    icoLabel_->setGeometry(0,0,75, height());
    icoLabel_->setFixedSize(75, 80);
    icoLabel_->setText("X");
    icoLabel_->setStyleSheet("QLabel{ \
                            background-color:rgb(76,161,255); \
                            border-top-left-radius:5px;\
                            border-bottom-left-radius:5px;\
                            color:white;}");

    setIcon(type);


    messageLabel_ = new QLabel(this);
    messageLabel_->setWordWrap(true);
    messageLabel_->setAlignment(Qt::AlignCenter);
    messageLabel_->setGeometry(icoLabel_->width(),0,
                               width()-icoLabel_->width(),height());
    QString elided_text = fontMetrics().elidedText(msg, Qt::ElideRight,
                                            messageLabel_->width() * 2, Qt::TextShowMnemonic);
    messageLabel_->setText(elided_text);
    messageLabel_->setStyleSheet("QLabel{background-color:rgb(224,242,255);\
                                    padding:10px; \
                                    font-size:13px;\
                                    border-top-right-radius:5px;\
                                    border-bottom-right-radius:5px;\
                                    }");
    /// 设置位置 (set pos)
    QRect parent_rect;
    // 获得父类大小 (get parent rect)
    if (parent == nullptr)
        parent_rect = QApplication::desktop()->availableGeometry();
    else
        parent_rect = parent->rect();

    // 计算出现的位置 (calc pos)
    const int temp_height = parent_rect.height() >> 3;
    startx_ = parent_rect.width();
    starty_ = (temp_height < height()) ? (parent_rect.height() - height()) : (temp_height * 7) ;
    endx_ = parent_rect.width() - width() - 15;
}

void OESms::build(void) {
    QPropertyAnimation *animation= new QPropertyAnimation(this,"pos");
    animation->setDuration(500);
    animation->setStartValue(QPoint(startx_, starty_));
    animation->setEndValue(QPoint(endx_, starty_));
    animation->setEasingCurve(QEasingCurve::OutCubic);

    connect(animation, SIGNAL(finished()),
            this, SLOT(animationFinished()));
    show();
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void OESms::setIcon(OESms::TYPE type)
{
    QString icoStyle = " QLabel{\
                    border-image: url(%1);\
                    }";

    // 自己根据自己需要的资源进行定义 (wish for custom)
    switch (type) {
    case Emergency:
//        icoStyle.arg(":ico/msg/emergency");
        break;
    case Simple:
//        icoStyle.arg(":ico/msg/briefmsg");
        break;
    case Prompt:
//        icoStyle.arg(":ico/msg/prompt");
        break;
    default:
        QPixmap pixmap;
        pixmap.loadFromData(uc_default_ico, sizeof(uc_default_ico));
        icoLabel_->setPixmap(pixmap);
        return;
    }
//    icoLabel_->setStyleSheet(icoStyle);
}


void OESms::animationFinished(void) {
    QTimer::singleShot(5000, this, SLOT(deleteLater()));
}
