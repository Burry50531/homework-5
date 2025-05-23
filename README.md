Витік памʼяті через циклічні посилання в C

Цей репозиторій демонструє класичний приклад **витоку памʼяті**, спричиненого **циклічними посиланнями** в мові програмування C.

 Опис

У C керування памʼяттю виконується вручну. Якщо структури даних (наприклад, звʼязані списки) посилаються одна на одну в циклі, можна втратити всі зовнішні покажчики, тоді як внутрішні покажчики залишаються живими. Через відсутність збирача сміття памʼять не звільняється — виникає **витік**.


 Як перевірити витік

1. Скомпілюйте з налагоджувальною інформацією:
   ```bash
   gcc -g cyclic_leak.c -o cyclic_leak

Запустіть програму через Valgrind:

valgrind --leak-check=full --show-leak-kinds=all ./cyclic_leak

Приклад результату:

==12345== HEAP SUMMARY:
==12345==    definitely lost: 72 bytes in 3 blocks
==12345==    indirectly lost: 0 bytes in 0 blocks
==12345== LEAK SUMMARY:
==12345==    definitely lost: 72 bytes in 3 blocks
