#include "person.h"
#include <iostream>
#include <QDebug>

Person::Person()
{
    //null constructor
}

Person::Person(QString n, QString a, QString e)
{
    n = m_Name;
    a = m_Affiliation;
    e = m_Email;
}

QString Person::getName()
{
    return m_Name;
}

QString Person::getAffiliation()
{
    return m_Affiliation;
}

QString Person::getEmail()
{
    return m_Email;
}

QString Person::toString()
{
    return QString("The name of the person registered %1./n Email: %2/n Affiliation: %3").arg(getName(), getAffiliation(), getEmail());
}
