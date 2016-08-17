#ifndef DOTEDITOR_H
#define DOTEDITOR_H

#include <QMainWindow>
#include <QtCore>

namespace Ui {
class DotEditor;
}

class DotEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit DotEditor(QWidget *parent = 0);
    ~DotEditor();

private slots:
    void on_pushButton_show_clicked();

private:
    Ui::DotEditor *ui;
};

#endif // DOTEDITOR_H
