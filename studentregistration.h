#ifndef STUDENTREGISTRATION_H
#define STUDENTREGISTRATION_H

#include "registration.h"

class StudentRegistration : public Registration
{
public:
    StudentRegistration();
    StudentRegistration(Person a, QString q);
    double calculateFee() override;
    QString toString();

private:
    QString m_Qualification;
};

#endif // STUDENTREGISTRATION_H
