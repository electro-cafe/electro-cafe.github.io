---
date:
  created: 2026-05-25
categories:
  - site
  - AR
tags:
  - site
  - AR
authors:
  - thomas
slug: AR
---

# 8th Wall augmented réality
début 2026 8th wall est passé opensource, permettant de créer une expérience AR sans abonnement.

<!-- more -->
 
## Set up
Pour commencer se rendre sur le site [8th wall](https://adresseduliens.ch) pour télécharger le programme.  
[j'ai suivi les instructions d'installation mais je n'arrive plus à les retrouver, peut etre sont elle disponible uniquement au moment du téléchargement de 8th wall ?]
Il nous faudra également [node.js](https://nodejs.org/fr/download) qui est disponible sur ce site. Je l'ai téléchargé avec ces options:
![node js download](mkdocs/node_js.png)   

## 8th wall desktop  
On retrouve des formes primitives dans l'onglet de gauche. Les traductions françaises sont mauvaises (avion à la place de plan).  
Afin que notre smartphone se comporte comme la caméra dans la scène 3D il faut mettre cete dernière en mode **monde AR**.  
![node js download](mkdocs/8th_wall_camera_AR.png)   

## Import de modèle 3D personalisé
Dans blender, exporter notre mesh en .glb, gITF binary et embeded fonctionnent
![node js download](mkdocs/export_GLB_1.png)  
![node js download](mkdocs/export_GLB_2.png)  
Dans 8th wall, Drag and drop les fichiers dans l'onglet de gauche, section du bas (ça ne marchera pas si on les dépose dans le chutier du haut)  
![node js download](mkdocs/8th_wall_import_mesh.png)    
![node js download](mkdocs/8th_wall_import_mesh_2.png)    

 ## Ombres
 Se gère dans les assets créant la lumière directionel (normal c'est eux qui "créent" les ombres). 
 Les ombres diffuses avec un soft edge ne sont pas terrible, mieux vaut baker les ombres depuis blender.
![node js download](mkdocs/8th_wall_ombre_portee.png)  

## workflow
Set up notre scène 3D dans 8th wall. Cliquer sur Publier
![node js download](mkdocs/8th_wall_publish.png) 
![node js download](mkdocs/8th_wall_build.png) 
Extraire le fichier zippé. Ici je range le contenu du .zip dans un dossier que je nomme builded project. Je fais ça pour qu'il y ait moins de confusion entre le dossier de travail et le dossier de code compilé. Peut être serait il mieux d'inclure le dossier code compilé dans le dossier de travail.
![node js download](mkdocs/8th_wall_extract.png) 
Comme j'ai crée un repository Github, je peux utiliser le terminal pour me mettre dans le dossier de code compilé et le synchroniser sur git via les commandes suivantes pour le 1er commit:  
cd "path de mon dossier de code compilé"  
git init //à faire la première fois afin d'initialiser un dépot git local qui suit les modifications futures  
git commit -m "message de commit"  
git remote add origin <URL du repo git> // lie le dépot local au repository github
git push -u origin main   
-> architecture de dossier a modifier, build dans projet, projet sync sur git

Afin de voir le site web et non les fichiers sources hébergés sur Github il nous faut aller dans **settings** -> **pages**
L'opération a fonctionnée si après un petit moment on voit "Your site is live at "https://url" en haut de la page.
![node js download](mkdocs/github_pages.png) 
On peut récupérer l'URL de cette page et générer un code QR avec.  
Scanner le code QR ouvrira l'expérience AR une fois que l'utilisateur aura authorisé l'accès caméra

## image target
[Tutoriel de référence](https://www.youtube.com/watch?v=-WLfXuZNy4g)

## Quick preview
NPM demandera les autorisation administrateur pour être installé de manière global. Mieux vaut utiliser la commande **xxxx** pour **xxxx** localement dans le dossier de travail lié aux projets 8th wall. Tant que la fenêtre du terminal où l'on vient de taper cette commande est ouverte, les appareils connecés au même réseau peuvent consulter le contenu du dossier. Ainsi on a fait de notre dossier un mini serveur. NPM permet de faire de notre ordinateur un serveur web. Les appareils sur le même wifi peuvent consulter son contenu (où un dossier spécifique si NPM est activé dans un dossier local). Pour commencer je m'en suis passé et je me contente d'héberger mon projet sur github



