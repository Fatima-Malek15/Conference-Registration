#include "person.h"
#include <iostream>
#include <QDebug>

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
    return QString("The name of the person registered %d./n Email: %d/n Affiliation: %d").arg(getName(), getAffiliation(), getEmail());
}
