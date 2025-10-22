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


    //adding signals and slots
    QObject::connect(add, &QPushButton::clicked, this, &Widget::addInfo);
    QObject::connect(registrationCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Widget::fieldChanged);
    QObject::connect(deleteButton, &QPushButton::clicked, this, &Widget::deleteInfo);
    QObject::connect(searchButton, &QPushButton::clicked, this, &Widget::searchInfo);
}



Widget::~Widget() {}

//adding the given information into the table
void Widget::addInfo()
{
    QString name  = nameLine->text();
    QString email = emailLine->text();
    QString date = dateEdit->text();

    table->setItem(1,1, new QTableWidgetItem(name));
    table->setItem(1,2, new QTableWidgetItem(email));
    table->setItem(1,3, new QTableWidgetItem(date));
}


void Widget::fieldChanged()
{
    QString text = registrationCombo->currentText();

    if(text == "Student")
    {
        qualificationLabel->show();
        qualificationCombo->show();
        categoryLine->hide();
        categoryLabel->hide();
    }
    else if(text == "Guest")
    {
        categoryLine->show();
        categoryLabel->show();
        qualificationLabel->hide();
        qualificationCombo->hide();
        affiliationLabel->hide();
        affiliationCombo->hide();
    }
    else{
        affiliationLabel->show();
        affiliationCombo->show();
        categoryLabel->hide();
        categoryLine->hide();
        qualificationLabel->hide();
        qualificationCombo->hide();
    }
}



void Widget::deleteInfo()
{
    QTableWidgetItem *item = table->currentItem();
    QTableWidgetItem *fee = table->columnAt(7);

    table->removeRow(table->row(item));

    //subtract fees
    double totaLFee = regList->totalFee(fee);
    for(const Registration *registration: regList)
    {
        if(item == "Registration" && dynamic_cast<const Registration*>(registration) ||
             item == "GuestRegistration" && dynamic_cast<const GuestRegistration*>(registration) ||
            item == "StudentRegistration" && dynamic_cast<const StudentRegistration*>(registration) ||
            (item == "All"))
        {
            totalFee -= registration->calculateFees();
        }
    }
}



void Widget::searchInfo()
{
    QString name = searchByLine->text();
    bool found = false;

    for(int i = 0; i < table->rowCount(); i++)
    {
        QTableWidgetItem *item = table->item(i, 0); // Assuming name is in column 0
        if (item && item->text() == name) {
            found = true;
            break;
        }
    }
    if(found)
    {
        QMessageBox::information(this, "Registration Status",QString("Name %1/nRegistered? Yes").arg(name));
    }
    else
    {
        QMessageBox::information(this, "Registration Status",QString("Name %1/nRegistered? No").arg(name));
    }
}

