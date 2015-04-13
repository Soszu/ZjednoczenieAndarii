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
#include "Core/Containers/Tests/Test.hpp"

#include "Core/Utils/EnumHelpers.hpp"
#include "Core/Containers/Tests/TestData.hpp"
#include "Core/Containers/Tests/BlankTest.hpp"
#include "Core/Containers/Tests/FightTest.hpp"
#include "Core/Containers/Tests/LuckTest.hpp"
#include "Core/Containers/Tests/SkillsTest.hpp"

Test * Test::createTest(const TestData & testData)
{
	switch (testData.type()) {
		case Type::Blank:
			return new BlankTest(testData.data());
		case Type::Fight:
			return new FightTest(testData.data());
		case Type::Luck:
			return new LuckTest(testData.data());
		case Type::Skills:
			return new SkillsTest(testData.data());
	}

	Q_ASSERT(false);
	return nullptr;
}

const BiHash <Test::Type, QString> Test::TypeLabels = {
	{Test::Type::Blank,           QObject::tr("Blank")},
	{Test::Type::Fight,           QObject::tr("Fight")},
	{Test::Type::Luck,            QObject::tr("Luck")},
	{Test::Type::Skills,          QObject::tr("Skills")}
};


inline uint qHash(Test::Type type)
{
	return qHash(toUnderlying(type));
}

QDataStream & operator<<(QDataStream & out, const Test::Type & type)
{
	return out << toUnderlying(type);
}

QDataStream & operator>>(QDataStream & in, Test::Type & type)
{
	return in >> toUnderlyingRef(type);
}
