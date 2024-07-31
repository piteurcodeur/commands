
# Projet de Création de fichiers en ligne de Commande pour C/C++ :


## Introduction : 

Ce projet est un outil en ligne de commande qui permet de créer des fichiers pour les langages de programmation C et C++. 
Il est conçu pour simplifier la création de nouveaux projets et fichiers de code source.



## Création des outils : 

Télécharger les fichiers sources, puis compiler en fichier .exe avec les commandes suivantes :
```cmd
> g++ cmdc.cpp -o cmdc
```
pour la commande de fichier C     


```cmd
> g++ cmdcpp.cpp -o cmdcpp
```
pour la commande de fichier C++


Veuiller ensuite placer ces fichiers .exe dans un dossier stable et renseigner son chemin dans la variable système PATH.
Vous pourrez ainsi utiliser les commandes depuis n'importe quel terminal.



## Utilisation :
```cmd
>cmdc
```

Options supplémentaires :

```cmd
>[-h]  ou  [-help]    : Affiche l'aide et les options disponibles
>[-s]  ou  [-source]  : crée un fichier header .h du même nom que le fichier de code
>[-o]  ou  [-open]    : ouvre le fichier dans l'éditeur de code 
```
==========================================================================================================================

Exemples : 
```cmd
>> cmdc -s -o
>> Entrer le nom du fichier : example
>> Le fichier example.h a ete cree avec succes.
>> Le fichier example.c a ete cree avec succes.
```




