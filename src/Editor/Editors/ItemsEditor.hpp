﻿/*
Copyright (C) 2014-2015 by Rafał Soszyński <rsoszynski121 [at] gmail [dot] com>
Copyright (C) 2015 by Bartosz Szreder <szreder [at] mimuw [dot] edu [dot] pl>
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

class ItemModel;
class EffectsListEdit;
class EnumEdit;

class ItemsEditor : public QWidget {
	Q_OBJECT

public:
	ItemsEditor(ItemModel *itemModel, QWidget *parent = nullptr);
	void loadFromStream(QDataStream& in);
	void saveToStream(QDataStream& out) const;
	bool isChanged() const;

public slots:
	void modelSaved();

private:
	static const int SpinBoxWidth = 50;

	QLayout * createEditPart();
	QLayout * createViewPart();
	void initLayout();
	void initMapper();
	void setEditWidgetsEnabled(bool enabled);

	ItemModel * const itemModel_;
	QDataWidgetMapper * const itemMapper_;

	//--- Item name ---
	QLineEdit *nameEdit_;
	EnumEdit *typeEdit_;
	EnumEdit *qualityEdit_;
	QSpinBox *priceEdit_;
	EffectsListEdit *effectsEdit_;

	//--- Item list---
	QListView *itemsList_;
	QPushButton *addItemButton_;
	QPushButton *removeItemButton_;

private slots:
	void addItem();
	void removeItem();
	void selectionChanged();
};