#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>

class LoginWindow : public QWidget {
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("All Login Options");
        resize(400, 450);

        // Background color
        this->setStyleSheet("background-color: #e6f2ff;");

        int y = 30;

        // Username Label
        QLabel *labelUser = new QLabel("Username:", this);
        labelUser->move(20, y);
        labelUser->setStyleSheet("color: #1a1a1a; font-weight: bold;");

        editUser = new QLineEdit(this);
        editUser->move(150, y);
        editUser->resize(200, 25);
        editUser->setStyleSheet("background-color: white; border: 2px solid gray; padding: 5px;");

        y += 50;
        QLabel *labelPass = new QLabel("Password:", this);
        labelPass->move(20, y);
        labelPass->setStyleSheet("color: #1a1a1a; font-weight: bold;");

        editPass = new QLineEdit(this);
        editPass->setEchoMode(QLineEdit::Password);
        editPass->move(150, y);
        editPass->resize(200, 25);
        editPass->setStyleSheet("background-color: white; border: 2px solid gray; padding: 5px;");

        y += 50;
        QPushButton *btnLogin = new QPushButton("Login", this);
        btnLogin->move(150, y);
        btnLogin->setStyleSheet("background-color: green; color: white; font-weight: bold; border-radius: 5px;");
        connect(btnLogin, &QPushButton::clicked, this, &LoginWindow::validateLogin);

        y += 40;
        QPushButton *btnForgot = new QPushButton("Forgot Password?", this);
        btnForgot->move(150, y);
        btnForgot->setFlat(true);
        btnForgot->setStyleSheet("color: red; font-weight: bold; background: transparent;");
        connect(btnForgot, &QPushButton::clicked, this, &LoginWindow::forgotPassword);

        y += 50;
        QLabel *labelSocial = new QLabel("Or login with:", this);
        labelSocial->move(20, y);
        labelSocial->setStyleSheet("color: #1a1a1a; font-weight: bold;");

        y += 40;
        // Social Buttons
        QPushButton *btnGoogle = new QPushButton("Google", this);
        btnGoogle->move(20, y);
        btnGoogle->setStyleSheet("background-color: #db4437; color: white; border-radius: 5px;");
        connect(btnGoogle, &QPushButton::clicked, this, &LoginWindow::googleLogin);

        QPushButton *btnFacebook = new QPushButton("Facebook", this);
        btnFacebook->move(120, y);
        btnFacebook->setStyleSheet("background-color: #3b5998; color: white; border-radius: 5px;");
        connect(btnFacebook, &QPushButton::clicked, this, &LoginWindow::facebookLogin);

        QPushButton *btnInstagram = new QPushButton("Instagram", this);
        btnInstagram->move(240, y);
        btnInstagram->setStyleSheet("background-color: #e1306c; color: white; border-radius: 5px;");
        connect(btnInstagram, &QPushButton::clicked, this, &LoginWindow::instagramLogin);

        y += 50;
        QPushButton *btnX = new QPushButton("X.com", this);
        btnX->move(20, y);
        btnX->setStyleSheet("background-color: #1da1f2; color: white; border-radius: 5px;");
        connect(btnX, &QPushButton::clicked, this, &LoginWindow::xLogin);

        QPushButton *btnYahoo = new QPushButton("Yahoo Mail", this);
        btnYahoo->move(120, y);
        btnYahoo->setStyleSheet("background-color: #400090; color: white; border-radius: 5px;");
        connect(btnYahoo, &QPushButton::clicked, this, &LoginWindow::yahooLogin);

        QPushButton *btnMobile = new QPushButton("Mobile OTP", this);
        btnMobile->move(240, y);
        btnMobile->setStyleSheet("background-color: #ff9900; color: white; border-radius: 5px;");
        connect(btnMobile, &QPushButton::clicked, this, &LoginWindow::mobileOTPLogin);
    }

private slots:
    void validateLogin() {
        QString username = editUser->text();
        QString password = editPass->text();

        if(username == "admin" && password == "1234") {
            QMessageBox::information(this, "Success", "Login Successful ✅");
        } else {
            QMessageBox::warning(this, "Error", "Invalid Username or Password ❌");
        }
    }

    void forgotPassword() {
        QMessageBox::information(this, "Password Hint", "Username: admin\nPassword: 1234");
    }

    void googleLogin() { QMessageBox::information(this, "Google Login", "Simulate Google OAuth login"); }
    void facebookLogin() { QMessageBox::information(this, "Facebook Login", "Simulate Facebook OAuth login"); }
    void instagramLogin() { QMessageBox::information(this, "Instagram Login", "Simulate Instagram OAuth login"); }
    void xLogin() { QMessageBox::information(this, "X.com Login", "Simulate X.com/Twitter OAuth login"); }
    void yahooLogin() { QMessageBox::information(this, "Yahoo Login", "Simulate Yahoo OAuth login"); }

    void mobileOTPLogin() {
        bool ok;
        QString mobile = QInputDialog::getText(this, "Mobile OTP Login", "Enter Mobile Number:", QLineEdit::Normal, "", &ok);
        if(ok && !mobile.isEmpty()) {
            QString otp = "123456"; // simulated OTP
            QString entered = QInputDialog::getText(this, "Enter OTP", "OTP sent to " + mobile + ":", QLineEdit::Normal, "", &ok);
            if(entered == otp) {
                QMessageBox::information(this, "Success", "OTP Verified ✅");
            } else {
                QMessageBox::warning(this, "Error", "Invalid OTP ❌");
            }
        }
    }

private:
    QLineEdit *editUser;
    QLineEdit *editPass;
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    LoginWindow w;
    w.show();
    return a.exec();
}

#include "main.moc"

