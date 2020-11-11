#ifndef FORMULAR_H
#define FORMULAR_H

#include <QWidget>

class QLabel;
class QRadioButton;
class QLineEdit;
class QPushButton;
class QCheckBox;
class QSpinBox;
class QComboBox;


class Formular : public QWidget
{
    Q_OBJECT

    QLabel *lblName;
    QLabel *lblSurname;
    QLabel *lblSex;
    QLabel *lblDateOfBirth;

    QLineEdit *editName;
    QLineEdit *editSurname;

    QRadioButton *rbFemale;
    QRadioButton *rbMale;

    QSpinBox *sbDate;
    QSpinBox *sbYear;
    QComboBox *cbMonth;

    QCheckBox *chbAgreement;

    QPushButton *btnRegister;
    QPushButton *btnCancel;

    void setupForm();
    void setupConnections();

public:
    Formular(QWidget *parent = nullptr);
    ~Formular();
public slots:
    void registrate();
};
#endif // FORMULAR_H
