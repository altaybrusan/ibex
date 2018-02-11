#ifndef RS232CONNECTOR_H
#define RS232CONNECTOR_H

#include <QObject>
#include "iconnector.h"
class QSettings;
class QSerialPort;

class RS232Connector : public QObject,IConnector
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "tr.edu.boun.IConnector")
    Q_INTERFACES(IConnector)

public:
    explicit RS232Connector(QObject *parent = nullptr);
    void UpdateConnectionSettings(const QMap<QString, QString>* settings) override;
    const QMap<QString, QString>* GetConnectionSettings() override;
    void OpenConnectionAsService() override;
    void OpenConnection() override;
    void CloseConnection() override;

signals:
    void NotifyMessage(const QString message) const  override;
    void NotifyConnectionError(const QString error) const override;
    void NotifyConnectionOpened() override;
    void NotifyConnectionClosed() override;

public slots:

private:
    QSerialPort *connection;
    QMap<QString, QString> *connectionSettings;






};

#endif // RS232CONNECTOR_H
