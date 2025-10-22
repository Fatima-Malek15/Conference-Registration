#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),regList(new RegistrationList(this))
{
    this->registration;
    table = new QTableWidget(this);

    infoLabel = new QLabel("Conference Registration 2025",this);
    nameLabel = new QLabel("Name", this);
    emailLabel = new QLabel("Email", this);
    affiliationLabel = new QLabel("Affiliation", this);
    qualificationLabel = new QLabel("Choose Qualification", this);
    registrationLabel = new QLabel("Type of Registration", this);
    categoryLabel = new QLabel("Category", this);
    totalFeesLabel = new QLabel("Total Fees", this);
    dateLabel = new QLabel("Date", this);
    searchByLabel = new QLabel("Search By Name", this);

    //lines
    nameLine = new QLineEdit(this);
    emailLine = new QLineEdit(this);
    categoryLine = new QLineEdit(this);
    searchByLine = new QLineEdit(this);
}

Widget::~Widget() {}
