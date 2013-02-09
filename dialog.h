#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    
private slots:
    void onNumberButtonClicked();
    void onPlusButtonClicked();
    void onMinusButtonClicked();
    void onClearButtonClicked();
    void onEqualButtonClicked();

private:
    Ui::Dialog *ui;    
    QString mem;
    QString operationClicked;
    void resetLineEdit();
};

#endif // DIALOG_H
