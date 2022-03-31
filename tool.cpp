#include "tool.h"
#include <QDebug>
Tool::Tool(QObject* parent):
    QObject(parent){
    init();
}


void Tool::init(){
    connect(this,&Tool::loadData,this,&Tool::onLoadData);
}

Tool::~Tool(){

}

void Tool::onLoadData(){
   QJsonArray arr;

   for(int i=0;i<10;i++){
       QJsonObject obj;
       obj["id"] = i;
       obj["name"] = "zs";
       obj["sex"] = "男";
       obj["age"] = 18+i;
       obj["school"] = "西电";
       obj["stuNo"] = "21031211675";
       arr.append(obj);
   }
   emit load(arr);
}
