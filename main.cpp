#include <iostream>
#include <fstream>
#include <cmath>
#include <random>
using namespace std;

float f(float x, float y) {
	return (pow(x, 2) + pow(y, 2));
}

float g(float x, float y) {
	return (exp(pow(x, 2)) + exp(pow(y, 2)));
}

float h(float x, float y) {
	return (exp(x) + exp(y));
}

void part3a() {
	int interval = 49;
	float con = (100 - 2) / (float)interval;
	float pi = 3.14159265358;
	ofstream outfile("out.csv");
	ofstream outxfile("x.csv");
	for (int i = 0; i < interval + 1; i++) {
		float theta = atan(6 / (2 + (con * i)));
		outfile << 2 * pi * (1 - cos(theta)) << ',' ;
		outxfile << (2 + (con * i)) << ',';
	}
	
}

void part3b() {
	int interval = 49;
	float con = (100 - 2) / (float)interval;
	float pi = 3.14159265358;
	ofstream outfile("outb.csv");
	ofstream outxfile("xb.csv");
	for (int i = 0; i < interval + 1; i++) {
		//float theta = atan(6 / (2 + (con * i)));
		outfile << (pi * pow(6, 2)) / (pow((2 + (con * i)), 2)) << ',';
		outxfile << (2 + (con * i)) << ',';
	}
}

void part5a() {
	srand(time(0));
	int particles = 10000;
	int runs = 1000;
	int numUnder = 0;
	float N = particles * runs;
	float avg = 0;
	float stddev = 0;
	float maxX = 1.0f;
	float maxY = 1.0f;
	float maxZ = 2.0f;
	float boxVolume = maxX * maxY * maxZ;
	float* historyRecord = new float[runs];

	for (int i = 0; i < runs; i++) {
		for (int j = 0; j < particles; j++) {
			float x = (rand() / (float)RAND_MAX) * maxX;
			float y = (rand() / (float)RAND_MAX) * maxY;
			float z = (rand() / (float)RAND_MAX) * maxZ;
			if (z <= f(x, y)) {
				numUnder++;
			}
			
		}
		avg += ((float)numUnder / (float)particles) * boxVolume;
		historyRecord[i] = ((float)numUnder / (float)particles) * boxVolume;
		numUnder = 0;
	}
	avg /= (float)runs;
	cout <<"True Mean: " << avg << endl;

	for (int i = 0; i < runs; i++) {
		stddev += pow((historyRecord[i] - avg), 2);
	}

	stddev = sqrt(stddev / N);
	cout << "Standard Deviation: " << stddev << endl;
	cout << "Number of Histories: " << N << endl;

}

void part5b() {
	srand(time(0));
	int particles = 100000;
	int runs = 500;
	int numUnder = 0;
	float N = particles * runs;
	float avg = 0;
	float stddev = 0;
	float maxX = 1.5f;
	float maxY = (5.0f / 3.0f);
	float maxZ = 10000.0f;
	float boxVolume = maxX * maxY * maxZ;
	float* historyRecord = new float[runs];

	for (int i = 0; i < runs; i++) {
		for (int j = 0; j < particles; j++) {
			float x = (rand() / (float)RAND_MAX) * maxX;
			float y = (rand() / (float)RAND_MAX) * maxY;
			float z = (rand() / (float)RAND_MAX) * maxZ;
			if (z <= g(x, y)) {
				numUnder++;
			}

		}
		avg += ((float)numUnder / (float)particles) * boxVolume;
		historyRecord[i] = ((float)numUnder / (float)particles) * boxVolume;
		numUnder = 0;
	}
	avg /= (float)runs;
	cout << "True Mean: " << avg << endl;

	for (int i = 0; i < runs; i++) {
		stddev += pow((historyRecord[i] - avg), 2);
	}

	stddev = stddev / N;
	cout << "Sigma: " << stddev << endl;
	cout << "Number of Histories: " << N << endl;

}


int main() {
	//part3a();
	//part3b();
	//part5a();
	//part5b();
	return 0;
}