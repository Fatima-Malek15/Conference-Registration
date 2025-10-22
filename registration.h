#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "person.h"
#include <QObject>
#include <QDate>

class Registration : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Person getAttendee READ getAttendee CONSTANT)
    Q_PROPERTY(QDate getBookingDate READ getBookingDate CONSTANT)
    Q_PROPERTY(double calculateFee READ calculateFee CONSTANT)
    Q_PROPERTY(QString toString READ toString CONSTANT)
public:
    Registration(QObject *parent);
    Registration(Person a);
    Person getAttendee() const;
    QDate getBookingDate() const;
    virtual double calculateFee() const;
    virtual QString toString() const;

    static double STANDARD_FEE;

private:
    //constant fee for standard registration
    Person m_Attendee;
    QDate m_BookingDate = QDate::currentDate();
};

#endif // REGISTRATION_H
