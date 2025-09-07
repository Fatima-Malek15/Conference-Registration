#include "registrationlist.h"

RegistrationList::RegistrationList() {}

bool RegistrationList::addRegistration(Registration *r)
{
    if(r != NULL){
        m_AttendeeList.append(r->Registration());
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

bool RegistrationList::isRegistered()
{
    if(!m_AttendeeList.isEmpty())
    {
        for(Registration *r:m_AttendeeList){
            if(m_AttendeeList.contains(r->getAttendee()))
            {
                QString("Attendee %1 already registered").arg(r->getAttendee());
                return true;
            }
            else
            {
                QString("Attendee %1 not registered").arg(r->getAttendee());
            }

        }
    }
    return false;
}

double RegistrationList::totalFee(QString l)
{
    if(l == "StudentRegistration")
    {

    }
}

int RegistrationList::totalRegistration(QString a)
{

}
