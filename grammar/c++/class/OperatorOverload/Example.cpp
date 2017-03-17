#include <iostream>
using namespace std;

class Point{
	public :
		int x;
		int y;

		//Point(int _x, int _y);
		explicit Point(int _x, int _y);
		const void Print();
		const Point operator+(Point arg);
		const Point operator++();
		const Point operator++(int);
		const Point operator--();
		const Point operator--(int);
		const bool operator==(const Point arg);
		const bool operator!=(const Point arg);

		const void operator()(int arg);
		const void operator()(int arg, string sarg);

		const int operator[](int index);

		operator int() const ;

};


Point::Point(int _x =0, int _y =0) : x(_x), y(_y){

}

void const Point::Print(){
	cout << x << "," << y << endl;
}
const Point Point::operator+(Point arg){
	cout << "call operator+() " << endl;
	Point pt;
	pt.x = this->x + arg.x ;
	pt.y = this->y + arg.y ;
	return pt;
}

const Point Point::operator++(){
	x++;
	y++;
	return *this;
}

const Point Point::operator++(int){
	Point pt(x,y);
	x++;
	y++;
	return pt;
}

const Point Point::operator--(){
	x--;
	y--;
	return *this;
}

const Point Point::operator--(int){
	Point pt(x,y);
	x--;
	y--;
	return pt;
}

const bool Point::operator==(const Point arg){
	return x ==arg.x && y== arg.y ? true:false;
}

const bool Point::operator!=(const Point arg){
	return !(*this == arg); 
}


const Point operator+(int x, Point arg){
	Point pr(arg.x+x, arg.y+x);
	return pr;
}

const void Point::operator()(int arg){
	cout << "operator (). arg : " << arg << endl;
}

const void Point::operator()(int arg, string sarg){
	cout << "operator (). arg : " << arg  << ", sarg : " << sarg << endl;
}

const int Point::operator[](int index){
	cout << "call const operator[] " << endl;
	if(index == 0){
		return x;
	}else if(index == 1){
		return y;
	}else {
		throw "out of range error!";
	}
}


Point::operator int() const {
	cout << "call operator int() " << endl;
	return x;
}

class SmartPoint{
	private : 
		Point* ptr;

	public :
		SmartPoint(Point *p);
		Point* operator->();
		Point& operator*();
		~SmartPoint();
};

SmartPoint::SmartPoint(Point *p): ptr(p){
	cout << "Point p to smart pointer" << endl;
}

SmartPoint::~SmartPoint(){
	cout << "remove Point p by smart pointer" << endl;
	delete ptr;
}

Point* SmartPoint::operator->(){
	return ptr;
}

Point& SmartPoint::operator*(){
	return *ptr;
}

int main(){
	Point p1(2,3) , p2(5,5);
	Point p3;
	p3 = p1 + p2; //same as p1.operator+(p2)
	p3.Print();
	
	cout << "=== operator+ ===" << endl;
	Point p4;
	p4 = p1.operator+(p2);
	p4.Print();

	//operator ++ test
	cout << "=== operator++, operator++(int) ===" << endl;
	Point p5(2,3) , p6(2,3);
	Point p7,p8;
	p7 = p5++;
	p8 = ++p6;

	p7.Print();
	p5.Print();
	cout << endl;
	p8.Print();
	p6.Print();

	//operator -- test
	cout << "=== operator--, operator--(int) ===" << endl;
	Point p9(2,3) , p10(2,3);
	Point p11,p12;
	p11 = p9--;
	p12 = --p10;

	p11.Print();
	p9.Print();
	cout << endl;
	p12.Print();
	p10.Print();

	//operator == test
	cout << "=== operator== ===" << endl;
	if(p11 != p9){
		cout << "p11 != p9 " << endl;
	}if(p12 != p10) {
		cout << "p12 != p10 " << endl;
		
	}

	//global operator+
	cout << "=== global operator+ ===" << endl;
	Point p13;
	p13 = 10 + p9;
	p13.Print();

	//operator ()
	cout << "=== operator() ===" << endl;
	Point pt1;
	pt1(100);
	pt1(100,"test");

	pt1.operator()(10);
	Point()(10);
	Point().operator()(10);

	//operator[]
	cout << "=== operator [] ===" << endl;
	Point pt2(10,20);
	cout << "[0] : " << pt2[0] << ", [1] : " << pt2[1] << endl;

	//operator-> (smart pointer)
	cout << "=== smart pointer ===" << endl;
	SmartPoint sp1 = new Point(2,3);
	SmartPoint sp2 = new Point(5,5);
	Point* pp1 = new Point(2,3);

	sp1->Print();  //sp1.operator->()->Print()
	pp1->Print();  //pp1.Print();

	(*pp1).Print();  //(*pp1).Print()
	(*sp1).Print();  // sp1.operator*().Print()

	delete pp1;

	//explicit
	cout << "=== explicit ===" << endl;
	Point exp;
	//exp = 10;  //without explict, compiler convert this as Point(10,0);  
	exp.Print();

	//operator int()
	cout << "=== operator int () ===" << endl;
	int z;
	Point intx(10,10);
	z = intx;
	cout << "z : " << z << endl;
	return 0;
}
