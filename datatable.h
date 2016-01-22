#ifndef MAINTABLE
#define MAINTABLE
#include <QTableWidget>

class DataTable :public QTableWidget {

public:
    DataTable (const QString &_tableName,const QString &_content);
    QString getTableName();

private:
    QString *tableName;
    QString *content;
};

#endif // MAINTABLE

