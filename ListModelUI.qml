import QtQuick 2.4
import QtQuick.Controls 2.15
//import Com.Lc.Classes
ListModelUIForm {
    id: student

    listView.model: $Model


    listView.delegate: StudentItem{
        stuidNo:id
        stuname:name
        stusex:sex
        stuage:age
        stuschool:school
        stustuNo:stuNo

        onDataclick: {
            console.log("我被点击了")
        }
    }




}
