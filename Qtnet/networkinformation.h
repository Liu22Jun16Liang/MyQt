#ifndef NETWORKINFORMATION_H
#define NETWORKINFORMATION_H

#include<QWidget>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QGridLayout>
#include<QMessageBox>
#include<QHostInfo>
#include<QNetworkInterface>


class networkinformation : public QWidget
{
    Q_OBJECT

public:
    networkinformation(QWidget *parent = nullptr);
    ~networkinformation();
    void getHostInformation();

public slots:
    void slotDetail();


private:
    QLabel *hostLabel;
    QLineEdit *LineEditLocalHostName; //主机名的显示相关
    QLabel *ipLabel;
    QLineEdit *LineEditAddress; //IP地址相关
    QPushButton *detailBtn; //详细 按钮
    QGridLayout *mainLayout; //网格布局
};
#endif // NETWORKINFORMATION_H
