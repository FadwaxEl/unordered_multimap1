#pragma once
#include<iostream>
using namespace std;
class Personne
{
private:
	string nom;
	string adresse;
	string telephone;
public:
	Personne() {};
	Personne(string n, string a, string t) {
		this->nom = n;
		this->adresse = a;
		this->telephone = t;
	}

	void print() {
		cout << "Nom :" << this->nom << endl;
		cout << "Adresse : " << this->adresse << endl;
		cout << "telephone : " << this->telephone << endl;
	}
	const string getNom() {
		return this->nom;
	}

	void Recuperer(string& adresse, string& telephone) {
		adresse = this->adresse;
		telephone = this->telephone;
	}
};
