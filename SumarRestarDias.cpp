#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

string MonthsName[12] = {"enero","febrero","marzo","abril","mayo","junio","julio","agosto","septiembre","octubre","novimebre","diciembre"};

int GetNumbersDayOfMonth(int month, int year);
bool IsBisiesto(int year);

class Date{
public:
	int day;
	int month;
	int year;
public:
	/*CONTRUCTORRES*/ 
	Date(int _day, int _month, int _year);
	Date();

	void showDate();
};

 /* CONSTRUCTORES DE LA CLASE DATE */
Date::Date(int _day, int _month, int _year){
	day = _day;
	month = _month;
	year = _year;
}

Date::Date(){
	struct tm *Time;

	time_t systemDate;
	time(&systemDate);
	Time = localtime(&systemDate);

	day = Time->tm_mday;
	month = Time->tm_mon + 1;
	year = Time->tm_year + 1900;
}
 /* METODOS DE LA CLASE DATE*/
void Date::showDate(){
	cout << day << " de " << MonthsName[month-1] << " del " << year <<endl;
}

/*SOBRECARGA DE OPERADORES*/
Date& operator +(const Date &date, int &DayToSum){	

	int year 	= date.year;
	int month 	= date.month;
	int day 	= date.day;

	while(DayToSum > 0){
		if( day + DayToSum > GetNumbersDayOfMonth(month - 1, year) ){
			DayToSum = (day + DayToSum) - GetNumbersDayOfMonth(month - 1, year);
			day =  0;
			month++;
			if( month > 11 ){
				month = 0;
				year++;
			}
		}
		else{
			day = day + DayToSum;
			DayToSum = 0;
		} 
			
	}

	return *( new Date(day, month, year) );

}

Date& operator -(const Date &date, int &DayToSubtract){

	int year 	= date.year;
	int month 	= date.month;
	int day 	= date.day;

	while(DayToSubtract > 0 ){

		day = day - DayToSubtract;
		DayToSubtract = 0;
		if(day < 0){
			month--;
			if(month < 0){
				month = 11;
				year--;
			}

			DayToSubtract = abs(day);
			day = GetNumbersDayOfMonth(month - 1, year);
		}
	}

	return *( new Date(day, month, year) );
}

void SubtractOrSumDay(const Date &date, Date &result){

	int option;
	int Days;

	cout << "Elija una opción: " << endl;
	cout << "1) Sumar dias."<<endl;
	cout << "2) Restar dias."<<endl;
	cout << "Option : ";
	cin >> option;
	switch(option){
		case 1:
			cout << "Ingrese cantidad de Dias: ";
			cin >> Days;
			result = date + Days; 
		break;
		case 2:
			cout << "Ingrese cantidad de Dias: ";
			cin >> Days;
			result = date - Days;
		break;
	}
}


int GetNumbersDayOfMonth(int month, int year){

	switch(month){
		case 0:
		case 2:
		case 4:
		case 6:
		case 7:
		case 9:
		case 11:
			return 31;
		break;
		case 3:
		case 5:
		case 8:
		case 10:
			return 30;
		break;
		case 1:
			return IsLeapYearint(year)?29:28;
		break;
		default:
		break;
	}

}

bool IsLeapYearint(year){
	if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    	return true;
    return false;
}



int main(int argc, char const *argv[])
{

	int Opt;
	Date ResultDate;

	cout << "Elija una opción: " << endl;
	cout << "1) Ingresar fecha."<<endl;
	cout << "2) Fecha actual."<<endl;
	cout << "Option : ";
	cin >> Opt;

	if(Opt == 1){
		int day;
		int month;
		int year;
		cout << "Dia: "; cin >> day;
		cout << "Mes: "; cin >> month;
		cout << "Annio: "; cin >> year;
		Date dat(day, month, year);
		SubtractOrSumDay(dat, ResultDate);
		dat.showDate();	
		r.showDate();	
	}
	else{
		Date dat;
		SubtractOrSumDay(dat, ResultDate);
		dat.showDate();	
		r.showDate();		
	}
		
	return 0;
}