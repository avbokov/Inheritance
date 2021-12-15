// AbstractGeometry
#define _USE_MATH_DEFINES // должен быть в самом верху, чтобы использовать константу Пи

#include<Windows.h>
#include<iostream>
#include<conio.h>
#include<cmath>

using namespace std;

//#define CONSOLE_DRAWING

namespace Geometry
{
	enum Color
	{
		red = 0x000000FF,
		green = 0x0000FF00,
		blue = 0x00FF0000,
		yellow = 0x0000FFFF,
		white = 0x00FFFFFF,

		console_default = 0x07,
		console_blue = 0x99,
		console_green = 0x0A,
		console_red = 0xCC,
		console_yellow = 0xEE,
		console_white = 0xFF
	};
	// enum (Enumeration - или перечисление) - это набор именованных констант типа 'int'
	class Shape
	{
	protected:
		Color color;
		unsigned int line_width;
		unsigned int start_x;
		unsigned int start_y;
	public:
		void set_line_width(unsigned int line_width)
		{
			if (line_width > 120) line_width = 120;
			this->line_width = line_width;
		}
		void set_start_x(unsigned int start_x)
		{
			if (start_x < 400) start_x = 400;
			if (start_x > 800) start_x = 800;
			this->start_x = start_x;
		}
		void set_start_y(unsigned int start_y)
		{
			if (start_y < 100) start_y = 100;
			if (start_y > 500) start_y = 500;
			this->start_y = start_y;
		}
		Shape(Color color, unsigned int line_width, unsigned int start_x, unsigned int start_y) :color(color)
		{
			set_line_width(line_width);
			set_start_x(start_x);
			set_start_y(start_y);
		}
		virtual ~Shape() {}

		virtual double get_area()const = 0;			// площадь фигуры
		virtual double get_perimeter()const = 0;	// периметр фигуры
		virtual void draw()const = 0;				// любую фигуру можно нарисовать
	};

