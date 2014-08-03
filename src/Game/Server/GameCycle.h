﻿/*
Copyright (C) 2014 by Rafał Soszyński <rsoszynski121 [at] gmail [dot] com>
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

#include <QtWidgets>

#include "Core/Containers/Player.h"
#include "Game/Server/ConnectionAdapterSrv.h"
//#include "Game/GameMaster.h"
//#include "Game/

class GameCycle : public QObject{
	Q_OBJECT
public:
	GameCycle( ConnectionAdapterSrv * connectionAdapter);
	~GameCycle();

//	GameMaster * gameMaster();
//	Board * board();

	void beginGame(QList <Player *> players);
	void showEquipment();
	void showQuests();

	ConnectionAdapterSrv * connectionAdapter();
	Player * currentPlayer();
	const QList <Player *> & players();
	int day();
	int week();

private:
	void endTurn();
	void removeCurrentPlayer();
	void init();
	void playerHasWon(Player *player);
	bool hasPlayerWon(Player *player);
	void movePlayer(int index);
	void nextPlayer();
	void newDay();

	int playersAlive_;
	int currentPlayerIdx_;
	int week_;
	int day_;

	QList <Player *> players_;
	ConnectionAdapterSrv *connectionAdapter_;

//	Board board_;
//	GameMaster gameMaster_;
signals:
	void playerChanged();
	void gameStarted();
	void statsChanged();
	void dateChanged(int day, int week);
};
