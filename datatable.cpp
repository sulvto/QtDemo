#include "datatable.h"

DataTable:: DataTable(const QString &_tableName,const QString &_content){
//    *tableName =  _tableName;
//    *content = _content;
    this->setAccessibleName(_tableName);
}
QString DataTable::getTableName(){
    return *tableName;
}
