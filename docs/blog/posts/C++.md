---
date:
  created: 2025-02-22
categories:
  - C++
  - Informatique
tags:
  - c++
authors:
  - thomas
slug: c++
---

# C++ 

Cet article explique les différents éléments du language C++  

<!-- more -->

## vocabulaire

**classe** = blueprint permettant de créer des objets.  
**objet** = instance d'une classe.  
**méthode** = fonction d'une classe.  
**attribut** = variable dans une classe.  
**constructeur** = méthode d'une classe instanciant un objet.  
  
**variable globale** = une variable déclaré à l'extérieur d'une classe où fonction. Utilisable partout dans le code cpp (mais seulement le fichier cpp où elle est déclarée). Stocké dans data où bss si non initialisée.    
**variable locale** = une variable déclarée dans une fonction. Elle n'existe pas en dehors de la fonction. Lorsque la fonction se termine elle est détruite.  
**variable globale static** = visible que dans le fichier cpp où elle est déclarée.  
**variable locale static** = n'est pas stocké dans la stack mais avec les variables globales. Elle est **visible que dans la fonction dans laquelle elle est déclarée**. Conserve sa valeur entre deux appels.   
**variable dynamique** = crée quand on appelle quelquechose avec **new**. n'existe pas à la compilation, sera cére lors de l'execution du code. Stocké dans la **Heap**, n'est pas effacée automatiquement, il faut appeller un delete pour l'effacer. 

