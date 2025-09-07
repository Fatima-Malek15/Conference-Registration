#ifndef GUESTREGISTRATION_H
#define GUESTREGISTRATION_H

#include "registration.h"

class GuestRegistration : public Registration
{
public:
    GuestRegistration();
    GuestRegistration(Person a, QString q);
    double calculateFee() override;
    QString toString();

private:
    QString m_category;
};

#endif // GUESTREGISTRATION_H
