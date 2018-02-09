#ifndef ICONNECTOR_H
#define ICONNECTOR_H
#include <QObject>
#include <QString>
#include <QMap>

class IConnector
{

public:

    template<typename T>
    void WriteToConnection(const T& message) = 0;

    template<typename U,typename V>
    V ReadFromDevice(const U& param) = 0;

    // Connectors Do not have any idea where and what is the underling
    // file format of the settings. In otherwords, a connector can not
    // read from a settings ini file neighther is allowed to write into.
    // It just get the already-read settings and can update its OWN COPY,
    // but not the central settings repository. It does not have any  function
    // like read from or write into settings file.
    virtual void UpdateConnectionSettings(QMap<QString,QString> settings) = 0;
    virtual QMap<QString,QString> GetConnectionSettings()= 0;


    // May be not-best practice. Because some connecction types
    // may not require any connection time out at all!
    virtual void SetConnectionTimeout(int msec)=0;



    virtual ~IConnector()
    {

    }


//inherited by all sub-classes
signals:

    void NotifyMessage(const QString message) const;
    // simple message as error! not best practice.
    void NotifyConnectionError(const QString error) const;

};


Q_DECLARE_INTERFACE(IDevice, "tr.edu.boun.IConnector")
#endif // ICONNECTOR_H
