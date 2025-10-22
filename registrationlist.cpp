#include "registrationlist.h"
#include "guestregistration.h"
#include "studentregistration.h"

RegistrationList::RegistrationList(Registration *r)
{
    m_AttendeeList.append(r);
}

bool RegistrationList::addRegistration(Registration *r)
{
    if(r != NULL){
        m_AttendeeList.append(r);
        return true;
    }
    return false;
}

RegistrationList::~RegistrationList()
{
    if(!m_AttendeeList.isEmpty())
    {
        m_AttendeeList.clear();
    }
}

bool RegistrationList::isRegistered(QString n)
{
    for(Registration *r:m_AttendeeList){
        if(r->getAttendee().getName() == n)
        {
            return true;
        }
    }
    return false;

}

double RegistrationList::totalFee(QString t)
{
    double total = 0.0;

    for(Registration *registration: m_AttendeeList)
    {
        if((t == "Registration" && dynamic_cast<const Registration*>(registration)) ||
             (t == "GuestRegistration" && dynamic_cast<const GuestRegistration*>(registration)) ||
            (t == "StudentRegistration" && dynamic_cast<const StudentRegistration*>(registration)) ||
            (t == "All"))
        {
            total += registration->calculateFee();
        }
    }

    return total;
}

int RegistrationList::totalRegistration(QString a)
{
    int count = 0;

    for(Registration *registration: m_AttendeeList)
    {
        if(registration->getAttendee().getAffiliation() == a)
        {
            count++;
        }
    }
    return count;
}


RegistrationList::RegistrationList(QObject *parent):QObject(parent)
{

}

