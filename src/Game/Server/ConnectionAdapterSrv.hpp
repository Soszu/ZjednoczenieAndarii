/*
Copyright (C) 2014-2015 by Rafał Soszyński <rsoszynski121 [at] gmail [dot] com>
This file is part of The Chronicles Of Andaria Project.

	The Chronicles of Andaria Project is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	The Chronicles of Andaria Project is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with The Chronicles Of Andaria.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#include <QtCore>
#include "Game/Server/Strings.hpp"
#include "Core/Utils/Serial.hpp"
#include "Game/Common/ConnectionAdapter.hpp"

class ConnectionAdapterSrv : public ConnectionAdapter {
	Q_OBJECT
public:
	ConnectionAdapterSrv();
	void startListen();

public slots:
	virtual void sendMessage(Message &msg, UID recipient) const;

private:
	QTcpServer tcpServer_;
	Serial usersIDs_;
	QHash <UID, QTcpSocket *> connectedUsers_;
	QSignalMapper msgSignalMapper_;
	QSignalMapper disconnectSignalMapper_;

private slots:
	void handleNewConnection();
	void handleMessage(UID userID);
	void handleDisconnected(UID userID);

signals:
	void newUser(UID userID);
	void userDisconnected(UID userID);
};