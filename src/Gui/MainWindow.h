#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

#include "Core/Board.h"
#include "Core/GameMaster.h"
#include "Gui/Windows/RulesWindow.h"
#include "Gui/ActionPanel.h"
#include "Gui/BoardArea.h"
#include "Gui/PlayerWindow.h"

class GameMaster;
class BoardArea;
class PlayerWindow;
class ActionPanel;

class MainWindow : public QMainWindow {
	Q_OBJECT;
public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	ActionPanel * actionPanel();
	BoardArea * boardArea();
	PlayerWindow * playerWindow();

	void setBoard(Board *board);
	void setGameMaster(GameMaster *gameMaster);
	void changeDate(int day, int week);

private slots:
	void displayRules();

private:
	QGraphicsView *graphicsView;
	QGroupBox *panel;

	QMenu *menuGame;
	QMenu *menuView;
	QMenu *menuHelp;
	QLabel *dateDisplay;

	ActionPanel *actionPanel_;
	BoardArea *boardArea_;
	PlayerWindow *playerWindow_;
	RulesWindow *rulesWindow_;
};

#endif
