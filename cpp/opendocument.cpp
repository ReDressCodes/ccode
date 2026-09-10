#include <iostream>

class StarOffice
{
	public:
		
	int calc;
	int spreadsheets;
	int base;
	int draw;
	int math;
	int writer;
	int impress;

	int calcFunction()
	{
		std::cout<<"Aid with calculations"<<std::endl;
		return calc;
	}

	int SpreadsheetsFunction()
	{
		std::cout<<"Aid with record keeping" << std::endl;
		return spreadsheets;
	}

	int baseFunction()
	{
		std::cout<<"Aid with database management"<<std::endl;
		return base;
	}

	int mathFunction()
	{
		std::cout<<"Aid with formulas and formula editing"<<std::endl;
		return draw;
	}
	
	int drawFunction()
	{
		std::cout<<"Aid with vector graphics creation and editing"<<std::endl;
		return math;
	}
	int writerFunction()
	{
		std::cout<<"Aid with word processing "<<std::endl;
		return writer;
	}

	int impressFunction()
	{
		std::cout<<"Aid with presentations " <<std::endl;
		return impress;
	}

};

class OpenOffice:public StarOffice
{
	//add something
	//
};

class LibreOffice:public OpenOffice{
	//add something
	//
};

int main(int argc, char *argv[])
{
	class LibreOffice office;

	office.calcFunction();

	return 0;
}
