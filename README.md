Projet RT Refresh
=====================

# Ancien code

Toutes les sources de l'ancienne version du RT sont dans le dossier **oldsrc**.
C'est un peu le bordel sur l'organisation donc les éléments utiles seront linké dans la ToDo liste.

Voilà en gros la structure :

* __headers__  
	tout les .h

* __events__  
	gestion des entrées utilisateur

* __filter__  
	filtres d'image

* __interface__  
	tout ce qui concerne l'interface utilisateur dans le RT

* __menu__  
	le menu principale si le RT est lancé sans argument

* __objects__  
	tout les fonction pour la gestion des objets et de leurs propriétés en
	mémoire

* __parser__  
	les parser pour les différents types de données

* __render__  
	toute la gestion du rendu mis à part les équations d'intersection

* __shaders__  
	toutes les fonctions de rendu des effets de lumière, transparence, etc...

* __texture__  
	gestion des textures (mise en mémoire/free, textures procédurales, etc ...)

* __type__  
	équations d'interaction

# Nouveau code

Strucure du projet
---------------------
Le RT pourra faire le rendu d'une scene soit dans un fichier image depuis la ligne de commande simplement avec des paramètres en argument ou en mode interactif (commande disponnible dans la console pour régler les paramètres), soit dans une fenêtre qui disposera en plus d'un mode preview avec openGL.

La partie principale du rt s'occupe de l'initialisation du programme, de parser les scènes passées en argument ou choisie dans un menu, charger et gérer les ressources nécessaire au rendu et gérer les erreurs et l'exit.

### Sous Module
En plus de la partie principale, le code se divise en trois autre modules presque indépendant :

#### Renderer
Ce module s'occupe du rendu. Il est principalement exécuté sur sont propre thread pour éviter de bloquer le thread principale pendant le rendu.
C'est à lui de gérer la couche résau dans le cas d'un rendu en résau, et il peut créer des thread enfant pour accélérer le rendu. C'est aussi à lui de s'occuper de la camera, du render tree et de la communication avec le thread principale. Pour faire le tracé de rayon lui même ainsi que le rendu des effets visuels il appel les fonctions du module de raytracer.

#### Viewer
Ce module s'occupe de gérer la fenêtre de preview/d'affichage du rendu. Il gère le rendu openGL et l'affichage de l'interface utilisateur.

#### Raytracer
Ce module contient toutes les fonctions nécessaires au ray tracing des objets et au rendu des effets visuels comme la lumière ou la transparence.

### Scene Tree
Un scène est stocké en mémoire sous la forme d'un arbre nodale d'instance d'objets. Dans un arbre nodale chaque node a un parent et peut avoir un nombre illimité de node enfant. Le node à la racine de l'arbre (root node) est son propre parent et contient toutes les données propre à la scène. Chaque node de l'arbre pointe vers une instance, de type [object instance \(t_rtobi\)](include/data/rt_data_objects.h#L81), qui contient quelques informations propre à elle même (principalement ses transformations) et pointe vers le ou les différent(s) objet(s) dont elle est composée, de type [object \(t_rtobj\)](include/data/rt_data_objects.h#L90).

### Parser
Les parsers qui lisent les scènes doivent obligatoirement générer un Scene tree valide ce qui veux dire qu'ils doivent remplire les données des objets avec des valeurs par défaut quand elle ne sont pas spécifié et vérifier la validité de celles spécifiées (par exemple les noms, les noms d'instances et d'objets doivent être uniques) et il doit s'occuper de l'attribution des ID.

### Render Tree
Le render tree est une copy complète des node d'un Scene tree (seulement les nodes, pas les instances qu'ils contienent) avec un précalcule des matrices de transformation et de transformation inverse.

Règles de travail
---------------------

### Règles générales
Pour le développement, le makefile compile automatiquement toutes les sources
présentes dans le dossier **src** donc il n'est pas nécessaire d'y toucher.  
Si vous avez d'autres règle à proposer ou des commentaire à faire sur celles
déjà présente hésitez pas.

