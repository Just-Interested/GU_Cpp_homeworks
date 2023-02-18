#include "loginform.h"
#include "ui_loginform.h"

#include <QGridLayout>
#include <QSequentialAnimationGroup>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>

LoginForm::LoginForm(QWidget *parent) :
    QFrame(parent)
{
    this->setObjectName("LoginForm");
    this->setFixedSize(300,250);

    QGridLayout* layout = new QGridLayout(this);

    login = new QLineEdit(this);
    login->setPlaceholderText(tr(" Логин"));

    password = new QLineEdit(this);
    password->setEchoMode(QLineEdit::Password);
    password->setPlaceholderText(tr(" Пароль"));

    login_button = new QPushButton(this);
    login_button->setText(tr("Вход"));

    this->setLayout(layout);
    layout->addWidget(login);
    layout->addWidget(password);
    layout->addWidget(login_button);

    layout->setAlignment(login, Qt::AlignHCenter);
    layout->setAlignment(password, Qt::AlignHCenter);
    layout->setAlignment(login_button, Qt::AlignHCenter);

    this->setStyleSheet("QFrame#LoginForm { "
                            "background-color:white;"
                            "border-radius: 5px;"
                        "}"
                        "* {"
                            "color: #535353;"
                        "}"
                        "QLineEdit {"
                            "background-color:white;"
                            "min-width:250px;"
                        "}"
                        "QPushButton {"
                            "background-color: #f6f6f6;"
                            "min-width:200px;"
                            "min-height: 20px;"
                        "}"
                        "QPushButton:pressed {"
                            "background-color: #bbbbbb;"
                        "}"
                        "QPushButton:hover:!pressed {"
                            "background-color: #d6d6d6;"
                        "}");

    QWidget* p = static_cast<QWidget*>(this->parent());
    if (p != nullptr){
        this->setGeometry(p->width() * 0.5 - this->width() * 0.5,
                          p->height() * 0.5 - this->height() * 0.5,
                          300, 250);
    }
    connect(login_button, &QPushButton::clicked, this, &LoginForm::checkCredentials);
}

LoginForm::~LoginForm()
{

}

void LoginForm::setFrameColor(QColor color)
{
    // it should be soooo slowly I guess
    QString color_pattern("QFrame#LoginForm { background-color:");
    QString stylesheet = this->styleSheet();
    int pos = stylesheet.indexOf(color_pattern);
    pos = pos + color_pattern.length();
    int end_pos = stylesheet.indexOf(';', pos);
    stylesheet.replace(pos, end_pos - pos, color.name());
    this->setStyleSheet(stylesheet);
}

void LoginForm::playAnimation()
{
    // here is memory leakage I guess
    uint32_t duration = 100;
    QPoint start_pos = this->pos();
    QPoint end_pos = QPoint(start_pos.x(), start_pos.y() + 10);

    QPropertyAnimation* anim1 = new QPropertyAnimation(this, "pos");
    anim1->setDuration(duration);
    anim1->setStartValue(start_pos);
    anim1->setEndValue(end_pos);

    QPropertyAnimation* anim2 = new QPropertyAnimation(this, "pos");
    anim2->setDuration(duration / 2);
    anim2->setStartValue(end_pos);
    anim2->setEndValue(start_pos);

    QPropertyAnimation* anim3 = new QPropertyAnimation(this, "frame_color");
    anim3->setDuration(duration / 2);
    anim3->setStartValue(QColor("white"));
    anim3->setEndValue(QColor("red"));

    QPropertyAnimation* anim4 = new QPropertyAnimation(this, "frame_color");
    anim4->setDuration(duration / 2);
    anim4->setStartValue(QColor("red"));
    anim4->setEndValue(QColor("white"));

    QSequentialAnimationGroup* anim_group1 = new QSequentialAnimationGroup;
    anim_group1->addAnimation(anim1);
    anim_group1->addAnimation(anim2);

    QSequentialAnimationGroup* anim_group2 = new QSequentialAnimationGroup;
    anim_group2->addAnimation(anim3);
    anim_group2->addAnimation(anim4);

    QParallelAnimationGroup* group = new QParallelAnimationGroup;
    group->addAnimation(anim_group1);
    group->addAnimation(anim_group2);
    group->start();
}

void LoginForm::checkCredentials()
{
    QString default_login("admin");
    QString default_password("admin");
    if (login->text() != default_login || password->text() != default_password)
        playAnimation();
    else {
        qDebug() << "Success!";
    }
}
