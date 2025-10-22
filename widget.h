#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QMessageBox>
#include <QGridLayout>
#include <QDateEdit>
#include <QCursor>

#include "registrationlist.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    //void addInfo();

private:
    QTableWidget *table;
    Registration *registration;
    RegistrationList *regList;

    QCursor cursor;

    QGridLayout *layout;

    QDateEdit *dateEdit;

    QLabel *infoLabel;
    QLabel *nameLabel;
    QLabel *emailLabel;
    QLabel *affiliationLabel;
    QLabel *registrationLabel;
    QLabel *qualificationLabel;
    QLabel *totalFeesLabel;
    QLabel *dateLabel;
    QLabel *categoryLabel;
    QLabel *searchByLabel;

    QLineEdit *nameLine;
    QLineEdit *emailLine;
    QLineEdit *categoryLine;
    QLineEdit *searchByLine;

    QComboBox *affiliationCombo;
    QComboBox *registrationCombo;
    QComboBox *qualificationCombo;
    QComboBox *totalFees;

    QPushButton *add;
    QPushButton *deleteButton;
    QPushButton *searchButton;
    QPushButton *saveButton;
    QPushButton *loadButton;

};
#endif // WIDGET_H
