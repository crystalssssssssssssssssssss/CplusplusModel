#ifndef STUDENTMODEL_H
#define STUDENTMODEL_H
#include <QAbstractListModel>
#include <QJsonObject>
#include <QJsonArray>

class StudentModel : public QAbstractListModel{
    Q_OBJECT

public:
    enum Student_Role{
        IdRole = Qt::UserRole+1, //UserRole表示合法位置的起始位置
        NameRole,
        SexRole,
        AgeRole,
        SchoolRole,
        StuNumberRole
    };

    Q_ENUM(Student_Role)

    explicit StudentModel(QObject *parent = nullptr);
    ~StudentModel();


    //重写三个方法
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
protected:
     QHash<int, QByteArray> roleNames() const override;

public slots:
     void setStudent(const QJsonArray StudentJsonArray); //初始化数据
     void insertStudent(const QJsonObject &StudentJsonobject,int &index); //添加数据
     void removeStudent(int &index); //移除数据

private:
     QList<int> m_idList;
     QList<QString> m_nameList;
     QList<QString> m_sexList;
     QList<int> m_ageList;
     QList<QString> m_schoolList;
     QList<QString> m_schoolNumberList;

     // QAbstractItemModel interface
};

#endif // STUDENTMODEL_H
