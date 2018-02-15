#ifndef ICONNECTOR_H
#define ICONNECTOR_H
#include <QObject>
#include <QString>
#include <QMap>

class IConnector
{

public:


    // Connectors Do not have any idea where and what is the underling
    // file format of the settings. In otherwords, a connector can not
    // read from a settings ini file neighther is allowed to write into.
    // It just get the already-read settings and can update its OWN COPY,
    // but not the central settings repository. It does not have any  function
    // like read from or write into settings file.
    virtual void UpdateConnectionSettings(const QMap<QString,QString>* settings) = 0;
    virtual const QMap<QString,QString>* GetConnectionSettings()= 0;

    // some connections may require an initial verification like security dongle
    // checking or something like that.
    template<typename U,typename V>
    U VerifyConnection(V parameter);
    // depends on parameters, different write commands may issue.
    // for example writing to port when you execute a command may differ from
    // writing to port when you are updating a device parameter.
    template<typename T>
    void WriteToConnection(const T& message, const QString parameter=0) = 0;
    template<typename V>
    V ReadFromConnection(const QString parameter=0) = 0;


    // try to open the connection in a separate thread.
    virtual void OpenConnectionAsService() = 0;
    // open the connection on the callers thread.
    virtual void OpenConnection() = 0;
    virtual void CloseConnection() = 0;


    virtual ~IConnector()
    {

    }


//inherited by all sub-classes
signals:

    virtual void NotifyMessage(const QString message) const = 0;
    // simple message as error! not best practice.
    virtual void NotifyConnectionError(const QString error) const = 0;
    virtual void NotifyConnectionOpened() = 0;
    virtual void NotifyConnectionClosed() = 0;
};


Q_DECLARE_INTERFACE(IConnector, "tr.edu.boun.IConnector")
#endif // ICONNECTOR_H
