#ifndef TOOL_H
#define TOOL_H
#include <QObject>
#include <QJsonArray>
#include <QJsonObject>
#include "StudentModel.h"

class Tool : public QObject
{
    Q_OBJECT
public:
    explicit Tool(QObject* parent = nullptr);
    ~Tool();

signals:
    void loadData();
    void load(const QJsonArray arr);
private slots:
    void onLoadData();
private:
    void init();
};

#endif // TOOL_H
