//
// SmartDec decompiler - SmartDec is a native code to C/C++ decompiler
// Copyright (C) 2015 Alexander Chernov, Katerina Troshina, Yegor Derevenets,
// Alexander Fokin, Sergey Levin, Leonid Tsvetkov
//
// This file is part of SmartDec decompiler.
//
// SmartDec decompiler is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// SmartDec decompiler is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with SmartDec decompiler.  If not, see <http://www.gnu.org/licenses/>.
//

#include "LogManager.h"

#include <memory> /* unique_ptr */

#include <QtGlobal> /* qInstallMsgHandler() */

namespace nc { namespace gui {

namespace {

void myMessageHandler(QtMsgType type, const char *msg) {
    LogManager::instance()->log(type, msg);
}

} // anonymous namespace

LogManager *LogManager::instance() {
    static std::unique_ptr<LogManager> manager;

    if (!manager) {
        manager.reset(new LogManager);
        qInstallMsgHandler(myMessageHandler);
    }

    return manager.get();
}

void LogManager::log(QtMsgType type, const char *msg) {
    switch (type) {
    case QtDebugMsg:
        log(tr("[Debug] %1").arg(msg));
        break;
    case QtWarningMsg:
        log(tr("[Warning] %1").arg(msg));
        break;
    case QtCriticalMsg:
        log(tr("[Critical] %1").arg(msg));
        break;
    case QtFatalMsg:
        log(tr("[Fatal] %1").arg(msg));
        break;
    }
}

void LogManager::log(const QString &text) {
    Q_EMIT message(text);
}

}} // namespace nc::gui

/* vim:set et sts=4 sw=4: */
