#include "studentregistration.h"

StudentRegistration::StudentRegistration(Person a, QString q): Registration(Person(a.getName(),a.getAffiliation(),a.getEmail())),m_Qualification(q){}

double StudentRegistration::calculateFee()
{
    return calculateFee()/2;
}

QString StudentRegistration::toString()
{
    return QString("The information of the person registered %1./n Booking Date: %2/n Fee: %3/Qualification %4").arg(getAttendee().toString()).arg(getBookingDate().toString("yyyy-MM-dd")).arg(calculateFee()).arg(m_Qualification);
}
