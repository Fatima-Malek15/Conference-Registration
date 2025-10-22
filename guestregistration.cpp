#include "guestregistration.h"

GuestRegistration::GuestRegistration(QObject *parent):Registration(parent) {}

GuestRegistration::GuestRegistration(Person a, QString q):Registration(a)
{
    q = m_category;
}

double GuestRegistration::calculateFee() const
{
    return calculateFee()*0.90;
}

QString GuestRegistration::toString() const
{
    return QString("Qualification: %1\nThe Standard Fee is %2").arg(m_category).arg(calculateFee());
}


