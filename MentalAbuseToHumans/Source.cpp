#include <iostream>
#include <utility>
using namespace std;

const float	PI = 3.1415926535897932384626433832795f;

inline float RadianToDegree(float value){
	return value * 180.f / PI;
}

void Qn1(){
	float COF;
	float length;
	float gravAccel = 9.8f;
	float time;
	cout << "COF: ";
	cin >> COF;
	cout << "length: ";
	cin >> length;
	cout << "time: ";
	cin >> time;
	const float&& a = (time * time * gravAccel) / 2.f;
	const float&& b = a * COF;
	float R = sqrtf(a * a + b * b);
	float alpha = atanf(b / a);
	cout << "Unknown angle: " << RadianToDegree(asinf(length / R) + alpha) << "\n\n";
}

void Qn2(){
	float mass;
	std::pair<float, float> sInitial;
	std::pair<float, float> initialVel;
	std::pair<float, float> F1;
	std::pair<float, float> F2;
	float time1;
	float time2;
	float time3;
	float time4;
	cout << "mass: ";
	cin >> mass;
	cout << "sInitial.x: ";
	cin >> sInitial.first;
	cout << "sInitial.y: ";
	cin >> sInitial.second;

	cout << "initialVel.x: ";
	cin >> initialVel.first;
	cout << "initialVel.y: ";
	cin >> initialVel.second;

	cout << "F1.x: ";
	cin >> F1.first;
	cout << "F1.y: ";
	cin >> F1.second;
	cout << "F2.x: ";
	cin >> F2.first;
	cout << "F2.y: ";
	cin >> F2.second;

	cout << "time1: ";
	cin >> time1;
	cout << "time2: ";
	cin >> time2;
	cout << "time3: ";
	cin >> time3;
	cout << "time4: ";
	cin >> time4;

	std::pair<float, float> accel = {F1.first / mass, F1.second / mass};
	const std::pair<float, float>&& s1 = {initialVel.first * time1 + accel.first * .5f * time1 * time1, initialVel.second * time1 + accel.second * .5f * time1 * time1};
	std::pair<float, float> finalVel = {initialVel.first + accel.first * time1, initialVel.second + accel.second * time1};

	initialVel = finalVel;
	const std::pair<float, float>&& s2 = {initialVel.first * time2, initialVel.second * time2};

	accel = {F2.first / mass, F2.second / mass};
	const std::pair<float, float>&& s3 = {initialVel.first * time3 + accel.first * .5f * time3 * time3, initialVel.second * time3 + accel.second * .5f * time3 * time3};
	finalVel = {initialVel.first + accel.first * time3, initialVel.second + accel.second * time3};

	initialVel = finalVel;
	const std::pair<float, float>&& s4 = {initialVel.first * time4, initialVel.second * time4};
	const float&& a = sInitial.first + s1.first + s2.first + s3.first + s4.first;
	const float&& b = sInitial.second + s1.second + s2.second + s3.second + s4.second;
	cout << "Ans: " << sqrtf(a * a + b * b) << "\n\n";
}

void Qn3(){
	float mass;
	float intialPos;
	float intialVel;
	float drivingForce;
	float COF;
	float gravAccel = 9.8f;
	float time;
	cout << "mass: ";
	cin >> mass;
	cout << "intialPos: ";
	cin >> intialPos;
	cout << "intialVel: ";
	cin >> intialVel;
	cout << "drivingForce: ";
	cin >> drivingForce;
	cout << "COF: ";
	cin >> COF;
	cout << "time: ";
	cin >> time;
	const float&& accel = (drivingForce + COF * mass * gravAccel) / mass;
	const float&& switchDirTime = -intialVel / accel;
	const float&& sAtSwitchDirTime = -(intialVel * intialVel) / (2 * accel);
	const float&& timeLeft = time - switchDirTime;
	cout << "Ans: " << .5f * ((drivingForce - COF * mass * gravAccel) / mass) * timeLeft * timeLeft + sAtSwitchDirTime + intialPos << "\n\n";
}

int main(){
	while(true){
		Qn1();
		Qn2();
		Qn3();
		system("pause");
		system("pause");
		system("cls");
	}
}