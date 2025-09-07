#ifndef REGISTRATIONLIST_H
#define REGISTRATIONLIST_H

#include "registration.h"

class RegistrationList : public Registration
{
public:
    RegistrationList();
    bool addRegistration(Registration* r);
    ~RegistrationList();
    bool isRegistered();
    double totalFee(QString l);
    int totalRegistration(QString a);

private:
    QList<Registration*> m_AttendeeList;
};

#endif // REGISTRATIONLIST_H
