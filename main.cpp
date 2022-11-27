#include "lexique.hpp"

int main() {
  std::cout << "Hello World!\n";
  Lexique dico("Test");
  string content;
  const string path = "tp1-Lexique-fichiers/lesMiserables_A.txt";
  readFileIntoString(path, content);
  dico.miseEnForme(content);
  dico.afficherLexique();
  string l_path = "test.txt";
  dico.ecrireDansFichier(l_path);
}