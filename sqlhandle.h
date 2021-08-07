#ifndef SQLHANDLE_H
#define SQLHANDLE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include <QString>
#include <QDebug>

class sqlHandle
{
public:
    sqlHandle();
    int connectDB();
    int disconnectDB();
    int createTable();
    int insertStudent(const QString& fname,const QString& lname,
                      const QString& state,const QString& city,
                      const QString& ssc,const QString& hsc,
                      const QString& leaving,const QString& gap,
                      const QString& eligibility,const QString& migration,
                      const QString& hscm,const QString& sscm);
};

#endif // SQLHANDLE_H
