---
goal:Apprendre à maîtriser les références.
notions:&
---
**Point technique**

- Le compilateur utilise le _lowering_ pour transformer une référence en pointeur
		int original;
		int & alias = original; // int * pAlias = &original;
		alias = 5;              // *pAlias = 5;
		int copy = alias;       // int copy = *pAlias;
    Noté que - par _design_ - le pointeur sous-jacent à la référence est non nul.

**A faire**

Pour chaque morceau de code suivant précisez :
 - s’il est valide
 - l’affichage produit
 - s’il s’agit d’une référence ou d’une adresse.
---
    int & a = NULL;
---
    int & a = 10;
---
    int b;
    int & a = b;
    std::cout << a << std::endl;
---
    int b=10;
    int & a = b;
    std::cout << a << std::endl;
---
    int b=10;
    int & a = b;
    b=15;
    std::cout << a << std::endl;
---
    int b=10;
    int c = 5;
    int & a = b;
    a = c;
    ++a;
    std::cout << a << " " << b << " " << c << std::endl;
---
    int b=10;
    int c = 5;
    int & a = b;
    a = &c;
    ++a;
    std::cout << a << " " << b << " " << c << std::endl;
---
    int b=10;
    int c = 5;
    int * a = &b;
    a = &c;
    ++(*a);
    std::cout << *a << " " << b << " " << c << std::endl;
---
    void function(int c) {
      ++c;
    }
    …
    int c = 10;
    function(c);
    std::cout << c << std::endl;
---
    void function(int & c) {
      ++c;
    }
    …
    int c = 10;
    function(c);
    std::cout << c << std::endl;
---
    void function(int * c) {
      ++(*c);
    }
    …
    int c = 10;
    function(&c);
    std::cout << c << std::endl;
---
    int & function() {
	  int c = 5;
	  return c;
    }
    …
    int c = 10;
    c = function();
    std::cout << c << std::endl;
---
    int & function() {
	  int *c = new int;
	  c = 5;
	  return *c;
    }
    …
    int c = 10;
    c = function();
    std::cout << c << std::endl;
---
    int * function(int & c) {
	  ++c;
	  return &c;
    }
    …
    int c = 10;
    c = *function(c);
    std::cout << c << std::endl;