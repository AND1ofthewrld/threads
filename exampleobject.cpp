#include "exampleobject.h"

ExampleObject::ExampleObject(QObject *parent)
    : QObject{parent}, m_message(""), m_message2("")
{

}

void ExampleObject::run()
{
    count = 0;
    while (m_running) {
        count++;
        emit sendMessage(m_message);
        qDebug() << m_message << " " << m_message2 << " " << count;
    }
    emit finished();
}

bool ExampleObject::running() const
{
    return m_running;
}

void ExampleObject::setRunning(bool newRunning)
{
    if (m_running == newRunning)
        return;
    m_running = newRunning;
    emit runningChanged();
}

QString ExampleObject::message() const
{
    return m_message;
}

void ExampleObject::setMessage(const QString &newMessage)
{
    if (m_message == newMessage)
        return;
    m_message = newMessage;
    emit messageChanged();
}

QString ExampleObject::message2() const
{
    return m_message2;
}

void ExampleObject::setMessage2(const QString &newMessage2)
{
    if (m_message2 == newMessage2)
        return;
    m_message2 = newMessage2;
    emit message2Changed();
}
