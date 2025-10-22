#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),regList(new RegistrationList(this))
{
    this->registration = nullptr;
    table = new QTableWidget(0, 8, this);

    //adding GUI labels
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

    //date
    dateEdit = new QDateEdit(QDate::currentDate(),this);

    //adding widget GUI lines and combo boxes
    nameLine = new QLineEdit(this);
    emailLine = new QLineEdit(this);
    categoryLine = new QLineEdit(this);
    searchByLine = new QLineEdit(this);

    affiliationCombo = new QComboBox(this);
    registrationCombo = new QComboBox(this);
    qualificationCombo = new QComboBox(this);
    totalFees = new QComboBox(this);

    layout = new QGridLayout(this);

    //buttons
    add = new QPushButton("Add", this);
    deleteButton = new QPushButton("Delete", this);
    searchButton = new QPushButton("Search", this);

    //add items to combo box
    affiliationCombo->addItems({"Unisa", "Rhodes University", "UCT", "UKZN","Emeris"});
    qualificationCombo->addItems({"Bsc", "Bsc Computing", "Bsc Mathematic", "Bcom", "Bcom Accounting", "Bed Senior"});
    registrationCombo->addItems({"Standard", "Student", "Guest"});
    totalFees->addItems({"Standard", "Student", "Guest"});

    //we need to hide the information until its valid
    qualificationLabel->hide();
    qualificationCombo->hide();
    categoryLine->hide();
    categoryLabel->hide();

    //adding table columns and grid layout
    cursor.setPos(600,500);
    table->setHorizontalHeaderLabels({"Name", "Email", "Type", "Qualification", "Affiliation", "Category", "Date", "Fees"});
    table->setCursor(cursor);
    table->setGeometry(200, 200, 400, 200);

    layout->addWidget(infoLabel, 1, 1);
    layout->addWidget(nameLabel, 2, 1);
    layout->addWidget(nameLine, 2, 2);
    layout->addWidget(emailLabel, 3, 1);
    layout->addWidget(emailLine, 3, 2);
    layout->addWidget(dateLabel, 4, 1);
    layout->addWidget(dateEdit, 4, 2);
    layout->addWidget(registrationLabel, 5, 1);
    layout->addWidget(registrationCombo, 5, 2);
    layout->addWidget(affiliationLabel, 6, 1);
    layout->addWidget(affiliationCombo, 6, 2);
    layout->addWidget(qualificationLabel, 7, 1);
    layout->addWidget(qualificationCombo, 7, 2);
    layout->addWidget(categoryLine, 8, 1);
    layout->addWidget(categoryLabel, 8, 2);
    layout->addWidget(add, 9, 1);
    layout->addWidget(deleteButton, 9, 2);
    layout->addWidget(table, 10, 1);
    layout->addWidget(totalFeesLabel, 11, 1);
    layout->addWidget(totalFees, 11, 2);
    layout->addWidget(searchByLabel, 12, 1);
    layout->addWidget(searchByLine, 12, 2);
    layout->addWidget(searchButton, 12, 3);

    setLayout(layout);

}

Widget::~Widget() {}
