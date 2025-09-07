#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "person.h"

#include <QDate>

class Registration : public Person
{
public:
    Registration();
    Registration(Person a);
    Person getAttendee();
    QDate getBookingDate();
    virtual double calculateFee();
    QString toString();

private:
    double STANDARD_FEE = 120.00; //constant fee for standard registration
    Person m_Attendee;
    QDate m_BookingDate;
};

#endif // REGISTRATION_H
