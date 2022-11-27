#include "lexique.hpp"

int main() {
  std::cout << "Hello World!\n";
  Lexique dico("Test");
  string content;
  const string l_path = "test.txt";
  const string l_path_sup = "test_sup.txt";
  const string path = "tp1-Lexique-fichiers/lesMiserables_A.txt";

  // Test ajout d'un texte
  readFileIntoString(path, content);
  dico.miseEnForme(content);
  dico.afficherLexique();
  dico.ecrireDansFichier(l_path);
  std::cout << dico.getTaille() << std::endl;

  // Test suppression
  dico.supprimerMot("cosette");
  dico.afficherLexique();
  dico.ecrireDansFichier(l_path_sup);

  std::cout << dico.getTaille() << std::endl;
}