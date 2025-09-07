#include "registration.h"


Registration::Registration():Person() {}

Registration::Registration(Person a):Person(a.getName(), a.getAffiliation(), a.getEmail())
{

}

Person Registration::getAttendee()
{
    return Person(m_Attendee.getName(), m_Attendee.getAffiliation(), m_Attendee.getEmail());
}

QDate Registration::getBookingDate()
{
    return m_BookingDate.currentDate();
}

double Registration::calculateFee()
{
    return STANDARD_FEE;
}

QString Registration::toString()
{
    return QString("The information of the person registered %1./n Booking Date: %2/n Fee: %3").arg(getAttendee().toString()).arg(getBookingDate().toString("yyyy-MM-dd")).arg(calculateFee());
}
