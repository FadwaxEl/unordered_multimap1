// EXO3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include<unordered_map>
#include<queue>
#include"Personne.h"
using namespace std;
void afficher_map(unordered_map<string, Personne> Map) {
    for (auto it : Map)
    {
        cout << endl << "Key :" << it.first << endl;
        it.second.print();
    }
}
bool recuperer(unordered_map<string, Personne> Map, const string& nom, string& adresse, string& telephone) {
    for (auto it : Map)
    {
        if (it.first == nom) {
            it.second.Recuperer(adresse, telephone);
            return true;
        }
    }
    return false;
}
void afficherMAP_ordonnee(unordered_map<string, Personne> Map)
{
    priority_queue<string, vector<string>, greater<string>> queue;
    for (auto it : Map)
    {
        queue.push(it.first);
    }
    while (!queue.empty()) {
        string adresse, telephone;
        recuperer(Map, queue.top(), adresse, telephone);
        cout << "Nom : " << queue.top() << endl;
        cout << "Adresse : " << adresse << endl;
        cout << "Telephone : " << telephone << endl;
        queue.pop();
    }
}
int main()
{
    unordered_map<string, Personne> Map;
    Personne P1("Hamza", "tanger", "061879554");
    Personne P3("Khadija", "sefro", "066699555");
    Personne P2("Fadwa", "casablanca", "063333333");
    Map.insert(make_pair(P2.getNom(), P2));
    Map.insert(make_pair(P1.getNom(), P1));
    Map.insert(make_pair(P3.getNom(), P3));
    afficher_map(Map);

    string nom, adresse, telephone;
    cout << "\nEntrer le nom pour trouver les info : ";
    cin >> nom;
    bool res = recuperer(Map, nom, adresse, telephone);
    if (res == true)
        cout << endl << "Les infos de " << nom << endl 
        << "-----------> Adresse = " << adresse << "\n---------->Telephone = " << telephone << endl;
    else
        cout << endl << nom << " ne trouve pas dans le Map" << endl;

    cout << "\n\naffichage ordonnée :" << endl;
    afficherMAP_ordonnee(Map);
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
