#include "guestregistration.h"

GuestRegistration::GuestRegistration() {}

GuestRegistration::GuestRegistration(Person a, QString q):Registration(Person(a.getName(),a.getAffiliation(),a.getEmail())), m_category(q)
{

}

double GuestRegistration::calculateFee()
{
    return calculateFee()*0.90;
}

QString GuestRegistration::toString()
{
    return QString("The information of the person registered %1./n Booking Date: %2/n Fee: %3/nCategory %4").arg(getAttendee().toString()).arg(getBookingDate().toString("yyyy-MM-dd")).arg(calculateFee()).arg(m_category);
}


