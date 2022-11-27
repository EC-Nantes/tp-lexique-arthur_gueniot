#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include "utilitaire.hpp"


using namespace std;

class Lexique {
  private :
    string nom;
    map<string,int> mots;

  public : 
    Lexique(string nom);

    string getNom() const;

    void ajouterTexte(const vector<string> &liste_mot);
    bool ajouterMot(string nom);
    void incrementerOccurence(string nom);
    bool exist(string nom);
    void miseEnForme(string & content);
    void afficherLexique();
    // ~Lexique();
    void ecrireDansFichier(const string &path);

    /* Surcharge de l'opérateur << */
    // friend ostream& operator<<(ostream& os, const pair<string,int> &pair);
};