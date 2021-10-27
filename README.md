# syst-me-de-gestion-des-contract
Projet de structures de données avancées: Gestion des contacts téléphonique sous forme arborescente

//L’objectif du projet

La gestion du contact téléphonique désigne l’organisation de l’ensemble des contacts à savoir : l’ajout, la suppression, la sauvegarde, la recherche d’un contact. Le but de ce projet est la création d’une application de gestion des contacts téléphonique en se basant sur une structure arborescente (arbre n-aires).

//Description des fonctionnalités du programme

Le système propose un menu dont les fonctionnalités attendues sont :

*Ajout d'un nouveau contact.

*Suppression d’un contact existant.

*Recherche de contacts par leurs noms : L’utilisateur pourra saisir la première, ou les deux premières lettres ou le nom complet du contact souhaité. La recherche fournira la liste des contacts qui vérifient ces critères.

*Affichage de la liste des contacts.

*Quitter : Arrêt de l'exécution du programme.

//Les structures de données utilisées

L'implémentation est basée sur les arbres n-aires. On rappelle que l’arbre n-aire est une structure de données dynamique d’éléments organisés d’une manière hiérarchique appelés « nœuds ». Il est composé d’un nœud particulier appelé « racine », de plusieurs nœuds intermédiaires possédant chacun un et un seul nœud appelé père et un ou plusieurs nœud appelés fils. Les nœuds qui ne possèdent pas de fils sont appelés feuilles.

Dans notre application la racine est une structure de donnée appelée contact qui se compose de 3 champs :

*Info qui est à son tour une structure de donnée de type contact comportant trois champs (le nom, le téléphone et le mail)

*Fils qui est un pointeur vers le premier fils de la racine contact

*Frère qui est un pointeur nul dans ce cas vu que la racine n’a pas de frère

-Les nœuds de 2eme niveau à savoir les fils de la racine sont les alphabets. Chacun a comme fils un trio et comme frère un alphabet.

-Les nœuds de 3eme niveau à savoir les fils de la racine sont des trios des alphabets. Chacun a comme fils un nom de contact et comme frère un autre trio.

-Les feuilles de cet arbre sont les noms de contact, chacune pointe vers un frère qui est un nom de contact et ils ont ne possèdent pas de fils.

//Le langage utilisé

L'implémentation du programme s’est appuyé sur le langage C qui est un langage de programmation impératif conçu pour la programmation système, tout en le compilant à l'aide de l’IDE (Environnement de développement intégré) Code::Blocks.
