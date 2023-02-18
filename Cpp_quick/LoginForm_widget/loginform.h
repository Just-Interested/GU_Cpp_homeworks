#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QFrame>
#include <QLineEdit>
#include <QPushButton>


class LoginForm : public QFrame
{
    Q_OBJECT
    Q_PROPERTY(QColor frame_color WRITE setFrameColor)

public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

    void setFrameColor(QColor color);

public slots:
    void checkCredentials();

private:
    QLineEdit* login;
    QLineEdit* password;
    QPushButton* login_button;

    void playAnimation();
};

#endif // LOGINFORM_H
