#include <iostream>
#include <fstream>
#include <stdbool.h>
using namespace std;

#define VERSION 1.1f

std::string setName()
{
    std::string nomFichier;
    std::cout << "Entrer le nom du fichier : ";
    std::cin >> nomFichier;

    return nomFichier;
}

void createSourceFile(std::string nomFichier)
{
    std::ofstream fichier(nomFichier + ".h");

    // Vérifie si le fichier est bien ouvert
    if (fichier.is_open())
    {
        // Écrit les en-têtes d'include de base
        fichier << "#include <iostream>\n";
        fichier << "#include <string>\n\n";
        fichier << "using namespace std;\n\n";

        // Ferme le fichier
        fichier.close();
        std::cout << "Le fichier " << nomFichier << ".h a ete cree avec succes." << std::endl;
    }
    else
    {
        std::cerr << "Erreur: Impossible de créer le fichier " << nomFichier << std::endl;
    }
}

void createCppFile(bool isCreateSourceFile, std::string nomFichier)
{

    std::ofstream fichier(nomFichier + ".cpp");

    // Vérifie si le fichier est bien ouvert
    if (fichier.is_open())
    {
        // Écrit les en-têtes d'include de base
        fichier << "#include <iostream>\n";
        if (isCreateSourceFile)
        {
            fichier << "#include \"";
            fichier << nomFichier;
            fichier << ".h\"\n";
        }
        fichier << "using namespace std;\n\n";
        fichier << "int main(int argc, char **argv) {\n";
        fichier << "    // Code ici\n";
        fichier << "    cout << \"Hello, world!\" << endl;\n";
        fichier << "    return 0;\n";
        fichier << "}\n";

        // Ferme le fichier
        fichier.close();
        std::cout << "Le fichier " << nomFichier << ".cpp a ete cree avec succes." << std::endl;
    }
    else
    {
        std::cerr << "Erreur: Impossible de créer le fichier " << nomFichier << std::endl;
    }
}

void openEditor()
{
    // Ouvre automatiquement l'éditeur de code avec le dossier courant
#ifdef _WIN32
    system("code . || subl . || atom .");
#elif __APPLE__
    system("open -a 'Visual Studio Code' . || open -a 'Sublime Text' . || open -a Atom .");
#else
    system("code . || subl . || atom .");
#endif
}

float get_version()
{
    return VERSION;
}

void displayHelp()
{
    cout << "\n\nCommand create Cpp file [version " << get_version() << "]\n" << endl;
    cout << "MENU HELP : \n"
         << endl;
    cout << "Create a cpp file in your project directory : \n"
         << endl;
    cout << "write : <cmdcpp> in your command console\n" << endl;
    cout << "\t o add option : [-o] or [-open]      => open the file in your code editor" << endl;
    cout << "\t o add option : [-s] or [-source]    => create a source file linked to the .cpp file" << endl;
    cout << "\t o add option : [-h] or [-help]      => open the menu help" << endl;
    cout << "\nexample : \tcmdcpp -o " << endl;
}

int main(int argc, char **argv)
{
    bool isOpenFile = false;
    bool isHelp = false;
    bool isCreateSourceFile = false;

    // Vérifie s'il y a au moins deux arguments (nom du programme + au moins un argument)
    if (argc >= 2)
    {

        for (int i = 1; i < argc; i++)
        {

            std::string argument = argv[i];

            if (argument == "-o" || argument == "-open")
            {
                isOpenFile = true;
            }
            if (argument == "-s" || argument == "-source")
            {
                isCreateSourceFile = true;
                        }
            if (argument == "-h" || argument == "-help")
            {
                isHelp = true;
                displayHelp();
                exit(0);
            }
        }

        std::string fileName = setName();

        if (isCreateSourceFile)
        {
            createSourceFile(fileName);
        }
        createCppFile(isCreateSourceFile, fileName);
    }
    else
    {
        std::string fileName = setName();
        createCppFile(false, fileName);
    }

    if (isOpenFile)
    {
        openEditor();
    }

    return 0;
}
