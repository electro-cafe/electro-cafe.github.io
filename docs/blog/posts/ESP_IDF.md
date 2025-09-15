---
date:
  created: 2025-03-09
categories:
  - Logiciels
tags:
  - Logiciel
authors:
  - thomas
slug: Arduino IDE
---

# ESP IDF set up et utilisatoin 
Initialisation de l'environnement de développement intégré ESP


<!-- more -->

## Set up 
dans visual studio code, simplement installer l'extension ESP IDF
![extension ESP-IDF](mkdocs/ESP_IDF_extension.png)  

choisir le mode express
![extension ESP-IDF](mkdocs/ESP_IDF_installation_Express.png)  

Choisir le chemin où enregistrer les fichiers relatifs à ESP-IDF
![extension ESP-IDF](mkdocs/ESP_IDF_path.png)  

De mon côté ça ne fonctionnait pas encore et il a fallu encore localiser le fichier de commande **install.Bat** et l'exécuter pour réinstaller les dépendances.
![extension ESP-IDF](mkdocs/ESP_IDF_install_bat.png) 

## ouvrir terminal de commande
quand on utilise des commande dans la barre de recherche (palette de commande) il faut mettre > devant la commande. 
![extension ESP-IDF](mkdocs/ESP_IDF_commande.png)   
Si on utilise **ctrl** + **shift** + **p** ça met notre curseur dans la palette de commande pour que l'on puisse écrire notre commande, le > est déjà inclu.   
![extension ESP-IDF](mkdocs/ESP_IDF_ctrl_shift_p.png)     
il faut utiliser la commande **ESP-IDF: Open ESP-IDF Terminal** pour ouvrir le terminal ESP IDF.


## connexion à l'ESP 32
j'ai un ESP32 S3 mini, je le connecte au PC via le câble USB-C, il me faut connaitre son serial port, pour ce faire chercher Ports
![extension ESP-IDF](mkdocs/ESP_IDF_port.png)  

En bas de notre page on a les boutons pour ce qui est de compiler le code et le téléverser vers l'ESP.
On va choisir UART comme flash méthode, sélectioner le port, faire build et flash
![extension ESP-IDF](mkdocs/ESP_IDF_boutons.png)  
Afin de voir le code s'executer (ici un hello world qui tourne en boucle) il faut encore cliquer sur monitor device afin de le voir dans le terminal.  
![extension ESP-IDF](mkdocs/ESP_IDF_monitor_device.png)  
![extension ESP-IDF](mkdocs/ESP_IDF_code_running.png) 

## commandes
Les commandes idf.py sont disponible dans les répertoires (directories en anglais = dossiers) contenant un fichier CMakeList.txt  
On parle de CLI: Command Line Interface (Interface en ligne de commande), cela permet de se passer des menus et interface graphique.

>idf.py build -> revient à cliquer sur l'icone de clée à molette pour build le projet.  
>idf.py menuconfig -> configurer les paramètres système de l'ESP tel que la fréquence du tick (fréquence FreeRTOS)  
>idf.py update-dependencies -> met à jour le projet au niveau des dépendances.  
>idf.py create-project -> crée un nouveau projet ESP IDF.  
>idf.py create component -> crée un nouveau component.  
>idf.py set-target -> définir le type de processeur sur lequel on va flasher notre programme.

## ESP Registry
C'est un [site](https://components.espressif.com/) permettant de télécharger des bibliothèques pour faire fonctionner des composants comme les leds WS2812.
On peut aussi créer nos propres component et les partager sur ESP Registry.


## Récupérer un component sur ESP Registry et l'intégrer à un projet / Architecture dossiers
le code principale que l'on écrit se situe dans le dossier main.
Chaque composant sur ESP.Registry comprent une commande permettant de télécharger les fichiers dans notre dossier de projet au sein d'un sous-dossier nommé **managed_components**.  

