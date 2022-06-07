#ifndef UILIST_H
#define UILIST_H

#include <QMainWindow>
#include <QSerialPort>



namespace Button{
const QString BOTTON_OPEN  = "Open";
const QString BOTTON_CLOSE = "Close";
const QString BOTTON_SEND  = "Send";
const QString BOTTON_CLEAR = "Clear";
}

namespace Combo{
const QString PORT_NOFOUND = "No Found";
}

namespace Log{
const QString PORTOPEN       = "Port opened.";
const QString PORTCLOSE      = "Port closed.";
const QString CANTOPEN       = "Could't open";
const QString PORT_NOFOUND   = "Port no found.";
const QString PORTISCLOSE    = "Could not send because the port is closed";
const QString CONNECT        = "Device connected.";
const QString DISCONNECT     = "Device disconnected.";
const QString ERROR_PORTLATE = "Receive interval too short!  Please add more delays.";
}

namespace Menu{
const QString MONITOR  = "Monitor";
const QString PLOTTER  = "Plotter";
const QString BINARY   = "Binary";
const QString PROPERTY = "Property";
}

#endif // UILIST_H
