#include "networkinformation.h"

networkinformation::networkinformation(QWidget *parent)
    : QWidget(parent)
{
    hostLabel=new QLabel(tr("主机名:"));
    LineEditLocalHostName= new QLineEdit;
    ipLabel=new QLabel(tr("IP地址:"));
    LineEditAddress =new QLineEdit;

    detailBtn=new QPushButton(tr("详细"));

    mainLayout= new QGridLayout(this);
    mainLayout->addWidget(hostLabel,0,0);
    mainLayout->addWidget(LineEditLocalHostName,0,1);

    mainLayout->addWidget(ipLabel,1,0);
    mainLayout->addWidget(LineEditAddress,1,1);
    mainLayout->addWidget(detailBtn,2,0,1,2); //后两个参数的意思：控件跨越1个行，控件跨越2个列
    //至此，只是完成了布局的设计。

    getHostInformation();
    connect(detailBtn,SIGNAL(clicked()),this,SLOT(slotDetail())); //

}

networkinformation::~networkinformation() {}


void networkinformation::getHostInformation() //获取主机信息
{
    QString localHostName = QHostInfo::localHostName(); //
    LineEditLocalHostName->setText(localHostName);//
    QHostInfo hostInfo= QHostInfo::fromName(localHostName);// 获取除主机名之外的其他很多信息
    QList<QHostAddress> listAddress = hostInfo.addresses();//
    if(!listAddress.isEmpty())//
    {
        LineEditAddress->setText(listAddress.first().toString());//
    }
}

void networkinformation::slotDetail()// 获得与网络接口相关的信息
{

    QString detail="";//
    QList<QNetworkInterface> list=QNetworkInterface::allInterfaces();//
    for(int i=0;i<list.count();i++)//
    {
        QNetworkInterface interface=list.at(i);//
        detail=detail+tr("设备: ")+interface.name()+"\n";//
        detail=detail+tr("硬件地址: ")+interface.hardwareAddress()+"n";//
        QList<QNetworkAddressEntry> entryList=interface.addressEntries();//
        for(int j=0;j<entryList.count();j++)//
        {
            QNetworkAddressEntry entry=entryList.at(j);//
            detail=detail+"\t"+tr("IP地址: ")+entry.ip().toString()+"\n";//
            detail=detail+"\t"+tr("子网掩码: ")+entry.netmask().toString()+"\n";//
            detail=detail+"\t"+tr("广播地址: ")+entry.broadcast().toString()+"\n";//
        }
    }
    QMessageBox::information(this,tr("Detail"),detail);//
}
