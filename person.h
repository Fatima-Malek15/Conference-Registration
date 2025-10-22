#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <QString>

using namespace std;

class Person
{
public:
    Person();
    Person(QString n, QString a, QString e);
    QString getName() const;
    QString getAffiliation() const;
    QString getEmail() const;
    QString toString() const;

private:
    QString m_Name;
    QString m_Affiliation;
    QString m_Email;
};

#endif // PERSON_H
