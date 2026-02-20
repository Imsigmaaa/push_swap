
*This project has been created as part of the 42 curriculum by xingchen.*

# Description
Le projet libftprintf consiste à réécrire la fonction printf de la bibliothèque standard en C.  
L'objectif est de créer une fonction ft_printf() qui peut afficher du texte formaté et gérer plusieurs types de conversions :  
- `%c` : afficher un caractère  
- `%s` : afficher une chaîne de caractères  
- `%p` : afficher un pointeur en hexadécimal  
- `%d` / `%i` : afficher un entier en base 10  
- `%u` : afficher un entier non signé  
- `%x` / `%X` : afficher un entier en hexadécimal (minuscules / majuscules)  
- `%%` : afficher le caractère `%`  

La fonction doit utiliser uniquement les fonctions autorisées : `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`.  
Le projet autorise l'utilisation de la bibliothèque **libft** existante.

---

# Instructions
Pour compiler la bibliothèque et générer `libftprintf.a` :
```
make
```
Supprimer les fichiers objets :
```
make clean
```
Supprimer les fichiers objets et la bibliothèque :
```
make fclean
```
Recompiler entièrement le projet :
```
make re
```

---

# Ressources

J’ai utilisé YouTube, Google et ChatGPT pour comprendre va_start, va_arg, va_copy et va_end, mais le code a été entièrement réalisé par moi-même.

*This project has been created as part of the 42 curriculum by xingchen.*

# Description

The libftprintf project consists of rewriting the standard C library function printf.
The goal is to create a function ft_printf() that can display formatted text and handle multiple conversion types:

- `%c` : print a character

- `%s` : print a string

- `%p` : print a pointer in hexadecimal

- `%d` / `%i` : print an integer in base 10

- `%u` : print an unsigned integer

- `%x` / -`%X` : print an integer in hexadecimal (lowercase / uppercase)

-`%%` : print the `%` character

The function must only use the allowed functions: `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`.
The project allows the use of the existing libft library.

# Instructions

To compile the library and generate libftprintf.a:
```
make
```

To remove object files:
```
make clean
```

To remove object files and the library:
```
make fclean
```

To fully recompile the project:
```
make re
```

# Resources

I used YouTube, Google, and ChatGPT to understand `va_start`, `va_arg`, `va_copy`, and `va_end`, but all the code was implemented by myself.