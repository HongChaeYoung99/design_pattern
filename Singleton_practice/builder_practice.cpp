#include <iostream>

using namespace std;

class CEngine
{
public:
	CEngine(int mph) :mMPH(mph) {} //생성자
	int GetMPH()const { return mMPH;}

private:
	int mMPH; //엔진마력
};

class CWheel
{
public:
	CWheel(int size) : mSize(size) {} //size값으로 mSize를 초기화한다.
	int GetSize() const { return mSize; }

private:
	int mSize; //휠 사이즈
};

class CBody
{
public:
	CBody(string shape) : mShape(shape) {}
	string GetShape() const { return mShape; }

private:
	string mShape;
};

class Car
{
public:
	Car() : mEngine(NULL), mWheel(NULL), mBody(NULL) {}
	~Car() { if (mEngine) delete mEngine; if (mWheel) delete mWheel; if (mBody) delete mBody;}

public:
	void SetEngine(CEngine* engine) { mEngine = engine; }
	void SetWheel(CWheel* wheel) { mWheel = wheel; }
	void SetBody(CBody* body) { mBody = body; }
	void SetManufacturer(string m) { mManufacturer = m; }

	void print() const
	{
		cout << "제조회사 : " << mManufacturer << endl;
		cout << "엔진 마력 : " << mEngine->GetMPH() << endl;
		cout << "휠 사이즈 : " << mWheel->GetSize() << endl;
		cout << "외형 타입 : " << mBody->GetShape() << endl;
	}

private:
	CEngine* mEngine;
	CWheel* mWheel;
	CBody* mBody;
	string mManufacturer;
};

class Builder
{
public:
	virtual CEngine* GetEngine() = 0;
	virtual CWheel* GetWheel() = 0;
	virtual CBody* GetBody() = 0;
	virtual string GetManufacturer() = 0;
};

class JeepBuilder : public Builder
{
	CEngine* GetEngine() override { return new CEngine(120); }
	CWheel* GetWheel() override { return new CWheel(20); }
	CBody* GetBody() override { return new CBody("SUV"); }
	string GetManufacturer() override { return "Jeep"; }
};

class FordBuilder : public Builder
{
public:
	CEngine* GetEngine() override { return new CEngine(150); }
	CWheel* GetWheel() override { return new CWheel(18); }
	CBody* GetBody() override { return new CBody("해치백"); }
	string GetManufacturer() override { return "Food"; }
};

class Director
{
public:
	Director( Builder * builder ) : pBuilder(builder) {};
	~Director() { if (pBuilder) delete pBuilder; }

public:
	Car* construct()
	{
		Car* pCar = new Car;

		pCar->SetBody(pBuilder->GetBody());
		pCar->SetEngine(pBuilder->GetEngine());
		pCar->SetWheel(pBuilder->GetWheel());
		pCar->SetManufacturer(pBuilder->GetManufacturer());

		return pCar;
	}
private:
	Builder* pBuilder;
};


int main()
{
	Director* pDirector = new Director(new FordBuilder());
	Car* pCar = pDirector->construct();

	pCar->print();

	delete pCar;
	delete pDirector;

	return 0;
}