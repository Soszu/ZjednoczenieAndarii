#ifndef GRA_H
#define GRA_H
#include <QString>
#include <QColor>

static const int MAX_GRACZY = 8;
static const int MIN_GRACZY = 2;

static const quint8 LICZBA_KROLESTW = 4;
static const quint8 LICZBA_RAS = 4;
static const quint8 LICZBA_KLAS = 4;

static const quint16 MAKSYMALNY_POZIOM = 10;
static const quint16 GRANICE_POZIOMOW[]={0, 500, 1100, 1800, 2600, 3500, 4500, 5600, 6800, 8100};
static const quint8 POCZATKOWY_POZIOM = 1;
static const quint8 POCZATKOWA_REPUTACJA = 0;
static const quint8 MAX_REPUTACJA = 5;
static const quint8 POCZATKOWE_ZLOTO = 10;
static const quint8 POCZATKOWE_DOSWIADCZENIE = 0;
static const quint8 POCZATKOWE_PUNKTY_RUCHU = 10;

static const quint8 POCZATKOWA_ILOSC_MALYCH_POTOW = 2;
static const quint8 POCZATKOWE_ILOSC_DUZYCH_POTOW = 1;
static const int CZAS_TRWANIA_JEDNEGO_PRZEJSCIA = 700; //w milisekundach


static const QString KROLESTWA[LICZBA_KROLESTW] = {
	QString::fromUtf8("Ludzie"),
	"Elfy",
	"Krasnoludy",
	QString::fromUtf8("Niziołki")
};

//index nazwy rasy jest równoznaczny z wartością enumeratora Rasa, dla tej rasy
static const QString RASY[LICZBA_RAS] = {
	QString::fromUtf8("Człowiek"),
	"Elf",
	"Krasnolud",
	QString::fromUtf8("Niziołek")
};

enum Rasa
{
	czlowiek = 0,
	elf = 1,
	krasnolud = 2,
	niziolek = 3
};

//index nazwy klasy jest równoznaczny z wartością enumeratora Klasa, dla tej rasy
static const QString KLASY[LICZBA_KLAS] = {
	"Wojownik",
	"Mag",
	QString::fromUtf8("Łowca"),
	"Druid"
};

enum Klasa
{
	wojownik = 0,
	mag = 1,
	lowca = 2,
	druid = 3
};

struct IDPola
{
	int x;
	int y;
};

//index ustawienia początkowego jest równoznaczna z wartością enumeratora Rasa, dla tej rasy
static const IDPola POCZATKOWE_USTAWIENIE[LICZBA_RAS] = {
	{19,4}, //czlowiek
	{29,9}, //elf
	{15,19}, //krasnolud
	{3,9}  //niziołek
};

struct statystyka
{
	quint8 zdrowieMaks;
	quint8 regeneracja;
	quint8 atakWrecz;
	quint8 atakDystansowy;
	quint8 atakMagiczny;
	quint8 obrona;
	quint8 percepcja;
};

static const statystyka POCZATKOWE_STATYSTYKI[LICZBA_RAS][LICZBA_KLAS] = {
	{{15,2,10,3,1,10,1},	//Człowiek wojownik:
	{11,3,2,1,11,7,4},	//Człowiek mag
	{13,3,5,9,1,8,7},	//Człowiek łowca
	{13,4,2,2,7,10,3}},	//Człowiek druid:

	{{15,2,10,5,1,10,1},	//Elf wojownik
	{11,3,2,1,11,7,4},	//Elf mag
	{13,3,5,9,1,8,7},	//Elf łowca
	{13,4,2,2,7,9,3}},	//Elf druid

	{{15,2,10,5,1,10,1},	//Krasnolud wojownik
	{11,3,2,1,11,7,4},	//Krasnolud mag
	{13,3,5,9,1,8,7},	//Krasnolud łowca
	{13,4,2,2,7,9,3}},	//Krasnolud druid

	{{15,2,10,5,1,10,1},	//Niziołek wojownik
	{11,3,2,1,11,7,4},	//Niziołek mag
	{13,3,5,9,1,8,7},	//Niziołek łowca
	{13,4,2,2,7,9,3}}	//Niziołek druid
};

enum RodzajPrzedmiotu
{
	helm,
	zbrojaLekka,
	zbrojaCiezka,
	bronJednoreczna,
	bronDwureczna,
	tarcza,
	artefakt
};

static const quint8 LICZBA_MOZLIWYCH_KOLOROW = 9;
static const QString MOZLIWE_KOLORY[] = {
	"Zielony",
	"Czerwony",
	QString::fromUtf8("Żółty"),
	"Niebieski",
	"Czarny",
	QString::fromUtf8("Biały"),
	QString::fromUtf8("Błękitny"),
	"Fioletowy",
	"Szary"
};

static const QColor KOLORY[]= {
	Qt::green,
	Qt::red,
	Qt::yellow,
	Qt::blue,
	Qt::black,
	Qt::white,
	Qt::cyan,
	Qt::magenta,
	Qt::gray
};

//index nazwy akcji jest równoznaczny z wartością enumeratora Akcja, dla tej akcji
enum Akcja
{
	koniecTury = 0,
	testowa = 1
};

static const QString AKCJE[] = {
	QString::fromUtf8("Zakończ turę"),
	"Akcja testowa"
};

//modyfikatory służące do przesuwania pionków jeśli kilka stoi na tym samym polu
struct modyfikator{
	int x;
	int y;
};
static const int LICZBA_PRZEWIDZIANYCH_MODYFIKATOROW = 9;
static const modyfikator MODYFIKATORY_POZYCJI[LICZBA_PRZEWIDZIANYCH_MODYFIKATOROW]= {
	{0,0}, {0, -1}, {-1, 1}, {1, 1}, {-1, -1}, {1, -1}, {0, 1}, {-1, 0}, {1, 0} };

#endif // GRA_H
