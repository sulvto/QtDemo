#ifndef CONNECTIONSDIALOG
#define CONNECTIONSDIALOG

#include <QtGui>
#include <QDialog>

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;

class ConnectionsDialog : public QDialog
{
        Q_OBJECT

public:
        ConnectionsDialog(QWidget *parent = 0);
        ~ConnectionsDialog();
signals:
        void findNext(const QString &str, Qt::CaseSensitivity cs);
        void findPrevious(const QString &str, Qt::CaseSensitivity cs);
private slots:
        void findClicked();
        void enableFindButton(const QString &text);
private:
        QPushButton *connectButton ;
        QPushButton *cancelButton;
};
#endif // CONNECTIONSDIALOG

