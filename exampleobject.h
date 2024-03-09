#ifndef EXAMPLEOBJECT_H
#define EXAMPLEOBJECT_H

#include <QObject>
#include <QDebug>

class ExampleObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged)
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)
    Q_PROPERTY(QString message2 READ message2 WRITE setMessage2 NOTIFY message2Changed)
public:
    explicit ExampleObject(QObject *parent = nullptr);
    int count;
    bool running() const;
    void setRunning(bool newRunning);

    QString message() const;
    void setMessage(const QString &newMessage);

    QString message2() const;
    void setMessage2(const QString &newMessage2);

signals:
    void finished();
    void runningChanged();

    void messageChanged();

    void message2Changed();
    void sendMessage(QString message);

public slots:
    void run();
private:
    bool m_running;
    QString m_message;
    QString m_message2;
};

#endif // EXAMPLEOBJECT_H
