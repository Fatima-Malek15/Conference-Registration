#include "studentregistration.h"

StudentRegistration::StudentRegistration(QObject *parent):Registration(parent)
{

}

StudentRegistration::StudentRegistration(Person a, QString q):Registration(a)
{
    q = m_Qualification;
}

double StudentRegistration::calculateFee() const
{
    return STANDARD_FEE/2;
}

QString StudentRegistration::toString() const
{
    return QString("Qualification: %1\nThe Standard Fee is %2").arg(m_Qualification).arg(calculateFee());
}



