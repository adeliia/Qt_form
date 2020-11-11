#include "formular.h"

#include <QLineEdit>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include <QCheckBox>
#include <QSpinBox>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QList>

Formular::Formular(QWidget *parent)
    : QWidget(parent)
{
    setupForm();
    setupConnections();
}

Formular::~Formular()
{
}

void Formular::setupForm() {
    QVBoxLayout *lMain = new QVBoxLayout;
    QHBoxLayout *lName = new QHBoxLayout;
    QVBoxLayout *lNameEdits = new QVBoxLayout;
    QVBoxLayout *lNameLabels = new QVBoxLayout;
    QHBoxLayout *lSex = new QHBoxLayout;
    QHBoxLayout *lDateOfBirth = new QHBoxLayout;
    QHBoxLayout *lAgreement = new QHBoxLayout;
    QHBoxLayout *lButtons = new QHBoxLayout;

    // Name and Surname
    lblName = new QLabel(tr("Jméno:"));
    editName = new QLineEdit;
    lblSurname = new QLabel(tr("Přijimení:"));
    editSurname = new QLineEdit;
    lblName->setBuddy(editName);
    lblSurname->setBuddy(editSurname);
    lNameLabels->addWidget(lblName);
    lNameLabels->addWidget(lblSurname);
    lNameLabels->addStretch();
    lNameEdits->addWidget(editName);
    lNameEdits->addWidget(editSurname);
    lNameEdits->addStretch();

    //Sex
    lblSex = new QLabel(tr("Pohlaví"));
    rbFemale = new QRadioButton(tr("&m"));
    rbMale = new QRadioButton(tr("&ž"));
    rbMale->setChecked(true);
    lSex->addWidget(lblSex);
    lSex->addWidget(rbMale);
    lSex->addWidget(rbFemale);

    // Date of birth
    lblDateOfBirth = new QLabel(tr("Narození"));
    sbDate = new QSpinBox();
    sbDate->setRange(1, 31);
    sbYear = new QSpinBox();
    sbYear->setRange(1920,2020);

    cbMonth = new QComboBox();
    QList<QString> items = {"Leden",
                                  "Unor",
                                  "Březen",
                                  "Duben",
                                  "Květen",
                                  "Červen",
                                  "Červenec",
                                  "Srpen",
                                  "Žáři",
                                  "Řjien",
                                  "Listopad",
                                  "Prosinec"};
    cbMonth->addItems(items);

    lDateOfBirth->addWidget(sbDate);
    lDateOfBirth->addWidget(cbMonth);
    lDateOfBirth->addWidget(sbYear);

    // Agreement
    chbAgreement = new QCheckBox(tr("Souhlasím s pravidly"));
//    chbAgreement->setChecked(true);
    lAgreement->addWidget(chbAgreement);
    lAgreement->addStretch();

    // Buttons
    btnRegister = new QPushButton(tr("Registrace"));
    btnCancel = new QPushButton(tr("Zrušit"));
    lButtons->addWidget(btnRegister);
    lButtons->addWidget(btnCancel);

    //Layouts
    lName->addLayout(lNameLabels);
    lName->addLayout(lNameEdits);
    lMain->addLayout(lName);
    lMain->addLayout(lSex);
    lMain->addLayout(lDateOfBirth);
    lMain->addLayout(lAgreement);
    lMain->addLayout(lButtons);

    setWindowTitle(tr("Formulař"));
    setLayout(lMain);
}

void Formular::setupConnections(){
    connect(btnCancel, SIGNAL(clicked()), this, SLOT(close()));
    connect(btnCancel, SIGNAL(clicked()), this, SLOT(registrate()));
}

void Formular::registrate(){
    QString name, surname, sex, dateOfBirth;

}
