#include "StudentModel.h"
#include <QDebug>
StudentModel::StudentModel(QObject *parent)
    :QAbstractListModel(parent)
{
}

StudentModel::~StudentModel()
{
}


int StudentModel::rowCount(const QModelIndex &parent) const{
    return m_idList.size();
}

QVariant StudentModel::data(const QModelIndex &index, int role) const{
    if(!index.isValid()){
        return QVariant();
    }
    switch (role) {
    case IdRole:
        return m_idList.at(index.row());
    case NameRole:
        return m_nameList.at(index.row());
    case SexRole:
        return m_sexList.at(index.row());
    case AgeRole:
        return m_ageList.at(index.row());
    case SchoolRole:
        return m_schoolList.at(index.row());
    case StuNumberRole:
        return m_schoolNumberList.at(index.row());
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> StudentModel::roleNames() const{
    static QHash<int, QByteArray> roles{
        {IdRole,"id"},
        {NameRole,"name"},
        {SexRole,"sex"},
        {AgeRole,"age" },
        {SchoolRole,"school"},
        {StuNumberRole,"stuNo" }
    };
    return roles;
}

//注入初始数据
void StudentModel::setStudent(const QJsonArray StudentJsonArray){
    qDebug() << "333333333";
    beginResetModel();
    m_idList.clear();
    m_nameList.clear();
    m_sexList.clear();
    m_ageList.clear();
    m_schoolList.clear();
    m_schoolNumberList.clear();
    for(int i=0;i<StudentJsonArray.size();i++){
        QJsonObject obj = StudentJsonArray.at(i).toObject();
        m_idList << obj["id"].toInt();
        m_nameList << obj["name"].toString();
        m_sexList << obj["sex"].toString();
        m_ageList << obj["age"].toInt();
        m_schoolList << obj["school"].toString();
        m_schoolNumberList << obj["stuNo"].toString();
    }
    endResetModel();
    //    emit dataChanged(index(0, 0), index(rowCount()-1, 0));
    //   qDebug() << m_idList.size();
    //   for(int i=0;i<m_nameList.size();i++){
    //       qDebug() << m_nameList.at(i).toCFString()<<m_sexList.at(i).toCFString();
    //   }
}

//增加数据
void StudentModel::insertStudent(const QJsonObject &StudentJsonobject,int &index){
    if(index <0 || index > rowCount())
        return;
    int id = StudentJsonobject.value(QLatin1String("id")).toInt();
    QString name = StudentJsonobject.value(QLatin1String("name")).toString();
    QString sex = StudentJsonobject.value(QLatin1String("sex")).toString();
    int age = StudentJsonobject.value(QLatin1String("age")).toInt();
    QString school = StudentJsonobject.value(QLatin1String("school")).toString();
    QString stuNo = StudentJsonobject.value(QLatin1String("stuNo")).toString();


    beginInsertRows(QModelIndex(),index,index); //第一个参数表示在顶级根(由于是列表结构所以表示当前列表的根）,第二个参数表示起始位置，第三个参数表示结束位置，由于只有一列，所以两者都一样
    m_idList.insert(index,id);
    m_nameList.insert(index,name);
    m_sexList.insert(index,sex);
    m_ageList.insert(index,age);
    m_schoolList.insert(index,school);
    m_schoolNumberList.insert(index,stuNo);
    endInsertRows();
}

//移除数据
void StudentModel::removeStudent(int &index){
    if(index < 0 || index > rowCount())return;
    beginRemoveRows(QModelIndex(),index,index);
    m_idList.removeAt(index);
    m_nameList.removeAt(index);
    m_sexList.removeAt(index);
    m_ageList.removeAt(index);
    m_schoolList.removeAt(index);
    m_schoolNumberList.removeAt(index);
    endRemoveRows();
}

