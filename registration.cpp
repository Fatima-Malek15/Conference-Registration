#include "registration.h"

double Registration::STANDARD_FEE = 100.00;

Registration::Registration(QObject *parent):QObject(parent) {}

Registration::Registration(Person a)
{
    m_Attendee.getName() = a.getName();
    m_Attendee.getEmail() = a.getEmail();
    m_Attendee.getAffiliation() = a.getAffiliation();
}

Person Registration::getAttendee() const
{
    Person p(m_Attendee.getName(), m_Attendee.getAffiliation(), m_Attendee.getEmail());
    return p;
}

QDate Registration::getBookingDate() const
{
    return m_BookingDate;
}

double Registration::calculateFee() const
{
    return STANDARD_FEE;
}

QString Registration::toString() const
{
    return QString("Booking Date: %1\nThe Attendee is %2\nThe Standard Fee%3")
        .arg(getBookingDate().toString("yyyy-MM-dd")).arg(getAttendee().toString()).arg(calculateFee());
}
