# Tema2PA_2022

Vladu Denis-Marius 321CB

Curatare:

Calculez cu |R| + |S| BFS-uri distantele intre oricare 2 pozitii de interes
(roboti / locuri) si le salvez intr-o matrice de 8x8

Dupa, cu backtracking calculam toate configuratiile posibile
O configuratie e o lista de liste, cate o lista pentru fiecare robot cu 
toate spatiile pe care le viziteaza. ATENTIE: ordinea in care robotii viziteaza
locurile murdare conteaza. Configuratiile astea se genereaza luand fiecare loc
in parte si incercand sa il adaug in lista unui anumit robot pe o pozitie 
random in lista (similar cu generatul de permutari)

Dupa ce am generat o configuratie, costul configuratiei este maximul tuturor
robotilor. Luam configuratia cu costul minim.


Fortificatii:

Cu dijkstra generam distantele minime de la 1 la toate nodurie, doar ca nu 
adaug in coada nodurile cu barbari.
Dupa aceea caut binar raspunsul si iau toate nodurile cu barbari, ma uit la 
toate muchiile lor adiacente si le cresc cu valoarea minima posibila a.i 
distanta de la 1 la nodul curent sa fie >= middle. Daca am nevoie de prea
multe fortificatii caut o valoare mai mica. Altfel, maresc valoarea cautata

Beamdrone:

- dp[i][j][0|1|2|3] = costul minim de a ajunge din start in pozitia (i, j) si
                      sa fiu orientat in una din cele 4 directii (N|E|S|W)

Initializare:
- dp[xi][yi][orice] = 0

Raspuns:
min(dp[xf][yf][orice])

Recurenta:
- din dp[i][j][d] am 2 variante:
    - ori continui pe directia asta cu cost 0
    - ori schimb directia cu 90% (ma mut in dp[i][j][alt d la 90%]) cu cost 1

Recurentele de tip bfs in care costurile sunt 0/1 se pot rezolva in O(N*M) 
folosind un algoritm numit 0-1 BFS 
    (link: https://cp-algorithms.com/graph/01_bfs.html )

Curse:

Generez graful relatiilor fix ca in explicatii):
    - ne uitam pe prima coloana (pista 1) si adaugam muchii orientate intre 
oricare 2 valori consecutive diferite (pe exemplul 2 adaugam intre 3 si 2)
    - in caz de egalitate pe pista 1 (pe exemplul 2 avem egalitate pe pista 1
in intervalele [1-4] si [5-7]), ne uitam pe pista 2 si adaugam muchii intre 
oricare 2 valori consecutive diferite (in intervalul [1-4] adaugam intre 2 
si 4 si in intervalul [5-7] adaugam intre 3 si 1)
    - in caz de egalitate pe pistele 1 si 2 ne uitam la pista 3 etc

Numarul de muchii din graf este maxim A-1 si solutia o gasim prin sortarea 
topologica a grafului obtinut.
 
