---
date:
  created: 2025-02-22
categories:
  - Mkdocs
tags:
  - introduction
authors:
  - thomas
slug: Mkdocs
---

# Mkdocs presentation et fonctionnement

Cet article présente et explique comment ajouter des articles dans Mkdocs.  

<!-- more -->

## Qu'es-ce que Mkdocs  et Markdown
[Mkdocs](https://www.mkdocs.org/) est une générateur de site conçu pour créer de la documentation. C'est avec Mkdocs que nous réalisons celle-ci.
J'utilise Visual Studio Code pour éditer le code.

[Markdown](https://www.markdownguide.org/basic-syntax/#links) est un language de balisage permettant de styliser du text.

Exemple synthaxe Markdown vs HTML:
![exemple comparatif code markdown et HTML5](mkdocs/markdown_exemple.png)

## Comment previsualiser les changements Mkdocs

![layout mkdocs visualstudio code](mkdocs/vsc_mkdocs_page_layout.jpg)
On peut ajouter des dossier dans la partie explorer (ici nommée hierarchie fichiers), c'est ce que j'ai fait pour pouvoir joindre des images à mes pages (dossier sources contenant le dossier images contenant les images)

La partie d'édition de fichier permet de créer du text, changer sa mise en forme, joindre des images etc.

Le terminal nous permet de simuler notre page en local.
Pour ce faire taper **poetry run mkdocs serve** puis enter, la ligne de commande s'exécute. avec ctrl + clic sur le lien ça ouvre la page web en local:

![commande pour lancer le site en local](mkdocs/commande_run_server.png)

On peut ajouter nos fichiers dans le dossier draft. Il ne sont visible qu'en local. 
Ils apparaissent avec la mention brouillon

![aperçu d'un draft en local](mkdocs/draft_preview.png)

lorsque l'on est content du résultat on peut les sortir de draft pour les mettre dans posts. Attention il faut enlever "../" au chemin des images.

Dans le terminal faire **ctrl + c** pour mettre fin à la synchronisation du site en local.
**flèche vers le haut** pour parcourir l'historique des commandes entrées dans le terminal.

## Publier changements sur Github

les changements sont indiqué à droite de l'écran sous source control. Ici il y en a 6
![stage changes](mkdocs/icone_changement.png)

Ils sont ici listés, on ajoute ceux qu'on désire avec le +
![staged changes](mkdocs/stash_files.png)

les ajouts passent en "staged change". On ajoute une description des changement dans la case message pour mieux s'y retrouver si on doit utiliser l'historique des changements.
On clique sur Commit, c'est comme faire une photo de l'état du projet, afin de marquer une étape dans son historique et de pouvoir y revenir au besoin.

![commit changes](mkdocs/staged_changes.png)

Puis Sync changes

<figure markdown="span">
  ![push to git](mkdocs/push.png)
  <figcaption>push to git</figcaption>
</figure>