Pour commencer il faut ouvrir le terminal ESP_IDF (ctrl + shift + p -> Open ESP IDF terminal) et y coller la commande du component que l'on souhaite ajouter au projet, récupérée d'ESP Registry. Autre manière: coller > + la commande du component dans la barre de recherche de Visual studio Code.  
![extension ESP-IDF](mkdocs/ESP_IDF_Registry.png)   
> comande à récupérer sur ESP Registry.


Par exemple: **idf.py add-dependency "supcik/status_led^2.0.0"** ça va créer un fichier idf.component.yml au sein du dossier main. le fichier .yml est comme une liste de course lisible/compréhensible par l'ordinateur et l'humain que CMake va interpréter pour télécharger les fichiers voulu lorsque l'on lance la commande **idf.py build**. Si le composant n'est pas ajouté on peut essayer **idf.py reconfigure** qui fait une sorte de refresh.



Résumé des actions de la commande prise sur esp-Registry et idf-py build:   

- créer le fichier .yml qui est une liste de ce dont on a besoin pour intégrer le Component.     

- CMake va traduire la liste pour qu'elle soit lisible par Ninja.    

- Ninja va compiler et executer les instructions.  

- les fichiers du component sont téléchargé dans le dossier managed_component  

J'ai été bloqué à cette étape, je n'avais pas de dossier managed_component. Le problème a pu etre résolu grâce à la commande **idf.py update-dependencies** qui a fait une sorte de rafraichissement, retéléchargé ce qui me manquais, mis à jour les fichiers.  
Attention: Lors de la création de mon projet de test ESP IDF "hello-world" j'ai du cocher une option qui m'a ajouté des component Arduino, ça complique les choses, j'en ai pas besoin pour le moment, j'efface le dossier arduino.

[Création de component et upload sur ESP-Registry](ESP_Registry_creation_de_component.md)



## FreeRTOS
Système d'exploitation temps réel intégré dans ESP-IDF. c'est l'acronyme de Real Time Operating System.
Permet de créer des tâches indépendentes qui vont dialoguer entre elles. Elles tournent en concurrences, c'est à dire que FreeRTOS gère le temps de processeur alloué à chaqu'une, ce qui donne une illusion de parallèlisme. Exemple: la 1ère tâche à droit à 20 milisecondes de processeur avant qu'elle soit mise en pause et que la 2ème tâche ait à son tour droit à 20 milisecondes, si elle a besoin de moins elle passe la main dès la fin de ses opérations à la 3ème tâche.
Le scheduleur (ordonnanceur en français) est la partie du programme qui décide quelle est la tâche qui tourne actuellement. Les tâches sont gérées dans une queue.
Le fait d'allouer du temps disponible par tâche est nommé système préemptif, c'est à dire que le système peut arrêter une tâche en cour pour passer à une autre. L'autre système est nommé coopératif, une tâche bloque tout le monde tant qu'elle n'est pas terminé, ça à l'aventage d'être plus rapide dans certains cas mais l'inconvénient de ne pas pouvoir faire de temps réel.
Sur esp-idf le temps alloué par tâche est libre, ex: 1000 Herz, ça veux dire qu'une tâche dure 1'000ème de seconde, soit 1 miliseconde. plus la valeur est élevé moins elle dure longtemps/plus elle la durée est courte.
On peut modifier cette valeur grace à la commande **idf.py menuconfig** -> Component config -> FreeRTOS -> Kernel
-----------------
MQTT = protocole efficace pr dialogue entre appareils.
Publisher = partage
SUbscriber = reçoit

un client peut faire les 2

structure organisé autour de topic (sujet)

broker = c'est le cerveau qui redirige les infos dans les topics.


Node-RED = programme qui permet d'implémenter la logique générale inter appareil, c'est comme une map des actions à faire en fonction des messages retournés par les différents appareils.

Un petit raspberry pi peut être un serveur à - de 100.-
un Nass - network attak ? storage marque synologie.

--------------------------------

projet hello world: C:\Users\thoma\Documents\Github\Timer_code\Test_decouverte-_ESP_IDF\main
Cmake installed by espIDF extension: C:\Users\thoma\esp\v5.4.2\esp-idf\tools\cmake
