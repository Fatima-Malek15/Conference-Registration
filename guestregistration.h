#ifndef GUESTREGISTRATION_H
#define GUESTREGISTRATION_H

#include "registration.h"

class GuestRegistration : public Registration
{
    Q_OBJECT
public:
    GuestRegistration(QObject *parent);
    GuestRegistration(Person a, QString q);
    double calculateFee() const override;
    QString toString() const override;

private:
    QString m_category;
};

#endif // GUESTREGISTRATION_H
