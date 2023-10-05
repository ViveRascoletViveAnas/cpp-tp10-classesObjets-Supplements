# TP 10 - Classes et objets - BONUS

## Exo 6 - Ellen's Alien Game

### Classes
Il est temps d'aborder l'un des paradigmes fondamentaux de C++ : la programmation orientée objet (OOP). L'OOP est centrée autour des classes, qui sont des types de données définis par l'utilisateur avec leur propre ensemble de fonctions associées. Nous commencerons par les bases puis aborderons des sujets plus avancés par la suite.

### Membres
Les classes peuvent avoir des variables membres et des fonctions membres. Ils sont accessibles via l'opérateur de sélection de membres (..). Tout comme les variables en dehors des classes, il est conseillé d'initialiser les variables membres avec une valeur lors de leur déclaration. Cette valeur deviendra alors la valeur par défaut pour les nouveaux objets créés à partir de cette classe.

### Encapsulation et masquage de l'information
Les classes offrent la possibilité de restreindre l'accès à leurs membres. Les deux spécificateurs d'accès de base sont `private` et `public`. Les membres `private` ne sont pas accessibles depuis l'extérieur de la classe, tandis que les membres `public` peuvent être librement utilisés. Par défaut, tous les membres d'une classe sont `private`. Seuls les membres explicitement marqués `public` sont librement utilisables en dehors de la classe.

### Exemple de base
La définition d'une classe peut être vue dans l'exemple suivant. Remarquez le `;` après la définition :
```cpp
class Wizard {
  public:               // from here on all members are publicly accessible
    int cast_spell() {  // defines the public member function cast_spell
      return damage;
    }
    std::string name{}; // defines the public member variable `name`
  private:              // from here on all members are private
    int damage{5};      // defines the private member variable `damage`
};

```

Vous pouvez accéder à toutes les attributs depuis l'intérieur de la classe. Jetez un œil à la variable `damage` à l'intérieur de la fonction `cast_spell`. Vous ne pouvez ni lire ni modifier les membres privés en dehors de la classe.

```cpp
Wizard silverhand{};
// calling the `cast_spell` function is okay, it is public:
silverhand.cast_spell();
// => 5

// name is public and can be changed:
silverhand.name = "Laeral";

// damage is private:
silverhand.damage = 500; 
 // => Compilation error
```

### Les constructeurs
Les constructeurs offrent la possibilité d'attribuer des valeurs aux attributs lors de la création d'un objet. Ils ont le **même nom que la classe et n'ont pas de type de retour**. Une classe peut avoir plusieurs constructeurs. C'est utile si vous n'avez pas toujours besoin de définir toutes les variables. Parfois, vous souhaiterez peut-être tout laisser par défaut mais modifier la variable de nom. Dans le cas d'un sorcier important, vous voudrez peut-être également modifier les dégâts, vous aurez donc besoin de deux constructeurs.

Exemple d'une classe `Wizard`:

```cpp
class Wizard {
  public:
    Wizard(std::string new_name) {
      name = new_name;
    }
    Wizard(std::string new_name, int new_damage) {
      name = new_name;
      damage = new_damage;
    }
    int cast_spell() {
      return damage;
    }
    std::string name{};
  private:
    int damage{5};
};

Wizard el{"Eleven"};       // deals  5 damage
Wizard vecna{"Vecna", 50}; // deals 50 damage
```
Les constructeurs sont un sujet vaste et comportent de nombreuses subtilités. Si vous ne définissez pas explicitement un constructeur pour votre classe, c'est alors, et seulement dans ce cas, que le compilateur s'en chargera pour vous. Cela s'est produit dans le premier exemple ci-dessus. L'objet `silverhand` est créé en appelant le constructeur par défaut, sans argument. Toutes les variables sont définies à la valeur indiquée dans la définition de la classe. Si vous n'aviez pas donné de valeurs dans cette définition, les variables pourraient être non initialisées, ce qui pourrait entraîner des conséquences indésirables.

### Instructions
Ellen est en train de créer un jeu où le joueur doit combattre des aliens. Elle vient d'apprendre la Programmation Orientée Objet et est impatiente de profiter des avantages que l'utilisation de classes pourrait apporter à son programme.

Pour sa plus grande joie, vous avez proposé votre aide et elle vous a confié la tâche de programmer les aliens que le joueur doit combattre.

#### 1. Créez la Classe Alien
Définissez la classe Alien avec un constructeur qui accepte deux paramètres entiers `x` et `y`, en les plaçant dans les variables membres `x_coordinate` et `y_coordinate`. Chaque alien commencera également avec un niveau de santé de 3, donc la variable membre `health` doit également être initialisée.

`health` doit être une variable membre privée. Pour permettre aux autres parties du programme de lire les informations de santé, Ellen souhaite avoir une méthode publique `get_health()` qui renvoie un entier.

```cpp
Alien alien{2, 0};
alien.x_coordinate;
// => 2
alien.y_coordinate;
// => 0
alien.get_health();
// => 3
```

Maintenant, chaque alien devrait être en mesure de suivre sa propre position et sa propre santé en interne.

#### 2.	La fonction hit
Ellen aimerait que la classe Alien ait une méthode `hit` qui décrémente la santé d'un objet alien de 1 lorsqu'elle est appelée. De cette façon, elle peut simplement appeler `some_alien_instance.hit()` au lieu de devoir modifier manuellement la santé d'un alien. Assurez-vous que les points de santé ne descendent pas en dessous de zéro. La fonction devrait renvoyer `true`. Ellen souhaite introduire des boucliers ultérieurement, qui renverraient alors `false` si le bouclier est actif.

```cpp
Alien alien {0, 0};
alien.get_health(); 
// => 3 (Initial health value)

alien.hit(); // Decrements health by 1 point.
alien.get_health();
// => 2
```

#### 3.	La fonction is_alive
Vous réalisez que si la santé continue de diminuer, à un moment donné, elle atteindra probablement zéro. Il serait donc judicieux d'ajouter une méthode `is_alive` que Ellen peut rapidement appeler pour vérifier si l'alien est... eh bien... vivant. 😉 `some_alien_instance.is_alive()` devrait renvoyer un booléen.

```cpp
alien.get_health();
// => 1
alien.is_alive();
// => true
alien.hit();
alien.get_health();
// => 0
alien.is_alive();
// => false
```

#### 4.	La fonction teleport
Dans le jeu d'Ellen, les aliens peuvent se téléporter ! Vous devrez écrire une fonction `teleport` qui prend les valeurs `x_new` et `y_new` et modifie les coordonnées de l'alien en conséquence. Pour le moment, la fonction devrait renvoyer `true`. Ellen souhaite ajouter des bombes bloquant la téléportation dans les niveaux ultérieurs, qui renverront alors false en cas de tentatives de téléportation échouées.

```cpp
alien.teleport(5, -4);
alien.x_coordinate;
// => 5
alien.y_coordinate;
// => -4
```

#### 5.	La fonction collision_detection
Si les aliens peuvent être touchés par quelque chose, alors ils doivent être en mesure de détecter quand une collision pourrait se produire. Ellen a besoin de savoir si deux aliens occupent les mêmes coordonnées. La fonction `collision_detection()` prend un autre objet alien en argument et renvoie un booléen.

```cpp
Alien lrrr {3, 6};
Alien ndnd {-2, 12};
lrrr.collision_detection(ndnd);
// => false
ndnd.teleport(3, 6);
ndnd.collision_detection(lrrr);
// => true
```
