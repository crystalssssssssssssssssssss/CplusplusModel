import QtQuick 2.4
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.2

Item {
    height: 20
    property alias stuidNo: id1.text //id
    property alias stuname: name.text //姓名
    property alias stusex: sex.text //性别
    property alias stuage: age.text //年纪
    property alias stuschool: school.text //学校
    property alias stustuNo: stuNo.text //学号
    signal dataclick

    RowLayout {
        spacing: 20
        Label {
            id: id1
            color: "red"
            text: "1"
            MouseArea {
                anchors.fill: parent

                Connections {
//                    onClicked: dataclick()
                    function onClicked(){
                        dataclick()
                    }
                }
            }
        }
        Text {
            id: name
            text: "张三"
            color: "red"
        }

        Text {
            id: sex
            text: "男"
            color: "red"
        }
        Text {
            id: age
            text: "18"
            color: "red"
        }

        Text {
            id: school
            text: "西安电子科技大学"
            color: "red"
        }

        Text {
            id: stuNo
            text: "21031211675"
            color: "red"
        }
    }
}
