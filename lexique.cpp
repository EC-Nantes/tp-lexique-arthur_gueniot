#include "lexique.hpp"

Lexique::Lexique(string nom) { this->nom = nom; }

string Lexique::getNom() const { return this->nom; }

void Lexique::ajouterTexte(const vector<string> &liste_mot) {
  for (auto it = liste_mot.begin(); it != liste_mot.end(); ++it) {
    if (Lexique::ajouterMot(*it) == false) {
      cout << "Erreur dans l'ajout du mot" << endl;
    }
  }
}

bool Lexique::ajouterMot(string nom) {
  // this->mots[nom] = val;
  // Insérer un nouveau mot
  if (this->mots.insert(std::pair<string, int>(nom, 1)).second == true) {
    return true;
  } else {
    this->mots[nom] += 1;
    return false;
  }
}

void Lexique::incrementerOccurence(string nom) { this->mots[nom] += 1; }

bool Lexique::exist(string nom) {
  map<string, int>::iterator it;

  it = this->mots.find(nom);
  if (it != this->mots.end()) {
    return true;
  } else {
    return false;
  }
}

void Lexique::miseEnForme(string &content) {
  char *pch, *str;
  str = &content[0];
  const char *delimiters = " ,.-!(){}=+[]'\"&\\:/*;?<>_\n\t|     ";
  pch = strtok(str, delimiters);
  while (pch != NULL) {
    string mot = pch;
    //std::cout<<" mot avant traitement"<< mot<<std::endl;
    toLower(mot);
    remove_punctuation(mot);
    //std::cout<<" mot après traitement"<< mot<<std::endl;
    ajouterMot(mot);
    pch = strtok(NULL, delimiters);
  }
}

void Lexique::afficherLexique() {
  for (map<string, int>::iterator it = this->mots.begin();
       it != this->mots.end(); ++it) {
    cout << it->first << " : " << it->second << endl;
  }
}

// ostream &operator<<(ostream &os, const pair<string, int> &pair) {
//   os << pair.first << " : " << pair.second;
//   return os;
// }

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
  output_file.close();
}