import QtQuick 2.4
import QtQuick.Window 2.15
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.2
import Com.Lc.Classes 1.0
import "./util.js" as JS
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("ModelTest")
    signal sendLoad()



//        ListView
//            id: listView
//            width: parent.width
//            height: parent.height{


//            model: $Model

//            delegate: StudentItem{
//                width: parent.width
//                stuidNo:id
//                stuname:name
//                stusex:sex
//                stuage:age
//                stuschool:school
//                stustuNo:stuNo
//            }

//            delegate: Rectangle{
//                width: listView.width
//                height: listView.height/20
//                RowLayout{
//                    Text {
//                        id: stuid
//                        text: id
//                    }
//                    Text {
//                        id: stuname
//                        text: name
//                    }
//                    Text {
//                        id: stusex
//                        text: sex
//                    }
//                    Text {
//                        id: stuage
//                        text: age
//                    }
//                    Text {
//                        id: schoolName
//                        text: school
//                    }
//                    Text {
//                        id: stuNumber
//                        text: stuNo
//                    }
//                }


//            }


//            ScrollBar.vertical: ScrollBar {}
//        }




        Component.onCompleted:{
          console.log("222")
          sendLoad()
        }

        onSendLoad: {
          console.log("4444")
          tool.loadData()
//          let jsonarr = [
//                  {"id":1,"name":"lc1","sex":"男","age":18,"school":"xidian","stuNo":"111"},
//                  {"id":2,"name":"lc2","sex":"男","age":18,"school":"xidian","stuNo":"111"},
//                  {"id":4,"name":"lc3","sex":"男","age":18,"school":"xidian","stuNo":"111"}]
//          $Model.setStudent(jsonarr)
//            StudentModel.setStudent(jsonarr)
        }

        ColumnLayout{
            width: parent.width
            height: parent.height
            ListModelUI{
                id:listModel
                width: parent.width
                height: parent.height
            }

        }
        RowLayout{
            x:300
            Button{
                id: insertBtn
                highlighted: true
                text:"添加学生"
                onClicked: {
                    let json = {}
                    json['id'] = 111
                    json['name'] = '牛逼'
                    json['sex'] = '男'
                    json['age'] = 90
                    json['school'] = '复旦大学'
                    json['stuNo'] = '2001001'
                    let index = $Model.rowCount()
                   $Model.insertStudent(json,index) //默认在末尾空行增加数据项
                }
            }
            Button{
                id: removeBtn
                highlighted: true
                text:"移除学生"
                onClicked: {
                    let index = $Model.rowCount()-1 //默认移除最后一个数据项
                    $Model.removeStudent(index)
                }
            }
        }



        Tool{
            id: tool
        }

        Connections{
            target: tool
                function onLoad(arr) { //5.15以后的新语法 格式：function on信号函数(arg){}
                    JS.loadData(arr)
                }
//                onLoad: {   旧语法  。。报错：QML Connections: Implicitly defined onFoo properties in Connections are deprecated. Use this syntax instead: function onFoo(<arguments>) { ... }
//                    JS.loadData(arr)
//                }
        }



}
