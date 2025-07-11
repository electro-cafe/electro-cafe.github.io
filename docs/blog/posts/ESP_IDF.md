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

## review fonctionnement de l'IDE
quand on utilise des commande dans la barre de recherche (palette de commande) il faut mettre > devant la commande. 
![extension ESP-IDF](mkdocs/ESP_IDF_commande.png)   
Si on utilise **ctrl** + **shift** + **p** ça met notre curseur dans la palette de commande pour que l'on puisse écrire notre commande, le > est déjà inclu.   
![extension ESP-IDF](mkdocs/ESP_IDF_ctrl_shift_p.png)   


## connexion à l'ESP 32
j'ai un ESP32 S3 mini, je le connecte au PC via le câble USB-C, il me faut connaitre son serial port, pour ce faire chercher Ports
![extension ESP-IDF](mkdocs/ESP_IDF_port.png)  

En bas de notre page on a les boutons pour ce qui est de compiler le code et le téléverser vers l'ESP.
On va choisir UART comme flash méthode, sélectioner le port, faire build et flash
![extension ESP-IDF](mkdocs/ESP_IDF_boutons.png)  
Afin de voir le code s'executer (ici un hello world qui tourne en boucle) il faut encore cliquer sur monitor device afin de le voir dans le terminal.  
![extension ESP-IDF](mkdocs/ESP_IDF_monitor_device.png)  
![extension ESP-IDF](mkdocs/ESP_IDF_code_running.png) 

## ESP Registry
C'est un [site](https://components.espressif.com/) permettant de télécharger des bibliothèques pour faire fonctionner des composants comme les leds WS2812