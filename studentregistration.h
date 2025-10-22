#ifndef STUDENTREGISTRATION_H
#define STUDENTREGISTRATION_H

#include "registration.h"

class StudentRegistration : public Registration
{
    Q_OBJECT
public:
    StudentRegistration(QObject *parent);
    StudentRegistration(Person a, QString q);
    double calculateFee() const override;
    QString toString() const override;

private:
    QString m_Qualification;
};

#endif // STUDENTREGISTRATION_H
