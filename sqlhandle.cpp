#include "sqlhandle.h"

sqlHandle::sqlHandle()
{

}

int sqlHandle::connectDB()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("universitydb");
    db.setUserName("root");
    db.setPassword("RMahadule7");
    bool ok = db.open();

    if (ok)
        qDebug()<<"DATABASE CONNECTED.";
    else
        qDebug()<<"FAILED TO CONNECT.";

    return ok;
}

int sqlHandle::disconnectDB()
{
    QSqlDatabase db;
    db = QSqlDatabase::database();

    db.close();

    bool ok = db.isOpen();

    if(ok)
        qDebug()<<"DATABASE IS OPEN.";
    else
        qDebug()<<"DATABASE DISCONNECTED.";

    return ok;
}

int sqlHandle::createTable()
{
    int ok = 0;

    QSqlQuery query;

    query.prepare("CREATE TABLE IF NOT EXISTS tb_student(id integer primary key auto incremented,fname varchar(255),lname varchar(255))");

    if(query.exec())
    {
        ok = 1;
        qDebug()<<"Table created.";
    }
    else
    {
        qDebug()<<"Failed to create table."<<query.lastError();
    }

    return ok;

}

int insertStudent(const QString& fname,const QString& lname,
                  const QString& state,const QString& city,
                  const QString& ssc,const QString& hsc,
                  const QString& leaving,const QString& gap,
                  const QString& eligibility,const QString& migration,
                  const QString& hscm,const QString& sscm)
{
    int ok = 0;
    QSqlQuery query;
    query.prepare("INSERT INTO tbl_student(fname,lname,state,city,ssc,hsc,leaving,gap,eligibility,migration,hscm,sscm) VALUES(:fname,:lname,:state,:city,:ssc,:hsc,:leaving,:gap,:eligibility,:migration,:hscm,:sscm)");
    query.bindValue(":fname",fname);
    query.bindValue(":lname",lname);
    query.bindValue(":state",state);
    query.bindValue(":city",city);
    query.bindValue(":ssc",ssc);
    query.bindValue(":hsc",hsc);
    query.bindValue(":leaving",leaving);
    query.bindValue(":gap",gap);
    query.bindValue(":eligibility",eligibility);
    query.bindValue(":migration",migration);
    query.bindValue(":hscm",hscm);
    query.bindValue(":sscm",sscm);
    if(query.exec())
    {
        ok = 1;
    }
    else
    {
        qDebug()<<"ERROR INSERTING."<<query.lastError();
    }

    return ok;
}
