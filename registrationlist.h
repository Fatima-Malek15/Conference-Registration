#ifndef REGISTRATIONLIST_H
#define REGISTRATIONLIST_H

#include "registration.h"
#include <QMetaObject>

class RegistrationList : public QObject
{
    Q_OBJECT
public:
    explicit RegistrationList(QObject *parent = nullptr);
    RegistrationList(Registration *r);
    bool addRegistration(Registration* r);
    ~RegistrationList();
    bool isRegistered(QString n);
    double totalFee(QString l);
    int totalRegistration(QString a);

private:
    QList<Registration*> m_AttendeeList;
};

#endif // REGISTRATIONLIST_H