	class Square :public Shape
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side <= 0) side = 1;
			this->side = side;
		}
		Square(double side, Color color = Color::white, unsigned int line_width = 5, unsigned int start_x = 400, unsigned int start_y = 100) :Shape(color, line_width, start_x, start_y)
		{
			set_side(side);
		}
		~Square() {}

		double get_area()const
		{
			return side * side;
		}
		double get_perimeter()const
		{
			return side * 4;
		}
		void draw()const
		{
#ifdef CONSOLE_DRAWING
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < side; i++)
			{
				for (int i = 0; i < side; i++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);
#endif // CONSOLE_DRAWING

			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			/*int start_x = 400;
			int start_y = 130;*/
			::Rectangle(hdc, start_x, start_y, start_x + side, start_y + side);

			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);
		}

		void info()
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны:\t" << side << endl;
			cout << "Площадь:\t" << get_area() << endl;
			cout << "Периметр:\t" << get_perimeter() << endl;
			char key = 0;
			while (key != 27)
			{
				draw();
				if (_kbhit())key = _getch();
			}
		}
	};

	class Rectangle : public Shape
	{
		double side_A;
		double side_B;
	public:
		double get_side_A()const
		{
			return side_A;
		}
		double get_side_B()const
		{
			return side_B;
		}
		void set_side_A(double side_A)
		{
			if (side_A <= 0)side_A = 1;
			this->side_A = side_A;
		}
		void set_side_B(double side_B)
		{
			if (side_B <= 0)side_B = 1;
			this->side_B = side_B;
		}

		Rectangle(double side_A, double side_B, Color color = Color::white, unsigned int line_width = 5, unsigned int start_x = 400, unsigned int start_y = 100) :Shape(color, line_width, start_x, start_y)
		{
			set_side_A(side_A);
			set_side_B(side_B);
		}
		~Rectangle() {}

		double get_area()const
		{
			return side_A * side_B;
		}
		double get_perimeter()const
		{
			return (side_A + side_B) * 2;
		}
		void draw()const
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < side_A; i++)
			{
				for (int i = 0; i < side_B; i++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);
		}
		void info()
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны A:\t" << side_A << endl;
			cout << "Длина стороны B:\t" << side_B << endl;
			cout << "Площадь:\t" << get_area() << endl;
			cout << "Периметр:\t" << get_perimeter() << endl;
			draw();
		}
	};

	class Circle : public Shape
	{
		double radius;
	public:
		Circle(double radius, Color color = Color::white, unsigned int line_width = 5, unsigned int start_x = 400, unsigned int start_y = 100) :Shape(color, line_width, start_x, start_y)
		{
			set_radius(radius);
		}
		~Circle() {}

		void set_radius(double radius)
		{
			if (radius <= 0)radius = 1;
			this->radius = radius;
		}
		double get_radius()const
		{
			return radius;
		}
		double get_area()const
		{
			return  M_PI * radius * radius;
		}
		double get_perimeter()const
		{
			return 2 * M_PI * radius;
		}
		void draw()const
		{
			// GDI - Graphics Device Inerface (WinAPI)

			HWND hwnd = GetConsoleWindow(); // получаем окно консоли
			//HWND hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
			HDC hdc = GetDC(hwnd); // создаём контекст устройства. На этом контексте мы будем рисовать.

			HPEN hPen = CreatePen(PS_SOLID, line_width, color); // создаём карандаш
			// PS_SOLID - сплошная линия
			// 5 - это толщина линии в пикселах
			// RGB(...) - цвет
			HBRUSH hBrush = CreateSolidBrush(color);

			//цвет занимает 4 байта, по одному на цвет и альфа-канал (прозрачность)

			SelectObject(hdc, hPen); // выбираем чем и на чём будем рисовать
			SelectObject(hdc, hBrush); // выбираем чем и на чём будем рисовать

			/*int start_x = 300;
			int start_y = 270;*/
			/*int end_x = 400;
			int end_y = 370;*/

			Ellipse(hdc, start_x, start_y, start_x + 2 * radius, start_y + 2 * radius);

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Радиус кргуа:\t" << get_radius() << endl;
			cout << "Площадь круга:\t" << get_area() << endl;
			cout << "Длина окружности:\t" << get_perimeter() << endl;
			char key;
			do
			{
				draw();
				//if (_kbhit())break; //_kbhit() ожидает нажатие кливиши и возвращает ненулевое значение при ёё нажатии
				if (key = _kbhit())key = _getch();
			} while (key != 27);
		}
	};

	class Triangle :public Shape
	{
	public:
		Triangle(Color color = Color::white, unsigned int line_width = 5, unsigned int start_x = 400, unsigned int start_y = 100) :Shape(color, line_width, start_x, start_y) {}
		~Triangle() {}
		virtual double get_height()const = 0;
	};

	class EquilateralTriangle : public Triangle
	{
		double side;
	public:
		EquilateralTriangle(double side, Color color = Color::white, unsigned int line_width = 5, unsigned int start_x = 400, unsigned int start_y = 100) :Triangle(color, line_width, start_x, start_y)
		{
			set_side(side);
		}
		void set_side(double side)
		{
			if (side <= 0)side = 1;
			this->side = side;
		}
		double get_side()const
		{
			return side;
		}
		double get_height()const
		{
			return sqrt(side * side - pow(side / 2, 2));
		}
		double get_area()const
		{
			return side * get_height() / 2;
		}
		double get_perimeter()const
		{
			return 3 * side;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			/*int start_x = 400;
			int start_y = 200;*/
			const POINT verticies[] =
			{
				{start_x, start_y + side},
				{start_x + side, start_y + side},
				{start_x + side / 2, start_y + side - get_height()},
			};

			Polygon(hdc, verticies, sizeof(verticies) / sizeof(POINT));

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны: " << get_side() << endl;
			cout << "Высота треугольника: " << get_height() << endl;
			cout << "Площадь треугольника: " << get_area() << endl;
			cout << "Периметр треугольника: " << get_perimeter() << endl;
			char key;
			do
			{
				draw();
				//if (_kbhit())break; //_kbhit() ожидает нажатие кливиши и возвращает ненулевое значение при ёё нажатии
				if (key = _kbhit())key = _getch();
			} while (key != 27);
		}
	};

	class IsoscelesTriangle : public Triangle
	{
		double side;
		double base;
	public:
		IsoscelesTriangle(double side, double base, Color color = Color::white, unsigned int line_width = 5, unsigned int start_x = 400, unsigned int start_y = 100) :Triangle(color, line_width, start_x, start_y)
		{
			set_side(side);
			set_base(base);
		}
		void set_side(double side)
		{
			if (side <= 0)side = 1;
			this->side = side;
		}
		void set_base(double base)
		{
			if (base <= 0)base = 1;
			this->base = base;
		}
		double get_side()const
		{
			return side;
		}
		double get_base()const
		{
			return base;
		}
		double get_height()const
		{
			return sqrt(side * side - pow(base / 2, 2));
		}
		double get_area()const
		{
			return base * get_height() / 2;
		}
		double get_perimeter()const
		{
			return 2 * side + base;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			/*int start_x = 600;
			int start_y = 400;*/
			const POINT verticies[] =
			{
				{start_x, start_y + side},
				{start_x + base, start_y + side},
				{start_x + base / 2, start_y + side - get_height()},
			};

			Polygon(hdc, verticies, sizeof(verticies) / sizeof(POINT));

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны: " << get_side() << endl;
			cout << "Длина основания: " << get_base() << endl;
			cout << "Высота треугольника: " << get_height() << endl;
			cout << "Площадь треугольника: " << get_area() << endl;
			cout << "Периметр треугольника: " << get_perimeter() << endl;
			while (true)
			{
				draw();
			}
		}
	};
}



void main()
{
	setlocale(LC_ALL, "");

	//Shape shape(Color::console_blue);
	Geometry::Square square(150, Geometry::Color::console_blue);
	square.info();

	Geometry::Rectangle rect(5, 12, Geometry::Color::console_red);
	rect.info();

	Geometry::Circle circ(200, Geometry::Color::yellow);
	circ.info();

	Geometry::EquilateralTriangle et(200, Geometry::Color::green, 120, 200, 50);
	et.info();
	
	Geometry::IsoscelesTriangle it(200, 100, Geometry::Color::blue, 50);
	it.info();
}