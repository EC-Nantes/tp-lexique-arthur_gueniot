#include "lexique.hpp"

/**
Création d'un lexique
*/
Lexique::Lexique(string nom) { this->nom = nom; }

/**
Getteur pour la variable nom de l'objet
*/
string Lexique::getNom() const { return this->nom; }

/**
Getteur pour la variable taille du lexique
*/
int Lexique::getTaille() const { return this->mots.size(); }

/**
NON UTILISE / Ajouter un texte au lexique
*/
void Lexique::ajouterTexte(const vector<string> &liste_mot) {
  for (auto it = liste_mot.begin(); it != liste_mot.end(); ++it) {
    if (Lexique::ajouterMot(*it) == false) {
      cout << "Erreur dans l'ajout du mot" << endl;
    }
  }
}

/** Ajouter un nouveau mot au lexique ou incrémenter la valeur si elle existe
 * déjà
 */
bool Lexique::ajouterMot(string nom) {
  // this->mots[nom] = val;
  // Insérer un nouveau mot
  if (this->mots.insert(std::pair<string, int>(nom, 1)).second == true) {
    return true;
  } else {
    this->incrementerOccurence(nom);
    return false;
  }
}

/**
Supprimer un mot du lexique
*/
void Lexique::supprimerMot(string nom) { this->mots.erase(nom); }

/**
Incrémenter un nom : fonction pas forcément nécessaire
*/
void Lexique::incrementerOccurence(string nom) { this->mots[nom] += 1; }

/**
Vérifie l'existence d'un mot dans la liste
*/
bool Lexique::exist(string nom) {
  map<string, int>::iterator it;

  it = this->mots.find(nom);
  if (it != this->mots.end()) {
    return true;
  } else {
    return false;
  }
}

/**
Mettre en forme le texte lu dans un fichier avec la suppression de la
ponctuation et la mise de l'ensemble du texte en minuscule
*/
void Lexique::miseEnForme(string &content) {
  char *pch, *str;
  str = &content[0];
  const char *delimiters = " ,.-!(){}=+[]'\"&\\:/*;?<>_\n\t|     ";
  pch = strtok(str, delimiters);
  while (pch != NULL) {
    string mot = pch;
    // std::cout<<" mot avant traitement"<< mot<<std::endl;
    toLower(mot);
    remove_punctuation(mot);
    // std::cout<<" mot après traitement"<< mot<<std::endl;
    ajouterMot(mot);
    pch = strtok(NULL, delimiters);
  }
}

/**
Afficher le lexique dans la console
*/
void Lexique::afficherLexique() {
  for (map<string, int>::iterator it = this->mots.begin();
       it != this->mots.end(); ++it) {
    cout << it->first << " : " << it->second << endl;
  }
}

/**
  Surcharge de l'opérateur d'affichage pour afficher l'ensemble du lexique
*/
// ostream &operator<<(ostream &os, const pair<string, int> &pair) {
//   os << pair.first << " : " << pair.second;
//   return os;
// }

/**
  Enregistrer le lexique dans un fichier
*/
void Lexique::ecrireDansFichier(const string &path) {
  fstream output_file(path, ios::out);
  if (!output_file.is_open()) {
    cerr << "Could not open the file - '" << path << "'" << endl;
    exit(EXIT_FAILURE);
  }
  for (map<string, int>::iterator it = this->mots.begin();
       it != this->mots.end(); ++it) {
    output_file << it->first << " : " << it->second << "\n";
  }
  // Afficher la taille en fin de fichier
  output_file << this->getTaille() << "\n";
  output_file.close();
}