les 3 "etats" d'une fonction: explique et donne exemple
**déclaration** = dit au compileur quelles fonctions, variable et classes existent. quand on déclare une classe on déclare également ses méthodes et attributs à l'intérieur
**definition** = donne le corps de la fonctions et méthodes (ce qu'elles font)
**appel** = exécute les fonctions
  
exemple:  
```cpp
int add(int a, int b);   // Déclaration (prototype)

int add(int a, int b) {  // Définition
    return a + b;
}

int main() {
    cout << add(2, 3);   // Appel
}

```

⚠️ Attention à ne pas confondre  

|  **nom**   | **def** | **exemple** | 
|--------------|----------------------------|----------------------------------------------------------|
| **variablee**  | ce qui contient une valeur | int x = 5; | 
| **parametre** | variable locale qui permet à une fonction de recevoir une donnée externe. elle est déclarée dans la signature de la fonction | calculateTax(float localImposition);  |  
| **parametre** | variable passées à la fonction lors de son appel | calculateTax(1.7); |  
| **attribut** | variable d'une class |     |
  
⚠️ Static dans une fonction VS dans une classe.
|  **fonction**   | **class** |
|--------------|----------------------------|
| Conserve la valeur entre les appels  | Partagé entre toutes les instances |
| N'est initialisée qu'une seule fois | Peut être accédé sans objet : Classe::membre |
| Est locale en visibilité, globale en durée de vie (existe toujours quand la fonction se termine) |      | 



🔎 différentes formes du constructeur

constructeur local:  
```cpp
class Animal {      // <-- Class 
public:             // <-- Access modifier
    int legs;       // <-- Attribute

    Animal(int l) { // <-- Constructor (same name as class, NO return type!)
        legs = l;
    }

    void roar() {   // <-- Method
        // Some code here to roar
    }
};

Animal monkey(4);   // <-- Object 'monkey' created with 4 legs
```  

constructur hors classe:  
Pour ne pas surcharger la déclaration d'une classe on peut définir sont constructeur en dehors. (Attention la déclaration de classe possède bien une déclaration de constructeur mais pas de définition de constructeur)  

```cpp
// Declaration inside the header or class
class Stepper {
public:
    Stepper(); // Constructor declared
    void stepForward(); // Method declared
};
```
et en dehors de la classe on va la définir. pour se faire on utilise Stepper::Stepper() qui se lit(de droite à gauche) "c'est le constructeur Stepper() de la classe Stepper"

```cpp
// In the .cpp file:
Stepper::Stepper() { // Constructor defined outside class
    // Constructor code here
}

void Stepper::stepForward() {
    // Method code here
}

```



ce qui me perturbe c'est qu'on doit utiliser le nom de la class pour nommer le constructeur (dans sa déclaration) mais on utilise le nom que l'on veux lorsque on l'utilise ex:
Animal(int leg); //déclaration interne
Animal::Animal(int leg); //déclaration externe

Monkey(4); // création d'objet Monkey
Animal::Monkey(4)// création d'objet Monkey. -> je suis perdu es-ce que c'est juste ? quelle est la diférence

aussi les constructeur des classes sont ils utilisés pour créer des classes filles ?
les objets héritent ils des attributs et méthodes de la classe ?
et static dans tout ça ? dans une fonction c'est un mot clé pour appeler la variable que une fois je crois. dans les class c'est un attribut partagé par toutes les instances de la classe (donc les objets ?)

⚠️ Héritage   

|  **Visibilité**   | **Accessibilité par classe fille ?** | **Accessible de l'extérieur ?
** | 
|--------------|----------------------------|----------------------------------------------------------|
| **public**  | oui | oui | 
| **protected** | non | non |  
| **private** | non | non |  

🔎 Is-a VS Has-a

On utilise la question is-a / has-a pour savoir si une classe hérite d'une autre classe où possède une autre classe ou un objet d'une autre classe ??  

Is-a:
```cpp
class Vehicle {
    // common properties like speed, fuel, etc.
};

class Car : public Vehicle {
    // Car is-a vehicule because Car inherits everything from Vehicle 
};
```    
  
Has-a:
```cpp
class Engine {
    // Engine details
};

class Car {
public:
    Engine engine; // Car "has a" Engine
}; 
``` 

## utilisation de la mémoire
Après compilation, le programme est stocké dans 3 zones de la mémoire: **data**.Il y a aussi deux zones dynamiques qui se remplissent et se vident en fonction des besoins, c'est la **stack** et la **heap**. toutes les variables qui seront crées localement par des fonctions viendront dans la **stack**, les variables dynamiques créées avec new iront dans la **heap**.

**data** = les variables globales initialisées  
**BSS** (block start by symbol) = les variables globales non initialisées où = à 0.   
ex:int speed;  
**RO**(read only) = les variables constantes (celles qui ont le mot clé **const** et ne peuvent être modifées).
.Il y a aussi deux zones dynamiques qui se remplissent et se vident en fonction des besoins, c'est la **stack** et la **heap**. toutes les variables qui seront crées localement par des fonctions viendront dans la **stack** où la **heap**??

  ![zone mémoire](mkdocs/memory_adresse.png)

La zone text contient le code compilé du programme, en lecture seule.

## Stack - Heap
  
La stack et la heap occupent et se partagent le reste de la mémoire, il n'y a pas 50% réservé pour la stack et 50% pour la heap, c'est en fonction de nos besoin. on peut se retrouver dans une situation où 80% c'est de la stack et 20% de la heap. Si on a trop de variables locale on peut se retrouver en stack overflow, c'est qu'on a plus de place pour les variables locales.
La **Stack** se remplie du haut vers le bas, il faut imaginer ça comme une pile de livre dont on peut retirer que le livre au sommet de la pile. Ainsi la 1ère variable que l'on entre sera la dernière que l'on sort. A contratio, la dernière variable ajoutée est la plus accessible, on dit **LIFO** last in first out.

Chaque appelle de fonction vient remplir la stack avec ses variables locales. Chaque fonction terminé enlève les variables grâce au mot clé **return**.

## fonctions

Ce qui est important de savoir c'est **où la variable est stockée** et **où la variable est visible**

## class et objets synthaxe
on utilise le type class pour créer une class. on lui donne le nom qu'on veut.

class Animal {

}

On peut créer un objet à partir de la class en utilisant le nom de la classe comme type. Qu'es-ce que ça change par rapport à l'utilisation d'un constructeur.

Animal Singe {

};
> on a crée un objet nomé "Singe" à partir de la classe "Animal".  
> il hérite des méthode et attributs de son parent.

une autre manière de créer un objet - on dit instancier - est d'utiliser le contstructeur de la classe si elle en a un.

class Animal {
  int legs; //attribut de la classe Animal
  string roar(); //méthode de la classe
  Animal(int l) { //constructeur, il doit obligatoirement avoir le meme nom que la classe et n'a pas de type de retour
    legs = l;
  }
  
};
> voici notre classe posédant un constructeur  

Animal Singe (4); //création d'un objet singe avec 4 legs.  

Dans ce cas le constructeur était présent dans la classe. Pour gagner de la place, il arrive que l'on définisse la classe dans le fichier .h et son constructeur dans le fichier .cpp  
Ainsi le constructeur est en dehors de la classe. Voici comment on le définit:  

Animal::Animal(int l){  //se lit constructeur "Animal" de la classe animal es-ce qu'on pourait faire Animal::Singe(int l) pour créer un objet singe ?
  legs = l;
}

Maintenant si on décide que singe doit être une classe plutôt qu'un objet (mettons que les objets sont les races, ils hérite d'une class famille d'animal - singe - qui hérite elle même de la classe animal)
class Monkey : public Animal {
  //méthodes et attributs aditionelles spécifiques à la classe Monkey
};  
Ainsi Monkey hérite des méthodes et attributs de la classe animal tout en pouvant ajouter les méthodes et attributs spécifiques à sa classe


## is a / has a