### Règle de syntaxe
**Codez directement à la norme !!**  
Je préviens, je `git reset --hard` le premier fichier que je vois avec 10 variables locales ou plus de 30 lignes. Si y'a juste quelques lignes en trop c'est pas grave on peut corriger ça plus tard, mais pensez à la fonction avant de l'écrire, séparé là en plusieurs static dés le début ça évitera pas mal de prise de tête sur les arguments. Sinon commentez les lignes de debug que vous voulez garder au cas où, et y'a un ft_printf dans ma lib qui fait tout pareil que le vrai pas besoin de ramener l'usine à gaz de stdio pour le debug.

Et pour les structures :
* Pas de padding, y'a un flag qui vous engueulera si vous en avez.
* Pas de structure fourre-tout de 50 lignes, on est propre on fait des tiroirs.
* Essayez de minimiser la longueur des noms des membres, hésitez pas à mettre un commentaire au dessus pour la décrire.
* Les `typedef` c'est dans [rt_prototype.h](include/rt_prototype.h) que ça va, à moins que ce soit locale à un fichier.

### Règle de nommage
Tous les noms des fonctions déstiné à être utiliser dans l'espace globale doivent être préfixé à la mode GNU (`type prefix_nom(args...);`) de manière logique à l'exception des fonctions de création et suppression de donnée, qui prennent respectivement les préfixes `mk` et `rm` sans underscore après (exemple dans [rt_tree.h](include/rt_tree.h)).

Les noms des fonctions spécifique à un ensemble de code et à une personne n'ont pas de règle précise, essayez juste de rester cohérent sur tous le noms du bloc en question.

### Règles de hiérarchie
Toute les sources C doivent être dans le dossier **src**, ça évitera de polluer
le répertoire principale du projet. Essayez de fragmenter en sous dossier
par thème ou toutes les fonctionnalité qui nécessite plus d'un fichier C.

##### Hiérarchie actuelle :
*À modifier en fonction des updates*
* __include__ - Tout les .h vont là
	* __data__ - Définition des structures de donnée
	* *rt_prototype.h* - contient les `typedef` pour les structures et les `#define` pour le projet, ce fichier doit être inclus dans tout les autres .h, après tout include système et avant tout include du projet
* __lib__ - Contient les bibliothèque externes
	* __libft__ - la ft
	* __mathex__ - extension de la lib math du système
	* __mglw__ - lib de gestion des fenêtre et de chargement d'images
* __oldsrc__ - Les sources du précédent RT
* __src__ - les sources du projet
	* __gui__ - gestion de l'interface utilisateur
	* __object__ - gestion des différents types d'objets et de leur données
	* __parser__ - les sources des différents parser dont on aura besoin, faire
	un dossier par type de fichier à parser
	* __raytracing__ - les fonctions générique de raytracing
	* __render__ - la gestion du rendu
	* __thread__ - tout ce qui concerne la gestion du multi-threading
	* __tree__ - tout ce qui concerne la gestion de l'arborescence des objets
	dans les scènes (node tree, render tree et data tree)
	* __viewer__ - tout ce qui touche à l'affichage du RT et sa
	prévisualisation dans une fenêtre

To Do liste :
---------------------
É pa finis :3  
Here, have a flying unicorn !

                                . . . .
                                ,\`,`,`,`,
          . . . .               `\`\`\`\;
          `\`\`\`\`,            ~|;!;!;\!
           ~\;\;\;\|\          (--,!!!~`!       .
          (--,\\\===~\         (--,|||~`!     ./
           (--,\\\===~\         `,-,~,=,:. _,//
            (--,\\\==~`\        ~-=~-.---|\;/J,
             (--,\\\((```==.    ~'`~/       a |
               (-,.\\('('(`\\.  ~'=~|     \_.  \
                  (,--(,(,(,'\\. ~'=|       \\_;>
                    (,-( ,(,(,;\\ ~=/        \
                    (,-/ (.(.(,;\\,/          )
                     (,--/,;,;,;,\\         ./------.
                       (==,-;-'`;'         /_,----`. \
               ,.--_,__.-'                    `--.  ` \
              (='~-_,--/        ,       ,!,___--. \  \_)
             (-/~(     |         \   ,_-         | ) /_|
             (~/((\    )\._,      |-'         _,/ /
              \\))))  /   ./~.    |           \_\;
           ,__/////  /   /    )  /
            '===~'   |  |    (, <.
                     / /       \. \
                   _/ /          \_\
                  /_!/            >_\
