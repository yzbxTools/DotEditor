#include "doteditor.h"
#include "ui_doteditor.h"

DotEditor::DotEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DotEditor)
{
    ui->setupUi(this);
}

DotEditor::~DotEditor()
{
    delete ui;
}

void DotEditor::on_pushButton_show_clicked()
{
    QString cmd;
    QString dottxt=ui->textEdit->toPlainText();
    QString format=ui->comboBox_format->currentText();
    QString engine=ui->comboBox_engine->currentText();

    QString basename="graph";
    QString suffix=".txt";


    QFile file(basename+suffix);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out <<dottxt;

    cmd="/usr/bin/"+engine+" -T"+format+" "+basename+suffix+" -o"+basename+"."+format;
    qDebug()<<cmd;
    QProcess::startDetached(cmd);
    cmd="gnome-open "+basename+"."+format;
    qDebug()<<cmd;
    QProcess::startDetached(cmd);
}
