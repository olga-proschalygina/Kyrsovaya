// Лабораторная работа № 1. Вариант N68
// Выполнил: Прощалыгина О. А., группа ПИ-53.
#include <iostream>
using namespace std;
// ===== Расчётные функции варианта =====
// Площадь прямоугольника со сторонами a и b
double rectangleArea(double a, double b) {
	return a * b;
}
// Периметр прямоугольника со сторонами a и b
double rectanglePerimeter(double a, double b) {
	return 2 * (a + b);
}
// Диагональ прямоугольника со сторонами a и b
double rectangleDiagonal(double a, double b) {
	return sqrt(a * a + b * b); // не забудьте #include <cmath>
}
// ===== Главная функция: меню =====
int main() {
	int choice;
	double a, b;
	do {
		cout << "\n=== Вариант N: расчёты для прямоугольника ===\n";
		cout << "1. Площадь\n";
		cout << "2. Периметр\n";
		cout << "3. Диагональ\n";
		cout << "0. Выход\n";
		cout << "Выберите пункт: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Введите стороны a и b: ";
			cin >> a >> b;
			cout << "Площадь = " << rectangleArea(a, b) << "\n";
			break;
		case 2:
			cout << "Введите стороны a и b: ";
			cin >> a >> b;
			cout << "Периметр = " << rectanglePerimeter(a, b) << "\n";
			break;
		case 3:
			cout << "Введите стороны a и b: ";
			cin >> a >> b;
			cout << "Диагональ = " << rectangleDiagonal(a, b) << "\n";
			break;
		case 0:
			cout << "Работа завершена.\n";
			break;
		default:
			cout << "Такого пункта нет.\n";
		}
	} while (choice != 0);
	return 0;
}